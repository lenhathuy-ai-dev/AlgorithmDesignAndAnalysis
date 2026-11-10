# CHƯƠNG 6: CHIẾN LƯỢC BIẾN ĐỔI ĐỂ TRỊ (TRANSFORM-AND-CONQUER)
## Giáo trình: *Introduction to the Design and Analysis of Algorithms* (Anany Levitin, 3rd Edition)
**Phạm vi nghiên cứu:** Trang 201 đến trang 252 (Toàn bộ Chương 6)  
**Địa chỉ lưu trữ:** `D:\_2026\1.CNTT\5.ThuatToanChuyenSau\2.pttktt\1.pttktt\4.TransformAndConquer`

---

## 📌 TỔNG QUAN HỆ THỐNG TÀI LIỆU

Bộ tài liệu này cung cấp toàn bộ nền tảng lý thuyết chuyên sâu, mã giả chuẩn hóa cấu trúc (Structured Pseudocode với `function:`, `input:`, `output:`, đánh số dòng và từ khóa đóng tường minh), phân tích toán học độ phức tạp (thời gian tốt nhất/xấu nhất/trung bình, không gian bộ nhớ, tính ổn định) và **lời giải chi tiết 100% của toàn bộ 66 bài tập (với đầy đủ các câu hỏi phụ a, b, c)** thuộc Chương 6 sách giáo trình của GS. Anany Levitin.

Tài liệu được phân chia thành các chuyên đề chuyên sâu bám sát cấu trúc giáo trình:

| File tài liệu | Tên chuyên đề & Phạm vi giáo trình | Nội dung trọng tâm | Bài tập giải chi tiết |
| :--- | :--- | :--- | :--- |
| [`00_Tong_Quan_Chien_Luoc_Bien_Doi_De_Tri.md`](00_Tong_Quan_Chien_Luoc_Bien_Doi_De_Tri.md) | **Tổng quan Chương 6** (pp. 201–202) | Bản chất hai bước, 3 biến thể: Biến đổi thể hiện, Thay đổi biểu diễn, Thu gọn bài toán | Khung phân loại phương pháp |
| [`01_Muc_6_1_Sap_Xep_So_Bo_Presorting.md`](01_Muc_6_1_Sap_Xep_So_Bo_Presorting.md) | **Mục 6.1: Sắp xếp sơ bộ (Presorting)** (pp. 202–208) | Kiểm tra tính duy nhất ($O(n \log n)$), Tìm yếu vị (Mode), Tìm kiếm đa truy vấn | **11 bài tập (6.1.1 – 6.1.11)** |
| [`02_Muc_6_2_Khu_Gauss_Gaussian_Elimination_LU.md`](02_Muc_6_2_Khu_Gauss_Gaussian_Elimination_LU.md) | **Mục 6.2: Khử Gauss & Phân rã LU** (pp. 208–218) | Khử xuôi, Thế ngược, Trục xoay một phần, Phân rã $A=LU$, Nghịch đảo ma trận, Định thức | **12 bài tập (6.2.1 – 6.2.12)** |
| [`03_Muc_6_3_Cay_Tim_Kiem_Can_Bang_AVL_2_3.md`](03_Muc_6_3_Cay_Tim_Kiem_Can_Bang_AVL_2_3.md) | **Mục 6.3: Cây tìm kiếm cân bằng** (pp. 218–226) | Cây AVL (4 phép quay LL, RR, LR, RL), Cây 2-3 (Tách nút từ dưới lên), Đẳng cấu Đỏ-Đen | **10 bài tập (6.3.1 – 6.3.10)** |
| [`04_Muc_6_4_Dong_Va_Sap_Xep_Dong_Heapsort.md`](04_Muc_6_4_Dong_Va_Sap_Xep_Dong_Heapsort.md) | **Mục 6.4: Đống và Heapsort** (pp. 226–234) | Max-Heap bằng mảng, Dựng đống tuyến tính $\Theta(n)$, Heapsort $\Theta(n \log n)$, Hàng đợi ưu tiên | **11 bài tập (6.4.1 – 6.4.11)** |
| [`05_Muc_6_5_Luat_Horner_Va_Luy_Thua_Nhi_Phan.md`](05_Muc_6_5_Luat_Horner_Va_Luy_Thua_Nhi_Phan.md) | **Mục 6.5: Luật Horner & Lũy thừa nhị phân** (pp. 234–244) | Luật Horner tính đa thức tối ưu, Chia đa thức Ruffini, Lũy thừa nhị phân Trái-Phải & Phải-Trái | **10 bài tập (6.5.1 – 6.5.10)** |
| [`06_Muc_6_6_Thu_Gon_Bai_Toan_Problem_Reduction.md`](06_Muc_6_6_Thu_Gon_Bai_Toan_Problem_Reduction.md) | **Mục 6.6: Thu gọn bài toán** (pp. 244–252) | BCNN qua UCLN, Đếm đường đi qua ma trận kề $A^k$, Quy hoạch tuyến tính (LP), Câu đố qua sông | **12 bài tập (6.6.1 – 6.6.12)** |

---

## 🌟 TÀI LIỆU TOÀN VĂN MASTER
1. **Bản Markdown tổng hợp:** [`GIAO_TRINH_TOAN_TAP_CHUONG_06_BIEN_DOI_DE_TRI.md`](GIAO_TRINH_TOAN_TAP_CHUONG_06_BIEN_DOI_DE_TRI.md)
2. **Bản Microsoft Word Equation chuẩn hóa (OMML):** [`Giao_Trinh_Toan_Tap_Chuong_06_Bien_Doi_De_Tri.docx`](Giao_Trinh_Toan_Tap_Chuong_06_Bien_Doi_De_Tri.docx)
   - Chứa hơn **1.500 công thức toán học Word Equation gốc (`<m:oMath>`)**.
   - Hơn **40 bảng mã giả đóng khung chuẩn cấu trúc** và **hộp chú thích học thuật**.
