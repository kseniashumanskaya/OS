#include "matrix.h"
#include <thread>

Matrix::Matrix(const std::vector<std::vector<int>>& source, int i_index, int j_index, int width, int high) {
    for (int i = i_index; i < i_index + high; ++i) {
        std::vector<int> line;
        for (int j = j_index; j < j_index + width; ++j) {
            line.push_back(source[i][j]);
        }
        body_.push_back(line);
    }
}

std::ostream& operator<<(std::ostream &out, const Matrix &matrix) {
    for (const auto& i : matrix.body_) {
        for (int j : i) {
            out << j << " ";
        }
        std::cout << '\n';
    }
    return out;
}

Matrix Matrix::operator*(const Matrix &second) const {
    if (body_[0].size() != second.body_.size()) {
        throw std::invalid_argument("");
    }
    std::vector<std::vector<int>> matrix;
    for (int i = 0; i < body_.size(); ++i) {
        std::vector<int> result_line(second.body_[0].size(), 0);
        for (int j = 0; j < result_line.size(); ++j) {
            for (int k = 0; k < second.body_.size(); ++k) {
                result_line[j] += body_[i][k] * second.body_[k][j];
            }
        }
        matrix.push_back(result_line);
    }
    return Matrix(matrix, 0, 0, matrix[0].size(), matrix.size());
}

Matrix Matrix::operator+(const Matrix &second) const {
    std::vector<std::vector<int>> matrix;
    if (body_[0].size() != second.body_[0].size() || body_.size() != second.body_.size()) {
        throw std::invalid_argument("");
    }
    for (int i = 0; i < body_.size(); ++i) {
        std::vector<int> result_line(body_[0].size(), 0);
        for (int j = 0; j < result_line.size(); ++j) {
            result_line[j] += body_[i][j] + second.body_[i][j];
        }
        matrix.push_back(result_line);
    }
    return Matrix(matrix, 0, 0, matrix[0].size(), matrix.size());
}

std::vector<std::vector<Matrix>> Matrix::BlockSplitting(int block_size) {
    int count_of_blocks = body_.size() / block_size;
    int last_block_size = body_.size() % block_size;
    std::vector<std::vector<Matrix>> new_matrix;
    if (block_size <= 0 || block_size > body_.size()) {
        throw std::invalid_argument("");
    }
    for (int i = 0; i <= body_.size() - block_size; i+=block_size){
        std::vector<Matrix> term;
        for (int j = 0; j <= body_.size() - block_size; j+=block_size){
            term.push_back(Matrix(body_, i, j, block_size, block_size));
        }
        if (last_block_size != 0) {
            term.push_back(Matrix(body_, i, block_size * count_of_blocks, last_block_size, block_size));
        }
        new_matrix.push_back(term);
    }
    if (last_block_size != 0){
        std::vector<Matrix> term;
        for (int j = 0; j < body_.size() - block_size; j += block_size){
            term.push_back(Matrix(body_, block_size * count_of_blocks , j, block_size, last_block_size));
        }
        term.push_back(Matrix(body_, block_size * count_of_blocks, block_size * count_of_blocks, last_block_size, last_block_size));
        new_matrix.push_back(term);
    }
    return new_matrix;
}

std::vector<std::vector<Matrix>>
Matrix::Multiplication(std::vector<std::vector<Matrix>> m1, std::vector<std::vector<Matrix>> m2) {
    if (m1[0].size() != m2.size()) {
        throw std::invalid_argument("");
    }
    std::vector<std::vector<Matrix>> matrix;
    for (int i = 0; i < m1.size(); ++i) {
        std::vector<Matrix> result_line;
        for (int j = 0; j < m2[i].size(); ++j) {
            std::thread thr(foo, std::cref(m1), std::cref(m2), std::ref(result_line), i, j);
            thr.join();
        }
        matrix.push_back(result_line);
    }
    return matrix;
}

void foo(const std::vector<std::vector<Matrix>>& m1,
         const std::vector<std::vector<Matrix>>& m2,
         std::vector<Matrix>& result_line,
         int i,
         int j) {
    result_line.push_back(m1[i][0] * m2[0][j]);
    for (int k = 1; k < m2.size(); ++k) {
        result_line[j] = result_line[j] + m1[i][k] * m2[k][j];
    }
}
