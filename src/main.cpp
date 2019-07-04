#include "vector.hpp"
#include "matrix.hpp"
using namespace lal;
using namespace std;

int main()
{
	//////////////////////////////////////////
	// vector
	/////////////////////////////////////////
	Vector3d v1(1.0, 2.0, 3.0);
	cout << "v1 = ";
	v1.print();
	cout << endl;

	Vector3d v2(-2.0, 1.0, 2.0);
	cout << "v2 = ";
	v2.print();
	cout << endl;

	// addition
	cout << "v1 + v2 = ";
	(v1 + v2)print();
	cout << endl;

	cout << "v1 + 1 = ";
	(v1.add(1.0)).print();
	cout << endl;

	// subtracttion
	cout << "v1 - v2 = ";
	(v1.subtract(v2)).print();
	cout << endl;

	cout << "v1 - 1 = ";
	(v1.subtract(1.0)).print();
	cout << endl;

	// multiplication
	cout << "v1 * 2 = ";
	(v1.multiply(2.0)).print();
	cout << endl;

	// dot product
	cout << "v1 . v2 = ";
	cout << v1.dotProduct(v2) << endl;
	cout << endl;

	// cross product
	cout << "v1 x v2 = ";
	(v1.crossProduct(v2)).print();
	cout << endl;

	//////////////////////////////////////////
	// matrix 3d
	/////////////////////////////////////////

	// matrix
	Matrix3d m1(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
	cout << "m1 = ";
	m1.print();
	cout << endl;

	Matrix3d m2(-1.0, -2.0, -3.0, -4.0, -5.0, -6.0, 7.0, 8.0, 9.0);
	cout << "m2 = ";
	m2.print();
	cout << endl;

	// addition
	cout << "m1 + m2 = ";
	(m1.add(m2)).print();
	cout << endl;

	cout << "m1 + 1 = ";
	(m1.add(1.0)).print();
	cout << endl;

	// subtraction
	cout << "m1 - m2 = ";
	(m1.subtract(m2)).print();
	cout << endl;

	cout << "m1 - 1 = ";
	(m1.subtract(1.0)).print();
	cout << endl;

	// multiplication
	cout << "m1 * m2 = ";
	(m1.multiply(m2)).print();
	cout << endl;

	cout << "m1 * v1 = ";
	(m1.multiply(v1)).print();
	cout << endl;

	cout << "m1 * 2 = ";
	(m1.multiply(2.0)).print();
	cout << endl;

	// inverse
	cout << "inv(m1) = ";
	(m1.inverse()).print();
	cout << endl;

	//////////////////////////////////////////
	// matrix 
	/////////////////////////////////////////

	MatrixXd m3(4, 3);
	for(size_t row = 0; row < 4; row++)
	{
		for(size_t col = 0; col < 3; col++)
		{
			m3.set(row, col, row + col);
		}
	}
	cout << "m3 = ";
	m3.print();
	cout << endl;

	MatrixXd m4(4, 3);
	for (size_t row = 0; row < 4; row++)
	{
		for (size_t col = 0; col < 3; col++)
		{
			m4.set(row, col, row * 2);
		}
	}
	cout << "m4 = ";
	m4.print();
	cout << endl;

	// addition
	cout << "m3 + 2 = ";
	(m3.add(2.0)).print();
	cout << endl;

	cout << "m3 + m4 = ";
	(m3.add(m4)).print();
	cout << endl;

	// subtraction
	cout << "m3 - m4 = ";
	(m3.subtract(m4)).print();
	cout << endl;

	cout << "m3 - 3 = ";
	(m3.subtract(3.0)).print();
	cout << endl;

	MatrixXd m5(3, 5);
	for (size_t row = 0; row < 3; row++)
	{
		for (size_t col = 0; col < 5; col++)
		{
			m5.set(row, col, 2.0);
		}
	}
	cout << "m5 = ";
	m5.print();
	cout << endl;

	// multiplication
	cout << "m3 * m5 = ";
	(m3.multiply(m5)).print();
	cout << endl;

	cout << "m3 * v1 = ";
	(m3.multiply(v1)).print();
	cout << endl;

	cout << "m3 * 2 = ";
	(m3.multiply(2.0)).print();
	cout << endl;

	return 0;
}