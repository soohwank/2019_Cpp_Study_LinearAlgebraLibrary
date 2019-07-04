#ifndef _VECTOR3D_HPP_
#define _VECTOR3D_HPP_

#include <iostream>

namespace lal
{
	class Vector3d
	{
	public:
		// default constructor
		Vector3d()
		{
			// zero initialization
			for (int i = 0; i < 3; i++)
			{
				data[i] = 0.0;
			}
		}

		// constructor
		Vector3d(const double x, const double y, const double z)
		{
			data[0] = x;
			data[1] = y;
			data[2] = z;
		}

		// constructor
		Vector3d(const Vector3d &v)
		{
			for (int i = 0; i < 3; i++)
			{
				data[i] = v.data[i];
			}

		}

		// print function
		void print() const
		{
			std::cout << "[" << data[0] << ", " << data[1] << ", " << data[2] << "]" << std::endl;
		}

		// addition
		Vector3d operator+(const Vector3d &v) const
		{
			Vector3d result;
			for (int i = 0; i < 3; i++)
			{
				result.data[i] = data[i] + v.data[i];
			}
			return result;
		}

		Vector3d operator+(const double s) const
		{
			Vector3d result;
			for (int i = 0; i < 3; i++)
			{
				result.data[i] = data[i] + s;
			}
			return result;
		}

		// subtraction
		Vector3d operator-(const Vector3d &v) const
		{
			Vector3d result;
			for (int i = 0; i < 3; i++)
			{
				result.data[i] = data[i] - v.data[i];
			}
			return result;
		}

		Vector3d operator-(const double s) const
		{
			Vector3d result;
			for (int i = 0; i < 3; i++)
			{
				result.data[i] = data[i] - s;
			}
			return result;
		}

		// multiplication
		Vector3d operator*(const double s) const
		{
			Vector3d result;
			for (int i = 0; i < 3; i++)
			{
				result.data[i] = data[i] * s;
			}
			return result;
		}

		// dot product
		double operator^(const Vector3d &v) const
		{
			double result = 0.0;
			for (int i = 0; i < 3; i++)
			{
				result += data[i] * v.data[i];
			}
			return result;
		}

		// cross product
		Vector3d operator*(const Vector3d &v) const
		{
			Vector3d result;

			result.data[0] = data[1] * v.data[2] - data[2] * v.data[1];
			result.data[1] = data[2] * v.data[0] - data[0] * v.data[2];
			result.data[2] = data[0] * v.data[1] - data[1] * v.data[0];
			return result;
		}

		// getter
		double x() const
		{
			return data[0];
		}

		double y() const
		{
			return data[1];
		}

		double z() const
		{
			return data[2];
		}

		// setter
		double& x()
		{
			return data[0];
		}

		double& y()
		{
			return data[1];
		}

		double& z()
		{
			return data[2];
		}

	protected:
		// member variables
		double data[3];

	public:
		// static
		const static int dim = 3;

		friend std::ostream& operator<<(std::ostream &os, const Vector3d &v);
	};

	std::ostream& operator<<(std::ostream &os, const Vector3d &v)
	{
		os << "[" << v.data[0] << ", " << v.data[1] << ", " << v.data[2] << "]" << std::endl;

		return os;
	}

} // namespace lal
#endif // _VECTOR3D_HPP_