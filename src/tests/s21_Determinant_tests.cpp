#include <gtest/gtest.h>

#include "../s21_matrix_oop.hpp"

using namespace S21;

TEST(DeterminantTest, Test1) {
  S21Matrix matrix1{1, 1};
  matrix1[0][0] = 1.0;
  ASSERT_DOUBLE_EQ(matrix1.Determinant(), 1.0);
}

TEST(DeterminantTest, Test2) {
  S21Matrix matrix1{2, 2};
  matrix1[0][0] = 1.0;
  matrix1[0][1] = 2.0;
  matrix1[1][0] = 3.0;
  matrix1[1][1] = 4.0;
  ASSERT_DOUBLE_EQ(matrix1.Determinant(), -2.0);
}

TEST(DeterminantTest, Test3) {
  S21Matrix matrix1{3, 3};
  matrix1[0][0] = 1.0;
  matrix1[0][1] = 2.0;
  matrix1[0][2] = 3.0;
  matrix1[1][0] = 4.0;
  matrix1[1][1] = 5.0;
  matrix1[1][2] = 6.0;
  matrix1[2][0] = 7.0;
  matrix1[2][1] = 8.0;
  matrix1[2][2] = 9.0;
  ASSERT_DOUBLE_EQ(matrix1.Determinant(), 0.0);
}

TEST(DeterminantTest, Test4) {
  S21Matrix matrix1{1, 2};
  matrix1[0][0] = 1.0;
  matrix1[0][1] = 1.0;
  EXPECT_THROW(matrix1.Determinant(), std::runtime_error);
}

TEST(DeterminantTest, Test5) {
  S21Matrix matrix1{3, 3};
  matrix1[0][0] = __DBL_MAX__;
  matrix1[0][1] = 2.0;
  matrix1[0][2] = 3.0;
  matrix1[1][0] = 4.0;
  matrix1[1][1] = 99.0;
  matrix1[1][2] = 6.0;
  matrix1[2][0] = 7.0;
  matrix1[2][1] = 8.0;
  matrix1[2][2] = 99.0;
  EXPECT_THROW(matrix1.Determinant(), std::overflow_error);
}

TEST(GetMinorTest, Test4) {
  S21Matrix matrix1{2, 2};
  matrix1[0][0] = 1.0;
  matrix1[0][1] = 1.0;
  matrix1[1][0] = 1.0;
  matrix1[1][1] = 1.0;
  EXPECT_THROW(matrix1.GetMinor(5, 5), std::out_of_range);
}