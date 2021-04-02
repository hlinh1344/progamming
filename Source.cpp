#include<iostream>
using namespace std;


int main() {
	
	/*
	//ex1
	int n;
    cout << "nhap so n: ";
	cin >> n;
	int S = 0;
	for (int i = 1; i <= n; i++) {
		S = S + i;
	}
	cout << S << endl; 
	*/

	/*
	//ex2
	int n;
	cout << "nhap so n: ";
	cin >> n;
	int S = 0;
	for (int i = 1; i <= n; i++) {
		S = S + i*i;
	}
	cout << S << endl;
	*/

	/*
	//ex3
	int n;
	cout << "nhap so n: ";
	cin >> n;

	float S = 0.0f;

	for (int i = 1; i <= n; i++) {
		S = S + (1/(float)i);
	}
	cout << S << endl;
	*/


	/*
	//ex4
	int n;
	cout << "nhap so n: ";
	cin >> n;

	float S = 0.0f;

	for (int i = 1; i <= n; i++) {
		S = S + (1 /(float)2*i);
	}
	cout << S << endl;
	*/

	/*
	//ex5
	int n;
	cout << "nhap so n: ";
	cin >> n;

	float S = 0.0f;

	for (int i = 0; i <= n; i++) {
		S = S + (1 / (float)(2*i+1));
	}
	cout << S << endl;
	*/

	/*
	//ex6
	int n;
	cout << "nhap so n: ";
	cin >> n;

	float S = 0.0f;

	for (int i = 1; i <= n; i++) {
		S = S + (1 / (float)(i * (i + 1))) ;
	}
	cout << S << endl;
	*/

	/**
	//ex7
	int n;
	cout << "nhap so n: ";
	cin >> n;

	float S = 0.0f;

	for (int i = 1; i <= n; i++) {
		S = S + (i / (float)(i+1)) ;
	}
	cout << S << endl;
	*/

	/*
	//ex8
	int n;
	cout << "nhap so n: ";
	cin >> n;

	float S = 0.0f;

	for (int i = 0; i <= n; i++) {
		S = S + ((2*i+1) / (float)(2*i + 2));
	}
	cout << S << endl;
	*/

	/*
	//ex9
	int n;
	cout << "nhap so n: ";
	cin >> n;
	float P = 1.0f;

	for (int i = 1; i <= n; i++) {
		P = P * i;
	}
	cout << P << endl;
	*/

	/*
	//ex10
	int n,x;
	cout << "nhap so x: ";
	cin >> x;
	cout << "nhap so mu n: ";
	cin >> n;

	int P = 1;
	if (n == 0)
		P = 1;
	else
	{
		for (int i = 0; i < n; i++) {
			P = P * x;
		}
	
	}
	cout << x << " mu "<<n<< " = "<< P << endl;
	*/


	/*
	//ex11
	int n;
	cout << "nhap so n: ";
	cin >> n;
	int S = 0;
	for (int i = 1; i <= n ; i++)
	{
		int P = 1;
		for (int j = 1; j <= i; j++) {
			P = P * j;
		}
		S = S + P;
	}
	cout << S << endl;
	*/

	/*
	//ex12
	int n, x;
	cout << "nhap so x: ";
	cin >> x;
	cout << "nhap so n: ";
	cin >> n;

	int S = 0;
	for (int i = 1; i <= n; i++) {
		int P = 1;
		for (int j = 1; j <= i; j++) {
			P = P * x;
		}
		S = S + P;

	}
	*/
	
	

	cout << S << endl;
	system("pause");
	return 0;

}

