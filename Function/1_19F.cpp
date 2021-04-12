#include<iostream>
using namespace std;

//	//exercise 1
//void nhap(int &n);
//int Tinhtong(int &S,int n);
//void xuat(int S);
//
//int main() {
//
//	int n;
//	nhap(n);
//
//	int S = 0;
//	S = Tinhtong(S,n);
//	xuat(S);
//
//	system("pause");
//	return 0;
//}
//
//void nhap(int &n){
//	do {
//		cout << "nhap so n: ";
//		cin >> n;
//		if (n < 0) {
//			cout << "nhap sai moi nhap lai ";
//		}
//	} 	while (n < 0);
//}
//
//int Tinhtong(int &S,int n) {
//	for (int i = 1; i <= n; i++) {
//		S = S + i;
//	}
//	return S;
//}
//
//void xuat(int S) {
//	cout << "S = " << S << endl ;
//}


//	//exercise 2
//
//void nhap(int &n);
//void xuat(int s);
//void tinhs(int &s, int n);
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
//
//void nhap(int& n) {
//	do {
//		cout << "nhap so n: ";
//		cin >> n;
//		if (n < 0) {
//			cout << "nhap sai moi nhap lai ";
//		}
//	} while (n < 0);
//}
//
//void tinhs(int &s, int n){
//	for (int i = 1; i <= n; i++) {
//		s = s + i * i;
//	}
//}
//
//void xuat(int s) {
//	cout << "S = " << s << endl ;
//}


//	//exercise 3
//void nhap(int& n);
//void xuat(float s);
//void tinhs(float &s, int n);
//
//int main() {
//	int n;
//	nhap(n);
//
//	float s = 0.0f;
//	tinhs(s,n);
//	xuat(s);
//
//
//	system("pause");
//	return 0;
//}
//
//void nhap(int &n) {
//	do {
//		cout << "nhap so n: ";
//		cin >> n;
//		if (n < 0) {
//			cout << "nhap sai moi nhap lai ";
//		}
//	} while (n < 0);
//}
//
//void tinhs(float &s, int n) {
//	for (int i = 1; i <= n; i++) {
//		s = s + (1 / (float)i);
//	}
//}
//
//void xuat(float s) {
//	cout << "S = " << s << endl;
//}



//	//exercise 4
//void nhap(int& n);
//void tinhS(float& S, int n);
//void xuat(float s);
//int main() {
//	int n;
//	nhap(n);
//
//	float S = 0.0f;
//	tinhS(S,n);
//
//	xuat(S);
//	
//	system("pause");
//	return 0;
//}
//void nhap(int& n) {
//	cout << "nhap so n: ";
//	cin >> n;
//}
//
//void tinhS(float& S, int n) {
//	for (int i = 1; i <= n; i++) {
//		S = S + (1 / (float)(2 * i));
//	}
//}
//
//void xuat(float S) {
//	cout << S << endl;
//}


//	//exercise 5
//void nhap(int &n);
//void xuat(float S);
//void tinhS(float &S, int n);
//int main() {
//	int n;
//	nhap(n);
//	float S = 0.0f;
//	tinhS(S, n);
//	xuat(S);
//
//	system("pause");
//	return 0;
//}
//
//void nhap(int &n) {
//	cout << "nhap so n: ";
//	cin >> n;
//}
//
//void xuat(float S) {
//	cout << S << endl;
//}
//
//void tinhS(float& S, int n) {
//	for (int i = 0; i <= n; i++) {
//		S = S + (1 / (float)(2 * i + 1));
//	}
//}


//	//exercise 6
//void input(int& n);
//void tinhS(int n, float& S);
//void output(float S);
//int main(){
//	int n;
//	input(n);
//
//	float S = 0.0f;
//	tinhS(n, S);
//	output(S);
//
//	system("pause");
//	return 0;
//}
//
//void input(int& n) {
//	cout << "nhap so n :";
//	cin >> n;
//}
//void tinhS(int n, float& S) {
//	for (int i = 1; i <= n; i++) {
//		S = S + (1 / (float)(i * (i + 1)));
//	}
//}
//void output(float S) {
//	cout << "S = " << S << endl;
//}



//	//exercise 7
//void nhap(int &n);
//void xuat(float S);
//void tinhS(float &S,int n);
//
//int main() {
//	int n;
//	nhap(n);
//	float S = 0.0f;
//	tinhS(S,n);
//	xuat(S);
//
//
//	system("pause");
//	return 0;
//}
//
//void nhap(int &n) {
//	cout << "nhap so n: ";
//	cin >> n;
//}
//
//void xuat(float S) {
//	cout <<"S = " << S << endl;
//}
//
//void tinhS(float &S, int n) {
//	for (int i = 1; i <= n; i++) {
//		S = S + (i / (float)(i + 1));
//	}
//}



//	//exercise 8
//void nhap(int &n);
//void xuat(float S);
//void tinhS(float &S, int n);
//
//int main() {
//	int n;
//	nhap(n);
//	float S = 0.0f;
//	tinhS(S, n);
//	xuat(S);
//
//	system("pause");
//	return 0;
//}
//
//void nhap(int &n) {
//	cout << "nhap so n: ";
//	cin >> n;
//}
//
//void xuat(float S) {
//	cout << "S = " << S << endl;
//}
//
//void tinhS(float &S,int n) {
//	for (int i = 0; i <= n; i++) {
//		S = S + ((2 * i + 1) / (float)(2 * i + 2));
//	}
//}



//	//exercise 9
//void nhap(int& n);
//void xuat(float P);
//void tinhP(int n, float &P);
//int main(){
//	int n;
//	nhap(n);
//	float P = 1.0f;
//	tinhP(n,P);
//	xuat(P);
//	system("pause");
//	return 0;
//}
//
//void nhap(int &n) {
//	cout << "nhap so n: ";
//	cin >> n;
//}
//
//void xuat(float P) {
//	cout << "P = " << P << endl;
//}
//
//void tinhP(int n, float &P) {
//	for (int i = 1; i <= n; i++) {
//		P = P * i;
//	}
//}

//	//exercise 10
//
//void nhap(int &n,int &x);
//void tinhP(int n, int &P,int x);
//void xuat(int P,int n, int x);
//int main() {
//	int n, x;
//	nhap(n,x);
//	int P = 1;
//	tinhP(n, P, x);
//	xuat(P,n,x);
//
//	system("pause");
//	return 0;
//}
//void nhap(int& n,int &x) {
//	cout << "nhap so x: ";
//	cin >> x;
//	cout << "nhap so mu n: ";
//	cin >> n;
//}
//
//void tinhP(int n, int& P,int x) {
//	if (n == 0)
//		P = 1;
//	else
//	{
//		for (int i = 0; i < n; i++) {
//			P = P * x;
//		}
//
//	}
//}
//
//void xuat(int P,int n, int x) {
//	cout << x << " mu " << n << " = " << P << endl;
//}



//	//exercise 11
//void nhap(int &n);
//void xuat(int S);
//void tinh(int& S, int n);
//
//int main() {
//	int n;
//	nhap(n);
//	int S = 0;
//	tinh(S, n);
//	xuat(S);
//	system("pause");
//	return 0;
//}
//
//void nhap(int& n) {
//	cout << "nhap so n: ";
//	cin >> n;
//}
//
//void xuat(int S) {
//	cout <<"S = " <<S << endl;
//}
//
//void tinh(int& S, int n) {
//	for (int i = 1; i <= n; i++)
//	{
//		int P = 1;
//		for (int j = 1; j <= i; j++) {
//			P = P * j;
//		}
//		S = S + P;
//	}
//}



//	//exercise 12
//void nhap(int &n, int &x);
//void xuat(int s);
//int tinhS(int n, int x);
//
//int main() {
//	int n, x;
//	nhap(n, x);
//
//	int S= tinhS(n, x);
//	xuat(S);
//	system("pause");
//	return 0;
//}
//
//void nhap(int& n, int& x) {
//	cout << "nhap so x: ";
//	cin >> x;
//	cout << "nhap so n lon hon 0: ";
//	cin >> n;
//}
//
//void xuat(int s) {
//	cout <<"S = "<< s << endl;
//}
//
//int  tinhS(int n, int x) {
//	int s = 0;
//	for (int i = 1; i <= n; i++) {
//		int p = 1;
//		for (int j = 1; j <= i; j++) {
//			p = p * x;
//		}
//		s = s + p;
//	}
//	return s;
//}


//	//exercise 13
//void nhap(int &n, int &x);
//void xuat(int S);
//int tinhS(int n, int x);
//
//int main() {
//	int n, x;
//
//	nhap(n,x);
//	int S = 0;
//	S = tinhS(n,x);
//	xuat(S);
//
//	system("pause");
//	return 0;
//}
//
//void nhap(int& n, int& x) {
//	cout << "nhap so x: ";
//	cin >> x;
//	cout << "nhap so n lon hon 0: ";
//	cin >> n;
//}
//void xuat(int S) {
//	cout <<"S = "<< S << endl;
//}
//int tinhS(int n, int x) {
//	int S = 0;
//	for (int i = 1; i <= n; i++) {
//		int P = 1;
//		for (int j = 0; j < (2 * i); j++) {
//			P = P * x;
//		}
//		S = S + P;
//	}
//	return S;
//}

//	//exercise 14
//void nhap(int &n,int &x);
//void xuat(int S);
//int tinhS(int n, int x);
//
//int main() {
//	int x, n;
//	nhap(n,x);
//	int S = 0;
//	S = tinhS(n, x);
//	xuat(S);
//
//	system("pause");
//	return 0;
//}
//
//void nhap(int& n, int& x) {
//	cout << "nhap so x: ";
//	cin >> x;
//	cout << "nhap so n: ";
//	cin >> n;
//}
//
//void xuat(int S) {
//	cout << "S = " << S << endl;
//}
//
//int tinhS(int n, int x) {
//	int S = 0;
//	for (int i = 0; i <= n; i++) {
//		int P = 1;
//		for (int j = 0; j < (2 * i + 1); j++) {
//			P = P * x;
//		}
//		S = S + P;
//	}
//	return S;
//}



//	//exercise 15
//void nhap(int& n);
//void xuat(float S);
//float tinhS(int n);
//
//int main() {
//	int n;
//	nhap(n);
//	float S = 0;
//	S = tinhS(n);
//	xuat(S);
//	system("pause");
//	return 0;
//}
//
//void nhap(int& n) {
//	cout << "nhap so x: ";
//	cin >> n;
//}
//void xuat(float S) {
//	cout <<"S = "<< S << endl;
//}
//float tinhS(int n) {
//	float S = 0.0f;
//	for (int i = 1; i <= n; i++) {
//		int S2 = 0;
//		for (int j = 0; j <= i; j++) {
//			S2 = S2 + j;
//		}
//		S = S + 1 / (float)S2;
//	}
//	return S;
//}


//	//exercise 16
//void nhap(int& n, int& x);
//void xuat(float S);
//float tinhS(int n, int x);
//int main() {
//	int n, x;
//	nhap(n, x);
//	float s = 0.0f;
//	s = tinhS(n, x);
//	xuat(s);
//
//
//
//
//	system("pause");
//	return 0;
//}
//
//void nhap(int& n, int& x) {
//	cout << "nhap so x: ";
//	cin >> x;
//	cout << "nhap so n: ";
//	cin >> n;
//}
//
//void xuat(float S) {
//	cout << " S = " << S << endl;
//}
//
//float tinhS(int n, int x) {
//	float s = 0.0f;
//	int s2 = 0;
//	int p = 1;
//
//	for (int i = 1; i <= n; i++) {
//		s2 = s2 + i;
//		p = p * x;
//		s = s + (p / (float)s2);
//	}
//	return s;
//}


//	//exercise 17
//void nhap(int& n, int& x);
//float tinhS(int n, int x);
//void xuat(float S);
//int main() {
//	int n, x;
//	nhap(n, x);
//	float S = tinhS(n,x);
//	xuat(S);
//
//	system("pause");
//	return 0;
//}
//
//void nhap(int& n, int& x) {
//	cout << "nhap so x: ";
//	cin >> x;
//	cout << "nhap so n: ";
//	cin >> n;
//}
//float tinhS(int n, int x) {
//	float S = 0.0f;
//	int P = 1;
//	int P2 = 1;
//
//	for (int i = 1; i <= n; i++) {
//		P = P * x;
//		P2 = P2 * i;
//
//		S = S + P / (float)P2;
//	}
//	return S;
//}
//void xuat(float S) {
//	cout <<"S = "<< S << endl;
//}


//	//exercise 18
//void nhap(int& n, int& x);
//float tinhS(int n, int x);
//void xuat(float S);
//
//int main() {
//	int n, x;
//	nhap(n, x);
//	float s = tinhS(n,x);
//	xuat(s);
//	system("pause");
//	return 0;
//}
//
//void nhap(int& n, int& x) {
//	cout << "nhap so x: ";
//	cin >> x;
//	cout << "nhap so n: ";
//	cin >> n;
//}
//
//float tinhS(int n, int x) {
//
//	float s = 1.0f;
//	if (n == 0) {
//		s = 1.0f;
//	}
//	else {
//		int tuso = 1;
//		int mauso = 1;
//
//		for (int i = 1; i <= n; i++) {
//			tuso = tuso * x * x;
//			mauso = mauso * (2 * i) * (2 * i - 1);
//			s = s + tuso / (float)mauso;
//		}
//	
//	}
//	return s;
//}
//
//void xuat(float S) {
//	cout <<"S = "<< S << endl;
//}


//	//exercise 19
//void nhap(int& n, int& x);
//float tinhS(int n, int x);
//void xuat(float S);
//int main() {
//		int n, x;
//		nhap(n, x);
//		float s = tinhS(n, x);
//		xuat(s);
//	system("pause");
//	return 0;
//}
//
//void nhap(int& n, int& x) {
//	cout << "nhap so x: ";
//	cin >> x;
//	cout << "nhap so n : ";
//	cin >> n;
//}
//
//float tinhS(int n, int x) {
//	float s = 1.0f + x;
//	if (n == 0) {
//		s = 1.0f + x;
//	}
//	else {
//		int tuso = x;
//		int mauso = 1;
//		for (int i = 1; i <= n; i++) {
//
//			tuso = tuso * x * x;
//			mauso = mauso * (2 * i) * (2 * i + 1);
//			s = s + tuso / (float)mauso;
//		}
//	}
//	return s;
//
//}
//
//void xuat(float S) {
//	cout <<"S = "<< S << endl;
//}