#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Tạo bảng 5x5 từ khóa
string tao_bang_khoa(const string &khoa) {
    string bang, key = khoa;
    // Đưa về chữ in hoa và thay J -> I
    for (char &c : key) {
        if (isalpha((unsigned char)c)) {
            c = toupper(c);
            if (c == 'J') c = 'I';
            if (bang.find(c) == string::npos)
                bang.push_back(c);
        }
    }
    // Thêm các chữ còn thiếu
    for (char c = 'A'; c <= 'Z'; c++) {
        if (c == 'J') continue;
        if (bang.find(c) == string::npos)
            bang.push_back(c);
    }
    return bang; // độ dài = 25
}

// Tìm vị trí chữ trong bảng 5x5
void tim_vi_tri(char c, const string &bang, int &hang, int &cot) {
    if (c == 'J') c = 'I';
    c = toupper(c);
    int idx = bang.find(c);
    hang = idx / 5;
    cot = idx % 5;
}

// Chia bản rõ thành cặp (bigram)
vector<string> tao_cac_cap(string text) {
    vector<string> cap;
    string tmp;
    // Bỏ ký tự không phải chữ
    for (char &c : text) {
        if (isalpha((unsigned char)c)) {
            c = toupper(c);
            if (c == 'J') c = 'I';
            tmp.push_back(c);
        }
    }
    // Xử lý cặp
    for (size_t i = 0; i < tmp.size(); i++) {
        char a = tmp[i];
        char b;
        if (i + 1 < tmp.size()) {
            b = tmp[i + 1];
            if (a == b) { // nếu trùng, chèn X
                b = 'X';
            } else {
                i++;
            }
        } else {
            b = 'X'; // nếu lẻ, thêm X
        }
        string pair; pair.push_back(a); pair.push_back(b);
        cap.push_back(pair);
    }
    return cap;
}

// Mã hóa Playfair
string ma_hoa_playfair(const string &ban_ro, const string &bang) {
    string ket_qua;
    vector<string> cap = tao_cac_cap(ban_ro);

    for (auto &p : cap) {
        int r1, c1, r2, c2;
        tim_vi_tri(p[0], bang, r1, c1);
        tim_vi_tri(p[1], bang, r2, c2);

        if (r1 == r2) { 
            // cùng hàng
            c1 = (c1 + 1) % 5;
            c2 = (c2 + 1) % 5;
        } else if (c1 == c2) { 
            // cùng cột
            r1 = (r1 + 1) % 5;
            r2 = (r2 + 1) % 5;
        } else {
            // khác hàng & cột
            int t = c1;
            c1 = c2;
            c2 = t;
        }
        ket_qua.push_back(bang[r1 * 5 + c1]);
        ket_qua.push_back(bang[r2 * 5 + c2]);
    }
    return ket_qua;
}

// Giải mã Playfair
string giai_ma_playfair(const string &ban_ma, const string &bang) {
    string ket_qua;
    string tmp;
    // Bỏ khoảng trắng, đưa về in hoa
    for (char c : ban_ma) {
        if (isalpha((unsigned char)c)) {
            tmp.push_back(toupper(c));
        }
    }

    for (size_t i = 0; i < tmp.size(); i += 2) {
        char a = tmp[i], b = tmp[i + 1];
        int r1, c1, r2, c2;
        tim_vi_tri(a, bang, r1, c1);
        tim_vi_tri(b, bang, r2, c2);

        if (r1 == r2) {
            // cùng hàng → lùi trái
            c1 = (c1 + 4) % 5;
            c2 = (c2 + 4) % 5;
        } else if (c1 == c2) {
            // cùng cột → lùi lên
            r1 = (r1 + 4) % 5;
            r2 = (r2 + 4) % 5;
        } else {
            // khác hàng & cột
            int t = c1;
            c1 = c2;
            c2 = t;
        }

        ket_qua.push_back(bang[r1 * 5 + c1]);
        ket_qua.push_back(bang[r2 * 5 + c2]);
    }
    return ket_qua;
}

int main() {
    string khoa, ban_ro, ban_ma;
    cout << "=== THUAT TOAN PLAYFAIR ===\n";

    cout << "Nhap khoa: ";
    getline(cin, khoa);
    string bang = tao_bang_khoa(khoa);

    cout << "\nBang khoa (5x5):\n";
    for (int i = 0; i < 25; i++) {
        cout << bang[i] << ' ';
        if ((i + 1) % 5 == 0) cout << '\n';
    }

    // --- Ma hoa ---
    cout << "\n--- MA HOA ---\n";
    cout << "Nhap ban ro: ";
    getline(cin, ban_ro);
    ban_ma = ma_hoa_playfair(ban_ro, bang);
    cout << "Ban ma: " << ban_ma << "\n";

    // --- Giai ma ---
    cout << "\n--- GIAI MA ---\n";
    cout << "Nhap ban ma: ";
    getline(cin, ban_ma);
    cout << "Giai ma: " << giai_ma_playfair(ban_ma, bang) << "\n";

    return 0;
}
