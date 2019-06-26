#include <iostream>
using namespace std;

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
		cout << "[" << data[0] << ", "
			<< data[1] << ", "
			<< data[2] << "]" << endl;
	}

	// add
	Vector3d add(const Vector3d &v) const
	{
		Vector3d result;
		for (int i = 0; i < 3; i++)
		{
			result.data[i] = data[i] + v.data[i];
		}
		return result;
	}

	Vector3d subtract(const Vector3d &v) const
	{
		Vector3d result;
		for (int i = 0; i < 3; i++)
		{
			result.data[i] = data[i] - v.data[i];
		}
		return result;
	}

	double dotProduct(const Vector3d &v)const
	{
		double result;
		for (int i = 0; i < 3; i++)
		{
			result += data[i] * v.data[i];
		}
		return result;
	}
	Vector3d crossProduct(const Vector3d &v) const
	{
		Vector3d result;

		result.data[0] = data[1] * v.data[2] - data[2] * v.data[1];
		result.data[1] = data[0] * v.data[2] - data[2] * v.data[0];
		result.data[2] = data[0] * v.data[1] - data[1] * v.data[0];
		return result;
	}


private:
	// member variables
	double data[3];
};

int main()
{
	Vector3d v1(1.0, 2.0, 3.0);
	v1.print();

	Vector3d v2(-2.0, 1.0, 2.0);


	// add
	Vector3d v3 = v1.add(v2);

	// subtract
	Vector3d v4 = v1.subtract(v2);

	// dot product
	double dotProduct = v1.dotProduct(v2);

	// cross product
	Vector3d v4 = v1.crossProduct(v2);

	return 0;
}