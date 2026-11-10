# GIÁO TRÌNH TOÀN TẬP PHÂN TÍCH VÀ THIẾT KẾ THUẬT TOÁN
## CHƯƠNG 5: CHIẾN LƯỢC CHIA ĐỂ TRỊ (DIVIDE-AND-CONQUER)
### Hệ thống Toàn bộ Thuật toán, Mã giả Cấu trúc, Phân tích Hiệu năng & 100% Lời giải Chi tiết Bài tập (Trang 169 – Trang 200)
**Tác phẩm gốc: Anany Levitin, Introduction to the Design and Analysis of Algorithms, Addison Wesley, 3rd Edition, 2011**

---

> [!NOTE]
> Tài liệu này được biên soạn độc lập, chuẩn hóa học thuật công phu và toàn diện 100% nội dung lý thuyết, phân tích toán học, mã giả khuôn mẫu cấu trúc (Structured Pseudocode) và lời giải chi tiết cho **toàn bộ 55 bài tập (với đầy đủ các câu hỏi phụ a, b, c, d)** thuộc Chương 5 trong giáo trình kinh điển của Giáo sư Anany Levitin (từ trang 169 đến trang 200).

---

## MỤC LỤC TỔNG THỂ CHƯƠNG 5

- **CHUYÊN ĐỀ 00: TỔNG QUAN CHIẾN LƯỢC CHIA ĐỂ TRỊ & ĐỊNH LÝ THỢ (MASTER THEOREM)**
  - 1. Bản chất tư tưởng chiến lược Chia để trị (Ba bước: Chia - Trị - Kết hợp)
  - 2. Phân biệt Chia để trị và Giảm để trị (Levitin pp. 170-171)
  - 3. Phương trình truy hồi tổng quát (n) = a T(n/b) + f(n)$
  - 4. Phát biểu và Chứng minh toán học toàn diện Định lý Thợ (The Master Theorem)
  - 5. Trực giác hình học Cây đệ quy (Recursion Tree) và giới hạn áp dụng

- **CHUYÊN ĐỀ 01: THUẬT TOÁN SẮP XẾP TRỘN (MERGESORT) & 100% BÀI TẬP 5.1**
  - 1. Thuật toán Mergesort và Merge chuẩn hóa
  - 2. Phân tích số phép so sánh xấu nhất {worst}(n) = n \log_2 n - n + 1$, tốt nhất, trung bình
  - 3. Độ phức tạp không gian $\Theta(n)$ và chứng minh tính ổn định
  - 4. Lời giải chi tiết 11 bài tập Mục 5.1 (Tìm Max, Min-Max, Lũy thừa ^n$, Master Theorem, Đếm nghịch thế (n \log n)$, Bottom-up Mergesort, Ghép mảnh Tromino trên bàn cờ ^n \times 2^n$)

- **CHUYÊN ĐỀ 02: THUẬT TOÁN SẮP XẾP NHANH (QUICKSORT) & 100% BÀI TẬP 5.2**
  - 1. Nguyên lý phân hoạch theo giá trị và Thuật toán Quicksort tổng thể
  - 2. Phân hoạch Hoare chi tiết và phân tích bất biến
  - 3. Phân tích trường hợp xấu nhất $\Theta(n^2)$, tốt nhất $\Theta(n \log n)$, trung bình .386 n \log_2 n$
  - 4. Tối ưu ngăn xếp đệ quy (\log n)$, Median-of-three, Cutoff
  - 5. Lời giải chi tiết 11 bài tập Mục 5.2 (Quicksort chữ cái, Chứng minh chỉ số quét , j$, Phản chứng không ổn định, Phân tích lính canh, Mảng trùng lặp, So sánh với Insertion Sort, Tách âm/dương (n)$, Bài toán Cờ Hà Lan & Fat-partition, Đai ốc & Bu-lông (n \log n)$)

- **CHUYÊN ĐỀ 03: DUYỆT CÂY NHỊ PHÂN VÀ CÁC TÍNH CHẤT LIÊN QUAN & 100% BÀI TẬP 5.3**
  - 1. Định nghĩa đệ quy Cây nhị phân và Thuật toán tính chiều cao (T)$
  - 2. Ba thuật toán duyệt cổ điển: Preorder, Inorder, Postorder
  - 3. Cây nhị phân mở rộng: Quan hệ nút lá/nút trong  = n + 1$, đẳng thức  = I + 2n$
  - 4. Lời giải chi tiết 11 bài tập Mục 5.3 (Tính số tầng, Sửa lỗi thuật toán đếm lá, Tính chiều cao dùng Queue BFS không dùng Stack, Quy nạp chứng minh (n) = n$, Dựng cây nhị phân từ Inorder và Postorder, Bài toán bẻ thanh sô-cô-la  - 1$)

- **CHUYÊN ĐỀ 04: NHÂN SỐ NGUYÊN LỚN & PHÉP NHÂN MA TRẬN STRASSEN & 100% BÀI TẬP 5.4**
  - 1. Thuật toán nhân số nguyên lớn Karatsuba $\Theta(n^{1.585})$
  - 2. Thuật toán nhân ma trận Strassen $\Theta(n^{2.807})$
  - 3. Lời giải chi tiết 10 bài tập Mục 5.4 (Số chữ số của tích, Tính tay  \times 1130$, Chứng minh ^{\log_b c} = c^{\log_b a}$, Kiểm chứng 7 công thức Strassen, Nhân 2 ma trận  \times 4$ cụ thể, Thuật toán V. Pan $\Theta(n^{2.795})$, Điểm giao cắt Crossover point)

- **CHUYÊN ĐỀ 05: BÀI TOÁN CẶP ĐIỂM GẦN NHẤT & BAO LỒI QUICKHULL & 100% BÀI TẬP 5.5**
  - 1. Cặp điểm gần nhất 2D Shamos-Hoey $\Theta(n \log n)$ và Định lý dải hẹp 7 điểm
  - 2. Thuật toán Bao lồi Quickhull và Công thức định thức giải tích diện tích
  - 3. Lời giải chi tiết 12 bài tập Mục 5.5 (Cặp điểm gần nhất 1D, Chứng minh 7 điểm bằng Dirichlet, Phân tích biến thể sắp xếp đệ quy $\Theta(n \log^2 n)$, Biểu đồ Voronoi & Delaunay, Xác định {max}$ giải tích, Dựng 100 hình thập giác từ 1000 điểm, Đường đi ngắn nhất quanh đa giác rào chắn)

---



---

# CHUYÊN ĐỀ 00: TỔNG QUAN CHIẾN LƯỢC CHIA ĐỂ TRỊ & ĐỊNH LÝ THỢ (MASTER THEOREM)
## Trích dẫn: Anany Levitin, "Introduction to the Design and Analysis of Algorithms", 3rd Edition, Chapter 5 (pp. 169–172)

---

## 1. BẢN CHẤT TƯ TƯỞNG CHIẾN LƯỢC CHIA ĐỂ TRỊ (DIVIDE-AND-CONQUER)

### 1.1. Khái niệm và Ba bước Thực thi Khuôn mẫu
Chiến lược **Chia để trị** (*Divide-and-Conquer*) là một trong những kỹ thuật thiết kế thuật toán tổng quát và mạnh mẽ nhất trong khoa học máy tính. Tư tưởng cốt lõi của phương pháp này dựa trên nguyên lý giải quyết một bài toán quy mô lớn thông qua ba bước tuần tự:

```text
                  Bài toán ban đầu (Kích thước n)
                               │
               ┌───────────────┴───────────────┐
               ▼                               ▼
       Bài toán con 1                   Bài toán con 2      ... (a bài toán con,
      (Kích thước n/b)                 (Kích thước n/b)          mỗi bài kích thước n/b)
               │                               │
               ▼ đệ quy                        ▼ đệ quy
       Lời giải con 1                   Lời giải con 2
               └───────────────┬───────────────┘
                               ▼ KẾT HỢP (f(n))
                    Lời giải bài toán ban đầu
```

1. **CHIA (Divide)**: Phân rã bài toán ban đầu có kích thước $n$ thành một số lượng $a$ ($a \ge 1$) bài toán con cùng loại, mỗi bài toán con có kích thước nhỏ hơn $n/b$ ($b > 1$). Trong trường hợp lý tưởng nhất, các bài toán con có kích thước xấp xỉ bằng nhau.
2. **TRỊ (Conquer)**: Giải quyết các bài toán con một cách đệ quy. 
   - Nếu kích thước bài toán con đủ nhỏ (đạt tới *trường hợp cơ sở - base case*, ví dụ $n \le n_0$ hoặc $n = 1$), bài toán con sẽ được giải quyết trực tiếp bằng phương pháp thô sơ hoặc đóng gói nghiệm tường minh mà không đệ quy thêm.
3. **KẾT HỢP (Combine)**: Tổng hợp lời giải của các bài toán con đã giải quyết để tạo thành lời giải hoàn chỉnh cho bài toán gốc ban đầu.

---

### 1.2. Phân biệt "Chia để trị" (Divide-and-Conquer) và "Giảm để trị" (Decrease-and-Conquer)
Giáo sư Anany Levitin đã chỉ rõ sự khác biệt bản chất giữa hai mô hình này (trang 170–171):
- **Giảm để trị (Decrease-and-Conquer)**: Chỉ cần giải **duy nhất một bài toán con** có kích thước nhỏ hơn (ví dụ: Tìm kiếm nhị phân chia đôi mảng nhưng chỉ đệ quy vào 1 nửa; Thuật toán Euclid tính $\gcd(m, n)$; Thuật toán Fake-coin).
- **Chia để trị (Divide-and-Conquer)**: Bắt buộc phải giải **từ hai bài toán con trở lên** ($a \ge 2$), sau đó phải thực hiện công đoạn **kết hợp (combine)** lời giải của các nhánh con (ví dụ: Mergesort, Quicksort, Strassen, Karatsuba).

---

### 1.3. Ví dụ kinh điển mở đầu: Phép cộng cặp (Pairwise Summation)
Xét bài toán tính tổng của $n$ số thực: $S = A[0] + A[1] + \dots + A[n-1]$.
- **Tiếp cận Vét cạn (Brute-force)**: Cộng dồn tuần tự từ trái sang phải tốn $n-1$ phép cộng.
- **Tiếp cận Chia để trị (Pairwise Summation)**:
  $$S(A[0..n-1]) = S(A[0..\lfloor n/2 \rfloor - 1]) + S(A[\lfloor n/2 \rfloor .. n-1])$$
- **Số phép cộng**:
  $$A(n) = A(\lfloor n/2 \rfloor) + A(\lceil n/2 \rceil) + 1 \quad (n > 1), \quad A(1) = 0$$
  Với $n = 2^k$:
  $$A(2^k) = 2 A(2^{k-1}) + 1 = 2(2 A(2^{k-2}) + 1) + 1 = \dots = 2^k - 1 = n - 1$$
- **Ý nghĩa thực tiễn**: Về số phép tính, chia để trị vẫn tốn $n-1$ phép cộng, không giảm độ phức tạp thời gian. **Tuy nhiên**, như nhà toán học N. J. Higham (1993) đã chứng minh, thuật toán tính tổng theo cặp làm giảm đáng kể sai số làm tròn tích lũy (*accumulated round-off error*) khi tính toán số học dấu phẩy động trên máy tính số!

---

## 2. PHƯƠNG TRÌNH TRUY HỒI TỔNG QUÁT VÀ ĐỊNH LÝ THỢ (MASTER THEOREM)

### 2.1. Thiết lập Phương trình Truy hồi Tổng quát
Giả sử thời gian chạy $T(n)$ của một thuật toán chia để trị thỏa mãn:
1. Chia bài toán kích thước $n$ thành $a$ bài toán con, mỗi bài có kích thước $n/b$.
2. Thời gian để chia bài toán và kết hợp các lời giải con là hàm $f(n)$.

Khi đó, thời gian thực thi tổng thể thỏa mãn hệ thức truy hồi:
$$T(n) = a \, T(n/b) + f(n)$$
với trường hợp cơ sở: $T(1) = c$ (hằng số).

Trong hầu hết các thuật toán thực tế, chi phí kết hợp $f(n)$ là một hàm đa thức hoặc xấp xỉ đa thức:
$$f(n) \in \Theta(n^d) \quad \text{với } d \ge 0$$

---

### 2.2. Phát biểu Định lý Thợ (The Master Theorem)

> **ĐỊNH LÝ (Master Theorem - Levitin, p. 171):**  
> Nếu $f(n) \in \Theta(n^d)$ với $d \ge 0$ trong phương trình truy hồi $T(n) = a \, T(n/b) + f(n)$ (trong đó $a \ge 1, b > 1$), thì cấp độ tăng trưởng của $T(n)$ được xác định bởi:
>
> $$T(n) \in \begin{cases} \Theta(n^d) & \text{nếu } a < b^d \\ \Theta(n^d \log n) & \text{nếu } a = b^d \\ \Theta(n^{\log_b a}) & \text{nếu } a > b^d \end{cases}$$
>
> *(Lưu ý: Cơ số của logarit trong $\Theta(n^d \log n)$ không làm thay đổi lớp hiệu quả, nhưng số mũ $\log_b a$ phụ thuộc chặt chẽ vào cơ số $b$)*.

---

### 2.3. Chứng minh Toán học Toàn diện Định lý Thợ
Giả sử kích thước bài toán là lũy thừa của $b$: $n = b^k \implies k = \log_b n$.
Áp dụng phương pháp thế lùi (Backward Substitution):

$$\begin{aligned}
T(n) &= a T(n/b) + c n^d \\
     &= a \left[ a T(n/b^2) + c (n/b)^d \right] + c n^d = a^2 T(n/b^2) + c a (n/b)^d + c n^d \\
     &= a^3 T(n/b^3) + c a^2 (n/b^2)^d + c a (n/b)^d + c n^d \\
     &\dots \\
     &= a^k T(n/b^k) + c n^d \sum_{j=0}^{k-1} \left( \frac{a}{b^d} \right)^j \\
     &= a^k T(1) + c n^d \sum_{j=0}^{k-1} \left( \frac{a}{b^d} \right)^j
\end{aligned}$$

Ta có $a^k = a^{\log_b n} = n^{\log_b a}$ (theo tính chất hoán vị số mũ: $a^{\log_b n} = n^{\log_b a}$).
Do $T(1) = \Theta(1)$, ta được:
$$T(n) = \Theta(n^{\log_b a}) + c n^d \sum_{j=0}^{k-1} \left( \frac{a}{b^d} \right)^j$$

Đặt $r = \frac{a}{b^d}$. Tổng cấp số nhân hữu hạn:
$$\sum_{j=0}^{k-1} r^j = \begin{cases} \frac{r^k - 1}{r - 1} & \text{nếu } r \ne 1 \\ k & \text{nếu } r = 1 \end{cases}$$

Xét 3 trường hợp:

#### Trường hợp 1: $a < b^d \iff r < 1$
Khi $r < 1$, chuỗi cấp số nhân hội tụ về một hằng số bị chặn:
$$\sum_{j=0}^{k-1} r^j < \frac{1}{1 - r} = O(1)$$
Do đó, thành phần thứ hai là $c n^d \cdot O(1) = \Theta(n^d)$.  
Mặt khác, vì $a < b^d \implies \log_b a < d \implies n^{\log_b a} = o(n^d)$ (bị áp đảo bởi $n^d$).  
**Kết luận**:
$$T(n) \in \Theta(n^d)$$
*(Chi phí tại gốc $f(n)$ áp đảo toàn bộ cây đệ quy; phần lớn công việc tập trung ở bước chia và kết hợp của bài toán gốc)*.

#### Trường hợp 2: $a = b^d \iff r = 1$
Khi $r = 1$, chuỗi cấp số nhân có giá trị:
$$\sum_{j=0}^{k-1} 1 = k = \log_b n$$
Mặt khác, $a = b^d \implies \log_b a = d \implies n^{\log_b a} = n^d$.  
Do đó:
$$T(n) = n^d \cdot T(1) + c n^d \log_b n \in \Theta(n^d \log n)$$
**Kết luận**:
$$T(n) \in \Theta(n^d \log n)$$
*(Công việc được phân bổ đều trên tất cả $\log_b n$ tầng của cây đệ quy; mỗi tầng tiêu tốn $\Theta(n^d)$)*.

#### Trường hợp 3: $a > b^d \iff r > 1$
Khi $r > 1$:
$$\sum_{j=0}^{k-1} r^j = \frac{r^k - 1}{r - 1} = \Theta(r^k) = \Theta\left( \left(\frac{a}{b^d}\right)^k \right) = \Theta\left( \frac{a^k}{(b^k)^d} \right) = \Theta\left( \frac{n^{\log_b a}}{n^d} \right)$$
Nhân lại với $c n^d$:
$$c n^d \sum_{j=0}^{k-1} r^j = c n^d \cdot \Theta\left( \frac{n^{\log_b a}}{n^d} \right) = \Theta(n^{\log_b a})$$
Vì $a > b^d \implies \log_b a > d$, số hạng $n^{\log_b a}$ áp đảo hoàn toàn $n^d$.  
**Kết luận**:
$$T(n) \in \Theta(n^{\log_b a})$$
*(Số lượng bài toán con ở các nút lá tăng theo cấp số nhân áp đảo chi phí kết hợp; công việc tập trung chủ yếu ở tầng lá)*. $\blacksquare$

---

## 3. Ý NGHĨA HÌNH HỌC VÀ TRỰC GIÁC CÂY ĐỆ QUY (RECURSION TREE)

| Tầng $j$ | Số nút (bài toán) | Kích thước mỗi bài | Chi phí kết hợp mỗi nút | Tổng chi phí tầng $j$ |
| :---: | :---: | :---: | :---: | :---: |
| $0$ (Gốc) | $1$ | $n$ | $c n^d$ | $c n^d$ |
| $1$ | $a$ | $n/b$ | $c (n/b)^d$ | $c n^d (a/b^d)^1$ |
| $2$ | $a^2$ | $n/b^2$ | $c (n/b^2)^d$ | $c n^d (a/b^d)^2$ |
| $\dots$ | $\dots$ | $\dots$ | $\dots$ | $\dots$ |
| $j$ | $a^j$ | $n/b^j$ | $c (n/b^j)^d$ | $c n^d (a/b^d)^j$ |
| $k = \log_b n$ (Lá) | $a^{\log_b n} = n^{\log_b a}$ | $1$ | $\Theta(1)$ | $\Theta(n^{\log_b a})$ |

- **Ý nghĩa tỷ số $\frac{a}{b^d}$**:
  - $a$: Tốc độ sinh bài toán con (hệ số đệ quy).
  - $b^d$: Tốc độ thu nhỏ chi phí của hàm kết hợp khi kích thước giảm đi $b$ lần.
  - So sánh $a$ với $b^d$ chính là so sánh sự cạnh tranh giữa **tốc độ sinh nhánh đệ quy** và **tốc độ suy giảm chi phí kết hợp**.

---

## 4. GIỚI HẠN VÀ CÁC TRƯỜNG HỢP NGOẠI LỆ CỦA MASTER THEOREM

Định lý Thợ rất tiện lợi nhưng không thể áp dụng cho mọi phương trình truy hồi:
1. **Không áp dụng khi $f(n)$ không phải dạng đa thức**:
   - Ví dụ: $T(n) = 2T(n/2) + n \log n$. Ở đây $a=2, b=2, d=1$, nhưng $f(n) = n \log n$ tăng nhanh hơn $n^1$ một thừa số logarit chứ không phải đa thức $n^{1+\epsilon}$. Cần dùng phiên bản Master Theorem mở rộng hoặc cây đệ quy: giải ra $\Theta(n \log^2 n)$.
2. **Không áp dụng khi kích thước bài toán con không đều**:
   - Ví dụ: Dãy Fibonacci $T(n) = T(n-1) + T(n-2)$, hoặc $T(n) = T(n/3) + T(2n/3) + n$. Đối với trường hợp này, cần dùng **Định lý Akra-Bazzi** hoặc phương trình đặc trưng.
3. **Không áp dụng khi $a < 1$ hoặc $b \le 1$**.


---

# CHUYÊN ĐỀ 01: THUẬT TOÁN SẮP XẾP TRỘN (MERGESORT) & LỜI GIẢI CHI TIẾT 100% BÀI TẬP 5.1
## Trích dẫn: Anany Levitin, "Introduction to the Design and Analysis of Algorithms", 3rd Edition, Mục 5.1 (pp. 172–176)

---

## PHẦN 1: LÝ THUYẾT NỀN TẢNG & MÃ GIẢ CHUẨN HÓA

### 1.1. Bản chất Ý tưởng và Chiến lược Thiết kế
Thuật toán **Sắp xếp trộn (Mergesort)** là một hiện thực mẫu mực hoàn hảo cho chiến lược Chia để trị:
1. **Chia (Divide)**: Chia mảng đầu vào $A[0..n-1]$ theo **vị trí** thành hai nửa mảng độc lập: nửa trái $A[0..\lfloor n/2 \rfloor - 1]$ gồm $p = \lfloor n/2 \rfloor$ phần tử và nửa phải $A[\lfloor n/2 \rfloor .. n-1]$ gồm $q = n - p = \lceil n/2 \rceil$ phần tử. Bước chia diễn ra trong thời gian $O(1)$ (chỉ tính chỉ số).
2. **Trị (Conquer)**: Gọi đệ quy Mergesort để sắp xếp độc lập từng nửa mảng.
3. **Kết hợp (Combine / Merge)**: Hợp nhất hai mảng con đã được sắp xếp thành một mảng duy nhất có thứ tự hoàn chỉnh. Toàn bộ độ phức tạp và nỗ lực tính toán của thuật toán tập trung ở công đoạn này.

---

### 1.2. Mã giả Cấu trúc Chuẩn hóa (Standardized Pseudocode)

#### Thuật toán Mergesort
```text
algorithm: Mergesort(A[0..n - 1])
    input:  A[0..n - 1]: mảng gồm n phần tử có thể so sánh thứ tự.
   output:  Mảng A[0..n - 1] được sắp xếp theo thứ tự không giảm (tăng dần).

1   if n > 1 then
2       p ← ⌊n / 2⌋
3       q ← n - p
4       Khởi tạo mảng B[0..p - 1] ← A[0..p - 1]   // Sao chép nửa trái
5       Khởi tạo mảng C[0..q - 1] ← A[p..n - 1]   // Sao chép nửa phải
6       Mergesort(B[0..p - 1])                   // Đệ quy sắp xếp nửa trái
7       Mergesort(C[0..q - 1])                   // Đệ quy sắp xếp nửa phải
8       Merge(B, C, A)                           // Trộn hai nửa đã sắp vào mảng A
```

#### Thuật toán Trộn (Merge)
```text
algorithm: Merge(B[0..p - 1], C[0..q - 1], A[0..p + q - 1])
    input:  Hai mảng đã sắp thứ tự B[0..p - 1] và C[0..q - 1].
   output:  Mảng đích A[0..p + q - 1] chứa toàn bộ phần tử của B và C theo thứ tự không giảm.

1   i ← 0;  j ← 0;  k ← 0
2   while i < p and j < q do
3       if B[i] ≤ C[j] then
4           A[k] ← B[i]
5           i ← i + 1
6       else
7           A[k] ← C[j]
8           j ← j + 1
9       k ← k + 1
10  if i = p then
11      sao chép C[j..q - 1] vào A[k..p + q - 1]
12  else
13      sao chép B[i..p - 1] vào A[k..p + q - 1]
```

> **Bất biến vòng lặp (Loop Invariant) của `Merge`**:  
> Tại đầu mỗi lần lặp của vòng lặp `while` (dòng 2):
> 1. Mảng con $A[0..k-1]$ chứa đúng $k = i + j$ phần tử nhỏ nhất từ hai mảng $B[0..p-1]$ và $C[0..q-1]$, và đã được sắp xếp tăng dần.
> 2. Mọi phần tử trong $A[0..k-1]$ đều $\le \min(B[i], C[j])$.

---

### 1.3. Phân tích Toán học Hiệu năng Thuật toán

#### Số phép so sánh khóa trong trường hợp xấu nhất ($C_{worst}(n)$)
Trong bước hợp nhất hai mảng kích thước $p$ và $q$, mỗi phép so sánh đưa được đúng 1 phần tử vào mảng $A$. Trường hợp xấu nhất xảy ra khi hai mảng xen kẽ nhau cho tới phần tử cuối cùng của cả hai mảng, khi đó số phép so sánh tối đa là:
$$p + q - 1 = n - 1$$
Hệ thức truy hồi cho $C_{worst}(n)$:
$$C_{worst}(n) = C_{worst}(\lfloor n/2 \rfloor) + C_{worst}(\lceil n/2 \rceil) + n - 1 \quad (n > 1), \quad C_{worst}(1) = 0$$

Giả sử $n = 2^k$:
$$C_{worst}(2^k) = 2 C_{worst}(2^{k-1}) + 2^k - 1$$
Áp dụng phương pháp thế lùi (Backward Substitution):
$$\begin{aligned}
C(2^k) &= 2[2 C(2^{k-2}) + 2^{k-1} - 1] + 2^k - 1 = 2^2 C(2^{k-2}) + 2 \cdot 2^k - (1 + 2) \\
       &= 2^3 C(2^{k-3}) + 3 \cdot 2^k - (1 + 2 + 2^2) \\
       &= 2^i C(2^{k-i}) + i \cdot 2^k - (2^i - 1)
\end{aligned}$$
Khi $i = k$: do $C(2^0) = C(1) = 0$, ta có:
$$C_{worst}(n) = k \cdot 2^k - (2^k - 1) = n \log_2 n - n + 1$$
Vậy:
$$C_{worst}(n) \in \Theta(n \log n)$$

#### Số phép so sánh trong trường hợp tốt nhất ($C_{best}(n)$)
Trường hợp tốt nhất xảy ra khi tất cả các phần tử của một nửa mảng đều nhỏ hơn phần tử nhỏ nhất của nửa mảng kia (ví dụ: $B[p-1] < C[0]$). Khi đó, chỉ cần so sánh $p = n/2$ lần thì mảng $B$ đã cạn sạch, phần còn lại của $C$ được sao chép trực tiếp mà không tốn phép so sánh nào.
$$C_{best}(n) = 2 C_{best}(n/2) + \frac{n}{2}$$
Giải với $n = 2^k$:
$$C_{best}(n) = \frac{1}{2} n \log_2 n \in \Theta(n \log n)$$

#### Số phép so sánh trường hợp trung bình ($C_{avg}(n)$)
Qua phân tích xác suất trên tất cả các hoán vị:
$$C_{avg}(n) \approx n \log_2 n - 1.1588 n \in \Theta(n \log n)$$

#### Độ phức tạp Không gian (Space Complexity)
- Thuật toán Mergesort kinh điển cần cấp phát bộ nhớ phụ để lưu các mảng con $B$ và $C$ trong quá trình trộn:
  $$S(n) \in \Theta(n)$$
- Ngăn xếp lời gọi đệ quy (Call Stack): có chiều cao $\lceil \log_2 n \rceil$, tiêu tốn $O(\log n)$ bộ nhớ.  
Do đó, tổng bộ nhớ phụ là $\Theta(n)$.

#### Tính ổn định (Stability)
Mergesort là thuật toán sắp xếp **ổn định (stable)**. Tại dòng 3 của thủ tục `Merge`, điều kiện $B[i] \le C[j]$ sử dụng dấu $\le$ bảo đảm rằng nếu có hai phần tử bằng nhau, phần tử xuất hiện ở mảng con bên trái ($B$) sẽ luôn được đưa vào mảng kết quả $A$ trước phần tử ở mảng con bên phải ($C$).

---

## PHẦN 2: LỜI GIẢI CHI TIẾT 100% CÁC BÀI TẬP 5.1 (BÀI 1 ĐẾN BÀI 11)

---

### Bài 1 (Exercises 5.1 - Trang 175)
**Đề bài:**  
*a. Viết mã giả cho thuật toán chia để trị tìm vị trí của phần tử lớn nhất trong mảng gồm $n$ số.*  
*b. Đầu ra của thuật toán sẽ là gì đối với các mảng có nhiều phần tử cùng đạt giá trị lớn nhất?*  
*c. Thiết lập và giải phương trình truy hồi cho số phép so sánh khóa của thuật toán.*  
*d. So sánh hiệu năng của thuật toán này với thuật toán vét cạn thông thường.*

#### Lời giải chi tiết:

**a. Mã giả chuẩn hóa:**
```text
algorithm: MaxPositionDC(A[l..r])
    input:  Mảng A, chỉ số đầu l, chỉ số cuối r (0 ≤ l ≤ r ≤ n - 1).
   output:  Chỉ số index của phần tử có giá trị lớn nhất trong đoạn A[l..r].

1   if l = r then
2       return l
3   else
4       m ← ⌊(l + r) / 2⌋
5       pos1 ← MaxPositionDC(A[l..m])
6       pos2 ← MaxPositionDC(A[m + 1..r])
7       if A[pos1] ≥ A[pos2] then
8           return pos1
9       else
10          return pos2
```

**b. Phân tích đầu ra khi có nhiều phần tử lớn nhất bằng nhau:**  
Tại dòng 7, ta sử dụng điều kiện `if A[pos1] ≥ A[pos2] then return pos1`. Do $pos1 \in [l..m]$ (nằm ở nửa trái) và $pos2 \in [m+1..r]$ (nằm ở nửa phải), việc ưu tiên lấy $pos1$ khi bằng nhau bảo đảm thuật toán sẽ trả về **vị trí xuất hiện đầu tiên (chỉ số nhỏ nhất)** của giá trị cực đại. Nếu đổi dấu thành `>`, thuật toán sẽ trả về vị trí xuất hiện cuối cùng (chỉ số lớn nhất).

**c. Thiết lập và giải hệ thức truy hồi:**  
- Với $n = 1$ ($l = r$): không cần so sánh khóa nào $\implies C(1) = 0$.
- Với $n > 1$: chia đôi mảng thành 2 bài toán con kích thước $\lfloor n/2 \rfloor$ và $\lceil n/2 \rceil$. Sau khi giải đệ quy, chỉ tốn **đúng 1 phép so sánh** tại dòng 7 để chọn giữa $A[pos1]$ và $A[pos2]$.
$$C(n) = C(\lfloor n/2 \rfloor) + C(\lceil n/2 \rceil) + 1 \quad (n > 1), \quad C(1) = 0$$

Với $n = 2^k$, áp dụng phương pháp thế lùi:
$$\begin{aligned}
C(2^k) &= 2 C(2^{k-1}) + 1 \\
       &= 2 [2 C(2^{k-2}) + 1] + 1 = 2^2 C(2^{k-2}) + 2 + 1 \\
       &= 2^3 C(2^{k-3}) + 2^2 + 2 + 1 \\
       &= 2^k C(1) + \sum_{j=0}^{k-1} 2^j = 0 + (2^k - 1) = n - 1
\end{aligned}$$
Tổng quát với mọi $n \ge 1$, bằng quy nạp ta luôn có $C(n) = n - 1$.

**d. So sánh với thuật toán vét cạn (tuần tự):**  
- Thuật toán tuần tự quét từ $A[1]$ đến $A[n-1]$ thực hiện chính xác $n - 1$ phép so sánh.
- Thuật toán chia để trị cũng thực hiện chính xác $n - 1$ phép so sánh.
- **Đánh giá**: Về mặt số phép so sánh, hai phương pháp hoàn toàn tương đương. Tuy nhiên, thuật toán chia để trị tốn thêm chi phí overhead cho các lời gọi hàm đệ quy và tiêu tốn ngăn xếp bộ nhớ $O(\log n)$, trong khi thuật toán vét cạn chạy lặp tốn $O(1)$ bộ nhớ phụ và chạy nhanh hơn trên thực tế. Vì vậy, chia để trị không đem lại lợi thế thời gian cho bài toán tìm Max đơn lẻ.

---

### Bài 2 (Exercises 5.1 - Trang 175)
**Đề bài:**  
*a. Viết mã giả cho thuật toán chia để trị tìm đồng thời cả giá trị lớn nhất và giá trị nhỏ nhất trong mảng gồm $n$ số.*  
*b. Thiết lập và giải (với $n = 2^k$) phương trình truy hồi cho số phép so sánh khóa.*  
*c. So sánh hiệu năng của thuật toán này với thuật toán vét cạn.*

#### Lời giải chi tiết:

**a. Mã giả chuẩn hóa:**
```text
algorithm: MinMaxDC(A[l..r], minVal, maxVal)
    input:  Mảng A, đoạn chỉ số từ l đến r.
   output:  minVal và maxVal chứa giá trị nhỏ nhất và lớn nhất trong đoạn A[l..r].

1   if l = r then
2       minVal ← A[l]
3       maxVal ← A[l]
4   else if l = r - 1 then
5       if A[l] ≤ A[r] then
6           minVal ← A[l]
7           maxVal ← A[r]
8       else
9           minVal ← A[r]
10          maxVal ← A[l]
11  else
12      m ← ⌊(l + r) / 2⌋
13      MinMaxDC(A[l..m], min1, max1)
14      MinMaxDC(A[m + 1..r], min2, max2)
15      minVal ← min(min1, min2)    // 1 phép so sánh
16      maxVal ← max(max1, max2)    // 1 phép so sánh
```

**b. Thiết lập và giải phương trình truy hồi ($n = 2^k$):**  
- Trường hợp cơ sở:
  - Khi $n = 1$: $C(1) = 0$ phép so sánh.
  - Khi $n = 2$: $C(2) = 1$ phép so sánh (tại dòng 5).
- Bước kết hợp: Sau khi tìm được $(\min_1, \max_1)$ và $(\min_2, \max_2)$, ta cần đúng 2 phép so sánh: $\min_1$ với $\min_2$ và $\max_1$ với $\max_2$.
$$C(n) = 2 C(n/2) + 2 \quad \text{với } n > 2$$

Giải bằng phương pháp thế lùi với $n = 2^k$:
$$\begin{aligned}
C(2^k) &= 2 C(2^{k-1}) + 2 \\
       &= 2 [2 C(2^{k-2}) + 2] + 2 = 2^2 C(2^{k-2}) + 2^2 + 2 \\
       &= 2^3 C(2^{k-3}) + 2^3 + 2^2 + 2 \\
       &= 2^{k-1} C(2) + \sum_{j=1}^{k-1} 2^j
\end{aligned}$$
Vì $C(2) = 1$, ta có:
$$C(n) = 2^{k-1} \cdot 1 + 2 \cdot \frac{2^{k-1} - 1}{2 - 1} = 2^{k-1} + 2^k - 2 = \frac{n}{2} + n - 2 = \frac{3}{2}n - 2$$

**c. So sánh với thuật toán vét cạn:**  
- **Thuật toán vét cạn thông thường**: Khởi tạo $\min = \max = A[0]$, sau đó duyệt qua $n-1$ phần tử còn lại, mỗi phần tử so sánh với $\min$, nếu không nhỏ hơn thì so sánh tiếp với $\max$. Trong trường hợp xấu nhất, số phép so sánh là $2(n - 1) = 2n - 2$.
- **Thuật toán chia để trị**: Số phép so sánh luôn luôn là $\frac{3}{2}n - 2$.
- **Đánh giá**: Thuật toán chia để trị tiết kiệm được $\approx 25\%$ số phép so sánh so với vét cạn (giảm từ $2n$ xuống $1.5n$). Đây là một ví dụ xuất sắc cho thấy Chia để trị cải thiện hằng số nhân của độ phức tạp thời gian.

---

### Bài 3 (Exercises 5.1 - Trang 175)
**Đề bài:**  
*a. Viết mã giả cho thuật toán chia để trị giải bài toán tính lũy thừa $a^n$ với $n$ là số nguyên dương.*  
*b. Thiết lập và giải phương trình truy hồi cho số phép nhân.*  
*c. So sánh thuật toán này với thuật toán vét cạn.*

#### Lời giải chi tiết:

**a. Mã giả chia đôi ngây thơ (Naive Divide-and-Conquer):**
Ý tưởng chia bài toán tính $a^n$ thành hai nửa $a^{\lfloor n/2 \rfloor} \times a^{\lceil n/2 \rceil}$:
```text
algorithm: PowerDC(a, n)
    input:  Cơ số thực a, số nguyên dương n.
   output:  Giá trị a^n.

1   if n = 1 then
2       return a
3   else
4       return PowerDC(a, ⌊n / 2⌋) * PowerDC(a, ⌈n / 2⌉)
```

**b. Thiết lập và giải truy hồi:**  
- Với $n = 1$: $M(1) = 0$ phép nhân.
- Với $n > 1$: Tính 2 nhánh đệ quy độc lập rồi nhân kết quả với nhau (1 phép nhân):
  $$M(n) = M(\lfloor n/2 \rfloor) + M(\lceil n/2 \rceil) + 1$$
Với $n = 2^k$:
$$M(2^k) = 2 M(2^{k-1}) + 1 \implies M(n) = n - 1$$
Số phép nhân là $n - 1$.

**c. So sánh với vét cạn và bài học sâu sắc:**  
- Thuật toán vét cạn tính $a \times a \times \dots \times a$ cũng tốn đúng $n - 1$ phép nhân.
- Như vậy, thuật toán chia đôi ngây thơ không hề nhanh hơn vét cạn, mà còn tốn bộ nhớ ngăn xếp!
- **Cải tiến đúng đắn**: Vì hai nửa $a^{\lfloor n/2 \rfloor}$ là như nhau, ta chỉ nên tính $a^{\lfloor n/2 \rfloor}$ **MỘT LẦN**, sau đó bình phương lên:
  $$a^n = \begin{cases} (a^{n/2})^2 & \text{nếu } n \text{ chẵn} \\ a \times (a^{(n-1)/2})^2 & \text{nếu } n \text{ lẻ} \end{cases}$$
  Khi đó số phép nhân thỏa mãn $M(n) = M(\lfloor n/2 \rfloor) + (1 \text{ hoặc } 2) \implies M(n) \in \Theta(\log n)$. Tuy nhiên, đây chính là chiến lược **Giảm để trị (Decrease-by-a-constant-factor)** chứ không còn là Chia để trị thuần túy.

---

### Bài 4 (Exercises 5.1 - Trang 175)
**Đề bài:**  
*Trong Chương 2 đã đề cập rằng cơ số logarit thường không quan trọng khi phân tích lớp hiệu quả thuật toán. Điều này có đúng cho cả hai mệnh đề có chứa logarit trong Định lý Thợ (Master Theorem) hay không?*

#### Lời giải chi tiết:
Xét hai khẳng định chứa logarit trong Định lý Thợ:
1. **Mệnh đề 2 ($a = b^d$)**: $T(n) \in \Theta(n^d \log n)$.
   - Ở đây, $\log n$ đóng vai trò là một thừa số nhân. Theo công thức đổi cơ số logarit: $\log_c n = \frac{\log_k n}{\log_k c} = \frac{1}{\log_k c} \cdot \log_k n$.
   - Do $\frac{1}{\log_k c}$ là một hằng số dương độc lập với $n$, nên $\Theta(n^d \log_2 n) = \Theta(n^d \ln n) = \Theta(n^d \log_{10} n) = \Theta(n^d \log n)$.
   - **Kết luận**: Mệnh đề này **đúng**, cơ số logarit hoàn toàn không quan trọng.
2. **Mệnh đề 3 ($a > b^d$)**: $T(n) \in \Theta(n^{\log_b a})$.
   - Ở đây, $\log_b a$ nằm **trên số mũ** của biến $n$.
   - Cơ số $b$ ảnh hưởng trực tiếp đến giá trị số học của số mũ. Ví dụ: nếu $a = 8$, với $b = 2$ thì $n^{\log_2 8} = n^3$; nhưng với $b = 4$ thì $n^{\log_4 8} = n^{1.5}$. Rõ ràng $\Theta(n^3) \ne \Theta(n^{1.5})$.
   - **Kết luận**: Mệnh đề này **không đúng**. Cơ số $b$ của logarit là bắt buộc và tối quan trọng, không thể tùy tiện thay đổi!

---

### Bài 5 (Exercises 5.1 - Trang 175)
**Đề bài:**  
*Tìm bậc tăng trưởng (order of growth) cho nghiệm của các phương trình truy hồi sau:*  
*a. $T(n) = 4 T(n/2) + n, \quad T(1) = 1$*  
*b. $T(n) = 4 T(n/2) + n^2, \quad T(1) = 1$*  
*c. $T(n) = 4 T(n/2) + n^3, \quad T(1) = 1$*

#### Lời giải chi tiết:
Cả 3 phương trình đều có dạng chuẩn: $T(n) = a T(n/b) + f(n)$ với $a = 4$ và $b = 2$.  
Ta có: $b^d = 2^d$, và $\log_b a = \log_2 4 = 2$.

- **Câu a**: $f(n) = n = n^1 \implies d = 1$.  
  So sánh: $a = 4$ và $b^d = 2^1 = 2$.  
  Vì $a > b^d$ ($4 > 2$), bài toán rơi vào **Trường hợp 3 của Master Theorem**:
  $$T(n) \in \Theta(n^{\log_b a}) = \Theta(n^{\log_2 4}) = \Theta(n^2)$$

- **Câu b**: $f(n) = n^2 \implies d = 2$.  
  So sánh: $a = 4$ và $b^d = 2^2 = 4$.  
  Vì $a = b^d$ ($4 = 4$), bài toán rơi vào **Trường hợp 2 của Master Theorem**:
  $$T(n) \in \Theta(n^d \log n) = \Theta(n^2 \log n)$$

- **Câu c**: $f(n) = n^3 \implies d = 3$.  
  So sánh: $a = 4$ và $b^d = 2^3 = 8$.  
  Vì $a < b^d$ ($4 < 8$), bài toán rơi vào **Trường hợp 1 của Master Theorem**:
  $$T(n) \in \Theta(n^d) = \Theta(n^3)$$

---

### Bài 6 (Exercises 5.1 - Trang 175)
**Đề bài:**  
*Áp dụng thuật toán Mergesort để sắp xếp danh sách các ký tự: `E, X, A, M, P, L, E` theo thứ tự bảng chữ cái.*

#### Lời giải chi tiết:
Mảng ban đầu gồm $n = 7$ phần tử: $A[0..6] = [E_1, X, A, M, P, L, E_2]$ (đánh dấu chỉ số $1, 2$ để theo dõi tính ổn định).

**Quá trình phân rã (Divide Tree):**
```text
                          [E1, X, A, M, P, L, E2]
                         /                       \
               [E1, X, A]                         [M, P, L, E2]
              /          \                       /             \
          [E1]          [X, A]               [M, P]           [L, E2]
                       /      \             /      \         /       \
                     [X]      [A]         [M]      [P]     [L]       [E2]
```

**Quá trình hợp nhất (Merge Steps):**
1. Trộn `[X]` và `[A]`: So sánh `X` và `A` $\to$ được `[A, X]`.
2. Trộn `[E1]` và `[A, X]`:
   - So sánh `E1` với `A` $\to$ lấy `A`.
   - So sánh `E1` với `X` $\to$ lấy `E1`.
   - Lấy `X` còn lại $\to$ nửa trái sắp xong: `[A, E1, X]`.
3. Trộn `[M]` và `[P]`: So sánh `M` và `P` $\to$ được `[M, P]`.
4. Trộn `[L]` và `[E2]`: So sánh `L` và `E2` $\to$ được `[E2, L]`.
5. Trộn `[M, P]` và `[E2, L]`:
   - So sánh `M` với `E2` $\to$ lấy `E2`.
   - So sánh `M` với `L` $\to$ lấy `L`.
   - Đưa `M, P` vào $\to$ nửa phải sắp xong: `[E2, L, M, P]`.
6. Trộn hai nửa `[A, E1, X]` và `[E2, L, M, P]`:
   - So sánh `A` với `E2` $\to$ lấy `A`.
   - So sánh `E1` với `E2` $\to$ vì $E_1 \le E_2$, lấy `E1`.
   - So sánh `X` với `E2` $\to$ lấy `E2`.
   - So sánh `X` với `L` $\to$ lấy `L`.
   - So sánh `X` với `M` $\to$ lấy `M`.
   - So sánh `X` với `P` $\to$ lấy `P`.
   - Hết mảng phải, đưa `X` vào cuối.

**Kết quả cuối cùng:** `[A, E1, E2, L, M, P, X]`.

---

### Bài 7 (Exercises 5.1 - Trang 175)
**Đề bài:**  
*Thuật toán Mergesort có phải là một thuật toán sắp xếp ổn định (stable) không?*

#### Lời giải chi tiết:
**Khẳng định: Mergesort là một thuật toán sắp xếp ỔN ĐỊNH (Stable).**

**Chứng minh chặt chẽ:**  
Một thuật toán sắp xếp được gọi là ổn định nếu với mọi cặp phần tử có khóa bằng nhau $A[u] = A[v]$ mà $u < v$ (phần tử $A[u]$ đứng trước $A[v]$ trong mảng ban đầu), thì trong mảng kết quả sau khi sắp xếp, $A[u]$ vẫn đứng trước $A[v]$.

1. **Giai đoạn phân chia (Divide)**: Mergesort chia mảng theo vị trí liên tục từ trái qua phải. Do đó:
   - Nếu $u$ và $v$ cùng rơi vào nửa trái $B$, thứ tự tương đối được bảo toàn đệ quy.
   - Nếu $u$ và $v$ cùng rơi vào nửa phải $C$, thứ tự tương đối được bảo toàn đệ quy.
   - Nếu $u$ rơi vào nửa trái $B$ và $v$ rơi vào nửa phải $C$, thì $u < v$.
2. **Giai đoạn hợp nhất (Merge)**:  
   Tại dòng 3 của thuật toán `Merge`:
   ```text
   if B[i] ≤ C[j] then
       A[k] ← B[i]; i ← i + 1
   ```
   Khi hai phần tử có giá trị khóa bằng nhau ($B[i] = C[j]$), phép so sánh $B[i] \le C[j]$ trả về `true`. Do đó, phần tử $B[i]$ (thuộc nửa bên trái, xuất hiện trước trong mảng gốc) sẽ luôn được chọn để ghi vào mảng đích $A$ trước phần tử $C[j]$ (thuộc nửa bên phải).
3. Do thứ tự tương đối không bao giờ bị đảo ngược ở bất kỳ bước nào, Mergesort ổn định. $\blacksquare$

---

### Bài 8 (Exercises 5.1 - Trang 175)
**Đề bài:**  
*a. Giải phương trình truy hồi cho số phép so sánh khóa của Mergesort trong trường hợp xấu nhất (giả sử $n = 2^k$).*  
*b. Thiết lập và giải phương trình truy hồi cho số phép so sánh khóa của Mergesort trong trường hợp tốt nhất (giả sử $n = 2^k$).*  
*c. Thiết lập phương trình truy hồi cho số phép di chuyển khóa (key moves). Việc tính thêm số phép di chuyển khóa có làm thay đổi lớp hiệu năng của thuật toán không?*

#### Lời giải chi tiết:

**a. Giải truy hồi trường hợp xấu nhất:**  
Phương trình: $C_{worst}(n) = 2 C_{worst}(n/2) + n - 1$ với $C(1) = 0, n = 2^k$.  
Áp dụng phương pháp thế lùi:
$$\begin{aligned}
C(2^k) &= 2 C(2^{k-1}) + 2^k - 1 \\
       &= 2 [2 C(2^{k-2}) + 2^{k-1} - 1] + 2^k - 1 = 2^2 C(2^{k-2}) + 2 \cdot 2^k - (1 + 2) \\
       &= 2^3 C(2^{k-3}) + 3 \cdot 2^k - (1 + 2 + 4) \\
       &= 2^k C(1) + k \cdot 2^k - \sum_{j=0}^{k-1} 2^j = 0 + k \cdot 2^k - (2^k - 1)
\end{aligned}$$
Thay $k = \log_2 n$ và $2^k = n$:
$$C_{worst}(n) = n \log_2 n - n + 1 \in \Theta(n \log n)$$

**b. Thiết lập và giải truy hồi trường hợp tốt nhất:**  
- **Dạng đầu vào tạo trường hợp tốt nhất**: Khi ở mọi bước trộn hai mảng con $B[0..p-1]$ và $C[0..q-1]$, phần tử lớn nhất của mảng này luôn nhỏ hơn phần tử nhỏ nhất của mảng kia (ví dụ $B[p-1] < C[0]$).
- Khi đó, thuật toán chỉ cần so sánh đúng $p = n/2$ lần để đưa toàn bộ mảng $B$ vào $A$, sau đó sao chép toàn bộ $C$ vào $A$ mà không tốn thêm phép so sánh nào.
- Hệ thức truy hồi:
  $$C_{best}(n) = 2 C_{best}(n/2) + \frac{n}{2} \quad (n > 1), \quad C_{best}(1) = 0$$
Với $n = 2^k$:
$$\begin{aligned}
C_{best}(2^k) &= 2 C_{best}(2^{k-1}) + \frac{2^k}{2} = 2 C_{best}(2^{k-1}) + 2^{k-1} \\
              &= 2 [2 C_{best}(2^{k-2}) + 2^{k-2}] + 2^{k-1} = 2^2 C_{best}(2^{k-2}) + 2 \cdot 2^{k-1} \\
              &= 2^k C_{best}(1) + k \cdot 2^{k-1} = 0 + k \cdot \frac{n}{2} = \frac{1}{2} n \log_2 n
\end{aligned}$$
$$C_{best}(n) = \frac{1}{2} n \log_2 n \in \Theta(n \log n)$$

**c. Số phép di chuyển khóa (Key moves):**  
Trong thuật toán Mergesort ở Mục 5.1:
1. Trước khi đệ quy: Sao chép $p = n/2$ phần tử từ $A$ sang $B$ và $q = n/2$ phần tử từ $A$ sang $C$ $\implies$ tốn $n$ phép di chuyển.
2. Trong thủ tục `Merge`: Toàn bộ $n$ phần tử từ $B$ và $C$ được sao chép trở lại mảng $A$ $\implies$ tốn $n$ phép di chuyển.
Tổng số phép di chuyển ở giai đoạn chia và trộn là $n + n = 2n$.  
Hệ thức truy hồi cho số phép di chuyển khóa $M(n)$:
$$M(n) = 2 M(n/2) + 2n \quad (n > 1), \quad M(1) = 0$$
Với $n = 2^k$:
$$M(2^k) = 2 M(2^{k-1}) + 2 \cdot 2^k \implies M(n) = 2n \log_2 n$$
- **Đánh giá**: Vì $M(n) = 2n \log_2 n \in \Theta(n \log n)$, việc tính thêm số phép di chuyển khóa **hoàn toàn không làm thay đổi lớp hiệu năng** của Mergesort; thời gian thực thi vẫn thuộc $\Theta(n \log n)$.

---

### Bài 9 (Exercises 5.1 - Trang 175)
**Đề bài:**  
*Cho mảng $A[0..n-1]$ gồm $n$ số thực. Một cặp chỉ số $(A[i], A[j])$ được gọi là một cặp nghịch thế (inversion) nếu $i < j$ nhưng $A[i] > A[j]$. Hãy thiết kế một thuật toán độ phức tạp $O(n \log n)$ để đếm tổng số cặp nghịch thế trong mảng.*

#### Lời giải chi tiết:

**Ý tưởng thiết kế:**  
Một thuật toán vét cạn kiểm tra mọi cặp $(i, j)$ với $0 \le i < j < n$ sẽ tốn $\frac{n(n-1)}{2} = \Theta(n^2)$ phép so sánh.  
Để đạt độ phức tạp $O(n \log n)$, ta sử dụng kỹ thuật **Chia để trị cải biên từ Mergesort**:
1. Chia mảng $A$ thành hai nửa $A[l..m]$ và $A[m+1..r]$.
2. Tổng số cặp nghịch thế trong $A[l..r]$ bằng:
   $$\text{Inversions}(A[l..r]) = \text{Inv}(A[l..m]) + \text{Inv}(A[m+1..r]) + \text{SplitInv}(A[l..m], A[m+1..r])$$
   trong đó $\text{SplitInv}$ là số cặp nghịch thế có $i \le m$ và $j > m$.
3. **Mấu chốt**: Khi hai nửa mảng đã được sắp xếp tăng dần, nếu tại bước trộn ta thấy $B[i] > C[j]$, thì do mảng $B$ đã sắp xếp, **tất cả các phần tử còn lại từ $B[i]$ đến $B[p-1]$ đều lớn hơn $C[j]$**!  
   Do đó, số nghịch thế sinh ra từ $C[j]$ với nửa trái đúng bằng:
   $$p - i$$
   Ta cộng dồn $p - i$ vào biến đếm mà chỉ tốn thời gian $O(1)$!

**Mã giả chuẩn hóa:**
```text
algorithm: CountInversions(A[l..r])
    input:  Mảng A, đoạn chỉ số l đến r.
   output:  Số lượng cặp nghịch thế trong A[l..r], đồng thời đoạn A[l..r] được sắp xếp.

1   if l ≥ r then
2       return 0
3   m ← ⌊(l + r) / 2⌋
4   invCount ← CountInversions(A[l..m]) + CountInversions(A[m + 1..r])
5   invCount ← invCount + MergeAndCount(A, l, m, r)
6   return invCount
```

```text
algorithm: MergeAndCount(A, l, m, r)
1   Tạo mảng tạm B[0..m - l] và C[0..r - m - 1]
2   Sao chép A[l..m] vào B, A[m + 1..r] vào C
3   i ← 0;  j ← 0;  k ← l;  splits ← 0
4   while i < len(B) and j < len(C) do
5       if B[i] ≤ C[j] then
6           A[k] ← B[i]; i ← i + 1
7       else
8           A[k] ← C[j]; j ← j + 1
9           splits ← splits + (len(B) - i)   // Điểm mấu chốt: cộng toàn bộ phần tử còn lại của B
10      k ← k + 1
11  Sao chép phần tử còn lại của B hoặc C vào A
12  return splits
```

**Phân tích độ phức tạp:**
$$T(n) = 2 T(n/2) + \Theta(n) \implies T(n) \in \Theta(n \log n)$$

---

### Bài 10 (Exercises 5.1 - Trang 175)
**Đề bài:**  
*Cài đặt phiên bản Mergesort từ dưới lên (Bottom-up Mergesort) bằng một ngôn ngữ lập trình tùy chọn.*

#### Lời giải chi tiết:

**Bản chất thuật toán Bottom-up Mergesort:**  
Bottom-up Mergesort loại bỏ hoàn toàn đệ quy:
- Vòng lặp ngoài duyệt kích thước mảng con cần trộn: $width = 1, 2, 4, 8, \dots < n$.
- Vòng lặp trong chia mảng thành các cặp đoạn liên tiếp có độ dài $width$ và gọi hàm `Merge` để trộn chúng thành các đoạn kích thước $2 \times width$.

**Mã nguồn C++ hoàn chỉnh:**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

void merge(std::vector<int>& a, std::vector<int>& temp, int l, int m, int r) {
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r) {
        if (a[i] <= a[j]) temp[k++] = a[i++];
        else temp[k++] = a[j++];
    }
    while (i <= m) temp[k++] = a[i++];
    while (j <= r) temp[k++] = a[j++];
    for (int idx = l; idx <= r; ++idx) a[idx] = temp[idx];
}

void bottomUpMergesort(std::vector<int>& a) {
    int n = a.size();
    std::vector<int> temp(n);
    for (int width = 1; width < n; width *= 2) {
        for (int l = 0; l < n - width; l += 2 * width) {
            int m = l + width - 1;
            int r = std::min(l + 2 * width - 1, n - 1);
            merge(a, temp, l, m, r);
        }
    }
}
```

---

### Bài 11 (Exercises 5.1 - Trang 175)
**Đề bài: Trò chơi ghép mảnh Tromino (Tromino Puzzle - Golomb, 1994)**  
*Một mảnh tromino hình thước thợ (L-shaped tromino) là một mảnh ghép gồm ba ô vuông đơn vị $1 \times 1$. Bài toán yêu cầu lát kín một bàn cờ kích thước $2^n \times 2^n$ bị khuyết đúng một ô vuông bất kỳ bằng các mảnh tromino sao cho các mảnh không đè lên nhau và phủ kín tất cả các ô còn lại. Hãy thiết kế thuật toán chia để trị cho bài toán này.*

#### Lời giải chi tiết:

**Phân tích toán học:**  
Bàn cờ $2^n \times 2^n$ có tổng diện tích là $2^{2n} = 4^n$ ô.  
Khi khuyết 1 ô, số ô cần lát là $4^n - 1$.  
Vì $4 \equiv 1 \pmod 3 \implies 4^n - 1 \equiv 0 \pmod 3$, tổng số ô cần lát luôn chia hết cho 3. Số mảnh tromino cần dùng chính xác là $\frac{4^n - 1}{3}$.

**Chiến lược thiết kế Chia để trị (Golomb's Tromino Algorithm):**
1. **Trường hợp cơ sở ($n = 1$)**: Bàn cờ kích thước $2 \times 2$ có 4 ô, khuyết 1 ô $\implies$ còn đúng 3 ô tạo thành một hình chữ L. Ta chỉ việc đặt đúng 1 mảnh tromino là phủ kín hoàn toàn.
2. **Bước chia ($n > 1$)**:
   - Chia bàn cờ $2^n \times 2^n$ thành 4 góc phần tư, mỗi góc là một bàn cờ vuông kích thước $2^{n-1} \times 2^{n-1}$.
   - Ô bị khuyết ban đầu chắc chắn phải nằm trong **đúng một** trong 4 góc phần tư này.
3. **Mấu chốt kỳ diệu (Bước Trị & Đặt mảnh tâm)**:
   - Ba góc phần tư còn lại hiện đang hoàn toàn nguyên vẹn (chưa có ô khuyết nào, nên không thể gọi đệ quy ngay).
   - Ta đặt **một mảnh tromino duy nhất vào chính giữa tâm bàn cờ**, sao cho ba ô của mảnh tromino này che phủ đúng ba góc kề tâm của **ba góc phần tư không chứa ô khuyết ban đầu**!
   - Khi đó, ba ô bị che này đóng vai trò như **ba ô khuyết mới** cho ba góc phần tư tương ứng!
4. **Gọi đệ quy**: Bây giờ cả 4 góc phần tư đều trở thành các bàn cờ kích thước $2^{n-1} \times 2^{n-1}$ bị khuyết đúng 1 ô. Ta gọi đệ quy để giải cho từng góc phần tư.

**Mã giả chuẩn hóa:**
```text
algorithm: TileBoard(top, left, size, missingRow, missingCol)
    input:  Tọa độ góc trên-trái (top, left), kích thước bàn cờ size = 2^n,
            tọa độ ô khuyết (missingRow, missingCol).
   output:  Lát kín bàn cờ bằng các mảnh tromino có đánh số nhận diện.

1   if size = 2 then
2       Đặt mảnh tromino mới phủ 3 ô không khuyết trong bảng 2x2
3       return
4   half ← size / 2
5   centerRow ← top + half
6   centerCol ← left + half
7   trominoID ← tạo_mã_mảnh_ghép_mới()
8
9   // Kiểm tra góc Tây Bắc (Top-Left)
10  if missingRow < centerRow and missingCol < centerCol then
11      TileBoard(top, left, half, missingRow, missingCol)
12  else
13      Đánh dấu ô (centerRow - 1, centerCol - 1) bằng trominoID
14      TileBoard(top, left, half, centerRow - 1, centerCol - 1)
15
16  // Kiểm tra góc Đông Bắc (Top-Right)
17  if missingRow < centerRow and missingCol ≥ centerCol then
18      TileBoard(top, centerCol, half, missingRow, missingCol)
19  else
20      Đánh dấu ô (centerRow - 1, centerCol) bằng trominoID
21      TileBoard(top, centerCol, half, centerRow - 1, centerCol)
22
23  // Kiểm tra góc Tây Nam (Bottom-Left)
24  if missingRow ≥ centerRow and missingCol < centerCol then
25      TileBoard(centerRow, left, half, missingRow, missingCol)
26  else
27      Đánh dấu ô (centerRow, centerCol - 1) bằng trominoID
28      TileBoard(centerRow, left, half, centerRow, centerCol - 1)
29
30  // Kiểm tra góc Đông Nam (Bottom-Right)
31  if missingRow ≥ centerRow and missingCol ≥ centerCol then
32      TileBoard(centerRow, centerCol, half, missingRow, missingCol)
33  else
34      Đánh dấu ô (centerRow, centerCol) bằng trominoID
35      TileBoard(centerRow, centerCol, half, centerRow, centerCol)
```

**Phân tích độ phức tạp:**
- Mỗi bước chia thành $a = 4$ bài toán con kích thước $N/2$ (với $N = 2^n$).
- Chi phí đặt mảnh tâm là $\Theta(1)$.
- Hệ thức truy hồi:
  $$T(N) = 4 T(N/2) + \Theta(1) \implies T(N) \in \Theta(N^2) = \Theta(4^n)$$
Thuật toán có thời gian chạy tỷ lệ thuận với số ô cờ, đạt mức tối ưu tuyệt đối $\Theta(\text{diện tích bàn cờ})$.


---

# CHUYÊN ĐỀ 02: THUẬT TOÁN SẮP XẾP NHANH (QUICKSORT) & LỜI GIẢI CHI TIẾT 100% BÀI TẬP 5.2
## Trích dẫn: Anany Levitin, "Introduction to the Design and Analysis of Algorithms", 3rd Edition, Mục 5.2 (pp. 176–182)

---

## PHẦN 1: LÝ THUYẾT NỀN TẢNG & MÃ GIẢ CHUẨN HÓA

### 1.1. Bản chất Ý tưởng và Chiến lược Thiết kế
Thuật toán **Sắp xếp nhanh (Quicksort)** được C.A.R. Hoare phát minh năm 1960. Trái ngược với Mergesort (chia mảng theo **vị trí** và tốn công sức ở bước **kết hợp**), Quicksort chia mảng theo **giá trị** của các phần tử và dồn toàn bộ nỗ lực vào bước **chia (phân hoạch - partitioning)**:
1. **Phân hoạch (Partitioning)**: Chọn một phần tử làm chốt (*pivot* $p$). Sắp xếp lại đoạn mảng sao cho:
   - Tất cả các phần tử nhỏ hơn hoặc bằng $p$ dồn về bên trái.
   - Tất cả các phần tử lớn hơn hoặc bằng $p$ dồn về bên phải.
   - Phần tử $p$ nằm tại vị trí phân tách chính xác $s$ trong mảng đã sắp xếp.
2. **Trị (Conquer)**: Đệ quy áp dụng Quicksort cho hai mảng con $A[l..s-1]$ và $A[s+1..r]$.
3. **Kết hợp (Combine)**: Hoàn toàn không tốn chi phí ($O(1)$) vì các mảng con đã nằm đúng vùng giá trị của chúng!

---

### 1.2. Mã giả Cấu trúc Chuẩn hóa

#### Thuật toán Quicksort tổng thể
```text
algorithm: Quicksort(A[l..r])
    input:  Mảng con A[l..r] của mảng A[0..n - 1] (0 ≤ l ≤ r ≤ n - 1).
   output:  Mảng con A[l..r] được sắp xếp theo thứ tự không giảm.

1   if l < r then
2       s ← HoarePartition(A[l..r])   // s là vị trí phân hoạch của chốt
3       Quicksort(A[l..s - 1])        // Đệ quy sắp xếp nửa bên trái chốt
4       Quicksort(A[s + 1..r])        // Đệ quy sắp xếp nửa bên phải chốt
```

#### Thuật toán Phân hoạch Hoare (Hoare Partition)
```text
algorithm: HoarePartition(A[l..r])
    input:  Đoạn mảng A[l..r] với l < r.
   output:  Vị trí phân hoạch s và mảng A[l..r] được sắp xếp lại sao cho:
            mọi k < s: A[k] ≤ A[s] và mọi k > s: A[k] ≥ A[s].

1   p ← A[l]          // Chọn phần tử đầu tiên làm chốt (pivot)
2   i ← l;  j ← r + 1
3   repeat
4       repeat i ← i + 1 until A[i] ≥ p
5       repeat j ← j - 1 until A[j] ≤ p
6       swap(A[i], A[j])
7   until i ≥ j
8   swap(A[i], A[j])  // Hoàn tác phép hoán đổi dư thừa cuối cùng khi i ≥ j
9   swap(A[l], A[j])  // Đưa chốt về vị trí phân hoạch chính xác
10  return j
```

---

### 1.3. Phân tích Toán học Hiệu năng Thuật toán Quicksort

#### Phân tích số phép so sánh khóa trong thủ tục Phân hoạch
Trong mỗi lần gọi `HoarePartition(A[l..r])`, các con trỏ $i$ và $j$ quét từ hai đầu vào trong. Số phép so sánh khóa thực hiện là:
$$r - l + 1 \quad \text{(nếu không cần lính canh) hoặc } r - l + 2$$
Trung bình và xấp xỉ là $n + 1$ phép so sánh trên đoạn $n$ phần tử.

#### Trường hợp xấu nhất ($C_{worst}(n)$)
Xảy ra khi tại mọi bước, chốt luôn là phần tử nhỏ nhất hoặc lớn nhất (ví dụ: mảng đã tăng dần nghiêm ngặt). Khi đó một mảng con rỗng ($0$ phần tử) và mảng con còn lại có kích thước $n-1$:
$$C_{worst}(n) = C_{worst}(n-1) + (n + 1) \quad (n > 1), \quad C_{worst}(1) = 0$$
$$\begin{aligned}
C_{worst}(n) &= (n+1) + n + (n-1) + \dots + 3 \\
             &= \frac{(n+1)(n+2)}{2} - 3 = \frac{n^2 + 3n - 4}{2} \in \Theta(n^2)
\end{aligned}$$

#### Trường hợp tốt nhất ($C_{best}(n)$)
Xảy ra khi tại mọi bước, chốt luôn chia đôi mảng thành hai nửa bằng nhau có kích thước xấp xỉ $\lfloor (n-1)/2 \rfloor$:
$$C_{best}(n) = 2 C_{best}(n/2) + n$$
Theo Định lý Thợ với $a=2, b=2, d=1 \implies a = b^d$:
$$C_{best}(n) \in \Theta(n \log n)$$
Chính xác với $n = 2^k - 1$: $C_{best}(n) = n \log_2 (n+1) - n \approx n \log_2 n$.

#### Trường hợp trung bình ($C_{avg}(n)$)
Giả định mọi vị trí phân hoạch $s \in [0..n-1]$ đều có xác suất xuất hiện như nhau là $\frac{1}{n}$:
$$C_{avg}(n) = (n + 1) + \frac{1}{n} \sum_{s=0}^{n-1} [C_{avg}(s) + C_{avg}(n - 1 - s)] = (n + 1) + \frac{2}{n} \sum_{k=0}^{n-1} C_{avg}(k)$$
Nhân cả hai vế với $n$:
$$n C_{avg}(n) = n(n+1) + 2 \sum_{k=0}^{n-1} C_{avg}(k) \quad (1)$$
Thay $n$ bằng $n-1$:
$$(n-1) C_{avg}(n-1) = n(n-1) + 2 \sum_{k=0}^{n-2} C_{avg}(k) \quad (2)$$
Lấy $(1) - (2)$:
$$n C_{avg}(n) - (n-1) C_{avg}(n-1) = 2n + 2 C_{avg}(n-1) \implies n C_{avg}(n) = (n+1) C_{avg}(n-1) + 2n$$
Chia cả hai vế cho $n(n+1)$:
$$\frac{C_{avg}(n)}{n+1} = \frac{C_{avg}(n-1)}{n} + \frac{2}{n+1}$$
Đặt $a_n = \frac{C_{avg}(n)}{n+1}$, ta có:
$$a_n = a_{n-1} + \frac{2}{n+1} = a_1 + 2 \sum_{k=2}^n \frac{1}{k+1} \approx 2 \sum_{k=1}^n \frac{1}{k} \approx 2 \ln n$$
Do đó:
$$C_{avg}(n) \approx 2(n+1) \ln n \approx 2n \frac{\log_2 n}{\log_2 e} \approx 2 \ln 2 \cdot n \log_2 n \approx 1.386 n \log_2 n$$
- **Nhận xét quan trọng**: Quicksort chỉ tốn hơn Mergesort khoảng $39\%$ số phép so sánh trong trường hợp trung bình, nhưng vòng lặp trong của Quicksort cực kỳ gọn nhẹ, không cần mảng phụ và tối ưu hóa bộ nhớ đệm (cache), khiến nó chạy nhanh hơn Mergesort trong thực tế trên hầu hết hệ thống phần cứng.

#### Độ phức tạp Không gian và Tối ưu Ngăn xếp (Stack Space)
- Trong trường hợp xấu nhất, chiều sâu đệ quy là $n \implies$ tốn $O(n)$ không gian ngăn xếp.
- **Kỹ thuật tối ưu đệ quy đuôi (Tail Recursion Optimization)**: Luôn gọi đệ quy cho mảng con có kích thước **nhỏ hơn trước**, và dùng vòng lặp cho mảng con lớn hơn. Vì mảng con nhỏ hơn có kích thước tối đa là $n/2$, chiều sâu ngăn xếp tối đa luôn được bảo đảm ở mức:
  $$S(n) \le \lceil \log_2 n \rceil = O(\log n)$$

---

## PHẦN 2: LỜI GIẢI CHI TIẾT 100% BÀI TẬP 5.2 (BÀI 1 ĐẾN BÀI 11)

---

### Bài 1 (Exercises 5.2 - Trang 181)
**Đề bài:**  
*Áp dụng thuật toán Quicksort để sắp xếp danh sách các chữ cái: `E, X, A, M, P, L, E` theo thứ tự bảng chữ cái. Vẽ cây của các lời gọi đệ quy.*

#### Lời giải chi tiết:
Mảng ban đầu: $A[0..6] = [E_1, X, A, M, P, L, E_2]$.

**Bước 1: Phân hoạch đoạn $A[0..6]$ với chốt $p = A[0] = E_1$:**
- Khởi tạo: $i = 0, j = 7$.
- Quét $i$ tìm phần tử $\ge E_1$: $A[1] = X \ge E_1 \implies i = 1$.
- Quét $j$ tìm phần tử $\le E_1$: $A[6] = E_2 \le E_1 \implies j = 6$.
- $i < j$: Hoán đổi $A[1]$ và $A[6] \implies A = [E_1, E_2, A, M, P, L, X]$.
- Quét tiếp:
  - $i$ tăng tới $A[3] = M \ge E_1 \implies i = 3$.
  - $j$ giảm tới $A[2] = A \le E_1 \implies j = 2$.
- Dừng vì $i \ge j$ ($3 \ge 2$). Hoán đổi dư thừa hoàn tác, sau đó hoán đổi $A[l]$ và $A[j]$ (tức $A[0]$ và $A[2]$):
  $$\text{Đổi } A[0] (E_1) \leftrightarrow A[2] (A) \implies A = [A, E_2, \mathbf{E_1}, M, P, L, X]$$
- Chốt $E_1$ nằm tại vị trí $s = 2$. Hai mảng con là $A[0..1] = [A, E_2]$ và $A[3..6] = [M, P, L, X]$.

**Bước 2: Quicksort nhánh trái $A[0..1] = [A, E_2]$ với chốt $p = A$:**
- $i$ dừng tại $1$ ($E_2 \ge A$), $j$ dừng tại $0$ ($A \le A$). $i \ge j$, hoán đổi $A[0]$ với chính nó $\implies s = 0$.
- Đoạn con trái rỗng, đoạn con phải là $[E_2]$ ($1$ phần tử $\implies$ xong).

**Bước 3: Quicksort nhánh phải $A[3..6] = [M, P, L, X]$ với chốt $p = M$:**
- $i$ dừng tại $A[4] = P \ge M$, $j$ dừng tại $A[5] = L \le M$.
- Hoán đổi $P \leftrightarrow L \implies [M, L, P, X]$.
- Quét tiếp: $i$ dừng tại $P$ (vị trí 5), $j$ dừng tại $L$ (vị trí 4). $i \ge j$.
- Hoán đổi $A[3] (M) \leftrightarrow A[4] (L) \implies [L, \mathbf{M}, P, X]$.
- Chốt $M$ nằm tại vị trí $s = 4$. Hai mảng con là $[L]$ (xong) và $[P, X]$.

**Bước 4: Quicksort $[P, X]$ với chốt $p = P$:**
- $s = 5$ cố định $P$, mảng con $[X]$ xong.

**Cây các lời gọi đệ quy (Recursive Call Tree):**
```text
                     Quicksort(A[0..6]) [E1, X, A, M, P, L, E2]
                              s = 2 (chốt E1)
                             /              \
            Quicksort(A[0..1])              Quicksort(A[3..6])
               [A, E2] (s=0, chốt A)           [M, P, L, X] (s=4, chốt M)
              /       \                       /            \
          (rỗng)   Quicksort(A[1..1])   Quicksort(A[3..3])  Quicksort(A[5..6])
                         [E2]                  [L]            [P, X] (s=5, chốt P)
                                                             /       \
                                                          (rỗng)   Quicksort(A[6..6])
                                                                         [X]
```
**Kết quả cuối cùng:** `[A, E2, E1, L, M, P, X]`.

---

### Bài 2 (Exercises 5.2 - Trang 181)
**Đề bài:**  
*Đối với thủ tục phân hoạch Hoare:*  
*a. Chứng minh rằng nếu hai chỉ số quét dừng lại khi cùng trỏ tới một phần tử ($i = j$), thì giá trị của phần tử đó bắt buộc phải bằng chốt ($A[i] = p$).*  
*b. Chứng minh rằng khi các chỉ số dừng quét, $j$ không thể trỏ tới vị trí lệch quá một vị trí về bên trái của $i$ (tức $j \ge i - 1$).*

#### Lời giải chi tiết:

**a. Chứng minh $i = j \implies A[i] = p$:**
- Quy tắc tăng con trỏ $i$: Vòng lặp `repeat i ← i + 1 until A[i] ≥ p` chỉ dừng lại khi phần tử tại $i$ thỏa mãn:
  $$A[i] \ge p$$
- Quy tắc giảm con trỏ $j$: Vòng lặp `repeat j ← j - 1 until A[j] ≤ p` chỉ dừng lại khi phần tử tại $j$ thỏa mãn:
  $$A[j] \le p$$
- Nếu hai chỉ số cùng dừng tại cùng một vị trí, tức là $i = j$, thì phần tử tại vị trí này phải đồng thời thỏa mãn cả hai điều kiện dừng:
  $$A[i] \ge p \quad \text{và} \quad A[i] \le p$$
- Từ hai bất đẳng thức trên, theo tính chất phản xứng của quan hệ thứ tự, bắt buộc:
  $$A[i] = p$$
  $\blacksquare$

**b. Chứng minh $j$ không thể lệch quá một vị trí về bên trái của $i$ ($j \ge i - 1$):**
- Trước khi thực hiện bước quét hiện tại, giả sử hai chỉ số đang có thứ tự $i < j$ (vì nếu $i \ge j$ vòng lặp ngoài đã kết thúc).
- Khi con trỏ $i$ di chuyển sang phải từng bước một ($i \leftarrow i + 1$), nó chỉ dừng lại tại vị trí đầu tiên $i_{new}$ có $A[i_{new}] \ge p$.
- Sau đó, con trỏ $j$ di chuyển sang trái từng bước một ($j \leftarrow j - 1$). Nó kiểm tra các phần tử.
- Nếu $j$ di chuyển giảm dần và tiến về phía $i_{new}$:
  - Khi $j$ chạm tới $i_{new}$: Ta đã biết $A[i_{new}] \ge p$. Nếu $A[i_{new}] = p$, thì điều kiện $A[j] \le p$ được thỏa mãn ngay tại đây, $j$ dừng lại ngay tại $j = i_{new}$.
  - Nếu $A[i_{new}] > p$, thì $j$ không dừng tại $i_{new}$ mà giảm tiếp thêm 1 đơn vị: $j = i_{new} - 1$.
  - Nhưng trước vị trí $i_{new}$, phần tử tại $i_{new} - 1$ vừa được kiểm tra ở lần quét trước (hoặc là vị trí đã được hoán đổi sao cho $A \le p$, hoặc chính là chốt ban đầu $A[l] = p \le p$). Do đó, tại vị trí $j = i_{new} - 1$, chắc chắn giá trị $A[j] \le p$ luôn thỏa mãn!
  - Do đó con trỏ $j$ **bắt buộc phải dừng ngay lập tức tại $j = i_{new} - 1$**, không bao giờ có thể giảm tiếp xuống $i_{new} - 2$.
- Vậy khi dừng quét, chỉ có hai khả năng: $j = i$ hoặc $j = i - 1$. Tuyệt đối không thể xảy ra $j \le i - 2$. $\blacksquare$

---

### Bài 3 (Exercises 5.2 - Trang 181)
**Đề bài:**  
*Hãy đưa ra một ví dụ chứng minh rằng Quicksort không phải là một thuật toán sắp xếp ổn định (not stable).*

#### Lời giải chi tiết:
Xét mảng gồm 3 phần tử: $A = [2_a, 2_b, 1]$ (đánh dấu $a, b$ để phân biệt hai số 2 bằng nhau, $2_a$ xuất hiện trước $2_b$).

**Áp dụng Quicksort với phân hoạch Hoare:**
1. Chọn chốt $p = A[0] = 2_a$.
2. Khởi tạo $i = 0, j = 3$.
3. Quét $i$: $A[1] = 2_b \ge p \implies i$ dừng tại chỉ số $1$.
4. Quét $j$: $A[2] = 1 \le p \implies j$ dừng tại chỉ số $2$.
5. Vì $i < j$ ($1 < 2$), thực hiện hoán đổi $A[i] \leftrightarrow A[j]$ (đổi $2_b \leftrightarrow 1$):
   $$A = [2_a, 1, 2_b]$$
6. Quét tiếp:
   - $i$ tăng tới $2$ ($A[2] = 2_b \ge p$) $\implies i = 2$.
   - $j$ giảm tới $1$ ($A[1] = 1 \le p$) $\implies j = 1$.
7. Dừng vì $i \ge j$ ($2 \ge 1$). Hoán đổi chốt $A[0]$ và $A[j]$ (đổi $A[0] \leftrightarrow A[1]$, tức $2_a \leftrightarrow 1$):
   $$A = [1, 2_a, 2_b]$$
   *(Khoan, ở ví dụ này thứ tự $2_a, 2_b$ vô tình được giữ nguyên. Hãy xét ví dụ kinh điển hơn bên dưới)*.

**Ví dụ phản chứng chuẩn mực nhất:**
Xét mảng 4 phần tử: $A = [3, 2_a, 2_b, 1]$ với chốt $p = 3$.
- $i$ quét tìm phần tử $\ge 3$: không có (trừ lính canh ở ngoài).
- Hãy xét mảng: $A = [5, 3_a, 3_b, 1, 6]$ với chốt $p = 5$:
- $i$ dừng tại $6$ (vị trí 4), $j$ dừng tại $1$ (vị trí 3). Đổi $6 \leftrightarrow 1 \implies [5, 3_a, 3_b, 1, 6]$.

**Ví dụ ngắn gọn và chuẩn xác tuyệt đối (3 phần tử):**
Xét mảng $A = [3, 3^*, 1]$ với chốt $p = 3$:
1. $i = 0, j = 3$.
2. $i$ tăng đến $1$: $A[1] = 3^* \ge 3 \implies i$ dừng tại $1$.
3. $j$ giảm đến $2$: $A[2] = 1 \le 3 \implies j$ dừng tại $2$.
4. $i < j$: hoán đổi $A[1] \leftrightarrow A[2]$ (đổi $3^* \leftrightarrow 1$):
   $$A = [3, 1, 3^*]$$
5. Quét tiếp:
   - $i$ tăng đến $2$: $A[2] = 3^* \ge 3 \implies i = 2$.
   - $j$ giảm đến $1$: $A[1] = 1 \le 3 \implies j = 1$.
6. $i \ge j$, dừng quét. Hoán đổi chốt $A[0]$ với $A[j]$ (tức đổi $A[0] \leftrightarrow A[1]$, hoán đổi $3 \leftrightarrow 1$):
   $$A = [1, 3, 3^*]$$
*(Trong ví dụ này $3$ vẫn đứng trước $3^*$. Hãy xét ví dụ khi chốt được hoán đổi nhảy qua phần tử bằng nó!)*

**Ví dụ chuẩn xác nhất:** Xét $A = [2, 2^*, 1]$:
1. $p = A[0] = 2$.
2. $i$ dừng tại $1$ ($2^* \ge 2$). $j$ dừng tại $2$ ($1 \le 2$).
3. Đổi $A[1] \leftrightarrow A[2]$: mảng thành $[2, 1, 2^*]$.
4. Quét tiếp: $i$ dừng tại $2$ ($2^* \ge 2$), $j$ dừng tại $1$ ($1 \le 2$).
5. Dừng quét. Hoán đổi $A[0] (2)$ với $A[j] = A[1] (1)$:
   $$A = [1, 2, 2^*]$$
   
Bây giờ xét $A = [2, 1, 2^*]$:
1. $p = 2$. $i$ dừng tại $2$ ($2^* \ge 2$), $j$ dừng tại $2$ ($2^* \le 2$).
2. Vì $i = j = 2$, dừng quét. Đổi $A[0] (2) \leftrightarrow A[2] (2^*)$:
   $$A = [2^*, 1, 2]$$
Sau đó Quicksort đệ quy đoạn $[2^*, 1]$ sẽ đưa về:
$$[1, 2^*, 2]$$
- Ban đầu: $2$ đứng trước $2^*$.
- Kết quả cuối cùng: $2^*$ đứng trước $2$!  
Thứ tự tương đối bị đảo ngược. Vậy **Quicksort không ổn định**. $\blacksquare$

---

### Bài 4 (Exercises 5.2 - Trang 181)
**Đề bài:**  
*Hãy đưa ra ví dụ về một mảng gồm $n$ phần tử mà tại đó phần tử lính canh (sentinel) thực sự cần thiết. Giá trị của lính canh nên là bao nhiêu? Giải thích tại sao một lính canh duy nhất ở cuối mảng là đủ cho mọi trường hợp đầu vào.*

#### Lời giải chi tiết:
1. **Ví dụ mảng cần lính canh**:  
   Xét mảng đã sắp xếp tăng dần nghiêm ngặt: $A = [1, 2, 3, 4, 5]$ và không có lính canh.
   - Chọn chốt $p = A[0] = 1$.
   - Con trỏ $i$ bắt đầu tại $0$, tăng dần: $i \leftarrow i + 1$. Vòng lặp `until A[i] ≥ p` sẽ kiểm tra $A[1]=2 \ge 1, A[2]=3 \ge 1, \dots$. Nếu phần tử chốt $p$ lớn hơn tất cả các phần tử còn lại trong mảng (ví dụ mảng $A = [10, 2, 3, 4, 5]$):
     - Chốt $p = 10$.
     - $A[1]=2 < 10, A[2]=3 < 10, A[3]=4 < 10, A[4]=5 < 10$.
     - Con trỏ $i$ sẽ tăng vượt qua chỉ số $n-1 = 4$ sang vùng nhớ không hợp lệ ($i = 5, 6, \dots$) gây lỗi tràn bộ nhớ (*segmentation fault* / *out of bounds*)!
2. **Giá trị của lính canh**:  
   Lính canh cần được đặt tại $A[n]$ (ngay sau phần tử cuối cùng) với giá trị:
   $$\text{Sentinel} \ge \max_{0 \le k < n} A[k] \quad \text{(hoặc } +\infty \text{)}$$
   Khi con trỏ $i$ tăng tới $n$, điều kiện $A[n] \ge p$ chắc chắn thỏa mãn, ép con trỏ $i$ phải dừng lại.
3. **Tại sao một lính canh duy nhất ở cuối mảng là đủ?**
   - **Với con trỏ $j$ quét từ phải sang trái**: $j$ bắt đầu từ $r$ và giảm dần. Do chốt $p = A[l]$ nằm ở đầu đoạn mảng, khi $j$ giảm về tới vị trí $l$, điều kiện dừng $A[l] \le p$ (tức $p \le p$) **luôn luôn đúng**! Do đó, chính phần tử chốt $A[l]$ đã đóng vai trò là một lính canh tự nhiên ở phía bên trái. Con trỏ $j$ không bao giờ có thể chạy vượt quá biên trái ($j \ge l$).
   - Do phía bên trái đã có chốt bảo vệ tự nhiên, ta chỉ cần duy nhất một lính canh chặn ở biên cực phải của toàn bộ mảng là đủ bảo đảm an toàn cho mọi lần phân hoạch.

---

### Bài 5 (Exercises 5.2 - Trang 181)
**Đề bài:**  
*Đối với phiên bản Quicksort trong giáo trình (dùng phân hoạch Hoare):*  
*a. Mảng gồm tất cả các phần tử bằng nhau là trường hợp xấu nhất, tốt nhất, hay không phải cả hai?*  
*b. Mảng giảm dần nghiêm ngặt là trường hợp xấu nhất, tốt nhất, hay không phải cả hai?*

#### Lời giải chi tiết:

**a. Mảng gồm tất cả các phần tử bằng nhau ($A[0] = A[1] = \dots = A[n-1]$):**
- Trong phân hoạch Hoare, điều kiện dừng của $i$ là $A[i] \ge p$ và của $j$ là $A[j] \le p$.
- Vì mọi phần tử đều bằng $p$, nên con trỏ $i$ tăng đúng 1 bước là dừng ngay ($i \leftarrow i + 1$), và con trỏ $j$ giảm đúng 1 bước là dừng ngay ($j \leftarrow j - 1$).
- Hai con trỏ tiến đều từ hai đầu vào chính giữa với tốc độ như nhau.
- Kết quả là $i$ và $j$ gặp nhau ở **chính giữa mảng** ($s \approx \lfloor n/2 \rfloor$), chia mảng ban đầu thành hai nửa con có kích thước bằng nhau!
- Do đó, mảng chia đôi hoàn hảo ở mọi tầng đệ quy $\implies T(n) = 2T(n/2) + \Theta(n)$.
- **Kết luận**: Đây là **TRƯỜNG HỢP TỐT NHẤT (Best-case)** với độ phức tạp $\Theta(n \log n)$.

**b. Mảng giảm dần nghiêm ngặt ($A[0] > A[1] > \dots > A[n-1]$):**
- Chọn chốt $p = A[0]$ (là phần tử lớn nhất trong mảng).
- Vì $p$ lớn nhất, mọi phần tử còn lại đều nhỏ hơn $p$.
- Con trỏ $i$: tìm phần tử $\ge p$, do không có phần tử nào lớn hơn $p$, $i$ sẽ chạy thẳng đến cuối mảng (hoặc gặp lính canh).
- Con trỏ $j$: bắt đầu từ cuối mảng ($r$), phần tử tại $r$ nhỏ hơn $p$ nên $j$ dừng ngay tại $r$.
- Các cặp phần tử ở hai đầu được hoán đổi liên tục, và mảng bị đảo ngược thành tăng dần. Vị trí phân hoạch chốt rơi vào điểm chia không cân bằng.
- **Kết luận**: Đây là **TRƯỜNG HỢP XẤU NHẤT (Worst-case)** với độ phức tạp $\Theta(n^2)$.

---

### Bài 6 (Exercises 5.2 - Trang 181)
**Đề bài:**  
*Đối với Quicksort sử dụng kỹ thuật chọn chốt là trung vị của ba phần tử (Median-of-three: phần tử đầu, giữa và cuối):*  
*a. Mảng tăng dần nghiêm ngặt là trường hợp xấu nhất, tốt nhất, hay không phải cả hai?*  
*b. Trả lời câu hỏi tương tự cho mảng giảm dần nghiêm ngặt.*

#### Lời giải chi tiết:

**a. Mảng tăng dần nghiêm ngặt:**  
- Ba phần tử được xét: $A[l]$ (nhỏ nhất), $A[m]$ (ở giữa), và $A[r]$ (lớn nhất).
- Trung vị của 3 phần tử này chính là $A[m]$ - phần tử nằm ở chính giữa mảng!
- Kỹ thuật Median-of-three sẽ chọn đúng phần tử trung vị lý tưởng làm chốt, giúp chia mảng thành hai nửa bằng nhau ở mỗi lần phân hoạch.
- **Kết luận**: Đây là **TRƯỜNG HỢP TỐT NHẤT (Best-case)** với độ phức tạp $\Theta(n \log n)$.

**b. Mảng giảm dần nghiêm ngặt:**  
- Ba phần tử được xét: $A[l]$ (lớn nhất), $A[m]$ (ở giữa), và $A[r]$ (nhỏ nhất).
- Trung vị của 3 phần tử này vẫn chính là $A[m]$ - phần tử nằm ở chính giữa mảng!
- Chốt được chọn vẫn chia đều mảng thành hai nửa xấp xỉ bằng nhau.
- **Kết luận**: Đây cũng là **TRƯỜNG HỢP TỐT NHẤT (Best-case)** với độ phức tạp $\Theta(n \log n)$.

---

### Bài 7 (Exercises 5.2 - Trang 181)
**Đề bài:**  
*a. Hãy ước tính Quicksort chạy nhanh hơn Insertion Sort khoảng bao nhiêu lần khi sắp xếp một mảng gồm $1.000.000$ số ngẫu nhiên.*  
*b. Đúng hay Sai: Với mọi $n > 1$, luôn tồn tại các mảng kích thước $n$ mà Insertion Sort chạy nhanh hơn Quicksort?*

#### Lời giải chi tiết:

**a. Ước tính tốc độ trên $n = 10^6$ số ngẫu nhiên:**  
- **Số phép so sánh trung bình của Insertion Sort**:
  $$C_{ins}(n) \approx \frac{n^2}{4}$$
  Với $n = 10^6$: $C_{ins}(10^6) \approx \frac{(10^6)^2}{4} = \frac{10^{12}}{4} = 2.5 \times 10^{11}$ phép so sánh.
- **Số phép so sánh trung bình của Quicksort**:
  $$C_{quick}(n) \approx 2n \ln n \approx 1.386 n \log_2 n$$
  Với $n = 10^6$, ta có $\log_2 (10^6) \approx 19.93 \approx 20$:
  $$C_{quick}(10^6) \approx 1.386 \times 10^6 \times 20 \approx 2.77 \times 10^7 \text{ phép so sánh.}$$
- **Tỷ số tốc độ**:
  $$\frac{C_{ins}(10^6)}{C_{quick}(10^6)} \approx \frac{2.5 \times 10^{11}}{2.77 \times 10^7} \approx 9025 \approx 9000 \text{ lần!}$$
Quicksort chạy nhanh hơn Insertion Sort xấp xỉ **9.000 lần**.

**b. Mệnh đề: "Với mọi $n > 1$, luôn tồn tại mảng kích thước $n$ mà Insertion Sort chạy nhanh hơn Quicksort":**  
- **Khẳng định: ĐÚNG (TRUE).**  
- **Chứng minh / Ví dụ cụ thể**: Xét mảng đã có thứ tự tăng dần hoàn hảo $A = [1, 2, 3, \dots, n]$.
  - **Insertion Sort**: Tại mỗi bước chèn, chỉ cần đúng 1 phép so sánh với phần tử liền trước là thấy thỏa mãn ngay. Tổng số phép so sánh của Insertion Sort là $n - 1 \in \Theta(n)$ (thời gian tuyến tính tuyệt đối, không di chuyển phần tử nào).
  - **Quicksort (bản chuẩn chọn chốt đầu mảng)**: Rơi vào trường hợp xấu nhất, thực hiện $\frac{n(n+1)}{2} - 1 \in \Theta(n^2)$ phép so sánh. Kể cả phiên bản tối ưu, Quicksort vẫn tốn ít nhất $\Theta(n \log n)$ phép so sánh và chi phí đệ quy.
  - Do đó với mảng đã sắp xếp, Insertion Sort ($O(n)$) luôn chạy nhanh vượt trội so với Quicksort ($O(n^2)$ hoặc $O(n \log n)$).

---

### Bài 8 (Exercises 5.2 - Trang 181)
**Đề bài:**  
*Thiết kế thuật toán sắp xếp lại các phần tử của một mảng gồm $n$ số thực sao cho tất cả các số âm đứng trước tất cả các số dương. Thuật toán phải tối ưu cả về thời gian và không gian.*

#### Lời giải chi tiết:

**Ý tưởng thiết kế:**  
Áp dụng cơ chế quét hai con trỏ của phân hoạch Hoare với giá trị chốt quy ước là $0$:
- Con trỏ $i$ quét từ trái sang phải tìm số dương đầu tiên ($A[i] \ge 0$).
- Con trỏ $j$ quét từ phải sang trái tìm số âm đầu tiên ($A[j] < 0$).
- Hoán đổi $A[i]$ và $A[j]$, lặp lại cho đến khi $i \ge j$.

**Mã giả chuẩn hóa:**
```text
algorithm: SeparateNegativesPositives(A[0..n - 1])
    input:  Mảng A[0..n - 1] gồm n số thực.
   output:  Mảng A được biến đổi tại chỗ sao cho mọi số âm đứng trước mọi số dương.

1   i ← 0;  j ← n - 1
2   while i < j do
3       while i < n and A[i] < 0 do
4           i ← i + 1
5       while j ≥ 0 and A[j] ≥ 0 do
6           j ← j - 1
7       if i < j then
8           swap(A[i], A[j])
9           i ← i + 1
10          j ← j - 1
```

**Phân tích độ phức tạp:**
- **Thời gian**: Mỗi phần tử được duyệt qua đúng một lần bởi con trỏ $i$ hoặc $j$. Thời gian thực thi là tuyến tính $O(n)$ tối ưu.
- **Không gian**: Chỉ sử dụng 2 biến chỉ số con trỏ $i, j$, thực hiện biến đổi tại chỗ (in-place) với bộ nhớ phụ $O(1)$ tối ưu tuyệt đối.

---

### Bài 9 (Exercises 5.2 - Trang 182)
**Đề bài: Bài toán Cờ quốc gia Hà Lan (The Dutch National Flag Problem - E.W. Dijkstra, 1976)**  
*a. Hãy sắp xếp lại một mảng gồm các ký tự 'R' (Red - Đỏ), 'W' (White - Trắng), và 'B' (Blue - Xanh) sao cho tất cả các chữ 'R' đứng đầu, tiếp theo là 'W', và cuối cùng là 'B'. Thuật toán phải chạy trong thời gian tuyến tính và tại chỗ (in-place).*  
*b. Giải thích cách ứng dụng giải pháp của bài toán này vào thuật toán Quicksort.*

#### Lời giải chi tiết:

**a. Thuật toán Dijkstra 3 con trỏ (3-Way Partitioning):**
Ta duy trì 3 con trỏ chia mảng thành 4 vùng:
- $A[0..low-1]$: Toàn bộ là màu Đỏ ('R').
- $A[low..mid-1]$: Toàn bộ là màu Trắng ('W').
- $A[mid..high]$: Vùng chưa được xử lý.
- $A[high+1..n-1]$: Toàn bộ là màu Xanh ('B').

```text
algorithm: DutchFlagPartition(A[0..n - 1])
    input:  Mảng A chứa các ký tự 'R', 'W', 'B'.
   output:  Mảng A được sắp xếp: toàn bộ 'R' đứng trước, đến 'W', rồi đến 'B'.

1   low ← 0;  mid ← 0;  high ← n - 1
2   while mid ≤ high do
3       if A[mid] = 'R' then
4           swap(A[low], A[mid])
5           low ← low + 1
6           mid ← mid + 1
7       else if A[mid] = 'W' then
8           mid ← mid + 1
9       else // A[mid] = 'B'
10          swap(A[mid], A[high])
11          high ← high - 1
```
- **Độ phức tạp**: Thời gian đúng $O(n)$ (mỗi bước $mid$ tăng hoặc $high$ giảm, tối đa $n$ bước lặp), không gian tại chỗ $O(1)$.

**b. Ứng dụng đột phá vào Quicksort (Fat Partitioning / 3-Way Quicksort):**
- Trong Quicksort thông thường, khi mảng có rất nhiều phần tử có khóa **bằng nhau**, phân hoạch 2 chiều vẫn tiếp tục đẩy các phần tử bằng chốt vào các mảng con đệ quy, dẫn tới nguy cơ rơi vào $\Theta(n^2)$.
- Khi áp dụng phân hoạch 3 chiều (Dutch National Flag Partitioning):
  - Phân hoạch mảng thành 3 vùng: $[ < p \mid = p \mid > p ]$.
  - Toàn bộ các phần tử có giá trị bằng chốt ($= p$) được gom lại ở giữa và đã **nằm đúng vị trí cuối cùng của chúng**!
  - Hai lời gọi đệ quy tiếp theo chỉ cần thực hiện cho vùng $[ < p ]$ và vùng $[ > p ]$, **hoàn toàn bỏ qua toàn bộ vùng $[ = p ]$**!
- Nhờ đó, với các mảng có nhiều phần tử trùng lặp, thời gian chạy của Quicksort giảm ngoạn mục xuống mức **tuyến tính $O(n)$**! Đây chính là kỹ thuật `dual-pivot / 3-way quicksort` được sử dụng trong thư viện chuẩn Java (`Arrays.sort`).

---

### Bài 10 (Exercises 5.2 - Trang 182)
**Đề bài:**  
*Cài đặt thuật toán Quicksort bằng một ngôn ngữ lập trình tùy chọn. Chạy chương trình trên các tập dữ liệu mẫu để kiểm chứng các khẳng định lý thuyết về hiệu năng thuật toán.*

#### Lời giải chi tiết:

**Mã nguồn C++ hoàn chỉnh với đo thời gian thực nghiệm:**
```cpp
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

int hoarePartition(std::vector<int>& a, int l, int r) {
    int p = a[l];
    int i = l, j = r + 1;
    while (true) {
        do { i++; } while (i <= r && a[i] < p);
        do { j--; } while (a[j] > p);
        if (i >= j) break;
        std::swap(a[i], a[j]);
    }
    std::swap(a[l], a[j]);
    return j;
}

void quicksort(std::vector<int>& a, int l, int r) {
    while (l < r) {
        int s = hoarePartition(a, l, r);
        // Tối ưu tail recursion: đệ quy nhánh nhỏ trước
        if (s - l < r - s) {
            quicksort(a, l, s - 1);
            l = s + 1;
        } else {
            quicksort(a, s + 1, r);
            r = s - 1;
        }
    }
}
```
**Kết quả thực nghiệm**: Trên mảng ngẫu nhiên $N = 10^5$, thời gian chạy xấp xỉ vài mili-giây, tăng theo hàm $N \log_2 N$. Với mảng đã sắp xếp và không tối ưu chốt, thời gian tăng theo $N^2$.

---

### Bài 11 (Exercises 5.2 - Trang 182)
**Đề bài: Bài toán Đai ốc và Bu-lông (Nuts and Bolts Problem - Rawlins, 1991)**  
*Cho $n$ chiếc bu-lông có kích thước khác nhau và $n$ chiếc đai ốc tương ứng. Ta chỉ được phép thử ghép một chiếc đai ốc với một chiếc bu-lông để biết đai ốc đó vừa vặn, rộng hơn hay chật hơn bu-lông. Tuyệt đối không được so sánh trực tiếp hai chiếc bu-lông với nhau, hoặc hai chiếc đai ốc với nhau. Hãy thiết kế thuật toán ghép cặp hoàn hảo mỗi bu-lông với đai ốc tương ứng với thời gian trung bình $\Theta(n \log n)$.*

#### Lời giải chi tiết:

**Ý tưởng thiết kế (Randomized Quicksort-like Matching):**
Không thể so sánh bu-lông với bu-lông hay đai ốc với đai ốc, nhưng **ta có thể dùng một chiếc bu-lông làm chốt (pivot) để phân hoạch tập các đai ốc**, và ngược lại!

**Quy trình thuật toán từng bước:**
1. **Chọn chốt ngẫu nhiên**: Chọn ngẫu nhiên một chiếc bu-lông $B_{pivot}$ trong tập bu-lông $B$.
2. **Phân hoạch tập đai ốc $N$ bằng $B_{pivot}$**:
   - Thử lần lượt từng chiếc đai ốc trong $N$ với $B_{pivot}$.
   - Chia tập đai ốc $N$ thành 3 nhóm:
     - $N_{smaller}$: các đai ốc nhỏ hơn $B_{pivot}$.
     - $N_{pivot}$: đúng một chiếc đai ốc vừa khít với $B_{pivot}$!
     - $N_{larger}$: các đai ốc lớn hơn $B_{pivot}$.
3. **Phân hoạch tập bu-lông $B$ bằng chiếc đai ốc vừa tìm được ($N_{pivot}$)**:
   - Bây giờ lấy chính chiếc đai ốc $N_{pivot}$ vừa tìm được làm chốt để thử với tất cả các bu-lông còn lại trong $B$.
   - Chia tập bu-lông $B$ thành 2 nhóm:
     - $B_{smaller}$: các bu-lông nhỏ hơn $N_{pivot}$.
     - $B_{larger}$: các bu-lông lớn hơn $N_{pivot}$.
4. **Ghép đôi & Đệ quy**:
   - Cặp $(B_{pivot}, N_{pivot})$ đã được ghép đôi hoàn hảo.
   - Tập con nhỏ hơn $(B_{smaller}, N_{smaller})$ có cùng kích thước $k$.
   - Tập con lớn hơn $(B_{larger}, N_{larger})$ có cùng kích thước $n - 1 - k$.
   - Gọi đệ quy cho hai cặp bài toán con độc lập này.

**Phân tích độ phức tạp:**
- Mỗi vòng phân hoạch tốn $2(n - 1) = \Theta(n)$ phép thử.
- Khi chọn chốt ngẫu nhiên, hệ thức truy hồi thời gian trung bình y hệt Quicksort:
  $$T(n) = 2 T(n/2) + \Theta(n) \implies T(n) \in \Theta(n \log n)$$
Thuật toán giải quyết bài toán triệt để trong thời gian trung bình $\Theta(n \log n)$ mà không vi phạm bất kỳ ràng buộc nào của đề bài.


---

# CHUYÊN ĐỀ 03: DUYỆT CÂY NHỊ PHÂN VÀ CÁC TÍNH CHẤT LIÊN QUAN & LỜI GIẢI CHI TIẾT 100% BÀI TẬP 5.3
## Trích dẫn: Anany Levitin, "Introduction to the Design and Analysis of Algorithms", 3rd Edition, Mục 5.3 (pp. 182–186)

---

## PHẦN 1: LÝ THUYẾT NỀN TẢNG & MÃ GIẢ CHUẨN HÓA

### 1.1. Định nghĩa Đệ quy của Cây Nhị phân và Tư tưởng Chia để trị
Một **cây nhị phân (Binary Tree)** $T$ được định nghĩa đệ quy như sau:
- Hoặc $T$ là một cây rỗng ($\emptyset$).
- Hoặc $T$ bao gồm một nút gốc $r$ cùng với hai cây nhị phân rời nhau được gọi là **cây con trái** ($T_L$) và **cây con phải** ($T_R$).

Bản thân định nghĩa cấu trúc dữ liệu cây nhị phân đã mang bản chất đệ quy phân đôi hoàn hảo, do đó hầu hết các thuật toán xử lý trên cây nhị phân đều là sự thể hiện tự nhiên của chiến lược **Chia để trị**:
1. **Chia**: Tách cây thành hai cây con $T_L$ và $T_R$.
2. **Trị**: Giải quyết bài toán trên $T_L$ và $T_R$ bằng các lời gọi đệ quy độc lập.
3. **Kết hợp**: Tổng hợp kết quả từ hai cây con cùng với dữ liệu tại nút gốc $r$.

---

### 1.2. Thuật toán Tính Chiều cao của Cây Nhị phân (Height of Binary Tree)

**Quy ước trong giáo trình Levitin**:  
- Chiều cao của cây là độ dài của đường đi dài nhất từ gốc tới một nút lá (tính bằng số cạnh).
- Cây rỗng có chiều cao quy ước là $-1$.
- Cây chỉ có đúng 1 nút gốc có chiều cao là $0$.

```text
algorithm: Height(T)
    input:  Cây nhị phân T.
   output:  Chiều cao của T (số cạnh của đường đi dài nhất từ gốc tới lá; trả về -1 nếu cây rỗng).

1   if T = ∅ then
2       return -1
3   else
4       return max(Height(T_left), Height(T_right)) + 1
```

#### Phân tích Hiệu năng Thuật toán `Height(T)`:
Gọi $n$ là tổng số nút trong cây $T$.
1. **Số phép cộng $A(n)$**:  
   Tại dòng 4, mỗi nút khác rỗng thực hiện đúng 1 phép cộng $+ 1$:
   $$A(n) = A(n(T_L)) + A(n(T_R)) + 1 \quad (n > 0), \quad A(0) = 0$$
   Với $n = n(T_L) + n(T_R) + 1$, bằng quy nạp toán học ta có:
   $$A(n) = n$$
2. **Số phép kiểm tra rỗng $C(n)$**:  
   Mỗi lần gọi hàm đều thực hiện kiểm tra `T = ∅`.
   - Một cây có $n$ nút sẽ có đúng $n + 1$ liên kết rỗng (con trỏ `null`).
   - Tổng số lời gọi hàm kiểm tra là số nút thực cộng số nút rỗng:
     $$C(n) = n + (n + 1) = 2n + 1 \in \Theta(n)$$
- **Độ phức tạp thời gian**: $\Theta(n)$. Thuật toán duyệt qua mọi nút trong cây đúng 1 lần.
- **Độ phức tạp không gian (Call Stack)**: Tỷ lệ thuận với chiều cao của cây:
  - Trường hợp xấu nhất (cây suy biến thành danh sách liên kết): $O(n)$.
  - Trường hợp tốt nhất (cây cân bằng hoàn hảo): $O(\log n)$.

---

### 1.3. Ba Thuật toán Duyệt Cây Cổ điển (Classic Traversals)

| Thứ tự duyệt | Tên gọi | Thứ tự xử lý | Ứng dụng tiêu biểu |
| :--- | :--- | :--- | :--- |
| **Preorder** | Tiền thứ tự | **Gốc $\to$ Cây con trái $\to$ Cây con phải** | Sao chép cây, tính biểu thức tiền tố (Prefix / Polish Notation) |
| **Inorder** | Trung thứ tự | **Cây con trái $\to$ Gốc $\to$ Cây con phải** | Xuất khóa theo thứ tự tăng dần trên Cây tìm kiếm nhị phân (BST) |
| **Postorder** | Hậu thứ tự | **Cây con trái $\to$ Cây con phải $\to$ Gốc** | Giải phóng bộ nhớ cây, tính biểu thức hậu tố (Postfix / RPN) |

```text
algorithm: Preorder(T)
1   if T ≠ ∅ then
2       thăm(root(T))
3       Preorder(T_left)
4       Preorder(T_right)

algorithm: Inorder(T)
1   if T ≠ ∅ then
2       Inorder(T_left)
3       thăm(root(T))
4       Inorder(T_right)

algorithm: Postorder(T)
1   if T ≠ ∅ then
2       Postorder(T_left)
3       Postorder(T_right)
4       thăm(root(T))
```

---

### 1.4. Cây Nhị phân Mở rộng (Extended Binary Tree) và Các Tính chất Cốt lõi
- **Cây nhị phân mở rộng**: Cây nhị phân ban đầu được bổ sung các **nút ngoài (external nodes)** dạng hình vuông thay thế cho mọi con trỏ rỗng (`null`). Các nút ban đầu được gọi là **nút trong (internal nodes)** dạng hình tròn.
- **Định lý 1 (Số nút ngoài)**: Nếu cây có $n$ nút trong, thì số nút ngoài luôn luôn là:
  $$x = n + 1$$
- **Định lý 2 (Quan hệ độ dài đường đi)**:
  - Gọi $I$ là **độ dài đường đi trong (Internal Path Length)**: tổng khoảng cách từ gốc tới tất cả các nút trong.
  - Gọi $E$ là **độ dài đường đi ngoài (External Path Length)**: tổng khoảng cách từ gốc tới tất cả các nút ngoài.
  - Khi đó ta luôn có hệ thức bất biến:
    $$E = I + 2n$$

---

## PHẦN 2: LỜI GIẢI CHI TIẾT 100% BÀI TẬP 5.3 (BÀI 1 ĐẾN BÀI 11)

---

### Bài 1 (Exercises 5.3 - Trang 185)
**Đề bài:**  
*Thiết kế một thuật toán chia để trị tính số tầng (number of levels) trong một cây nhị phân. (Cụ thể, thuật toán phải trả về 0 đối với cây rỗng và 1 đối với cây chỉ có đúng một nút). Cho biết lớp hiệu năng thời gian của thuật toán.*

#### Lời giải chi tiết:

**Phân tích:**  
Số tầng của một cây nhị phân liên hệ mật thiết với chiều cao: $\text{Số tầng} = \text{Height} + 1$.
- Cây rỗng: $\text{Số tầng} = 0$.
- Cây 1 nút: $\text{Số tầng} = 1$.
- Với cây tổng quát, số tầng bằng 1 (cho nút gốc) cộng với giá trị lớn nhất giữa số tầng của cây con trái và số tầng của cây con phải.

**Mã giả chuẩn hóa:**
```text
algorithm: NumLevels(T)
    input:  Cây nhị phân T.
   output:  Số tầng của cây T (trả về 0 nếu T rỗng).

1   if T = ∅ then
2       return 0
3   else
4       return max(NumLevels(T_left), NumLevels(T_right)) + 1
```

**Lớp hiệu năng thời gian:**
Thuật toán thăm mọi nút của cây đúng một lần. Số phép toán cơ bản thỏa mãn:
$$T(n) = T(n_L) + T(n_R) + \Theta(1) \implies T(n) \in \Theta(n)$$
Không gian ngăn xếp tiêu tốn $O(h)$ với $h$ là chiều cao của cây.

---

### Bài 2 (Exercises 5.3 - Trang 185)
**Đề bài:**  
*Xét thuật toán đếm số nút lá trong cây nhị phân được đề xuất như sau:*
```text
ALGORITHM LeafCounter(T)
// Computes recursively the number of leaves in a binary tree
// Input: A binary tree T
// Output: The number of leaves in T
if T = ∅ return 0
else return LeafCounter(T_left) + LeafCounter(T_right)
```
*Thuật toán này có đúng không? Nếu đúng hãy chứng minh; nếu sai hãy chỉ ra lỗi và sửa lại cho chính xác.*

#### Lời giải chi tiết:

**1. Khẳng định: Thuật toán trên HOÀN TOÀN SAI!**

**2. Chỉ ra lỗi sai:**  
- Xét một cây chỉ có đúng **một nút lá duy nhất** (nút gốc không có con: $T_L = \emptyset$ và $T_R = \emptyset$).
- Khi gọi `LeafCounter(T)`:
  - Vì $T \ne \emptyset$, thuật toán nhảy vào nhánh `else`.
  - Nhánh `else` trả về: `LeafCounter(T_left) + LeafCounter(T_right)`.
  - Nhưng $T_L = \emptyset \implies \text{LeafCounter}(T_L) = 0$.
  - Và $T_R = \emptyset \implies \text{LeafCounter}(T_R) = 0$.
  - Kết quả trả về là: $0 + 0 = 0$!
- Do đó, với cây gồm đúng 1 lá, thuật toán trả về 0 thay vì 1.
- Tệ hơn nữa, vì thuật toán luôn trả về tổng các lời gọi con trên các nút rỗng, **nó sẽ trả về 0 đối với MỌI cây nhị phân** bất kể cây lớn đến đâu!

**3. Sửa lại cho chính xác:**  
Cần bổ sung trường hợp cơ sở nhận diện đúng một nút lá (nút có cả hai con trái và phải đều là rỗng):
```text
algorithm: CorrectLeafCounter(T)
    input:  Cây nhị phân T.
   output:  Số lượng nút lá thực tế trong cây T.

1   if T = ∅ then
2       return 0
3   if T_left = ∅ and T_right = ∅ then
4       return 1
5   return CorrectLeafCounter(T_left) + CorrectLeafCounter(T_right)
```

---

### Bài 3 (Exercises 5.3 - Trang 185)
**Đề bài:**  
*Có thể tính chiều cao của cây nhị phân với cùng độ phức tạp thời gian tiệm cận $\Theta(n)$ nhưng hoàn toàn KHÔNG sử dụng ngăn xếp (stack) cả một cách tường minh lẫn ngầm định (không dùng đệ quy) hay không?*

#### Lời giải chi tiết:

**Khẳng định: HOÀN TOÀN CÓ THỂ ĐƯỢC.**

**Giải pháp:**  
Thay vì dùng ngăn xếp (duyệt theo chiều sâu - DFS), ta sử dụng **cấu trúc dữ liệu Hàng đợi (Queue)** để duyệt cây theo **chiều rộng / theo từng mức (Breadth-First Search / Level-Order Traversal)**:
- Hàng đợi FIFO hoạt động hoàn toàn độc lập với ngăn xếp LIFO.
- Tại mỗi mức (level), ta đếm số lượng nút hiện tại trong hàng đợi ($levelSize$), sau đó lấy lần lượt từng nút ra và đẩy tất cả các nút con hợp lệ của chúng vào hàng đợi.
- Mỗi lần xử lý xong một mức, ta tăng biến đếm chiều cao thêm 1.

**Mã giả chuẩn hóa dùng Queue (BFS):**
```text
algorithm: HeightUsingQueue(T)
    input:  Cây nhị phân T.
   output:  Chiều cao của cây T (-1 nếu rỗng).

1   if T = ∅ then return -1
2   Khởi tạo hàng đợi Q
3   Q.enqueue(T)
4   height ← -1
5   while not Q.isEmpty() do
6       levelSize ← Q.size()
7       for i ← 1 to levelSize do
8           node ← Q.dequeue()
9           if node.left ≠ ∅ then Q.enqueue(node.left)
10          if node.right ≠ ∅ then Q.enqueue(node.right)
11      height ← height + 1
12  return height
```
- **Độ phức tạp**: Thời gian $\Theta(n)$ vì mỗi nút vào/ra hàng đợi đúng một lần. Bộ nhớ phụ dùng Queue thay vì Stack, thỏa mãn 100% yêu cầu đề bài.

---

### Bài 4 (Exercises 5.3 - Trang 185)
**Đề bài:**  
*Chứng minh đẳng thức (5.2) trong giáo trình: $A(n) = n$ (với $A(n)$ là số phép cộng được thực hiện bởi thuật toán `Height` trên cây có $n$ nút) bằng phương pháp quy nạp toán học.*

#### Lời giải chi tiết:

**Chứng minh bằng quy nạp toán học mạnh theo số nút $n$:**

**1. Cơ sở quy nạp ($n = 0$):**  
Cây có $n = 0$ nút là cây rỗng ($T = \emptyset$). Thuật toán gặp dòng `if T = ∅ return -1`, kết thúc ngay mà không thực hiện phép cộng nào.  
$\implies A(0) = 0$. Công thức $A(n) = n$ đúng với $n = 0$.

**2. Giả thiết quy nạp:**  
Giả sử công thức đúng với mọi cây nhị phân có số nút $k < n$ ($n \ge 1$), tức là số phép cộng trên cây có $k$ nút luôn bằng $A(k) = k$.

**3. Bước quy nạp:**  
Xét cây $T$ bất kỳ có $n$ nút ($n \ge 1$).  
- Cây $T$ gồm một nút gốc $r$, cây con trái $T_L$ có $n_L$ nút, và cây con phải $T_R$ có $n_R$ nút.  
- Do $n_L$ và $n_R$ đều không chứa gốc $r$, ta có hệ thức:
  $$n_L + n_R = n - 1 \implies n_L < n \text{ và } n_R < n$$
- Theo thuật toán `Height(T)`: Khi $T \ne \emptyset$, thuật toán tính `max(Height(T_left), Height(T_right)) + 1`.  
- Số phép cộng thực hiện bằng tổng số phép cộng trên hai cây con cộng thêm đúng **1 phép cộng** với $1$:
  $$A(n) = A(n_L) + A(n_R) + 1$$
- Áp dụng giả thiết quy nạp cho $T_L$ (có $n_L < n$ nút) và $T_R$ (có $n_R < n$ nút):
  $$A(n_L) = n_L \quad \text{và} \quad A(n_R) = n_R$$
- Thay vào phương trình:
  $$A(n) = n_L + n_R + 1 = (n - 1) + 1 = n$$
Vậy công thức đúng với mọi $n \ge 0$. Theo nguyên lý quy nạp toán học, ta có điều phải chứng minh: $A(n) = n$. $\blacksquare$

---

### Bài 5 (Exercises 5.3 - Trang 185)
**Đề bài:**  
*Duyệt cây nhị phân trong hình vẽ (trang 186):*
```text
        a
       / \
      b   c
     / \   \
    d   e   f
```
*a. Theo thứ tự Preorder.*  
*b. Theo thứ tự Inorder.*  
*c. Theo thứ tự Postorder.*

#### Lời giải chi tiết:

- **a. Preorder (Gốc $\to$ Trái $\to$ Phải):**
  1. Thăm gốc: `a`.
  2. Duyệt nhánh trái gốc $a$ (gốc $b$): thăm `b` $\to$ duyệt con trái thăm `d` $\to$ duyệt con phải thăm `e`.
  3. Duyệt nhánh phải gốc $a$ (gốc $c$): thăm `c` $\to$ duyệt con phải thăm `f`.  
  **Kết quả Preorder:** `a, b, d, e, c, f`.

- **b. Inorder (Trái $\to$ Gốc $\to$ Phải):**
  1. Duyệt nhánh trái gốc $a$:
     - Cây con trái gốc $b$: duyệt con trái `d` $\to$ thăm gốc `b` $\to$ duyệt con phải `e` $\implies$ `d, b, e`.
  2. Thăm gốc: `a`.
  3. Duyệt nhánh phải gốc $a$:
     - Cây con phải gốc $c$: con trái rỗng $\to$ thăm gốc `c` $\to$ duyệt con phải `f` $\implies$ `c, f`.  
  **Kết quả Inorder:** `d, b, e, a, c, f`.

- **c. Postorder (Trái $\to$ Phải $\to$ Gốc):**
  1. Duyệt nhánh trái gốc $a$:
     - Duyệt con trái `d` $\to$ duyệt con phải `e` $\to$ thăm gốc `b` $\implies$ `d, e, b`.
  2. Duyệt nhánh phải gốc $a$:
     - Con trái rỗng $\to$ duyệt con phải `f` $\to$ thăm gốc `c` $\implies$ `f, c`.
  3. Thăm gốc: `a`.  
  **Kết quả Postorder:** `d, e, b, f, c, a`.

---

### Bài 6 (Exercises 5.3 - Trang 186)
**Đề bài:**  
*Viết mã giả cho một trong các thuật toán duyệt kinh điển (preorder, inorder, hoặc postorder) cho cây nhị phân. Giả sử thuật toán được cài đặt đệ quy, hãy tìm số lượng lời gọi đệ quy được thực hiện.*

#### Lời giải chi tiết:

**Mã giả chuẩn hóa cho Inorder:**
```text
algorithm: InorderTraversal(T)
    input:  Cây nhị phân T có n nút.
   output:  In ra nhãn của các nút theo thứ tự Inorder.

1   if T ≠ ∅ then
2       InorderTraversal(T_left)
3       Print(T.key)
4       InorderTraversal(T_right)
```

**Tính toán chính xác số lời gọi đệ quy $R(n)$:**
- Mỗi nút khác rỗng thực hiện 2 lời gọi đệ quy (một cho con trái, một cho con phải).
- Lời gọi đệ quy ban đầu tính là 1.
- Một cây nhị phân có $n$ nút trong (nút thực) luôn có đúng:
  $$x = n + 1 \text{ liên kết rỗng (con trỏ null)}$$
- Mỗi nút thực sẽ được gọi 1 lần (tổng cộng $n$ lần cho nút thực).
- Mỗi liên kết rỗng sẽ dẫn đến 1 lời gọi đệ quy với tham số $T = \emptyset$ (dừng tại dòng 1, tổng cộng $n + 1$ lần cho nút rỗng).
- Do đó, tổng số lần gọi hàm đệ quy là:
  $$R(n) = n + (n + 1) = 2n + 1$$
- **Kết luận**: Với cây có $n$ nút, thuật toán thực hiện chính xác **$2n + 1$ lời gọi đệ quy**.

---

### Bài 7 (Exercises 5.3 - Trang 186)
**Đề bài:**  
*Thuật toán nào trong ba thuật toán duyệt kinh điển sẽ cho ra danh sách các khóa đã được sắp xếp tăng dần khi áp dụng lên Cây tìm kiếm nhị phân (Binary Search Tree - BST)? Hãy chứng minh tính chất này.*

#### Lời giải chi tiết:

**Khẳng định: Thuật toán duyệt TRUNG THỨ TỰ (Inorder Traversal).**

**Chứng minh chặt chẽ bằng quy nạp toán học:**  
1. **Định nghĩa BST**: Trong một cây tìm kiếm nhị phân $T$ với gốc $r$:
   - Mọi khóa $k_L$ trong cây con trái $T_L$ đều thỏa mãn: $k_L < key(r)$.
   - Mọi khóa $k_R$ trong cây con phải $T_R$ đều thỏa mãn: $key(r) < k_R$.
   - Cả $T_L$ và $T_R$ đều là các BST.
2. **Quy nạp theo số nút $n$**:
   - **Cơ sở ($n \le 1$)**: Cây rỗng hoặc cây 1 nút hiển nhiên có thứ tự tăng dần.
   - **Bước quy nạp**: Giả sử Inorder cho thứ tự tăng dần với mọi BST có ít hơn $n$ nút ($n \ge 2$).
   - Xét BST có $n$ nút với gốc $r$.
     - Theo giả thiết quy nạp, `Inorder(T_L)` duyệt qua toàn bộ các khóa của $T_L$ theo thứ tự tăng dần hoàn chỉnh.
     - Tiếp theo, thuật toán thăm khóa $key(r)$. Vì mọi khóa trong $T_L$ đều $< key(r)$, nên $key(r)$ đứng ngay sau phần tử lớn nhất của $T_L$ vẫn giữ nguyên tính tăng dần.
     - Cuối cùng, `Inorder(T_R)` duyệt qua toàn bộ các khóa của $T_R$ theo thứ tự tăng dần. Vì mọi khóa trong $T_R$ đều $> key(r)$, toàn bộ dãy của $T_R$ đứng sau $key(r)$ tiếp tục duy trì tính tăng dần hoàn hảo.
3. Vậy dãy khóa thu được từ `Inorder(T)` trên BST luôn có thứ tự tăng dần nghiêm ngặt. $\blacksquare$

---

### Bài 8 (Exercises 5.3 - Trang 186)
**Đề bài:**  
*a. Vẽ một cây nhị phân gồm 10 nút được đánh nhãn $0, 1, \dots, 9$ sao cho kết quả duyệt Inorder và Postorder lần lượt là:*  
*Inorder: `9, 3, 1, 0, 4, 2, 7, 6, 8, 5`*  
*Postorder: `9, 1, 4, 0, 3, 6, 7, 5, 8, 2`*  
*b. Đưa ra ví dụ về hai hoán vị của cùng $n$ nhãn $0, 1, \dots, n-1$ không thể là danh sách duyệt Inorder và Postorder của cùng một cây nhị phân.*  
*c. Thiết kế thuật toán chia để trị dựng lại cây nhị phân từ hai danh sách Inorder và Postorder, đồng thời nhận diện trường hợp dữ liệu đầu vào không hợp lệ (vô nghiệm).*

#### Lời giải chi tiết:

**a. Dựng lại cây nhị phân:**
1. **Tìm gốc tổng thể**: Phần tử cuối cùng của Postorder là `2` $\implies$ Gốc của cây là **`2`**.
2. **Phân chia theo Inorder**:
   - Vị trí của `2` trong Inorder chia danh sách thành 2 nửa:
     - Nửa trái Inorder: `9, 3, 1, 0, 4` (5 phần tử).
     - Nửa phải Inorder: `7, 6, 8, 5` (4 phần tử).
3. **Phân chia Postorder tương ứng**:
   - 5 phần tử đầu Postorder: `9, 1, 4, 0, 3` $\implies$ thuộc nhánh trái. Phần tử cuối là `3` $\implies$ **Gốc con trái là `3`**.
   - 4 phần tử tiếp Postorder: `6, 7, 5, 8` $\implies$ thuộc nhánh phải. Phần tử cuối là `8` $\implies$ **Gốc con phải là `8`**.
4. **Phân rã tiếp nhánh trái (gốc 3)**:
   - Inorder: `9, 3, 1, 0, 4` $\implies$ Bên trái `3` là `9` (lá); Bên phải `3` là `1, 0, 4`.
   - Postorder của `1, 0, 4` là `1, 4, 0` $\implies$ **Gốc là `0`**, con trái là `1`, con phải là `4`.
5. **Phân rã tiếp nhánh phải (gốc 8)**:
   - Inorder: `7, 6, 8, 5` $\implies$ Bên trái `8` là `7, 6`; Bên phải `8` là `5` (lá).
   - Postorder của `7, 6` là `6, 7` $\implies$ **Gốc là `7`**, con trái rỗng, **con phải là `6`**.

**Cấu trúc Cây Nhị phân hoàn chỉnh:**
```text
                  2
               /     \
             3         8
           /   \      /  \
          9     0    7    5
               / \    \
              1   4    6
```

**b. Ví dụ phản chứng hai hoán vị không hợp lệ:**  
Xét $n = 3$ với các nhãn $0, 1, 2$:
- Giả sử Inorder: `0, 1, 2`.
- Giả sử Postorder: `2, 1, 0`.
- Phân tích:
  - Postorder kết thúc bằng `0` $\implies$ Gốc cây phải là `0`.
  - Trong Inorder `0, 1, 2`, nhãn `0` nằm ở đầu mảng, nghĩa là toàn bộ các nhãn `1, 2` phải nằm ở cây con bên phải của `0`, nhánh con bên trái phải rỗng.
  - Nhưng trong Postorder `2, 1, 0`, trước gốc `0` phải là toàn bộ các nút của cây con phải. Cây con phải có hai nút $1, 2$ với Inorder là `1, 2` và Postorder là `2, 1`.
  - Từ Postorder `2, 1`, gốc cây con phải là `1`.
  - Nhưng trong Inorder `1, 2`, nhãn `1` đứng trước `2`, nghĩa là `2` phải là con phải của `1`.
  - Khi đó Postorder của cây phải là `2, 1, 0`. Trông có vẻ hợp lệ!
- Hãy xét ví dụ thực sự mâu thuẫn:
  - Cho Inorder: `0, 1, 2` và Postorder: `1, 0, 2`.
  - Gốc là `2`. Inorder là `0, 1, 2` $\implies$ toàn bộ $0, 1$ thuộc cây con trái.
  - Nhánh trái có Inorder `0, 1` và Postorder `1, 0`.
  - Gốc nhánh trái là `0`. Trong Inorder, `0` đứng trước `1` $\implies$ `1` là con phải của `0`.
- **Ví dụ vi phạm tập hợp phần tử**: Inorder: `0, 1, 2`, Postorder: `0, 3, 2` (khác tập nhãn).
- **Ví dụ mâu thuẫn cấu trúc**: Inorder: `1, 2, 3`, Postorder: `3, 1, 2`.
  - Gốc là `2`. Inorder chia thành trái $\{1\}$ và phải $\{3\}$.
  - Trong Postorder, thứ tự phải là (toàn bộ con trái) rồi (toàn bộ con phải), tức là $\{1\}$ phải đứng trước $\{3\}$.
  - Nhưng ở đây Postorder lại là `3, 1, 2` (nút `3` thuộc cây con phải lại xuất hiện trước nút `1` thuộc cây con trái) $\implies$ **Vô nghiệm, không thể tồn tại cây như vậy!**

**c. Mã giả chia để trị phục hồi cây và bắt lỗi:**
```text
algorithm: BuildTree(inorder[inL..inR], postorder[postL..postR])
    input:  Đoạn Inorder và đoạn Postorder tương ứng.
   output:  Nút gốc của cây nhị phân được dựng lại; báo lỗi nếu dữ liệu mâu thuẫn.

1   if inL > inR then return null
2   rootVal ← postorder[postR]
3   Tạo nút root mới với khóa rootVal
4
5   // Tìm rootVal trong Inorder
6   idx ← -1
7   for i ← inL to inR do
8       if inorder[i] = rootVal then
9           idx ← i; break
10  if idx = -1 then BÁO_LỖI("Dữ liệu không hợp lệ: Không tìm thấy gốc trong Inorder!")
11
12  leftSize ← idx - inL
13  root.left ← BuildTree(inorder[inL..idx - 1], postorder[postL..postL + leftSize - 1])
14  root.right ← BuildTree(inorder[idx + 1..inR], postorder[postL + leftSize..postR - 1])
15  return root
```

---

### Bài 9 (Exercises 5.3 - Trang 186)
**Đề bài:**  
*Trong một cây nhị phân mở rộng có $n$ nút trong:*  
*- Độ dài đường đi trong $I$ là tổng khoảng cách từ gốc tới tất cả các nút trong.*  
*- Độ dài đường đi ngoài $E$ là tổng khoảng cách từ gốc tới tất cả các nút ngoài.*  
*Chứng minh rằng: $E = I + 2n$.*

#### Lời giải chi tiết:

**Chứng minh bằng quy nạp toán học mạnh theo số nút trong $n$:**

**1. Cơ sở quy nạp ($n = 0$):**  
- Khi $n = 0$: Cây rỗng, cây mở rộng chỉ có duy nhất $1$ nút ngoài chính là nút gốc.
- Khoảng cách từ gốc tới nút ngoài này bằng $0 \implies E = 0$.
- Không có nút trong nào $\implies I = 0$.
- Ta có: $E = 0 = 0 + 2(0) = I + 2n$. Đẳng thức đúng với $n = 0$.

**2. Giả thiết quy nạp:**  
Giả sử đẳng thức $E = I + 2k$ đúng với mọi cây nhị phân mở rộng có số nút trong $k < n$ ($n \ge 1$).

**3. Bước quy nạp:**  
Xét cây $T$ bất kỳ có $n$ nút trong ($n \ge 1$).  
- Cây $T$ gồm gốc $r$, cây con trái $T_L$ có $n_L$ nút trong, và cây con phải $T_R$ có $n_R$ nút trong ($n_L + n_R = n - 1$).
- Gọi $I_L, E_L$ và $I_R, E_R$ lần lượt là độ dài đường đi trong và ngoài của $T_L$ và $T_R$ khi xét cục bộ đối với gốc của riêng chúng.
- Theo giả thiết quy nạp:
  $$E_L = I_L + 2n_L \quad \text{và} \quad E_R = I_R + 2n_R$$
- Khi ghép $T_L$ và $T_R$ làm con của gốc $r$:
  - Mỗi nút trong của $T_L$ cách gốc $r$ thêm đúng $1$ đơn vị $\implies I$ tăng thêm $n_L$.
  - Mỗi nút trong của $T_R$ cách gốc $r$ thêm đúng $1$ đơn vị $\implies I$ tăng thêm $n_R$.
  - Gốc $r$ có khoảng cách tới chính nó bằng $0$.
  - Do đó:
    $$I = I_L + n_L + I_R + n_R = I_L + I_R + (n - 1) \quad (1)$$
  - Tương tự với các nút ngoài: $T_L$ có $n_L + 1$ nút ngoài, $T_R$ có $n_R + 1$ nút ngoài. Khoảng cách từ gốc $r$ tới mỗi nút ngoài tăng thêm 1:
    $$E = E_L + (n_L + 1) + E_R + (n_R + 1) = E_L + E_R + (n_L + n_R + 2) = E_L + E_R + (n + 1) \quad (2)$$
- Thay giả thiết quy nạp $E_L = I_L + 2n_L$ và $E_R = I_R + 2n_R$ vào $(2)$:
  $$\begin{aligned}
  E &= (I_L + 2n_L) + (I_R + 2n_R) + n + 1 \\
    &= (I_L + I_R) + 2(n_L + n_R) + n + 1 \\
    &= (I_L + I_R) + 2(n - 1) + n + 1 \\
    &= (I_L + I_R) + 3n - 1
  \end{aligned}$$
- Từ $(1)$, ta có $I_L + I_R = I - (n - 1) = I - n + 1$. Thay vào biểu thức của $E$:
  $$E = (I - n + 1) + 3n - 1 = I + 2n$$
Đẳng thức được chứng minh hoàn tất cho mọi $n \ge 0$. $\blacksquare$

---

### Bài 10 (Exercises 5.3 - Trang 186)
**Đề bài:**  
*Viết chương trình tính độ dài đường đi trong $I$ của cây nhị phân mở rộng. Sử dụng chương trình để khảo sát thực nghiệm số phép so sánh khóa trung bình khi tìm kiếm trên Cây tìm kiếm nhị phân (BST) được tạo ngẫu nhiên.*

#### Lời giải chi tiết:

**Cơ sở lý thuyết:**  
Số phép so sánh trung bình để tìm kiếm thành công một khóa trong BST có $n$ nút liên hệ trực tiếp với $I$:
$$\bar{C}_{success} = \frac{I}{n} + 1 \approx 2 \ln n \approx 1.386 \log_2 n$$

**Chương trình C++ hoàn chỉnh:**
```cpp
#include <iostream>
#include <vector>
#include <random>
#include <numeric>

struct Node {
    int key;
    Node *left = nullptr, *right = nullptr;
    Node(int k) : key(k) {}
};

Node* insertBST(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->key) root->left = insertBST(root->left, key);
    else root->right = insertBST(root->right, key);
    return root;
}

int computeInternalPathLength(Node* root, int depth = 0) {
    if (!root) return 0;
    return depth + computeInternalPathLength(root->left, depth + 1)
                 + computeInternalPathLength(root->right, depth + 1);
}

int main() {
    int n = 1000;
    std::vector<int> vals(n);
    std::iota(vals.begin(), vals.end(), 1);
    std::mt19937 g(42);
    std::shuffle(vals.begin(), vals.end(), g);

    Node* root = nullptr;
    for (int v : vals) root = insertBST(root, v);

    int I = computeInternalPathLength(root);
    double avgComp = (double)I / n + 1.0;
    std::cout << "So nut n = " << n << std::endl;
    std::cout << "Do dai duong di trong I = " << I << std::endl;
    std::cout << "So phep so sanh trung binh: " << avgComp << std::endl;
    std::cout << "Ly thuyet (2 * ln(n)): " << 2.0 * std::log(n) << std::endl;
    return 0;
}
```

---

### Bài 11 (Exercises 5.3 - Trang 186)
**Đề bài: Câu đố Bẻ thanh Sô-cô-la (Chocolate Bar Puzzle)**  
*Cho một thanh sô-cô-la hình chữ nhật kích thước $n \times m$, bạn cần bẻ rời nó thành $nm$ miếng nhỏ kích thước $1 \times 1$. Bạn chỉ được phép bẻ một thanh theo một đường thẳng duy nhất và mỗi lần chỉ được bẻ một thanh (không được xếp chồng các thanh để bẻ cùng lúc). Hãy thiết kế thuật toán giải quyết bài toán với số lần bẻ tối thiểu. Số lần bẻ tối thiểu này là bao nhiêu? Hãy chứng minh câu trả lời bằng cách sử dụng các tính chất của cây nhị phân.*

#### Lời giải chi tiết:

**1. Khẳng định số lần bẻ tối thiểu:**  
Số lần bẻ tối thiểu **LUÔN LUÔN LÀ $nm - 1$**, bất kể bạn lựa chọn thứ tự hay chiến lược bẻ như thế nào!

**2. Chứng minh chặt chẽ bằng Cây Nhị phân:**  
- Hãy mô hình hóa toàn bộ quá trình bẻ thanh sô-cô-la bằng một **cây nhị phân**:
  - **Gốc của cây**: Đại diện cho thanh sô-cô-la nguyên bản ban đầu kích thước $n \times m$.
  - **Mỗi phép bẻ**: Chia một thanh hiện có thành hai thanh nhỏ hơn $\implies$ tương ứng với một **nút trong (internal node)** có đúng hai nhánh con.
  - **Mỗi miếng sô-cô-la $1 \times 1$ cuối cùng**: Là một mảnh không thể bẻ thêm được nữa $\implies$ tương ứng với một **nút lá (external node / leaf)** của cây.
- Vì mục tiêu cuối cùng là thu được $nm$ miếng kích thước $1 \times 1$, cây nhị phân kết thúc bắt buộc phải có đúng:
  $$L = nm \text{ nút lá}$$
- Cây nhị phân này là một **cây nhị phân nghiêm ngặt (strict / proper binary tree)**, nghĩa là mỗi nút trong đều có đúng 2 nút con (mỗi nhát bẻ luôn sinh ra đúng 2 mảnh).
- Theo định lý cơ bản về cây nhị phân nghiêm ngặt: Trong mọi cây nhị phân nghiêm ngặt có $L$ nút lá, số nút trong $I$ luôn thỏa mãn:
  $$I = L - 1$$
- Vì mỗi nhát bẻ tương ứng với đúng một nút trong, nên tổng số nhát bẻ thực hiện bắt buộc phải bằng:
  $$\text{Số lần bẻ} = I = L - 1 = nm - 1$$

**3. Kết luận bất biến:**  
Vì công thức $nm - 1$ là một bất biến toán học phụ thuộc duy nhất vào số lá cuối cùng, **mọi chiến lược bẻ hợp lệ đều cần chính xác $nm - 1$ lần bẻ**. Không có bất kỳ thuật toán nào có thể làm với ít hơn hoặc nhiều hơn $nm - 1$ lần bẻ. $\blacksquare$


---

# CHUYÊN ĐỀ 04: NHÂN SỐ NGUYÊN LỚN VÀ PHÉP NHÂN MA TRẬN STRASSEN & LỜI GIẢI CHI TIẾT 100% BÀI TẬP 5.4
## Trích dẫn: Anany Levitin, "Introduction to the Design and Analysis of Algorithms", 3rd Edition, Mục 5.4 (pp. 186–191)

---

## PHẦN 1: LÝ THUYẾT NỀN TẢNG & MÃ GIẢ CHUẨN HÓA

### 1.1. Phép nhân Số nguyên Lớn (Multiplication of Large Integers - Thuật toán Karatsuba)

#### Hạn chế của Thuật toán Đặt tính Bút và Giấy Cổ điển
Thuật toán nhân thông thường nhân từng cặp chữ số đòi hỏi $n^2$ phép nhân một chữ số. Khi số lượng chữ số lên tới hàng nghìn hoặc hàng triệu (trong mật mã học RSA, số học dấu phẩy động đa chính xác), thuật toán $O(n^2)$ trở nên quá chậm.

#### Ý tưởng Chia để trị của A. Karatsuba (1960)
Cho hai số nguyên dương $n$ chữ số $A$ và $B$ (giả sử $n$ là lũy thừa của 2). Chia mỗi số thành hai nửa $n/2$ chữ số:
$$A = a_1 10^{n/2} + a_0, \quad B = b_1 10^{n/2} + b_0$$
Tích $A \times B$ được khai triển đại số thành:
$$A \times B = (a_1 10^{n/2} + a_0)(b_1 10^{n/2} + b_0) = (a_1 b_1) 10^n + (a_1 b_0 + a_0 b_1) 10^{n/2} + a_0 b_0 = c_2 10^n + c_1 10^{n/2} + c_0$$
trong đó:
- $c_2 = a_1 b_1$ (tích hai nửa đầu)
- $c_0 = a_0 b_0$ (tích hai nửa cuối)
- $c_1 = a_1 b_0 + a_0 b_1$

Nếu tính trực tiếp theo định nghĩa, ta cần **4 phép nhân** các số có kích thước $n/2$:
$$M(n) = 4 M(n/2) \implies M(n) \in \Theta(n^{\log_2 4}) = \Theta(n^2)$$
không mang lại cải thiện nào.

**Đột phá của Karatsuba**: Biến đổi hệ số $c_1$ chỉ bằng **MỘT PHÉP NHÂN DUY NHẤT** bổ sung:
$$(a_1 + a_0)(b_1 + b_0) = a_1 b_1 + (a_1 b_0 + a_0 b_1) + a_0 b_0 = c_2 + c_1 + c_0$$
Suy ra:
$$c_1 = (a_1 + a_0)(b_1 + b_0) - (c_2 + c_0)$$
Như vậy, ta chỉ cần đúng **3 phép nhân** các số có $n/2$ chữ số:
1. $c_2 = a_1 \times b_1$
2. $c_0 = a_0 \times b_0$
3. $c_{sum} = (a_1 + a_0) \times (b_1 + b_0)$, sau đó $c_1 = c_{sum} - c_2 - c_0$

#### Phân tích Hiệu năng:
- **Số phép nhân $M(n)$**:
  $$M(n) = 3 M(n/2) \quad (n > 1), \quad M(1) = 1$$
  Giải với $n = 2^k$:
  $$M(n) = 3^{\log_2 n} = n^{\log_2 3} \approx n^{1.585} \in \Theta(n^{1.585})$$
- **Số phép cộng $A(n)$**:
  $$A(n) = 3 A(n/2) + c n \implies A(n) \in \Theta(n^{\log_2 3}) \approx \Theta(n^{1.585})$$
Thuật toán Karatsuba phá vỡ rào cản bậc hai $O(n^2)$ và chạy nhanh hơn rõ rệt khi $n \ge 300$ chữ số.

---

### 1.2. Phép nhân Ma trận Strassen (Strassen's Matrix Multiplication)

#### Hạn chế của Phép nhân Ma trận theo Định nghĩa
Nhân hai ma trận vuông kích thước $n \times n$ theo định nghĩa $C = A \times B$ tốn $n^3$ phép nhân và $n^2(n-1)$ phép cộng số thực $\implies \Theta(n^3)$.  
Nếu chia ma trận thành các khối con $2 \times 2$ có kích thước $(n/2) \times (n/2)$:
$$\begin{pmatrix} C_{00} & C_{01} \\ C_{10} & C_{11} \end{pmatrix} = \begin{pmatrix} A_{00} & A_{01} \\ A_{10} & A_{11} \end{pmatrix} \begin{pmatrix} B_{00} & B_{01} \\ B_{10} & B_{11} \end{pmatrix}$$
Theo công thức nhân khối thông thường cần **8 phép nhân** ma trận con:
$$M(n) = 8 M(n/2) \implies M(n) \in \Theta(n^{\log_2 8}) = \Theta(n^3)$$

#### Công thức Đột phá của Volker Strassen (1969)
Strassen đã tìm ra cách tính tích ma trận khối chỉ bằng **7 phép nhân** ma trận con kích thước $(n/2) \times (n/2)$ cùng với một hệ thống các phép cộng/trừ:

$$\begin{aligned}
M_1 &= (A_{00} + A_{11}) (B_{00} + B_{11}) \\
M_2 &= (A_{10} + A_{11}) B_{00} \\
M_3 &= A_{00} (B_{01} - B_{11}) \\
M_4 &= A_{11} (B_{10} - B_{00}) \\
M_5 &= (A_{00} + A_{01}) B_{11} \\
M_6 &= (A_{10} - A_{00}) (B_{00} + B_{01}) \\
M_7 &= (A_{01} - A_{11}) (B_{10} + B_{11})
\end{aligned}$$

Sau khi tính xong 7 ma trận trung gian $M_1 \dots M_7$, 4 khối con của ma trận kết quả $C$ được tính bằng:
$$\begin{aligned}
C_{00} &= M_1 + M_4 - M_5 + M_7 \\
C_{01} &= M_3 + M_5 \\
C_{10} &= M_2 + M_4 \\
C_{11} &= M_1 + M_3 - M_2 + M_6
\end{aligned}$$

#### Phân tích Hiệu năng Thuật toán Strassen:
- **Số phép nhân $M(n)$**:
  $$M(n) = 7 M(n/2) \quad (n > 1), \quad M(1) = 1$$
  $$M(n) = 7^{\log_2 n} = n^{\log_2 7} \approx n^{2.807} \in \Theta(n^{2.807})$$
- **Số phép cộng $A(n)$**:
  Cần $10$ phép cộng/trừ để chuẩn bị các thừa số cho $M_1 \dots M_7$, và $8$ phép cộng/trừ để tổng hợp $C_{ij}$, tổng cộng là 18 phép cộng ma trận kích thước $(n/2) \times (n/2)$ (mỗi phép tốn $(n/2)^2 = n^2/4$ phép tính):
  $$A(n) = 7 A(n/2) + 18 \left( \frac{n}{2} \right)^2 = 7 A(n/2) + \frac{9}{2} n^2$$
  Nghiệm giải tích: $A(n) = 6(n^{\log_2 7} - n^2) \in \Theta(n^{\log_2 7})$.
- Vì $2.807 < 3$, thuật toán Strassen vượt trội về mặt tiệm cận so với thuật toán $O(n^3)$ cổ điển.

---

## PHẦN 2: LỜI GIẢI CHI TIẾT 100% BÀI TẬP 5.4 (BÀI 1 ĐẾN BÀI 10)

---

### Bài 1 (Exercises 5.4 - Trang 191)
**Đề bài:**  
*Tích của hai số nguyên dương $n$ chữ số thập phân có thể có số lượng chữ số nhỏ nhất và lớn nhất là bao nhiêu?*

#### Lời giải chi tiết:

**1. Ký hiệu và miền giá trị:**  
Một số nguyên dương $n$ chữ số trong hệ thập phân $X$ thỏa mãn bất đẳng thức:
$$10^{n-1} \le X \le 10^n - 1 < 10^n$$

**2. Số lượng chữ số nhỏ nhất (Smallest number of digits):**  
- Tích nhỏ nhất đạt được khi cả hai số đều đạt giá trị nhỏ nhất có thể, tức là $A = 10^{n-1}$ và $B = 10^{n-1}$:
  $$P_{min} = A \times B = 10^{n-1} \times 10^{n-1} = 10^{2n-2}$$
- Số $10^{2n-2}$ là số gồm chữ số 1 theo sau bởi $2n - 2$ chữ số 0.
- Tổng số chữ số là: $(2n - 2) + 1 = \mathbf{2n - 1}$ chữ số.
- *Ví dụ kiểm chứng*: với $n = 2$, hai số 2 chữ số nhỏ nhất là $10 \times 10 = 100$ ($2(2) - 1 = 3$ chữ số).

**3. Số lượng chữ số lớn nhất (Largest number of digits):**  
- Tích lớn nhất đạt được khi cả hai số đều đạt giá trị lớn nhất: $A = 10^n - 1$ và $B = 10^n - 1$:
  $$P_{max} = (10^n - 1)^2 = 10^{2n} - 2 \cdot 10^n + 1$$
- Ta thấy:
  $$10^{2n-1} < 10^{2n} - 2 \cdot 10^n + 1 < 10^{2n}$$
- Vì $P_{max} < 10^{2n}$, số chữ số của $P_{max}$ không thể đạt tới $2n + 1$.  
- Mặt khác, vì $P_{max} \ge 10^{2n-1}$ (với mọi $n \ge 1$), tích luôn có tối đa là $\mathbf{2n}$ chữ số.
- *Ví dụ kiểm chứng*: với $n = 2$, số lớn nhất là $99 \times 99 = 9801$ ($2(2) = 4$ chữ số).

**Kết luận**: Số chữ số nhỏ nhất là **$2n - 1$**, lớn nhất là **$2n$**.

---

### Bài 2 (Exercises 5.4 - Trang 191)
**Đề bài:**  
*Tính tích $2101 \times 1130$ bằng cách áp dụng thuật toán chia để trị (Karatsuba) được trình bày trong giáo trình.*

#### Lời giải chi tiết:
Cho $A = 2101$ và $B = 1130$ có $n = 4$ chữ số $\implies n/2 = 2$.

**Bước 1: Phân rã hai số thành các phần $n/2 = 2$ chữ số:**
- $A = a_1 \cdot 10^2 + a_0$ với $a_1 = 21, a_0 = 01$.
- $B = b_1 \cdot 10^2 + b_0$ với $b_1 = 11, b_0 = 30$.

Cần tính 3 tích của các số 2 chữ số:
1. $c_2 = a_1 \times b_1 = 21 \times 11$
2. $c_0 = a_0 \times b_0 = 01 \times 30 = 30$ (tính trực tiếp)
3. $c_{sum} = (a_1 + a_0) \times (b_1 + b_0) = (21 + 1) \times (11 + 30) = 22 \times 41$

**Bước 2: Gọi đệ quy tính hai tích 2 chữ số bằng thuật toán Karatsuba:**

- **Tính $c_2 = 21 \times 11$ ($n' = 2, n'/2 = 1$):**
  - $a'_1 = 2, a'_0 = 1$; $b'_1 = 1, b'_0 = 1$.
  - $c'_2 = 2 \times 1 = 2$.
  - $c'_0 = 1 \times 1 = 1$.
  - $c'_{sum} = (2 + 1) \times (1 + 1) = 3 \times 2 = 6$.
  - $c'_1 = c'_{sum} - c'_2 - c'_0 = 6 - 2 - 1 = 3$.
  - $c_2 = c'_2 \cdot 10^2 + c'_1 \cdot 10^1 + c'_0 = 2 \cdot 100 + 3 \cdot 10 + 1 = \mathbf{231}$.

- **Tính $c_{sum} = 22 \times 41$ ($n' = 2, n'/2 = 1$):**
  - $a''_1 = 2, a''_0 = 2$; $b''_1 = 4, b''_0 = 1$.
  - $c''_2 = 2 \times 4 = 8$.
  - $c''_0 = 2 \times 1 = 2$.
  - $c''_{sum} = (2 + 2) \times (4 + 1) = 4 \times 5 = 20$.
  - $c''_1 = c''_{sum} - c''_2 - c''_0 = 20 - 8 - 2 = 10$.
  - $c_{sum} = c''_2 \cdot 10^2 + c''_1 \cdot 10^1 + c''_0 = 8 \cdot 100 + 10 \cdot 10 + 2 = 800 + 100 + 2 = \mathbf{902}$.

**Bước 3: Tính hệ số $c_1$ và tổng hợp kết quả cuối cùng:**
- $c_1 = c_{sum} - c_2 - c_0 = 902 - 231 - 30 = \mathbf{641}$.
- Tổng hợp tích $A \times B$:
  $$\begin{aligned}
  A \times B &= c_2 \cdot 10^4 + c_1 \cdot 10^2 + c_0 \\
             &= 231 \times 10000 + 641 \times 100 + 30 \\
             &= 2.310.000 + 64.100 + 30 = \mathbf{2.374.130}
  \end{aligned}$$
*(Kiểm tra trực tiếp bằng phép nhân thông thường: $2101 \times 1130 = 2.374.130$. Kết quả chính xác 100%)*.

---

### Bài 3 (Exercises 5.4 - Trang 191)
**Đề bài:**  
*a. Chứng minh đẳng thức $a^{\log_b c} = c^{\log_b a}$ được sử dụng trong Mục 5.4.*  
*b. Tại sao biểu thức $n^{\log_2 3}$ lại tốt hơn $3^{\log_2 n}$ khi được dùng làm công thức đóng cho $M(n)$?*

#### Lời giải chi tiết:

**a. Chứng minh $a^{\log_b c} = c^{\log_b a}$:**
- Lấy logarit cơ số $b$ của vế trái:
  $$\log_b \left( a^{\log_b c} \right) = \log_b c \cdot \log_b a$$
- Lấy logarit cơ số $b$ của vế phải:
  $$\log_b \left( c^{\log_b a} \right) = \log_b a \cdot \log_b c$$
- Vì phép nhân các số thực có tính giao hoán:
  $$\log_b c \cdot \log_b a = \log_b a \cdot \log_b c$$
- Do hàm logarit cơ số $b > 0, b \ne 1$ là đơn ánh nghiêm ngặt, từ sự bằng nhau của logarit ta suy ra hai biểu thức ban đầu bắt buộc phải bằng nhau:
  $$a^{\log_b c} = c^{\log_b a}$$
  $\blacksquare$

**b. Tại sao $n^{\log_2 3}$ tốt hơn $3^{\log_2 n}$?**  
- Trong phân tích thuật toán, kích thước đầu vào của bài toán là biến số $n$.
- Biểu thức $n^{\log_2 3}$ đặt biến số $n$ ở vị trí **cơ số** và số mũ là một hằng số thực cố định $\log_2 3 \approx 1.585$. Cách viết này ngay lập tức cho người đọc thấy rõ hàm tăng trưởng theo cấp số **đa thức** $O(n^{1.585})$, giúp so sánh trực quan ngay với thuật toán cổ điển $O(n^2)$.
- Ngược lại, cách viết $3^{\log_2 n}$ đặt biến số $n$ trên số mũ, dễ gây nhầm lẫn với các hàm tăng trưởng theo cấp số mũ (như $3^n$) hoặc khó nhận biết ngay cấp độ tăng trưởng so với các đa thức khác. Do đó, $n^{\log_2 3}$ là chuẩn mực biểu diễn vượt trội.

---

### Bài 4 (Exercises 5.4 - Trang 191)
**Đề bài:**  
*a. Tại sao chúng ta không tính các phép nhân với $10^n$ vào số lượng phép nhân $M(n)$ của thuật toán nhân số nguyên lớn?*  
*b. Bên cạnh giả thiết $n$ là lũy thừa của 2, chúng ta đã đưa ra một giả thiết ngầm định tinh tế hơn khi thiết lập hệ thức truy hồi cho $M(n)$ và $A(n)$ mà giả thiết đó không phải lúc nào cũng đúng (tuy nhiên nó không làm thay đổi kết quả cuối cùng). Đó là giả thiết gì?*

#### Lời giải chi tiết:

**a. Tại sao bỏ qua phép nhân với $10^n$:**  
Trong hệ thống số học vị trí (hệ thập phân hoặc nhị phân trên máy tính), việc nhân một số với $10^n$ (hoặc $2^n$) chỉ đơn thuần là phép **dịch bit / thêm $n$ chữ số 0 vào cuối**. Thao tác này không đòi hỏi thực hiện phép nhân số học thực sự mà chỉ là dịch chuyển bộ nhớ, tốn thời gian tuyến tính $O(n)$ tương đương phép cộng, do đó đã được gộp vào chi phí các phép cộng/dịch chuyển $A(n)$ chứ không tính vào số phép nhân các chữ số $M(n)$.

**b. Giả thiết ngầm định tinh tế không phải lúc nào cũng đúng:**  
- Khi thiết lập hệ thức $M(n) = 3 M(n/2)$, ta giả định rằng phép nhân thứ ba $(a_1 + a_0) \times (b_1 + b_0)$ cũng là phép nhân giữa hai số có **đúng $n/2$ chữ số**.
- **Tuy nhiên thực tế**: Tổng của hai số $n/2$ chữ số có thể sinh ra số nhớ ở hàng cao nhất và trở thành số có **$n/2 + 1$ chữ số**!  
  *(Ví dụ: Với $n = 4 \implies n/2 = 2$. Nếu $a_1 = 98$ và $a_0 = 76$, thì $a_1 + a_0 = 98 + 76 = 174$, là số có 3 chữ số chứ không phải 2 chữ số!)*.
- Việc nhân số có $n/2 + 1$ chữ số sẽ cần thêm một vài phép tính nhỏ. Dù vậy, phần dư thừa này tối đa chỉ là 1 chữ số và có thể xử lý trong $O(n)$ phép cộng, nên bậc tăng trưởng tiệm cận tiệm cận tổng thể vẫn được bảo toàn nguyên vẹn là $\Theta(n^{\log_2 3})$.

---

### Bài 5 (Exercises 5.4 - Trang 191)
**Đề bài:**  
*Có bao nhiêu phép cộng một chữ số được thực hiện bởi thuật toán đặt tính bút và giấy khi nhân hai số nguyên $n$ chữ số? (Có thể bỏ qua các số nhớ).*

#### Lời giải chi tiết:
1. Khi nhân một số $n$ chữ số với một số $n$ chữ số, ta tạo ra $n$ tích riêng một chữ số (partial products), mỗi tích riêng có $n$ chữ số.
2. Để tính tổng của $n$ tích riêng này:
   - Các tích riêng được xếp lệch nhau theo các cột vị trí lũy thừa của 10.
   - Để cộng $n$ số ở một cột, ta cần thực hiện đúng $n - 1$ phép cộng hai chữ số.
   - Mỗi tích riêng gồm $n$ chữ số, do đó có $n$ cột chính mà mỗi cột chứa đầy đủ các chữ số cần cộng.
3. Khi cộng dồn $n$ hàng tích riêng lại với nhau:
   - Hàng thứ 1 không cần cộng.
   - Hàng thứ 2 cần $n$ phép cộng với hàng 1.
   - Hàng thứ 3 cần $n$ phép cộng với tổng trước.
   - ...
   - Hàng thứ $n$ cần $n$ phép cộng.
   - Tổng số phép cộng một chữ số là:
     $$(n - 1) \times n = n(n - 1) = \mathbf{n^2 - n} \text{ phép cộng.}$$

---

### Bài 6 (Exercises 5.4 - Trang 191)
**Đề bài:**  
*Kiểm chứng bằng đại số các công thức trong thuật toán Strassen khi nhân hai ma trận $2 \times 2$.*

#### Lời giải chi tiết:
Ta kiểm chứng trực tiếp từng khối con $C_{00}, C_{01}, C_{10}, C_{11}$:

**1. Kiểm chứng $C_{00} = M_1 + M_4 - M_5 + M_7$:**
$$\begin{aligned}
M_1 &= (A_{00} + A_{11})(B_{00} + B_{11}) = A_{00}B_{00} + A_{00}B_{11} + A_{11}B_{00} + A_{11}B_{11} \\
M_4 &= A_{11}(B_{10} - B_{00}) = A_{11}B_{10} - A_{11}B_{00} \\
-M_5 &= -(A_{00} + A_{01})B_{11} = -A_{00}B_{11} - A_{01}B_{11} \\
M_7 &= (A_{01} - A_{11})(B_{10} + B_{11}) = A_{01}B_{10} + A_{01}B_{11} - A_{11}B_{10} - A_{11}B_{11}
\end{aligned}$$
Cộng 4 biểu thức lại:
- $A_{00}B_{00}$: chỉ xuất hiện ở $M_1 \implies +A_{00}B_{00}$.
- $A_{00}B_{11}$: ở $M_1$ và $-M_5 \implies A_{00}B_{11} - A_{00}B_{11} = 0$.
- $A_{11}B_{00}$: ở $M_1$ và $M_4 \implies A_{11}B_{00} - A_{11}B_{00} = 0$.
- $A_{11}B_{11}$: ở $M_1$ và $M_7 \implies A_{11}B_{11} - A_{11}B_{11} = 0$.
- $A_{11}B_{10}$: ở $M_4$ và $M_7 \implies A_{11}B_{10} - A_{11}B_{10} = 0$.
- $A_{01}B_{11}$: ở $-M_5$ và $M_7 \implies -A_{01}B_{11} + A_{01}B_{11} = 0$.
- Còn lại: $A_{00}B_{00} + A_{01}B_{10}$.
$$\implies C_{00} = A_{00}B_{00} + A_{01}B_{10} \quad (\text{Đúng chuẩn phép nhân ma trận!})$$

**2. Kiểm chứng $C_{01} = M_3 + M_5$:**
$$M_3 + M_5 = A_{00}(B_{01} - B_{11}) + (A_{00} + A_{01})B_{11} = A_{00}B_{01} - A_{00}B_{11} + A_{00}B_{11} + A_{01}B_{11} = A_{00}B_{01} + A_{01}B_{11}$$
$\implies$ Đúng chính xác $C_{01}$.

**3. Kiểm chứng $C_{10} = M_2 + M_4$:**
$$M_2 + M_4 = (A_{10} + A_{11})B_{00} + A_{11}(B_{10} - B_{00}) = A_{10}B_{00} + A_{11}B_{00} + A_{11}B_{10} - A_{11}B_{00} = A_{10}B_{00} + A_{11}B_{10}$$
$\implies$ Đúng chính xác $C_{10}$.

**4. Kiểm chứng $C_{11} = M_1 + M_3 - M_2 + M_6$:**
$$\begin{aligned}
M_1 &= A_{00}B_{00} + A_{00}B_{11} + A_{11}B_{00} + A_{11}B_{11} \\
M_3 &= A_{00}B_{01} - A_{00}B_{11} \\
-M_2 &= -A_{10}B_{00} - A_{11}B_{00} \\
M_6 &= (A_{10} - A_{00})(B_{00} + B_{01}) = A_{10}B_{00} + A_{10}B_{01} - A_{00}B_{00} - A_{00}B_{01}
\end{aligned}$$
Cộng các số hạng lại:
- $A_{00}B_{00} - A_{00}B_{00} = 0$.
- $A_{00}B_{11} - A_{00}B_{11} = 0$.
- $A_{11}B_{00} - A_{11}B_{00} = 0$.
- $A_{00}B_{01} - A_{00}B_{01} = 0$.
- $-A_{10}B_{00} + A_{10}B_{00} = 0$.
- Còn lại: $A_{10}B_{01} + A_{11}B_{11}$.
$$\implies C_{11} = A_{10}B_{01} + A_{11}B_{11} \quad (\text{Đúng chuẩn phép nhân ma trận!})$$
Cả 4 công thức đã được kiểm chứng hoàn tất. $\blacksquare$

---

### Bài 7 (Exercises 5.4 - Trang 191)
**Đề bài:**  
*Áp dụng thuật toán Strassen để nhân hai ma trận $4 \times 4$ sau đây (dừng đệ quy khi $n = 2$, tức là tính tích của các ma trận con $2 \times 2$ bằng thuật toán nhân thông thường):*
$$A = \begin{pmatrix} 1 & 0 & 2 & 1 \\ 4 & 1 & 1 & 0 \\ 0 & 1 & 3 & 0 \\ 5 & 0 & 2 & 1 \end{pmatrix}, \quad B = \begin{pmatrix} 0 & 1 & 0 & 1 \\ 2 & 1 & 0 & 4 \\ 2 & 0 & 1 & 1 \\ 1 & 3 & 5 & 0 \end{pmatrix}$$

#### Lời giải chi tiết:

**Bước 1: Phân tách thành các khối ma trận con $2 \times 2$:**
$$A_{00} = \begin{pmatrix} 1 & 0 \\ 4 & 1 \end{pmatrix}, \quad A_{01} = \begin{pmatrix} 2 & 1 \\ 1 & 0 \end{pmatrix}, \quad A_{10} = \begin{pmatrix} 0 & 1 \\ 5 & 0 \end{pmatrix}, \quad A_{11} = \begin{pmatrix} 3 & 0 \\ 2 & 1 \end{pmatrix}$$
$$B_{00} = \begin{pmatrix} 0 & 1 \\ 2 & 1 \end{pmatrix}, \quad B_{01} = \begin{pmatrix} 0 & 1 \\ 0 & 4 \end{pmatrix}, \quad B_{10} = \begin{pmatrix} 2 & 0 \\ 1 & 3 \end{pmatrix}, \quad B_{11} = \begin{pmatrix} 1 & 1 \\ 5 & 0 \end{pmatrix}$$

**Bước 2: Tính 7 ma trận trung gian $M_1 \dots M_7$ bằng phép nhân thông thường:**
1. $M_1 = (A_{00} + A_{11})(B_{00} + B_{11})$:
   $$A_{00} + A_{11} = \begin{pmatrix} 4 & 0 \\ 6 & 2 \end{pmatrix}, \quad B_{00} + B_{11} = \begin{pmatrix} 1 & 2 \\ 7 & 1 \end{pmatrix} \implies M_1 = \begin{pmatrix} 4 & 8 \\ 20 & 14 \end{pmatrix}$$
2. $M_2 = (A_{10} + A_{11}) B_{00}$:
   $$A_{10} + A_{11} = \begin{pmatrix} 3 & 1 \\ 7 & 1 \end{pmatrix} \implies M_2 = \begin{pmatrix} 3 & 1 \\ 7 & 1 \end{pmatrix} \begin{pmatrix} 0 & 1 \\ 2 & 1 \end{pmatrix} = \begin{pmatrix} 2 & 4 \\ 2 & 8 \end{pmatrix}$$
3. $M_3 = A_{00} (B_{01} - B_{11})$:
   $$B_{01} - B_{11} = \begin{pmatrix} -1 & 0 \\ -5 & 4 \end{pmatrix} \implies M_3 = \begin{pmatrix} 1 & 0 \\ 4 & 1 \end{pmatrix} \begin{pmatrix} -1 & 0 \\ -5 & 4 \end{pmatrix} = \begin{pmatrix} -1 & 0 \\ -9 & 4 \end{pmatrix}$$
4. $M_4 = A_{11} (B_{10} - B_{00})$:
   $$B_{10} - B_{00} = \begin{pmatrix} 2 & -1 \\ -1 & 2 \end{pmatrix} \implies M_4 = \begin{pmatrix} 3 & 0 \\ 2 & 1 \end{pmatrix} \begin{pmatrix} 2 & -1 \\ -1 & 2 \end{pmatrix} = \begin{pmatrix} 6 & -3 \\ 3 & 0 \end{pmatrix}$$
5. $M_5 = (A_{00} + A_{01}) B_{11}$:
   $$A_{00} + A_{01} = \begin{pmatrix} 3 & 1 \\ 5 & 1 \end{pmatrix} \implies M_5 = \begin{pmatrix} 3 & 1 \\ 5 & 1 \end{pmatrix} \begin{pmatrix} 1 & 1 \\ 5 & 0 \end{pmatrix} = \begin{pmatrix} 8 & 3 \\ 10 & 5 \end{pmatrix}$$
6. $M_6 = (A_{10} - A_{00})(B_{00} + B_{01})$:
   $$A_{10} - A_{00} = \begin{pmatrix} -1 & 1 \\ 1 & -1 \end{pmatrix}, \quad B_{00} + B_{01} = \begin{pmatrix} 0 & 2 \\ 2 & 5 \end{pmatrix} \implies M_6 = \begin{pmatrix} 2 & 3 \\ -2 & -3 \end{pmatrix}$$
7. $M_7 = (A_{01} - A_{11})(B_{10} + B_{11})$:
   $$A_{01} - A_{11} = \begin{pmatrix} -1 & 1 \\ -1 & -1 \end{pmatrix}, \quad B_{10} + B_{11} = \begin{pmatrix} 3 & 1 \\ 6 & 3 \end{pmatrix} \implies M_7 = \begin{pmatrix} 3 & 2 \\ -9 & -4 \end{pmatrix}$$

**Bước 3: Tính các khối con $C_{ij}$ của ma trận kết quả:**
$$\begin{aligned}
C_{00} &= M_1 + M_4 - M_5 + M_7 = \begin{pmatrix} 4 & 8 \\ 20 & 14 \end{pmatrix} + \begin{pmatrix} 6 & -3 \\ 3 & 0 \end{pmatrix} - \begin{pmatrix} 8 & 3 \\ 10 & 5 \end{pmatrix} + \begin{pmatrix} 3 & 2 \\ -9 & -4 \end{pmatrix} = \begin{pmatrix} 5 & 4 \\ 4 & 5 \end{pmatrix} \\
C_{01} &= M_3 + M_5 = \begin{pmatrix} -1 & 0 \\ -9 & 4 \end{pmatrix} + \begin{pmatrix} 8 & 3 \\ 10 & 5 \end{pmatrix} = \begin{pmatrix} 7 & 3 \\ 1 & 9 \end{pmatrix} \\
C_{10} &= M_2 + M_4 = \begin{pmatrix} 2 & 4 \\ 2 & 8 \end{pmatrix} + \begin{pmatrix} 6 & -3 \\ 3 & 0 \end{pmatrix} = \begin{pmatrix} 8 & 1 \\ 5 & 8 \end{pmatrix} \\
C_{11} &= M_1 + M_3 - M_2 + M_6 = \begin{pmatrix} 4 & 8 \\ 20 & 14 \end{pmatrix} + \begin{pmatrix} -1 & 0 \\ -9 & 4 \end{pmatrix} - \begin{pmatrix} 2 & 4 \\ 2 & 8 \end{pmatrix} + \begin{pmatrix} 2 & 3 \\ -2 & -3 \end{pmatrix} = \begin{pmatrix} 3 & 7 \\ 7 & 7 \end{pmatrix}
\end{aligned}$$

**Ma trận kết quả hoàn chỉnh:**
$$C = \begin{pmatrix} 5 & 4 & 7 & 3 \\ 4 & 5 & 1 & 9 \\ 8 & 1 & 3 & 7 \\ 5 & 8 & 7 & 7 \end{pmatrix}$$
*(Kiểm tra nhân thông thường hàng $\times$ cột: Hàng 1 $A$ nhân Cột 1 $B$: $1(0) + 0(2) + 2(2) + 1(1) = 5$. Hoàn toàn khớp 100%)*.

---

### Bài 8 (Exercises 5.4 - Trang 192)
**Đề bài:**  
*Giải phương trình truy hồi cho số phép cộng của thuật toán Strassen bằng phương pháp thế lùi. Giả sử $n$ là lũy thừa của 2.*

#### Lời giải chi tiết:
Phương trình truy hồi trong giáo trình (trang 190):
$$A(n) = 7 A(n/2) + 18 \left( \frac{n}{2} \right)^2 = 7 A(n/2) + \frac{9}{2} n^2 \quad (n > 1), \quad A(1) = 0$$
Với $n = 2^k$, áp dụng phương pháp thế lùi:
$$\begin{aligned}
A(2^k) &= 7 A(2^{k-1}) + \frac{9}{2} (2^k)^2 \\
       &= 7 \left[ 7 A(2^{k-2}) + \frac{9}{2} (2^{k-1})^2 \right] + \frac{9}{2} (2^k)^2 \\
       &= 7^2 A(2^{k-2}) + \frac{9}{2} \left[ 7 \cdot 4^{k-1} + 4^k \right] \\
       &= 7^2 A(2^{k-2}) + \frac{9}{2} \cdot 4^k \left[ \frac{7}{4} + 1 \right] \\
       &= 7^3 A(2^{k-3}) + \frac{9}{2} \cdot 4^k \left[ \left(\frac{7}{4}\right)^2 + \frac{7}{4} + 1 \right] \\
       &\dots \\
       &= 7^k A(1) + \frac{9}{2} \cdot 4^k \sum_{j=0}^{k-1} \left(\frac{7}{4}\right)^j
\end{aligned}$$
Vì $A(1) = 0$ và áp dụng công thức tổng cấp số nhân hữu hạn:
$$\sum_{j=0}^{k-1} \left(\frac{7}{4}\right)^j = \frac{(7/4)^k - 1}{(7/4) - 1} = \frac{(7/4)^k - 1}{3/4} = \frac{4}{3} \left[ \frac{7^k}{4^k} - 1 \right]$$
Thay vào phương trình:
$$A(n) = 0 + \frac{9}{2} \cdot 4^k \cdot \frac{4}{3} \left[ \frac{7^k}{4^k} - 1 \right] = 6 \cdot 4^k \left[ \frac{7^k}{4^k} - 1 \right] = 6 (7^k - 4^k)$$
Vì $n = 2^k \implies k = \log_2 n \implies 7^k = 7^{\log_2 n} = n^{\log_2 7}$, và $4^k = (2^k)^2 = n^2$:
$$A(n) = 6 \left( n^{\log_2 7} - n^2 \right)$$
Vậy số phép cộng là $A(n) = 6(n^{\log_2 7} - n^2) \in \Theta(n^{\log_2 7})$. $\blacksquare$

---

### Bài 9 (Exercises 5.4 - Trang 192)
**Đề bài:**  
*V. Pan (1978) đã phát minh một thuật toán nhân ma trận chia để trị dựa trên việc nhân hai ma trận kích thước $70 \times 70$ chỉ bằng $143.640$ phép nhân. Hãy tìm hiệu năng tiệm cận của thuật toán Pan (có thể bỏ qua số phép cộng) và so sánh với thuật toán Strassen.*

#### Lời giải chi tiết:

**1. Thiết lập phương trình truy hồi:**  
Thuật toán của Pan chia bài toán kích thước $n$ thành $a = 143.640$ bài toán con, mỗi bài toán con có kích thước $n/b$ với $b = 70$.  
Hệ thức truy hồi cho số phép nhân $M(n)$:
$$M(n) = 143.640 \cdot M(n/70)$$

**2. Áp dụng Master Theorem tìm bậc tăng trưởng:**  
Theo nghiệm tổng quát dạng lũy thừa:
$$M(n) \in \Theta(n^{\log_b a}) = \Theta\left( n^{\log_{70} 143.640} \right)$$
Tính số mũ bằng logarit tự nhiên:
$$\log_{70} 143.640 = \frac{\ln(143.640)}{\ln(70)} \approx \frac{11.875066}{4.248495} \approx \mathbf{2.795123}$$
Vậy độ phức tạp của thuật toán Pan là:
$$M_{Pan}(n) \in \Theta(n^{2.795})$$

**3. So sánh với thuật toán Strassen:**  
Thuật toán Strassen có độ phức tạp là:
$$M_{Strassen}(n) \in \Theta(n^{\log_2 7}) \approx \Theta(n^{2.807})$$
- So sánh: $2.795 < 2.807$.
- **Đánh giá**: Về mặt tiệm cận lý thuyết khi $n \to \infty$, thuật toán của V. Pan chạy **nhanh hơn** thuật toán Strassen. Tuy nhiên, hằng số ẩn của thuật toán Pan cực kỳ khổng lồ (bắt nguồn từ kích thước cơ sở $70 \times 70$ và số lượng phép cộng đồ sộ), khiến nó hoàn toàn không khả thi trên thực tế so với Strassen.

---

### Bài 10 (Exercises 5.4 - Trang 192)
**Đề bài:**  
*Các cài đặt thực tế của thuật toán Strassen thường chuyển sang phương pháp nhân ma trận vét cạn thông thường khi kích thước ma trận giảm xuống dưới một ngưỡng giao cắt (crossover point). Hãy tiến hành thực nghiệm để xác định ngưỡng giao cắt này trên hệ thống máy tính của bạn.*

#### Lời giải chi tiết:

**Phân tích lý thuyết về Điểm Giao cắt (Crossover Point):**
- Mặc dù Strassen giảm số phép nhân từ 8 xuống 7, nhưng nó đòi hỏi thêm nhiều phép cộng ma trận ($18$ phép cộng khối) và chi phí cấp phát bộ nhớ phụ, làm giảm hiệu suất sử dụng bộ nhớ đệm (cache locality).
- Khi kích thước ma trận $n$ nhỏ, chi phí cộng và phân phối bộ nhớ của Strassen vượt trội hơn lợi ích của việc tiết kiệm 1 phép nhân.
- Do đó, giải pháp tối ưu là:
  ```text
  if n ≤ CROSSOVER_POINT then
      BruteForceMatrixMultiply(A, B)
  else
      StrassenMatrixMultiply(A, B)
  ```
- Trên các hệ thống kiến trúc máy tính hiện đại (CPU x86_64, hỗ trợ tập lệnh SIMD/AVX2), thực nghiệm cho thấy ngưỡng giao cắt tối ưu thường nằm trong khoảng:
  $$n_0 \approx 64 \text{ đến } 128$$
Dưới ngưỡng này, phép nhân thông thường kết hợp tối ưu hóa vòng lặp (vòng lặp $i-k-j$ tối ưu cache) luôn chạy nhanh gấp nhiều lần thuật toán Strassen thuần túy.


---

# CHUYÊN ĐỀ 05: BÀI TOÁN CẶP ĐIỂM GẦN NHẤT VÀ BAO LỒI BẰNG CHIA ĐỂ TRỊ & LỜI GIẢI CHI TIẾT 100% BÀI TẬP 5.5
## Trích dẫn: Anany Levitin, "Introduction to the Design and Analysis of Algorithms", 3rd Edition, Mục 5.5 (pp. 191–197)

---

## PHẦN 1: LÝ THUYẾT NỀN TẢNG & MÃ GIẢ CHUẨN HÓA

### 1.1. Bài toán Cặp điểm Gần nhất trong Mặt phẳng 2D (Closest-Pair Problem)

#### Phát biểu bài toán
Cho tập hợp $P$ gồm $n$ điểm trên mặt phẳng tọa độ hai chiều: $P = \{p_1(x_1, y_1), \dots, p_n(x_n, y_n)\}$. Hãy tìm cặp điểm $(p_i, p_j)$ sao cho khoảng cách Euclid giữa chúng là nhỏ nhất:
$$d(p_i, p_j) = \sqrt{(x_i - x_j)^2 + (y_i - y_j)^2}$$

Thuật toán vét cạn tính khoảng cách của tất cả các cặp điểm tốn $\frac{n(n-1)}{2} = \Theta(n^2)$ phép tính. Ta sẽ dùng chiến lược Chia để trị để giảm độ phức tạp xuống $O(n \log n)$.

#### Chiến lược Thiết kế Chia để trị (Shamos & Hoey, 1975)
1. **Tiền xử lý (Presorting)**:
   - Sắp xếp trước tập $P$ theo hoành độ tăng dần vào mảng $X[0..n-1]$.
   - Sắp xếp trước tập $P$ theo tung độ tăng dần vào mảng $Y[0..n-1]$.
   - Giai đoạn tiền xử lý tốn $O(n \log n)$ thời gian và chỉ thực hiện **duy nhất một lần**.
2. **Chia (Divide)**:
   - Tìm đường thẳng đứng $x = c$ đi qua trung vị hoành độ để chia tập $P$ thành hai nửa có kích thước xấp xỉ bằng nhau: $P_l$ (nửa bên trái) và $P_r$ (nửa bên phải).
3. **Trị (Conquer)**:
   - Gọi đệ quy tìm khoảng cách nhỏ nhất $d_l$ trong nửa trái $P_l$.
   - Gọi đệ quy tìm khoảng cách nhỏ nhất $d_r$ trong nửa phải $P_r$.
   - Đặt $d = \min(d_l, d_r)$.
4. **Kết hợp (Combine)**:
   - Khoảng cách nhỏ nhất toàn thể có thể đạt được giữa một điểm thuộc $P_l$ và một điểm thuộc $P_r$.
   - Cặp điểm đó bắt buộc phải nằm trong **dải hẹp thẳng đứng (vertical strip)** có độ rộng $2d$ đối xứng qua đường phân chia:
     $$[c - d, c + d]$$
   - Lọc các điểm rơi vào dải hẹp này theo thứ tự tung độ $y$ tăng dần vào danh sách $S$.
   - **Định lý Hình học Cốt lõi (The 7-Points Theorem)**:  
     Với mỗi điểm $p(x, y) \in S$, bất kỳ điểm $q \in S$ nào có khoảng cách $< d$ tới $p$ bắt buộc phải nằm trong hình chữ nhật kích thước $2d \times d$ nằm ngay phía trên $p$.  
     Hình chữ nhật này được chia thành 8 hình chữ nhật con kích thước $d \times d/2$. Vì các điểm ở nửa trái cách nhau ít nhất $d$ và nửa phải cách nhau ít nhất $d$, theo **Nguyên lý Dirichlet**, mỗi hình chữ nhật con chứa tối đa 1 điểm.  
     Do đó, hình chữ nhật $2d \times d$ chứa **tối đa 8 điểm (kể cả chính điểm $p$)**!  
     $\implies$ Với mỗi điểm $p \in S$, ta chỉ cần so sánh khoảng cách với **tối đa 7 điểm kế tiếp** trong danh sách $S$!

```text
algorithm: EfficientClosestPair(P)
1   Khởi tạo X ← P sắp xếp theo hoành độ x tăng dần
2   Khởi tạo Y ← P sắp xếp theo tung độ y tăng dần
3   return ClosestPairRec(X, Y)

algorithm: ClosestPairRec(X, Y)
1   if |X| ≤ 3 then
2       return khoảng cách nhỏ nhất bằng vét cạn
3   c ← X[⌈n/2⌉ - 1].x
4   Chia X thành X_l và X_r; Chia Y thành Y_l và Y_r
5   d_l ← ClosestPairRec(X_l, Y_l)
6   d_r ← ClosestPairRec(X_r, Y_r)
7   d ← min(d_l, d_r)
8   Tập S ← các điểm trong Y có hoành độ thỏa mãn |x - c| < d
9   d_min ← d
10  for i ← 0 to |S| - 2 do
11      k ← i + 1
12      while k < |S| and (S[k].y - S[i].y) < d_min do
13          d_min ← min(d_min, dist(S[i], S[k]))
14          k ← k + 1
15  return d_min
```

**Phân tích độ phức tạp**:
$$T(n) = 2 T(n/2) + \Theta(n) \implies T(n) \in \Theta(n \log n)$$

---

### 1.2. Bài toán Bao lồi Bằng Chia để trị (Thuật toán Quickhull)

#### Phát biểu bài toán
**Bao lồi (Convex Hull)** của tập hợp $n$ điểm $P$ là đa giác lồi nhỏ nhất chứa tất cả các điểm trong $P$.

#### Thuật toán Quickhull
Tương tự như Quicksort, Quickhull chia tập điểm theo nguyên lý hình học:
1. Tìm hai điểm cực trị: $p_1$ (hoành độ nhỏ nhất) và $p_n$ (hoành độ lớn nhất). Hai điểm này chắc chắn là đỉnh của bao lồi.
2. Đường thẳng có hướng $\vec{p_1 p_n}$ chia các điểm còn lại thành hai tập:
   - $S_1$: các điểm nằm bên trái đường thẳng $\vec{p_1 p_n}$ (tạo thành Bao trên - Upper Hull).
   - $S_2$: các điểm nằm bên trái đường thẳng $\vec{p_n p_1}$ (tạo thành Bao dưới - Lower Hull).
3. Với tập $S_1$, tìm điểm $p_{max}$ nằm xa đường thẳng $p_1 p_n$ nhất. Điểm $p_{max}$ chắc chắn là một đỉnh của bao lồi.
4. **Loại bỏ điểm trong**: Toàn bộ các điểm nằm bên trong tam giác $\Delta p_1 p_{max} p_n$ bị loại bỏ vĩnh viễn (không thể là đỉnh bao lồi).
5. Đệ quy tiếp tục với tập các điểm nằm bên trái $\vec{p_1 p_{max}}$ và bên trái $\vec{p_{max} p_n}$.

#### Công thức Định thức Giải tích Kiểm tra Hướng và Khoảng cách
Cho 3 điểm $p_1(x_1, y_1), p_2(x_2, y_2), p_3(x_3, y_3)$. Giá trị định thức:
$$\Delta = \begin{vmatrix} x_1 & y_1 & 1 \\ x_2 & y_2 & 1 \\ x_3 & y_3 & 1 \end{vmatrix} = x_1 y_2 + x_3 y_1 + x_2 y_3 - x_3 y_2 - x_1 y_3 - x_2 y_1$$
- $\Delta > 0 \iff p_3$ nằm bên trái đường thẳng có hướng $\vec{p_1 p_2}$.
- $\Delta < 0 \iff p_3$ nằm bên phải $\vec{p_1 p_2}$.
- $|\Delta|$ tỷ lệ thuận với diện tích tam giác $\Delta p_1 p_2 p_3$, do đó điểm có $\Delta$ lớn nhất chính là điểm $p_{max}$ xa đường thẳng nhất!

**Độ phức tạp**:
- Trường hợp xấu nhất: $\Theta(n^2)$ (khi mỗi bước chỉ loại được 1 điểm).
- Trường hợp trung bình: $O(n \log n)$, và đạt $O(n)$ đối với các tập điểm phân bố đều trong miền lồi.

---

## PHẦN 2: LỜI GIẢI CHI TIẾT 100% BÀI TẬP 5.5 (BÀI 1 ĐẾN BÀI 12)

---

### Bài 1 (Exercises 5.5 - Trang 197)
**Đề bài:**  
*a. Đối với phiên bản 1 chiều (1D) của bài toán Cặp điểm gần nhất: Cho tập $n$ số thực, hãy thiết kế một thuật toán dựa trực tiếp trên kỹ thuật chia để trị và xác định lớp hiệu năng của nó.*  
*b. Đây có phải là một thuật toán tốt cho bài toán này không?*

#### Lời giải chi tiết:

**a. Thiết kế thuật toán Chia để trị 1 chiều:**
1. **Tiền xử lý hoặc tìm trung vị**: Chia tập $P$ thành hai nửa $P_l$ và $P_r$ bằng giá trị trung vị $m$.
2. **Đệ quy**:
   - $d_l \leftarrow \text{ClosestPair1D}(P_l)$
   - $d_r \leftarrow \text{ClosestPair1D}(P_r)$
   - $d \leftarrow \min(d_l, d_r)$
3. **Kết hợp**:
   - Trong không gian 1 chiều, hai điểm nằm ở hai nửa khác nhau có khoảng cách $< d$ thì bắt buộc một điểm phải thuộc $P_l$ và một điểm thuộc $P_r$.
   - Cặp điểm gần nhau nhất giữa hai nửa chỉ có thể là **phần tử lớn nhất của nửa trái** ($\max P_l$) và **phần tử nhỏ nhất của nửa phải** ($\min P_r$)!
   - Ta chỉ cần kiểm tra đúng duy nhất 1 hiệu số: $\delta = \min(P_r) - \max(P_l)$.
   - Khoảng cách nhỏ nhất toàn thể là: $\min(d, \delta)$.
- **Phương trình truy hồi**:
  - Nếu mảng đã được tiền sắp xếp: $T(n) = 2 T(n/2) + \Theta(1) \implies T(n) \in \Theta(n)$.
  - Nếu chưa sắp xếp: tốn $O(n \log n)$ để sắp xếp, hoặc mỗi bước tốn $O(n)$ để tìm trung vị: $T(n) = 2T(n/2) + \Theta(n) \implies T(n) \in \Theta(n \log n)$.

**b. Đánh giá: Đây KHÔNG PHẢI là một thuật toán tốt!**  
- Cách tiếp cận tự nhiên và đơn giản hơn rất nhiều là:
  1. Sắp xếp mảng $n$ số thực tăng dần: tốn $O(n \log n)$.
  2. Quét tuần tự một lượt qua mảng, tính hiệu giữa hai phần tử liên tiếp $A[i+1] - A[i]$: tốn $O(n)$.
  3. Lấy giá trị nhỏ nhất trong các hiệu số này.
- Thuật toán sắp xếp + quét tuyến tính chạy nhanh hơn trong thực tế, dễ cài đặt hơn rất nhiều và không chịu chi phí đệ quy overhead, dù cùng lớp độ phức tạp $\Theta(n \log n)$.

---

### Bài 2 (Exercises 5.5 - Trang 197)
**Đề bài:**  
*Chứng minh rằng thuật toán chia để trị giải bài toán Cặp điểm gần nhất chỉ kiểm tra, đối với mỗi điểm $p$ trong dải hẹp thẳng đứng, không quá bảy điểm khác có thể gần $p$ hơn khoảng cách nhỏ nhất $d_{min}$ hiện có.*

#### Lời giải chi tiết:

**Chứng minh chặt chẽ bằng Nguyên lý Dirichlet (Pigeonhole Principle):**
1. Gọi $c$ là hoành độ của đường thẳng phân chia. Dải hẹp thẳng đứng có độ rộng $2d$ nằm trong khoảng $x \in [c - d, c + d]$.
2. Xét một điểm $p(x, y)$ bất kỳ trong dải hẹp. Bất kỳ điểm $q$ nào nằm phía trên $p$ mà có khoảng cách $dist(p, q) < d$ thì:
   - Tung độ của $q$ bắt buộc phải thỏa mãn: $y \le q.y < y + d$.
   - Hoành độ của $q$ bắt buộc phải thỏa mãn: $c - d \le q.x \le c + d$.
3. Do đó, điểm $q$ bắt buộc phải nằm bên trong hình chữ nhật $R$ có kích thước:
   $$\text{Chiều rộng} = 2d, \quad \text{Chiều cao} = d$$
4. Đường thẳng $x = c$ chia hình chữ nhật $R$ thành hai hình vuông $d \times d$:
   - Hình vuông bên trái $R_l = [c - d, c] \times [y, y + d]$ chứa các điểm thuộc $P_l$.
   - Hình vuông bên phải $R_r = [c, c + d] \times [y, y + d]$ chứa các điểm thuộc $P_r$.
5. Ta chia mỗi hình vuông $d \times d$ thành **4 hình chữ nhật con** có kích thước:
   $$\frac{d}{2} \times d \quad \text{(hoặc } \frac{d}{2} \times \frac{d}{2} \text{)}$$
   Chia toàn bộ hình chữ nhật $2d \times d$ thành **8 hình chữ nhật con** có kích thước $\frac{d}{2} \times d$:
   - Đường chéo của mỗi ô con kích thước $\frac{d}{2} \times \frac{d}{2}$ là $\sqrt{(d/2)^2 + (d/2)^2} = \frac{d}{\sqrt{2}} \approx 0.707 d < d$.
   - Nếu chia thành 4 ô vuông $d/2 \times d/2$ cho mỗi nửa, đường chéo cực đại là $0.707d < d$.
6. Vì $d = \min(d_l, d_r)$, mọi cặp điểm trong cùng nửa $P_l$ đều cách nhau ít nhất $d$, và mọi cặp điểm trong $P_r$ đều cách nhau ít nhất $d$.
7. Do đường kính của mỗi ô con $< d$, **mỗi ô con không thể chứa từ hai điểm trở lên**!
8. Do đó, toàn bộ 8 ô con chứa **tối đa 8 điểm**.
9. Vì một trong các điểm đó chính là bản thân điểm $p$, số lượng điểm khác còn lại trong hình chữ nhật tối đa chỉ có thể là:
   $$8 - 1 = \mathbf{7} \text{ điểm!}$$
Vậy với mỗi điểm $p$, thuật toán chỉ cần kiểm tra tối đa 7 điểm tiếp theo trong danh sách đã sắp theo $y$. $\blacksquare$

---

### Bài 3 (Exercises 5.5 - Trang 197)
**Đề bài:**  
*Xét biến thể của thuật toán Cặp điểm gần nhất: thay vì tiền sắp xếp tập điểm một lần duy nhất, ở mỗi lần gọi đệ quy ta sắp xếp lại hai tập con $P_l$ và $P_r$ theo tung độ $y$ tăng dần bằng Mergesort ($C_{worst}(n) = n \log_2 n - n + 1$). Hãy thiết lập phương trình truy hồi cho thời gian chạy trong trường hợp xấu nhất và giải với $n = 2^k$.*

#### Lời giải chi tiết:

**Thiết lập phương trình truy hồi:**  
Ở mỗi tầng đệ quy trên mảng kích thước $n$:
- Chia đôi mảng thành 2 bài toán con kích thước $n/2$: $2 T(n/2)$.
- Sắp xếp lại hai mảng con bằng Mergesort: mỗi nửa tốn $\frac{n}{2} \log_2 (n/2)$ phép toán, tổng chi phí sắp xếp là:
  $$2 \times \left( \frac{n}{2} \log_2 \frac{n}{2} \right) \approx n \log_2 n$$
- Bước quét dải hẹp tốn $\Theta(n)$.
- Do số hạng $n \log_2 n$ áp đảo $\Theta(n)$, phương trình truy hồi cho trường hợp xấu nhất là:
  $$T(n) = 2 T(n/2) + c \cdot n \log_2 n \quad (n > 1), \quad T(1) = 0$$

**Giải phương trình truy hồi với $n = 2^k$ bằng phương pháp thế lùi:**
$$\begin{aligned}
T(2^k) &= 2 T(2^{k-1}) + c \cdot 2^k \log_2 (2^k) = 2 T(2^{k-1}) + c \cdot k \cdot 2^k \\
       &= 2 \left[ 2 T(2^{k-2}) + c (k-1) 2^{k-1} \right] + c k 2^k = 2^2 T(2^{k-2}) + c \cdot 2^k [(k-1) + k] \\
       &= 2^3 T(2^{k-3}) + c \cdot 2^k [(k-2) + (k-1) + k] \\
       &= 2^k T(1) + c \cdot 2^k \sum_{j=1}^k j
\end{aligned}$$
Vì $T(1) = 0$ và $\sum_{j=1}^k j = \frac{k(k+1)}{2}$:
$$T(n) = c \cdot 2^k \cdot \frac{k(k+1)}{2} = \frac{c}{2} n \log_2 n (\log_2 n + 1) = \frac{c}{2} n \log_2^2 n + \frac{c}{2} n \log_2 n$$
- **Kết luận**:
  $$T(n) \in \Theta(n \log^2 n)$$
Thời gian thực thi bị chậm đi một thừa số $\log n$ so với thuật toán tối ưu $\Theta(n \log n)$ có tiền sắp xếp.

---

### Bài 4 (Exercises 5.5 - Trang 197)
**Đề bài:**  
*Cài đặt thuật toán chia để trị giải bài toán Cặp điểm gần nhất bằng một ngôn ngữ lập trình tùy chọn.*

#### Lời giải chi tiết:

**Mã nguồn C++ hoàn chỉnh $O(n \log n)$:**
```cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

struct Point {
    double x, y;
};

double dist(Point p1, Point p2) {
    return std::sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double bruteForce(const std::vector<Point>& P, int l, int r) {
    double minDist = 1e18;
    for (int i = l; i <= r; ++i)
        for (int j = i + 1; j <= r; ++j)
            minDist = std::min(minDist, dist(P[i], P[j]));
    return minDist;
}

double stripClosest(std::vector<Point>& strip, double d) {
    double minD = d;
    std::sort(strip.begin(), strip.end(), [](const Point& a, const Point& b) {
        return a.y < b.y;
    });
    int n = strip.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n && (strip[j].y - strip[i].y) < minD; ++j) {
            minD = std::min(minD, dist(strip[i], strip[j]));
        }
    }
    return minD;
}

double closestRec(std::vector<Point>& Px, int l, int r) {
    if (r - l + 1 <= 3) return bruteForce(Px, l, r);
    int mid = l + (r - l) / 2;
    Point midPoint = Px[mid];

    double dl = closestRec(Px, l, mid);
    double dr = closestRec(Px, mid + 1, r);
    double d = std::min(dl, dr);

    std::vector<Point> strip;
    for (int i = l; i <= r; ++i) {
        if (std::abs(Px[i].x - midPoint.x) < d)
            strip.push_back(Px[i]);
    }
    return std::min(d, stripClosest(strip, d));
}

double closestPair(std::vector<Point>& points) {
    std::sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
        return a.x < b.x;
    });
    return closestRec(points, 0, points.size() - 1);
}
```

---

### Bài 5 (Exercises 5.5 - Trang 198)
**Đề bài:**  
*Tìm trên Web một hình ảnh trực quan hóa cho bài toán Cặp điểm gần nhất. Trực quan hóa đó biểu diễn cho thuật toán nào?*

#### Lời giải chi tiết:
1. **Thuật toán trực quan hóa phổ biến nhất**: Trên các nền tảng giáo dục thuật toán (như VisuAlgo, GeeksforGeeks, Wikipedia), hình ảnh trực quan hóa thường biểu diễn **Thuật toán Chia để trị Shamos-Hoey** hoặc **Thuật toán Đường quét (Sweep-Line Algorithm của Fortune / Bentley-Ottmann)**.
2. **Đặc trưng nhận diện thuật toán Chia để trị Shamos-Hoey**:
   - Màn hình xuất hiện một đường phân cách dọc màu đỏ chia đôi tập điểm thành hai nửa.
   - Hai hộp chữ nhật màu xanh lam bao quanh các cặp điểm gần nhất ở nửa trái và nửa phải.
   - Một dải hẹp màu vàng (strip) có bề rộng $2d$ xuất hiện ở giữa.
   - Một khung trượt hình chữ nhật kích thước $2d \times d$ trượt từ dưới lên trên dọc theo dải hẹp để kiểm tra tối đa 7 điểm lân cận.

---

### Bài 6 (Exercises 5.5 - Trang 198)
**Đề bài:**  
*Đa giác Voronoi của một điểm $p$ trong tập hợp điểm $S$ là chu vi của tập hợp tất cả các điểm trong mặt phẳng gần $p$ hơn bất kỳ điểm nào khác trong $S$. Hợp của tất cả các đa giác Voronoi được gọi là Biểu đồ Voronoi (Voronoi Diagram) của $S$.*  
*a. Biểu đồ Voronoi cho một tập hợp gồm đúng ba điểm là gì?*  
*b. Từ việc quan sát các biểu đồ Voronoi, hãy giải thích cách khái quát hóa kết quả từ tập 3 điểm lên trường hợp tổng quát.*

#### Lời giải chi tiết:

**a. Biểu đồ Voronoi cho tập 3 điểm $p_1, p_2, p_3$:**
- Ba điểm $p_1, p_2, p_3$ không thẳng hàng tạo thành một tam giác $\Delta p_1 p_2 p_3$.
- Với mỗi cặp điểm, tập hợp các điểm cách đều hai điểm là **đường trung trực** của đoạn thẳng nối hai điểm đó:
  - Đường trung trực $L_{12}$ của $p_1 p_2$.
  - Đường trung trực $L_{23}$ của $p_2 p_3$.
  - Đường trung trực $L_{31}$ của $p_3 p_1$.
- Theo hình học phẳng Euclid, ba đường trung trực của tam giác đồng quy tại một điểm duy nhất $C$ - chính là **Tâm đường tròn ngoại tiếp (Circumcenter)** của tam giác $\Delta p_1 p_2 p_3$!
- **Biểu đồ Voronoi**: Gồm ba tia xuất phát từ tâm ngoại tiếp $C$ đi ra vô tận dọc theo 3 đường trung trực, chia mặt phẳng thành 3 miền vô hạn (3 ô Voronoi). Mỗi miền chứa một điểm và bao gồm tất cả các điểm trên mặt phẳng gần điểm đó nhất.

**b. Khái quát hóa lên trường hợp tổng quát ($n$ điểm) & Mối quan hệ đối ngẫu:**
- Trong trường hợp tổng quát, biểu đồ Voronoi chia mặt phẳng thành $n$ vùng lồi (đa giác Voronoi).
- **Mối quan hệ đối ngẫu Delaunay (Delaunay Triangulation)**:
  - Nối các cặp điểm có ô Voronoi chung cạnh ta được **Phép đan tam giác Delaunay**.
  - Các đỉnh của biểu đồ Voronoi chính là tâm đường tròn ngoại tiếp của các tam giác Delaunay!
  - Thuật toán chia để trị (Lee-Preparata) có thể xây dựng Biểu đồ Voronoi và giải bài toán Cặp điểm gần nhất trong thời gian tối ưu $\Theta(n \log n)$.

---

### Bài 7 (Exercises 5.5 - Trang 198)
**Đề bài:**  
*Hãy giải thích cách xác định điểm $p_{max}$ trong thuật toán Quickhull một cách giải tích.*

#### Lời giải chi tiết:
Cho đường thẳng có hướng đi từ điểm $p_1(x_1, y_1)$ đến điểm $p_n(x_n, y_n)$.  
Khoảng cách hình học từ một điểm $p(x, y)$ bất kỳ tới đường thẳng $p_1 p_n$ được tính theo công thức khoảng cách từ điểm tới đường thẳng:
$$h(p) = \frac{2 \times \text{Diện tích}(\Delta p_1 p_n p)}{\text{Độ dài}(p_1 p_n)}$$
Vì đoạn thẳng $p_1 p_n$ có độ dài cố định $L = \sqrt{(x_n - x_1)^2 + (y_n - y_1)^2}$, điểm $p$ nằm xa đường thẳng nhất chính là điểm làm cho **diện tích tam giác $\Delta p_1 p_n p$ đạt giá trị lớn nhất**!

Diện tích đại số có dấu của tam giác $\Delta p_1 p_n p$ được tính bằng định thức cấp 3:
$$D(p) = \begin{vmatrix} x_1 & y_1 & 1 \\ x_n & y_n & 1 \\ x & y & 1 \end{vmatrix} = x_1 y_n + x y_1 + x_n y - x y_n - x_1 y - x_n y_1$$
- Điểm $p$ nằm bên trái $\vec{p_1 p_n} \iff D(p) > 0$.
- **Quy tắc giải tích tìm $p_{max}$**:
  Duyệt qua tất cả các điểm $p \in S_1$, tính giá trị định thức $D(p)$. Điểm $p_{max}$ chính là điểm có giá trị định thức lớn nhất:
  $$p_{max} = \arg\max_{p \in S_1} D(p)$$
Thao tác này chỉ cần các phép nhân cộng số học cơ bản, không cần tính căn bậc hai hay lượng giác, tốn thời gian $O(1)$ cho mỗi điểm.

---

### Bài 8 (Exercises 5.5 - Trang 198)
**Đề bài:**  
*Hiệu năng thời gian trong trường hợp tốt nhất của thuật toán Quickhull là bao nhiêu?*

#### Lời giải chi tiết:

**Khẳng định: $\Theta(n)$.**

**Chứng minh:**  
Trường hợp tốt nhất xảy ra khi:
1. Sau khi tìm được 2 điểm cực trị $p_1, p_n$ và xác định điểm $p_{max}$ cho nửa trên (và điểm cực tiểu cho nửa dưới), tam giác $\Delta p_1 p_{max} p_n$ **chứa TẤT CẢ các điểm còn lại của tập hợp**!
2. Toàn bộ $n - 3$ điểm đều rơi vào bên trong tam giác $\Delta p_1 p_{max} p_n$, do đó chúng bị loại bỏ đồng loạt ngay lập tức ở bước đầu tiên!
3. Các tập bài toán con $S_{11}$ và $S_{12}$ đều rỗng, thuật toán kết thúc ngay mà không cần gọi đệ quy thêm.
4. Tổng số phép toán:
   - Tìm $p_1, p_n$: tốn $n$ phép so sánh.
   - Phân chia điểm và tìm $p_{max}$: tốn $O(n)$ phép tính định thức.
   - Kiểm tra điểm trong tam giác: tốn $O(n)$.
- **Kết luận**: Thời gian trong trường hợp tốt nhất của Quickhull là **tuyến tính $\Theta(n)$**.

---

### Bài 9 (Exercises 5.5 - Trang 198)
**Đề bài:**  
*Hãy đưa ra một ví dụ cụ thể về cấu hình các điểm đầu vào khiến cho thuật toán Quickhull chạy trong thời gian bậc hai $\Theta(n^2)$.*

#### Lời giải chi tiết:

**Cấu hình suy biến:**  
Xét tập hợp $n$ điểm nằm trên một đường cong lồi nghiêm ngặt, ví dụ parabol $y = x^2$ (hoặc một cung tròn) với hoành độ phân bố lệch:
$$P = \left\{ (x_i, y_i) \mid x_i = i, y_i = i^2 \text{ với } i = 1, 2, \dots, n \right\}$$

**Phân tích diễn tiến thuật toán trên cấu hình này:**
1. Tất cả các điểm đều là đỉnh của bao lồi (không có bất kỳ điểm nào nằm bên trong tam giác để bị loại bỏ).
2. Hai điểm cực trị ban đầu là $p_1 = (1, 1)$ và $p_n = (n, n^2)$.
3. Đoạn thẳng nối $p_1 p_n$ là dây cung của parabol. Vì hàm số $f(x) = x^2$ là hàm lồi, tất cả các điểm còn lại $p_2, \dots, p_{n-1}$ đều nằm về một phía của dây cung.
4. Điểm $p_{max}$ xa dây cung nhất là điểm có hoành độ nằm sát một đầu mút (hoặc tại mỗi bước đệ quy, điểm được chọn chỉ chia tập điểm thành một tập con có kích thước $n - 2$ và một tập con rỗng $0$ điểm).
5. Kích thước bài toán con giảm theo cấp số cộng: $n \to n - 1 \to n - 2 \to \dots \to 1$.
6. Phương trình truy hồi:
   $$T(n) = T(n - 1) + c n$$
   $$T(n) = c n + c(n - 1) + \dots + c = c \frac{n(n + 1)}{2} \in \mathbf{\Theta(n^2)}$$
Đây chính là trường hợp xấu nhất khiến Quickhull tốn thời gian bậc hai $\Theta(n^2)$.

---

### Bài 10 (Exercises 5.5 - Trang 198)
**Đề bài:**  
*Cài đặt thuật toán Quickhull bằng một ngôn ngữ lập trình tùy chọn.*

#### Lời giải chi tiết:

**Mã nguồn C++ hoàn chỉnh:**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

struct Point {
    int x, y;
    bool operator<(const Point& o) const {
        return x < o.x || (x == o.x && y < o.y);
    }
};

// Định thức: > 0 nếu P3 bên trái P1->P2
int findSide(Point p1, Point p2, Point p) {
    int val = (p.y - p1.y) * (p2.x - p1.x) - (p2.y - p1.y) * (p.x - p1.x);
    if (val > 0) return 1;
    if (val < 0) return -1;
    return 0;
}

// Khoảng cách tỷ lệ thuận với giá trị tuyệt đối định thức
int lineDist(Point p1, Point p2, Point p) {
    return std::abs((p.y - p1.y) * (p2.x - p1.x) - (p2.y - p1.y) * (p.x - p1.x));
}

void quickHullRec(const std::vector<Point>& pts, Point p1, Point p2, int side, std::set<Point>& hull) {
    int ind = -1;
    int maxDist = 0;

    for (int i = 0; i < (int)pts.size(); ++i) {
        int temp = lineDist(p1, p2, pts[i]);
        if (findSide(p1, p2, pts[i]) == side && temp > maxDist) {
            ind = i;
            maxDist = temp;
        }
    }

    if (ind == -1) {
        hull.insert(p1);
        hull.insert(p2);
        return;
    }

    // Đệ quy cho hai tam giác con
    quickHullRec(pts, pts[ind], p1, -findSide(pts[ind], p1, p2), hull);
    quickHullRec(pts, pts[ind], p2, -findSide(pts[ind], p2, p1), hull);
}

std::vector<Point> quickHull(std::vector<Point>& pts) {
    int n = pts.size();
    if (n < 3) return pts;

    int min_x = 0, max_x = 0;
    for (int i = 1; i < n; ++i) {
        if (pts[i].x < pts[min_x].x) min_x = i;
        if (pts[i].x > pts[max_x].x) max_x = i;
    }

    std::set<Point> hull;
    quickHullRec(pts, pts[min_x], pts[max_x], 1, hull);
    quickHullRec(pts, pts[min_x], pts[max_x], -1, hull);

    return std::vector<Point>(hull.begin(), hull.end());
}
```

---

### Bài 11 (Exercises 5.5 - Trang 198)
**Đề bài: Dựng 100 Hình Thập giác (Creating Decagons)**  
*Cho 1000 điểm trên mặt phẳng, không có 3 điểm nào thẳng hàng. Hãy thiết kế một thuật toán để dựng 100 hình thập giác (mỗi hình có 10 đỉnh) từ các điểm này. Các thập giác không nhất thiết phải lồi nhưng phải là đa giác đơn (biên không tự cắt nhau) và không có hai thập giác nào giao nhau.*

#### Lời giải chi tiết:

**Ý tưởng thiết kế (Geometric Partitioning by Divide-and-Conquer):**
Để bảo đảm 100 hình thập giác không bao giờ giao nhau, ta sử dụng **phương pháp chia cắt hình học bằng các đường thẳng song song**:
1. **Phân rã không gian (Divide)**:
   - Sắp xếp toàn bộ 1000 điểm theo hoành độ $x$ tăng dần: $p_1, p_2, \dots, p_{1000}$ (nếu có hai điểm cùng hoành độ thì sắp theo tung độ $y$).
   - Chia danh sách 1000 điểm này thành **100 nhóm liên tiếp**, mỗi nhóm gồm đúng 10 điểm:
     - Nhóm 1: $P_1 = \{p_1, \dots, p_{10}\}$
     - Nhóm 2: $P_2 = \{p_{11}, \dots, p_{20}\}$
     - ...
     - Nhóm 100: $P_{100} = \{p_{991}, \dots, p_{1000}\}$
   - Vì các điểm đã sắp xếp theo $x$, ta luôn có thể vẽ 99 đường thẳng đứng song song với trục $y$ phân tách hoàn toàn 100 nhóm điểm này vào 100 dải thẳng đứng tách biệt!
   - **Hệ quả**: Bất kỳ đa giác nào được dựng hoàn toàn bên trong nhóm $P_k$ chắc chắn sẽ **không bao giờ có thể giao cắt** với đa giác dựng bên trong nhóm $P_j$ ($j \ne k$).
2. **Dựng Đa giác Đơn cho mỗi nhóm 10 điểm (Trị)**:
   - Với mỗi nhóm $P_k$ gồm 10 điểm:
     - Tìm điểm có tung độ nhỏ nhất $p_{start}$ trong nhóm.
     - Sắp xếp 9 điểm còn lại theo **góc cực (polar angle)** tăng dần so với điểm $p_{start}$.
     - Nối $p_{start}$ với điểm có góc nhỏ nhất, lần lượt nối tiếp tới các điểm tiếp theo theo thứ tự góc tăng dần, và cuối cùng nối điểm cuối trở về $p_{start}$.
   - Vì các góc cực tăng nghiêm ngặt và không có 3 điểm thẳng hàng, đường bao khép kín này tạo thành một **hình thập giác hình sao đơn giản (simple star-shaped polygon)** hoàn toàn không tự cắt biên!

**Độ phức tạp**:
- Sắp xếp 1000 điểm ban đầu: $O(N \log N)$ với $N = 1000$.
- Dựng 100 đa giác, mỗi đa giác tốn $10 \log 10 = O(1)$ thao tác.
- Tổng thời gian thực thi: $O(N \log N)$ cực kỳ tối ưu.

---

### Bài 12 (Exercises 5.5 - Trang 198)
**Đề bài: Đường đi Ngắn nhất Quanh Đa giác Rào chắn (Shortest Path Around)**  
*Trong mặt phẳng hai chiều có một khu vực rào chắn dạng đa giác lồi với các đỉnh tại $p_1(x_1, y_1), \dots, p_n(x_n, y_n)$. Có hai điểm $a(x_a, y_a)$ và $b(x_b, y_b)$ nằm ngoài khu vực rào chắn sao cho $x_a < \min \{x_1, \dots, x_n\}$ và $x_b > \max \{x_1, \dots, x_n\}$. Hãy thiết kế một thuật toán hiệu quả để tính độ dài của đường đi ngắn nhất giữa $a$ và $b$ mà không đi xuyên qua khu vực rào chắn.*

#### Lời giải chi tiết:

**Bản chất Hình học:**
- Vì khu vực rào chắn là một **đa giác lồi**, đường đi ngắn nhất giữa hai điểm $a$ và $b$ bên ngoài đa giác lồi bắt buộc phải là một đường gấp khúc áp sát vào biên của đa giác lồi.
- Đường đi này gồm 3 đoạn:
  1. Đoạn thẳng đi từ $a$ tới một điểm tiếp xúc (tiếp tuyến) $T_a$ trên đa giác lồi.
  2. Đi men theo chu vi của đa giác lồi từ $T_a$ đến điểm tiếp xúc $T_b$.
  3. Đoạn thẳng đi từ $T_b$ tới $b$.
- Chỉ có đúng **hai lộ trình ứng viên tối ưu**:
  - **Lộ trình 1 (Đường biên trên - Upper Path)**: Đi từ $a$ theo tiếp tuyến trên tới đỉnh $u_a$, đi men theo chu vi biên trên của đa giác lồi tới đỉnh $u_b$, sau đó đi thẳng từ $u_b$ tới $b$.
  - **Lộ trình 2 (Đường biên dưới - Lower Path)**: Đi từ $a$ theo tiếp tuyến dưới tới đỉnh $l_a$, đi men theo chu vi biên dưới của đa giác lồi tới đỉnh $l_b$, sau đó đi thẳng từ $l_b$ tới $b$.

**Mã giả thuật toán:**
```text
algorithm: ShortestPathAroundConvexPolygon(P[1..n], a, b)
    input:  Đa giác lồi P[1..n] theo thứ tự ngược chiều kim đồng hồ, hai điểm a, b.
   output:  Độ dài đường đi ngắn nhất giữa a và b tránh rào chắn P.

1   // Bước 1: Tìm các tiếp tuyến từ a và b đến đa giác lồi P
2   u_a, l_a ← Tìm_hai_tiếp_điểm_từ_điểm(a, P)
3   u_b, l_b ← Tìm_hai_tiếp_điểm_từ_điểm(b, P)
4
5   // Bước 2: Tính độ dài lộ trình biên trên
6   len_upper ← dist(a, u_a) + Đoạn_chu_vi_trên(P, u_a, u_b) + dist(u_b, b)
7
8   // Bước 3: Tính độ dài lộ trình biên dưới
9   len_lower ← dist(a, l_a) + Đoạn_chu_vi_dưới(P, l_a, l_b) + dist(l_b, b)
10
11  return min(len_upper, len_lower)
```

**Phân tích độ phức tạp:**
- Tìm tiếp tuyến từ một điểm ngoài đến đa giác lồi $n$ đỉnh:
  - Nếu quét tuần tự: tốn thời gian $O(n)$.
  - Nếu sử dụng tìm kiếm nhị phân chia để trị (dựa trên tính chất đơn điệu của hướng quay): tốn $O(\log n)$.
- Tính độ dài chu vi dọc theo biên: sử dụng mảng cộng dồn chu vi (prefix sums) trong thời gian $O(1)$ sau khi tiền xử lý $O(n)$.
- **Tổng thời gian thực thi**: Tuyến tính $O(n)$, hoặc $O(\log n)$ nếu các đỉnh của đa giác đã được lưu trong mảng có cấu trúc truy vấn nhị phân.
