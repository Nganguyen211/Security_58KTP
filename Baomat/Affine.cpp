#include <iostream>
#include <string>
using namespace std;

// Hàm tìm nghịch đảo modulo của a theo mod m
int mod_inverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) return x;
    }
    return -1; // Không tồn tại
}

// Hàm mã hóa Affine
string affine_encrypt(const string &plain, int a, int b) {
    string result = "";
    for (char c : plain) {
        if (isalpha((unsigned char)c)) {
            char base = isupper(c) ? 'A' : 'a';
            int P = c - base;
            int C = (a * P + b) % 26;
            result += char(C + base);
        } else result += c;
    }
    return result;
}

// Hàm giải mã Affine
string affine_decrypt(const string &cipher, int a, int b) {
    string result = "";
    int a_inv = mod_inverse(a, 26);
    if (a_inv == -1) {
        return "Loi: 'a' khong co nghich dao modulo!";
    }
    for (char c : cipher) {
        if (isalpha((unsigned char)c)) {
            char base = isupper(c) ? 'A' : 'a';
            int C = c - base;
            int P = (a_inv * (C - b + 26)) % 26;
            result += char(P + base);
        } else result += c;
    }
    return result;
}

int main() {
    string text;
    int a, b;
    cout << "=== MA HOA AFFINE ===\n";

    cout << "Nhap chuoi can ma hoa: ";
    getline(cin, text);
    cout << "Nhap khoa a (nguyen to cung 26): ";
    cin >> a;
    cout << "Nhap khoa b: ";
    cin >> b;
    cin.ignore();

    string encrypted = affine_encrypt(text, a, b);
    cout << "Ban ma: " << encrypted << "\n";

    cout << "\n=== GIAI MA ===\n";
    cout << "Nhap chuoi can giai ma: ";
    string cipher;
    getline(cin, cipher);

    cout << "Nhap lai a: ";
    cin >> a;
    cout << "Nhap lai b: ";
    cin >> b;

    string decrypted = affine_decrypt(cipher, a, b);
    cout << "Ban ro: " << decrypted << "\n";

    return 0;
}
