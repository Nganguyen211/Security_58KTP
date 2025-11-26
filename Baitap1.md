# Security_58KTP
BÀI TẬP MÔN: An toàn và bảo mật thông tin
BÀI TẬP 1:
TÌM HIỂU CÁC PHƯƠNG PHÁP MÃ HOÁ CỔ ĐIỂN

1 Caesar

2 Affine

3 Hoán vị

4 Vigenère

5 Playfair

Với mỗi phương pháp, hãy tìm hiểu:
  Tên gọi  Thuật toán mã hoá, thuật toán giải mã
  Không gian khóa
  Cách phá mã (mà không cần khoá)
  Cài đặt thuật toán mã hoá và giải mã bằng code C++ và bằng html+css+javascript

BÀI LÀM:

1) Caesar

* Tên

Caesar cipher (dịch chuyển theo một số k cố định)

* Thuật toán

Mã hóa: với ký tự chữ hoa/thuộc bảng A–Z, C = (P + k) mod 26. Với chữ thường tương tự (a–z).

Giải mã: P = (C - k) mod 26.

(K thường là số nguyên 0..25)

* Không gian khóa

26 (nếu chỉ A–Z) → rất nhỏ.

* Cách phá mã (không cần khóa)

Brute-force: thử 26 khóa — đọc kết quả để chọn ý nghĩa.

Frequency analysis: dò tần suất chữ cái (E, T, A...) để suy ra k.
*Cài đặt thuật toán mã hoá và giải mã bằng code C++ và bằng html+css+javascript.
Mã hóa và giải thuật bằng C++
<img width="779" height="451" alt="image" src="https://github.com/user-attachments/assets/62b0ba27-ea5a-4730-abb0-502c4ea1ae01" />



2) Affine 

* Tên

Affine cipher (mã affine): là ánh xạ tuyến tính modulo 26.

* Thuật toán

Mã hóa: C = (a * P + b) mod 26, với P là chỉ số chữ (0..25), a và b là khóa; a phải có nghịch đảo modulo 26 (gcd(a,26)=1).

Giải mã: P = a_inv * (C - b) mod 26, với a_inv là nghịch đảo nhân modulo 26.

* Không gian khóa

a có thể là một trong các số nguyên nguyên tố với 26: những a such that gcd(a,26)=1. Các giá trị a khả dĩ: 1,3,5,7,9,11,15,17,19,21,23,25 → 12 giá trị.

b có 26 giá trị (0..25).

Tổng keyspace = 12 * 26 = 312.

* Cách phá mã (không cần khóa)

Brute-force: thử tất cả 312 cặp (a,b) — dễ.

Known plaintext / frequency: dùng tần suất để tìm a,b.
Mã hóa và giải thuật bằng C++
<img width="757" height="308" alt="image" src="https://github.com/user-attachments/assets/38489295-02af-4f78-b876-3a7b02228028" />

3) Transposition (Columnar) 

* Tên

Transposition cipher (hoán vị cột, hoán vị theo block) — giữ nguyên các ký tự nhưng thay đổi vị trí.

* Thuật toán

Ví dụ phổ biến: Columnar Transposition:

Chọn một khóa là một chuỗi chữ (ví dụ "ZEBRA"); gán thứ tự chỉ số theo thứ tự chữ cái → vị trí cột.

Viết plaintext theo hàng vào ma trận với số cột = độ dài khóa.

Đọc các cột theo thứ tự khóa để tạo ciphertext.

Khôi phục (giải mã): xác định kích thước ma trận từ chiều dài ciphertext và khóa, rồi điền các cột theo thứ tự và đọc theo hàng.

* Không gian khóa

Với độ dài khóa m, nếu khóa là hoán vị các cột thì keyspace = m!. Nếu khóa là từ thì số lượng tùy thuộc vào tập chữ/độ dài.

* Cách phá mã (không cần khóa)

Brute-force: thử các hoán vị cột (m! lớn → chỉ khả thi cho m nhỏ).

Kỹ thuật thống kê: kiểm tra tính hợp lý (ngôn ngữ), bigram/trigram, hoặc dùng anagramming + hill-climbing (heuristic) để tìm hoán vị cho điểm cao nhất theo mô hình ngôn ngữ (như simulated annealing, genetic algorithm).

Nếu attacker có plaintext nguyên mẫu hoặc biết cấu trúc (ví dụ từ khóa độ dài nhỏ), dễ hơn.
<img width="756" height="312" alt="image" src="https://github.com/user-attachments/assets/bd35a87b-20cb-4d19-a9eb-b5dbe78fb052" />

4) Vigenère

* Tên

Vigenère cipher — polyalphabetic substitution using key word.

* Thuật toán

Mã hóa: lặp khóa K so kích thước với plaintext P. C_i = (P_i + K_i) mod 26 (nếu chữ cái).

Giải mã: P_i = (C_i - K_i) mod 26.

K_i là chỉ số chữ trong key (A=0,..).

* Không gian khóa

Nếu khóa có độ dài m và mỗi ký tự 26 khả năng → 26^m (rất lớn cho m lớn).

* Cách phá mã (không cần khóa)

Kasiski Examination: tìm khoảng cách giữa các xuất hiện của cùng một chuỗi trùng lặp để ước lượng độ dài khóa.

Friedman test (index of coincidence): ước lượng độ dài khóa.

Sau khi biết độ dài m, tách ciphertext thành m chuỗi (các chữ vị trí mod m) và thực hiện frequency analysis (vì mỗi chuỗi là như Caesar).

Known plaintext attack cũng dễ.
<img width="755" height="344" alt="image" src="https://github.com/user-attachments/assets/9a4003ce-3a7d-4a74-bd26-077a65def473" />

5. Playfair cipher
* Tên

Playfair cipher — substitution theo cặp (digraph), dùng bảng 5×5 (thường gộp I/J).

* Thuật toán

Tạo bảng (5×5) từ khóa: ghi khóa (bỏ ký tự trùng, thay J bằng I hoặc ngược lại), sau đó điền phần còn lại của bảng với các chữ cái còn lại A–Z (loại bỏ chữ đã dùng; hợp nhất I/J).

Chuẩn hóa plaintext:

Thay J → I (nếu quy ước đó).

Tách plaintext thành digraph (cặp): nếu một digraph có hai ký tự giống nhau thì chèn chữ 'X' (hoặc 'Q') vào giữa rồi tiếp tục.

Nếu cuối cùng lẻ, thêm chữ 'X' để padding.

Mã hóa một digraph (pair) (A,B):

Nếu A và B ở cùng hàng → thay mỗi ký tự bằng ký tự bên phải (vòng quanh).

Nếu cùng cột → thay bằng ký tự bên dưới.

Nếu khác hàng và cột → thay bằng ký tự cùng hàng với mỗi ký tự nhưng cột lấy cột của ký tự kia (hình chữ nhật → swap cột).

Giải mã: ngược lại (bên trái / bên trên).

* Không gian khóa

Với bảng 5×5, số cấu hình có thể là rất lớn (25! / something) nếu dùng bất kỳ hoán vị, nhưng nếu key là một chuỗi ký tự, keyspace phụ thuộc vào tất cả các chuỗi có thể — thực tế khó brute-force trực tiếp, nhưng Playfair bị tấn công bằng phân tích digraph frequency và thuật toán tối ưu hóa.

* Cách phá mã (không cần khóa)

Frequency analysis of digraphs (thống kê cặp 2-chữ).

Hill-climbing / simulated annealing: tìm bảng 5×5 tốt nhất đánh giá bằng mô hình ngôn ngữ (score log-likelihood từ quadgrams).

Có nhiều công cụ tự động cổ điển (như simulated annealing) để phá Playfair.
<img width="755" height="330" alt="image" src="https://github.com/user-attachments/assets/3279ab32-b3be-4459-bb57-90258b917f91" />
