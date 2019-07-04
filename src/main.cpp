#include "vector.hpp"
#include "matrix.hpp"
#include <cassert>
using namespace lal;
using namespace std;

int main()
{
	//////////////////////////////////////////
	// vector
	/////////////////////////////////////////
	Vector3d v1(1.0, 2.0, 3.0);
	/*/v1.print();

	Vector3d v2(-2.0, 1.0, 2.0);
	v2.print();

	// addition
	(v1.add(v2)).print();
	(v1.add(1.0)).print();

	// subtracttion
	(v1.subtract(v2)).print();
	(v1.subtract(1.0)).print();

	// multiplication
	(v1.multiply(2.0)).print();

	// dot product
	cout << v1.dotProduct(v2) << endl;

	// cross product
	(v1.crossProduct(v2)).print();*/

	//////////////////////////////////////////
	// matrix 3d
	/////////////////////////////////////////

	// matrix
	Matrix3d m1(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
	m1.print();

	Matrix3d m2(-1.0, -2.0, -3.0, -4.0, -5.0, -6.0, -7.0, -8.0, -9.0);
	m2.print();

	// addition
	cout << "m1 + m2" << endl;
	(m1.add(m2)).print();
	cout << "m1 + 1" << endl ;
	(m1.add(1.0)).print();

	// subtraction
	cout << "m1 - m2" << endl ;
	(m1.subtract(m2)).print();
	cout << "m1 - 1" << endl ;
	(m1.subtract(1.0)).print();
	
	// multiplication
	cout << "m1 x m2" << endl;
	(m1.multiply(m2)).print();
	cout << "m1 x 2" << endl;
	(m1.multiply(2.0)).print();
	//(m1.multiply(v1)).print();


	// inverse
	//(m1.inverse()).print();

	//////////////////////////////////////////
	// matrix 
	/////////////////////////////////////////

	MatrixXd m3(4, 3);
	MatrixXd m4(4, 3);
	
	for(size_t row = 0; row < 4; row++)
	{
		for(size_t col = 0; col < 3; col++)
		{
			m3.set(row, col, row + col);
		}
	}

	for (size_t row = 0; row < 4; row++)
	{
		for (size_t col = 0; col < 3; col++)
		{
			m3.set(row, col, row * 2);
		}
	}

	MatrixXd m5(3, 5);
	for (size_t row = 0; row < 3; row++)
	{
		for (size_t col = 0; col < 5; col++)
		{
			m3.set(row, col,2.0);
		}
	}

	cout << "m3 + 2";
	m3.add(2.0).print();
	cout << endl << "m3 + m4";
	(m3.add(m4)).print();
	cout << endl << "m3 - m4";

//	(m3.subtract(m4)).print();
	//m3.subtract(3.0).print();

//	(m3.multiply(m5)).print();
//	(m3.multiply(v1)).print();
//	(m3.multiply(2.0)).print();

	return 0;
}