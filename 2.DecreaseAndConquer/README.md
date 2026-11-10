# CHƯƠNG 4: CHIẾN LƯỢC THIẾT KẾ THUẬT TOÁN GIẢM ĐỂ TRỊ (DECREASE-AND-CONQUER)
### Giáo trình: *Introduction to the Design and Analysis of Algorithms* (Anany Levitin, 3rd Edition)
**Phạm vi nghiên cứu:** Trang 131 đến trang 167 (Toàn bộ Chương 4)  
**Địa chỉ lưu trữ:** `D:\_2026\1.CNTT\5.ThuatToanChuyenSau\2.pttktt\1.pttktt\2.DecreaseAndConquer`

---

## 📌 TỔNG QUAN HỆ THỐNG TÀI LIỆU

Bộ tài liệu này cung cấp toàn bộ nền tảng lý thuyết, mã giả chuẩn hóa cấu trúc (Structured Pseudocode), phân tích toán học độ phức tạp (thời gian tốt nhất/xấu nhất/trung bình, không gian bộ nhớ, tính ổn định, bất biến vòng lặp) và **lời giải chi tiết 100% của toàn bộ 62 bài tập** thuộc Chương 4 sách giáo trình của Giáo sư Anany Levitin.

Tài liệu được phân chia thành các chuyên đề chuyên sâu, bám sát cấu trúc từng mục của giáo trình:

| File tài liệu | Tên chuyên đề & Phạm vi giáo trình | Nội dung trọng tâm | Bài tập giải chi tiết |
| :--- | :--- | :--- | :--- |
| [`00_Tong_Quan_Chien_Luoc_Giam_De_Tri.md`](./00_Tong_Quan_Chien_Luoc_Giam_De_Tri.md) | **Tổng quan Chiến lược Giảm để trị** *(Trang 131–134)* | Bản chất triết lý, 3 biến thể chính (Giảm theo hằng số, Giảm theo tỉ lệ hằng số, Giảm biến thiên), so sánh với Chia để trị & QHD, mô hình Top-down vs Bottom-up. | Hệ thống câu hỏi lý thuyết mở đầu |
| [`01_Muc_4_1_Sap_Xep_Chen_Insertion_Sort.md`](./01_Muc_4_1_Sap_Xep_Chen_Insertion_Sort.md) | **Mục 4.1: Sắp xếp chèn (Insertion Sort)** *(Trang 134–138)* | Thuật toán Sắp xếp chèn, phân tích so sánh khóa $C_{worst}, C_{best}, C_{avg}$, tính ổn định, kỹ thuật lính canh, sắp xếp danh sách liên kết, Shellsort. | **Exercises 4.1**: 12 bài tập (Bài 1 → 12) |
| [`02_Muc_4_2_Sap_Xep_Topological_Topological_Sorting.md`](./02_Muc_4_2_Sap_Xep_Topological_Topological_Sorting.md) | **Mục 4.2: Sắp xếp Tô-pô (Topological Sorting)** *(Trang 138–144)* | Đồ thị có hướng không chu trình (DAG), Thuật toán dựa trên DFS, Thuật toán Xóa đỉnh nguồn (Kahn), Thành phần liên thông mạnh (SCC - Kosaraju), Đếm đường đi mạng nhện. | **Exercises 4.2**: 10 bài tập (Bài 1 → 10) |
| [`03_Muc_4_3_Sinh_Cac_Doi_Tuong_To_Hop_Combinatorial_Objects.md`](./03_Muc_4_3_Sinh_Cac_Doi_Tuong_To_Hop_Combinatorial_Objects.md) | **Mục 4.3: Sinh đối tượng tổ hợp** *(Trang 144–150)* | Sinh hoán vị: Johnson-Trotter (phần tử di động), Thứ tự từ điển (Lexicographic), Thuật toán Heap. Sinh tập con: Đệ quy giảm 1, Mã Gray phản xạ nhị phân (BRGC), Tháp Hà Nội & Trò chơi công tắc đèn. | **Exercises 4.3**: 12 bài tập (Bài 1 → 12) |
| [`04_Muc_4_4_Thuat_Toan_Giam_Theo_Ti_Le_Hang_So_Constant_Factor.md`](./04_Muc_4_4_Thuat_Toan_Giam_Theo_Ti_Le_Hang_So_Constant_Factor.md) | **Mục 4.4: Giảm theo tỉ lệ hằng số** *(Trang 150–157)* | Tìm kiếm nhị phân (Binary Search 2 nhánh & 3 nhánh), Bài toán Đồng xu giả (Fake-Coin 2 đĩa & 3 đĩa), Phép nhân nông dân Nga, Bài toán Josephus (công thức đóng & dịch vòng 1 bit). | **Exercises 4.4**: 15 bài tập (Bài 1 → 15) |
| [`05_Muc_4_5_Thuat_Toan_Giam_Theo_Kich_Thuoc_Bien_Thien_Variable_Size.md`](./05_Muc_4_5_Thuat_Toan_Giam_Theo_Kich_Thuoc_Bien_Thien_Variable_Size.md) | **Mục 4.5: Giảm theo kích thước biến thiên** *(Trang 157–167)* | Thuật toán Euclid (góc nhìn giảm), Bài toán chọn phần tử thứ $k$ (Quickselect & Lomuto/Hoare), Tìm kiếm nội suy (Interpolation Search), Cây BST, Trò chơi Nim (1 đống & đa đống với Nim-sum), Bánh kếp, Saddleback Search. | **Exercises 4.5**: 13 bài tập (Bài 1 → 13) |
| [`GIAO_TRINH_TOAN_TAP_CHUONG_04_GIAM_DE_TRI.md`](./GIAO_TRINH_TOAN_TAP_CHUONG_04_GIAM_DE_TRI.md) | **TOÀN TẬP CHƯƠNG 4 (HỢP NHẤT)** *(Trang 131–167)* | Bản biên soạn hợp nhất toàn diện, liền mạch đầy đủ lý thuyết, mã giả, phân tích và toàn bộ 62 bài tập có lời giải chi tiết 100%. | Đầy đủ 62/62 bài tập |

---

## 📊 BẢNG TỔNG KẾT ĐỘ PHỨC TẠP CỦA CÁC THUẬT TOÁN CỐT LÕI

| Thuật toán | Mục | Cơ chế giảm | Thời gian Tốt nhất | Thời gian Trung bình | Thời gian Xấu nhất | Không gian | Ổn định / Ghi chú |
| :--- | :---: | :---: | :---: | :---: | :---: | :---: | :--- |
| **Insertion Sort** | 4.1 | Giảm 1 ($n-1$) | $\Theta(n)$ | $\Theta(n^2)$ | $\Theta(n^2)$ | $\Theta(1)$ | Ổn định; cực nhanh với mảng gần có thứ tự |
| **Topological Sort (DFS)** | 4.2 | Giảm 1 | $\Theta(\|V\|+\|E\|)$ | $\Theta(\|V\|+\|E\|)$ | $\Theta(\|V\|+\|E\|)$ | $\Theta(\|V\|)$ | Dùng danh sách kề; phát hiện chu trình qua Back edge |
| **Topological Sort (Kahn)**| 4.2 | Giảm 1 | $\Theta(\|V\|+\|E\|)$ | $\Theta(\|V\|+\|E\|)$ | $\Theta(\|V\|+\|E\|)$ | $\Theta(\|V\|)$ | Xóa đỉnh nguồn; dùng Queue lưu in-degree = 0 |
| **Johnson-Trotter** | 4.3 | Giảm 1 | $\Theta(n!)$ | $\Theta(n!)$ | $\Theta(n!)$ | $\Theta(n)$ | Sinh hoán vị thay đổi tối thiểu (1 swap láng giềng) |
| **Lexicographic Permute** | 4.3 | Giảm biến thiên | $\Theta(n)$ mỗi hoán vị | $\Theta(1)$ amortized | $\Theta(n)$ | $\Theta(n)$ | Sinh theo thứ tự từ điển chuẩn |
| **Heap's Algorithm** | 4.3 | Giảm 1 | $\Theta(n!)$ | $\Theta(n!)$ | $\Theta(n!)$ | $\Theta(n)$ | Mỗi hoán vị chỉ tốn đúng 1 phép swap |
| **BRGC (Mã Gray)** | 4.3 | Giảm 1 (phản xạ) | $\Theta(2^n)$ | $\Theta(2^n)$ | $\Theta(2^n)$ | $\Theta(n)$ | Thay đổi đúng 1 bit giữa 2 cấu hình kế tiếp |
| **Binary Search** | 4.4 | Giảm một nửa ($n/2$) | $\Theta(1)$ | $\Theta(\log n)$ | $\Theta(\log n)$ | $\Theta(1)$ | Áp dụng trên mảng đã sắp xếp |
| **Fake-Coin (Chia 3)** | 4.4 | Giảm $n/3$ | $\Theta(\log_3 n)$ | $\Theta(\log_3 n)$ | $\Theta(\log_3 n)$ | $\Theta(1)$ | Nhanh hơn chia 2 khoảng $1.585$ lần |
| **Russian Peasant** | 4.4 | Giảm một nửa ($n/2$) | $\Theta(\log n)$ | $\Theta(\log n)$ | $\Theta(\log n)$ | $\Theta(1)$ | Nhân 2 số chỉ dùng chia đôi, nhân đôi và cộng |
| **Josephus Problem** | 4.4 | Giảm một nửa ($n/2$) | $\Theta(1)$ (dịch bit) | $\Theta(\log n)$ | $\Theta(\log n)$ | $\Theta(1)$ | Nghiệm đóng $J(n) = 2l + 1$ với $n = 2^m + l$ |
| **Euclid GCD** | 4.5 | Giảm biến thiên | $\Theta(1)$ | $\Theta(\log n)$ | $\Theta(\log n)$ | $\Theta(1)$ | Sau 2 bước kích thước giảm ít nhất 1 nửa |
| **Quickselect** | 4.5 | Giảm biến thiên | $\Theta(n)$ | $\Theta(n)$ | $\Theta(n^2)$ | $\Theta(1)$ lặp | Tìm phần tử nhỏ thứ $k$ (trung vị trong $O(n)$) |
| **Interpolation Search** | 4.5 | Giảm biến thiên | $\Theta(1)$ | $\Theta(\log \log n)$ | $\Theta(n)$ | $\Theta(1)$ | Hiệu quả vượt trội khi dữ liệu phân bố đều |
| **BST Search & Insert** | 4.5 | Giảm biến thiên | $\Theta(1)$ | $\Theta(\log n)$ | $\Theta(n)$ | $\Theta(1)$ | Phụ thuộc độ cao của cây |
| **Nim Game Strategy** | 4.5 | Giảm biến thiên | $\Theta(1)$ | $\Theta(1)$ | $\Theta(1)$ | $\Theta(1)$ | Tính toán dựa trên Nim-sum (phép XOR nhị phân) |
| **Saddleback Search** | 4.5 | Giảm 1 hàng/cột | $\Theta(1)$ | $\Theta(n)$ | $\Theta(n)$ | $\Theta(1)$ | Tìm trong ma trận $n \times n$ có hàng & cột tăng |

---

## 🎯 CÁC TIÊU CHUẨN ĐÃ ĐẢM BẢO
1. **Đầy đủ 100%:** Bao phủ toàn bộ nội dung từ trang 131 đến 167 của giáo trình A. Levitin (3rd edition). Không lược bỏ bất kỳ bài toán hay bài tập nào (tổng cộng 62 bài tập).
2. **Khuôn mẫu mã giả chuẩn hóa:** Mỗi thuật toán đều có khối đặc tả cấu trúc `Algorithm Name(Input)`, mô tả đầu vào/đầu ra, các bước đánh số thứ tự kèm chú thích giải thích ngữ nghĩa từng dòng.
3. **Phân tích toán học chuẩn xác:** Sử dụng ký hiệu công thức LaTeX / KaTeX đầy đủ: các phương trình truy hồi, tính tổng $\sum$, cận tiệm cận $O, \Omega, \Theta, o$.
4. **Trực quan & sư phạm:** Có các sơ đồ Mermaid, bảng theo dõi vết từng bước (tracing table) và hình vẽ minh họa chi tiết.
