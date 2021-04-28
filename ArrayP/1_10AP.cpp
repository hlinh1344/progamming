#include <iostream>
using namespace std;
#include "1_10AP.h"

int main() {
    
    int* a = new int[1];
    int n;
    int select;
    bool willExit = false;
    do {

        system("cls");
        cout << "1.  Nhap mang mot chieu.";
        cout << "\n2.  Xuat mang.";
        cout << "\n3.  Xuat cac so chan trong mang.";
        cout << "\n4.  Tim vi tri cac so le trong mang.";
        cout << "\n5.  Tim gia tri duong dau tien.";
        cout << "\n6.  Tim gia tri chan cuoi cung.";
        cout << "\n7.  Tim vi tri nho nhat trong mang.";
        cout << "\n8.  Tim so nguyen to dau tien trong mang.";
        cout << "\n9.  Tim so nguyen to lon nhat trong mang.";
        cout << "\n10. Tim gia tri xa mot so X nhat";
        cout << "\n0.  Thoat";
        cout << "\n\nVui long chon thao tac muon thuc hien : ";
        cin >> select;
        switch (select) {
        case 0:
            willExit = true;
            break;
        case 1:
            bai1(a, n);
            break;
        case 2:
            bai2(a, n);
            break;
        case 3:
            bai3(a, n);
            break;
        case 4:
            bai4(a, n);
            break;
        default:
            break;
           
        }
    }     while (!willExit);
    cout << "\n";
    system("pause");
    return 0;
}

void bai1(int* a, int &n) {
    cout << "\nNhap so nguyen n : ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> *a;
        a++;
    }
}


void bai2(int* a, int n) {
    cout << "\n";
    for (int i = 0; i < n; i++) {
        cout << *a << "\t";
        a++;
    }
    cout << "\n";
    system("pause");
}

void bai3(int *a, int n) {
    cout << "\ncac so chan trong mang la:\n";
    for (int i = 0; i < n; i++) {
        if (*a % 2 == 0) {
            cout << *a << "\t";
        }
        a++;
    }
    cout << "\n";
    system("pause");
}

void bai4(int *a, int n) {
    cout << "\nvi tri cac so am trong mang la:\n";
    for (int i = 0; i < n; i++) {
        if (*a < 0) {
            cout << "a[" << i << "]\t";
        }
        a++;
    }
    cout << "\n";
    system("pause");
}


void bai5(int *a, int n) {
    int soduongdau = duongdau(a, n);
    cout << "\ngia tri duong dau tien: " << soduongdau << endl;
    cout << "\n";
    system("pause");
}

int duongdau(int *a, int n) {
    for (int i = 0; i < n; i++) {
        if (*a > 0) {
            return *a;
        }
        a++;
    }
    return -1;
}