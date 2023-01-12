#pragma once
#include "Header.h"

template <typename T> class Matrix
{
private:
	int rows;
	int cols;
	T** matrix;
public:
	Matrix(int rows, int cols);
	~Matrix();
	void fillMatrix();
	void fillMatrixRandom();
	void showMatrix();
	Matrix<T> operator+(Matrix<T>& m);
	Matrix<T> operator-(Matrix<T>& m);
	Matrix<T> operator*(Matrix<T>& m);
	Matrix<T> operator/(Matrix<T>& m);
	T findMax();
	T findMin();
};

