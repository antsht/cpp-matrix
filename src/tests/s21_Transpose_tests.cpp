#include <gtest/gtest.h>

#include "../s21_matrix_oop.hpp"

using namespace S21;

TEST(TransposeTest, Test1) {
  S21Matrix matrix1{1, 1};
  matrix1[0][0] = 2.0;

  ASSERT_DOUBLE_EQ((matrix1.Transpose())(0, 0), 2);
}

TEST(TransposeTest, Test2) {
  S21Matrix matrix1{2, 2};
  matrix1[0][0] = 1.0;
  matrix1[0][1] = 2.0;
  matrix1[1][0] = 3.0;
  matrix1[1][1] = 4.0;
  S21Matrix expected{2, 2};
  expected[0][0] = 1.0;
  expected[0][1] = 3.0;
  expected[1][0] = 2.0;
  expected[1][1] = 4.0;
  S21Matrix res = matrix1.Transpose();
  EXPECT_TRUE(res.EqMatrix(expected));
}

TEST(TransposeTest, Test3) {
  S21Matrix matrix1{1, 2};
  matrix1[0][0] = 1.0;
  matrix1[0][1] = 1.0;
  EXPECT_THROW(matrix1.Transpose(), std::runtime_error);
}