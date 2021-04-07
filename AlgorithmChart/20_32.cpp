#include<iostream>
using namespace std;

//	//exercise 20
//int main() {
//	int n;
//	cout << "nhap so nguyen duong n: ";
//	do {
//		cin >> n;
//		if (n <= 0) {
//			cout << "nhap sai, moi nhap lai: ";
//		}
//	} 	while (n <= 0);
//	cout << "Cac uoc so cua " << n << " la:" << endl;
//	for (int i = 2; i <= (int)(n/2); i++) {
//		if (n % i == 0) {
//			cout << i <<"\t";
//		}
//	}
//	cout << n << endl ;
//	system("pause");
//	return 0;
//}

//	//exercise 21
//int main() {
//int n;
//cout << "nhap so nguyen duong n: ";
//do {
//	cin >> n;
//	if (n <= 0) {
//		cout << "nhap sai, moi nhap lai: ";
//	}
//} 	while (n <= 0);
//cout << "Tong cac uoc so cua " << n << " la: " ;
//int S = n;
//
//for (int i = 1; i <= (n / 2); i++) {
//	if (n % i == 0)
//	{
//		S = S + i;
//	}
//}
//
//cout << S << endl;
//	system("pause");
//	return 0;
//}


//	//exercise 22
//int main() {
//	int n;
//	cout << "nhap so nguyen duong n: ";
//	do {
//		cin >> n;
//		if (n <= 0) {
//			cout << "nhap sai, moi nhap lai: ";
//		}
//	} while (n <= 0);
//	cout << "Tich cac uoc so cua " << n << " la: ";
//	int P = n;
//
//	for (int i = 1; i <= (n / 2); i++) {
//		if (n % i == 0)
//		{
//			P = P * i;
//		}
//	}
//
//	cout << P << endl;
//
//
//	system("pause");
//	return 0;
//}


//	//exercise 23
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
//	int S = 1;
//	for (int i = 1; i <= (n / 2); i++) {
//		if (n % i == 0) {
//			cout << i << "\t";
//			S = S + 1;
//		}
//	}
//	cout << n << endl;
//	cout << "\n";
//	cout << "So luong uoc so cua " << n << " la: " << S << endl;
//	system("pause");
//	return 0;
//}


//	//exercise 24
//int main() {
//	int n;
//	cout << "nhap so nguyen duong n: ";
//	do {
//		cin >> n;
//		if (n <= 0) {
//			cout << "nhap sai, moi nhap lai: ";
//		}
//	} while (n <= 0);
//	cout << "Cac uoc so le cua " << n << " la: \n";
//
//	for (int i = 1; i <= (n / 2); i++) {
//		if ((n % i == 0) && (i % 2 != 0)){
//				cout << i << "\t\t";
//		}
//	}
//
//	if (n % 2 != 0) {
//		cout << n << endl;
//	}
//	cout << "\n";
//	system("pause");
//	return 0;
//}


//	//exercise 25
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
//	int S = 0;
//	for (int i = 1; i <= (n / 2); i++) {
//		if ((n % i == 0) && (i % 2 == 0)){
//				cout << i << "\t";
//				S = S + i;
//		}
//	}
//
//	if (n % 2 == 0) {
//		cout << n;
//		S = S + n;
//	}
//	cout << "\n";
//	cout << "Tong uoc so chan cua " << n << " la : " << S <<endl;
//	cout << "\n";
//	system("pause");
//	return 0;
//}


//	//exercise 26
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
//	int P = 1;
//	for (int i = 1; i <= (n / 2); i++) {
//		if ((n % i == 0) && (i % 2 != 0)) {
//			cout << i << "\t";
//			P = P * i;
//		}
//	}
//
//	if (n % 2 != 0) {
//		cout << n;
//		P = P * n;
//	}
//	cout << "\n";
//	cout << "Tich uoc so le cua " << n << " la : " << P << endl;
//	cout << "\n";
//	system("pause");
//	return 0;
//}


//	//exercise 27
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
//	int S = 0;
//	for (int i = 2; i <= (n / 2); i++) {
//		if ((n % i == 0) && (i % 2 == 0)) {
//			cout << i << "\t";
//			S = S + 1;
//		}
//	}
// if (n % 2 ==0){
//		cout << n << endl;
//		S = S + 1;
// }
//	cout << "\n";
//	cout << "So luong uoc so chan cua " << n << " la: " << S << endl;
//	system("pause");
//	return 0;
//}



//	//exercise 28
//int main() {
//	int n;
//	cout << "nhap so nguyen duong n: ";
//	do {
//		cin >> n;
//		if (n <= 0) {
//			cout << "nhap sai, moi nhap lai: ";
//		}
//	} 	while (n <= 0);
//
//	int S = 0;
//
//	for (int i = 1; i <= (n / 2); i++) {
//		if (n % i == 0)
//		{
//			cout << i << "\t";
//			S = S + i;
//		}
//	}
//	cout << "\n";
//	cout << "Tong cac uoc so nho hon "<<n<< " cua " << n << " la: ";
//	cout << S << endl;
//	system("pause");
//	return 0;
//}


//	//exercise 29
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
//	cout << "uoc so le lon nhat cua " << n << " la " ;
//	if (n % 2 != 0) {
//		cout << n << endl; 
//	}
//	else {
//		for (int i = (int)(n / 2); i >= 1; i--) {
//			if ((n % i == 0) && (i % 2 != 0)){
//				cout << i << endl;
//				break;
//			}
//		}
//	}
//	cout << "\n";
//	system("pause");
//	return 0;
//}



//	//exercise 30
//int main() {
//	bool isPerfectNumber = 1;
//	int n;
//	cout << "nhap so nguyen duong n: ";
//	do {
//		cin >> n;
//		if (n <= 0) {
//			cout << "nhap sai, moi nhap lai: ";
//		}
//	} 	while (n <= 0);
//
//	int S = 0;
//
//	for (int i = 1; i <= (n / 2); i++) {
//		if (n % i == 0)
//		{
//			S = S + i;
//		}
//	}
//	cout << "\n";
//	if (S == n) {
//		isPerfectNumber = 1;
//	}
//	else
//	{
//		isPerfectNumber = 0;
//	}
//
//	if (isPerfectNumber == 1) {
//		cout << n << " la so hoan thien" << endl;
//	}
//	else
//	{
//		cout << n << " khong phai la so hoan thien" << endl;
//	}
//	system("pause");
//	return 0;
//}



//	//exercise 31
//int main() {
//	int n;
//	cout << "nhap so nguyen duong n: ";
//	do {
//		cin >> n;
//		if (n < 0) {
//			cout << "nhap sai, moi nhap lai: ";
//		}
//	} while (n <= 0);
//
//	bool isPrimeNumber = 1;
//
//	if ((n == 2) || (n == 3)) {
//		isPrimeNumber = 1;
//	}
//	else if((n == 1) || (n == 0 ) || (n % 2 == 0 ))
//	{
//		isPrimeNumber = 0;
//	}
//	else
//	{
//		for (int i = 2; i <= int (n/2); i++) {
//			if (n % i == 0) {
//				isPrimeNumber = 0;
//				break;
//			}
//			
//		}
//	}
//
//	if (isPrimeNumber == 1) {
//		cout << n << " la so nguyen to" << endl;
//	}
//	else
//	{
//		cout << n << " khong phai la so nguyen to" << endl;
//	}
//	system("pause");
//	return 0;
//}



//	//exercise 32
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
//	bool isSquareNumber = 0;
//	if (n == 1) {
//		isSquareNumber = 1;
//	}
//	else
//	{
//		for (int i = 1; i <= (int)(n / 2); i++) {
//			if (i * i == n) {
//				isSquareNumber = 1;
//				break;
//			}
//		}
//
//
//	}
//	if (isSquareNumber == 1) {
//		cout << n << " la so chinh phuong" << endl;
//	}
//	else
//	{
//		cout << n << " khong phai la so chinh phuong" << endl;
//	}
//
//	system("pause");
//	return 0;
//}