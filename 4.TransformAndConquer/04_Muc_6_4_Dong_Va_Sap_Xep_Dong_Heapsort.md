# CHUYÊN ĐỀ 04: ĐỐNG VÀ SẮP XẾP ĐỐNG (HEAPS AND HEAPSORT) & LỜI GIẢI BÀI TẬP 6.4
*Tài liệu tham chiếu: A. Levitin, "Introduction to the Design and Analysis of Algorithms", 3rd Edition, Chương 6, Mục 6.4, Trang 226–234.*

---

## PHẦN I. LÝ THUYẾT VÀ MÃ GIẢ CHUẨN HÓA

### 4.1. Khái niệm Cấu trúc Đống (Heap Definition)
Đống (Heap) là một cấu trúc dữ liệu kinh điển minh họa cho biến thể **Thay đổi biểu diễn (Representation Change)**.
Một cây nhị phân được gọi là một **Đống cực đại (Max-Heap)** nếu thỏa mãn đồng thời hai điều kiện:
1. **Tính chất hình học (Shape Property):** Là một cây nhị phân gần hoàn chỉnh (essentially complete binary tree):
   - Mọi mức của cây đều chứa đầy đủ số nút tối đa, ngoại trừ có thể mức cuối cùng.
   - Ở mức cuối cùng, tất cả các nút lá đều được điền dồn về phía tận cùng bên trái mà không để lại bất kỳ lỗ hổng nào.
2. **Tính chất trội của cha (Parental Dominance / Heap Property):**
   - Khóa lưu tại mỗi nút luôn lớn hơn hoặc bằng các khóa lưu tại các nút con của nó:
     $$\text{Key}(\text{parent}) \ge \text{Key}(\text{children})$$
   *(Hệ quả: Phần tử lớn nhất trong toàn bộ đống luôn luôn nằm tại nút gốc!)*

---

### 4.2. Cài đặt Đống bằng Mảng (Array Representation)
Nhờ tính chất gần hoàn chỉnh, một đống $n$ phần tử có thể được ánh xạ 1-1 cực kỳ hoàn hảo vào một mảng một chiều $H[1..n]$ (đánh số từ chỉ số 1) mà **hoàn toàn không cần dùng bất kỳ con trỏ nào**:
- Gốc của đống nằm tại $H[1]$.
- Với nút tại chỉ số $i$ ($1 \le i \le n$):
  - Nút cha nằm tại chỉ số: $\lfloor i / 2 \rfloor$.
  - Nút con trái nằm tại chỉ số: $2i$ (nếu $2i \le n$).
  - Nút con phải nằm tại chỉ số: $2i + 1$ (nếu $2i + 1 \le n$).
  - Các nút nội (có ít nhất một con) có chỉ số từ $1$ đến $\lfloor n / 2 \rfloor$.
  - Tất cả các nút lá có chỉ số từ $\lfloor n / 2 \rfloor + 1$ đến $n$.

---

### 4.3. Thuật toán Xây dựng Đống từ dưới lên (HeapBottomUp / Heapify)
Để biến một mảng $H[1..n]$ lộn xộn bất kỳ thành một đống cực đại, thuật toán quét từ nút nội cuối cùng ($\lfloor n/2 \rfloor$) lùi dần về gốc ($1$). Tại mỗi nút, thực hiện thao tác **sàng xuống (sift-down)**: so sánh nút cha với nút con lớn nhất, nếu cha nhỏ hơn con lớn nhất thì đổi chỗ và tiếp tục trôi xuống dưới.

##### Mã giả chuẩn hóa:
```text
function: HeapBottomUp(H[1..n]): void
    input: H[1..n]: Array of comparable elements – mảng dữ liệu đầu vào.
           n: integer (n ≥ 1) – số lượng phần tử.
    output: H[1..n] thỏa mãn tính chất đống cực đại tại chỗ (in-place).

 1  for i = floor(n / 2) downto 1 do
 2      k = i – chỉ số nút đang xét sàng xuống.
 3      v = H[k] – lưu tạm giá trị nút cần sàng.
 4      is_heap = false
 5      while not is_heap and 2 * k <= n do
 6          j = 2 * k – con trái của k.
 7          if j < n then
 8              if H[j] < H[j + 1] then
 9                  j = j + 1 – j trỏ tới con lớn hơn giữa con trái và con phải.
10              end-if
11          end-if
12          if v >= H[j] then
13              is_heap = true – thỏa mãn tính chất đống, dừng sàng.
14          else
15              H[k] = H[j] – kéo con lớn hơn lên thay vị trí cha.
16              k = j – tiếp tục trôi xuống nhánh con.
17          end-if
18      end-while
19      H[k] = v – đặt phần tử vào đúng vị trí cân bằng.
20  end-for
```

#### Chứng minh toán học: Độ phức tạp thời gian tuyến tính $\Theta(n)$ của Heapify
Một sai lầm phổ biến là ước lượng: $n/2$ nút nội, mỗi nút sàng tốn $O(\log n) \implies O(n \log n)$. 
Tuy nhiên, phần lớn các nút nội nằm ở các tầng thấp gần lá (có chiều cao nhỏ, chỉ cần sàng 1 hoặc 2 bước)!
Gọi $h = \lfloor \log_2 n \rfloor$ là chiều cao của đống. Số lượng nút ở mức có chiều cao $k$ (cách lá $k$ bước) tối đa là $\lceil n / 2^{k+1} \rceil$.
Tổng số phép so sánh khóa trong trường hợp xấu nhất:
$$C(n) = \sum_{k=1}^{\lfloor \log_2 n \rfloor} 2 k \left\lceil \frac{n}{2^{k+1}} \right\rceil \le 2 n \sum_{k=1}^{\infty} \frac{k}{2^{k+1}} = n \sum_{k=1}^{\infty} \frac{k}{2^k}$$
Áp dụng công thức tổng cấp số lũy thừa $\sum_{k=1}^{\infty} \frac{k}{2^k} = 2$:
$$C(n) \le 2n \in \Theta(n)$$
**Kết luận kỳ diệu:** Xây dựng đống từ dưới lên chỉ tốn **thời gian tuyến tính $\Theta(n)$**!

---

### 4.4. Thuật toán Sắp xếp Đống (Heapsort)
Heapsort hoạt động theo hai giai đoạn hoàn hảo:
1. **Giai đoạn 1 (Heap Construction):** Dùng `HeapBottomUp` biến mảng thành đống cực đại trong $\Theta(n)$.
2. **Giai đoạn 2 (Maximum Deletions):** Lặp $n-1$ lần:
   - Đổi chỗ phần tử lớn nhất ở gốc $H[1]$ với phần tử cuối cùng của đống hiện tại $H[i]$.
   - Thu nhỏ kích thước đống đi 1 ($i - 1$).
   - Sàng nút gốc mới $H[1]$ xuống để tái lập tính chất đống trong thời gian $O(\log i)$.
   - Phần tử lớn nhất đã nằm cố định ở cuối mảng!

##### Mã giả chuẩn hóa:
```text
function: HeapSort(A[1..n]): void
    input: A[1..n]: Array of orderable elements.
           n: integer (n ≥ 1).
    output: A[1..n] được sắp xếp theo thứ tự không giảm tại chỗ.

 1  HeapBottomUp(A) – giai đoạn 1: dựng đống trong O(n).
 2  for i = n downto 2 do
 3      Swap(A[1], A[i]) – đưa phần tử lớn nhất về cuối mảng.
 4      – Sàng nút gốc A[1] xuống đống có kích thước mới là i - 1:
 5      k = 1
 6      v = A[k]
 7      is_heap = false
 8      while not is_heap and 2 * k <= i - 1 do
 9          j = 2 * k
10          if j < i - 1 and A[j] < A[j + 1] then
11              j = j + 1
12          end-if
13          if v >= A[j] then
14              is_heap = true
15          else
16              A[k] = A[j]
17              k = j
18          end-if
19      end-while
20      A[k] = v
21  end-for
```

#### Đánh giá toàn diện thuật toán Heapsort:
- **Độ phức tạp thời gian:**
  - Giai đoạn 1: $\Theta(n)$.
  - Giai đoạn 2: $\sum_{i=1}^{n-1} 2 \lfloor \log_2 i \rfloor = 2 n \log_2 n + O(n)$.
  - **Mọi trường hợp (Tốt nhất, Xấu nhất, Trung bình): Đều là $\Theta(n \log n)$**.
- **Bộ nhớ phụ trợ:** $O(1)$ (Sắp xếp tại chỗ - In-place).
- **Tính ổn định:** **KHÔNG ỔN ĐỊNH (Unstable)** do các phép đổi chỗ khoảng cách xa giữa gốc và lá.

---

## PHẦN II. GIẢI CHI TIẾT 100% BÀI TẬP EXERCISES 6.4 (BÀI 1 ĐẾN BÀI 11)

### Bài 6.4.1: Dựng đống từ mảng cho trước
> **Đề bài:**
> Cho dãy khóa sau: $1, 8, 6, 5, 3, 7, 4$.
> a. Dựng đống cực đại bằng thuật toán từ dưới lên (bottom-up algorithm).
> b. Dựng đống cực đại bằng thuật toán từ trên xuống (top-down / successive insertions).
> c. Hai phương pháp có luôn tạo ra cùng một đống hay không?

**Lời giải chi tiết:**
- **a. Thuật toán từ dưới lên (HeapBottomUp):**
  - Mảng ban đầu: $H = [1, 8, 6, 5, 3, 7, 4]$ với $n = 7$.
  - Nút nội cuối cùng là $\lfloor 7/2 \rfloor = 3$ (khóa $H[3] = 6$).
  - **Xét nút $i = 3$ (khóa 6):** Con trái $j = 6$ ($H[6] = 7$), con phải $j = 7$ ($H[7] = 4$). Con lớn hơn là $H[6] = 7 > 6 \implies$ Đổi chỗ 6 và 7.
    Mảng thành: $[1, 8, 7, 5, 3, 6, 4]$.
  - **Xét nút $i = 2$ (khóa 8):** Con trái $H[4] = 5$, con phải $H[5] = 3$. Con lớn hơn là $5 < 8 \implies$ Đã thỏa mãn, không đổi chỗ.
  - **Xét nút $i = 1$ (khóa 1 - gốc):**
    + Con trái $H[2] = 8$, con phải $H[3] = 7$. Con lớn hơn là $8 > 1 \implies$ Kéo 8 lên gốc, vị trí 2 nhận 1.
    + Tiếp tục sàng 1 tại vị trí 2: Con trái $H[4] = 5$, con phải $H[5] = 3$. Con lớn hơn là $5 > 1 \implies$ Kéo 5 lên vị trí 2, vị trí 4 nhận 1.
  - **Kết quả đống từ dưới lên:**
    $$H_{\text{bottom-up}} = [8, 5, 7, 1, 3, 6, 4]$$

- **b. Thuật toán từ trên xuống (Chèn liên tiếp - Top-down):**
  - Chèn 1: $[1]$.
  - Chèn 8: $[1, 8] \to 8 > 1 \implies [8, 1]$.
  - Chèn 6: $[8, 1, 6]$.
  - Chèn 5: $[8, 1, 6, 5] \to 5 > 1 \implies [8, 5, 6, 1]$.
  - Chèn 3: $[8, 5, 6, 1, 3]$.
  - Chèn 7: $[8, 5, 6, 1, 3, 7] \to 7 > 6 \implies [8, 5, 7, 1, 3, 6]$.
  - Chèn 4: $[8, 5, 7, 1, 3, 6, 4]$.
  - **Kết quả đống từ trên xuống:**
    $$H_{\text{top-down}} = [8, 5, 7, 1, 3, 6, 4]$$

- **c. Trả lời câu hỏi (c): KHÔNG.**
  - Mặc dù trong ví dụ trên hai đống ngẫu nhiên trùng nhau, nhưng trên trường hợp tổng quát, **hai thuật toán KHÔNG LUÔN tạo ra cùng một đống**.
  - *Phản ví dụ chứng minh:* Xét dãy $1, 2, 3$.
    + Dưới lên: $H = [1, 2, 3] \implies$ xét $i = 1$, con lớn hơn là 3, đổi chỗ 1 và 3 $\implies [3, 2, 1]$.
    + Trên xuống: Chèn 1 $[1] \to$ chèn 2 $[2, 1] \to$ chèn 3 $[2, 1, 3] \to$ trôi lên $[3, 1, 2]$.
    + Hai kết quả $[3, 2, 1] \ne [3, 1, 2]$ hoàn toàn khác nhau về vị trí con trái và con phải!

---

### Bài 6.4.2: Thuật toán kiểm tra một mảng có phải là Đống
> **Đề bài:**
> Thiết kế thuật toán hiệu quả $O(n)$ để kiểm tra xem một mảng số thực $A[1..n]$ cho trước có thỏa mãn tính chất đống cực đại hay không.

**Lời giải chi tiết:**
- Vì mảng biểu diễn một cây gần hoàn chỉnh, tính chất hình học luôn được thỏa mãn tự động. Ta chỉ cần kiểm tra **tính chất trội của cha** tại tất cả các nút nội từ $i = 1$ đến $\lfloor n/2 \rfloor$.
- Với mỗi nút nội $i$:
  - Con trái $2i \le n$: Bắt buộc $A[i] \ge A[2i]$.
  - Con phải $2i + 1 \le n$: Bắt buộc $A[i] \ge A[2i + 1]$.
  - Nếu có bất kỳ điều kiện nào bị vi phạm: Trả về `false`.
- **Mã giả:**
```text
function: IsMaxHeap(A[1..n]): Boolean
    input: A[1..n]: Array of real numbers (n ≥ 1).
    output: true nếu A là đống cực đại, false nếu không.

 1  for i = 1 to floor(n / 2) do
 2      if A[i] < A[2 * i] then
 3          return false
 4      end-if
 5      if 2 * i + 1 <= n and A[i] < A[2 * i + 1] then
 6          return false
 7      end-if
 8  end-for
 9  return true.
```
- **Độ phức tạp:** Vòng lặp chạy $\lfloor n/2 \rfloor$ lần, mỗi lần tối đa 2 phép so sánh $\implies$ Số phép so sánh tối đa là $n - 1 \in \Theta(n)$.

---

### Bài 6.4.3: Số nút tối đa và tối thiểu của Đống có chiều cao $h$
> **Đề bài:**
> a. Một đống có chiều cao $h$ ($h \ge 0$) có thể chứa tối thiểu bao nhiêu nút và tối đa bao nhiêu nút?
> b. Từ đó suy ra công thức biểu diễn chiều cao $h$ theo số nút $n$.

**Lời giải chi tiết:**
- **a. Xác định số nút cực trị:**
  - **Số nút tối đa $n_{\max}$:** Đạt được khi tất cả các mức từ 0 đến $h$ đều được điền đầy đủ (cây nhị phân hoàn chỉnh):
    $$n_{\max} = \sum_{i=0}^h 2^i = 2^{h+1} - 1$$
  - **Số nút tối thiểu $n_{\min}$:** Đạt được khi các mức từ 0 đến $h-1$ được điền đầy đủ, và mức cuối cùng $h$ chỉ có duy nhất 1 nút lá ở tận cùng bên trái:
    $$n_{\min} = (2^h - 1) + 1 = 2^h$$
- **b. Công thức chiều cao $h$ theo $n$:**
  Từ $2^h \le n \le 2^{h+1} - 1 < 2^{h+1}$, lấy logarit cơ số 2 các vế:
  $$h \le \log_2 n < h + 1 \iff h = \lfloor \log_2 n \rfloor$$

---

### Bài 6.4.4: Chứng minh công thức tổng số phép so sánh của Heapify
> **Đề bài:**
> Chứng minh bằng quy nạp toán học hoặc khai triển đại số rằng:
> $$\sum_{i=1}^h i 2^{h-i} = 2^{h+1} - h - 2 \quad \forall h \ge 1$$

**Lời giải chi tiết:**
- **Cách 1: Khai triển đại số:**
  Đặt $S = \sum_{i=1}^h i 2^{h-i} = 1 \cdot 2^{h-1} + 2 \cdot 2^{h-2} + \dots + (h-1) \cdot 2^1 + h \cdot 2^0$.
  Chia cả hai vế cho 2:
  $$\frac{S}{2} = 1 \cdot 2^{h-2} + 2 \cdot 2^{h-3} + \dots + (h-1) \cdot 2^0 + \frac{h}{2}$$
  Lấy phương trình trên trừ đi phương trình dưới:
  $$S - \frac{S}{2} = \frac{S}{2} = 2^{h-1} + 2^{h-2} + 2^{h-3} + \dots + 2^0 - \frac{h}{2}$$
  Nhận thấy $2^{h-1} + \dots + 2^0 = 2^h - 1$. Do đó:
  $$\frac{S}{2} = (2^h - 1) - \frac{h}{2} = 2^h - \frac{h}{2} - 1$$
  Nhân cả hai vế với 2:
  $$S = 2 \cdot 2^h - h - 2 = 2^{h+1} - h - 2$$
  (Điều phải chứng minh).

---

### Bài 6.4.5: Tìm phần tử nhỏ nhất trong Đống cực đại
> **Đề bài:**
> a. Trong một đống cực đại (max-heap) gồm $n$ phần tử, phần tử nhỏ nhất có thể nằm ở những vị trí nào? Thuật toán tìm phần tử nhỏ nhất tốn thời gian bao nhiêu?
> b. Trình bày thuật toán xóa một phần tử bất kỳ tại chỉ số $i$ trong đống.

**Lời giải chi tiết:**
- **a. Vị trí phần tử nhỏ nhất:**
  - Theo tính chất max-heap, nút cha luôn lớn hơn hoặc bằng con. Do đó phần tử nhỏ nhất **không bao giờ có thể là một nút nội** (vì nếu là nút nội thì nó phải lớn hơn con của nó, mâu thuẫn).
  - Do đó, phần tử nhỏ nhất **bắt buộc phải nằm tại một trong các nút lá**!
  - Các nút lá nằm ở các chỉ số từ $\lfloor n/2 \rfloor + 1$ đến $n$.
  - Thuật toán tìm: Quét tuyến tính qua $\lceil n/2 \rceil$ phần tử lá để tìm giá trị nhỏ nhất $\implies$ Thời gian chạy: $\Theta(n)$.
- **b. Thuật toán xóa một phần tử bất kỳ tại chỉ số $i$ ($1 \le i \le n$):**
  1. Gán giá trị phần tử cuối cùng của đống $H[n]$ vào vị trí $H[i]$: $H[i] = H[n]$.
  2. Giảm kích thước đống đi 1: $n = n - 1$.
  3. So sánh $H[i]$ với cha và các con của nó:
     - Nếu $H[i] > H[\lfloor i/2 \rfloor]$: Sàng lên (sift-up) về phía gốc.
     - Nếu $H[i] < \max(H[2i], H[2i+1])$: Sàng xuống (sift-down) về phía lá.
  4. Cả sàng lên và sàng xuống đều tốn tối đa $O(\log n)$ phép so sánh.
  - Tổng thời gian: $O(\log n)$.

---

### Bài 6.4.6: So sánh hiệu quả ba cấu trúc dữ liệu cho Hàng đợi ưu tiên (Priority Queue)
> **Đề bài:**
> Điền vào bảng so sánh độ phức tạp thời gian của ba thao tác cơ bản: Tìm Max (`FindMax`), Xóa Max (`DeleteMax`), và Thêm mới (`Insert`) khi cài đặt bằng:
> 1. Mảng chưa sắp xếp.
> 2. Mảng đã sắp xếp.
> 3. Cấu trúc Đống cực đại (Max-Heap).

**Bảng so sánh chi tiết:**

| Cấu trúc dữ liệu | `FindMax` | `DeleteMax` | `Insert` | Nhận xét tổng quan |
| :--- | :---: | :---: | :---: | :--- |
| **Mảng chưa sắp xếp** | $\Theta(n)$ | $\Theta(n)$ | $\Theta(1)$ | Thêm cực nhanh, lấy Max rất chậm |
| **Mảng đã sắp xếp** | $\Theta(1)$ | $\Theta(1)$ | $\Theta(n)$ | Lấy Max tức thì, chèn tốn dời mảng |
| **Đống cực đại (Heap)** | $\mathbf{\Theta(1)}$ | $\mathbf{\Theta(\log n)}$ | $\mathbf{\Theta(\log n)}$ | **Cân bằng hoàn hảo, tối ưu cho mọi tác vụ** |

---

### Bài 6.4.7: Mô phỏng Heapsort từng bước
> **Đề bài:**
> Thực hiện thuật toán Heapsort để sắp xếp mảng sau theo thứ tự tăng dần:
> $$C, O, M, P, U, T, E, R$$

**Lời giải chi tiết:**
- Chuyển đổi chữ cái theo thứ tự bảng chữ cái:
  $C(3), O(15), M(13), P(16), U(21), T(20), E(5), R(18)$. Mảng có $n = 8$.
- **Giai đoạn 1: Dựng đống cực đại:**
  - Quét từ $i = 4$ về $1$:
    - $i = 4$ ($P=16$): con trái là $R=18 \implies$ đổi chỗ $P$ và $R$.
    - $i = 3$ ($M=13$): con trái $T=20$, con phải $E=5 \implies$ đổi chỗ $M$ và $T$.
    - $i = 2$ ($O=15$): con trái $R=18$, con phải $U=21 \implies$ đổi chỗ $O$ và $U$.
    - $i = 1$ ($C=3$): hai con là $U=21$ và $T=20 \implies$ đổi $C$ với $U$. Sàng tiếp $C$ tại vị trí 2: hai con là $R=18$ và $O=15 \implies$ đổi $C$ với $R$. Sàng tiếp $C$ tại vị trí 4: con trái là $P=16 \implies$ đổi $C$ với $P$.
  - Đống cực đại thu được: $[U, R, T, P, O, M, E, C]$ (tương ứng: $21, 18, 20, 16, 15, 13, 5, 3$).
- **Giai đoạn 2: Lần lượt xóa Max và đưa về cuối:**
  - Đổi $U$ với $C$, sàng $C \implies [T, R, M, P, O, C, E \mid U]$.
  - Đổi $T$ với $E$, sàng $E \implies [R, P, M, E, O, C \mid T, U]$.
  - Đổi $R$ với $C$, sàng $C \implies [P, O, M, E, C \mid R, T, U]$.
  - Đổi $P$ với $C$, sàng $C \implies [O, E, M, C \mid P, R, T, U]$.
  - Đổi $O$ với $C$, sàng $C \implies [M, E, C \mid O, P, R, T, U]$.
  - Đổi $M$ với $C$, sàng $C \implies [E, C \mid M, O, P, R, T, U]$.
  - Đổi $E$ với $C \implies [C, E, M, O, P, R, T, U]$.
- **Mảng sau khi sắp xếp:** $C, E, M, O, P, R, T, U$.

---

### Bài 6.4.8: Tính không ổn định của Heapsort
> **Đề bài:**
> Chứng minh rằng Heapsort là thuật toán sắp xếp không ổn định (unstable) bằng một phản ví dụ tối thiểu.

**Lời giải chi tiết:**
- Xét mảng gồm 3 phần tử với hai khóa bằng nhau mang nhãn phân biệt:
  $$A = [2_a, 2_b, 1]$$
  Trong mảng ban đầu, $2_a$ xuất hiện trước $2_b$.
- Áp dụng Heapsort:
  1. Dựng đống: $A[1] = 2_a$, hai con là $A[2] = 2_b$ và $A[3] = 1$. Vì $2_a \ge 2_b$ và $2_a \ge 1$, mảng đã là đống cực đại hợp lệ.
  2. Giai đoạn 2 (Bước 1): Đổi chỗ phần tử gốc $A[1]$ với phần tử cuối cùng $A[3]$:
     $$A[1] \leftrightarrow A[3] \implies A = [1, 2_b, 2_a]$$
  3. Kích thước đống còn 2: $[1, 2_b]$. Gốc là 1, con là $2_b \implies$ đổi chỗ 1 và $2_b$:
     $$A = [2_b, 1, 2_a]$$
  4. Bước 2: Đổi chỗ gốc $A[1]$ với $A[2]$:
     $$A = [1, 2_b, 2_a]$$
- **Kết quả:** Mảng sắp xếp là $[1, 2_b, 2_a]$, trong đó $2_b$ bị đảo lên đứng trước $2_a$!
- **Kết luận:** Heapsort là thuật toán **không ổn định (unstable)**.

---

### Bài 6.4.9: So sánh cài đặt Đống bằng Mảng và Con trỏ
> **Đề bài:**
> Tại sao người ta hầu như luôn luôn cài đặt Đống bằng mảng mà không dùng cấu trúc nút liên kết với các con trỏ `left`, `right`, `parent`?

**Lời giải chi tiết:**
1. **Tiết kiệm bộ nhớ vượt bậc:**
   - Dùng mảng không tốn bất kỳ byte nhớ nào cho con trỏ (con trỏ tốn 8 bytes trên hệ 64-bit cho mỗi liên kết, với 3 con trỏ là 24 bytes/nút).
2. **Truy cập trực tiếp trong $O(1)$:**
   - Tìm cha và con chỉ bằng phép dịch bit: $\lfloor i/2 \rfloor = i \gg 1$, $2i = i \ll 1$, cực kỳ nhanh ở cấp độ phần cứng.
3. **Hiệu năng bộ nhớ đệm (Cache Locality):**
   - Mảng nằm liên tục trên các ô nhớ, tận dụng tối đa cơ chế nạp đường dẫn bộ nhớ đệm (Spatial Locality) của CPU, nhanh hơn gấp nhiều lần so với các nút liên kết phân tán rải rác trên vùng nhớ Heap.

---

### Bài 6.4.10: So sánh Heapsort và Selection Sort
> **Đề bài:**
> Tại sao Heapsort có thể được coi là phiên bản nâng cấp tối thượng của thuật toán Sắp xếp chọn (Selection Sort)?

**Lời giải chi tiết:**
- Cả hai thuật toán đều hoạt động trên cùng một triết lý: Chia mảng thành phần chưa sắp và phần đã sắp, liên tục tìm phần tử lớn nhất trong phần chưa sắp và đưa nó về vị trí cuối cùng.
- Sự khác biệt quyết định nằm ở **cấu trúc dữ liệu tìm cực trị**:
  - Selection Sort: Giữ phần chưa sắp trong mảng lộn xộn, mỗi lần tìm Max tốn quét tuyến tính $\Theta(k) \implies$ Tổng thời gian $\sum k \in \Theta(n^2)$.
  - Heapsort: Biến đổi phần chưa sắp thành Đống (Representation Change), mỗi lần lấy và xóa Max chỉ tốn $\Theta(\log k) \implies$ Tổng thời gian $\sum \log k \in \Theta(n \log n)$.

---

### Bài 6.4.11: Đống $d$-phân (d-ary Heap)
> **Đề bài:**
> Đống $d$-phân ($d$-ary heap) là tổng quát hóa của đống nhị phân, trong đó mỗi nút có tối đa $d$ con ($d \ge 2$).
> a. Nếu đống $d$-phân được lưu trong mảng $H[1..n]$, hãy xác định công thức tính chỉ số các con và chỉ số nút cha của nút tại vị trí $i$.
> b. Chiều cao của đống $d$-phân gồm $n$ phần tử là bao nhiêu?
> c. Thao tác nào sẽ nhanh hơn và thao tác nào sẽ chậm hơn khi $d$ tăng lên?

**Lời giải chi tiết:**
- **a. Công thức chỉ số cha và con trong đống $d$-phân (đánh số từ 1):**
  - Các nút con của nút $i$ nằm tại các chỉ số liên tiếp:
    $$\text{Child}_k(i) = d(i - 1) + 1 + k \quad (k = 1, 2, \dots, d)$$
    Cụ thể: con đầu tiên là $d(i-1) + 2$, con cuối cùng là $d \cdot i + 1$.
  - Nút cha của nút $i$ ($i > 1$) nằm tại chỉ số:
    $$\text{Parent}(i) = \left\lfloor \frac{i - 2}{d} \right\rfloor + 1$$
- **b. Chiều cao của đống:**
  $$h \approx \lfloor \log_d n \rfloor = \frac{\log_2 n}{\log_2 d}$$
  Chiều cao giảm đi theo hệ số $\log_2 d$.
- **c. Đánh giá tốc độ:**
  - Thao tác `Insert` (sàng lên): **Nhanh hơn**, vì số mức phải trôi lên giảm xuống chỉ còn $\log_d n$, mỗi bước chỉ so sánh với 1 nút cha duy nhất.
  - Thao tác `DeleteMax` (sàng xuống): **Chậm hơn**, vì tại mỗi tầng, ta phải tìm phần tử lớn nhất trong số $d$ con (tốn $d - 1$ phép so sánh). Tổng số phép so sánh khi sàng xuống là $(d - 1) \log_d n = \frac{d - 1}{\log_2 d} \log_2 n$, tăng khi $d \ge 4$.
  *(Ứng dụng: Đống $d$-phân với $d = 3$ hoặc $d = 4$ rất phổ biến trong thuật toán Dijkstra vì số lần giảm khóa/chèn nhiều hơn số lần xóa min).*
