#pragma once
#include "/Users/kalmar4ic/Documents/VSCodeC++/Lab3/src/lib/Fraction.h"
template <class T>
class TMatrix
{
private:
	T** matrix;
	int rows;
	int cols;

public:
	TMatrix();
	TMatrix(const TMatrix& TM);
	~TMatrix();

	istream& In(istream& stream);
	ostream& Out(ostream& stream) const;

	void SetRandomValue(int min, int max, int rows, int cols);
	void generateRandomValues(int min, int max);
	void deleteMas();
	T mainDiagonal();
	T findMinNumber();
};

template<class T>
inline TMatrix<T>::TMatrix()
{
	rows = 0;
	cols = 0;
	matrix = nullptr;
}

template<class T>
inline TMatrix<T>::TMatrix(const TMatrix& TM)
{
	rows = TM.rows;
	cols = TM.cols;
	matrix = new T * [rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new T[cols];
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			matrix[i][j] = TM.matrix[i][j];
		}
	}
}

template<class T>
inline TMatrix<T>::~TMatrix()
{
	deleteMas();
}

template<class T>
inline istream& TMatrix<T>::In(istream& stream)
{
	deleteMas();
	if (&stream == &cin)
	{
		cout << "enter the number of rows and cols ";
	}
	stream >> rows >> cols;
	matrix = new T * [rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new T[cols];
	}

	for (int j = 0; j < rows; j++)
	{
		for (int k = 0; k < cols; k++)
		{
			stream >> matrix[j][k];
		}
	}
	return stream;
}

template<class T>
inline ostream& TMatrix<T>::Out(ostream& stream) const
{
	if (&stream != &cout)
	{
		stream << rows << " " << cols << endl;
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			stream << matrix[i][j] << " ";
		}
		stream << endl;
	}
	return stream;
}

template<class T>
inline void TMatrix<T>::SetRandomValue(int min, int max, int rows, int cols)
{
	matrix[rows][cols] = rand() % (max - min + min);
}

template<>
inline void TMatrix<Fraction>::SetRandomValue(int min, int max, int rows, int cols)
{
	int denominator = rand() % (max - min + min);
	int numerator = rand() % (max - min + min);
	Fraction F(numerator, denominator);
	matrix[rows][cols] = F;
}

template<class T>
inline void TMatrix<T>::generateRandomValues(int min, int max)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			matrix[i][j] = rand() % (max - min + min);;
		}
	}
}

template <class T>
inline void TMatrix<T>::deleteMas()
{
	for (int i = 0; i < rows; ++i)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
	rows = 0;
	cols = 0;
	matrix = nullptr;
}

template<>
inline void TMatrix<Fraction>::generateRandomValues(int min, int max)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			int denominator = rand() % (max - min) + min + 1;;
			int numerator = rand() % (max - min) + min;
			Fraction F(numerator, denominator);
			matrix[i][j] = F;
		}
	}
}

template<class T>
inline T TMatrix<T>::mainDiagonal()
{
	T count = matrix[0][0];
	for (int i = 0, j = 0; i < rows && i < cols; i++, j++)
	{
		count += matrix[i][j];
	}
	count -= matrix[0][0];
	//cout << "Main Diagonal: " << count << endl;
	return count;
}

template<class T>
inline T TMatrix<T>::findMinNumber()
{
	T averageValue = matrix[0][0];
	T min;
	T max = matrix[0][0];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			averageValue += matrix[i][j];
			if (matrix[i][j] > max)
			{
				max = matrix[i][j];
			}
		}
	}
	averageValue -= matrix[0][0];
	averageValue /= (rows + cols);
	min = max;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (matrix[i][j] > averageValue)
			{
				if (matrix[i][j] < min)
				{
					min = matrix[i][j];
				}
			}
		}
	}
	//cout << "Min number: " << min << endl;
	return min;
}

template<class T>
istream& operator>>(istream& stream, TMatrix<T>& TM)
{
	return TM.In(stream);;
}

template<class T>
ostream& operator<<(ostream& stream, const TMatrix<T>& TM)
{
	TM.Out(stream);
	return stream;
}
