#include <iostream>
#include <vector>
#include <chrono>
#include "matrix.h"


int main() {
    std::vector<std::vector<int>> vector(10, std:: vector<int>(10, 0));
    for (int i = 0; i < vector.size(); ++i){
        for(int j = 0; j < vector[i].size(); ++j){
            vector[i][j] = rand() % 100;
        }
    }

    std::vector<std::vector<int>> vector2(10, std:: vector<int>(10, 0));
    for (int i = 0; i < vector2.size(); ++i){
        for(int j = 0; j < vector2[i].size(); ++j){
            vector2[i][j] = rand() % 100;
        }
    }

    Matrix m1(vector, 0, 0, 10, 10);
    Matrix m2(vector2, 0, 0, 10, 10);
    //std::cout << m1 << '\n';
    //std::cout << m2 << '\n';
    std::chrono::high_resolution_clock::time_point t11 = std::chrono::high_resolution_clock::now();
    Matrix result = m1*m2;
    std::chrono::high_resolution_clock::time_point t22 = std::chrono::high_resolution_clock::now();
    std:: cout << std::chrono::duration_cast<std::chrono::microseconds>(t22 - t11).count() << " microseconds" <<'\n';
    //std::cout << result;

    for (int i = 1; i <= vector.size(); i++){
        int number_of_blocks = vector.size() / i;
        if (vector.size() % i != 0){
            number_of_blocks++;
        }
        std::vector<std::vector<Matrix>> matrix1 = m1.BlockSplitting(i);
        std::vector<std::vector<Matrix>> matrix2 = m2.BlockSplitting(i);
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    std::vector<std::vector<Matrix>> result = m1.Multiplication(matrix1, matrix2);
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    std::cout << "size of block is " << i << ", " << "number of blocks is " << number_of_blocks << ", " <<
    std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << " microseconds" <<'\n';
    }
    return 0;
}