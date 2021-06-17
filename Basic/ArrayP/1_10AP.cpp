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
        case 5:
            bai5(a, n);
            break;
        case 6:
            bai6(a, n);
        case 7:
            bai7(a, n);
        case 8:
            bai8(a, n);
        case 9:
            bai9(a, n);
        case 10:
            bai10(a, n);
            willExit = true;
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

void bai6(int *a, int n) {
    int sochancuoi = chancuoi(a, n);
    cout << "\ngia so chan cuoi cung: " << sochancuoi << endl;
}

int chancuoi(int *a, int n) {
    a = a + n - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (*a % 2 == 0) {
            return *a;
        }
        a--;
    }
    return -1;
}

void bai7(int *a, int n) {
    cout << "\nvi tri nho nhat cua mang la: a[" << vitrinhonhat(a, n) << "]";
}

int vitrinhonhat(int *a, int n) {
    int min = *a;
    int vitrimin = 0;
    for (int i = 0; i < n; i++) {
        if (*a < min) {
            min = *a;
            vitrimin = i;
        }
        a++;
    }
    return vitrimin;
}

void bai8(int *a, int n) {
    cout << "\nso nguyen to dau tien trong mang : " << songuyentodau(a, n) << endl;
}

int songuyentodau(int *a, int n) {
    for (int i = 0; i < n; i++) {
        if (checkSonguyento(*a) == 1) {
            return *a;
        }
        a++;
    }
    return -1;
}

bool checkSonguyento(int n) {
    if (n < 2) {
        return 0;
    }

    if (n == 2) {
        return 1;
    }

    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

void bai9(int *a, int n) {
    int sntmax = songuyentomax(a, n);
    cout << "\nso nguyen to lon nhat trong mang : " << sntmax << endl;
}

int vitrisonguyentodau(int *a, int n) {
    for (int i = 0; i < n; i++) {
        if (checkSonguyento(*a) == 1) {
            return i;
        }
        a++;
    }
    return -1;
}

int songuyentomax(int *a, int n) {

    if (songuyentodau(a, n) == -1) {
        return 0;
    }
    int sntMax = songuyentodau(a, n);
    for (int i = vitrisonguyentodau(a, n); i < n; i++) {
        if ((checkSonguyento(*a) == 1) && (*a > sntMax)) {
            sntMax = *a;
        }
        a++;
    }

    return sntMax;
}

void bai10(int *a, int n) {
    int x;
    cout << "\nnhap so nguyen x: ";
    cin >> x;
    int xanhat = 0;
    int khoangcachxanhat = abs(*a - x);
    for (int i = 0; i < n; i++) {
        if (abs(x - *a) > khoangcachxanhat) {
            khoangcachxanhat = abs(x - *a);
            xanhat = *a;
        }
        a++;
    }
    cout << "xa gia tri " << x << " nhat la : " << xanhat << endl;
}