#include <iostream>
#include <string>
#include <cctype>   // Thư viện xử lý ký tự
using namespace std;

// Hàm mã hóa một ký tự đơn lẻ
char ma_hoa_ky_tu(char ch, int k) {
    if (isalpha((unsigned char)ch)) {
        bool la_chu_hoa = isupper((unsigned char)ch);
        char moc = la_chu_hoa ? 'A' : 'a';
        int vt_goc = ch - moc;
        int vt_moi = (vt_goc + k + 26) % 26;
        return char(vt_moi + moc);
    }
    return ch;
}

// Hàm giải mã một ký tự
char giai_ma_ky_tu(char ch, int k) {
    return ma_hoa_ky_tu(ch, -k);
}

// Hàm mã hóa toàn chuỗi
string ma_hoa_chuoi(const string &chuoi, int k) {
    string kq = "";
    for (size_t i = 0; i < chuoi.length(); i++) {
        kq += ma_hoa_ky_tu(chuoi[i], k);
    }
    return kq;
}

// Hàm giải mã toàn chuỗi
string giai_ma_chuoi(const string &chuoi, int k) {
    string kq = "";
    for (size_t i = 0; i < chuoi.length(); i++) {
        kq += giai_ma_ky_tu(chuoi[i], k);
    }
    return kq;
}

int main() {
    string ro, ma;
    int k;

    cout << "===== THUAT TOAN MA HOA CAESAR =====" << endl;

    // Nhập bản rõ và khóa
    cout << "\n>> Nhap ban ro: ";
    getline(cin, ro);
    cout << ">> Nhap khoa k: ";
    cin >> k;
    cin.ignore();

    // Mã hóa
    ma = ma_hoa_chuoi(ro, k);
    cout << "\nBan ma thu duoc: " << ma << endl;

    // Giải mã
    string ma_nhap;
    cout << "\n>> Nhap lai ban ma de giai ma: ";
    getline(cin, ma_nhap);
    cout << ">> Nhap khoa k: ";
    cin >> k;

    string giai_ma = giai_ma_chuoi(ma_nhap, k);
    cout << "\nBan giai ma: " << giai_ma << endl;

    return 0;
}
