#include <iostream>
using namespace std;
void bai1();
void nhapmang(int a[], int n);
void nhapn(int &n);
void xuatmang(int a[], int n);
void sochan(int a[], int n);
void bai4(int a[], int n);
void bai5(int a[], int n);
int duongdau(int a[], int n);
void bai6(int a[], int n);
int chancuoi(int a[], int n);

int main() {
	

	int a[100];
	int n;
	nhapn(n);
	nhapmang(a, n);
	xuatmang(a, n);


	int bai = 6;
	switch (bai) {
	case 3:
		sochan(a,n);
		break;
	case 4:
		bai4(a, n);
		break;
	case 5:
		bai5(a, n);
		break;
	case 6:
		bai6(a, n);
		break;

	default:
		break;
	}
	cout << "\n";
	system("pause");
	return 0;
}

void nhapmang(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "a["<<i<<"] = ";
		cin >> a[i];
	}
}


void nhapn(int& n) {
	cout << "nhap n : ";
	cin >> n;
}

void xuatmang(int a[], int n) {
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << a[i] << "\t";
	}
}


#pragma region Bai3
void sochan(int a[], int n) {
	cout << "\ncac so chan trong mang la:\n";
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) {
			cout << a[i] << "\t";
		}
	}
}
#pragma endregion Bai3

#pragma region Bai4
void bai4(int a[], int n) {
	cout << "\nvi tri cac so am trong mang la:\n";
	for (int i = 0; i < n; i++) {
		if (a[i] < 0) {
			cout << "a["<<i<<"]\t";
		}
	}

}


#pragma endregion Bai4

#pragma region Bai5
void bai5(int a[], int n) {
	int soduongdau = duongdau(a, n);
	cout << "\ngia tri duong dau tien: " << soduongdau << endl;

}

int duongdau(int a[], int n) {
	for (int i = 0; i < n; i++) {
		if (a[i] > 0) {
			return a[i];
		}
	}
	return -1;
}

#pragma endregion Bai5

#pragma region Bai6
void bai6(int a[], int n) {
	int sochancuoi = chancuoi(a, n);
	cout << "\ngia so chan cuoi cung: " << sochancuoi << endl;
}

int chancuoi(int a[], int n) {
	for (int i = n-1; i >= 0; i--) {
		if (a[i] %2 == 0) {
			return a[i];
		}
	}
	return -1;
}
#pragma endregion Bai6

#pragma region Bai7

#pragma endregion Bai7

#pragma region Bai8

#pragma endregion Bai8

#pragma region Bai9

#pragma endregion Bai9