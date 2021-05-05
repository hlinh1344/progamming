// Inclusion order and rules
// 1. System libraries: use <>
// 2. Users's libraries: use ""
 
#include <iostream>
#include <vector>
#include "IO.h"
//#include "Algorithm.h"
#include "Source.h"

using namespace std;

void bai1();
void sochan(int a[], int n);
void bai4(int a[], int n);
void bai5(int a[], int n);
int duongdau(int a[], int n);
void bai6(int a[], int n);
int chancuoi(int a[], int n);
void bai7(int a[], int n);
int vitrinhonhat(int a[], int n);
void bai8(int a[], int n);
bool checkSonguyento(int n);
int songuyentodau(int a[], int n);
void bai9(int a[], int n);
int vitrisonguyentodau(int a[], int n);
int songuyentomax(int a[], int n);
void bai10(int a[], int n);
void bai11(int a[], int n);
void bai12(int a[], int n);
void bai13(int a[], int n);
int vitritichlancan(int a[], int n);
int vitrisochandautien(int a[], int n);
void bai14(int a[], int n);
int soledautien(int a[], int n);
int solenhonhat(int a[], int n);
void bai15(int a[], int n);
void bai16(int a[], int n);
void bai17(int a[], int n);
void xoaphantu(int a[], int b[], int& n, int vitri);
void bai25(int a[], int n);
void bai18(int a[], int n);
void bai19(int a[], int n);
void bai20(int a[], int n);
void bai21(int a[], int n);
vector<vector<int>> C(int a[], int l, int n, int k, int x);
int sum2(vector <int> a);
void inVT(vector <int> a);
void bai22(int a[], int n);
void bai23(int a[], int n);
//void bai24(int a[], int n);
 
int main() {

    int a[100];
    int n;
    nhapn(n);
    nhapmang(a, n);
    int s = sum(a, n);
    xuatmang(a, n);

    int bai = 24;
    switch (bai) {
    case 3:
        sochan(a, n);
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
    case 7:
        bai7(a, n);
    case 8:
        bai8(a, n);
        break;
    case 9:
        bai9(a, n);
        break;
    case 10:
        bai10(a, n);
        break;
    case 11:
        bai11(a, n);
        break;
    case 12:
        bai12(a, n);
        break;
    case 13:
        bai13(a, n);
        break;
    case 14:
        bai14(a, n);
        break;
    case 15:
        bai15(a, n);
        break;
    case 16:
        bai16(a, n);
        break;
    case 17:
        bai17(a, n);
        break;
    case 18:
        bai18(a, n);
        break;
    case 19:
        bai19(a, n);
        break;
    case 20:
        bai20(a, n);
        break;
    case 25:
        bai25(a, n);
        break;
    case 21:
        bai21(a, n);
        break;
    case 22:
        bai22(a, n);
        break;
    case 23:
        bai23(a, n);
        break;
    //case 24:
        //bai24(a, n);
        //break;
    default:
        break;
    }
    cout << "\n";
    system("pause");
    return 0;
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
            cout << "a[" << i << "]\t";
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
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] % 2 == 0) {
            return a[i];
        }
    }
    return -1;
}
#pragma endregion Bai6

#pragma region Bai7
void bai7(int a[], int n) {
    cout << "\nvi tri nho nhat cua mang la: a[" << vitrinhonhat(a, n) << "]";
}

int vitrinhonhat(int a[], int n) {
    int min = a[0];
    int vitrimin = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
            vitrimin = i;
        }
    }
    return vitrimin;
}
#pragma endregion Bai7

#pragma region Bai8

void bai8(int a[], int n) {
    cout << "\nso nguyen to dau tien trong mang : " << songuyentodau(a, n) << endl;
}

int songuyentodau(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (checkSonguyento(a[i]) == 1) {
            return a[i];
        }
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

#pragma endregion Bai8

#pragma region Bai9
void bai9(int a[], int n) {
    int sntmax = songuyentomax(a, n);
    cout << "\nso nguyen to lon nhat trong mang : " << sntmax << endl;
}

int vitrisonguyentodau(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (checkSonguyento(a[i]) == 1) {
            return i;
        }
    }
    return -1;
}

int songuyentomax(int a[], int n) {

    if (songuyentodau(a, n) == -1) {
        return 0;
    }
    int sntmax = songuyentodau(a, n);
    for (int i = vitrisonguyentodau(a, n); i < n; i++) {
        if ((checkSonguyento(a[i]) == 1) && (a[i] > sntmax)) {
            sntmax = a[i];
        }
    }

    return sntmax;
}
#pragma endregion Bai9

#pragma region Bai10
void bai10(int a[], int n) {
    int x;
    cout << "\nnhap so nguyen x: ";
    cin >> x;
    int xanhat = 0;
    int khoangcachxanhat = abs(a[0] - x);
    for (int i = 1; i < n; i++) {
        if (abs(x - a[i]) > khoangcachxanhat) {
            khoangcachxanhat = abs(x - a[i]);
            xanhat = a[i];
        }
    }

    cout << "xa gia tri " << x << " nhat la : " << xanhat << endl;
}
#pragma endregion Bai10

#pragma region Bai11
void bai11(int a[], int n) {
    int x;
    cout << "\nnhap so nguyen x: ";
    cin >> x;
    int gannhat = 0;
    int khoangcachgannhat = abs(a[0] - x);
    for (int i = 1; i < n; i++) {
        if (abs(x - a[i]) < khoangcachgannhat) {
            khoangcachgannhat = abs(x - a[i]);
            gannhat = i;
        }
    }

    cout << "vi tri gan gia tri " << x << " nhat la : a[" << gannhat << "]" << endl;
}
#pragma endregion Bai11

#pragma region Bai12
void bai12(int a[], int n) {
    int timx = abs(a[0]);
    for (int i = 1; i < n; i++) {
        if (abs(a[i]) > timx) {
            timx = abs(a[i]);
        }
    }
    cout << "\n[" << -timx << "," << timx << "] chua tat ca gia tri trong mang" << endl;
}
#pragma endregion Bai12

#pragma region Bai13
void bai13(int a[], int n) {
    int vitri = vitritichlancan(a, n);
    cout << "\nvi tri co gia tri bang tich 2 so xung quanh: a[" << vitri << "]" << endl;
}
int vitritichlancan(int a[], int n) {

    for (int i = 1; i < n - 1; i++) {
        if (a[i] == a[i - 1] * a[i + 1]) {
            return i;
        }
    }
    return -1;
}
#pragma endregion Bai13

#pragma region Bai14
void bai14(int a[], int n) {

    int solemin = solenhonhat(a, n);
    int sochannhohonx = a[vitrisochandautien(a, n)];

    for (int i = vitrisochandautien(a, n) + 1; i < n; i++) {
        if ((a[i] % 2 == 0) && (a[i] < solemin)) {
            sochannhohonx = a[i];
        }
    }
    if ((sochannhohonx > solemin) || (soledautien(a, n) == -1) || (vitrisochandautien(a, n) == -1)) {
        cout << "\nkhong tim duoc so thoa man";
    }
    else {

        cout << "\nso chan can tim la: " << sochannhohonx << endl;
    }
}
int vitrisochandautien(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0)
            return i;
    }
    return -1;
}
int soledautien(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 1)
            return a[i];
    }
    return -1;
}
int solenhonhat(int a[], int n) {
    int solemin = soledautien(a, n);
    for (int i = 0; i < n; i++) {
        if (((a[i] % 2 == 1) || (a[i] % 2 == -1)) && (a[i] < solemin)) {
            solemin = a[i];
        }
    }
    return solemin;
}
#pragma endregion Bai14

#pragma region Bai15
void bai15(int a[], int n) {
    int b[100];
    cout << "\n";
    for (int i = 0; i < n; i++) {
        b[i] = 0;
    }
    cout << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i] == a[j]) {
                b[i] = b[i] + 1;
            }
        }
    }
    cout << "\n";
    int vitriitlaplainhat = 0;
    for (int i = 1; i < n; i++) {
        if (b[i] < b[vitriitlaplainhat]) {
            vitriitlaplainhat = i;
        }
    }
    cout << "\nso it lap lai nhat la: " << a[vitriitlaplainhat] << endl;
}
#pragma endregion Bai15

#pragma region Bai16
void bai16(int a[], int n) {
    int S = 0;
    if (n == 1) {
        S = 0;
    }
    else {
        if (a[0] > a[1]) {
            S = S + a[0];
        }
        if (a[n - 1] > a[n - 2]) {
            S = S + a[n - 1];
        }
        for (int i = 1; i < n - 1; i++) {
            if ((a[i] > (a[i - 1])) && (a[i] > (a[i + 1]))) {
                S = S + a[i];
            }
        }
    }
    cout << "\ntong can tim la: " << S;
}
#pragma endregion Bai16

#pragma region Bai17
void bai17(int a[], int n) {
    int b[100];
    cout << "\n";
    for (int i = 0; i < n; i++) {
        b[i] = 0;
    }
    cout << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i] == a[j]) {
                b[i] = b[i] + 1;
            }
        }
    }
    int n2 = n;
    for (int i = 0; i < n2-1; i++) {
        for (int j = i+1; j < n2; j++) {
            if (a[i] == a[j]) {
                xoaphantu(a, b, n2, j);
            }
        }

    }

    for (int i = 0; i < n2; i++) {
        cout << "\nso " << a[i] << " xuat hien " << b[i] << " lan";
    }

}
void xoaphantu(int a[],int b[], int &n, int vitri) {
    for (vitri; vitri < n; vitri++) {
        a[vitri] = a[vitri + 1];
        b[vitri] = b[vitri + 1];

    }
    n = n - 1;
}
#pragma endregion Bai17

#pragma region Bai17a
void bai25(int a[], int n) {
    int b[100] = { 0 };
    cout << "\n";

    for (int i = 0; i < n; i++) {
        b[a[i]] = b[a[i]] + 1;
    }
  
    for (int i = 0; i < n; i++) {
        if (b[i] > 1) {
            cout << "\nso " << i << " xuat hien " << b[i] << " lan";
        }
    }
}
#pragma endregion Bai17a

#pragma region Bai18
void bai18(int a[], int n) {
    int n2;
    int b[100];
    cout << "\nhap mang b:" << endl;
    nhapn(n2);
    nhapmang(b, n2);
    xuatmang(b, n2);
    int dem = 0;

    for (int i = 0; i < n; i++) {
        int i2 = i;
        int j2 = 0;
        bool check = 1;
        for (int j = 0; j < n2; j++)
        {
            if (a[i2++] != b[j2++]) {
                check = 0;
                break;
            }
        }
        if (check == 1) {
            dem = dem + 1;
        }
    }
    
    cout << "\nso lan lap lai cua mang b trong mang a la: " << dem << endl;
}
#pragma endregion Bai18

#pragma region Bai19
void bai19(int a[], int n) {
    cout << "\n";
    cout << "\ncac day con tang dan trong mang la:" << endl;

    if (a[0] < a[1]) {
        cout << a[0]<<"\t";
    }

    for (int i = 1; i < n-1; i++) {
        if (a[i] < a[i + 1]) {
            cout << a[i] << "\t";
        }
        else if((a[i]> a[i+1]) &&(a[i-1]< a[i]) ) {
            cout << a[i] << "\n";
        }
    }

    if (a[n-2] < a[n-1]) {
        cout << a[n-1] << "\n";
    }
}
#pragma endregion Bai19

#pragma region Bai20
void bai20(int a[], int n) {
    int m;
    cout << "\nnhap so M: ";
    cin >> m;
    cout << "cac mang con co tong gia tri = " << m << " la :" << endl;
    for (int i = 0; i < n; i++) {
        int S = 0;
        for (int j = i; j < n; j++) {
            S = S + a[j];
            if (S > m) {
                break;
            }
            if (S == m) {
                for (int k = i; k <= j; k++) {
                    cout << a[k] << "\t";
                }
                cout << "\n";
                break;
            }
        }
       
    }
}
#pragma endregion Bai20

#pragma region Bai21
void bai21(int a[], int n) {
    int x;
    cout << "\nnhap so x:";
    cin >> x;  

    for (int k = 1; k <= n; k++) {
        auto result = C(a, 0, n, k, x);
        for (int i = 0; i < result.size(); i++)
        {
            int S = sum2(result[i]);
            if (x == S) {
                inVT(result[i]);
            }
        }
    }  
 }

int sum2(vector <int> a) {
    int Sum = 0;
    for (int j = 0; j< a.size(); j++)
        Sum = Sum + a[j];
    return Sum;
}

void inVT(vector <int> a) {
    cout << "{";
    for (int i = 0; i < a.size(); i++) {
        cout <<a[i];
        if (i == a.size() - 1) {
            cout << "}";
        }
        else {
            cout << ",";
        }
    }
    cout << "\n";
}
vector<vector<int>> C(int a[], int l, int n, int k, int x) {

    if (k == 0 || l == n) {
        return { {} };
    }    
    vector<vector<int>> result;
    for (int i = l; i < n - k + 1; i++) {        
        vector<vector<int>> subResult = C(a, i + 1, n, k - 1, x);        
        for (int j = 0; j < subResult.size(); j++)
        {
            subResult[j].insert(subResult[j].begin(), a[i]);
            result.push_back(subResult[j]);
        }        
    }    
    return result;
}


#pragma endregion Bai21

#pragma region Bai22
void bai22(int a[], int n) {
    int b[100] = { };
    int c[100] = { };
    c[n - 1] = a[n - 1];
    b[0] = a[0];
    int j = 0;

    for (int i = 1; i < n; i++) {
        j = j + 1;
        if (a[i] < b[j-1]) {
            b[j] = a[i];
        }
        else {
            b[j] = b[j - 1];
        }
    }

    j = n - 1;
    for (int i = n-2; i >= 0; i--) {
        j = j - 1;
        if (a[i] > c[j+1]) {
            c[j] = a[i];
        }
        else {
            c[j] = c[j + 1];
        }
        
    }
    cout << "\n";
    int i = 0;
    int iMax = 0;
    int jMax = 0;
    int maxIJ = -1;
    while (i < n && j < n) {
        if (b[i] < c[j]) {
            maxIJ = max(maxIJ, j - i);
            j = j + 1;
        }
        else {
            i = i + 1;
        }
    }


    if (maxIJ == -1) {
        cout << "\n-1";
    }
    else {
        for (int k = 0; k < n; k++) {
            if (a[k + maxIJ] > a[k]) {
                iMax = k;
                jMax = k + maxIJ;
                break;
            }
        }
        cout << "\ni = " << iMax << "\nj = " << jMax << endl;
    }
   

}
#pragma endregion Bai22

#pragma region Bai23
void bai23(int a[], int n) {
    int x; 
    cout << "\nnhap so x: ";
    cin >> x;

    int i = 0;
    int j = n - 1;
    int iNearestX = 0;
    int jNearestX = n - 1;
    int nearestX = abs(a[0] + a[n - 1] - x);
    while (i < j) {
        if (abs(a[i] + a[j] - x) <= nearestX) {
            iNearestX = i;
            jNearestX = j;
            nearestX = abs(a[i] + a[j] - x);
        }

        if (abs(a[i + 1] + a[j] - x) <= nearestX) {
            i++;
        }
        else {
            j--;
        }

    }
    cout << "\n" << a[iNearestX] << " va "<< a[jNearestX] << endl;
}
#pragma endregion Bai23

#pragma region Bai24

#pragma endregion Bai24

#pragma region Bai25

#pragma endregion Bai25