#pragma once


#include<iostream>
#include<cmath>
#include<ctime>
using namespace std;


class Matrix
{
private:
	int n;
	int m;
	double** M;


public:
	
	Matrix(int n, int m, double** A);
	Matrix(int n, double** A);

	Matrix(int n);
	Matrix(int n, int m);
	Matrix(int n, int m, double element);
	Matrix(int n, int m, int element);

	Matrix(Matrix& A);
	Matrix();

	~Matrix() { 
		for (int i = 0; i < n; i++)
			delete[]M[i];
		delete[]M;
	};

	/*void delete()
	{
		~Matrix();
	}*/

	void set(int n, int m, double element);
	double get(int n, int m);


	Matrix cut(const int&I,const  int& J);
	double det();
	Matrix T();
	Matrix rev();

    void E();


	double minor(const int &n,const int &m);
	double algEdit(const int& n, const int& m);

	Matrix operator+(const Matrix& A);
	Matrix operator-(const Matrix& A);
	Matrix operator*( Matrix& A);
	friend Matrix Pow(Matrix& A, int pow);
	
	/*friend Matrix operator^(Matrix& A, int& pow);*/

	Matrix operator*(const double& a);
	Matrix operator/(const double& a);

	Matrix operator=(const Matrix& A);

	friend ostream& operator<<(ostream& stream,  Matrix &A);
	friend istream& operator>>(istream& stream, Matrix& A);

	bool operator==(const Matrix& A);



};

Matrix Pow( Matrix& A, int pow);

//Matrix operator^( Matrix& A, int& pow);

ostream& operator<<(ostream& stream, Matrix& A);
istream& operator>>(istream& stream, Matrix& A);

void Rand_Arr(int n, int m, double**& A); 
