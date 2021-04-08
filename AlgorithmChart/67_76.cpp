#include<iostream>
using namespace std;

//	//exercise 67
//int main() {
//	int x;
//	cout << "nhap so nguyen x: ";
//	cin >> x;
//
//	int n;
//	cout << "nhap so nguyen duong n: ";
//	do {
//		cin >> n;
//		if (n <= 0) {
//			cout << "nhap sai, moi nhap lai: ";
//		}
//	} while (n <= 0);
//
//	int S = 0;
//	int P1 = -1;
//	int P2 = 1;
//
//	for (int i = 1; i <= n; i++) {
//		P1 = P1 * (-1);
//		P2 = P2 * x;
//		S = S + (P1 * P2);
//	}
//
//	cout << "S = " << S << endl;
//	system("pause");
//	return 0;
//}


//	//exercise 68
//int main() {
//	int x;
//	cout << "nhap so nguyen x: ";
//	cin >> x;
//
//	int n;
//	cout << "nhap so nguyen duong n: ";
//	do {
//		cin >> n;
//		if (n <= 0) {
//			cout << "nhap sai, moi nhap lai: ";
//		}
//	} while (n <= 0);
//
//	int S = 0;
//	int P1 = 1;
//	int P2 = 1;
//
//	for (int i = 1; i <= n; i++) {
//		P1 = P1 * (-1);
//		P2 = P2 * x * x;
//		S = S + (P1 * P2);
//	}
//
//	cout << "S = " << S << endl;
//	system("pause");
//	return 0;
//}


//	//exercise 69
//int main() {
//	int x;
//	cout << "nhap so nguyen x: ";
//	cin >> x;
//
//	int n;
//	cout << "nhap so nguyen duong n: ";
//	do {
//		cin >> n;
//		if (n < 0) {
//			cout << "nhap sai, moi nhap lai: ";
//		}
//	} while (n < 0);
//
//	int S = x;
//	int P1 = 1;
//	int P2 = x;
//
//	if (n == 0) {
//		S = x;
//	}
//	else {
//		for (int i = 1; i <= n; i++) {
//			P1 = P1 * (-1);
//			P2 = P2 * x * x;
//			S = S + (P1 * P2);
//		}
//	}
//
//
//	cout << "S = " << S << endl;
//	system("pause");
//	return 0;
//}


//	//exercise 70
//int main() {
//
//	int n;
//	cout << "nhap so nguyen duong n: ";
//	do {
//		cin >> n;
//		if (n <= 0) {
//			cout << "nhap sai, moi nhap lai: ";
//		}
//	} while (n <= 0);
//
//	float S = 0;
//	int P1 = -1;
//	float mauso = 0;
//
//
//	for (int i = 1; i <= n; i++) {
//		P1 = P1 * (-1);
//		mauso = mauso + i;
//		S = S + (P1 * (1/mauso));
//	}
//
//	cout << "S = " << S << endl;
//	system("pause");
//	return 0;
//}


//	//exercise 71
//int main() {
//	int x;
//	cout << "nhap so nguyen x: ";
//	cin >> x;
//
//	int n;
//	cout << "nhap so nguyen duong n: ";
//	do {
//		cin >> n;
//		if (n <= 0) {
//			cout << "nhap sai, moi nhap lai: ";
//		}
//	} while (n <= 0);
//
//	float S = 0;
//	int P1 = 1;
//	int tuso = 1;
//	float mauso = 0;
//
//
//	for (int i = 1; i <= n; i++) {
//		P1 = P1 * (-1);
//		tuso = tuso * x;
//		mauso = mauso + i;
//		S = S + (P1 * (tuso/mauso));
//	}
//
//	cout << "S = " << S << endl;
//	system("pause");
//	return 0;
//}


//	//exercise 72
//int main() {
//	int x;
//	cout << "nhap so nguyen x: ";
//	cin >> x;
//
//	int n;
//	cout << "nhap so nguyen duong n: ";
//	do {
//		cin >> n;
//		if (n <= 0) {
//			cout << "nhap sai, moi nhap lai: ";
//		}
//	} while (n <= 0);
//
//	float S = 0;
//	int P1 = 1;
//	int tuso = 1;
//	float mauso = 1;
//
//
//	for (int i = 1; i <= n; i++) {
//		P1 = P1 * (-1);
//		tuso = tuso * x;
//		mauso = mauso * i;
//		S = S + (P1 * tuso / mauso);
//	}
//
//	cout << "S = " << S << endl;
//	system("pause");
//	return 0;
//}


//	//exercise 73
//int main() {
//	int x;
//	cout << "nhap so nguyen x: ";
//	cin >> x;
//
//	int n;
//	cout << "nhap so nguyen duong n: ";
//	do {
//		cin >> n;
//		if (n < 0) {
//			cout << "nhap sai, moi nhap lai: ";
//		}
//	} while (n < 0);
//
//	float S = -1;
//	int P1 = -1;
//	int tuso = 1;
//	float mauso = 1;
//
//	if (n == 0) {
//		S = -1;
//	}
//	else {
//
//
//		for (int i = 1; i <= n; i++) {
//			P1 = P1 * (-1);
//			tuso = tuso * x * x;
//			mauso = mauso * ((2 * i) - 1) * (2 * i);
//			S = S + (P1 * tuso / mauso);
//		}
//	}
//	cout << "S = " << S << endl;
//	system("pause");
//	return 0;
//}


//	//exercise 74
//int main() {
//	int x;
//	cout << "nhap so nguyen x: ";
//	cin >> x;
//
//	int n;
//	cout << "nhap so nguyen duong n: ";
//	do {
//		cin >> n;
//		if (n < 0) {
//			cout << "nhap sai, moi nhap lai: ";
//		}
//	} while (n < 0);
//
//	float S = 1 - x;
//	int P1 = -1;
//	int tuso = x;
//	float mauso = 1;
//
//	if (n == 0) {
//		S = S = 1 - x;
//	}
//	else {
//
//		for (int i = 1; i <= n; i++) {
//			P1 = P1 * (-1);
//			tuso = tuso * x * x;
//			mauso = mauso * (2 * i) * ((2 * i) + 1);
//			S = S + (P1 * tuso / mauso);
//		}
//	}
//	cout << "S = " << S << endl;
//	system("pause");
//	return 0;
//}


	//exercise 75
int main() {
	int n;
	cout << "nhap so nguyen n: ";
	cin >> n;

	bool is2muk = 1;
	int somu=0;
	int a = n;

	for (int i = 0;a != 2 && a != 1; i++) {
		a = a / 2;		
		if ((a % 2 == 1)) {
			is2muk = 0;
			break;
		}			
		somu++;
	}
	if(a!=1)
		somu++;;

	if (is2muk) {
		cout << "so tu nhien " << n << " la 2 mu "<<somu << endl;
	}
	else {
		cout << "so tu nhien " << n << " khong phai la 2 mu k"<< endl;
	}

	system("pause");
	return 0;
}


////exercise 76
//int main() {
//	int n;
//	cout << "nhap so nguyen n: ";
//	cin >> n;
//
//	bool is3muk = 0;
//	int somu;
//	int a=1;
//	for (int i = 0; i < 32; i++) {
//		if (a == n) {
//			is3muk = 1;
//			somu = i;
//			break;
//		}
//
//		a = a * 3;
//
//	}
//
//	if (is3muk) {
//		cout << "so tu nhien " << n << " la 3 mu " << somu << endl;
//	}
//	else {
//		cout << "so tu nhien " << n << " khong phai la 3 mu k" << endl;
//	}
//
//	system("pause");
//	return 0;
//}
