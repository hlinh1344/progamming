#include<iostream>
using namespace std;

//	//exercise 1
//int main() {
//	int n;
//    cout << "nhap so n: ";
//	cin >> n;
//	int S = 0;
//	for (int i = 1; i <= n; i++) {
//		S = S + i;
//	}
//	cout << S << endl;
//	system("pause");
//	return 0;
//}


////	//exercise 2
//int main() {
//	int n;
//	cout << "nhap so n: ";
//	cin >> n;
//	int s = 0;
//	for (int i = 1; i <= n; i++) {
//		s = s + i*i;
//	}
//	cout << s << endl;
//	system("pause");
//	return 0;
//}

	

//	//exercise 3
//int main() {
//	int n;
//	cout << "nhap so n: ";
//	cin >> n;
//
//	float S = 0.0f;
//
//	for (int i = 1; i <= n; i++) {
//		S = S + (1 / (float)i);
//	}
//	cout << S << endl;
//	system("pause");
//	return 0;
//}
	


	
//	//exercise 4
//int main() {
//	int n;
//	cout << "nhap so n: ";
//	cin >> n;
//
//	float S = 0.0f;
//
//	for (int i = 1; i <= n; i++) {
//		S = S + (1 / (float)(2 * i));
//
//	}
//	cout << S << endl;
//	system("pause");
//	return 0;
//}

	
//	//exercise 5
//int main() {
//	int n;
//	cout << "nhap so n: ";
//	cin >> n;
//
//	float S = 0.0f;
//
//	for (int i = 0; i <= n; i++) {
//		S = S + (1 / (float)(2 * i + 1));
//	}
//	cout << S << endl;
//	system("pause");
//	return 0;
//}

	
//	//exercise 6
//	int main(){
//	int n;
//	cout << "nhap so n: ";
//	cin >> n;
//
//	float S = 0.0f;
//
//	for (int i = 1; i <= n; i++) {
//		S = S + (1 / (float)(i * (i + 1))) ;
//	}
//	cout << S << endl;
//	system("pause");
//	return 0;
//}


	
//	//exercise 7
//int main() {
//	int n;
//	cout << "nhap so n: ";
//	cin >> n;
//
//	float S = 0.0f;
//
//	for (int i = 1; i <= n; i++) {
//		S = S + (i / (float)(i + 1));
//	}
//	cout << S << endl;
//	system("pause");
//	return 0;
//}
	

	
//	//exercise 8
//int main() {
//	int n;
//	cout << "nhap so n: ";
//	cin >> n;
//
//	float S = 0.0f;
//
//	for (int i = 0; i <= n; i++) {
//		S = S + ((2 * i + 1) / (float)(2 * i + 2));
//	}
//	cout << S << endl;
//	system("pause");
//	return 0;
//}


//	//exercise 9
//int main(){
//	int n;
//	cout << "nhap so n: ";
//	cin >> n;
//	float P = 1.0f;
//
//	for (int i = 1; i <= n; i++) {
//		P = P * i;
//	}
//	cout << P << endl;
//	system("pause");
//	return 0;
//}
	

	
//	//exercise 10
//int main() {
//	int n, x;
//	cout << "nhap so x: ";
//	cin >> x;
//	cout << "nhap so mu n: ";
//	cin >> n;
//
//	int P = 1;
//	if (n == 0)
//		P = 1;
//	else
//	{
//		for (int i = 0; i < n; i++) {
//			P = P * x;
//		}
//
//	}
//	cout << x << " mu " << n << " = " << P << endl;
//	system("pause");
//	return 0;
//}


	
//	//exercise 11
//int main() {
//	int n;
//	cout << "nhap so n: ";
//	cin >> n;
//	int S = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		int P = 1;
//		for (int j = 1; j <= i; j++) {
//			P = P * j;
//		}
//		S = S + P;
//	}
//	cout << S << endl;
//	system("pause");
//	return 0;
//}


	
//	//exercise 12
//int main() {
//	int n, x;
//	cout << "nhap so x: ";
//	cin >> x;
//	cout << "nhap so n lon hon 0: ";
//	cin >> n;
//
//	int s = 0;
//	for (int i = 1; i <= n; i++) {
//		int p = 1;
//		for (int j = 1; j <= i; j++) {
//			p = p * x;
//		}
//		s = s + p;
//
//	}
//	cout << s << endl;
//	system("pause");
//	return 0;
//}


//	//exercise 13
//int main() {
//	int n, x;
//	cout << "nhap so x: ";
//	cin >> x;
//	cout << "nhap so n lon hon 0: ";
//	cin >> n;
//	int S = 0;
//
//	for (int i = 1; i <= n; i++) {
//		int P = 1;
//		for (int j = 0; j < (2 * i); j++) {
//			P = P * x;
//		}
//		S = S + P;
//	}
//	cout << S << endl;
//	system("pause");
//	return 0;
//}

//	//exercise 14
//int main() {
//	int x, n;
//	cout << "nhap so x: ";
//	cin >> x;
//	cout << "nhap so n: ";
//	cin >> n;
//	int S = 0;
//
//	for (int i = 0; i <= n; i++) {
//		int P = 1;
//		for (int j = 0; j < (2 * i + 1); j++) {
//			P = P * x;
//		}
//		S = S + P;
//	}
//	cout << S << endl;
//	system("pause");
//	return 0;
//}


//	//exercise 15
//int main() {
//	int n;
//	cout << "nhap so x: ";
//	cin >> n;
//	float S = 0.0f;
//
//	for (int i = 1; i <= n; i++) {
//		int S2 = 0;
//		for (int j = 0; j <= i; j++) {
//			S2 = S2 + j;
//		}
//		S = S + 1/(float)S2;
//	}
//	cout << S << endl;
//	system("pause");
//	return 0;
//}


//	//exercise 16
//int main() {
//	int n, x;
//	cout << "nhap so x: ";
//	cin >> x;
//	cout << "nhap so n: ";
//	cin >> n;
//	float s = 0.0f;
//
//	for (int i = 1; i <= n; i++) {
//		int s2 = 0;
//		float temp = 0.0f;
//		int P = 1;
//		for (int j = 1; j <= i; j++) {
//			s2 = s2 + j;
//			P = P * x;
//			temp = P / (float)s2;
//		}
//		s = s + temp;
//	}
//	cout << s << endl;
//	system("pause");
//	return 0;
//}





