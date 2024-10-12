#include <gtest/gtest.h>

#include "../s21_matrix_oop.hpp"

using namespace S21;

TEST(EqTest, Test1) {
  S21Matrix matrix1{2, 2};
  S21Matrix matrix2{2, 2};
  matrix1[0][0] = 999.0;
  matrix1[0][1] = 0.0;
  matrix1[1][0] = 0.0;
  matrix1[1][1] = 0.0;
  matrix2[0][0] = 1.0;
  matrix2[0][1] = 0.0;
  matrix2[1][0] = 0.0;
  matrix2[1][1] = 0.0;
  EXPECT_FALSE(matrix1.EqMatrix(matrix2));
}

TEST(EqTest, Test2) {
  S21Matrix matrix1{2, 2};
  S21Matrix matrix2{2, 2};
  matrix1[0][0] = 1.0;
  matrix1[0][1] = 0.0;
  matrix1[1][0] = 0.0;
  matrix1[1][1] = 0.0;
  matrix2[0][0] = 1.0;
  matrix2[0][1] = 0.0;
  matrix2[1][0] = 0.0;
  matrix2[1][1] = 0.0;
  EXPECT_TRUE(matrix1.EqMatrix(matrix2));
}

TEST(EqTest, Test3) {
  S21Matrix matrix1{5, 5};
  S21Matrix matrix2{5, 5};
  matrix1.RandomizeMatrix();
  matrix2.RandomizeMatrix();
  EXPECT_FALSE(matrix1.EqMatrix(matrix2));
}