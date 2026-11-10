# CHUYÊN ĐỀ 05: LUẬT HORNER VÀ LŨY THỪA NHỊ PHÂN & LỜI GIẢI BÀI TẬP 6.5
*Tài liệu tham chiếu: A. Levitin, "Introduction to the Design and Analysis of Algorithms", 3rd Edition, Chương 6, Mục 6.5, Trang 234–244.*

---

## PHẦN I. LÝ THUYẾT VÀ MÃ GIẢ CHUẨN HÓA

### 5.1. Luật Horner để tính giá trị Đa thức (Horner's Rule)
Xét đa thức bậc $n$ theo biến $x$:
$$P(x) = a_n x^n + a_{n-1} x^{n-1} + \dots + a_1 x + a_0$$

#### Tiếp cận vét cạn:
- Tính từng số hạng $a_i x^i$ độc lập: $x^i$ tốn $i-1$ phép nhân, nhân với $a_i$ tốn thêm 1 phép nhân $\implies \sum_{i=1}^n i = \frac{n(n+1)}{2} \in \Theta(n^2)$ phép nhân.
- Nếu tối ưu bằng cách lưu lũy thừa trước ($x^i = x^{i-1} \cdot x$): Tốn $2n - 1$ phép nhân.

#### Tiếp cận Biến đổi để trị (Representation Change - Luật Horner):
Bằng cách đặt $x$ làm thừa số chung từ trong ra ngoài (cấu trúc ngoặc lồng nhau):
$$P(x) = (\dots((a_n x + a_{n-1})x + a_{n-2})x + \dots + a_1)x + a_0$$

Công thức truy hồi tính toán:
$$p_0 = a_n$$
$$p_i = p_{i-1} \cdot x + a_{n-i} \quad (i = 1, 2, \dots, n)$$
Giá trị cuối cùng $p_n$ chính là $P(x)$!

##### Mã giả chuẩn hóa:
```text
function: Horner(P[0..n], x): Real
    input: P[0..n]: Array of real numbers – hệ số của đa thức an, an-1, ..., a0.
           n: integer (n ≥ 0) – bậc của đa thức.
           x: real number – điểm cần tính giá trị.
    output: p: Real – giá trị P(x).

 1  p = P[0] – gán p = an.
 2  for i = 1 to n do
 3      p = p * x + P[i] – tương đương p = p * x + an-i.
 4  end-for
 5  return p.
```

#### Phân tích độ phức tạp:
- **Số phép nhân:** Đúng $n$ phép nhân.
- **Số phép cộng:** Đúng $n$ phép cộng.
- **Tính tối ưu tuyệt đối:** Năm 1966, nhà toán học A. Pan đã chứng minh định lý kinh điển: Mọi thuật toán dựa trên các phép tính số học cơ bản để tính đa thức bậc $n$ đều phải thực hiện **ít nhất $n$ phép nhân và $n$ phép cộng**. Do đó, **Luật Horner là tối ưu tuyệt đối (strictly optimal)**!

#### Ứng dụng phụ: Chia đa thức theo sơ đồ Horner (Synthetic Division)
Khi chia $P(x)$ cho nhị thức bậc nhất $(x - c)$, ta có:
$$P(x) = (x - c) Q(x) + R$$
Trong đó phần dư $R = P(c)$, và các hệ số của đa thức thương $Q(x) = q_{n-1} x^{n-1} + \dots + q_0$ chính là các giá trị trung gian $p_0, p_1, \dots, p_{n-1}$ được sinh ra trong quá trình chạy Luật Horner tại $x = c$!

---

### 5.2. Lũy thừa nhị phân (Binary Exponentiation)
Bài toán: Tính $a^n$ với $a$ là số thực (hoặc ma trận) và $n$ là số nguyên dương.
- Tiếp cận nhân tuần tự: $a \times a \times \dots \times a$ tốn $n - 1$ phép nhân $\implies \Theta(n)$.
- Tiếp cận Biến đổi biểu diễn: Biểu diễn số mũ $n$ trong hệ nhị phân:
  $$n = b_m b_{m-1} \dots b_1 b_0 \quad (b_m = 1, b_i \in \{0, 1\})$$
  với $m = \lfloor \log_2 n \rfloor$.

#### 1. Lũy thừa nhị phân từ Trái sang Phải (Left-to-Right Binary Exponentiation)
Quét các bit từ trái sang phải (từ bit có trọng số cao $b_{m-1}$ xuống $b_0$):
- Khởi tạo tích lũy: $product = a$.
- Với mỗi bit $b_i$ từ $m-1$ lùi về $0$:
  + Luôn luôn bình phương: $product = product \times product$.
  + Nếu bit $b_i = 1$: Nhân thêm cơ số: $product = product \times a$.

##### Mã giả chuẩn hóa:
```text
function: LeftRightBinaryExponentiation(a, b[0..m]): Real
    input: a: Real – cơ số.
           b[0..m]: Array of bits – biểu diễn nhị phân của số mũ n (bm là bit cao nhất = 1).
           m: integer – m = floor(log2(n)).
    output: result: Real – giá trị a^n.

 1  product = a
 2  for i = m - 1 downto 0 do
 3      product = product * product – luôn luôn bình phương.
 4      if b[i] = 1 then
 5          product = product * a – nhân thêm cơ số nếu bit là 1.
 6      end-if
 7  end-for
 8  return product.
```

#### 2. Lũy thừa nhị phân từ Phải sang Trái (Right-to-Left Binary Exponentiation)
Quét các bit từ phải sang trái (từ bit thấp $b_0$ lên $b_m$):
- Khởi tạo: $term = a$, $product = 1$.
- Duy trì $term = a^{2^i}$ tăng dần qua từng bước bình phương ($term = term \times term$).
- Nếu bit $b_i = 1$: gom $term$ vào kết quả: $product = product \times term$.

##### Mã giả chuẩn hóa:
```text
function: RightLeftBinaryExponentiation(a, n): Real
    input: a: Real – cơ số.
           n: positive integer – số mũ.
    output: product: Real – giá trị a^n.

 1  term = a
 2  product = 1.0
 3  while n > 0 do
 4      if n mod 2 = 1 then
 5          product = product * term
 6      end-if
 7      term = term * term – bình phương lũy kế.
 8      n = floor(n / 2) – dịch phải 1 bit.
 9  end-while
10  return product.
```

#### Độ phức tạp tính toán:
- Số phép nhân:
  $$M(n) = \lfloor \log_2 n \rfloor + (\text{số lượng bit 1 trong } n) - 1$$
  - Tốt nhất ($n = 2^k$): $M(n) = \lfloor \log_2 n \rfloor$.
  - Xấu nhất ($n = 2^{k+1} - 1$): $M(n) = 2 \lfloor \log_2 n \rfloor$.
  - **Độ phức tạp luôn là $\Theta(\log n)$**, giảm ngoạn mục từ tuyến tính $\Theta(n)$ xuống logarit. Ví dụ tính $a^{1000}$ chỉ cần khoảng 14 phép nhân thay vì 999 phép nhân!

---

## PHẦN II. GIẢI CHI TIẾT 100% BÀI TẬP EXERCISES 6.5 (BÀI 1 ĐẾN BÀI 10)

### Bài 6.5.1: Số phép tính của thuật toán vét cạn tính đa thức
> **Đề bài:**
> Cho thuật toán vét cạn tính giá trị đa thức:
> ```text
> p = a0
> for i = 1 to n do
>     power = 1
>     for j = 1 to i do
>         power = power * x
>     end-for
>     p = p + a[i] * power
> end-for
> ```
> Hãy thiết lập công thức tổng và tính chính xác số phép nhân, số phép cộng mà thuật toán thực hiện.

**Lời giải chi tiết:**
1. **Số phép nhân:**
   - Trong vòng lặp trong (tính $x^i$): Vòng lặp $j$ chạy $i$ lần $\implies i$ phép nhân.
   - Bên ngoài vòng lặp trong (tính $a_i \cdot power$): 1 phép nhân.
   - Tổng số phép nhân cho mỗi bước $i$: $i + 1$.
   - Tổng trên toàn bộ thuật toán:
     $$M(n) = \sum_{i=1}^n (i + 1) = \sum_{i=1}^n i + \sum_{i=1}^n 1 = \frac{n(n+1)}{2} + n = \frac{n(n+3)}{2} \in \Theta(n^2)$$
2. **Số phép cộng:**
   - Mỗi bước $i$ thực hiện đúng 1 phép cộng $p = p + a_i \cdot power$.
   - Tổng số phép cộng:
     $$A(n) = \sum_{i=1}^n 1 = n \in \Theta(n)$$

---

### Bài 6.5.2: Tối ưu hóa tính lũy thừa kế tiếp
> **Đề bài:**
> Thiết kế thuật toán tính đa thức sử dụng lưu lũy thừa kế tiếp: $power_i = power_{i-1} \cdot x$.
> Xác định số phép nhân và số phép cộng của thuật toán này.

**Lời giải chi tiết:**
- **Mã giả:**
```text
p = a[0]
power = 1.0
for i = 1 to n do
    power = power * x – tốn 1 phép nhân
    p = p + a[i] * power – tốn 1 phép nhân và 1 phép cộng
end-for
return p
```
- **Số phép tính:**
  - Mỗi bước $i$ chỉ tốn 2 phép nhân và 1 phép cộng.
  - Tổng số phép nhân: $M(n) = 2n$.
  - Tổng số phép cộng: $A(n) = n$.
  - So sánh với Luật Horner: Horner chỉ cần $n$ phép nhân (tiết kiệm đúng 50% số phép nhân)!

---

### Bài 6.5.3: So sánh chi phí giữa Luật Horner và Tối ưu lũy thừa kế tiếp
> **Đề bài:**
> a. So sánh số phép toán giữa Luật Horner và thuật toán ở Bài 2.
> b. Luật Horner có sử dụng thêm bộ nhớ phụ trợ hay không?

**Lời giải chi tiết:**
- **a. So sánh chi phí:**
  - Thuật toán Bài 2: $2n$ phép nhân, $n$ phép cộng.
  - Luật Horner: $n$ phép nhân, $n$ phép cộng.
  - $\implies$ Luật Horner giảm được đúng $n$ phép nhân, tương đương tiết kiệm 50% thời gian nhân.
- **b. Bộ nhớ phụ trợ:**
  - Luật Horner chỉ dùng đúng một biến tích lũy duy nhất $p$ $\implies$ Bộ nhớ phụ trợ là $O(1)$ (tại chỗ), không dùng thêm bất kỳ mảng phụ nào.

---

### Bài 6.5.4: Áp dụng Luật Horner cho đa thức cụ thể
> **Đề bài:**
> Áp dụng Luật Horner để tính giá trị của đa thức:
> $$P(x) = 2 x^4 - x^3 + 3 x^2 + x - 5 \quad \text{tại } x = 3$$
> Trình bày từng bước tính toán.

**Lời giải chi tiết:**
- Hệ số: $a_4 = 2, a_3 = -1, a_2 = 3, a_1 = 1, a_0 = -5$. Điểm $x = 3$.
- Biểu diễn Horner:
  $$P(3) = (((2 \times 3 - 1) \times 3 + 3) \times 3 + 1) \times 3 - 5$$
- Các bước tính toán liên tiếp:
  - $p_0 = a_4 = 2$.
  - $p_1 = p_0 \times 3 + a_3 = 2 \times 3 + (-1) = 6 - 1 = 5$.
  - $p_2 = p_1 \times 3 + a_2 = 5 \times 3 + 3 = 15 + 3 = 18$.
  - $p_3 = p_2 \times 3 + a_1 = 18 \times 3 + 1 = 54 + 1 = 55$.
  - $p_4 = p_3 \times 3 + a_0 = 55 \times 3 + (-5) = 165 - 5 = 160$.
- **Kết luận:** $P(3) = 160$.

---

### Bài 6.5.5: Chuyển đổi số nhị phân sang thập phân bằng Luật Horner
> **Đề bài:**
> Giải thích tại sao việc chuyển đổi một số nhị phân sang hệ thập phân có thể xem là một trường hợp đặc biệt của Luật Horner.
> Áp dụng tính giá trị thập phân của số nhị phân $110100101_2$.

**Lời giải chi tiết:**
- **Nguyên lý:** Một số nhị phân $b_n b_{n-1} \dots b_0$ thực chất là giá trị của đa thức:
  $$P(x) = b_n x^n + b_{n-1} x^{n-1} + \dots + b_1 x + b_0 \quad \text{tại } x = 2$$
  Do đó, việc đổi nhị phân sang thập phân chính là chạy Luật Horner với cơ số $x = 2$!
  Tại mỗi bước, ta chỉ việc lấy giá trị hiện tại **nhân 2 (dịch trái 1 bit) rồi cộng thêm bit tiếp theo**.
- **Tính toán cho $110100101_2$:**
  - $p = 1$
  - Bit 1: $p = 1 \times 2 + 1 = 3$
  - Bit 0: $p = 3 \times 2 + 0 = 6$
  - Bit 1: $p = 6 \times 2 + 1 = 13$
  - Bit 0: $p = 13 \times 2 + 0 = 26$
  - Bit 0: $p = 26 \times 2 + 0 = 52$
  - Bit 1: $p = 52 \times 2 + 1 = 105$
  - Bit 0: $p = 105 \times 2 + 0 = 210$
  - Bit 1: $p = 210 \times 2 + 1 = 421$
- **Kết quả:** $110100101_2 = 421_{10}$.

---

### Bài 6.5.6: Chia đa thức bằng Sơ đồ Horner (Synthetic Division)
> **Đề bài:**
> Chia đa thức $P(x) = 2 x^4 - x^3 + 3 x^2 + x - 5$ cho $(x - 3)$.
> Xác định đa thức thương $Q(x)$ và phần dư $R$.

**Lời giải chi tiết:**
- Bảng tổng hợp sơ đồ Horner tại $x = 3$:
  $$\begin{matrix} & a_4 = 2 & a_3 = -1 & a_2 = 3 & a_1 = 1 & a_0 = -5 \\ \times 3 & & 6 & 15 & 54 & 165 \\ \hline & q_3 = 2 & q_2 = 5 & q_1 = 18 & q_0 = 55 & R = 160 \end{matrix}$$
- Các hệ số ở hàng cuối cùng (ngoại trừ số cuối) chính là các hệ số của đa thức thương $Q(x)$, và số cuối cùng chính là phần dư $R$:
  $$Q(x) = 2 x^3 + 5 x^2 + 18 x + 55$$
  $$R = 160$$
  Thỏa mãn đẳng thức: $P(x) = (x - 3)(2 x^3 + 5 x^2 + 18 x + 55) + 160$.

---

### Bài 6.5.7: Mô phỏng Lũy thừa nhị phân Trái-sang-Phải
> **Đề bài:**
> Tính $a^{13}$ bằng thuật toán Lũy thừa nhị phân từ Trái sang Phải.

**Lời giải chi tiết:**
- Chuyển số mũ 13 sang hệ nhị phân:
  $$13 = 8 + 4 + 1 = 1101_2$$
  Các bit theo thứ tự từ trái sang phải: $b_3 = 1, b_2 = 1, b_1 = 0, b_0 = 1$.
- Bắt đầu với $product = a$ (ứng với bit cao nhất $b_3 = 1$):
  1. **Xét bit $b_2 = 1$:**
     - Bình phương: $product = product^2 = (a)^2 = a^2$.
     - Vì $b_2 = 1$, nhân thêm $a$: $product = a^2 \times a = a^3$.
  2. **Xét bit $b_1 = 0$:**
     - Bình phương: $product = product^2 = (a^3)^2 = a^6$.
     - Vì $b_1 = 0$, không nhân thêm.
  3. **Xét bit $b_0 = 1$:**
     - Bình phương: $product = product^2 = (a^6)^2 = a^{12}$.
     - Vì $b_0 = 1$, nhân thêm $a$: $product = a^{12} \times a = a^{13}$.
- **Tổng số phép nhân:** 3 phép bình phương + 2 phép nhân cơ số = **5 phép nhân**!

---

### Bài 6.5.8: Mô phỏng Lũy thừa nhị phân Phải-sang-Trái
> **Đề bài:**
> Tính $a^{13}$ bằng thuật toán Lũy thừa nhị phân từ Phải sang Trái.

**Lời giải chi tiết:**
- Số mũ $n = 13 = 1101_2$. Khởi tạo $product = 1$, $term = a$.
- Các bước thực hiện:
  1. $n = 13$ (lẻ): $product = product \times term = 1 \times a = a$.
     Bình phương: $term = term^2 = a^2$. Số mũ mới $n = \lfloor 13/2 \rfloor = 6$.
  2. $n = 6$ (chẵn): không nhân vào $product$.
     Bình phương: $term = (a^2)^2 = a^4$. Số mũ mới $n = \lfloor 6/2 \rfloor = 3$.
  3. $n = 3$ (lẻ): $product = product \times term = a \times a^4 = a^5$.
     Bình phương: $term = (a^4)^2 = a^8$. Số mũ mới $n = \lfloor 3/2 \rfloor = 1$.
  4. $n = 1$ (lẻ): $product = product \times term = a^5 \times a^8 = a^{13}$.
     Số mũ mới $n = 0 \implies$ Dừng lại.
- **Kết quả:** $product = a^{13}$. Tổng cộng đúng 5 phép nhân.

---

### Bài 6.5.9: Ứng dụng Lũy thừa nhị phân cho Nhân ma trận (Tính số Fibonacci thứ $n$ trong $O(\log n)$)
> **Đề bài:**
> Biết rằng số Fibonacci thứ $n$ có thể tính thông qua lũy thừa ma trận:
> $$\begin{pmatrix} F_{n+1} & F_n \\ F_n & F_{n-1} \end{pmatrix} = \begin{pmatrix} 1 & 1 \\ 1 & 0 \end{pmatrix}^n$$
> Giải thích cách tính số Fibonacci thứ $10^9$ trong thời gian $O(\log n)$ phép toán.

**Lời giải chi tiết:**
- Đặt ma trận $M = \begin{pmatrix} 1 & 1 \\ 1 & 0 \end{pmatrix}$.
- Phép nhân hai ma trận kích thước $2 \times 2$ chỉ tốn 8 phép nhân và 4 phép cộng các số thực $\implies$ tốn thời gian hằng số $O(1)$.
- Áp dụng thuật toán Lũy thừa nhị phân trên ma trận $M$ với số mũ $n = 10^9$:
  - Vì $10^9 < 2^{30}$, số mũ có tối đa 30 bit nhị phân.
  - Thuật toán lũy thừa nhị phân chỉ cần thực hiện tối đa $2 \times 30 = 60$ phép nhân ma trận $2 \times 2$!
  - 60 phép nhân ma trận được tính toán trong chưa đầy $1$ micro-giây!
- **Độ phức tạp thời gian:** $\Theta(\log n)$, vượt trội hoàn toàn so với tiếp cận vòng lặp tuyến tính $\Theta(n)$ (cần $10^9$ phép tính, mất vài giây) và đệ quy vét cạn $\Theta(2^n)$ (mất hàng tỷ năm).

---

### Bài 6.5.10: Tìm chuỗi phép nhân tối thiểu (Addition Chain Exponentiation)
> **Đề bài:**
> Thuật toán lũy thừa nhị phân tính $a^{15}$ tốn bao nhiêu phép nhân? Có tồn tại phương pháp tính $a^{15}$ với số phép nhân ít hơn hay không?

**Lời giải chi tiết:**
1. **Lũy thừa nhị phân:**
   - $15 = 1111_2$. Số bit $m = 3$, số bit 1 là 4.
   - Số phép nhân: $\lfloor \log_2 15 \rfloor + 4 - 1 = 3 + 3 = 6$ phép nhân.
   - Chuỗi lũy thừa: $a \to a^2 \to a^3 \to a^6 \to a^7 \to a^{14} \to a^{15}$ (6 phép nhân).
2. **Phương pháp xích cộng tối ưu (Addition Chain):**
   - Ta hoàn toàn có thể tính $a^{15}$ chỉ với **5 phép nhân**:
     - Bước 1: $a \times a = a^2$ (1 phép nhân)
     - Bước 2: $a^2 \times a = a^3$ (2 phép nhân)
     - Bước 3: $a^3 \times a^3 = a^6$ (3 phép nhân)
     - Bước 4: $a^6 \times a^6 = a^{12}$ (4 phép nhân)
     - Bước 5: $a^{12} \times a^3 = a^{15}$ (5 phép nhân!)
- **Kết luận:** Lũy thừa nhị phân rất nhanh nhưng không phải lúc nào cũng cho chuỗi phép nhân ngắn nhất tuyệt đối. Bài toán tìm xích cộng ngắn nhất (Shortest Addition Chain) là một bài toán NP-khó.
