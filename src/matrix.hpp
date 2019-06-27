#ifndef _MATRIX3D_HPP_
#define _MATRIX3D_HPP_

#include <iostream>
#include "vector.hpp"

namespace lal
{

class Vector3d;

class Matrix3d
{
public:
	// default constructor
	Matrix3d()
	{
		// zero initialization
		for(int row = 0; row < 3; row++)
		{
            for(int col = 0; col < 3; col++)
            {
                data[row][col] = 0.0;
            }
		}
	}

	// constructor
	Matrix3d(const double m00, const double m01, const double m02,
             const double m10, const double m11, const double m12,
             const double m20, const double m21, const double m22)
	{
		data[0][0] = m00; data[0][1] = m01; data[0][2] = m02;
		data[1][0] = m10; data[1][1] = m11; data[1][2] = m12;
		data[2][0] = m20; data[2][1] = m21; data[2][2] = m22;
	}

	// constructor
	Matrix3d(const Matrix3d &m)
	{
		for(int row = 0; row < 3; row++)
		{
            for(int col = 0; col < 3; col++)
            {
                data[row][col] = m.data[row][col];
            }
		}
	}

	// print function
	void print() const
	{
        std::cout << "[";
		for(int row = 0; row < 3; row++)
		{
            for(int col = 0; col < 3; col++)
            {
                std::cout << data[row][col];
                if (col != 2) std::cout << ", ";
            }
            if(row != 2) std::cout << std::endl;
		}
        std::cout << "]" << std::endl;
	}

	// addition
	Matrix3d add(const double s) const
	{
		Matrix3d result;
		for(int row = 0; row < 3; row++)
		{
            for(int col = 0; col < 3; col++)
            {
                result.data[row][col] = data[row][col] + s;
            }
		}
		return result;
	}

	Matrix3d add(const Matrix3d &m) const
	{
		Matrix3d result;
		for(int row = 0; row < 3; row++)
		{
            for(int col = 0; col < 3; col++)
            {
                result.data[row][col] = data[row][col] + m.data[row][col];
            }
		}
		return result;
	}

    // subtraction
	Matrix3d subtract(const Matrix3d &m) const
	{
		Matrix3d result;
		for(int row = 0; row < 3; row++)
		{
            for(int col = 0; col < 3; col++)
            {
                result.data[row][col] = data[row][col] - m.data[row][col];
            }
		}
		return result;
	}

	Matrix3d subtract(const double s) const
	{
		Matrix3d result;
		for(int row = 0; row < 3; row++)
		{
            for(int col = 0; col < 3; col++)
            {
                result.data[row][col] = data[row][col] - s;
            }
		}
		return result;
	}

    // multiplication
	Matrix3d multiply(const Matrix3d &m) const
	{
		Matrix3d result;
		for(int row = 0; row < 3; row++)
		{
            for(int col = 0; col < 3; col++)
            {
                result.data[row][col] = 0.0;
                for(int i = 0; i < 3; i++)
                {
                    result.data[row][col] += data[row][i] * m.data[i][col];
                }
            }
		}
		return result;
	}

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
	}

	Matrix3d multiply(const double s) const
	{
		Matrix3d result;
		for(int row = 0; row < 3; row++)
		{
            for(int col = 0; col < 3; col++)
            {
                result.data[row][col] = data[row][col] * s;
            }
		}
		return result;
	}

private:
	// member variables
	double data[3][3];

public:
	// static
	const static int dim = 3;
};

} // namespace lal
#endif // _MATRIX3D_HPP_