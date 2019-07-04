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
	v1.print();

	Vector3d v2(-2.0, 1.0, 2.0);
	v2.print();

	// addition
	(v1 + v2).print();
	(v1 + 1.0).print();

	// subtracttion
	(v1 - v2).print();
	(v1 - 1.0).print();

	// multiplication
	(v1 * 2.0).print();

	// dot product
	cout << (v1 ^ v2) << endl;

	// cross product
	(v1 * v2).print();

	//////////////////////////////////////////
	// matrix 3d
	/////////////////////////////////////////

	// matrix
	Matrix3d m1(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
	cout << m1 << endl;

	Matrix3d m2(-1.0, -2.0, -3.0, -4.0, -5.0, -6.0, 7.0, 8.0, 9.0);
	cout << m2 << endl;
	
	// addition
	cout << (m1 + m2) << endl;
	cout << (m1 + 1.0) << endl;

	// subtraction
	cout << (m1 - m2) << endl;
	cout << (m1 - 1.0) << endl;

	// multiplication
	cout << (m1 * m2) << endl;
	cout << (m1 * v1) << endl;
	cout << (m1 * 2.0) << endl;

	// inverse
	//(m1.inverse()).print();

	//////////////////////////////////////////
	// matrix 
	/////////////////////////////////////////

	MatrixXd m3(4, 3);
	for (size_t row = 0; row < 4; row++)
	{
		for (size_t col = 0; col < 3; col++)
		{
			m3.set(row, col,row + col);
		}
	}

	MatrixXd m4(4, 3);
	for (size_t row = 0; row < 4; row++)
	{
		for (size_t col = 0; col < 3; col++)
		{
			m4.set(row, col,row * 2);
		}
	}

	MatrixXd m5(3, 5);
	for (size_t row = 0; row < 3; row++)
	{
		for (size_t col = 0; col < 5; col++)
		{
			m5.set(row, col, 2.0);
		}
	}

	cout << (m3 + 2.0) << endl;
	cout << (m3 + m4) << endl;
	cout << m3 << endl;
	cout << (m3 - m4) << endl;
	cout << (m3 - 3.0) << endl;

	cout << (m3 * m5) << endl;
	cout << (m3 * v1) << endl;
	cout << (m3 * 2.0) << endl;
	
	return 0;
}