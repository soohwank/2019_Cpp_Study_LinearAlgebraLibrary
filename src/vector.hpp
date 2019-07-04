#ifndef _VECTOR3D_HPP_
#define _VECTOR3D_HPP_

#include <iostream>
#include "matrix.hpp"

namespace lal
{

class Vector3d : public MatrixXd
{
public:
	// default constructor
	Vector3d()
	: MatrixXd(3, 1)
	{
	}

	// constructor
	Vector3d(const double x, const double y, const double z)
	: MatrixXd(3, 1)
	{
		m_ppData[0][0] = x;
		m_ppData[1][0] = y;
		m_ppData[2][0] = z;
	}

	// constructor
	Vector3d(const MatrixXd &m)
	: MatrixXd(m)
	{
	}

    // dot product //
	double dotProduct(const Vector3d &v) const
	{
		double result =0.0;
		for (int i = 0; i < 3; i++)
		{
			result += m_ppData[i][0] * v.m_ppData[i][0];
		}
		return result;
	}

    // cross product
	Vector3d crossProduct(const Vector3d &v) const
	{
		Vector3d result;

		result.m_ppData[0][0] = m_ppData[1][0] * v.m_ppData[2][0] - m_ppData[2][0] * v.m_ppData[1][0];
		result.m_ppData[1][0] = m_ppData[2][0] * v.m_ppData[0][0] - m_ppData[0][0] * v.m_ppData[2][0];
		result.m_ppData[2][0] = m_ppData[0][0] * v.m_ppData[1][0] - m_ppData[1][0] * v.m_ppData[0][0];
		return result;
	}

	// getter
	double x() const
	{
		return m_ppData[0][0];
	}

    double y() const
    {
        return m_ppData[1][0];
    }

    double z() const
    {
        return m_ppData[2][0];
    }

	// setter
	double& x()
	{
		return m_ppData[0][0];
	}

    double& y()
    {
        return m_ppData[1][0];
    }

    double& z()
    {
        return m_ppData[2][0];
    }
};

} // namespace lal
#endif // _VECTOR3D_HPP_