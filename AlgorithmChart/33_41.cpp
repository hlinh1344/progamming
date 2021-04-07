#include<iostream>
using namespace std;


//	//exercise 33
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
//	float S = 0.0f;
//	for (int i = 0; i < n; i++) {
//		S = sqrt(2+S);
//	}
//	cout << "S = "<< S<<endl;
//	system("pause");
//	return 0;
//}


//	//exercise 34
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
//	float S = 0.0f;
//	for (int i = 1; i <= n; i++) {
//		S = sqrt(i+ S);
//	}
//	cout << "S = " << S << endl;
//	system("pause");
//	return 0;
//}


//	//exercise 35
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
//	float S = 0.0f;
//	for (int i = n; i >= 1; i--) {
//		S = sqrt(i + S);
//	}
//	cout << "S = " << S << endl;
//	system("pause");
//	return 0;
//}


//	//exercise 36
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
//	float S = 0.0f;
//	for (int i = 1; i <= n; i++) {
//		int P = 1;
//		for (int j = 1; j <= i; j++)
//		{
//			P = P * j;
//		}
//		S = sqrt(P + S);
//	}
//	cout << "S = " << S << endl;
//	system("pause");
//	return 0;
//}


//	//exercise 37
//int main() {
//	int n;
//	cout << "nhap so nguyen duong n: ";
//	do {
//		cin >> n;
//		if (n <= 0) {
//			cout << "nhap sai, moi nhap lai: ";
//		}
//	} while (n <= 0);
//	float S = 0.0f;
//	if ( n == 1) {
//		cout << "S = " << S << endl;
//	}
//	else {
//
//		for (int i = 2; i <= n; i++) {
//			float temp1 = (float)(i) + S;
//			float temp2 = 1 / (float)i;
//			S = pow(temp1 , temp2);
//		}
//		cout << "S = " << S << endl;
//	}
//
//	system("pause");
//	return 0;
//}


//	//exercise 38
//int main() {
//	int n;
//	cout << "nhap so nguyen duong n: ";
//	do {
//		cin >> n;
//		if (n <= 0) {
//			cout << "nhap sai, moi nhap lai: ";
//		}
//	} while (n <= 0);
//	float S = 0.0f;
//
//	for (int i = 2; i <= n+1; i++) {
//		float temp1 = (float)(i-1) + S;
//		float temp2 = 1 / (float)i;
//		S = pow(temp1, temp2);
//	}
//	cout << "S = " << S << endl;
//
//	system("pause");
//	return 0;
//}


//	//exercise 39
//int main() {
//	int n;
//	cout << "nhap so nguyen duong n: ";
//	do {
//		cin >> n;
//		if (n <= 0) {
//			cout << "nhap sai, moi nhap lai: ";
//		}
//	} while (n <= 0);
//	float S = 0.0f;
//
//	for (int i = 2; i <= n + 1; i++) {
//		float  P = 1.0f;
//		for (int j = 1; j <= i - 1; j++) {
//			P = P * j;
//		}
//		S = pow(P+S, 1 / (float)i);
//
//	}
//	cout << "S = " << S << endl;
//
//	system("pause");
//	return 0;
//}


//	//exercise 40
//int main() {
//	int x;
//	cout << "nhap so x: ";
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
//	float S = 0.0f;
//
//	for (int i = 1; i <= n; i++) {
//		float  P = 1.0f;
//		for (int j = 1; j <= i; j++) {
//			P = P * x;
//		}
//		S = sqrt(P+S);
//
//	}
//	cout << "S = " << S << endl;
//
//	system("pause");
//	return 0;
//}


//	//exercise 41
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
//	float S = 1.0f;
//	for (int i = 0; i < n; i++) {
//		S = 1 / (1.0 + S);
//	}
//
//	cout << "S = " << S << endl;
//
//	system("pause");
//	return 0;
//}