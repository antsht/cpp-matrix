#include <gtest/gtest.h>

#include "../s21_matrix_oop.hpp"

using namespace S21;

TEST(CTOR, TestPrint) {
  S21Matrix A{1, 1};
  A(0, 0) = 1;
  A.PrintMatrix();
  ASSERT_EQ(1, 1);
}

TEST(CTOR, Test1) {
  S21Matrix A{2, 2};
  ASSERT_EQ(A.GetRows(), 2);
  ASSERT_EQ(A.GetCols(), 2);
  ASSERT_EQ(A(1, 1), 0);
}

TEST(CTOR, Test2) {
  S21Matrix A = S21Matrix();
  ASSERT_EQ(A.GetRows(), 2);
  ASSERT_EQ(A.GetCols(), 2);
  ASSERT_EQ(A(1, 1), 0);
}

TEST(CTOR, Test3) { EXPECT_THROW(S21Matrix A(-1, -1), std::length_error); }

TEST(CTOR, Test4) {
  S21Matrix A{2, 2};
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(1, 0) = 3;
  A(1, 1) = 4;
  S21Matrix B = S21Matrix(A);
  ASSERT_EQ(A.EqMatrix(B), true);
}

TEST(CTOR, Test5) {
  S21Matrix A{2, 2};
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(1, 0) = 3;
  A(1, 1) = 4;
  S21Matrix ref{2, 2};
  ref(0, 0) = 1;
  ref(0, 1) = 2;
  ref(1, 0) = 3;
  ref(1, 1) = 4;
  S21Matrix B = std::move(A);
  ASSERT_EQ(ref.EqMatrix(B), true);
}

TEST(CTOR, Test6) {
  S21Matrix A{2, 2};
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(1, 0) = 3;
  A(1, 1) = 4;
  S21Matrix ref{2, 2};
  ref(0, 0) = 1;
  ref(0, 1) = 2;
  ref(1, 0) = 3;
  ref(1, 1) = 4;
  S21Matrix B{2, 2};
  B = A;
  ASSERT_EQ(ref.EqMatrix(B), true);
}

TEST(SetDimensions, Test1) {
  S21Matrix A{2, 2};
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(1, 0) = 3;
  A(1, 1) = 4;
  A.SetRows(3);
  A.SetCols(3);
  ASSERT_EQ(A.GetRows(), 3);
  ASSERT_EQ(A.GetCols(), 3);
}

TEST(IndexOutOfRange, Test1) {
  S21Matrix A{2, 2};
  A(0, 0) = 555;
  A(0, 1) = 2;
  A(1, 0) = 3;
  A(1, 1) = 4;
  EXPECT_THROW(A(-1, -1), std::out_of_range);
}