#include <iostream>
using namespace std;

class Matrix3d
{
public:
	// default constructor
	Matrix3d()
	{
		// zero initialization
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				num[i][j] = 0.0;
			}
		}
	}

	// constructor
	Matrix3d(const double num1, const double num2, const double num3,
		const double num4, const double num5, const double num6,
		const double num7, const double num8, const double num9)
	{
		num[0][0] = num1;
		num[0][1] = num2;
		num[0][2] = num3;

		num[1][0] = num4;
		num[1][1] = num5;
		num[1][2] = num6;

		num[2][0] = num7;
		num[2][1] = num8;
		num[2][2] = num9;
	}

	// constructor
	Matrix3d(const Matrix3d &m)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				num[i][j] = m.num[i][j];
			}
		}
	}

	// print function
	void print() const
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << num[i][j] << ' ';
			}
			cout << endl;
		}
	}

	// matrix addition
	Matrix3d add(const Matrix3d &m) const
	{
		Matrix3d result;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				result.num[i][j] = num[i][j] + m.num[i][j];
			}
		}
		return result;
	}

	// matrix subtraction
	Matrix3d subtract(const Matrix3d &m) const
	{
		Matrix3d result;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				result.num[i][j] = num[i][j] - m.num[i][j];
			}
		}
		return result;
	}

	// matrix multiplication
	Matrix3d multiply(const Matrix3d &m) const
	{
		Matrix3d result;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				result.num[i][j] = num[i][j] * m.num[i][j];
			}
		}
		return result;
	}

private:
	double num[3][3];
	friend class Vector3d;
};

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

	double dotProduct(const Vector3d &v) const
	{
		double result = 0.0;
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

	// scalar addition
	Vector3d add(const double v) const
	{
		Vector3d result;
		for (int i = 0; i < 3; i++)
		{
			result.data[i] = data[i] + v;
			cout << result.data[i] << ' ';
		}
		cout << endl;
		return result;
	}

	// scalar subtract
	Vector3d subtract(const double v) const
	{
		Vector3d result;
		for (int i = 0; i < 3; i++)
		{
			result.data[i] = data[i] - v;
			cout << result.data[i] << ' ';
		}
		cout << endl;
		return result;
	}

	// scalar multiply
	Vector3d multiply(const double v) const
	{
		Vector3d result;
		for (int i = 0; i < 3; i++)
		{
			result.data[i] = data[i] * v;
			cout << result.data[i] << ' ';
		}
		cout << endl;
		return result;
	}

	// matrix-vector multiplication
	Vector3d multiply(const Vector3d &v) const
	{
		Matrix3d result;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				result.num[i][j] = num[i][j] * v.data[i];
			}
		}
		return result;
	}

	// getter
	double x() const
	{
		return data[0];
	}

	// setter
	double& x()
	{
		return data[0];
	}

private:
	// member variables
	double data[3];

public:
	// static
	const static int dim = 3;
};


int main()
{
	Vector3d v1(1.0, 2.0, 3.0);
	//v1.print();

	Vector3d v2(-2.0, 1.0, 2.0);

	/*
	// add
	Vector3d v3 = v1.add(v2);

	// subtract
	Vector3d v4 = v1.subtract(v2);

	// dot product
	double dotProduct = v1.dotProduct(v2);

	// cross product
	Vector3d v4 = v1.crossProduct(v2);
	*/

	// scalar addition
	Vector3d v5 = v1.add(3.0);

	// scalar subtraction
	Vector3d v6 = v1.subtract(3.0);

	// scalar multiplication
	Vector3d v7 = v1.multiply(3.0);

	// matrix
	Matrix3d m1(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
	m1.print();
	Matrix3d m2(-1.0, -2.0, -3.0, -4.0, -5.0, -6.0, 7.0, 8.0, 9.0);
	m2.print();

	// matrix addition
	Matrix3d m3 = m1.add(m2);

	// matrix subtraction
	Matrix3d m4 = m1.subtract(m2);

	// matrix multiplication
	Matrix3d m5 = m1.multiply(m2);

	// matrix-vector multiplication
	Vector3d v8 = m1.multiply(v1);

	// matrix inverse
	//Matrix3d m2 = m1.inverse();

	return 0;
}#include <iostream>
using namespace std;

class Matrix3d
{
public:
	// default constructor
	Matrix3d()
	{
		// zero initialization
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				num[i][j] = 0.0;
			}
		}
	}

	// constructor
	Matrix3d(const double num1, const double num2, const double num3,
		const double num4, const double num5, const double num6,
		const double num7, const double num8, const double num9)
	{
		num[0][0] = num1;
		num[0][1] = num2;
		num[0][2] = num3;

		num[1][0] = num4;
		num[1][1] = num5;
		num[1][2] = num6;

		num[2][0] = num7;
		num[2][1] = num8;
		num[2][2] = num9;
	}

	// constructor
	Matrix3d(const Matrix3d &m)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				num[i][j] = m.num[i][j];
			}
		}
	}

	// print function
	void print() const
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << num[i][j] << ' ';
			}
			cout << endl;
		}
	}

	// matrix addition
	Matrix3d add(const Matrix3d &m) const
	{
		Matrix3d result;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				result.num[i][j] = num[i][j] + m.num[i][j];
			}
		}
		return result;
	}

	// matrix subtraction
	Matrix3d subtract(const Matrix3d &m) const
	{
		Matrix3d result;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				result.num[i][j] = num[i][j] - m.num[i][j];
			}
		}
		return result;
	}

	// matrix multiplication
	Matrix3d multiply(const Matrix3d &m) const
	{
		Matrix3d result;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				result.num[i][j] = num[i][j] * m.num[i][j];
			}
		}
		return result;
	}

private:
	double num[3][3];
	friend class Vector3d;
};

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

	double dotProduct(const Vector3d &v) const
	{
		double result = 0.0;
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

	// scalar addition
	Vector3d add(const double v) const
	{
		Vector3d result;
		for (int i = 0; i < 3; i++)
		{
			result.data[i] = data[i] + v;
			cout << result.data[i] << ' ';
		}
		cout << endl;
		return result;
	}

	// scalar subtract
	Vector3d subtract(const double v) const
	{
		Vector3d result;
		for (int i = 0; i < 3; i++)
		{
			result.data[i] = data[i] - v;
			cout << result.data[i] << ' ';
		}
		cout << endl;
		return result;
	}

	// scalar multiply
	Vector3d multiply(const double v) const
	{
		Vector3d result;
		for (int i = 0; i < 3; i++)
		{
			result.data[i] = data[i] * v;
			cout << result.data[i] << ' ';
		}
		cout << endl;
		return result;
	}

	// matrix-vector multiplication
	Vector3d multiply(const Vector3d &v) const
	{
		Matrix3d result;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				result.num[i][j] = num[i][j] * v.data[i];
			}
		}
		return result;
	}

	// getter
	double x() const
	{
		return data[0];
	}

	// setter
	double& x()
	{
		return data[0];
	}

private:
	// member variables
	double data[3];

public:
	// static
	const static int dim = 3;
};


int main()
{
	Vector3d v1(1.0, 2.0, 3.0);
	//v1.print();

	Vector3d v2(-2.0, 1.0, 2.0);

	/*
	// add
	Vector3d v3 = v1.add(v2);

	// subtract
	Vector3d v4 = v1.subtract(v2);

	// dot product
	double dotProduct = v1.dotProduct(v2);

	// cross product
	Vector3d v4 = v1.crossProduct(v2);
	*/

	// scalar addition
	Vector3d v5 = v1.add(3.0);

	// scalar subtraction
	Vector3d v6 = v1.subtract(3.0);

	// scalar multiplication
	Vector3d v7 = v1.multiply(3.0);

	// matrix
	Matrix3d m1(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
	m1.print();
	Matrix3d m2(-1.0, -2.0, -3.0, -4.0, -5.0, -6.0, 7.0, 8.0, 9.0);
	m2.print();

	// matrix addition
	Matrix3d m3 = m1.add(m2);

	// matrix subtraction
	Matrix3d m4 = m1.subtract(m2);

	// matrix multiplication
	Matrix3d m5 = m1.multiply(m2);

	// matrix-vector multiplication
	Vector3d v8 = m1.multiply(v1);

	// matrix inverse
	//Matrix3d m2 = m1.inverse();

	return 0;
}