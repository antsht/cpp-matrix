#include <gtest/gtest.h>

#include "../s21_matrix_oop.hpp"

using namespace S21;

TEST(S21MatrixTest, s21_CalcComplements_test_1) {
  S21Matrix matrix1{1, 1};
  matrix1(0, 0) = 1;
  EXPECT_THROW(matrix1.CalcComplements(), std::runtime_error);
}

TEST(S21MatrixTest, s21_CalcComplements_test_2) {
  S21Matrix matrix1{2, 2};
  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  S21Matrix expected{2, 2};
  expected(0, 0) = 4;
  expected(0, 1) = -3;
  expected(1, 0) = -2;
  expected(1, 1) = 1;

  EXPECT_TRUE(matrix1.CalcComplements().EqMatrix(expected));
}

TEST(S21MatrixTest, s21_CalcComplements_test_3) {
  S21Matrix matrix1{4, 4};
  matrix1(0, 0) = 1;
  matrix1(0, 1) = 0;
  matrix1(0, 2) = 0;
  matrix1(0, 3) = 2;
  matrix1(1, 0) = 0;
  matrix1(1, 1) = 1;
  matrix1(1, 2) = 2;
  matrix1(1, 3) = 0;
  matrix1(2, 0) = 0;
  matrix1(2, 1) = 2;
  matrix1(2, 2) = 1;
  matrix1(2, 3) = 0;
  matrix1(3, 0) = 2;
  matrix1(3, 1) = 0;
  matrix1(3, 2) = 0;
  matrix1(3, 3) = 1;
  S21Matrix expected{4, 4};
  expected(0, 0) = -3;
  expected(0, 1) = 0;
  expected(0, 2) = 0;
  expected(0, 3) = 6;
  expected(1, 0) = 0;
  expected(1, 1) = -3;
  expected(1, 2) = 6;
  expected(1, 3) = 0;
  expected(2, 0) = 0;
  expected(2, 1) = 6;
  expected(2, 2) = -3;
  expected(2, 3) = 0;
  expected(3, 0) = 6;
  expected(3, 1) = 0;
  expected(3, 2) = 0;
  expected(3, 3) = -3;

  EXPECT_TRUE(matrix1.CalcComplements().EqMatrix(expected));
}

TEST(S21MatrixTest, s21_CalcComplements_test_4) {
  S21Matrix matrix1{3, 3};
  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(0, 2) = 3;
  matrix1(1, 0) = 0;
  matrix1(1, 1) = 4;
  matrix1(1, 2) = 2;
  matrix1(2, 0) = 5;
  matrix1(2, 1) = 2;
  matrix1(2, 2) = 1;
  S21Matrix expected{3, 3};
  expected(0, 0) = 0;
  expected(0, 1) = 10;
  expected(0, 2) = -20;
  expected(1, 0) = 4;
  expected(1, 1) = -14;
  expected(1, 2) = 8;
  expected(2, 0) = -8;
  expected(2, 1) = -2;
  expected(2, 2) = 4;

  EXPECT_TRUE(matrix1.CalcComplements().EqMatrix(expected));
}