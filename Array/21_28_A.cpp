//#include<iostream>
//using namespace std;
//
//
//void nhapMang(int a[20][20], int row, int col);
//void xuatMang(int a[20][20], int row, int col);
//void nhapHangCot(int &row,int &col);
//void bai22(int a[20][20], int row, int col);
//void bai21(int a[20][20], int row, int col);
//void bai23(int a[20][20], int row, int col);
//void bai24(int a[20][20], int row, int col);
//void bai25(int a[20][20], int row, int col);
//bool checkHoangHau(int a[20][20], int row, int col, int x, int y);
//void nhapXY(int& x, int& y);
//void bai26(int a[20][20], int row, int col);
//bool checkYenNgua(int a[20][20], int row, int col, int x, int y);
//void bai27(int a[20][20], int row, int col);
//int soChuSo(int n);
//int sumMaTran(int a[20][20], int x, int y, int k);
//void bai28(int a[20][20], int row, int col);
//
//
//int main() {
//    int bai = 28;
//   // int a[20][20] = { {0,20,754,1,}, {1,165,13,1}, {2,1,1111,12} };
//    int a[20][20];
//    int row ;
//    int col ;
//    nhapHangCot(row, col);
//    nhapMang(a, row, col);
//    cout << "\n";
//    xuatMang(a, row, col);
//    
//    switch (bai) {
//    case 21:
//        bai21(a,row,col);
//        break;
//    case 22:
//        bai22(a, row, col);
//        break;
//    case 23:
//        bai23(a, row, col);
//        break;
//    case 24:
//        bai24(a, row, col);
//        break;
//    case 25:
//        bai25(a, row, col);
//        break;
//    case 26:
//        bai26(a, row, col);
//        break;
//    case 27:
//        bai27(a, row, col);
//        break;
//    case 28:
//        bai28(a, row, col);
//        break;
//    default:
//        break;
//    }
//}
//
//void nhapMang(int a[20][20], int row, int col) {
//    for (int i = 0; i < row; i++) {
//        for (int j = 0; j < col; j++) {
//            cout << "a[" << i << "][" << j << "] = ";
//            cin >> a[i][j];
//        }
//    }
//}
//void xuatMang(int a[20][20], int row, int col) {
//    for (int i = 0; i < row; i++) {
//        for (int j = 0; j < col; j++) {
//            cout << a[i][j] << "\t";
//
//        }
//        cout << "\n";
//    }
//}
//void nhapHangCot(int& row, int& col) {
//    cout << "nhap so dong: ";
//    cin >> row;
//    cout << "nhap so cot: ";
//    cin >> col;
//}
//
//#pragma region Bai21
//void bai21(int a[20][20], int row, int col) {
//    int tichSoLe = 1;
//    for (int i = 0; i < row; i++) {
//        for (int j = 0; j < col; j++) {
//            if (a[i][j] % 2 == 1) {
//                tichSoLe = tichSoLe * a[i][j];
//            }
//        }
//    }
//    cout << "\ntich so le trong ma tran la: " << tichSoLe << endl;
//}
//#pragma endregion Bai21
//
//#pragma region Bai22
//void bai22(int a[20][20], int row, int col) {
//
//    for (int i = 0; i < col; i++) {
//        int tichSoChan = 1;
//        for (int j = 0; j < row; j++) {
//            if (a[j][i] % 2 == 0) {
//
//                tichSoChan = tichSoChan * a[j][i];
//            }
//        }
//        if (tichSoChan == 1) {
//            cout << "cot " << i + 1 << " khong co so chan" << endl;
//        }
//        else {
//            cout << "cot " << i + 1 << " co tich so chan la : " << tichSoChan << endl;
//        }
//    }
//
//}
//#pragma endregion Bai22
//
//#pragma region Bai23
//void bai23(int a[20][20], int row, int col) {
//    int tongGiaTriBien = 0;
//    for (int i = 0; i < row; i++) {
//        for (int j = 0; j < col; j++) {
//            if ((i == 0) || (j == 0) || (i == row - 1) || (j = col - 1)) {
//                tongGiaTriBien = tongGiaTriBien + a[i][j];
//            }
//        }
//    }
//    cout << "tong gia tri bien cua ma tran la : " << tongGiaTriBien << endl;
//}
//#pragma endregion Bai23
//
//#pragma region Bai24
//void bai24(int a[20][20], int row, int col) {
//    int tongSoPhanTuCucDai = 0;
//    if ((a[0][0] > a[0][1]) && (a[0][0] > a[1][0])) {
//        tongSoPhanTuCucDai = tongSoPhanTuCucDai + 1;
//    }
//    if ((a[0][col - 1] > a[0][col - 2]) && (a[0][col - 1] > a[1][col - 1])) {
//        tongSoPhanTuCucDai = tongSoPhanTuCucDai + 1;
//    }
//    if ((a[row - 1][0] > a[row - 1][1]) && (a[row - 1][0] > a[row - 2][0])) {
//        tongSoPhanTuCucDai = tongSoPhanTuCucDai + 1;
//    }
//    if ((a[row - 1][col - 1] > a[row - 1][col - 2]) && (a[row - 1][col - 1] > a[row - 2][col - 1])) {
//        tongSoPhanTuCucDai = tongSoPhanTuCucDai + 1;
//    }
//    for (int i = 1; i < col - 1; i++) {
//        if ((a[0][i] > a[0][i + 1]) && (a[0][i] > a[0][i - 1]) && (a[0][i] > a[1][i])) {
//            tongSoPhanTuCucDai = tongSoPhanTuCucDai + 1;
//        }
//    }
//    for (int i = 1; i < col - 1; i++) {
//        if ((a[row -1][i] > a[row - 1][i + 1]) && (a[row -1][i] > a[row -1][i - 1]) && (a[row - 1][i] > a[row -2][i])) {
//            tongSoPhanTuCucDai = tongSoPhanTuCucDai + 1;
//        }
//    }
//    for (int i = 1; i < row - 1; i++) {
//        if ((a[i][0] > a[i-1][0]) && (a[i][0] > a[i+1][0]) && (a[i][0] > a[i][1])) {
//            tongSoPhanTuCucDai = tongSoPhanTuCucDai + 1;
//        }
//    }
//    for (int i = 1; i < row - 1; i++) {
//        if ((a[i][col -1] > a[i + 1][col - 1]) && (a[i][col - 1] > a[i - 1][col - 1]) && (a[i][col - 1] > a[i][col - 2])) {
//            tongSoPhanTuCucDai = tongSoPhanTuCucDai + 1;
//        }
//    }
//    for (int i = 1; i < row-1; i++) {
//        for (int j = 1; j < col-1; j++) {
//            if ((a[i][j] > a[i+1][j]) && (a[i][j]> a[i-1][j]) && (a[i][j]> a[i][j+1]) && (a[i][j]> a[i][j-1])) {
//                tongSoPhanTuCucDai = tongSoPhanTuCucDai + 1;
//            }
//        }
//    }
//    cout << "\nso phan tu lon hon xung quanh la : " << tongSoPhanTuCucDai << endl;
//}
//#pragma endregion Bai24
//
//#pragma region Bai25
//void bai25(int a[20][20], int row, int col) {
//    int x, y;
//    nhapXY(x, y);
//    bool check = checkHoangHau(a, row, col,x,y);
//    if (check) {
//        cout << "diem a[" << x << "][" << y << "] = " << a[x][y] << " la diem hoanng hau" << endl;
//    }
//    else {
//        cout << "diem a[" << x << "][" << y << "] = " << a[x][y] << " khong phai la diem hoanng hau" << endl;
//    }
//  
//}
//bool checkHoangHau(int a[20][20], int row, int col, int x, int y) {
//    int dem = 0;
//    for (int i = 0; i < row; i++) {
//        if (a[i][y] >= a[x][y] ) {
//            dem = dem + 1;
//            if (dem >= 2) {
//                return 0;
//            }
//        }
//    }
//    dem = 0;
//    for (int i = 0; i < col; i++) {
//        if (a[x][i] >= a[x][y]) {
//            dem = dem + 1;
//            if (dem >= 2) {
//                return 0;
//            }
//        }
//    }
//
//    dem = 0;
//    for (int i = -min(x, y); (((x + i) < row) && ((y + i) < col)); i++) {
//        if (a[x + i][y + i] >= a[x][y]) {
//            dem = dem + 1;
//            if (dem >= 2) {
//                return 0;
//            }
//        }
//    }
//
//     dem = 0;
//    for (int i = -min(x,col-y); (((x-i) < row) && ((y+i) < col)); i++) {
//        if (a[x + i][y - i] >= a[x][y]) {
//            dem = dem + 1;
//            if (dem >= 2) {
//                return 0;
//            }
//        }
//    }
//    return 1;
//
//}
//
//void nhapXY(int& x, int& y) {
//    cout << "nhap toa do cua diem can xet a[x][y] :" << endl;
//    cout << "x =  ";
//    cin >> x;
//    cout << "y =  ";
//    cin >> y;
//}
//#pragma endregion Bai25
//
//#pragma region Bai26
//void bai26(int a[20][20], int row, int col) {
//    int x, y;
//    nhapXY(x,y);
//    bool check = checkYenNgua(a, row, col, x, y);
//    if (check) {
//        cout << "diem a[" << x << "][" << y << "] = " << a[x][y] << " la diem yen ngua" << endl;
//    }
//    else {
//        cout << "diem a[" << x << "][" << y << "] = " << a[x][y] << " khong phai la diem yen ngua" << endl;
//    }
//}
//
//bool checkYenNgua(int a[20][20], int row, int col, int x, int y) {
//    for (int i = 0; i < col; i++) {
//        if (a[x][y] > a[x][i]) {
//            return 0;
//        }
//    }
//
//    for (int i = 0; i < row; i++) {
//        if (a[x][y] < a[i][y]) {
//            return 0;
//        }
//    }
//    return 1;
//}
//#pragma endregion Bai26
//
//#pragma region Bai27
//void bai27(int a[20][20], int row, int col) {
//    int b[100] = {};
//    for (int i = 0; i < col; i++) {
//        for (int j = 0; j < row; j++) {
//            b[i] = b[i] + soChuSo(a[j][i]);
//        }
//        cout << "cot thu " << i + 1 << " co tat ca " << b[i] << " chu so\n";
//    }
//}
//
//int soChuSo(int n) {
//    int P = n;
//    int S = 0;
//    if (n == 0) {
//        S = S + 1;
//    }
//    else {
//        for (int i = 0; P > 0; i++) {
//            S = S + 1;
//            P = P / 10;
//        }
//    }
//
//    return S;
//}
//#pragma endregion Bai27
//
//#pragma region Bai28
//void bai28(int a[20][20], int row, int col) {
//    int k = 3;
//    int max = sumMaTran(a, 0, 0, k);
//    int xMax = 0;
//    int yMax = 0;
//    for (int i = 0; i < row - (k-1); i++) {
//        for (int j = 0; j < col - (k-1); j++) {
//            int curSum = sumMaTran(a, i, j, k);            
//            if (max < curSum) {
//                max = curSum;
//                xMax = i;
//                yMax = j;
//            }
//        }
//    }
//
//    for (int i = xMax; i < xMax + k; i++) {
//        for (int j = yMax; j < yMax + k; j++) {
//            cout << a[i][j] << "\t";
//        }
//        cout << "\n";
//    }
//    cout << "\n";
//}
//
//int sumMaTran(int a[20][20],int x, int y, int k) {
//    int S = 0;
//    for (int i = x; i < x + k; i++) {
//        for (int j = y; j < y + k; j++) {
//            S = a[i][j] + S;
//        }
//    }
//    return S;
//}
//#pragma endregion Bai28
//
//#pragma region Bai29
//
//#pragma endregion Bai29
//
//#pragma region Bai30
//
//#pragma endregion Bai30
