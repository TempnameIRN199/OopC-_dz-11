#pragma once
#include "Header.h"
// Создайте шаблонный класс матрица.
// Необходимо реализовать динамическое выделение памяти, очистку памяти, заполнение матрицы с клавиатуры, заполнение случайными значениями, отображение матрицы, арифметические операции с помощью перегруженных операторов (+, –, *, /), поиск максимального и минимального элемента.

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

