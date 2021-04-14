#include<iostream>
using namespace std;

#pragma region Region_1
void nhapn(int &n);
void bai1();
void bai2();
void bai3();
void bai4();
void bai5();
void bai6();
void bai7();
void bai8();
void bai9();
void bai10();
void bai11();

int xuly2(int n);
int xuly1(int n);
float xuly3(int n);
float xuly4(int n);
float xuly5(int n);
float xuly6(int n);
float xuly7(int n);
float xuly8(int n);
float xuly9(int n);
int xuly10(int n, int x);
void nhapxn(int& n, int& x);
int giaithua(int n);
int xuly11b(int n);
#pragma endregion Region_1
int main() {
	int bai = 11;
	switch (bai)
	{
	case 1:
		bai1();
		break;
	case 2:
		bai2();
		break;
	case 3:
		bai3();
		break;
	case 4:
		bai4();
		break;
	case 5:
		bai5();
		break;
	case 6:
		bai6();
		break;
	case 7:
		bai7();
		break;
	case 8:
		bai8();
		break;
	case 9:
		bai9();
		break;
	case 10:
		bai10();
		break;
	case 11:
		bai11();
		break;
	default:
		break;
	}
	system("pause");
	return 0;
}

#pragma region Bai1
void bai1() {

	int n;
	nhapn(n);

	int S = xuly1(n);
	cout << "S = " << S << endl;
}

void nhapn(int &n){
	do {
		cout << "nhap so n: ";
		cin >> n;
		if (n <= 0) {
			cout << "nhap sai moi nhap lai ";
		}
	} 	while (n <= 0);
}

int xuly1(int n) {
	if (n == 1)
		return 1;
	return xuly1(n - 1) + n;
}
#pragma endregion Bai1

#pragma region Bai2
void bai2() {
	int n;
	nhapn(n);
	int S = xuly2(n);
	cout << "S = " << S << endl;
}

int xuly2(int n) {
	if (n == 1) {
		return 1 * 1;
	}
	return xuly2(n - 1) + (n * n) ;
}

#pragma endregion Bai2

#pragma region Bai3
void bai3() {
	int n;
	nhapn(n);
	float s = xuly3(n);
	cout << "S = " << s << endl;
}

float xuly3(int n) {
	if (n == 1) {
		return 1;
	}
	return (xuly3(n - 1) + (1 / (float)n));
}
#pragma endregion Bai3

#pragma region Bai4
void bai4() {
	int n;
	nhapn(n);
	float S = xuly4(n);
	cout << S << endl;
	system("pause");
}

float xuly4(int n) {
	if (n == 1) {
		return 1 /(float) (2 * 1);
	}
	return (xuly4(n - 1) + (1 / (float)(2 * n)));
}
#pragma endregion Bai4

#pragma region Bai5
	//exercise 5

void bai5() {
	int n;
	nhapn(n);
	float S = xuly5(n);

	cout << S << endl;
	system("pause");

}


float xuly5(int n) {
	if (n == 0) {
		return 1;
	}
	return (xuly5(n-1 )+ 1 / (float)(2 * n + 1));
}

#pragma endregion Bai5

#pragma region Bai6
	//exercise 6

void bai6(){
	int n;
	nhapn(n);

	float S = xuly6(n);
	cout << S << endl;
	system("pause");
}

float xuly6(int n) {
	if (n == 1) {
		return 1 / float(1 * 2);
	}
	return (xuly6(n - 1) + 1 / (float)(n * (n + 1)));
}

#pragma endregion Bai6

#pragma region Bai7
//exercise 7
void bai7() {
	int n;
	nhapn(n);
	float S = xuly7(n);
	cout << "S = " << S << endl;
	system("pause");
}

float xuly7(int n) {
	if (n == 1) {
		return 1 / float(1 + 1);
	}
	return (xuly7(n - 1) + n / float(n + 1));
}
#pragma endregion Bai7

#pragma region Bai8
void bai8() {
	int n;
	nhapn(n);
	float S = xuly8(n);
	cout << "S = " << S << endl;
	system("pause");
}

float xuly8(int n) {
	if (n == 0) {
		return (2 * 0 + 1) / float(2 * 0 + 2);
	}
	return xuly8(n - 1) + (2 * n + 1) / float(2 * n + 2);
}
#pragma endregion Bai8

#pragma region Bai9
	//exercise 9
void bai9(){
	int n;
	nhapn(n);
	float P = xuly9(n);
	cout << "P = " << P << endl;
	system("pause");
}

float xuly9(int n) {
	if (n == 1) {
		return 1;
	}
	return xuly9(n - 1) * n;
}
#pragma endregion Bai9

#pragma region Bai10
void bai10() {
	int n, x;
	nhapxn(n,x);
	int P = xuly10(n, x);;
	

	cout << x << " mu " << n << " = " << P << endl;
	system("pause");
}
void nhapxn(int& n,int &x) {
	cout << "nhap so x: ";
	cin >> x;
	cout << "nhap so mu n: ";
	cin >> n;
}

int xuly10(int n,int x) {
	if (n == 0) {
		return 1;
	}
	if (n == 1) {
		return x;
	}

	return xuly10(n-1,x) * x;

}


#pragma endregion Bai10

#pragma region Bai11
	//exercise 11


void bai11() {
	int n;
	nhapn(n);
	int S =  xuly11b(n);
	cout << "S = " << S << endl;
	system("pause");
}


int giaithua(int n) {
	if (n == 1) {
		return 1;
	}
	return  giaithua(n-1) *n;
}

int xuly11b(int n) {
	if (n == 1) {
		return 1;
	}
	return  giaithua(n) + xuly11b(n -1);
}
#pragma endregion Bai11