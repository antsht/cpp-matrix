#include <gtest/gtest.h>

#include "../s21_matrix_oop.hpp"

using namespace S21;

TEST(InverseMatrixTest, Test1) {
  S21Matrix matrix1{1, 1};
  matrix1[0][0] = 2.0;

  ASSERT_DOUBLE_EQ((matrix1.InverseMatrix())(0, 0), 1.0 / 2.0);
}

TEST(InverseMatrixTest, Test2) {
  S21Matrix matrix1{2, 2};
  matrix1[0][0] = 1.0;
  matrix1[0][1] = 2.0;
  matrix1[1][0] = 3.0;
  matrix1[1][1] = 4.0;
  S21Matrix expected{2, 2};
  expected[0][0] =-2.0;
  expected[0][1] = 1.0;
  expected[1][0] = 1.5;
  expected[1][1] = -0.5;
  S21Matrix res = matrix1.InverseMatrix();
  EXPECT_TRUE(res.EqMatrix(expected));
}