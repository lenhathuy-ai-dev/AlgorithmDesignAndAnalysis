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
