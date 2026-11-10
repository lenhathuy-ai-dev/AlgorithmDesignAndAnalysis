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
