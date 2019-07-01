#ifndef _MATRIX3D_HPP_
#define _MATRIX3D_HPP_

#include <iostream>
#include <cassert>
#include "vector.hpp"

namespace lal
{

	class MatrixXd
	{
	public:
		// constructor
		MatrixXd(const size_t rows, const size_t cols)
			: m_rows(rows), m_cols(cols)
		{
			m_ppData = new double*[m_rows];
			for (size_t i = 0; i < m_rows; i++)
			{
				m_ppData[i] = new double[m_cols];
				for (size_t j = 0; j < m_cols; j++)
				{
					m_ppData[i][j] = 0.0;
				}
			}
		}
		MatrixXd(const MatrixXd &m)
			:MatrixXd(m.m_rows, m.m_cols)
		{
			for (size_t row = 0; row < m.m_rows; row++)
			{
				for (size_t col = 0; col < m.m_cols; col++)
				{
					m_ppData[row][col] = m.m_ppData[row][col];
				}
			}
		}
		// destructor
		~MatrixXd()
		{
			for (size_t i = 0; i < m_rows; i++)
			{
				delete[]  m_ppData[i];
			}
			delete[] m_ppData;
		}
		void set(size_t row, size_t col, double value)
		{
			m_ppData[row][col] = value;
		}

		// addition
		MatrixXd add(const MatrixXd &m) const
		{
			// speicial case
			assert(m_rows == m.m_rows && m_cols == m.m_cols);

			MatrixXd result(m_rows, m_cols);
			for (size_t row = 0; row < m_rows; row++)
			{
				for (size_t col = 0; col < m_cols; col++)
				{
					result.m_ppData[row][col] = m_ppData[row][col] + m.m_ppData[row][col];
				}
			}
			return result;
		}
		MatrixXd add(const double s) const
		{
			MatrixXd result(m_rows, m_cols);
			for (size_t row = 0; row < m_rows; row++)
			{
				for (size_t col = 0; col < m_cols; col++)
				{
					result.m_ppData[row][col] = m_ppData[row][col] + s;
				}
			}
			return result;
		}
		MatrixXd subtract(const MatrixXd &m) const
		{
			assert(m_rows == m.m_rows && m_cols == m.m_cols);

			MatrixXd result(m_rows, m_cols);
			for (size_t row = 0; row < m_rows; row++)
			{
				for (size_t col = 0; col < m_cols; col++)
				{
					result.m_ppData[row][col] = m_ppData[row][col] - m.m_ppData[row][col];
				}
			}
			return result;
		}
		MatrixXd subtract(const double s) const
		{
			MatrixXd result(m_rows, m_cols);
			for (size_t row = 0; row < m_rows; row++)
			{
				for (size_t col = 0; col < m_cols; col++)
				{
					result.m_ppData[row][col] = m_ppData[row][col] - s;
				}
			}
			return result;
		}
		// multiplication
		MatrixXd multiply(const MatrixXd &m) const
		{
			assert(m_cols == m.m_rows);

			MatrixXd result(m_rows, m_cols);
			for (int row = 0; row < m_rows; row++)
			{
				for (int col = 0; col < m.m_cols; col++)
				{
					result.m_ppData[row][col] = 0.0;
					for (int i = 0; i < m_cols; i++)
					{
						result.m_ppData[row][col] += m_ppData[row][i] * m.m_ppData[i][col];
					}
				}
			}
			return result;
		}
		
		MatrixXd multiply(const double s) const
		{
			MatrixXd result(m_rows, m_cols);
			for (int row = 0; row < m_rows; row++)
			{
				for (int col = 0; col < m_cols; col++)
				{
					result.m_ppData[row][col] = m_ppData[row][col] * s;
				}
			}
			return result;
		}
	/*	MatrixXd multiply(const Vector3d &v) const
		{
			Vector3d result;
			for (int row = 0; row < 3; row++)
			{
				result.m_ppData[row] = 0.0;
				for (int i = 0; i < 3; i++)
				{
					result.m_ppData[row] += m_ppData[row][i] * v.m_ppData[i];
				}
			}
			return result;
		}*/
		// print function
		void print() const
		{
			std::cout << "[";
			for (int row = 0; row < m_rows; row++)
			{
				for (int col = 0; col < m_cols; col++)
				{
					std::cout << m_ppData[row][col];
					if (col != (m_cols - 1))std::cout << ", ";
				}
				if (row != (m_rows - 1))std::cout << std::endl;
			}
			std::cout << "]" << std::endl;
		}
	private:
		MatrixXd()
			: m_rows(0), m_cols(0)
		{
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
			:MatrixXd(3, 3)
		{
		}
		// constructor
		Matrix3d(const double m00, const double m01, const double m02,
			const double m10, const double m11, const double m12,
			const double m20, const double m21, const double m22)
			:MatrixXd(3, 3)
		{
			m_ppData[0][0] = m00; m_ppData[0][1] = m01; m_ppData[0][2] = m02;
			m_ppData[1][0] = m10; m_ppData[1][1] = m11; m_ppData[1][2] = m12;
			m_ppData[2][0] = m20; m_ppData[2][1] = m21; m_ppData[2][2] = m22;
		}
		Matrix3d(const Matrix3d &m)
			:MatrixXd(m)
		{
		}
		// multiplication
		/*
		Vector3d multiply(const Vector3d &v) const
		{
		Vector3d result;
		for(int row = 0; row < 3; row++)
		{
		result.data[row] = 0.0;
		for(int i = 0; i < 3; i++)
		{
		result.data[row] += data[row][i] * v.data[i];
		}
		}
		return result;
		}*/

	private:
		// member variables
		double data[3][3];

	public:
		// static
		const static int dim = 3;
	};

} // namespace lal
#endif // _MATRIX3D_HPP_