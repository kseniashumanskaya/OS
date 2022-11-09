#include <iostream>
#include <vector>
#include <chrono>
#include "matrix.h"

int main() {
  std::vector<std::vector<int>> vector(100, std:: vector<int>(100, 0));
  for (int i = 0; i < vector.size(); ++i){
    for(int j = 0; j < vector[i].size(); ++j){
      vector[i][j] = rand() % 20;
    }
  }

  std::vector<std::vector<int>> vector2(100, std:: vector<int>(100, 0));
  for (int i = 0; i < vector2.size(); ++i){
    for(int j = 0; j < vector2[i].size(); ++j){
      vector2[i][j] = rand() % 20;
    }
  }

  Matrix m1(vector, 0, 0, 100, 100);
  Matrix m2(vector2, 0, 0, 100, 100);
  std::chrono::high_resolution_clock::time_point t11 = std::chrono::high_resolution_clock::now();
  Matrix result = m1*m2;
  std::chrono::high_resolution_clock::time_point t22 = std::chrono::high_resolution_clock::now();
  std:: cout << std::chrono::duration_cast<std::chrono::microseconds>(t22 - t11).count() << " microseconds" << std::endl;

  for (int i = 5; i <= vector.size(); i += 5) {
    int number_of_blocks = vector.size() / i;
    if (vector.size() % i != 0){
      number_of_blocks++;
    }
    std::vector<std::vector<Matrix>> matrix1 = m1.BlockSplitting(i);
    std::vector<std::vector<Matrix>> matrix2 = m2.BlockSplitting(i);
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    std::vector<std::vector<Matrix>> result_matrix = Matrix::Multiplication(matrix1, matrix2);
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    std::cout << "size of block is " << i << ", " << "number of blocks is " << number_of_blocks << ", " <<
              std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << " microseconds" << std::endl;
  }
  return 0;
}