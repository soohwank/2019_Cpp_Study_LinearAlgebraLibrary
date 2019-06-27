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

	// subtract
	Vector3d subtract(const Vector3d &v) const
	{
		Vector3d result;
		for (int i = 0; i < 3; i++)
		{
			result.data[i] = data[i] - v.data[i];
		}
		return result;
	}

	//dot product
	double dotProduct(const Vector3d &v) const
	{
		Vector3d temp;
		double result = 0;
		for (int i = 0; i < 3; i++)
		{
			temp.data[i] = data[i] * v.data[i];
		}
		for (int i = 0; i < 3; i++)
		{
			result += temp.data[i];
		}
		return result;
	}
	Vector3d crossProduct(const Vector3d &v) const
	{
		Vector3d result;
		result.data[0] = data[1] * v.data[2] - data[2] * v.data[1];
		result.data[1] = data[2] * v.data[0] - data[0] * v.data[2];
		result.data[2] = data[0] * v.data[1] - data[1] * v.data[0];
		return result;
	}
private:
	// member variables
	double data[3];
};


class Matrix3d
{
public:
	Matrix3d()
	{
		const int col = 3;
		const int row = 3;
		// zero initialization
		for (int i = 0; i < col; i++)
		{
			for (int j = 0; j < row; j++)
			{
				data[i][j] = 0.0;
				cout << " " << endl;
			}
			cout << "\n" << endl;
		}
	}

	Matrix3d(const double a, const double b, const double c, const double d,
		const double e, const double f, const double g, const double h,
		const double i)
	{

		data[0][0] = a;
		data[0][1] = b;
		data[0][2] = c;
		data[1][0] = d;
		data[1][1] = e;
		data[1][2] = f;
		data[2][0] = g;
		data[2][1] = h;
		data[2][2] = i;
	}
	Matrix3d(Matrix3d &a)
	{
		const int col = 3;
		const int row = 3;
		// zero initialization
		for (int i = 0; i < col; i++)
		{
			for (int j = 0; j < row; j++)
			{
				data[i][j] = a.data[i][j];
				cout << " " << endl;
			}
			cout << "\n" << endl;
		}
	}
	void print()
	{
		cout << data[0][0] << " " << data[0][1] << " " << data[0][2] << "\n"
			 << data[1][0] << " " << data[1][1] << " " << data[1][2] << "\n"
		     << data[2][0] << " " << data[2][1] << " " << data[2][2] << "\n" << endl;
	}
	//add function
	Matrix3d add(const Matrix3d &v) const
	{
		Matrix3d result;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				result.data[i][j] = data[i][j] + v.data[i][j];
			}
		}
		return result;
	}
	//subtract
	Matrix3d sub(const Matrix3d &v) const
	{
		Matrix3d result;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				result.data[i][j] = data[i][j] - v.data[i][j];
			}
		}
		return result;
	}
	Matrix3d multiply(const Matrix3d &v) const
	{
		Matrix3d result;

		return result;
	}
private:
	// member variables
	double data[3][3];
};



int main()
{
	Vector3d v1(1.0, 2.0, 3.0);
	v1.print();

	Vector3d v2(-2.0, 1.0, 2.0);
	v2.print();

	// add
	Vector3d v3 = v1.add(v2);
	v3.print();
	// subtract
	Vector3d v4 = v1.subtract(v2);
	v4.print();
	// dot product
	double dotProduct = v1.dotProduct(v2);
	cout << "inner product " << dotProduct << endl;
	// cross product
	Vector3d v6 = v1.crossProduct(v2);
	v6.print();

	Matrix3d m1(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);

	Matrix3d m2(-1.0, -2.0, -3.0, -4.0, -5.0, -6.0, 7.0, 8.0, 9.0);
	//add
	Matrix3d m3 = m1.add(m2);
	//subtract
	Matrix3d m4 = m1.sub(m2);
	// matrix multiplication
	Matrix3d m5 = m1.multiply(m2);
	m1.print();
	m2.print();
	m3.print();

	system("pause");
	return 0;
}