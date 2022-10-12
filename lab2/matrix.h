#pragma once
#include <vector>
#include <iostream>

class Matrix {
  public:
    Matrix(const std::vector<std::vector<int>>& source, int i_index, int j_index, int width, int high);
    Matrix operator*(const Matrix& second) const;
    Matrix operator+(const Matrix& second) const;
    std::vector<std::vector<Matrix>> BlockSplitting (int block_size);
    friend std::ostream& operator<< (std::ostream& out, const Matrix& matrix);
    std::vector<std::vector<Matrix>> Multiplication (std::vector<std::vector<Matrix>> m1,std::vector<std::vector<Matrix>> m2);

  private:
    std::vector<std::vector<int>> body_{};
};

std::ostream& operator<< (std::ostream& out, const Matrix& matrix);
void foo(const std::vector<std::vector<Matrix>>& m1,
         const std::vector<std::vector<Matrix>>& m2,
         std::vector<Matrix>& result_line,
         int i,
         int j);