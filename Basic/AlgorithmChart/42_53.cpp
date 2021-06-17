#include<iostream>
using namespace std;


//	//exercise 42
//int main() {
//	int n;
//	cout << "nhap so nguyen duong n: ";
//	do {
//		cin >> n;
//		if (n <= 0) {
//			cout << "nhap sai, moi nhap lai: ";
//		}
//	} while (n <= 0);
//	int S = 0;
//
//	for (int i = 1; S < n; i++) {
//		S = S + i;
//		if (S >= n) {
//			cout << "S = " << S -i << " < "<< n<<endl;
//			cout << "k = " << i - 1 << endl;
//		}
//	}
//	system("pause");
//	return 0;
//}


//	//exercise 43
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
//	int S = 0;
//
//	for (int i = 0; P > 0; i++) {
//		S = S + 1;
//		P = P / 10;
//	}
//
//	cout << "so "<< n << " co " << S << " chu so"<<endl;
//	system("pause");
//	return 0;
//}


//	//exercise 44
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
//	int S = 0;
//
//	for (int i = 0; P > 0; i++) {
//		S = S + (P % 10);
//		P = P / 10;
//	}
//
//	cout << n << " co tong cac chu so = " << S << endl;
//	system("pause");
//	return 0;
//}


//	//exercise 45
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
//	int P2 = 1;
//	for (int i = 1; P > 0; i++) {
//		P2 = P2 * (P % 10);
//		P = P / 10;
//	}
//	cout << n << " co tich cac chu so = " << P2 << endl;
//	system("pause");
//	return 0;
//}


//	//exercise 46
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
//	int P = n;
//	int S = 0;
//
//	for (int i = 0; P > 0; i++) {
//		if ((P % 10) % 2 == 1) {
//			S++;
//		}
//		P = P / 10;
//	}
//
//	cout << n << " co " << S << " chu so le" << endl;
//	system("pause");
//	return 0;
//}


//	//exercise 47
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
//	int S = 0;
//
//	for (int i = 1; P > 0; i++) {
//		if ((P % 10) % 2 == 0) {
//			S = S + (P % 10);
//		}
//		P = P / 10;
//	}
//
//	cout << n << " co tong cac chu so chan la " << S << endl;
//	system("pause");
//	return 0;
//}


//	//exercise 48
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
//	int P2 = 1;
//
//	for (int i = 1; P > 0; i++) {
//		if ((P % 10) % 2 == 1) {
//			P2 = P2 * (P % 10);
//		}
//		P = P / 10;
//	}
//
//	cout << n << " co tich cac chu so le la " << P2 << endl;
//	system("pause");
//	return 0;
//}


//	//exercise 49
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
//	for (int i = 1; P>9; i++) {
//		P = P / 10;
//	}
//	cout << n << " co chu so dau tien la " << P << endl;
//	system("pause");
//	return 0;
//}


//	//exercise 50
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
//		cout << n << " dao nguoc lai la so " << n << endl;
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
//		cout << n << " dao nguoc lai la so " << P2 << endl;
//	}
//
//	
//	system("pause");
//	return 0;
//}


//	//exercise 51
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
//	int nMax = (P % 10);
//	for (int i = 1; P > 0; i++) {
//		P = P / 10;
//		if (nMax < (P % 10)) {
//			nMax = (P % 10);
//		}
//
//	}
//
//	cout << n << " co so lon nhat la " << nMax << endl;
//	system("pause");
//	return 0;
//}


//	//exercise 52
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
//	int nMin = (P % 10);
//	for (int i = 1; P > 9; i++) {
//		P = P / 10;
//		if (nMin > (P % 10)) {
//			nMin = (P % 10);
//		}
//	}
//
//	cout << n << " co so nho nhat la " << nMin << endl;
//	system("pause");
//	return 0;
//}


//	//exercise 53
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
//	int nMax = (P % 10);
//	for (int i = 1; P > 0; i++) {
//		P = P / 10;
//		if (nMax < (P % 10)) {
//			nMax = (P % 10);
//		}
//
//	}
//
//	int S = 0;
//	for (int j = 1; P2 > 0; j++) {
//		if ((P2 % 10) == nMax) {
//			S = S + 1;
//		}
//		P2 = P2 / 10;
//	}
//
//	cout << n << " co "<< S << " so lon nhat la " << nMax << endl;
//	system("pause");
//	return 0;
//}



