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
void bai34();
void bai35();
void bai36();
void bai37();
void bai38();
void bai39();
void bai40();
void bai41();
void bai42();
void bai43();
void bai44();
void bai45();
void bai46();
void bai47();
void bai48();
void bai49();
void bai50();
void bai51();
void bai52();
void bai53();
void bai54();
void bai55();
void bai56();
void bai57();
void bai59();
void bai60();
void bai61();
void bai62();
void bai63();
void bai64();
void bai65();

void nhapn(int& n);
void nhapxn(int& x, int& n);
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
float xuly33(int n);
float xuly34(int n);
float xuly35(int n);
float xuly36(int n);
float xuly37(int n);
float xuly38(int n);
float xuly39(int n);
float xuly40(int n, int x);
float xuly41(int n);
void xuly42(int n);
void xuly43(int n);
void xuly44(int n);
void xuly45(int n);
void xuly46(int n);
void xuly47(int n);
void xuly48(int n);
void xuly49(int n);
void xuly50(int n);
void xuly51(int n);
void xuly52(int n);
void xuly53(int n);
void xuly54(int n);
void xuly55(int n);
void xuly56(int n);
void xuly57(int n);
void xuly59(int n);
void xuly60(int n);
void xuly61(int n);
void nhapab(int& a, int& b);
int xuly62(int a, int b);
void xuly64(float a, float b);
void nhap64(float& a, float& b);
void xuly65(float a, float b, float c);
void nhap65(float& a, float& b, float& c);

#pragma endregion Region_1
int main()
{
	int bai = 65;
#pragma region switch
	switch (bai)
	{
	case 27:
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
	case 34:
		bai34();
		break;
	case 35:
		bai35();
		break;
	case 36:
		bai36();
		break;
	case 37:
		bai37();
		break;
	case 38:
		bai38();
		break;
	case 39:
		bai39();
		break;
	case 40:
		bai40();
		break;
	case 41:
		bai41();
		break;
	case 42:
		bai42();
		break;
	case 43:
		bai43();
		break;
	case 44:
		bai44();
		break;
	case 45:
		bai45();
		break;
	case 46:
		bai46();
		break;
	case 47:
		bai47();
		break;
	case 48:
		bai48();
		break;
	case 49:
		bai49();
		break;
	case 50:
		bai50();
		break;
	case 51:
		bai51();
		break;
	case 52:
		bai52();
		break;
	case 53:
		bai53();
		break;
	case 54:
		bai54();
		break;
	case 55:
		bai55();
		break;
	case 56:
		bai56();
		break;
	case 57:
		bai57();
		break;
	case 58:
		bai57();
		break;
	case 59:
		bai59();
		break;
	case 60:
		bai60();
		break;
	case 61:
		bai61();
		break;
	case 62:
		bai62();
		break;
	case 63:
		bai63();
		break;
	case 64:
		bai64();
		break;
	case 65:
		bai65();
		break;
	default:
		break;
	}
#pragma endregion switch
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
	xuat28(n, S);

	system("pause");

}

int tonguocsonhohonn(int n) {
	int S = 0;
	int i = 1;
	while (i <= n / 2)
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
void bai29() {
	int n;
	nhapn(n);
	int uoclelonnhat = uocsolelonnhat(n);
	xuat29(n, uoclelonnhat);
	system("pause");

}

int uocsolelonnhat(int n) {

	int uoclelonnhat = 1;
	if (n % 2 != 0) {
		uoclelonnhat = n;
	}
	else {
		int i = (n / 2);
		while (i > 0) {
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
		while (i <= n / 2) {
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
	float S = xuly33(n);

	cout << "S = " << S << endl;
	system("pause");

}

float xuly33(int n) {
	float S = 0.0f;
	for (int i = 0; i < n; i++) {
		S = sqrt(2 + S);
	}
	return S;
}
#pragma endregion Bai33

#pragma region Bai34
//exercise 34
void bai34() {
	int n;
	nhapn(n);

	float S = xuly34(n);
	cout << "S = " << S << endl;
	system("pause");
}

float xuly34(int n) {
	float S = 0.0f;
	for (int i = 1; i <= n; i++) {
		S = sqrt(i + S);
	}
	return S;
}

#pragma endregion Bai34

#pragma region Bai35
//exercise 35
void bai35() {
	int n;
	nhapn(n);

	float S = xuly35(n);
	cout << "S = " << S << endl;
	system("pause");

}

float xuly35(int n) {
	float S = 0.0f;
	for (int i = n; i >= 1; i--) {
		S = sqrt(i + S);
	}
	return S;
}
#pragma endregion Bai35

#pragma region Bai36
void bai36() {
	int n;
	nhapn(n);

	float S = xuly36(n);
	cout << "S = " << S << endl;
	system("pause");
}

float xuly36(int n) {
	float S = 0.0f;
	int P = 1;
	for (int i = 1; i <= n; i++) {
		P = P * i;
		S = sqrt(P + S);
	}
	return S;
}
#pragma endregion Bai36

#pragma region Bai37

void bai37() {
	int n;
	nhapn(n);

	float S = xuly37(n);

	system("pause");
}

float xuly37(int n) {
	float S = 0.0f;
	if (n == 1) {
		cout << "S = " << S << endl;
	}
	else {

		for (int i = 2; i <= n; i++) {
			float temp1 = (float)(i)+S;
			float temp2 = 1 / (float)i;
			S = pow(temp1, temp2);
		}
		cout << "S = " << S << endl;
	}
	return S;
}
#pragma endregion Bai37

#pragma region Bai38
//exercise 38
void bai38() {
	int n;
	nhapn(n);
	float S = xuly38(n);
	cout << "S = " << S << endl;

	system("pause");

}

float xuly38(int n) {
	float S = 0.0f;
	for (int i = 2; i <= n + 1; i++) {
		float temp1 = (float)(i - 1) + S;
		float temp2 = 1 / (float)i;
		S = pow(temp1, temp2);
	}
	return S;
}

#pragma endregion Bai38

#pragma region Bai39
//exercise 39
void bai39() {
	int n;
	nhapn(n);

	float S = xuly39(n);
	cout << "S = " << S << endl;

	system("pause");
}

float xuly39(int n) {
	float S = 0.0f;
	float  P = 1.0f;
	for (int i = 1; i <= n; i++) {
		P = P * i;
		S = pow(P + S, 1 / (float)(i + 1));
	}
	return S;
}
#pragma endregion Bai39

#pragma region Bai40
//exercise 40
void bai40() {
	int x;
	int n;
	nhapxn(x, n);

	float S = xuly40(n, x);


	cout << "S = " << S << endl;

	system("pause");

}

void nhapxn(int& x, int& n) {
	cout << "nhap so x: ";
	cin >> x;
	cout << "nhap so nguyen duong n: ";
	do {
		cin >> n;
		if (n <= 0) {
			cout << "nhap sai, moi nhap lai: ";
		}
	} while (n <= 0);
}

float xuly40(int n, int x) {
	float S = 0.0f;
	float  P = 1.0f;
	for (int i = 1; i <= n; i++) {
		P = P * x;
		S = sqrt(P + S);
	}
	return S;
}

#pragma endregion Bai40

#pragma region Bai41
//exercise 41
void bai41() {
	int n;
	nhapn(n);
	double S = xuly41(n);
	cout << "S = " << S << endl;
	system("pause");

}

float xuly41(int n) {
	float S = 1.0f;
	for (int i = 0; i < n; i++) {
		S = (1 / (1.0 + S));
	}
	return S;
}
#pragma endregion Bai41

#pragma region Bai42
//exercise 42
void bai42() {
	int n;
	nhapn(n);
	xuly42(n);

	system("pause");
}

void xuly42(int n) {
	int S = 0;
	int i = 0;
	while (S < n) {
		S = S + i;

		i++;
	}
	cout << "S = " << S - i + 1 << " < " << n << endl;
	cout << "k = " << i - 2 << endl;

}
#pragma endregion Bai42

#pragma region Bai43
//exercise 43
void bai43() {
	int n;
	nhapn(n);
	xuly43(n);

	system("pause");
}

void xuly43(int n) {
	int P = n;
	int S = 0;
	for (int i = 0; P > 0; i++) {
		S = S + 1;
		P = P / 10;
	}
	cout << "so " << n << " co " << S << " chu so" << endl;
}
#pragma endregion Bai43

#pragma region Bai44
//exercise 44
void bai44() {
	int n;
	nhapn(n);
	xuly44(n);
	system("pause");
}

void xuly44(int n) {
	int P = n;
	int S = 0;

	for (int i = 0; P > 0; i++) {
		S = S + (P % 10);
		P = P / 10;
	}

	cout << n << " co tong cac chu so = " << S << endl;
}
#pragma endregion Bai44

#pragma region Bai45
//exercise 45
void bai45() {
	int n;
	nhapn(n);
	xuly45(n);
	system("pause");

}

void xuly45(int n) {
	int P = n;
	int P2 = 1;
	for (int i = 1; P > 0; i++) {
		P2 = P2 * (P % 10);
		P = P / 10;
	}
	cout << n << " co tich cac chu so = " << P2 << endl;
}
#pragma endregion Bai45

#pragma region Bai46
//exercise 46
void bai46() {
	int n;
	nhapn(n);
	xuly46(n);


	system("pause");

}

void xuly46(int n) {
	int P = n;
	int S = 0;

	for (int i = 0; P > 0; i++) {
		if ((P % 10) % 2 == 1) {
			S++;
		}
		P = P / 10;
	}

	cout << n << " co " << S << " chu so le" << endl;
}
#pragma endregion Bai46

#pragma region Bai47
//exercise 47
void bai47() {
	int n;
	nhapn(n);
	xuly47(n);
	system("pause");
}

void xuly47(int n) {
	int P = n;
	int S = 0;

	for (int i = 1; P > 0; i++) {
		if ((P % 10) % 2 == 0) {
			S = S + (P % 10);
		}
		P = P / 10;
	}

	cout << n << " co tong cac chu so chan la " << S << endl;
}
#pragma endregion Bai47

#pragma region Bai48
//exercise 48
void bai48() {
	int n;
	nhapn(n);
	xuly48(n);
	system("pause");
}

void xuly48(int n) {
	int P = n;
	int P2 = 1;

	for (int i = 1; P > 0; i++) {
		if ((P % 10) % 2 == 1) {
			P2 = P2 * (P % 10);
		}
		P = P / 10;
	}

	cout << n << " co tich cac chu so le la " << P2 << endl;
}
#pragma endregion Bai48

#pragma region Bai49
//exercise 49
void bai49() {
	int n;
	nhapn(n);
	xuly49(n);

	system("pause");
}

void xuly49(int n) {
	int P = n;
	for (int i = 1; P > 9; i++) {
		P = P / 10;
	}
	cout << n << " co chu so dau tien la " << P << endl;
}
#pragma endregion Bai49

#pragma region Bai50
//exercise 50
void bai50() {
	int n;
	nhapn(n);
	xuly50(n);
	system("pause");

}

void xuly50(int n) {
	if (n < 10) {
		cout << n << " dao nguoc lai la so " << n << endl;
	}
	else
	{
		int P = n;
		int P2 = (P % 10);

		for (int i = 1; P > 9; i++) {
			P = P / 10;
			P2 = P2 * 10 + (P % 10);
		}
		cout << n << " dao nguoc lai la so " << P2 << endl;
	}
}
#pragma endregion Bai50

#pragma region Bai51
//exercise 51
void bai51() {
	int n;
	nhapn(n);
	xuly51(n);

	system("pause");
}
void xuly51(int n) {
	int P = n;
	int nMax = (P % 10);
	for (int i = 1; P > 0; i++) {
		P = P / 10;
		if (nMax < (P % 10)) {
			nMax = (P % 10);
		}

	}

	cout << n << " co so lon nhat la " << nMax << endl;
}
#pragma endregion Bai51

#pragma region Bai52
//exercise 52
void bai52() {
	int n;
	nhapn(n);
	xuly52(n);
	system("pause");
}

void xuly52(int n) {
	int P = n;
	int nMin = (P % 10);
	for (int i = 1; P > 9; i++) {
		P = P / 10;
		if (nMin > (P % 10)) {
			nMin = (P % 10);
		}
	}
	cout << n << " co so nho nhat la " << nMin << endl;
}
#pragma endregion Bai52

#pragma region Bai53
//exercise 53
void bai53() {
	int n;
	nhapn(n);
	xuly53(n);
	system("pause");
}

void xuly53(int n) {
	int P = n;
	int P2 = n;
	int nMax = (P % 10);
	for (int i = 1; P > 0; i++) {
		P = P / 10;
		if (nMax < (P % 10)) {
			nMax = (P % 10);
		}

	}
	int S = 0;
	for (int j = 1; P2 > 0; j++) {
		if ((P2 % 10) == nMax) {
			S = S + 1;
		}
		P2 = P2 / 10;
	}
	cout << n << " co " << S << " so lon nhat la " << nMax << endl;
}
#pragma endregion Bai53

#pragma region Bai54
//exercise 54
void bai54() {
	int n;
	nhapn(n);
	xuly54(n);
	system("pause");
}

void xuly54(int n) {
	int P = n;
	int P2 = n;
	int nMin = (P % 10);
	for (int i = 1; P > 9; i++) {
		P = P / 10;
		if (nMin > (P % 10)) {
			nMin = (P % 10);
		}

	}
	int S = 0;
	for (int j = 1; P2 > 9; j++) {
		if ((P2 % 10) == nMin) {
			S = S + 1;
		}
		P2 = P2 / 10;
	}

	cout << n << " co " << S << " so nho nhat la " << nMin << endl;
}
#pragma endregion Bai54

#pragma region Bai55
//exercise 55
void bai55() {
	int n;
	nhapn(n);

	xuly55(n);
	system("pause");
}

void xuly55(int n) {
	int P = n;
	for (int i = 1; P > 9; i++) {
		P = P / 10;
	}
	cout << n << " co chu so dau tien la " << P << endl;
	int P2 = n;
	int S = 0;

	for (int j = 1; P2 > 0; j++) {
		if ((P2 % 10) == P) {
			S = S + 1;
		}
		P2 = P2 / 10;
	}

	cout << n << " co " << S << " chu so " << P << endl;
}
#pragma endregion Bai55

#pragma region Bai56
//exercise 56
void bai56() {
	int n;
	nhapn(n);
	xuly56(n);
	system("pause");
}

void xuly56(int n) {
	int P = n;
	int le = 0;

	for (int i = 1; P > 0; i++) {
		if ((P % 10) % 2 == 0) {
			cout << "so nguyen duong " << n << " khong toan chu so le" << endl;
			break;
		}
		P = P / 10;
		if (P == 0) {
			cout << "so nguyen duong " << n << " toan chu so le" << endl;
		}
	}
}
#pragma endregion Bai56

#pragma region Bai57
//exercise 57 (58)
void bai57() {
	int n;
	nhapn(n);
	xuly57(n);
	system("pause");
}

void xuly57(int n) {
	int P = n;
	int le = 0;

	for (int i = 1; P > 0; i++) {
		if ((P % 10) % 2 != 0) {
			cout << "so nguyen duong " << n << " khong toan chu so chan" << endl;
			break;
		}

		P = P / 10;

		if (P == 0) {
			cout << "so nguyen duong " << n << " toan chu so chan" << endl;
		}

	}
}
#pragma endregion Bai57

#pragma region Bai59
//exercise 59
void bai59() {
	int n;
	nhapn(n);
	xuly59(n);


	system("pause");

}

void xuly59(int n) {
	if (n < 10) {
		cout << n << " khong phai la so doi xung " << endl;
	}
	else
	{
		int P = n;
		int P2 = (P % 10);

		for (int i = 1; P > 9; i++) {
			P = P / 10;
			P2 = P2 * 10 + (P % 10);
		}

		if (P2 == n) {
			cout << P2 << " la so doi xung" << endl;
		}
		else {
			cout << n << " khong phai la so doi xung" << endl;
		}
	}
}
#pragma endregion Bai59

#pragma region Bai60
//exercise 60
void bai60() {
	int n;
	nhapn(n);
	xuly60(n);
	system("pause");
}

void xuly60(int n) {
	bool tangdan = 1;
	if (n < 10) {
		tangdan = 0;
	}
	else {
		int P = n;

		for (int i = 1; P > 9; i++) {

			int temp = (P % 10);
			P = P / 10;
			if (temp <= (P % 10)) {
				tangdan = 0;
				break;
			}

		}
	}

	if (tangdan) {
		cout << n << " tang dan tu trai sang phai " << endl;
	}
	else {
		cout << n << " khong tang dan tu trai sang phai " << endl;
	}
}

#pragma endregion Bai60

#pragma region Bai61
//exercise 61
void bai61() {
	int n;
	nhapn(n);
	xuly61(n);
	system("pause");
}

void xuly61(int n) {
	bool giamdan = 1;
	if (n < 10) {
		giamdan = 0;
	}
	else {
		int P = n;

		for (int i = 1; P > 9; i++) {

			int temp = (P % 10);
			P = P / 10;
			if (temp >= (P % 10)) {
				giamdan = 0;
				break;
			}

		}
	}

	if (giamdan) {
		cout << n << " giam dan tu trai sang phai " << endl;
	}
	else {
		cout << n << " khong giam dan tu trai sang phai " << endl;
	}
}
#pragma endregion Bai61

#pragma region Bai62
//exercise 62
void bai62() {

	int a, b;
	nhapab(a, b);

	int uocchunglonnhat = xuly62(a, b);

	cout << "uoc chung lon nhat cua " << a << " va " << b << " la : " << uocchunglonnhat << endl;
	cout << "\n";
	system("pause");

}

void nhapab(int& a, int& b) {
	cout << "nhap so thu nhat : ";
	cin >> a;
	cout << "nhap so thu hai : ";
	cin >> b;
}

int xuly62(int a, int b) {
	while (a * b != 0) {

		if (a > b) {
			a = a % b;
		}
		else {
			b = b % a;
		}
	}
	return a + b;
}

#pragma endregion Bai62

#pragma region Bai63
//exercise 63
void bai63() {
	int a, b;
	nhapab(a, b);
	// BCNN(a, b) = a*b / UCLN(a,b)
	int boichungnhonhat = (a * b) / xuly62(a, b);

	cout << "boi chung nho nhat cua " << a << " va " << b << " la : " << boichungnhonhat << endl;
	cout << "\n";
	system("pause");
}
#pragma endregion Bai63

#pragma region Bai64
//exercise 64
void bai64() {
	cout << "\t ax + b = 0 \n";
	float a, b;
	nhap64(a, b);
	xuly64(a, b);
	system("pause");
}

void nhap64(float& a, float& b) {
	cout << "Nhap he so a : ";
	do {
		cin >> a;
		if (a == 0) {
			cout << "nhap sai, moi nhap lai: ";
		}
	} while (a == 0);

	cout << "Nhap he so b : ";
	cin >> b;
}

void xuly64(float a, float b) {
	float x;
	x = ((-b) / a);
	cout << "x = " << x << endl;
}

#pragma endregion Bai64

#pragma region Bai65
//exercise 65
void bai65() {
	cout << "\t ax^2 + bx + c = 0 \n";

	float a;
	float b;
	float c;
	nhap65(a, b, c);
	xuly65(a, b, c);
	system("pause");

}

void nhap65(float& a, float& b, float& c) {
	cout << "Nhap he so a : ";
	do {
		cin >> a;
		if (a == 0) {
			cout << "nhap sai, moi nhap lai: ";
		}
	} while (a == 0);


	cout << "Nhap he so b : ";
	cin >> b;


	cout << "Nhap he so c : ";
	cin >> c;
}

void xuly65(float a, float b, float c) {
	float x1, x2;

	if (b == 0) {
		x1 = sqrt(-c / (a));
		x2 = -sqrt(-c / (a));
		cout << "phuong trinh co 2 nghiem:" << endl;
		cout << "x1 = " << x1 << endl;
		cout << "x2 = " << x2 << endl;
	}
	else {
		float denta = ((b * b) - (4 * a * c));
		if (denta < 0) {
			cout << "phuong trinh vo nghiem" << endl;
		}
		else if (denta == 0) {
			x1 = (-b / 2 * a);
			x2 = x1;
			cout << "phuong trinh co nghiem kep: " << endl;
			cout << "x1 = x2 = " << x1 << endl;
		}
		else {
			x1 = (-b + sqrt(denta)) / (2 * a);
			x2 = (-b - sqrt(denta)) / (2 * a);
			cout << "phuong trinh co 2 nghiem:" << endl;
			cout << "x1 = " << x1 << endl;
			cout << "x2 = " << x2 << endl;
		}

	}
}
#pragma endregion Bai65

#pragma region Bai66

#pragma endregion Bai66

#pragma region Bai67

#pragma endregion Bai67

#pragma region Bai68

#pragma endregion Bai68

#pragma region Bai69

#pragma endregion Bai69