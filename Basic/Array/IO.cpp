#include <iostream>
#include "IO.h"

using namespace std;

void nhapmang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
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
