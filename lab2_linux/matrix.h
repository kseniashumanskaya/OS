#pragma once
#include <vector>
#include <iostream>

class Matrix {
  public:
    Matrix() = default;
    Matrix(const std::vector<std::vector<int>>& source, int i_index, int j_index, int width, int high);
    Matrix operator*(const Matrix& second) const;
    Matrix operator+(const Matrix& second) const;
    std::vector<std::vector<Matrix>> BlockSplitting (int block_size);
    friend std::ostream& operator<< (std::ostream& out, const Matrix& matrix);
    static std::vector<std::vector<Matrix>> Multiplication (std::vector<std::vector<Matrix>> m1,std::vector<std::vector<Matrix>> m2);

  private:
    std::vector<std::vector<int>> body_{};
};

std::ostream& operator<< (std::ostream& out, const Matrix& matrix);

struct Arg {
  Arg(std::vector<std::vector<Matrix>>* mat1,
      std::vector<std::vector<Matrix>>* mat2,
      Matrix* res, int first, int second) : m1(mat1), m2(mat2), result(res), i(first), j(second) {}
  std::vector<std::vector<Matrix>>* m1;
  std::vector<std::vector<Matrix>>* m2;
  Matrix* result;
  int i;
  int j;
};

extern "C" void* foo(void* r);