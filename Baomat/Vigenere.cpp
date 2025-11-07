#include <iostream>
#include <string>
#include <cctype> // dùng cho toupper, isalpha
using namespace std;

// Hàm mở rộng khóa để bằng độ dài bản rõ
string extendKey(const string &key, int length) {
    string newKey = "";
    int keyIndex = 0;
    for (int i = 0; i < length; i++) {
        if (isalpha(key[keyIndex])) {
            newKey += toupper(key[keyIndex]);
            keyIndex = (keyIndex + 1) % key.length();
        } else {
            newKey += key[keyIndex];
        }
    }
    return newKey;
}

// Hàm mã hóa Vigenère
string vigenereEncrypt(const string &plainText, const string &key) {
    string result = "";
    string newKey = extendKey(key, plainText.length());

    for (int i = 0; i < (int)plainText.length(); i++) {
        char c = plainText[i];
        if (isalpha(c)) {
            char p = toupper(c);
            char k = newKey[i];
            char encrypted = ( (p - 'A') + (k - 'A') ) % 26 + 'A';
            result += encrypted;
        } else {
            result += c; // giữ nguyên ký tự không phải chữ cái
        }
    }
    return result;
}

// Hàm giải mã Vigenère
string vigenereDecrypt(const string &cipherText, const string &key) {
    string result = "";
    string newKey = extendKey(key, cipherText.length());

    for (int i = 0; i < (int)cipherText.length(); i++) {
        char c = cipherText[i];
        if (isalpha(c)) {
            char ci = toupper(c);
            char k = newKey[i];
            char decrypted = ( (ci - 'A') - (k - 'A') + 26 ) % 26 + 'A';
            result += decrypted;
        } else {
            result += c; // giữ nguyên ký tự không phải chữ cái
        }
    }
    return result;
}

int main() {
    string plainText, key;

    cout << "=== VIGENERE CIPHER ===" << endl;
    cout << "Nhap ban ro: ";
    getline(cin, plainText);
    cout << "Nhap khoa: ";
    getline(cin, key);

    string encrypted = vigenereEncrypt(plainText, key);
    cout << "\nBan ma: " << encrypted << endl;

    string decrypted = vigenereDecrypt(encrypted, key);
    cout << "Giai ma lai: " << decrypted << endl;

    return 0;
}
