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
	Vector3d (const double x, const double y, const double z)
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

	//addition
	Vector3d add(const Vector3d &v)const
	{
		Vector3d result;

		for(int i = 0; i < 3 ; i++)
		{
			result.data[i] = data[i] + v.data[i];
		}

		cout << "Vector addition : ";
		return result;
	}

	Vector3d scalar_add(const double v)const
	{
		Vector3d result;

		for(int i = 0; i < 3 ; i++)
		{
			result.data[i] = data[i] + v;
		}

		cout << "scalar addition : ";
		return result;
	}

	Vector3d subtract(const Vector3d &vs) const
	{
		Vector3d vecsub;

		for(int i  = 0 ; i < 3 ; i++)
		{
			vecsub.data[i] = data[i]- vs.data[i];
		}

		cout << "Vector subtraction : ";
		return vecsub;
	}

	Vector3d scalar_subtract(const double v) const
	{
		Vector3d result;

		for(int i = 0; i < 3 ; i++)
		{
			result.data[i] = data[i] - v;
		}
		
		cout << "scalar subtraction : ";
		return result;
	}

	Vector3d scalar_multiply(const double v) const
	{
		Vector3d result;
		
		for(int i  = 0 ; i < 3 ; i++)
		{
			result.data[i] = data[i] * v;
		}

		cout << "scalar multiplication : ";
		return result;
	}

	double dotProduct(Vector3d &vd) const
	{
		double vecdot = 0;

		for(int i = 0; i < 3 ; i++)
		{
			vecdot += data[i] * vd.data[i]; 
		}
		
		cout << "Vector dotproduct : ";
		return vecdot;
	}

	Vector3d crossProduct(Vector3d &vc)
	{
		Vector3d veccross;

		veccross.data[0] = data[1]*vc.data[2] - data[2]*vc.data[1];
		veccross.data[1] = data[0]*vc.data[2] - data[2]*vc.data[0];
		veccross.data[2] = data[0]*vc.data[1] - data[1]*vc.data[0];

		cout << "Vector crossproduct : ";
		return veccross; 	
	}

private:
	//member variables
	double data[3];
};

//Matrix 
class Matrix3d
{
public:
	//default constructor
	Matrix3d()
	{
		for(int i = 0 ; i < 9 ; i++)
		{
			component[i] = 0;
		}
	}

	//constructor
	Matrix3d(const double a, const double b, const double c,
			 const double d, const double e, const double f,
			 const double g, const double h, const double k)
		{	 
			for(int i = 0 ; i < 9 ; i++)
			{
				component[0] = a; component[1] = b; component[2] = c;
				component[3] = d; component[4] = e; component[5] = f;
				component[6] = g; component[7] = h; component[8] = k;	
			}
		}

	//print Matrix
	void print() const
	{
		cout << "|";
		for(int i = 0 ; i<9 ; i++)
		{
			cout <<  component[i] ; 
			
			if(i == 2 | i == 5)
			{	
				cout << "|" << endl << "|";
			}
		}

		cout << "|";
		cout << endl;
	}

	Matrix3d add(const Matrix3d & ma) const
	{
		Matrix3d result;
		for(int i = 0 ; i < 9 ; i++)
		{
			result.component[i] = component[i] + ma.component[i];
		}
		
		return result;
	}

	Matrix3d subtract(const Matrix3d & ms) const
	{
		Matrix3d result;
		for(int i = 0 ; i < 9 ; i++)
		{
			result.component[i] = component[i] - ms.component[i];
		}
		
		return result;
	}

	Matrix3d multiply(const Matrix3d & ms) const
	{
		Matrix3d result;
		int j = 0;
		int cnt = 0;

		for(int k = 0 ; k < 9 ; k++)
		{	
			for(int l = 0 ; l < 3 ; l++)
			{	
				for(int i = 0 ; i < 3 ; i++)
				{
					 l = cnt+1;
						result.component[k] += component[i] * ms.component[j];	
						
						j++;
						j = i+3;
				}
				cnt++;
			}
		}

		return result;
	}

	/* double vector_matrix_multiply(const Vector3d & vm) const
	{
		double result;
		for(int i = 0 ; i < 9 ; i++)
		{
			result = component[i] * vm[i];
		}
		
		return result;
	}*/

private:
	double component[9];
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


	// scalar addition
	Vector3d v6 = v1.scalar_add(3.0);
	v6.print();
	
	// scalar subtraction
	Vector3d v7 = v1.scalar_subtract(3.0);
	v7.print();

	// scalar multiplication
	Vector3d v8 = v1.scalar_multiply(3.0);
	v8.print();

	// matrix
	Matrix3d m1(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
	m1.print();

	Matrix3d m2(-1.0, -2.0, -3.0, -4.0, -5.0, -6.0, -7.0, -8.0, -9.0);
	m2.print();

	// matrix addition
	Matrix3d m3 = m1.add(m2);
	m3.print();

	// matrix subtraction
	Matrix3d m4 = m1.subtract(m2);
	m4.print();

	// matrix multiplication
	Matrix3d m5 = m1.multiply(m2);
	m5.print();

	//cout << v1.x() << endl;
	// matrix-vector multiplication
//	double vector_matrix_mutiply = m1.vector_matrix_multiply(v1);
//	cout << vector_matrix_mutiply << endl;

/* 
	v1.x() = 5.0;
	// matrix inverse
	//Matrix3d m2 = m1.inverse();
*/
	return 0;
}