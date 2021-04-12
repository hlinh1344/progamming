#include<iostream>
using namespace std;


//	//exercise 54
//int main() {
//	int n;
//	cout << "nhap so nguyen duong n: ";
//	do {
//		cin >> n;
//		if (n <= 0) {
//			cout << "nhap sai, moi nhap lai: ";
//		}
//	} while (n <= 0);
//	int P = n;
//	int P2 = n;
//	int nMin = (P % 10);
//	for (int i = 1; P > 9; i++) {
//		P = P / 10;
//		if (nMin > (P % 10)) {
//			nMin = (P % 10);
//		}
//
//	}
//
//	int S = 0;
//	for (int j = 1; P2 > 9; j++) {
//		if ((P2 % 10) == nMin) {
//			S = S + 1;
//		}
//		P2 = P2 / 10;
//	}
//
//	cout << n << " co " << S << " so nho nhat la " << nMin << endl;
//	system("pause");
//	return 0;
//}


//	//exercise 55
//int main() {
//	int n;
//	cout << "nhap so nguyen duong n: ";
//	do {
//		cin >> n;
//		if (n <= 0) {
//			cout << "nhap sai, moi nhap lai: ";
//		}
//	} while (n <= 0);
//	int P = n;
//	
//
//	for (int i = 1; P>9; i++) {
//		P = P / 10;
//	}
//	cout << n << " co chu so dau tien la " << P << endl;
//
//	int P2 = n;
//	int S = 0;
//
//	for (int j = 1; P2 > 0; j++) {
//		if ((P2 % 10) == P) {
//			S = S + 1;
//		}
//		P2 = P2 / 10;
//	}
//
//	cout << n << " co "<< S <<" chu so " << P << endl;
//	system("pause");
//	return 0;
//}


//	//exercise 56
//int main() {
//	int n;
//	cout << "nhap so nguyen duong n: ";
//	do {
//		cin >> n;
//		if (n <= 0) {
//			cout << "nhap sai, moi nhap lai: ";
//		}
//	} while (n <= 0);
//	int P = n;
//	int le = 0;
//
//	for (int i = 1; P> 0; i++) {
//		if ((P % 10) % 2 == 0) {
//			cout << "so nguyen duong "<< n <<" khong toan chu so le" << endl;
//			break;
//		}
//		P = P / 10;
//		if (P == 0) {
//			cout << "so nguyen duong " << n << " toan chu so le" << endl;
//		}
//	}
//	system("pause");
//	return 0;
//}


//	//exercise 57 (58)
//int main() {
//	int n;
//	cout << "nhap so nguyen duong n: ";
//	do {
//		cin >> n;
//		if (n <= 0) {
//			cout << "nhap sai, moi nhap lai: ";
//		}
//	} while (n <= 0);
//	int P = n;
//	int le = 0;
//
//	for (int i = 1;  P > 0; i++) {
//		if ((P % 10) % 2 != 0) {
//			cout << "so nguyen duong " << n << " khong toan chu so chan" << endl;
//			break;
//		}
//
//		P = P / 10;
//
//		if (P == 0) {
//			cout << "so nguyen duong " << n << " toan chu so chan" << endl;
//		}
//
//	}
//	system("pause");
//	return 0;
//}


//	//exercise 59
//int main() {
//	int n;
//	cout << "nhap so nguyen duong n: ";
//	do {
//		cin >> n;
//		if (n <= 0) {
//			cout << "nhap sai, moi nhap lai: ";
//		}
//	} while (n <= 0);
//
//	if (n < 10) {
//		cout << n << " khong phai la so doi xung " << endl;
//	}
//	else
//	{
//		int P = n;
//		int P2 = (P % 10);
//
//		for (int i = 1; P > 9; i++) {
//			P = P / 10;
//			P2 = P2 * 10 + (P % 10);
//		}
//
//		if (P2 == n) {
//			cout << P2 << " la so doi xung" << endl;
//		}
//		else {
//			cout << n << " khong phai la so doi xung" << endl;
//		}
//	}
//	system("pause");
//	return 0;
//}


//	//exercise 60
//int main() {
//	int n;
//	cout << "nhap so nguyen duong n: ";
//	do {
//		cin >> n;
//		if (n <= 0) {
//			cout << "nhap sai, moi nhap lai: ";
//		}
//	} while (n <= 0);
//
//	bool tangdan = 1;
//	if (n < 10) {
//		tangdan = 0;
//	}
//	else {
//		int P = n;
//		
//		for (int i = 1; P > 9; i++) {
//
//			int temp = (P % 10);
//			P = P / 10;
//			if (temp <= (P % 10)) {
//				tangdan = 0;
//				break;
//			}
//		
//		}
//	}
//
//	if (tangdan) {
//		cout << n << " tang dan tu trai sang phai " << endl;
//	}
//	else {
//		cout << n << " khong tang dan tu trai sang phai " << endl;
//	}
//
//
//	system("pause");
//	return 0;
//}


//	//exercise 61
//int main() {
//	int n;
//	cout << "nhap so nguyen duong n: ";
//	do {
//		cin >> n;
//		if (n <= 0) {
//			cout << "nhap sai, moi nhap lai: ";
//		}
//	} while (n <= 0);
//
//	bool giamdan = 1;
//	if (n < 10) {
//		giamdan = 0;
//	}
//	else {
//		int P = n;
//
//		for (int i = 1; P > 9; i++) {
//
//			int temp = (P % 10);
//			P = P / 10;
//			if (temp >= (P % 10)) {
//				giamdan = 0;
//				break;
//			}
//
//		}
//	}
//
//	if (giamdan) {
//		cout << n << " giam dan tu trai sang phai " << endl;
//	}
//	else {
//		cout << n << " khong giam dan tu trai sang phai " << endl;
//	}
//
//
//	system("pause");
//	return 0;
//}


//	//exercise 62
//int main() {
//
//	int a, b;
//	cout << "nhap so thu nhat : ";
//	cin >> a;
//	cout << "nhap so thu hai : ";
//	cin >> b;
//	
//	if (a < b) {
//		int temp = a;
//		a = b;
//		b = temp;
//	}
//
//	int uocchunglonnhat = 1;
//	if (a % b == 0 ) {
//		uocchunglonnhat = b;
//	}
//	else {
//		for (int i = (b / 2); i > 1; i--) {
//			if ((a % i == 0) && (b % i == 0)) {
//				uocchunglonnhat = i;
//				break;
//			}
//
//		}
//	}
//
//	cout << "uoc chung lon nhat cua " << a << " va " << b << " la : " << uocchunglonnhat << endl;
//	cout << "\n";
//	system("pause");
//	return 0;
//}


//	//exercise 63
//int main() {
//
//	int a, b;
//	cout << "nhap so thu nhat : ";
//	cin >> a;
//	cout << "nhap so thu hai : ";
//	cin >> b;
//
//	if (a < b) {
//		int temp = a;
//		a = b;
//		b = temp;
//	}
//
//	int boichungnhonhat = a*b;
//	if (a % b == 0) {
//		boichungnhonhat = a;
//	}
//	else {
//		for (int i = a; i < (a*b); i++) {
//			if ((i % a == 0) && (i % b == 0)) {
//				boichungnhonhat = i;
//				break;
//			}
//
//		}
//	}
//
//	cout << "boi chung nho nhat cua " << a << " va " << b << " la : " << boichungnhonhat << endl;
//	cout << "\n";
//	system("pause");
//	return 0;
//}


//	//exercise 64
//int main() {
//	cout << "\t ax + b = 0 \n";
//	
//	float a;
//	cout << "Nhap he so a : ";
//	do {
//		cin >> a;
//		if (a == 0) {
//			cout << "nhap sai, moi nhap lai: ";
//		}
//	} while (a == 0);
//
//	float b;
//	cout << "Nhap he so b : ";
//	cin >> b;
//
//	float x;
//	x = ((-b) / a);
//	cout << "x = " << x << endl;
//	system("pause");
//	return 0;
//}


//	//exercise 65
//int main() {
//	cout << "\t ax^2 + bx + c = 0 \n";
//
//	float a;
//	cout << "Nhap he so a : ";
//	do {
//		cin >> a;
//		if (a == 0) {
//			cout << "nhap sai, moi nhap lai: ";
//		}
//	} while (a == 0);
//
//	float b;
//	cout << "Nhap he so b : ";
//	cin >> b;
//
//	float c;
//	cout << "Nhap he so c : ";
//	cin >> c;
//
//	float x1,x2;
//
//	if (b == 0) {
//		x1 = sqrt(-c /(a));
//		x2 = - sqrt(-c /(a));
//		cout << "phuong trinh co 2 nghiem:" << endl;
//		cout << "x1 = " << x1 << endl;
//		cout << "x2 = " << x2 << endl;
//	}
//	else {
//		float denta = ((b * b) - (4 * a * c));
//		if (denta < 0) {
//			cout << "phuong trinh vo nghiem" << endl;
//		}
//		else if (denta == 0) {
//			x1 = (-b / 2 * a);
//			x2 = x1;
//			cout << "phuong trinh co nghiem kep: " << endl;
//			cout << "x1 = x2 = " << x1 << endl;
//		}
//		else {
//			x1 = (-b + sqrt(denta)) / (2 * a);
//			x2 = (-b - sqrt(denta)) / (2 * a);
//			cout << "phuong trinh co 2 nghiem:" << endl;
//			cout << "x1 = " << x1 << endl;
//			cout << "x2 = " << x2 << endl;
//		}
//
//	}
//
//
//	system("pause");
//	return 0;
//}


//	//exercise 66
//int main() {
//	cout << "\t ax^4 + bx^2 + c = 0 \n";
//
//	float a;
//	cout << "Nhap he so a : ";
//	do {
//		cin >> a;
//		if (a == 0) {
//			cout << "nhap sai, moi nhap lai: ";
//		}
//	} while (a == 0);
//
//	float b;
//	cout << "Nhap he so b : ";
//	cin >> b;
//
//	float c;
//	cout << "Nhap he so c : ";
//	cin >> c;
//
//	bool vonghiem = 0;
//	float t1,t2,x1,x2,x3,x4;
//
//	if (b == 0) {
//		t1 = sqrt(-c /(a));
//		t2 = - sqrt(-c /(a));
//	}
//	else {
//		float denta = ((b * b) - (4 * a * c));
//		if (denta < 0) {
//			vonghiem = 1;
//		}
//		else if (denta == 0) {
//			t1 = (-b / 2 * a);
//			t2 = t1;
//		}
//		else {
//			t1 = (-b + sqrt(denta)) / (2 * a);
//			t2 = (-b - sqrt(denta)) / (2 * a);
//		}
//
//	}
//
//	if (vonghiem) {
//		cout << "phuong trinh vo nghiem" << endl;
//	}
//	else {
//
//		if ((t1 >= 0) && (t2 >= 0)) {
//			cout << "phuong trinh co 4 nghiem :" << endl;
//			cout << "x1 = " << sqrt(t1) << endl;
//			cout << "x2 = " << -sqrt(t1) << endl;
//			cout << "x3 = " << sqrt(t2) << endl;
//			cout << "x4 = " << -sqrt(t2) << endl;
//		}
//		else if ((t1 >= 0) && (t2 < 0)) {
//			cout << "phuong trinh co 2 nghiem :" << endl;
//			cout << "x1 = " << sqrt(t1) << endl;
//			cout << "x2 = " << -sqrt(t1) << endl;
//		}
//		else if ((t1 < 0) && (t2 >= 0)) {
//			cout << "phuong trinh co 2 nghiem :" << endl;
//			cout << "x1 = " << sqrt(t2) << endl;
//			cout << "x2 = " << -sqrt(t2) << endl;
//		}
//		else {
//			cout << "phuong trinh vo nghiem :" << endl;
//		}
//
//	}
//
//
//	system("pause");
//	return 0;
//}


