#include <iostream>
using namespace std;

class Vector3d
{
public:
	//default constructor
	Vector3d()
	{
		for(int i = 0; i<3 ;i++)
		{
			data[i] = 0;
		}
	}

	//constructor
	Vector3d(const double x, const double y, const double z)
	{
		data[0] = x;
		data[1] = y;
		data[2] = z;
	}

	//print function 
	void print() const // don't change member variables you have to use 'const' keyword -> end of functions.
	{
		cout << "[" << data[0] << "," 
			 		<< data[1] << "," 
					<< data[2] << "]" << endl;
	}

	//add
	Vector3d add(const Vector3d &v)const
	{
		Vector3d result;

		for(int i = 0; i < 3 ; i++)
		{
			result.data[i] = data[i] + v.data[i];
		}
		
		return result;
	}

	Vector3d subtract(const Vector3d &vsub)const
	{
		Vector3d sub;

		for(int i  = 0 ; i < 3 ; i++)
		{
			sub.data[i] = data[i]- vsub.data[i];
		}

		return sub;
	}

	double dotProduct(Vector3d &vdot)const
	{
		return (data[0]*vdot.data[0]) + (data[1]*vdot.data[1]) + (data[2]*vdot.data[2]);
	}

	Vector3d crossProduct(Vector3d &vcross)
	{
		Vector3d cp;

		cp.data[0] = data[1]*vcross.data[2] - data[2]*vcross.data[1];
		cp.data[1] = data[0]*vcross.data[2] - data[2]*vcross.data[0];
		cp.data[2] = data[0]*vcross.data[1] - data[1]*vcross.data[0];
		

		return cp; 	
	}

private:
	//member variables
	double data[3];
};


int main()
{
	//cout << "hello world" << endl;
	Vector3d v1(1.0, 2.0, 3.0);
	v1.print();

	Vector3d v2(-2.0, 1.0 , 2.0);

	//add
	Vector3d v3 = v1.add(v2);
	v3.print();

	//subtract
	Vector3d v4 = v1.subtract(v2);
	v4.print();

	//dot product
	double dotProduct = v1.dotProduct(v2);
	cout << dotProduct << endl;

	//cross product
	Vector3d v5 = v1.crossProduct(v2);
	v5.print();

	return 0;
}