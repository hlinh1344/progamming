#include<iostream>
using namespace std;

//	//exercise 20
//void nhap(int& n);
//void tinhvaxuat(int n);
//int main() {
//	int n;
//	nhap(n);
//	tinhvaxuat(n);
//	
//	system("pause");
//	return 0;
//}
//
//void nhap(int& n) {
//	cout << "nhap so nguyen duong n: ";
//	do {
//		cin >> n;
//		if (n <= 0) {
//			cout << "nhap sai, moi nhap lai: ";
//		}
//	} while (n <= 0);
//}
//
//void tinhvaxuat(int n) {
//
//	cout << "Cac uoc so cua " << n << " la:" << endl;
//	for (int i = 1; i <= (int)(n / 2); i++) {
//		if (n % i == 0) {
//			cout << i << "\t";
//		}
//	}
//	cout << n << endl;
//}


//	//exercise 21
//void nhap(int& n);
//int tinhS(int n);
//void xuat(int S, int n);
//
//int main() {
//	int n;
//	nhap(n);
//	int S = tinhS(n);
//	xuat(S,n);
//
//
//	system("pause");
//	return 0;
//}
//
//void nhap(int& n) {
//	cout << "nhap so nguyen duong n: ";
//	do {
//		cin >> n;
//		if (n <= 0) {
//			cout << "nhap sai, moi nhap lai: ";
//		}
//	} while (n <= 0);
//}
//
//int tinhS(int n) {
//	int S = n;
//
//	for (int i = 1; i <= (n / 2); i++) {
//		if (n % i == 0)
//		{
//			S = S + i;
//		}
//	}
//	return S;
//}
//
//void xuat(int S,int n) {
//	cout << "Tong cac uoc so cua " << n << " la: ";
//	cout << S << endl;
//}


//	//exercise 22
//void nhap(int& n);
//int tinhP(int n);
//void xuat(int P,int n);
//
//int main() {
//	int n;
//	nhap(n);
//	int P = tinhP(n);
//	xuat(P, n);
//
//	system("pause");
//	return 0;
//}
//
//void nhap(int& n) {
//	cout << "nhap so nguyen duong n: ";
//	do {
//		cin >> n;
//		if (n <= 0) {
//			cout << "nhap sai, moi nhap lai: ";
//		}
//	} while (n <= 0);
//}
//
//int tinhP(int n) {
//	int P = n;
//	int i = 1;
//	while (i <= (n / 2)) {
//		if (n % i == 0) {
//			P = P * i;
//		}
//		i++;
//	}
//	return P;
//}
//
//void xuat(int P,int n) {
//	cout << "Tich cac uoc so cua " << n << " la: ";
//	cout << P << endl;
//}


//	//exercise 23
//void nhap(int &n);
//int tinhsouoc(int n);
//void xuat(int n, int S);
//int main() {
//	int n;
//	nhap(n);
//	int S = tinhsouoc(n);
//	xuat(n,S);
//
//	system("pause");
//	return 0;
//}
//
//void nhap(int& n) {
//	cout << "nhap so nguyen duong n: ";
//	do {
//		cin >> n;
//		if (n <= 0) {
//			cout << "nhap sai, moi nhap lai: ";
//		}
//	} while (n <= 0);
//
//}
//
//int tinhsouoc(int n) {
//	int S = 1;
//	for (int i = 1; i <= (n / 2); i++) {
//		if (n % i == 0) {
//			cout << i << "\t";
//			S = S + 1;
//		}
//	}
//	cout << n << endl;
//	return S;
//}
//
//void xuat(int n, int S) {
//	cout << "\n";
//	cout << "So luong uoc so cua " << n << " la: " << S << endl;
//}


//	//exercise 24
//void nhap(int& n);
//void tinhvaxuat(int n);
//
//int main() {
//	int n;
//	nhap(n);
//	tinhvaxuat(n);
//
//	cout << "\n";
//	system("pause");
//	return 0;
//}
//
//void nhap(int& n) {
//	cout << "nhap so nguyen duong n: ";
//	do {
//		cin >> n;
//		if (n <= 0) {
//			cout << "nhap sai, moi nhap lai: ";
//		}
//	} while (n <= 0);
//
//}
//
//
//void tinhvaxuat(int n) {
//	cout << "Cac uoc so le cua " << n << " la: \n";
//	int i = 1;
//	while (i <= (n / 2)) {
//		if (((n % i) == 0) && (i % 2 == 1)) {
//			cout << i << "\t\t";
//		}
//		i++;
//	}
//	if (n % 2 != 0) {
//		cout << n << endl;
//	}
//
//}

//	//exercise 25
//void nhap(int &n);
//int uocsochan(int n);
//void xuat(int n, int S);
//int main() {
//	int n;
//	nhap(n);
//	int S = uocsochan(n);
//	xuat(n,S);
//	system("pause");
//	return 0;
//}
//
//void nhap(int& n) {
//	cout << "nhap so nguyen duong n: ";
//	do {
//		cin >> n;
//		if (n <= 0) {
//			cout << "nhap sai, moi nhap lai: ";
//		}
//	} while (n <= 0);
//}
//
//int uocsochan(int n) {
//	int S = 0;
//	int i = 1;
//	while (i < (n / 2)) {
//		if ((n % i == 0) && (i % 2 == 0)) {
//			cout << i << "\t\t";
//			S = S + i;
//		}
//		i++;
//	}
//
//	if (n % 2 == 0) {
//		cout << n;
//		S = S + n;
//	}
//	return S;
//}
//
//void xuat(int n, int S) {
//	cout << "\n";
//	cout << "Tong uoc so chan cua " << n << " la : " << S << endl;
//	cout << "\n";
//}


//	//exercise 26
//void nhap(int &n);
//int tichuocsole(int n);
//void xuat(int n, int P);
//int main() {
//	int n;
//	nhap(n);
//	int P = tichuocsole(n);
//	xuat(n, P);
//
//	system("pause");
//	return 0;
//}
//
//void nhap(int& n) {
//	cout << "nhap so nguyen duong n: ";
//	do {
//		cin >> n;
//		if (n <= 0) {
//			cout << "nhap sai, moi nhap lai: ";
//		}
//	} while (n <= 0);
//}
//
//int tichuocsole(int n) {
//	int P = 1;
//	int i = 1;
//	while (i <= (n / 2)) {
//		if ((n % i == 0) && (i % 2 == 1)) {
//			P = P * i;
//			cout << i << "\t\t";
//		}
//		i++;
//	}
//	if (n % 2 == 1) {
//		P = P * n;
//		cout << n << endl;
//	}
//	return P;
//}
//
//void xuat(int n, int P) {
//	cout << "\n";
//	cout << "Tich uoc so le cua " << n << " la : " << P << endl;
//	cout << "\n";
//}



#pragma region Region_1
void bai27();
void bai28();
void bai29();
void bai30();
void bai31();
void bai32();
void bai33();

void nhapn(int& n);
int souocchan(int n);
void xuat27(int n, int S);
int tonguocsonhohonn(int n);
void xuat28(int n, int S);
int uocsolelonnhat(int n);
void xuat29(int n, int uoclelonnhat);
void xuat30(bool isPerfectNumber, int n);
bool Checksohoanthien(int n);
bool check31(int n);
bool check32(int n);
float tinh33(int n);

#pragma endregion Region_1
int main()
{
	int bai = 33;
	switch (bai)
	{
	case 231:
		bai27();
		break;
	case 28:
		bai28();
		break;
	case 29:
		bai29();
		break;
	case 30:
		bai30();
		break;
	case 31:
		bai31();
		break;
	case 32:
		bai32();
		break;
	case 33:
		bai33();
		break;
	default:
		break;
	}

	return 0;
}

#pragma region Bai27

void bai27() {
	int n;
	nhapn(n);
	int S = souocchan(n);
	xuat27(n, S);
	system("pause");
}

	void nhapn(int& n) {
		cout << "nhap so nguyen duong n: ";
		do {
			cin >> n;
			if (n <= 0) {
				cout << "nhap sai, moi nhap lai: ";
			}
		} while (n <= 0);


	}

	int souocchan(int n) {
		int S = 0;
		int i = 1;
		while (i <= n / 2) {
			if ((n % i == 0) && (i % 2 == 0)) {
				S = S + 1;
			}
			i++;
		}
		if (n % 2 == 0) {
			S = S + 1;
		}
		return S;
	}

	void xuat27(int n, int S) {
		cout << "\n";
		cout << "So luong uoc so chan cua " << n << " la: " << S << endl;
	}
#pragma endregion Bai27


#pragma region Bai28
void bai28() {
	int n;
	nhapn(n);
	int S = tonguocsonhohonn(n);
	xuat28(n,S);

	system("pause");

}

int tonguocsonhohonn(int n) {
	int S = 0;
	int i = 1;
	while (i <= n/2)
	{
		if (n % i == 0) {
			S = S + i;
			cout << i << "\t";
		}
		i++;
	}
	return S;
}

void xuat28(int n, int S) {
	cout << "\n";
	cout << "Tong cac uoc so nho hon " << n << " cua " << n << " la: ";
	cout << S << endl;
}
#pragma endregion Bai28

#pragma region Bai29
void bai29(){
	int n;
	nhapn(n);
	int uoclelonnhat = uocsolelonnhat(n);
	xuat29(n,uoclelonnhat);
	system("pause");

}

int uocsolelonnhat(int n) {

	int uoclelonnhat = 1;
	if (n % 2 != 0) {
		uoclelonnhat = n;
	}
	else {
		int i = (n / 2);
		while (i >0){
			if ((n % i == 0) && (i % 2 == 1)) {
				uoclelonnhat = i;
				break;
			}
			i--;
		}
	}
	return uoclelonnhat;
}

void xuat29(int n, int uoclelonnhat) {
	cout << "uoc so le lon nhat cua " << n << " la " << uoclelonnhat << endl;
	cout << "\n";
}
#pragma endregion Bai29


#pragma region Bai30
	//exercise 30
void bai30() {
	int n;
	nhapn(n);

	bool isPerfectNumber = Checksohoanthien(n);
	xuat30(isPerfectNumber, n);
	system("pause");
	
}

bool Checksohoanthien(int n) {
	int S = 0;
	int i = 1;
	while (i <= (n / 2)) {
		if (n % i == 0) {
			S = S + i;
		}
		i++;
	}

	if (S == n) {
		return 1;
	}
	else
	{
		return 0;
	}
}

void xuat30(bool isPerfectNumber, int n) {
	cout << "\n";
	if (isPerfectNumber == 1) {
		cout << n << " la so hoan thien" << endl;
	}
	else
	{
		cout << n << " khong phai la so hoan thien" << endl;
	}
}

#pragma endregion Bai30

#pragma region Bai31
	//exercise 31
void bai31() {
	int n;
	nhapn(n);
	bool isPrimeNumber = check31(n);
	if (isPrimeNumber == 1) {
		cout << n << " la so nguyen to" << endl;
	}
	else
	{
		cout << n << " khong phai la so nguyen to" << endl;
	}
	system("pause");
}

bool check31(int n) {
	bool isPrimeNumber = 1;

	if ((n == 2) || (n == 3)) {
		isPrimeNumber = 1;
	}
	else if ((n == 1) || (n == 0) || (n % 2 == 0))
	{
		isPrimeNumber = 0;
	}
	else
	{
		for (int i = 2; i <= int(n / 2); i++) {
			if (n % i == 0) {
				isPrimeNumber = 0;
				break;
			}

		}
	}
	return isPrimeNumber;
}
#pragma endregion Bai31

#pragma region Bai32
	//exercise 32
void bai32() {
	int n;
	nhapn(n);

	bool isSquareNumber = check32(n);


	if (isSquareNumber == 1) {
		cout << n << " la so chinh phuong" << endl;
	}
	else
	{
		cout << n << " khong phai la so chinh phuong" << endl;
	}

	system("pause");
}

bool check32(int n) {
	bool check = 0;
	if (n == 1) {
		check = 1;
	}
	else
	{
		int i = 1;
		while (i <= n / 2)  {
			if (i * i == n) {
				check = 1;
				break;
			}
			i++;
		}


	}
	return check;
}
#pragma endregion Bai32

#pragma region Bai33
	//exercise 33
void bai33() {
	int n;
	nhapn(n);
	float S = tinh33(n);

	cout << "S = "<< S<<endl;
	system("pause");

}

float tinh33(int n) {
	float S = 0.0f;
	for (int i = 0; i < n; i++) {
		S = sqrt(2 + S);
	}
	return S;
}
#pragma endregion Bai33

#pragma region Bai34
#pragma endregion Bai34

#pragma region Bai35
#pragma endregion Bai35

#pragma region Bai36
#pragma endregion Bai36