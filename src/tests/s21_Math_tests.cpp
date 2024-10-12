#include <gtest/gtest.h>

#include "../s21_matrix_oop.hpp"

using namespace S21;

TEST(SumTest, Test1) {
  S21Matrix matrix1{1, 1};
  matrix1[0][0] = 1.0;
  S21Matrix matrix2{2, 1};
  matrix2[0][0] = 2.0;
  matrix2[0][0] = 2.0;

  EXPECT_THROW(matrix1.SumMatrix(matrix2), std::runtime_error);
}

TEST(SumTest, Test2) {
  S21Matrix matrix1{2, 2};
  matrix1[0][0] = 1.0;
  matrix1[0][1] = 1.0;
  matrix1[1][0]= 1.0;
  matrix1[1][1] = 1.0;
  S21Matrix matrix2{2, 2};
  matrix2[0][0] = 1.0;
  matrix2[0][1] = 1.0;
  matrix2[1][0]= 1.0;
  matrix2[1][1] = 1.0;
  S21Matrix expected{2, 2};
  expected[0][0] = 2.0;
  expected[0][1] = 2.0;
  expected[1][0] = 2.0;
  expected[1][1] = 2.0;
  matrix1.SumMatrix(matrix2);
  EXPECT_TRUE(matrix1.EqMatrix(expected));
}

TEST(SubTest, Test1) {
  S21Matrix matrix1{1, 1};
  matrix1[0][0] = 1.0;
  S21Matrix matrix2{2, 1};
  matrix2[0][0] = 2.0;
  matrix2[0][0] = 2.0;

  EXPECT_THROW(matrix1.SubMatrix(matrix2), std::runtime_error);
}

TEST(SubTest, Test2) {
  S21Matrix matrix1{2, 2};
  matrix1[0][0] = 1.0;
  matrix1[0][1] = 1.0;
  matrix1[1][0]= 1.0;
  matrix1[1][1] = 1.0;
  S21Matrix matrix2{2, 2};
  matrix2[0][0] = 1.0;
  matrix2[0][1] = 1.0;
  matrix2[1][0] = 1.0;
  matrix2[1][1] = 1.0;
  S21Matrix expected{2, 2};
  expected[0][0] = 0.0;
  expected[0][1] = 0.0;
  expected[1][0] = 0.0;
  expected[1][1] = 0.0;
  matrix1.SubMatrix(matrix2);
  EXPECT_TRUE(matrix1.EqMatrix(expected));
}

TEST(MulNumberTest, Test1) {
  S21Matrix matrix1{2, 2};
  matrix1[0][0] = 1.0;
  matrix1[0][1] = 2.0;
  matrix1[1][0] = 3.0;
  matrix1[1][1] = 4.0;
  double mul = 0.5;
  S21Matrix expected{2, 2};
  expected[0][0] = 0.5;
  expected[0][1] = 1.0;
  expected[1][0] = 1.5;
  expected[1][1] = 2.0;
  matrix1.MulNumber(mul);
  EXPECT_TRUE(matrix1.EqMatrix(expected));
}

TEST(MulMatrixTest, Test1) {
  S21Matrix matrix1{2, 2};
  matrix1[0][0] = 1.0;
  matrix1[0][1] = 2.0;
  matrix1[1][0] = 3.0;
  matrix1[1][1] = 4.0;
  S21Matrix matrix2{1, 1};
  matrix2[0][0] = 1.0;

  EXPECT_THROW(matrix1.MulMatrix(matrix2), std::runtime_error);
}

TEST(MulMatrixTest, Test2) {
  S21Matrix matrix1{2, 1};
  matrix1[0][0] = 1.0;
  matrix1[1][0] = 2.0;
  S21Matrix matrix2{1, 2};
  matrix2[0][0] = 1.0;
  matrix2[0][1] = 2.0;
  S21Matrix expected{2, 2};
  expected[0][0] = 1.0;
  expected[0][1] = 2.0;
  expected[1][0] = 2.0;
  expected[1][1] = 4.0;

  matrix1.MulMatrix(matrix2);
  EXPECT_TRUE(matrix1.EqMatrix(expected));
}

TEST(EQoperatorTest, Test1) {
  S21Matrix matrix1{2, 2};
  matrix1[0][0] = 1.0;
  matrix1[0][1] = 1.0;
  matrix1[1][0] = 1.0;
  matrix1[1][1] = 1.0;
  S21Matrix matrix2{2, 2};
  matrix2[0][0] = 1.0;
  matrix2[0][1] = 1.0;
  matrix2[1][0] = 1.0;
  matrix2[1][1] = 1.0;

  EXPECT_TRUE(matrix1 == matrix2);
}

TEST(EQoperatorTest, Test2) {
  S21Matrix matrix1{2, 2};
  matrix1[0][0] = 1.0;
  matrix1[0][1] = 1.0;
  matrix1[1][0] = 1.0;
  matrix1[1][1] = 1.0;
  S21Matrix matrix2{2, 2};
  matrix2[0][0] = 222.0;
  matrix2[0][1] = 333.0;
  matrix2[1][0] = 444.0;
  matrix2[1][1] = 555.0;

  EXPECT_FALSE(matrix1 == matrix2);
}

TEST(PlusOperatorTest, Test1) {
  S21Matrix matrix1{1, 2};
  matrix1[0][0] = 1.0;
  matrix1[0][1] = 1.0;
  S21Matrix matrix2{1, 2};
  matrix2[0][0] = 1.0;
  matrix2[0][1] = 1.0;
  S21Matrix expected{1, 2};
  expected[0][0] = 2.0;
  expected[0][1] = 2.0;

  S21Matrix result = matrix1 + matrix2;
  EXPECT_TRUE(result.EqMatrix(expected));
}

TEST(MinusOperatorTest, Test1) {
  S21Matrix matrix1{1, 2};
  matrix1[0][0] = 1.0;
  matrix1[0][1] = 1.0;
  S21Matrix matrix2{1, 2};
  matrix2[0][0] = 1.0;
  matrix2[0][1] = 1.0;
  S21Matrix expected{1, 2};
  expected[0][0] = 0.0;
  expected[0][1] = 0.0;

  S21Matrix result = matrix1 - matrix2;
  EXPECT_TRUE(result.EqMatrix(expected));
}

TEST(MulOperatorTest, Test1) {
  S21Matrix matrix1{1, 2};
  matrix1[0][0] = 1.0;
  matrix1[0][1] = 1.0;
  double multiplier = 2;
  S21Matrix expected{1, 2};
  expected[0][0] = 2.0;
  expected[0][1] = 2.0;

  S21Matrix result = matrix1 * multiplier;
  EXPECT_TRUE(result.EqMatrix(expected));
}

TEST(MulMatrixOperatorTest, Test1) {
  S21Matrix matrix1{2, 1};
  matrix1[0][0] = 1.0;
  matrix1[1][0] = 2.0;
  S21Matrix matrix2{1, 2};
  matrix2[0][0] = 1.0;
  matrix2[0][1] = 2.0;
  S21Matrix expected{2, 2};
  expected[0][0] = 1.0;
  expected[0][1] = 2.0;
  expected[1][0] = 2.0;
  expected[1][1] = 4.0;

  S21Matrix result = matrix1 * matrix2;
  EXPECT_TRUE(result.EqMatrix(expected));
}

TEST(PlusAssignOperatorTest, Test1) {
  S21Matrix matrix1{1, 2};
  matrix1[0][0] = 1.0;
  matrix1[0][1] = 1.0;
  S21Matrix matrix2{1, 2};
  matrix2[0][0] = 1.0;
  matrix2[0][1] = 1.0;
  S21Matrix expected{1, 2};
  expected[0][0] = 2.0;
  expected[0][1] = 2.0;

  matrix1 += matrix2;
  EXPECT_TRUE(matrix1.EqMatrix(expected));
}

TEST(MinusAssignOperatorTest, Test1) {
  S21Matrix matrix1{1, 2};
  matrix1[0][0] = 1.0;
  matrix1[0][1] = 1.0;
  S21Matrix matrix2{1, 2};
  matrix2[0][0] = 1.0;
  matrix2[0][1] = 1.0;
  S21Matrix expected{1, 2};
  expected[0][0] = 0.0;
  expected[0][1] = 0.0;

  matrix1 -= matrix2;
  EXPECT_TRUE(matrix1.EqMatrix(expected));
}

TEST(MulAssignOperatorTest, Test1) {
  S21Matrix matrix1{1, 2};
  matrix1[0][0] = 1.0;
  matrix1[0][1] = 1.0;
  double multiplier = 2;
  S21Matrix expected{1, 2};
  expected[0][0] = 2.0;
  expected[0][1] = 2.0;

  matrix1 *= multiplier;
  EXPECT_TRUE(matrix1.EqMatrix(expected));
}

TEST(MulAssignMatrixOperatorTest, Test1) {
  S21Matrix matrix1{2, 1};
  matrix1[0][0] = 1.0;
  matrix1[1][0] = 2.0;
  S21Matrix matrix2{1, 2};
  matrix2[0][0] = 1.0;
  matrix2[0][1] = 2.0;
  S21Matrix expected{2, 2};
  expected[0][0] = 1.0;
  expected[0][1] = 2.0;
  expected[1][0] = 2.0;
  expected[1][1] = 4.0;

  matrix1 *= matrix2;
  EXPECT_TRUE(matrix1.EqMatrix(expected));
}

TEST(SetRowsTest, Test1) {
  S21Matrix matrix1{2, 2};
  matrix1[0][0] = 1.0;
  matrix1[0][1] = 1.0;
  matrix1[1][0] = 1.0;
  matrix1[1][1] = 1.0;

  EXPECT_THROW(matrix1.SetRows(-1), std::exception);
}

TEST(SetRowsTest, Test2) {
  S21Matrix matrix1{2, 2};
  matrix1[0][0] = 1.0;
  matrix1[0][1] = 1.0;
  matrix1[1][0] = 1.0;
  matrix1[1][1] = 1.0;
  matrix1.SetRows(1);
  EXPECT_DOUBLE_EQ(matrix1(0, 0), 1);
}

TEST(SetRowsTest, Test3) {
  S21Matrix matrix1{2, 2};
  matrix1[0][0] = 1.0;
  matrix1[0][1] = 1.0;
  matrix1[1][0] = 1.0;
  matrix1[1][1] = 1.0;
  matrix1.SetRows(3);
  EXPECT_DOUBLE_EQ(matrix1(0, 0), 1);
  EXPECT_DOUBLE_EQ(matrix1(2, 0), 0);
}

TEST(SetColsTest, Test1) {
  S21Matrix matrix1{2, 2};
  matrix1[0][0] = 1.0;
  matrix1[0][1] = 1.0;
  matrix1[1][0] = 1.0;
  matrix1[1][1] = 1.0;

  EXPECT_THROW(matrix1.SetCols(-1), std::exception);
}

TEST(SetColsTest, Test2) {
  S21Matrix matrix1{2, 2};
  matrix1[0][0] = 1.0;
  matrix1[0][1] = 1.0;
  matrix1[1][0] = 1.0;
  matrix1[1][1] = 1.0;
  matrix1.SetCols(1);
  EXPECT_DOUBLE_EQ(matrix1(0, 0), 1);
}

TEST(SetColsTest, Test3) {
  S21Matrix matrix1{2, 2};
  matrix1[0][0] = 1.0;
  matrix1[0][1] = 1.0;
  matrix1[1][0] = 1.0;
  matrix1[1][1] = 1.0;
  matrix1.SetCols(3);
  EXPECT_DOUBLE_EQ(matrix1(0, 0), 1);
  EXPECT_DOUBLE_EQ(matrix1(0, 2), 0);
}