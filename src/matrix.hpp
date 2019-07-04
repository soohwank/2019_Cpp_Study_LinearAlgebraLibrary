#ifndef _MATRIX3D_HPP_
#define _MATRIX3D_HPP_

#include <iostream>
#include <cassert>
#include "vector.hpp"

using namespace std;

namespace lal
{

class MatrixXd
{
private : 
	//default constructor
	MatrixXd()	
	: m_rows(0), m_cols(0)
	{
	}

public:
	// initializer
	MatrixXd(const size_t rows, const size_t cols)
	: m_rows(rows), m_cols (cols)
	{
		// memory allocation
		allocate();

		// initialization
		zero();
	}

	// copy constructor
	MatrixXd(const MatrixXd & m)
	: m_rows(m.m_rows), m_cols(m.m_cols)
	{
		// memory allocation
		allocate();

		// initialization
		for(size_t row = 0; row < m_rows ; row++)
		{
			for(size_t col = 0; col < m_cols ; col++)
			{
				m_ppData[row][col] = m.m_ppData[row][col];
			}
		}
	}

	// destructor
	~MatrixXd()
	{
		dellocate();
	}
	
	double get(const size_t row, const size_t col) const
	{
		// condition check
		//assert(row < m_rows && col < m_cols);

		return m_ppData[row][col];
	}

	void set(const size_t row, const size_t col, const size_t value)
	{
		// condition check
		//assert(row < m_rows && col < m_cols);
		m_ppData[row][col] = value;
	}
	// print function
	void print()
	{
		cout << "[";
		for(size_t row = 0; row < m_rows ; row++)
		{
			for(size_t col = 0; col < m_cols; col++)
			{
				cout << m_ppData[row][col];
				if(col !=(m_cols - 1)) cout << ",";
			}
			if(row !=(m_rows - 1)) cout << endl;
		}
		cout << "]" << endl;
	}



	// add function
	MatrixXd add(const MatrixXd &m) const
	{
		// condition check
		assert(m_rows == m.m_rows && m_cols == m.m_cols);

		MatrixXd result(m_rows, m_cols);
		for(size_t row = 0; row < m_rows; row++)
		{
			for(size_t col = 0; col < m_cols; col++)
			{
				result.m_ppData[row][col] = m_ppData[row][col] + m.m_ppData[row][col];
			}
		}
		return result;
	}

	MatrixXd add(const double m) 
	{
		// condition check
		//assert(m_rows == m.m_rows && m_cols == m.m_cols);

		MatrixXd result(m_rows, m_cols);
		for(size_t row = 0; row < m_rows; row++)
		{
			for(size_t col = 0; col < m_cols; col++)
			{
				result.m_ppData[row][col] = m_ppData[row][col] + m;
			}
		}
		return result;
	}

	// subtract
	MatrixXd subtract(const MatrixXd &m) 
	{
		// condition check
		assert(m_rows == m.m_rows && m_cols == m.m_cols);

		MatrixXd result(m_rows, m_cols);
		for(size_t row = 0; row < m_rows; row++)
		{
			for(size_t col = 0; col < m_cols; col++)
			{
				result.m_ppData[row][col] = m_ppData[row][col] - m.m_ppData[row][col];
			}
		}
		return result;
	}

	MatrixXd subtract(const double m) 
	{
		// condition check
		//assert(m_rows == m.m_rows && m_cols == m.m_cols);

		MatrixXd result(m_rows, m_cols);
		for(size_t row = 0; row < m_rows; row++)
		{
			for(size_t col = 0; col < m_cols; col++)
			{
				result.m_ppData[row][col] = m_ppData[row][col] - m;
			}
		}
		return result;
	}

	//multiply
	MatrixXd multiply(const MatrixXd &m) 
	{
		// condition check
		assert(m_rows == m.m_cols);
		MatrixXd result(m_rows, m.m_cols);
		for(int row = 0; row < m_rows; row++)
		{
            for(int col = 0; col < m.m_cols; col++)
            {
                result.m_ppData[row][col] = 0.0;
                for(int i = 0; i < m_cols; i++)
                {
                    result.m_ppData[row][col] += m_ppData[row][i] * m.m_ppData[i][col];
                }
            }
		}
		return result;
	}

	MatrixXd multiply(const double m) 
	{
		// condition check
		MatrixXd result(m_rows,m_cols);
		for(int row = 0; row < m_rows; row++)
		{
            for(int col = 0; col < m_cols; col++)
            {
                result.m_ppData[row][col] = 0.0;
                for(int i = 0; i < m_cols; i++)
                {
                    result.m_ppData[row][col] += m_ppData[row][i] * m;
                }
            }
		}
		return result;
	}
	
	/*MatrixXd multiply(const Vector3d &v) const
	{
		MatrixXd result(m_rows, m_cols);
		for(int row = 0; row < m_rows; row++)
		{
            for(int col = 0; col < m_cols; col++)
            {
				result.m_ppData[row][col] = 0.0;
				for(size_t i = 0; i < m_cols; i++)
                result.m_ppData[row][col] = m_ppData[row][i] * v.data[i];
            }
		}
		return result;
	}*/

protected:
	// allocation
	void allocate()
	{
		m_ppData = new double *[m_rows];
		for(size_t row = 0; row < m_rows ; row++)
		{
			m_ppData[row] = new double [m_cols];
		}
	}

	// dellocation
	void dellocate()
	{
		for(size_t i = 0; i < m_rows ; i++)
		{
			delete[] m_ppData[i];
		}
		delete[] m_ppData;
		m_ppData = NULL;
	}

	// zero
	void zero()
	{
		for(size_t row = 0; row < m_rows ; row++)
		{
			for(size_t col = 0; col < m_cols ; col++)
			{
				m_ppData[row][col] = 0.0;
			}
		}
	}

protected:
	//size
	const size_t m_rows;
	const size_t m_cols;

	//data
	double **m_ppData;
};



class Matrix3d : public MatrixXd
{
public:
	// default constructor
	Matrix3d()
	: MatrixXd(3,3)
	{	
	}

	// copy constructor
	Matrix3d(const double m00, const double m01, const double m02,
             const double m10, const double m11, const double m12,
             const double m20, const double m21, const double m22)
	: MatrixXd(3,3)
	{
		m_ppData[0][0] = m00; m_ppData[0][1] = m01; m_ppData[0][2] = m02;
		m_ppData[1][0] = m10; m_ppData[1][1] = m11; m_ppData[1][2] = m12;
		m_ppData[2][0] = m20; m_ppData[2][1] = m21; m_ppData[2][2] = m22;
	}
};

} // namespace lal
#endif // _MATRIX3D_HPP_