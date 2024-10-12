#ifndef S21_MATRIX_OOP_HPP_
#define S21_MATRIX_OOP_HPP_

#include <exception>
#include <iostream>
#include <random>
#include <vector>

static constexpr double EPSILON = 1e-6;

namespace S21 {

/// @brief A class representing a matrix with dynamic memory allocation.
/// @tparam T The type of the matrix elements.
/// @note T must be an arithmetic type.
template <typename T = double>
class S21Matrix {
  static_assert(std::is_arithmetic_v<T>, "T must be an arithmetic type");
  using matrix_t = std::vector<std::vector<T>>;

 private:
  std::size_t rows_ = 0;
  std::size_t cols_ = 0;  // Rows and columns
  matrix_t matrix_;       // Pointer to the memory where the matrix is allocated

 public:
  /// @brief Default constructor.
  /// @note Initializes a 2x2 matrix.
  S21Matrix();

  /// @brief Constructor with specified dimensions.
  /// @param rows Number of rows.
  /// @param cols Number of columns.
  S21Matrix(std::size_t rows, std::size_t cols);

  /// @brief Copy constructor.
  /// @param other The S21Matrix object to be copied.
  S21Matrix(const S21Matrix &other);

  /// @brief Move constructor.
  /// @param other The S21Matrix object to be moved.
  S21Matrix(S21Matrix &&other) noexcept;

  /// @brief Destructor.
  ~S21Matrix();

  std::vector<T> &operator[](std::size_t row);
  const std::vector<T> &operator[](std::size_t row) const;

  /// @brief Prints the contents of the matrix to the console.
  /// @note Used to display the current state of the matrix by printing its
  /// elements to the console.
  /// @note Primarily intended for debugging and testing purposes.
  void PrintMatrix() const;

  /// @brief Randomizes the elements of the matrix.
  /// @note Generates random values for all the elements of the matrix and
  /// assigns them to the corresponding matrix elements.
  /// @note Useful for initializing a matrix with random data, for example in
  /// testing or demonstration scenarios.
  void RandomizeMatrix();

  /// @brief Checks if two S21Matrix objects are equal.
  /// @note Compares the dimensions and elements of two S21Matrix objects to
  /// determine if they are equal.
  bool EqMatrix(const S21Matrix &other) const;

  /// @brief Adds the elements of the provided S21Matrix object to the current
  /// S21Matrix object.
  /// @note Performs an element-wise addition of the elements of the provided
  /// S21Matrix object to the corresponding elements of the current S21Matrix
  /// object.
  void SumMatrix(const S21Matrix &other);

  /// @brief Subtracts the elements of the provided S21Matrix object from the
  /// current S21Matrix object.
  /// @note Performs an element-wise subtraction of the elements of the provided
  /// S21Matrix object from the corresponding elements of the current S21Matrix
  /// object.
  void SubMatrix(const S21Matrix &other);

  /// @brief Multiplies the matrix by a scalar value.
  /// @note Multiplies all elements of the current S21Matrix object by the
  /// provided scalar value.
  /// @note Useful for scaling the matrix by a constant factor.
  void MulNumber(const T num);

  /// @brief Multiplies the current S21Matrix object by the provided S21Matrix
  /// object.
  /// @note Performs a matrix multiplication of the current S21Matrix object
  /// with the provided S21Matrix object.
  /// @note The number of columns in the current S21Matrix object must be equal
  /// to the number of rows in the provided S21Matrix object for the operation
  /// to succeed.
  void MulMatrix(const S21Matrix &other);

  /// @brief Transposes the current S21Matrix object.
  /// @note Creates a new S21Matrix object that is the transpose of the current
  /// S21Matrix object.
  /// @note The transpose of a matrix is obtained by interchanging the rows and
  /// columns of the matrix.
  /// @return A new S21Matrix object that is the transpose of the current
  /// S21Matrix object.
  S21Matrix Transpose();

  /// @brief Calculates the matrix of cofactors (complements) of the current
  /// S21Matrix object.
  /// @note Creates a new S21Matrix object that is the matrix of cofactors
  /// (complements) of the current S21Matrix object.
  /// @note The cofactor of an element is the determinant of the submatrix
  /// formed by deleting the row and column containing that element, multiplied
  /// by (-1)^(i+j), where i is the row index and j is the column index of the
  /// element.
  /// @return A new S21Matrix object that is the matrix of cofactors
  /// (complements) of the current S21Matrix object.
  S21Matrix CalcComplements();

  /// @brief Calculates the determinant of the current S21Matrix object.
  /// @note Calculates the determinant of the current S21Matrix object.
  /// @note The determinant is a scalar value that is a property of the matrix
  /// and is calculated based on the values of the matrix elements.
  /// @note The determinant can be used to determine various properties of the
  /// matrix, such as whether it is invertible.
  /// @return The determinant of the current S21Matrix object.
  T Determinant();

  /// @brief Calculates the inverse of the current S21Matrix object.
  /// @note Creates a new S21Matrix object that is the inverse of the current
  /// S21Matrix object.
  /// @note The inverse of a matrix is another matrix that, when multiplied by
  /// the original matrix, results in the identity matrix.
  /// @note The inverse of a matrix only exists if the determinant of the matrix
  /// is non-zero.
  /// @return A new S21Matrix object that is the inverse of the current
  /// S21Matrix object, or an empty matrix if the current matrix is not
  /// invertible.
  S21Matrix InverseMatrix();

  /// @brief Adds two S21Matrix objects together.
  /// @note Adds the elements of the current S21Matrix object to the elements of
  /// the provided S21Matrix object, and returns a new S21Matrix object that is
  /// the result of the addition.
  /// @param other The S21Matrix object to add to the current object.
  /// @return A new S21Matrix object that is the result of adding the current
  /// object to the provided object.
  S21Matrix operator+(const S21Matrix &other);

  /// @brief Subtracts two S21Matrix objects.
  /// @note Subtracts the elements of the provided S21Matrix object from the
  /// elements of the current S21Matrix object, and returns a new S21Matrix
  /// object that is the result of the subtraction.
  /// @param other The S21Matrix object to subtract from the current object.
  /// @return A new S21Matrix object that is the result of subtracting the
  /// provided object from the current object.
  S21Matrix operator-(const S21Matrix &other);

  /// @brief Multiplies the current S21Matrix object by a scalar value.
  /// @note Multiplies each element of the current S21Matrix object by the
  /// provided scalar value, and returns a new S21Matrix object that is the
  /// result of the multiplication.
  /// @param num The scalar value to multiply the matrix by.
  /// @return A new S21Matrix object that is the result of multiplying the
  /// current object by the provided scalar value.
  S21Matrix operator*(const T num);

  /// @brief Multiplies two S21Matrix objects.
  /// @note Multiplies the elements of the current S21Matrix object by the
  /// elements of the provided S21Matrix object, and returns a new S21Matrix
  /// object that is the result of the multiplication.
  /// @param other The S21Matrix object to multiply with the current object.
  /// @return A new S21Matrix object that is the result of multiplying the
  /// current object by the provided object.
  S21Matrix operator*(const S21Matrix &other);

  /// @brief Compares two S21Matrix objects for equality.
  /// @note Compares the elements of the current S21Matrix object with the
  /// elements of the provided S21Matrix object. If all elements are equal, it
  /// returns true, otherwise it returns false.
  /// @param other The S21Matrix object to compare with the current object.
  /// @return true if the two S21Matrix objects are equal, false otherwise.
  bool operator==(const S21Matrix &other);

  /// @brief Assignment operator for S21Matrix.
  /// @note Assigns the contents of the provided S21Matrix object to the current
  /// S21Matrix object. It performs a deep copy, ensuring that the new object is
  /// an independent copy of the provided object.
  /// @param other The S21Matrix object to assign to the current object.
  /// @return A reference to the current S21Matrix object after the assignment.
  S21Matrix &operator=(const S21Matrix &other);

  /// @brief Move assignment operator for S21Matrix.
  /// @note Moves the contents of the provided S21Matrix object to the current
  /// S21Matrix object. It performs a move operation, ensuring that the new
  /// object takes ownership of the resources of the provided object, and the
  /// provided object is left in a valid but unspecified state.
  /// @param other The S21Matrix object to move to the current object.
  /// @return A reference to the current S21Matrix object after the move
  /// assignment.
  S21Matrix &operator=(S21Matrix &&other) noexcept;

  /// @brief Addition assignment operator for S21Matrix.
  /// @note Adds the elements of the provided S21Matrix object to the elements
  /// of the current S21Matrix object, and assigns the result back to the
  /// current object.
  /// @param other The S21Matrix object to add to the current object.
  /// @return A reference to the current S21Matrix object after the addition.
  S21Matrix &operator+=(const S21Matrix &other);

  /// @brief Subtraction assignment operator for S21Matrix.
  /// @note Subtracts the elements of the provided S21Matrix object from the
  /// elements of the current S21Matrix object, and assigns the result back to
  /// the current object.
  /// @param other The S21Matrix object to subtract from the current object.
  /// @return A reference to the current S21Matrix object after the subtraction.
  S21Matrix &operator-=(const S21Matrix &other);

  /// @brief Multiplication assignment operator for S21Matrix.
  /// @note Multiplies the elements of the current S21Matrix object by the
  /// provided scalar value, and assigns the result back to the current object.
  /// @param num The scalar value to multiply the matrix elements by.
  /// @return A reference to the current S21Matrix object after the
  /// multiplication.
  S21Matrix &operator*=(const T num);

  /// @brief Multiplication assignment operator for S21Matrix.
  /// @note Multiplies the elements of the current S21Matrix object by the
  /// elements of the provided S21Matrix object, and assigns the result back to
  /// the current object.
  /// @param other The S21Matrix object to multiply the current object by.
  /// @return A reference to the current S21Matrix object after the
  /// multiplication.
  S21Matrix &operator*=(const S21Matrix &other);

  /// @brief Overloaded array-like access operator for S21Matrix.
  /// @note Allows accessing and modifying the elements of the S21Matrix object
  /// using array-like syntax, e.g. `matrix(i, j)`.
  /// @param i The row index of the element to access.
  /// @param j The column index of the element to access.
  /// @return A reference to the element at the specified row and column.
  T &operator()(std::size_t row, std::size_t col);

  /// @brief Gets the number of rows in the S21Matrix object.
  /// @return The number of rows in the S21Matrix object.
  std::size_t GetRows() const;

  /// @brief Gets the number of columns in the S21Matrix object.
  /// @return The number of columns in the S21Matrix object.
  std::size_t GetCols() const;

  /// @brief Sets the number of rows in the S21Matrix object.
  /// @param rows The new number of rows for the S21Matrix object.
  void SetRows(std::size_t rows);

  /// @brief Sets the number of columns in the S21Matrix object.
  /// @param cols The new number of columns for the S21Matrix object.
  void SetCols(std::size_t cols);

  /// @brief Gets the minor matrix of the current S21Matrix object.
  /// @param row The row index to remove from the current matrix.
  /// @param col The column index to remove from the current matrix.
  /// @return The minor matrix of the current S21Matrix object.
  S21Matrix GetMinor(std::size_t row, std::size_t col);

  /// @brief Swaps the rows at the specified indices in the S21Matrix object.
  /// @param i The index of the first row to swap.
  /// @param j The index of the second row to swap.
  void SwapRows(std::size_t i, std::size_t j);
};

template <typename T>
S21Matrix<T>::S21Matrix(std::size_t rows, std::size_t cols)
    : rows_(rows), cols_(cols), matrix_(rows_, std::vector<T>(cols_)){};

template <typename T>
S21Matrix<T>::S21Matrix() : S21Matrix(2, 2){};

template <typename T>
S21Matrix<T>::S21Matrix(const S21Matrix<T> &other)
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {}

template <typename T>
S21Matrix<T>::S21Matrix(S21Matrix<T> &&other) noexcept
    : rows_(other.rows_),
      cols_(other.cols_),
      matrix_(std::move(other.matrix_)) {}

template <typename T>
S21Matrix<T>::~S21Matrix() = default;

template <typename T>
std::vector<T> &S21Matrix<T>::operator[](std::size_t row) {
  return matrix_[row];
}

template <typename T>
const std::vector<T> &S21Matrix<T>::operator[](std::size_t row) const {
  return matrix_[row];
}

template <typename T>
void S21Matrix<T>::PrintMatrix() const {
  for (const auto &row : matrix_) {
    for (const auto &value : row) {
      std::cout << value << " ";
    }
    std::cout << '\n';
  }
}

template <typename T>
void S21Matrix<T>::RandomizeMatrix() {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  std::uniform_real_distribution<T> dis(__DBL_MIN__, __DBL_MAX__);
  for (auto &row : matrix_) {
    for (auto &element : row) {
      element = dis(gen);
    }
  }
}

template <typename T>
bool S21Matrix<T>::EqMatrix(const S21Matrix<T> &other) const {
  return matrix_ == other.matrix_;
}

template <typename T>
void S21Matrix<T>::SumMatrix(const S21Matrix<T> &other) {
  if (rows_ != other.rows_ || cols_ != other.cols_)
    throw std::runtime_error("Matrices dimensions are not equal");

  for (std::size_t i = 0; i < rows_; i++) {
    for (std::size_t j = 0; j < cols_; j++) {
      matrix_[i][j] += other.matrix_[i][j];
    }
  }
}

template <typename T>
void S21Matrix<T>::SubMatrix(const S21Matrix<T> &other) {
  if (rows_ != other.rows_ || cols_ != other.cols_)
    throw std::runtime_error("Matrices dimensions are not equal");

  for (std::size_t i = 0; i < rows_; i++) {
    for (std::size_t j = 0; j < cols_; j++) {
      matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}

template <typename T>
void S21Matrix<T>::MulNumber(const T num) {
  for (std::size_t i = 0; i < rows_; i++) {
    for (std::size_t j = 0; j < cols_; j++) {
      matrix_[i][j] *= num;
    }
  }
}

template <typename T>
void S21Matrix<T>::MulMatrix(const S21Matrix<T> &other) {
  if (cols_ != other.rows_)
    throw std::runtime_error(
        "Matrix dimensions are incompatible for multiplication");
  S21Matrix<T> result(rows_, other.cols_);
  for (std::size_t i = 0; i < rows_; i++) {
    for (std::size_t j = 0; j < other.cols_; j++) {
      T sum = 0;
      for (std::size_t k = 0; k < cols_; k++)
        sum += matrix_[i][k] * other.matrix_[k][j];
      result.matrix_[i][j] = sum;
    }
  }
  *this = std::move(result);
}

template <typename T>
S21Matrix<T> S21Matrix<T>::Transpose() {
  if (rows_ != cols_)
    throw std::runtime_error("Matrix must be square to be transposed");
  S21Matrix<T> result(cols_, rows_);
  for (std::size_t i = 0; i < rows_; i++) {
    for (std::size_t j = 0; j < cols_; j++) {
      result.matrix_[j][i] = matrix_[i][j];
    }
  }

  return result;
}

template <typename T>
S21Matrix<T> S21Matrix<T>::CalcComplements() {
  if (rows_ != cols_ || rows_ < 2)
    throw std::runtime_error("Matrix must be square and have at least 2 rows");

  S21Matrix<T> result(rows_, cols_);

  for (std::size_t i = 0; i < rows_; i++) {
    for (std::size_t j = 0; j < cols_; j++) {
      S21Matrix<T> minor = GetMinor(i, j);
      T minor_det = minor.Determinant();
      result.matrix_[i][j] = pow(-1, i + j) * minor_det;
    }
  }

  return result;
}

template <typename T>
T S21Matrix<T>::Determinant() {
  if (rows_ != cols_)
    throw std::runtime_error("Matrices dimensions are not equal");

  long double l_result = 1.0;
  S21Matrix<T> temp(*this);

  std::size_t n = temp.rows_;
  for (std::size_t i = 0; i < n; ++i) {
    if (std::abs(temp.matrix_[i][i]) < EPSILON) {
      std::size_t j = i + 1;
      while (j < n && std::abs(temp.matrix_[j][i]) < EPSILON) ++j;
      if (j < n) {
        temp.SwapRows(i, j);
        l_result *= -1;
      } else {
        l_result = 0;
        break;
      }
    }
    T diag_elem = temp.matrix_[i][i];
    if (std::abs(diag_elem) > EPSILON) {
      l_result *= diag_elem;
      for (std::size_t k = 0; k < n; ++k) {
        temp.matrix_[i][k] /= diag_elem;
      }
      for (std::size_t j = 0; j < n; ++j) {
        if (j != i) {
          long double multiplier = temp.matrix_[j][i];
          for (std::size_t k = 0; k < n; ++k) {
            temp.matrix_[j][k] -= (T)(multiplier * temp.matrix_[i][k]);
          }
        }
      }
    }
  }

  if (std::abs(l_result) > std::numeric_limits<double>::max())
    throw std::overflow_error("Value exceeds DBL_MAX");
  else
    return (T)l_result;
}

template <typename T>
S21Matrix<T> S21Matrix<T>::InverseMatrix() {
  T det = Determinant();
  if (det == 0) throw std::runtime_error("Matrix is not invertible");

  S21Matrix<T> result{rows_, cols_};
  if (rows_ == 1)
    result.matrix_[0][0] = 1.0 / matrix_[0][0];
  else {
    result = CalcComplements().Transpose();
    result.MulNumber(1.0 / det);
  }
  return result;
}

template <typename T>
S21Matrix<T> S21Matrix<T>::operator+(const S21Matrix<T> &other) {
  S21Matrix<T> result(*this);
  result.SumMatrix(other);
  return result;
}

template <typename T>
S21Matrix<T> S21Matrix<T>::operator-(const S21Matrix<T> &other) {
  S21Matrix<T> result(*this);
  result.SubMatrix(other);
  return result;
}

template <typename T>
S21Matrix<T> S21Matrix<T>::operator*(const T num) {
  S21Matrix<T> result(*this);
  result.MulNumber(num);
  return result;
}

template <typename T>
S21Matrix<T> S21Matrix<T>::operator*(const S21Matrix<T> &other) {
  S21Matrix<T> result(*this);
  result.MulMatrix(other);
  return result;
}

template <typename T>
bool S21Matrix<T>::operator==(const S21Matrix<T> &other) {
  return EqMatrix(other);
}

template <typename T>
S21Matrix<T> &S21Matrix<T>::operator=(const S21Matrix<T> &other) {
  if (&other != this) {
    rows_ = other.rows_;
    cols_ = other.cols_;
    matrix_t tmp = other.matrix_;
    std::swap(matrix_, tmp);
  }
  return *this;
}

template <typename T>
S21Matrix<T> &S21Matrix<T>::operator=(S21Matrix<T> &&other) noexcept {
  if (this != &other) {
    std::swap(rows_, other.rows_);
    std::swap(cols_, other.cols_);
    std::swap(matrix_, other.matrix_);
  }
  return *this;
}

template <typename T>
S21Matrix<T> &S21Matrix<T>::operator+=(const S21Matrix<T> &other) {
  SumMatrix(other);
  return *this;
}

template <typename T>
S21Matrix<T> &S21Matrix<T>::operator-=(const S21Matrix<T> &other) {
  SubMatrix(other);
  return *this;
}

template <typename T>
S21Matrix<T> &S21Matrix<T>::operator*=(const T num) {
  MulNumber(num);
  return *this;
}

template <typename T>
S21Matrix<T> &S21Matrix<T>::operator*=(const S21Matrix<T> &other) {
  MulMatrix(other);
  return *this;
}
template <typename T>
size_t S21Matrix<T>::GetRows() const {
  return rows_;
}

template <typename T>
size_t S21Matrix<T>::GetCols() const {
  return cols_;
}

template <typename T>
void S21Matrix<T>::SetRows(std::size_t rows) {
  if (rows == 0) throw std::out_of_range("Number of rows must be > 0");
  S21Matrix<T> tmp(rows, cols_);
  for (std::size_t i = 0; i < rows; i++) {
    for (std::size_t j = 0; j < cols_; j++) {
      tmp.matrix_[i][j] = (i < rows_) ? matrix_[i][j] : 0;
    }
  }
  *this = std::move(tmp);
}

template <typename T>
void S21Matrix<T>::SetCols(std::size_t cols) {
  if (cols == 0) throw std::out_of_range("Number of columns must be > 0");
  S21Matrix<T> tmp(rows_, cols);
  for (std::size_t i = 0; i < rows_; i++) {
    for (std::size_t j = 0; j < cols; j++) {
      tmp.matrix_[i][j] = (j < cols_) ? matrix_[i][j] : 0;
    }
  }
  *this = std::move(tmp);
}

template <typename T>
T &S21Matrix<T>::operator()(std::size_t i, std::size_t j) {
  if (i >= rows_ || j >= cols_) {
    throw std::out_of_range("Row or column index out of range");
  }
  return matrix_[i][j];
}

template <typename T>
void S21Matrix<T>::SwapRows(std::size_t i, std::size_t j) {
  std::swap(matrix_[i], matrix_[j]);
}

template <typename T>
S21Matrix<T> S21Matrix<T>::GetMinor(std::size_t row, std::size_t col) {
  if (row >= rows_ || col >= cols_) {
    throw std::out_of_range("Row or column index out of range");
  }

  S21Matrix<T> result(rows_ - 1, cols_ - 1);

  for (std::size_t i = 0, k = 0; i < rows_; ++i) {
    if (i == row) {
      continue;
    }
    for (std::size_t j = 0, l = 0; j < cols_; ++j) {
      if (j == col) continue;
      result.matrix_[k][l++] = matrix_[i][j];
    }
    ++k;
  }
  return result;
}

}  // namespace S21

#endif  // S21_MATRIX_OOP_HPP_
