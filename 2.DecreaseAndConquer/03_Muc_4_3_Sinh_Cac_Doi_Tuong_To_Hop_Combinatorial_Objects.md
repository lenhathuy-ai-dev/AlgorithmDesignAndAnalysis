# CHUYÊN ĐỀ 03: SINH CÁC ĐỐI TƯỢNG TỔ HỢP (COMBINATORIAL OBJECTS) & LỜI GIẢI BÀI TẬP 4.3
*Tài liệu tham chiếu: A. Levitin, "Introduction to the Design and Analysis of Algorithms", 3rd Edition, Chương 4, Mục 4.3, Trang 144–150.*

---

## PHẦN I. LÝ THUYẾT VÀ MÃ GIẢ CHUẨN HÓA

Các đối tượng tổ hợp cơ bản nhất bao gồm: **Hoán vị (Permutations)**, **Tập con (Subsets)** và **Tổ hợp (Combinations)**. Chúng là hạt nhân của các bài toán tối ưu hóa tổ hợp và vét cạn toàn diện.

---

### 1.1. Sinh Hoán vị (Generating Permutations)

#### 1.1.1. Thuật toán Johnson-Trotter (Thuật toán thay đổi tối thiểu - Minimal Change)
- **Ý tưởng cốt lõi:** Mỗi phần tử $k \in \{1, 2, \dots, n\}$ được gắn một **hướng di chuyển** (mũi tên trỏ sang trái $\leftarrow$ hoặc sang phải $\rightarrow$).
- **Định nghĩa phần tử di động (Mobile element):** Một phần tử $k$ được gọi là **di động (mobile)** nếu mũi tên của nó trỏ vào một phần tử láng giềng kề sát có giá trị **nhỏ hơn nó**.
- **Quy tắc thuật toán:**
  1. Khởi tạo hoán vị đầu tiên: $\overleftarrow{1} \; \overleftarrow{2} \; \dots \; \overleftarrow{n}$ (tất cả mũi tên trỏ sang trái).
  2. Lặp lại khi vẫn còn phần tử di động:
     - Tìm **phần tử di động lớn nhất** $k$.
     - Đổi chỗ $k$ với phần tử mà mũi tên của nó trỏ tới.
     - **Đảo chiều mũi tên** của tất cả các phần tử có giá trị lớn hơn $k$ ($x > k$).
- **Đặc tính:** Mỗi hoán vị mới được sinh ra chỉ bằng cách **đổi chỗ hai phần tử kề nhau** (Adjacent transposition - Minimal change property).

```text
Algorithm JohnsonTrotter(n)
// Đầu vào: Số nguyên dương n
// Đầu ra: Liệt kê toàn bộ n! hoán vị của {1, 2, ..., n}

1   Khởi tạo hoán vị: A[i] ← i, Dir[i] ← -1 (hướng trái) với mọi i = 1..n
2   In hoán vị A[1..n]
3   while tồn tại phần tử di động trong A do
4       k ← phần tử di động lớn nhất trong A
5       pos ← vị trí của k trong A
6       target ← pos + Dir[pos]
7       swap(A[pos], A[target])
8       swap(Dir[pos], Dir[target])
9       for i ← 1 to n do
10          if A[i] > k then
11              Dir[i] ← -Dir[i]  // Đảo chiều mũi tên
12      In hoán vị A[1..n]
```

---

#### 1.1.2. Thuật toán Sinh Hoán vị theo Thứ tự Từ điển (Lexicographic Permute)
Sinh các hoán vị theo đúng thứ tự tra từ điển (Dictionary order).
- **Thuật toán tìm hoán vị kế tiếp:**
  1. Quét từ phải sang trái, tìm chỉ số $i$ lớn nhất sao cho $a_i < a_{i+1}$. (Nếu không tồn tại, đã đạt hoán vị cuối cùng).
  2. Quét từ phải sang trái, tìm chỉ số $j$ lớn nhất sao cho $a_i < a_j$.
  3. Đổi chỗ $a_i$ và $a_j$.
  4. Đảo ngược đoạn đuôi từ $a_{i+1}$ đến $a_n$.

```text
Algorithm LexicographicPermute(n)
// Đầu vào: Số nguyên dương n
// Đầu ra: Toàn bộ n! hoán vị của {1, 2, ..., n} theo thứ tự từ điển

1   Khởi tạo A[i] ← i với mọi i = 1..n
2   repeat
3       In hoán vị A[1..n]
4       i ← n - 1
5       while i ≥ 1 and A[i] ≥ A[i + 1] do i ← i - 1
6       if i ≥ 1 then
7           j ← n
8           while A[j] ≤ A[i] do j ← j - 1
9           swap(A[i], A[j])
10          Đảo ngược đoạn A[i + 1 .. n]
11  until i = 0
```

---

#### 1.1.3. Thuật toán Heap (Heap's Algorithm - B. R. Heap, 1963)
Thuật toán đệ quy cực kỳ tối ưu, sinh mỗi hoán vị mới chỉ bằng đúng **1 phép hoán đổi**:

```text
Algorithm HeapPermute(n)
// Đầu vào: Số nguyên dương n và mảng toàn cục A[1..n]
// Đầu ra: Toàn bộ n! hoán vị của A

1   if n = 1 then
2       In mảng A
3   else
4       for i ← 1 to n do
5           HeapPermute(n - 1)
6           if n là số lẻ then
7               swap(A[1], A[n])
8           else
9               swap(A[i], A[n])
```

---

### 1.2. Sinh Tập con (Generating Subsets)

#### 1.2.1. Mã Gray nhị phân phản xạ (Binary Reflected Gray Code - BRGC)
- **Mã Gray bậc $n$:** Là danh sách gồm $2^n$ chuỗi bit độ dài $n$ sao cho **hai chuỗi bit liên tiếp chỉ khác nhau đúng 1 bit**.
- **Định nghĩa đệ quy (Giảm 1 - Phản xạ):**
  - Bậc 1: $L_1 = [0, 1]$.
  - Bậc $n$: Lấy danh sách $L_{n-1}$ thêm tiền tố `0`, nối với danh sách đảo ngược $L_{n-1}^R$ thêm tiền tố `1`:
    $$L_n = 0 L_{n-1} \;\|\; 1 L_{n-1}^R$$

```text
Algorithm BRGC(n)
// Đầu vào: Số nguyên dương n
// Đầu ra: Danh sách L chứa 2^n chuỗi bit theo mã Gray nhị phân phản xạ

1   if n = 1 then
2       return danh sách gồm hai chuỗi ["0", "1"]
3   else
4       L1 ← BRGC(n - 1)
5       L2 ← Đảo ngược danh sách L1
6       Thêm ký tự '0' vào đầu mỗi chuỗi trong L1
7       Thêm ký tự '1' vào đầu mỗi chuỗi trong L2
8       return Nối L1 và L2
```

---

## PHẦN II. GIẢI CHI TIẾT 100% CÁC BÀI TẬP EXERCISES 4.3 (BÀI 1 ĐẾN BÀI 12)

---

### Bài 1 (Feasibility of Generating 25-Element Combinatorial Objects - Tính khả thi với $n=25$)
> **Đề bài:**  
> Có thực tế không khi cài đặt một thuật toán đòi hỏi sinh toàn bộ các hoán vị của một tập hợp 25 phần tử trên máy tính của bạn? Thế còn việc sinh toàn bộ các tập con của một tập hợp như vậy thì sao?

#### Lời giải chi tiết:

1. **Trường hợp sinh toàn bộ Hoán vị ($25!$):**
   - Số lượng hoán vị của tập hợp 25 phần tử là:
     $$25! \approx 1.551121 \times 10^{25} \text{ hoán vị}$$
   - Giả sử máy tính siêu tốc có thể tạo ra và xử lý **1 tỷ ($10^9$) hoán vị trong 1 giây**:
     - Số giây cần thiết:
       $$\frac{1.551121 \times 10^{25}}{10^9} \approx 1.551121 \times 10^{16} \text{ giây}$$
     - Đổi ra năm ($1 \text{ năm} \approx 3.1536 \times 10^7 \text{ giây}$):
       $$T = \frac{1.551121 \times 10^{16}}{3.1536 \times 10^7} \approx 4.918 \times 10^8 \text{ năm} \approx \mathbf{492 \text{ triệu năm}!}$$
   - Tuổi của Trái Đất khoảng 4.5 tỷ năm, nghĩa là việc chạy chương trình này tốn hơn 10% tuổi của Trái Đất.
   - **Kết luận:** Hoàn toàn **BẤT KHẢ THI (Utterly Unrealistic)**!

2. **Trường hợp sinh toàn bộ Tập con ($2^{25}$):**
   - Số lượng tập con của tập hợp 25 phần tử là:
     $$2^{25} = 33,554,432 \approx 3.35 \times 10^7 \text{ tập con}$$
   - Với tốc độ xử lý hiện đại ($10^8 - 10^9$ phép tính/giây):
     $$T = \frac{3.355 \times 10^7}{10^8} \approx \mathbf{0.33 \text{ giây}!}$$
   - **Kết luận:** Hoàn toàn **KHẢ THI VÀ RẤT NHANH CHÓNG (Entirely Realistic)**!

---

### Bài 2 (Generate All Permutations of $\{1, 2, 3, 4\}$ - Sinh hoán vị 4 phần tử)
> **Đề bài:**  
> Sinh toàn bộ 24 hoán vị của tập hợp $\{1, 2, 3, 4\}$ bằng:  
> a. Thuật toán thay đổi tối thiểu từ dưới lên (Bottom-up minimal-change algorithm).  
> b. Thuật toán Johnson-Trotter.  
> c. Thuật toán sinh theo thứ tự từ điển (Lexicographic-order algorithm).

#### Lời giải chi tiết:

#### Phần a & b (Thuật toán Johnson-Trotter):
Bắt đầu với $\overleftarrow{1} \; \overleftarrow{2} \; \overleftarrow{3} \; \overleftarrow{4}$. Phần tử di động lớn nhất được gạch chân:

| STT | Trạng thái hoán vị và hướng | Phần tử di động lớn nhất | Thao tác thực hiện |
| :---: | :---: | :---: | :--- |
| 1 | $\overleftarrow{1} \; \overleftarrow{2} \; \overleftarrow{3} \; \underline{\overleftarrow{4}}$ | 4 | Đổi chỗ 4 sang trái |
| 2 | $\overleftarrow{1} \; \overleftarrow{2} \; \underline{\overleftarrow{4}} \; \overleftarrow{3}$ | 4 | Đổi chỗ 4 sang trái |
| 3 | $\overleftarrow{1} \; \underline{\overleftarrow{4}} \; \overleftarrow{2} \; \overleftarrow{3}$ | 4 | Đổi chỗ 4 sang trái |
| 4 | $\underline{\overleftarrow{4}} \; \overleftarrow{1} \; \overleftarrow{2} \; \overleftarrow{3}$ | 3 (vì 4 chạm biên trái) | Đổi chỗ 3 sang trái, đảo chiều các số $> 3$ (chiều của 4 thành $\rightarrow$) |
| 5 | $\underline{\overrightarrow{4}} \; \overleftarrow{1} \; \overleftarrow{3} \; \overleftarrow{2}$ | 4 (hướng phải) | Đổi chỗ 4 sang phải |
| 6 | $\overleftarrow{1} \; \underline{\overrightarrow{4}} \; \overleftarrow{3} \; \overleftarrow{2}$ | 4 | Đổi chỗ 4 sang phải |
| 7 | $\overleftarrow{1} \; \overleftarrow{3} \; \underline{\overrightarrow{4}} \; \overleftarrow{2}$ | 4 | Đổi chỗ 4 sang phải |
| 8 | $\overleftarrow{1} \; \overleftarrow{3} \; \overleftarrow{2} \; \underline{\overrightarrow{4}}$ | 3 (4 chạm biên phải) | Đổi chỗ 3 sang trái, đảo chiều $4 \to \leftarrow$ |
| 9 | $\overleftarrow{1} \; \overleftarrow{3} \; \overleftarrow{2} \; \underline{\overleftarrow{4}}$ | ... | Tiếp tục chu kỳ cho đến đủ 24 hoán vị |

Danh sách đầy đủ 24 hoán vị theo Johnson-Trotter:
1. `1234` $\to$ 2. `1243` $\to$ 3. `1423` $\to$ 4. `4123` $\to$ 5. `4132` $\to$ 6. `1432` $\to$ 7. `1342` $\to$ 8. `1324` $\to$ 9. `3124` $\to$ 10. `3142` $\to$ 11. `3412` $\to$ 12. `4312` $\to$ 13. `4321` $\to$ 14. `3421` $\to$ 15. `3241` $\to$ 16. `3214` $\to$ 17. `2314` $\to$ 18. `2341` $\to$ 19. `2431` $\to$ 20. `4231` $\to$ 21. `4213` $\to$ 22. `2413` $\to$ 23. `2143` $\to$ 24. `2134`.

#### Phần c (Thứ tự từ điển):
1. `1234`
2. `1243`
3. `1324`
4. `1342`
5. `1423`
6. `1432`
7. `2134`
8. `2143`
9. `2314`
10. `2341`
11. `2413`
12. `2431`
13. `3124`
14. `3142`
15. `3214`
16. `3241`
17. `3412`
18. `3421`
19. `4123`
20. `4132`
21. `4213`
22. `4231`
23. `4312`
24. `4321`

---

### Bài 3 (LexicographicPermute on Multiset - Áp dụng trên đa tập)
> **Đề bài:**  
> Áp dụng thuật toán `LexicographicPermute` cho đa tập $\{1, 2, 2, 3\}$. Thuật toán có sinh chính xác toàn bộ các hoán vị phân biệt theo đúng thứ tự từ điển mà không bị trùng lặp không?

#### Lời giải chi tiết:
- Đa tập $\{1, 2, 2, 3\}$ gồm 4 phần tử với số 2 xuất hiện hai lần. Số lượng hoán vị phân biệt theo công thức tổ hợp là:
  $$\frac{4!}{1! \times 2! \times 1!} = \frac{24}{2} = 12 \text{ hoán vị}$$
- Lần vết thuật toán bắt đầu từ `1 2 2 3`:
  1. `1 2 2 3`: $i=3$ ($a_3=2 < a_4=3$), $j=4$. Swap $a_3, a_4 \implies$ `1 2 3 2`.
  2. `1 2 3 2`: $i=2$ ($a_2=2 < a_3=3$), $j=3$ ($a_3=3 > 2$). Swap $a_2, a_3$, đảo đuôi $[3, 2] \to [2, 3] \implies$ `1 3 2 2`.
  3. `1 3 2 2`: $i=1$ ($a_1=1 < a_2=3$), $j=4$ ($a_4=2 > 1$). Swap $a_1, a_4$, đảo đuôi $[3, 2, 1] \to [2, 2, 3] \implies$ `2 1 2 3`.
  4. `2 1 2 3` $\to$ 5. `2 1 3 2` $\to$ 6. `2 2 1 3` $\to$ 7. `2 2 3 1` $\to$ 8. `2 3 1 2` $\to$ 9. `2 3 2 1` $\to$ 10. `3 1 2 2` $\to$ 11. `3 2 1 2` $\to$ 12. `3 2 2 1`.
- Tại bước 12 (`3 2 2 1`), không tồn tại chỉ số $i$ nào thỏa mãn $a_i < a_{i+1}$ (vì $3 \ge 2 \ge 2 \ge 1$). Thuật toán dừng lại.
- **Kết luận:** Thuật toán hoạt động **HOÀN TOÀN CHÍNH XÁC**! Thuật toán sinh ra đúng 12 hoán vị phân biệt, không bỏ sót và không trùng lặp bất kỳ hoán vị nào, đồng thời các hoán vị được sắp xếp hoàn hảo theo thứ tự từ điển.

---

### Bài 4 (Heap's Algorithm Analysis - Phân tích thuật toán Heap)
> **Đề bài:**  
> Xét thuật toán `HeapPermute(n)` của B. R. Heap.  
> a. Lần vết thuật toán bằng tay với $n = 2, 3, 4$.  
> b. Chứng minh tính đúng đắn của thuật toán Heap.  
> c. Phân tích độ phức tạp thời gian của `HeapPermute`.

#### Lời giải chi tiết:

#### Phần a (Lần vết bằng tay):
- **Với $n = 2$:** Mảng $A = [1, 2]$
  - $i=1$: gọi `HeapPermute(1)` $\implies$ in `1 2`. Vì $n=2$ (chẵn), `swap(A[1], A[2])` $\implies A = [2, 1]$.
  - $i=2$: gọi `HeapPermute(1)` $\implies$ in `2 1`. `swap(A[2], A[2])` $\implies A = [2, 1]$.
  - Kết quả: `1 2`, `2 1` (đủ 2! = 2 hoán vị).
- **Với $n = 3$:** Mảng $A = [1, 2, 3]$ (n lẻ $\implies$ luôn `swap(A[1], A[3])`)
  - Vòng $i=1$: Sinh các hoán vị với phần tử cuối 3: `1 2 3`, `2 1 3`. Sau đó swap $A[1], A[3] \implies A = [3, 1, 2]$.
  - Vòng $i=2$: Sinh các hoán vị với phần tử cuối 2: `3 1 2`, `1 3 2`. Sau đó swap $A[1], A[3] \implies A = [2, 3, 1]$.
  - Vòng $i=3$: Sinh các hoán vị với phần tử cuối 1: `2 3 1`, `3 2 1`.
  - Kết quả: Đủ 6 hoán vị phân biệt.

#### Phần b (Chứng minh tính đúng đắn bằng quy nạp):
- Ta chứng minh rằng ở mỗi lần lặp $i$ của vòng lặp $1..n$, việc gọi `HeapPermute(n-1)` sẽ cố định một phần tử ở vị trí cuối cùng $A[n]$ và sinh toàn bộ $(n-1)!$ hoán vị của $n-1$ phần tử đầu tiên.
- Phép hoán đổi ở cuối mỗi vòng lặp được thiết kế đặc biệt:
  - Khi $n$ lẻ: Phép `swap(A[1], A[n])` làm dịch vòng các phần tử. Sau $n$ lần lặp, mỗi phần tử trong số $n$ phần tử đều lần lượt được đưa về vị trí cuối $A[n]$ đúng một lần, và trạng thái mảng quay về trạng thái ban đầu.
  - Khi $n$ chẵn: Phép `swap(A[i], A[n])` đảm bảo đưa một phần tử mới chưa từng ở vị trí cuối về $A[n]$.
- Theo nguyên lý quy nạp, thuật toán sinh ra đúng $n \times (n-1)! = n!$ hoán vị phân biệt.

#### Phần c (Độ phức tạp thời gian):
- Gọi $T(n)$ là số phép hoán đổi để sinh $n!$ hoán vị:
  $$T(n) = n T(n - 1) + n - 1, \quad T(1) = 0$$
- Triển khai:
  $$T(n) = n! \sum_{k=1}^n \frac{1}{k!} \approx (e - 1) n! \in \Theta(n!)$$
- **Số phép gán trung bình cho mỗi hoán vị:**
  $$\frac{T(n)}{n!} \approx e - 1 \approx 1.718 \in \Theta(1)$$
- Mỗi hoán vị mới được tạo ra chỉ tốn thời gian trung bình **$O(1)$**! Đây là một trong những thuật toán sinh hoán vị nhanh nhất từng được phát minh.

---

### Bài 5 (Generate Subsets of 4-Element Set - Sinh tập con 4 phần tử)
> **Đề bài:**  
> Sinh toàn bộ các tập con của tập 4 phần tử $A = \{a_1, a_2, a_3, a_4\}$ bằng:  
> 1. Thuật toán Giảm 1 từ dưới lên.  
> 2. Thuật toán Mã Gray nhị phân phản xạ (BRGC).

#### Lời giải chi tiết:
Có tổng cộng $2^4 = 16$ tập con:

| Chuỗi bit BRGC | Tập con tương ứng theo BRGC | Tập con sinh theo Giảm 1 thông thường |
| :---: | :--- | :--- |
| `0000` | $\emptyset$ | $\emptyset$ |
| `0001` | $\{a_4\}$ | $\{a_1\}$ |
| `0011` | $\{a_3, a_4\}$ | $\{a_2\}$ |
| `0010` | $\{a_3\}$ | $\{a_1, a_2\}$ |
| `0110` | $\{a_2, a_3\}$ | $\{a_3\}$ |
| `0111` | $\{a_2, a_3, a_4\}$ | $\{a_1, a_3\}$ |
| `0101` | $\{a_2, a_4\}$ | $\{a_2, a_3\}$ |
| `0100` | $\{a_2\}$ | $\{a_1, a_2, a_3\}$ |
| `1100` | $\{a_1, a_2\}$ | $\{a_4\}$ |
| `1101` | $\{a_1, a_2, a_4\}$ | $\{a_1, a_4\}$ |
| `1111` | $\{a_1, a_2, a_3, a_4\}$ | $\{a_2, a_4\}$ |
| `1110` | $\{a_1, a_2, a_3\}$ | $\{a_1, a_2, a_4\}$ |
| `1010` | $\{a_1, a_3\}$ | $\{a_3, a_4\}$ |
| `1011` | $\{a_1, a_3, a_4\}$ | $\{a_1, a_3, a_4\}$ |
| `1001` | $\{a_1, a_4\}$ | $\{a_2, a_3, a_4\}$ |
| `1000` | $\{a_1\}$ | $\{a_1, a_2, a_3, a_4\}$ |

- **Nhận xét:** Trong cột BRGC, giữa hai tập con liên tiếp chỉ thêm vào đúng 1 phần tử hoặc bớt đi đúng 1 phần tử (đúng tính chất thay đổi tối thiểu).

---

### Bài 6 (Squashed Order for Subsets - Thứ tự Squashed)
> **Đề bài:**  
> Mẹo đơn giản nào có thể làm cho thuật toán sinh dựa trên chuỗi bit sinh các tập con theo thứ tự squashed (thứ tự mà trong đó mọi tập con của $\{a_1, \dots, a_{m-1}\}$ xuất hiện trước các tập con chứa $a_m$)?

#### Lời giải chi tiết:
- Thứ tự "squashed" đòi hỏi: Tập rỗng $\emptyset$ xuất hiện đầu tiên; tiếp theo là các tập con chỉ gồm $\{a_1\}$; tiếp theo là các tập con của $\{a_1, a_2\}$; tiếp theo là $\{a_1, a_2, a_3\}$,...
- Nếu ta biểu diễn tập con bằng chuỗi bit $b_n b_{n-1} \dots b_1$ theo quy ước chuẩn: $b_i = 1 \iff a_i$ có mặt trong tập con.
- **Mẹo đơn giản:** Đọc chuỗi bit theo thứ tự **từ phải sang trái** (ngược trọng số thông thường), hoặc biểu diễn số nguyên $i = 0, 1, \dots, 2^n - 1$ dưới dạng nhị phân sao cho bit có trọng số thấp nhất $2^0$ ứng với phần tử $a_1$, bit $2^1$ ứng với $a_2$, ..., bit $2^{n-1}$ ứng với $a_n$.
- Khi đó, việc tăng dần giá trị đếm $i$ từ $0$ đến $2^n - 1$ sẽ tự động sinh các tập con theo đúng thứ tự squashed:
  - $i=0$ (`...000`): $\emptyset$.
  - $i=1$ (`...001`): $\{a_1\}$.
  - $i=2, 3$ (`...010`, `...011`): $\{a_2\}, \{a_1, a_2\}$.
  - $i=4..7$: các tập con mới chứa thêm $a_3$.

---

### Bài 7 (Recursive Bit Strings Generation - Mã giả đệ quy sinh chuỗi bit)
> **Đề bài:**  
> Viết mã giả cho thuật toán đệ quy sinh toàn bộ $2^n$ chuỗi bit độ dài $n$.

#### Lời giải chi tiết:

```text
Algorithm GenerateBitStrings(k, n, B)
// Sinh toàn bộ chuỗi bit bằng đệ quy giảm 1
// Đầu vào: Vị trí hiện tại k (bắt đầu từ 0), độ dài n, mảng bit B[0..n-1]
// Lần gọi ban đầu: GenerateBitStrings(0, n, B)

1   if k = n then
2       In chuỗi bit B[0..n-1]
3   else
4       B[k] ← 0
5       GenerateBitStrings(k + 1, n, B)
6       B[k] ← 1
7       GenerateBitStrings(k + 1, n, B)
```
- **Phân tích:** Cây đệ quy nhị phân hoàn hảo có độ sâu $n$, số nút lá là $2^n$. Tổng thời gian $\Theta(2^n)$.

---

### Bài 8 (Nonrecursive Bit Strings Without Addition - Sinh chuỗi bit không đệ quy không cộng)
> **Đề bài:**  
> Viết một thuật toán không đệ quy sinh $2^n$ chuỗi bit độ dài $n$ cài đặt chuỗi bit bằng mảng và không sử dụng phép cộng nhị phân.

#### Lời giải chi tiết:
Sử dụng mảng $B[0..n-1]$ và một biến chỉ số để đảo bit:

```text
Algorithm NonrecursiveBitStrings(n)
// Sinh 2^n chuỗi bit không đệ quy và không dùng phép cộng nhị phân
// Đầu vào: Số nguyên dương n

1   Khởi tạo mảng B[0..n-1] ← [0, 0, ..., 0]
2   In B
3   repeat
4       // Tìm vị trí bit 0 đầu tiên từ phải sang trái
5       j ← n - 1
6       while j ≥ 0 and B[j] = 1 do
7           B[j] ← 0      // Lật các bit 1 thành 0
8           j ← j - 1
9       if j ≥ 0 then
10          B[j] ← 1      // Lật bit 0 đầu tiên thành 1
11          In B
12  until j < 0
```

---

### Bài 9 (BRGC Order 4 & Nonrecursive Algorithm - Mã Gray bậc 4)
> **Đề bài:**  
> a. Sinh mã Gray nhị phân phản xạ bậc 4.  
> b. Lần vết thuật toán không đệ quy sinh mã Gray bậc 4 bằng quy tắc: Bắt đầu từ chuỗi toàn số 0. Với $i = 1, 2, \dots, 2^n - 1$, sinh chuỗi thứ $i$ bằng cách lật bit ở vị trí $b$ trong chuỗi trước đó, trong đó $b$ là vị trí của **bit 1 có trọng số nhỏ nhất (least significant 1)** trong biểu diễn nhị phân của $i$.

#### Lời giải chi tiết:

#### Phần a:
Liệt kê đầy đủ 16 mã Gray bậc 4:
`0000, 0001, 0011, 0010, 0110, 0111, 0101, 0100, 1100, 1101, 1111, 1110, 1010, 1011, 1001, 1000`.

#### Phần b (Lần vết thuật toán không đệ quy):
Quy ước vị trí bit đánh số từ phải sang trái: bit 0 (ngoài cùng bên phải), bit 1, bit 2, bit 3.

| $i$ | Biểu diễn nhị phân của $i$ | Vị trí bit 1 thấp nhất ($b$) | Thao tác trên chuỗi bit cũ | Chuỗi bit Gray mới |
| :---: | :---: | :---: | :--- | :---: |
| 0 | `0000` | - | Khởi tạo | `0000` |
| 1 | `0001` | 0 | Lật bit 0 | `0001` |
| 2 | `0010` | 1 | Lật bit 1 | `0011` |
| 3 | `0011` | 0 | Lật bit 0 | `0010` |
| 4 | `0100` | 2 | Lật bit 2 | `0110` |
| 5 | `0101` | 0 | Lật bit 0 | `0111` |
| 6 | `0110` | 1 | Lật bit 1 | `0101` |
| 7 | `0111` | 0 | Lật bit 0 | `0100` |
| 8 | `1000` | 3 | Lật bit 3 | `1100` |
| 9 | `1001` | 0 | Lật bit 0 | `1101` |
| 10 | `1010` | 1 | Lật bit 1 | `1111` |
| 11 | `1011` | 0 | Lật bit 0 | `1110` |
| 12 | `1100` | 2 | Lật bit 2 | `1010` |
| 13 | `1101` | 0 | Lật bit 0 | `1011` |
| 14 | `1110` | 1 | Lật bit 1 | `1001` |
| 15 | `1111` | 0 | Lật bit 0 | `1000` |

Kết quả hoàn toàn khớp 100% với danh sách phản xạ ở phần a!

---

### Bài 10 (Combinations Generation - Sinh tổ hợp chập $k$ của $n$)
> **Đề bài:**  
> Thiết kế một thuật toán Giảm để trị để sinh toàn bộ tổ hợp chập $k$ của $n$ phần tử phân biệt (tức là tất cả các tập con $k$ phần tử của tập hợp $n$ phần tử). Thuật toán của bạn có phải là thuật toán thay đổi tối thiểu không?

#### Lời giải chi tiết:
- Dựa trên công thức tổ hợp Pascal kinh điển:
  $$\binom{n}{k} = \binom{n - 1}{k} + \binom{n - 1}{k - 1}$$
- Bản chất Giảm để trị:
  - Tập tổ hợp chập $k$ của $\{a_1, \dots, a_n\}$ chia làm 2 nhóm:
    1. **Không chứa $a_n$:** Chính là toàn bộ tổ hợp chập $k$ của $n-1$ phần tử $\{a_1, \dots, a_{n-1}\}$.
    2. **Có chứa $a_n$:** Lấy toàn bộ tổ hợp chập $k-1$ của $\{a_1, \dots, a_{n-1}\}$ rồi ghép thêm phần tử $a_n$.
- **Mã giả đệ quy:**
```text
Algorithm GenerateCombinations(n, k)
if k = 0 then return { ∅ }
if k = n then return { {a_1, a_2, ..., a_n} }
L1 ← GenerateCombinations(n - 1, k)
L2 ← GenerateCombinations(n - 1, k - 1)
for each subset C in L2 do
    C ← C ∪ { a_n }
return L1 ∪ L2
```
- **Về tính chất thay đổi tối thiểu (Minimal-change):**
  - Trong bài toán tổ hợp, "thay đổi tối thiểu" nghĩa là giữa hai tổ hợp liên tiếp chỉ khác nhau đúng **1 phần tử bị bỏ ra và 1 phần tử được thêm vào** (1 swap).
  - Thuật toán đệ quy thuần túy ở trên **chưa đạt** tính chất thay đổi tối thiểu tại điểm nối giữa $L_1$ và $L_2$. Tuy nhiên, nếu ta áp dụng kỹ thuật phản xạ (đảo ngược danh sách $L_2$ tương tự như mã Gray), ta sẽ thu được **Mã Gray cho tổ hợp (Revolving-door algorithm)** thỏa mãn tuyệt đối tính chất thay đổi tối thiểu!

---

### Bài 11 (Gray Code & Tower of Hanoi - Mã Gray và Tháp Hà Nội)
> **Đề bài:**  
> a. Chứng minh rằng các bước chuyển đĩa trong thuật toán đệ quy kinh điển của bài toán Tháp Hà Nội có thể được dùng để sinh mã Gray nhị phân phản xạ.  
> b. Chỉ ra cách dùng mã Gray nhị phân phản xạ để giải bài toán Tháp Hà Nội.

#### Lời giải chi tiết:

#### Phần a:
- Trong bài toán Tháp Hà Nội với $n$ đĩa, số bước chuyển đĩa tối thiểu là $2^n - 1$.
- Đánh số các đĩa từ 1 (đĩa nhỏ nhất) đến $n$ (đĩa lớn nhất).
- Xét dãy đĩa được di chuyển tại mỗi bước $i = 1, 2, \dots, 2^n - 1$:
  - Đĩa được di chuyển tại bước thứ $i$ chính là đĩa có số hiệu $d = b + 1$, trong đó $b$ là **vị trí của bit 1 thấp nhất** trong biểu diễn nhị phân của $i$.
  - Đây chính xác là quy tắc lật bit của mã Gray không đệ quy trong Bài 9b!
- Do đó, nếu ta theo dõi biến trạng thái của các đĩa (bit 0/1 biểu thị trạng thái cọc), mỗi lần chuyển đĩa tương ứng chính xác với việc lật đúng 1 bit trong mã Gray.

#### Phần b (Cách giải Tháp Hà Nội bằng mã Gray):
1. Liệt kê $2^n$ chuỗi bit của mã Gray bậc $n$ từ $00\dots0$ đến $10\dots0$.
2. Tại bước $i$ (chuyển từ chuỗi bit thứ $i-1$ sang chuỗi bit thứ $i$):
   - Xác định bit vừa bị lật ở vị trí nào (giả sử vị trí $k$, đếm từ phải sang trái).
   - Bit ở vị trí $k$ bị lật tương ứng với hành động: **Di chuyển đĩa thứ $k$**!
3. Hướng di chuyển của đĩa:
   - Với đĩa nhỏ nhất (đĩa 1): Luôn di chuyển tuần hoàn theo một hướng cố định:
     - Nếu $n$ lẻ: Cọc $A \to C \to B \to A \dots$
     - Nếu $n$ chẵn: Cọc $A \to B \to C \to A \dots$
   - Với các đĩa khác ($k > 1$): Chỉ có duy nhất một nước đi hợp lệ (chuyển sang cọc không chứa đĩa nhỏ hơn nó).
- Như vậy, mã Gray cung cấp lời giải không đệ quy hoàn hảo cho bài toán Tháp Hà Nội!

---

### Bài 12 (Fair Attraction & Hidden Switches - Trò chơi công tắc đèn hội chợ)
> **Đề bài:**  
> Tại một hội chợ xưa, có một trò chơi giải đố như sau: Một bóng đèn được nối với $n$ công tắc ẩn sao cho bóng đèn **chỉ bật sáng khi tất cả các công tắc đều đóng** (trạng thái $11\dots1$). Mỗi công tắc được điều khiển bởi một nút bấm; mỗi lần nhấn nút sẽ đảo trạng thái của công tắc tương ứng (đóng thành mở, mở thành đóng). Tuy nhiên, người chơi không thể nhìn thấy trạng thái hiện tại của các công tắc mà chỉ biết bóng đèn có sáng hay không. Mục tiêu là làm cho bóng đèn bật sáng.  
> Hãy thiết kế một thuật toán để bật sáng bóng đèn với **số lần bấm nút ít nhất có thể trong trường hợp xấu nhất** cho $n$ công tắc.

#### Lời giải chi tiết:
- **Phân tích bản chất bài toán:**
  - Có $n$ công tắc, do đó có $2^n$ trạng thái có thể có của hệ thống.
  - Ban đầu hệ thống đang ở một trạng thái ẩn nào đó trong $2^n$ trạng thái (chưa phải trạng thái $11\dots1$ vì đèn chưa sáng).
  - Mỗi lần bấm nút là chuyển sang một trạng thái láng giềng khác nhau đúng 1 bit.
  - Mục tiêu trong trường hợp xấu nhất: Ta phải duyệt qua **toàn bộ không gian $2^n$ trạng thái** mà không bị lặp lại, để đảm bảo chắc chắn sẽ chạm tới trạng thái mục tiêu $11\dots1$.
- **Thiết kế thuật toán tối ưu bằng Mã Gray:**
  - Ta lập một lộ trình bấm nút tương ứng với chuỗi lật bit của **Mã Gray nhị phân phản xạ bậc $n$**.
  - Tại bước $i = 1, 2, \dots, 2^n - 1$:
    - Bấm nút tương ứng với bit bị lật ở bước thứ $i$ của mã Gray (chính là vị trí của bit 1 thấp nhất trong biểu diễn nhị phân của $i$).
    - Kiểm tra xem bóng đèn đã sáng chưa. Nếu đèn sáng $\implies$ DỪNG THUẬT TOÁN NGAY LẬP TỨC.
- **Tính tối ưu:**
  - Chuỗi mã Gray tạo thành một **đường đi Hamilton** trên đồ thị siêu lập phương $n$ chiều ($n$-dimensional hypercube). Nó đi qua mọi trạng thái mà không bao giờ lặp lại bất kỳ cấu hình nào.
  - Mỗi bước di chuyển giữa hai trạng thái chỉ tốn đúng **1 lần bấm nút**.
- **Số lần bấm nút tối đa trong trường hợp xấu nhất:**
  - Trong trường hợp xấu nhất, trạng thái mục tiêu $11\dots1$ nằm ở vị trí cuối cùng của chu trình duyệt.
  - Số lần bấm nút tối đa cần thiết là:
    $$N_{worst} = 2^n - 1 \text{ lần bấm}$$
  - Không thể có thuật toán nào có số lần bấm ít hơn $2^n - 1$ trong trường hợp xấu nhất vì kích thước không gian tìm kiếm là $2^n$.
