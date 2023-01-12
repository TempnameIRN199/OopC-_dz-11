#include "memory.h"

template <typename T> Matrix<T>::Matrix(int rows, int cols)
{
	this->rows = rows;
	this->cols = cols;
	matrix = new T * [rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new T[cols];
	}
}

template <typename T> Matrix<T>::~Matrix()
{
	for (int i = 0; i < rows; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

template <typename T> void Matrix<T>::fillMatrix()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << "Enter element [" << i << "][" << j << "]: ";
			cin >> matrix[i][j];
		}
	}
}

template <typename T> void Matrix<T>::fillMatrixRandom()
{
	srand(time(NULL));
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			matrix[i][j] = rand() % 10;
		}
	}
}

template <typename T> void Matrix<T>::showMatrix()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << setw(3) << matrix[i][j];
		}
		cout << endl;
	}
}

template <typename T> Matrix<T> Matrix<T>::operator+(Matrix<T>& m)
{
	Matrix<T> result(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			result.matrix[i][j] = matrix[i][j] + m.matrix[i][j];
		}
	}
	return result;
}

template <typename T> Matrix<T> Matrix<T>::operator-(Matrix<T>& m)
{
	Matrix<T> result(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			result.matrix[i][j] = matrix[i][j] - m.matrix[i][j];
		}
	}
	return result;
}

template <typename T> Matrix<T> Matrix<T>::operator*(Matrix<T>& m)
{
	Matrix<T> result(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			result.matrix[i][j] = matrix[i][j] * m.matrix[i][j];
		}
	}
	return result;
}

template <typename T> Matrix<T> Matrix<T>::operator/(Matrix<T>& m)
{
	Matrix<T> result(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			result.matrix[i][j] = matrix[i][j] / m.matrix[i][j];
		}
	}
	return result;
}

template <typename T> T Matrix<T>::findMax()
{
	T max = matrix[0][0];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (matrix[i][j] > max)
			{
				max = matrix[i][j];
			}
		}
	}
	return max;
}

template <typename T> T Matrix<T>::findMin()
{
	T min = matrix[0][0];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (matrix[i][j] < min)
			{
				min = matrix[i][j];
			}
		}
	}
	return min;
}

int main()
{
	Matrix<int> m1(3, 3);
	m1.fillMatrixRandom();
	m1.showMatrix();
	cout << "Max: " << m1.findMax() << endl;
	cout << "Min: " << m1.findMin() << endl;
	Matrix<int> m2(3, 3);
	m2.fillMatrixRandom();
	m2.showMatrix();
	cout << "Max: " << m2.findMax() << endl;
	cout << "Min: " << m2.findMin() << endl;
	Matrix<double> m3(3, 3);
	m3.fillMatrixRandom();
	m3.showMatrix();
	cout << "Max: " << m3.findMax() << endl;
	cout << "Min: " << m3.findMin() << endl;
	Matrix<double> m4(3, 3);
	m4.fillMatrixRandom();
	m4.showMatrix();
	cout << "Max: " << m4.findMax() << endl;
	cout << "Min: " << m4.findMin() << endl;
	m1.~Matrix();
	m2.~Matrix();
	m3.~Matrix();
	m4.~Matrix();
	return 0;
}