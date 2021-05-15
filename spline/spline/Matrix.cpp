#include "Matrix.h"


Matrix::Matrix(int n, int m, double** A)
{
	this->n = n;
	this->m = m;
	M = new double* [n];
	for (int i = 0; i < n; i++)
	{
		M[i] = new double[m];
		for (int j = 0; j < m; j++)
		{
			M[i][j] = A[i][j];
		}
	}
}
Matrix::Matrix(int n, double** A) :Matrix(n, n, A) {};
Matrix::Matrix(int n,int m) 
{
	this->n = n;
	this->m = m;
	M = new double*[n];
	for (int i = 0; i < n; i++)
	{
		M[i] = new double[m];
		for (int j = 0; j < m; j++)
		{
			if (i == j)
			{
				M[i][j] = 1;
			}
		}
	}
}
Matrix::Matrix(int n) :Matrix(n, n) {};

Matrix::Matrix(int n, int m,double x)
{
	this->n = n;
	this->m = m;
	M = new double* [n];
	for (int i = 0; i < n; i++)
	{
		M[i] = new double[m];
		for (int j = 0; j < m; j++)
		{
			
				M[i][j] = x;
			
		}
	}
}


Matrix::Matrix(int n, int m, int x)
{
	this->n = n;
	this->m = m;
	M = new double* [n];
	for (int i = 0; i < n; i++)
	{
		M[i] = new double[m];
		for (int j = 0; j < m; j++)
		{

			M[i][j] = x;

		}
	}
}

Matrix::Matrix(Matrix& A) 
{	
	this->n = A.n;
	this->m = A.m;


	M = new double* [n];
	for (int i = 0; i < n; i++)
	{
		M[i] = new double[m];
		for (int j = 0; j < m; j++)
		{
			this->M[i][j] = A.M[i][j];
		}
	}

}
Matrix::Matrix()
{
	this->n = 1;
	this->m = 1;
	M = new double* [1];
	M[0] = new double[1];
	M[0][0] = 0;
}

void Matrix::set(int n, int m, double x) 
{
	this->M[n][m] = x;
};
double Matrix::get(int n, int m) 
{
	return M[n][m];
}


Matrix Matrix::cut(const int& I,const int& J)
{
	int n = this->n-1;
	int m = this->m-1;
	Matrix A(n, m);
	int k = 0;
	for (int i = 0; i < n; i++)
	{

		if (k== I)
		{
			k++;
		}
		int l = 0;
			for (int j = 0; j < m; j++)
			{
				if (l==J)
				{
					l++;
				}
					A.M[i][j] = M[k][l];
					l++;
			}
			k++;
	}
	return A;
}
double Matrix::det() 
{
	if (n == m)
	{
		if (n == 1)
		{
			return M[0][0];
		}
		else if (n == 2)
		{
			return M[0][0] * M[1][1] - M[0][1] * M[1][0];
		}
		else if (n == 3)
		{
			return	M[0][0] * M[1][1] * M[2][2] +
					M[0][1] * M[1][2] * M[2][0] +
					M[1][0] * M[0][2] * M[2][1] -
					M[2][0] * M[1][1] * M[0][2] -
					M[2][1] * M[1][2] * M[0][0] -
					M[0][1] * M[1][0] * M[2][2];
		}
		else
		{
			double l = 0;
			int i = 0;
			for (int j = 0; j < n; j++)
			{
				int znak;
				if ((i + j) % 2 == 0)
					znak = 1;
				else
					znak = -1;
				l += znak * M[i][j] * cut(i, j).det();
			}
			return l;
		}
	}
	else
		return	2.e-308;
}
Matrix Matrix::T()
{
	Matrix A(this->m, this->n);
	for (int i = 0; i < this->n; i++)
	{
		for (int j = 0;j < this->m; j++)
		{
			A.M[j][i] = M[i][j];
		}
	}
	return A;
}

double Matrix::minor(const int& I, const int& J) 
{
	return cut(I, J).det();
}
double Matrix::algEdit(const int& I, const int& J)
{
	int znak;
	if ((I + J) % 2 == 0)
		znak = 1;
	else
		znak = -1;
	return znak*cut(I, J).det();
}

Matrix Matrix::rev()
{
	if (n == m) {
		if (det() != 0)
		{
			Matrix A(this->n);

			for (int i = 0; i < this->n; i++)
			{
				for (int j = 0; j<this->m; j++)
				{
					A.M[i][j] = algEdit(j, i);
				}
			}
			A = A / det();
			return A ;
		}
		else
		{

			Matrix V(1, 1, 2.e-308);
			return V;
		}
	}
	else
	{
		Matrix V(1, 1, 2.e-308);
		return V;
	}
}


Matrix Matrix::operator+(const Matrix& A)
{
	if (this->n == A.n && this->m == A.m)
	{
		Matrix M(this->n,this-> m);
		for (int i = 0; i < this->n; i++)
		{
			for (int j = 0; j < this->m; j++)
			{
				M.M[i][j] = this->M[i][j] + A.M[i][j];
			}
		}
		return M;
	}
	else
	{
		Matrix V(1, 1, 2.e-308);
		return V;
	}
}
Matrix Matrix::operator-(const Matrix& A) 
{
	if (this->n == A.n && this->m == A.m)
	{
		Matrix M(n, m);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				M.M[i][j] = this->M[i][j] - A.M[i][j];
			}
		}
		return M;
	}
	else
	{
		Matrix V(1, 1, 2.e-308);
		return V;
	}
}

Matrix Matrix::operator*( Matrix& A)
{
	if (m == A.n)
	{
		Matrix C(n, A.m,0);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < A.m; j++)
			{
				for (int t = 0; t < m; t++)
				{
					C.M[i][j] += M[i][t] * A.M[t][j];
				}
			}
		}
		return C;
	}
	else
	{
		Matrix Error(1, 1, 2.e-308);
		return Error;
	}
}




Matrix Matrix::operator*(const double& a)
{
	Matrix A(this->n, this->m);
	for (int i = 0; i < this->n; i++)
	{
		for (int j = 0; j < this->m; j++)
		{
			A.M[i][j] =M[i][j]* a;
		}
	}
	return A;
}
Matrix Matrix::operator/(const double& a)
{ 
	Matrix A(this->n, this->m);
	for (int i = 0; i < this->n; i++)
	{
		for (int j = 0; j < this->m; j++)
		{
			A.M[i][j] = M[i][j] / a;
		}
	}
	return A;
}

Matrix Matrix::operator=(const Matrix& A) 
{
	if (M != nullptr) {
		for (int i = 0; i < n; ++i)
			delete[] M[i];
		delete[] M;
	}

	this->n = A.n;
	this->m = A.m;



	M = new double* [n];
	for (int i = 0; i < n; i++)
	{
		M[i] = new double[m];
		for (int j = 0; j < m; j++)
		{
			M[i][j] = A.M[i][j];
		}
	}
	return *this;
}

Matrix Pow( Matrix& A, int pow)
{
	if (A.n == A.m && pow > 0)
	{
		if (pow == 1)
			return A;
		else
		{
			Matrix C(A);
			for (int i = 0; i < pow; i++)
			{
				C = C * A;
			}
			return C;
		}
	}
	else
	{
		Matrix V(1, 1, 2.e-308);
		return V;
	}
}
//Matrix operator^( Matrix& A, int& p)
//{
//	return pow(A, p);
//}

ostream& operator<<(ostream& stream, Matrix& A)
{
	stream << endl;
	for (int i = 0; i < A.n; i++)
	{
	stream << "|| \t ";
		for (int j = 0; j < A.m; j++)
		{
			stream << A.M[i][j] << "   \t " ;
		}
		stream << " ||" << endl;
	}
	stream << endl;
	return stream;
}
istream& operator>>(istream& stream,  Matrix& A) 
{
	cout << "Enter kol strok" << endl;
	stream >> A.n;
	cout << "Enter kol stolb" << endl;
	stream >> A.n;
	A.M = new double* [A.n];
	for (int i = 0; i < A.n; i++)
	{
		A.M[i] = new double[A.m];
		for(int j = 0; j < A.m;j++)
		{
			cout << "Enter element number " << "[" << i << "][" << j << "]" << endl;
			stream >> A.M[i][j];
		}
	}
	return stream;
}

bool Matrix::operator==(const Matrix& A) 
{
	if (n == A.n && m == A.m)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (M[i][j] != A.M[i][j])
					return false;
			}
		}
		return true;
	}
	else
		return false;
}


void Rand_Arr(int n, int m, double**& A)
{
	srand(time_t(NULL));
	double** arr = new double* [n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new double[m];
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = 1. * rand() / RAND_MAX * (100) - 50;
		}
	}
	delete[] A;
	A = arr;
}
