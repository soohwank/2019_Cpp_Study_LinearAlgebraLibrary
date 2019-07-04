#ifndef _MATRIX3D_HPP_
#define _MATRIX3D_HPP_

#include <iostream>
#include <cassert>

using namespace std;

namespace lal
{

class MatrixXd
{
public:
	// default constructor
	MatrixXd() = delete;

	// constructor
	MatrixXd(const size_t rows, const size_t cols)
	: m_rows(rows), m_cols(cols)
	{
		// memory allocation
		allocateMemory();

		// initialization
		zero();
	}

	// copy constructor
	MatrixXd(const MatrixXd &m)
	: m_rows(m.m_rows), m_cols(m.m_cols)
	{
		// memory allocation
		allocateMemory();

		// initialization
		for(size_t row = 0; row < m_rows; row++)
		{
			for (size_t col = 0; col < m_cols; col++)
			{
				m_ppData[row][col] = m.m_ppData[row][col];
			}
		}
	}

	// destructor
	~MatrixXd()
	{
		dellocateMemory();
	}

	// geter
	size_t nrows() const
	{
		return m_rows;
	}

	size_t ncols() const
	{
		return m_cols;
	}

	double get(const size_t row, const size_t col) const
	{
		// condition check
		assert(row < m_rows && col < m_cols);

		return m_ppData[row][col];
	}

	void set(const size_t row, const size_t col, const double value)
	{
		// condition check
		assert(row < m_rows && col < m_cols);

		m_ppData[row][col] = value;
	}

	// addition
	MatrixXd operator+(const double s) const
	{
		MatrixXd result(m_rows, m_cols);
		for(size_t row = 0; row < m_rows; row++)
		{
			for (size_t col = 0; col < m_cols; col++)
			{
				result.m_ppData[row][col] = m_ppData[row][col] + s;
			}
		}
		return result;
	}

	MatrixXd operator+(const MatrixXd &m) const
	{
		// condition check
		assert(m_rows == m.m_rows && m_cols == m.m_cols);

		MatrixXd result(m_rows, m_cols);
		for(size_t row = 0; row < m_rows; row++)
		{
			for (size_t col = 0; col < m_cols; col++)
			{
				result.m_ppData[row][col] = m_ppData[row][col] + m.m_ppData[row][col];
			}
		}
		return result;
	}

	// subtraction
	MatrixXd operator-(const double s) const
	{
		MatrixXd result(m_rows, m_cols);
		for(size_t row = 0; row < m_rows; row++)
		{
			for (size_t col = 0; col < m_cols; col++)
			{
				result.m_ppData[row][col] = m_ppData[row][col] - s;
			}
		}
		return result;
	}

	MatrixXd operator-(const MatrixXd &m) const
	{
		// condition check
		assert(m_rows == m.m_rows && m_cols == m.m_cols);

		MatrixXd result(m_rows, m_cols);
		for(size_t row = 0; row < m_rows; row++)
		{
			for (size_t col = 0; col < m_cols; col++)
			{
				result.m_ppData[row][col] = m_ppData[row][col] - m.m_ppData[row][col];
			}
		}
		return result;
	}

	// multiplication
	MatrixXd operator-(const double s) const
	{
		MatrixXd result(m_rows, m_cols);
		for(size_t row = 0; row < m_rows; row++)
		{
			for (size_t col = 0; col < m_cols; col++)
			{
				result.m_ppData[row][col] = m_ppData[row][col] * s;
			}
		}
		return result;
	}

	MatrixXd operator*(const MatrixXd &m) const
	{
		// condition check
		assert(m_cols == m.m_rows);

		MatrixXd result(m_rows, m.m_cols);
		for(size_t row = 0; row < m_rows; row++)
		{
			for (size_t col = 0; col < m.m_cols; col++)
			{
				result.m_ppData[row][col] = 0.0;
				for(size_t i = 0; i < m_cols; i++)
				{
					result.m_ppData[row][col] += m_ppData[row][i] * m.m_ppData[i][col];
				}
			}
		}
		return result;
	}

	// print function
	void print() const
	{
		std::cout << "[";
		for (int row = 0; row < m_rows; row++)
		{
			for (int col = 0; col < m_cols; col++)
			{
				std::cout << m_ppData[row][col];
				if (col != (m_cols-1))std::cout << ", ";
			}
			if (row != (m_rows-1))std::cout << std::endl;
		}
		std::cout << "]" << std::endl;
	}

	// zero
	void zero()
	{
		for (int row = 0; row < m_rows; row++)
		{
			for (int col = 0; col < m_cols; col++)
			{
				m_ppData[row][col] = 0.0;
			}
		}
	}

protected:
	void allocateMemory()
	{
		// memory allocation
		m_ppData = new double*[m_rows];
		for (size_t i = 0; i < m_rows; i++)
		{
			m_ppData[i] = new double[m_cols];
		}
	}

	void dellocateMemory()
	{
		// memory dellocation
		for (size_t i = 0; i < m_rows; i++)
		{
			delete []  m_ppData[i];
		}
		delete [] m_ppData;
		m_ppData = NULL;
	}

protected:
	// size
	const size_t m_rows;
	const size_t m_cols;

	// data
	double **m_ppData;
};

class Matrix3d : public MatrixXd
{
public:
	// default constructor
	Matrix3d()
	: MatrixXd(3, 3)
	{
	}

	// constructor
	Matrix3d(const double m00, const double m01, const double m02,
             const double m10, const double m11, const double m12,
             const double m20, const double m21, const double m22)
	: MatrixXd(3, 3)
	{
		m_ppData[0][0] = m00; m_ppData[0][1] = m01; m_ppData[0][2] = m02;
		m_ppData[1][0] = m10; m_ppData[1][1] = m11; m_ppData[1][2] = m12;
		m_ppData[2][0] = m20; m_ppData[2][1] = m21; m_ppData[2][2] = m22;
	}

	// copy constructor
	Matrix3d(const Matrix3d &m)
	: MatrixXd(m)
	{
	}

	// determinant
	double determinant() const
	{
		const double &a11 = m_ppData[0][0];
		const double &a12 = m_ppData[0][1];
		const double &a13 = m_ppData[0][2];

		const double &a21 = m_ppData[1][0];
		const double &a22 = m_ppData[1][1];
		const double &a23 = m_ppData[1][2];

		const double &a31 = m_ppData[2][0];
		const double &a32 = m_ppData[2][1];
		const double &a33 = m_ppData[2][2];

		return a11*(a22*a33 - a23*a32) 
		     + a12*(a23*a31 - a21*a33) 
			 + a13*(a21*a32 - a22*a31);
	}

	Matrix3d inverse() const
	{
		const double &a11 = m_ppData[0][0];
		const double &a12 = m_ppData[0][1];
		const double &a13 = m_ppData[0][2];

		const double &a21 = m_ppData[1][0];
		const double &a22 = m_ppData[1][1];
		const double &a23 = m_ppData[1][2];

		const double &a31 = m_ppData[2][0];
		const double &a32 = m_ppData[2][1];
		const double &a33 = m_ppData[2][2];

		const double inv_det = 1.0/determinant();

		return Matrix3d(inv_det*(a22*a33-a23*a32),
						inv_det*(a13*a32-a12*a33),
						inv_det*(a12*a23-a13*a22),
						inv_det*(a23*a31-a21*a33),
						inv_det*(a11*a33-a13*a31),
						inv_det*(a13*a21-a11*a23),
						inv_det*(a21*a32-a22*a31),
						inv_det*(a12*a31-a11*a32),
						inv_det*(a11*a22-a12*a21));
	}
};

} // namespace lal
#endif // _MATRIX3D_HPP_