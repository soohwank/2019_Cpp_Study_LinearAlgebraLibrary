#include <iostream>

using namespace std;



class Matrix3d

{



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

	Vector3d add_(const double n) const

	{

		Vector3d result;

		for (int i = 0; i < 3; i++)

		{

			result.data[i] = data[i] + n;

		}

		return result;

	}

	Vector3d subtract_(const double n) const

	{

		Vector3d result;

		for (int i = 0; i < 3; i++)

		{

			result.data[i] = data[i] - n;

		}

		return result;

	}

	Vector3d multiply(const double n) const

	{

		Vector3d result;

		for (int i = 0; i < 3; i++)

		{

			result.data[i] = data[i] * n;

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

	static double data[3];

	friend Matrix3d;



public:

	// static

	const static int dim = 3;

};



class Matrix3d

{

public:

	Matrix3d()

	{

		// zero initialization

		for (int i = 0; i < 3; i++)

		{

			for (int j = 0; j < 3; j++)

			{

				data[i][j] = 0.0;

			}

		}

	}

	Matrix3d(const double a1, const double a2, const double a3, const double b1, const double b2, const double b3, const double c1, const double c2, const double c3)

	{

		data[0][0] = a1;

		data[0][1] = a2;

		data[0][2] = a3;

		data[1][0] = b1;

		data[1][1] = b2;

		data[1][2] = b3;

		data[2][0] = c1;

		data[2][1] = c2;

		data[2][2] = c3;

	}

	Matrix3d(const Matrix3d &m)

	{

		for (int i = 0; i < 3; i++)

		{

			for (int j = 0; j < 3; j++)

			{

				data[i][j] = m.data[i][j];

			}

		}

	}

	Matrix3d add(const Matrix3d &m)const

	{

		Matrix3d result;

		for (int i = 0; i < 3; i++)

		{

			for (int j = 0; j < 3; j++)

			{

				result.data[i][j] = data[i][j] + m.data[i][j];

			}

		}

		return result;

	}

	Matrix3d subtract(const Matrix3d &m)const

	{

		Matrix3d result;

		for (int i = 0; i < 3; i++)

		{

			for (int j = 0; j < 3; j++)

			{

				result.data[i][j] = data[i][j] - m.data[i][j];

			}

		}

		return result;

	}

	Matrix3d multiply(const Matrix3d &m)const

	{

		Matrix3d result;



		result.data[0][0] = (data[0][0] * m.data[0][0]) + (data[0][1] * m.data[1][0]) + (data[0][2] * m.data[2][0]);

		result.data[0][1] = (data[0][0] * m.data[0][1]) + (data[0][1] * m.data[1][1]) + (data[0][2] * m.data[2][1]);

		result.data[0][2] = (data[0][0] * m.data[0][2]) + (data[0][1] * m.data[1][2]) + (data[0][2] * m.data[2][2]);

		result.data[1][0] = (data[1][0] * m.data[0][0]) + (data[1][1] * m.data[1][0]) + (data[1][2] * m.data[2][0]);

		result.data[1][1] = (data[1][0] * m.data[0][1]) + (data[1][1] * m.data[1][1]) + (data[1][2] * m.data[2][1]);

		result.data[1][2] = (data[1][0] * m.data[0][2]) + (data[1][1] * m.data[1][2]) + (data[1][2] * m.data[2][2]);

		result.data[2][0] = (data[2][0] * m.data[0][0]) + (data[2][1] * m.data[1][0]) + (data[2][2] * m.data[2][0]);

		result.data[2][1] = (data[2][0] * m.data[0][1]) + (data[2][1] * m.data[1][1]) + (data[2][2] * m.data[2][1]);

		result.data[2][2] = (data[2][0] * m.data[0][2]) + (data[2][1] * m.data[1][2]) + (data[2][2] * m.data[2][2]);



		return result;

	}



	Vector3d multiply_(const Vector3d &m)const

	{

		Vector3d result;

		result.data[0] = data[0][0] * m.data[0] + data[0][1] * m.data[0] + data[0][2] * m.data[0]

			result.data[1] = data[1][0] * m.data[1] + data[1][1] * m.data[1] + data[1][2] * m.data[1]

			result.data[2] = data[2][0] * m.data[2] + data[2][1] * m.data[2] + data[2][2] * m.data[2]



			return result;

	}







private:

	double data[3][3];

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



	// scalar addition

	Vector3d v5 = v1.add_(3.0);



	// scalar subtraction

	Vector3d v5 = v1.subtract_(3.0);



	// scalar multiplication

	Vector3d v6 = v1.multiply(3.0);



	// matrix

	Matrix3d m1(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);

	Matrix3d m2(-1.0, -2.0, -3.0, -4.0, -5.0, -6.0, 7.0, 8.0, 9.0);



	// matrix addition

	Matrix3d m3 = m1.add(m2);



	// matrix subtraction

	Matrix3d m4 = m1.subtract(m2);



	// matrix multiplication

	Matrix3d m5 = m1.multiply(m2);



	// matrix-vector multiplication

	Vector3d v7 = m1.multiply_(v1);



	// matrix inverse

	//Matrix3d m2 = m1.inverse();



	return 0;

}