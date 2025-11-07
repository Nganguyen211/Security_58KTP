#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

// Ham nhap khoa hoan vi va kiem tra hop le
vector<int> nhapKhoaHoanVi() {
    cout << "Nhap khoa hoan vi (vi du: 2 0 3 1): ";
    string dong;
    getline(cin, dong);

    stringstream ss(dong);
    vector<int> khoa;
    int val;
    while (ss >> val) khoa.push_back(val);

    int n = khoa.size();
    vector<int> check = khoa;
    sort(check.begin(), check.end());
    for (int i = 0; i < n; i++) {
        if (check[i] != i) {
            cerr << "Loi: Khoa khong hop le. Phai chua day du cac so tu 0 den " << n - 1 << ".\n";
            exit(1);
        }
    }
    return khoa;
}

// Ma hoa hoan vi
string maHoaHoanVi(const string &banRo, const vector<int> &khoa) {
    string ketQua;
    int n = khoa.size();
    for (size_t i = 0; i < banRo.size(); i += n) {
        string block = banRo.substr(i, n);
        while (block.size() < (size_t)n) block.push_back('X');

        string blockMa(n, ' ');
        for (int j = 0; j < n; j++) {
            blockMa[j] = block[khoa[j]];
        }
        ketQua += blockMa;
    }
    return ketQua;
}

// Giai ma hoan vi
string giaiMaHoanVi(const string &banMa, const vector<int> &khoa) {
    string ketQua;
    int n = khoa.size();
    for (size_t i = 0; i < banMa.size(); i += n) {
        string block = banMa.substr(i, n);
        string blockGiai(n, ' ');

        for (int j = 0; j < n; j++) {
            blockGiai[khoa[j]] = block[j];
        }
        ketQua += blockGiai;
    }
    return ketQua;
}

int main() {
    string banRo, banMa;
    vector<int> khoa;

    cout << "=============================\n";
    cout << "  THUAT TOAN MA HOA HOAN VI \n";
    cout << "=============================\n";

    // --- MA HOA ---
    cout << "\n--- BUOC 1: MA HOA ---\n";
    cout << "Nhap ban ro: ";
    getline(cin, banRo);
    khoa = nhapKhoaHoanVi();

    banMa = maHoaHoanVi(banRo, khoa);
    cout << "Ban ma: " << banMa << "\n";

    // --- GIAI MA ---
    cout << "\n--- BUOC 2: GIAI MA ---\n";
    cout << "Nhap ban ma: ";
    getline(cin, banMa);
    khoa = nhapKhoaHoanVi();

    string giai = giaiMaHoanVi(banMa, khoa);
    cout << "Ban ro giai ma: " << giai << "\n";

    return 0;
}
