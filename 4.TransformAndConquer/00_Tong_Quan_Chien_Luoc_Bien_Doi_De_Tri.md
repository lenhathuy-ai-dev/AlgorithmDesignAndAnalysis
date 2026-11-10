# CHƯƠNG 6: CHIẾN LƯỢC BIẾN ĐỔI ĐỂ TRỊ (TRANSFORM-AND-CONQUER)
*Tài liệu tham chiếu chuẩn hóa: A. Levitin, "Introduction to the Design and Analysis of Algorithms", 3rd Edition, Chương 6, Trang 201–252.*

---

# CHUYÊN ĐỀ 00: TỔNG QUAN CHIẾN LƯỢC BIẾN ĐỔI ĐỂ TRỊ (TRANSFORM-AND-CONQUER)

## 1. TRIẾT LÝ VÀ BẢN CHẤT CỐT LÕI
Chiến lược **Biến đổi để trị (Transform-and-Conquer)** là một họ các phương pháp thiết kế thuật toán hoạt động dựa trên nguyên lý hai bước:
1. **Giai đoạn Biến đổi (Transformation Stage):** Chuyển đổi thể hiện bài toán ban đầu thành một thể hiện khác:
   - Dễ giải quyết hơn (more convenient / simpler instance).
   - Có dạng cấu trúc biểu diễn dữ liệu thuận lợi hơn (different data representation).
   - Hoặc chuyển đổi hoàn toàn sang một bài toán khác đã có sẵn thuật toán giải hiệu quả (different problem).
2. **Giai đoạn Trị / Giải quyết (Conquering Stage):** Giải quyết thể hiện sau khi biến đổi để thu được nghiệm của bài toán gốc.

## 2. BA BIẾN THỂ CHÍNH CỦA BIẾN ĐỔI ĐỂ TRỊ
Tùy thuộc vào bản chất của phép biến đổi, chiến lược được chia thành ba nhóm lớn:

```
                          ┌──────────────────────────────────────────────┐
                          │     TRANSFORM-AND-CONQUER (BIẾN ĐỔI ĐỂ TRỊ)  │
                          └──────────────────────┬───────────────────────┘
                                                 │
          ┌──────────────────────────────────────┼──────────────────────────────────────┐
          │                                      │                                      │
          ▼                                      ▼                                      ▼
┌───────────────────────────┐          ┌───────────────────────────┐          ┌───────────────────────────┐
│     1. BIẾN ĐỔI THỂ HIỆN   │          │   2. THAY ĐỔI BIỂU DIỄN   │          │   3. THU GỌN BÀI TOÁN     │
│   (Instance Simplification)│          │   (Representation Change) │          │    (Problem Reduction)    │
├───────────────────────────┤          ├───────────────────────────┤          ├───────────────────────────┤
│ • Chuyển sang thể hiện    │          │ • Giữ nguyên thể hiện     │          │ • Chuyển đổi bài toán A   │
│   cùng loại nhưng dễ hơn. │          │   nhưng đổi cấu trúc lưu. │          │   thành bài toán B.       │
│ • Ví dụ: Sắp xếp sơ bộ   │          │ • Ví dụ: Cây AVL, 2-3 Tree│          │ • Ví dụ: Tính lcm qua gcd,│
│   (Presorting), Khử Gauss │          │   Đống (Heap), Horner,    │          │   đường đi qua nhân ma trận│
│   (Gaussian Elimination). │          │   Lũy thừa nhị phân.      │          │   quy hoạch tuyến tính LP.│
└───────────────────────────┘          └───────────────────────────┘          └───────────────────────────┘
```

1. **Biến đổi thể hiện (Instance Simplification):**
   - Chuyển thể hiện bài toán ban đầu thành một thể hiện mới của *cùng một bài toán* nhưng có tính chất đơn giản hơn.
   - *Ví dụ 1:* **Sắp xếp sơ bộ (Presorting)** – Biến mảng lộn xộn thành mảng đã sắp xếp; nhờ đó bài toán kiểm tra tính duy nhất (Uniqueness) giảm từ $\Theta(n^2)$ xuống $\Theta(n \log n)$, tìm yếu vị (Mode) giảm từ $\Theta(n^2)$ xuống $\Theta(n \log n)$.
   - *Ví dụ 2:* **Khử Gauss (Gaussian Elimination)** – Biến hệ phương trình đại số tuyến tính $Ax = b$ với ma trận đầy đủ thành hệ tương đương với ma trận tam giác trên $Ux = y$, cho phép giải bằng phép thế ngược cực kỳ đơn giản.

2. **Thay đổi biểu diễn (Representation Change):**
   - Chuyển đổi cấu trúc dữ liệu biểu diễn của bài toán sang một cấu trúc dữ liệu mới hỗ trợ các thao tác nhanh hơn vượt bậc.
   - *Ví dụ 1:* **Cây tìm kiếm cân bằng (Balanced Search Trees - AVL & 2-3 Trees)** – Thay vì dùng cây tìm kiếm nhị phân có nguy cơ thoái hóa thành đường thẳng ($\Theta(n)$), ta duy trì cấu trúc cân bằng để đảm bảo thời gian tìm kiếm, chèn, xóa luôn là $\Theta(\log n)$ trong mọi trường hợp.
   - *Ví dụ 2:* **Cấu trúc Đống (Heap) & Heapsort** – Biểu diễn danh sách bằng cây nhị phân gần hoàn chỉnh thỏa mãn tính chất trội của cha, cho phép tìm và xóa phần tử cực trị trong $\Theta(\log n)$ và sắp xếp trong $\Theta(n \log n)$.
   - *Ví dụ 3:* **Luật Horner & Lũy thừa nhị phân** – Biến đổi đa thức thành dạng ngoặc lồng nhau và số mũ thành dạng biểu diễn nhị phân để giảm số phép nhân từ $\Theta(n^2)$ xuống $\Theta(n)$ và từ $\Theta(n)$ xuống $\Theta(\log n)$.

3. **Thu gọn bài toán (Problem Reduction):**
   - Chuyển đổi toàn bộ bài toán cần giải thành một bài toán hoàn toàn khác mà lời giải hiệu quả đã được biết rõ.
   - *Ví dụ 1:* Tìm BCNN $\text{lcm}(m, n) = \frac{m \cdot n}{\gcd(m, n)}$ (thu gọn về thuật toán Euclid).
   - *Ví dụ 2:* Đếm số đường đi độ dài $k$ trong đồ thị thu gọn về phép nhân lũy thừa ma trận kề $A^k$.
   - *Ví dụ 3:* Thu gọn các bài toán tối ưu hóa tổ hợp (Maximum Flow, Bipartite Matching) về Quy hoạch tuyến tính (Linear Programming - Simplex Method).
