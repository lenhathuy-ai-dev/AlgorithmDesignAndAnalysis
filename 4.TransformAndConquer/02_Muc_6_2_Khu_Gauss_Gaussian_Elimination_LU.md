# CHUYÊN ĐỀ 02: KHỬ GAUSS (GAUSSIAN ELIMINATION) & LỜI GIẢI BÀI TẬP 6.2
*Tài liệu tham chiếu: A. Levitin, "Introduction to the Design and Analysis of Algorithms", 3rd Edition, Chương 6, Mục 6.2, Trang 208–218.*

---

## PHẦN I. LÝ THUYẾT VÀ MÃ GIẢ CHUẨN HÓA

### 2.1. Phát biểu bài toán Hệ phương trình đại số tuyến tính
Xét hệ gồm $n$ phương trình đại số tuyến tính với $n$ ẩn số $x_1, x_2, \dots, x_n$:
$$\begin{matrix} a_{11} x_1 + a_{12} x_2 + \dots + a_{1n} x_n = b_1 \\ a_{21} x_1 + a_{22} x_2 + \dots + a_{2n} x_n = b_2 \\ \dots \\ a_{n1} x_1 + a_{n2} x_2 + \dots + a_{nn} x_n = b_n \end{matrix}$$

Dưới dạng ma trận: $A x = b$, trong đó $A = [a_{ij}]_{n \times n}$ là ma trận hệ số, $x = [x_i]_{n \times 1}$ là vector ẩn số, và $b = [b_i]_{n \times 1}$ là vector vế phải.
Ma trận bổ sung (Augmented matrix) kích thước $n \times (n+1)$ được ký hiệu là $\tilde{A} = [A | b]$.

---

### 2.2. Bản chất Biến đổi để trị trong Khử Gauss (Gaussian Elimination)
Khử Gauss là ví dụ điển hình nhất của biến thể **Biến đổi thể hiện (Instance Simplification)**:
1. **Giai đoạn 1: Khử xuôi (Forward Elimination):**
   - Biến đổi ma trận bổ sung đầy đủ $[A | b]$ thành ma trận tam giác trên tương đương $[U | y]$ bằng chuỗi các phép biến đổi sơ cấp trên dòng (Elementary row operations):
     - Nhân một dòng với một hằng số khác 0.
     - Cộng vào một dòng một bội số của dòng khác.
     - Đổi chỗ hai dòng.
2. **Giai đoạn 2: Thế ngược (Back Substitution):**
   - Giải hệ tam giác trên $Ux = y$ từ ẩn cuối cùng ngược lên ẩn đầu tiên:
     $$x_n = \frac{y_n}{u_{nn}}$$
     $$x_i = \frac{y_i - \sum_{j=i+1}^n u_{ij} x_j}{u_{ii}} \quad (i = n-1, n-2, \dots, 1)$$

---

### 2.3. Thuật toán Khử xuôi cải tiến với Trục xoay một phần (BetterForwardElimination)
Để tránh phép chia cho 0 và giảm thiểu tối đa sai số làm tròn số thực (roundoff errors), tại mỗi bước $i$, thuật toán tìm dòng $p$ ($i \le p \le n-1$) có phần tử $|A[p, i]|$ lớn nhất để hoán đổi với dòng $i$ (kỹ thuật **Partial Pivoting - Chọn phần tử trục xoay một phần**).

##### Mã giả chuẩn hóa:
```text
function: BetterForwardElimination(A[0..n - 1, 0..n]): void
    input: A[0..n - 1, 0..n]: Matrix of real numbers – ma trận bổ sung [A | b] cỡ n x (n + 1).
           n: integer (n ≥ 1) – số lượng phương trình và ẩn số.
    output: A[0..n - 1, 0..n] được biến đổi tại chỗ thành dạng tam giác trên [U | y].

 1  for i = 0 to n - 2 do
 2      pivot_row = i
 3      for j = i + 1 to n - 1 do
 4          if |A[j, i]| > |A[pivot_row, i]| then
 5              pivot_row = j
 6          end-if
 7      end-for
 8      if pivot_row != i then
 9          SwapRows(A, i, pivot_row) – đổi chỗ dòng i và dòng pivot_row.
10      end-if
11      for j = i + 1 to n - 1 do
12          temp = A[j, i] / A[i, i]
13          for k = i to n do
14              A[j, k] = A[j, k] - A[i, k] * temp
15          end-for
16      end-for
17  end-for
```

##### Thuật toán Thế ngược (BackSubstitution):
```text
function: BackSubstitution(U[0..n - 1, 0..n]): Array[0..n - 1] of Real
    input: U[0..n - 1, 0..n]: Matrix – ma trận tam giác trên [U | y].
    output: x[0..n - 1]: Array of real numbers – nghiệm của hệ phương trình.

 1  for i = n - 1 downto 0 do
 2      sum = 0.0
 3      for j = i + 1 to n - 1 do
 4          sum = sum + U[i, j] * x[j]
 5      end-for
 6      x[i] = (U[i, n] - sum) / U[i, i]
 7  end-for
 8  return x.
```

---

### 2.4. Phân tích độ phức tạp tính toán
- **Số phép nhân và chia trong Khử xuôi:**
  $$M(n) = \sum_{i=0}^{n-2} \sum_{j=i+1}^{n-1} (n - i + 1) = \sum_{i=0}^{n-2} (n - 1 - i)(n - i + 1) = \frac{n(n-1)(2n+5)}{6} \approx \frac{1}{3} n^3 \in \Theta(n^3)$$
- **Số phép cộng và trừ trong Khử xuôi:**
  $$A(n) = \sum_{i=0}^{n-2} \sum_{j=i+1}^{n-1} (n - i) = \frac{n(n-1)(2n-1)}{6} \approx \frac{1}{3} n^3 \in \Theta(n^3)$$
- **Số phép tính trong Thế ngược:**
  $$M_{\text{back}}(n) = \sum_{i=0}^{n-1} (n - 1 - i + 1) = \frac{n(n+1)}{2} \in \Theta(n^2)$$
- **Tổng thời gian giải hệ phương trình:**
  $$T(n) = \Theta(n^3) + \Theta(n^2) = \Theta(n^3)$$

---

### 2.5. Phân rã LU (LU Decomposition)
Ma trận vuông $A$ kích thước $n \times n$ có thể được phân rã thành tích của hai ma trận:
$$A = L \cdot U$$
- $L$ là ma trận tam giác dưới với tất cả các phần tử trên đường chéo chính bằng 1 (Unit Lower Triangular Matrix):
  $$L = \begin{pmatrix} 1 & 0 & \dots & 0 \\ m_{21} & 1 & \dots & 0 \\ \vdots & \vdots & \ddots & \vdots \\ m_{n1} & m_{n2} & \dots & 1 \end{pmatrix}$$
  Trong đó các hệ số $m_{ji} = \frac{A[j, i]}{A[i, i]}$ chính là các hệ số khử dòng thu được trong quá trình khử Gauss!
- $U$ là ma trận tam giác trên thu được sau giai đoạn khử xuôi của Khử Gauss.
- **Ứng dụng cực kỳ mạnh mẽ của phân rã LU:**
  Để giải hệ $A x = b$, ta viết thành $L (U x) = b$.
  1. Đặt $y = U x$, giải hệ tam giác dưới $L y = b$ bằng phép thế tiến (Forward Substitution) trong $\Theta(n^2)$.
  2. Giải hệ tam giác trên $U x = y$ bằng phép thế ngược (Back Substitution) trong $\Theta(n^2)$.
  3. Nếu cần giải $k$ hệ phương trình với cùng ma trận hệ số $A$ nhưng các vế phải $b^{(1)}, b^{(2)}, \dots, b^{(k)}$ khác nhau:
     - Ta chỉ cần phân rã LU **đúng 1 lần** tốn $\Theta(n^3)$.
     - Sau đó với mỗi vế phải, chỉ tốn $2 \times \Theta(n^2) = \Theta(n^2)$.
     - Tổng thời gian: $\Theta(n^3 + k n^2)$, tiết kiệm hơn rất nhiều so với chạy lại toàn bộ Khử Gauss $k$ lần ($\Theta(k n^3)$).

---

## PHẦN II. GIẢI CHI TIẾT 100% BÀI TẬP EXERCISES 6.2 (BÀI 1 ĐẾN BÀI 12)

### Bài 6.2.1: Giải hệ phương trình tuyến tính bằng Khử Gauss
> **Đề bài:**
> Giải hệ phương trình tuyến tính sau bằng thuật toán Khử Gauss:
> $$\begin{matrix} x_1 - 4 x_2 + 2 x_3 = \frac{1}{2} \\ 2 x_1 - x_2 + 5 x_3 = -4 \\ -x_1 + 3 x_2 - x_3 = 1 \end{matrix}$$

**Lời giải chi tiết từng bước:**
1. **Thiết lập ma trận bổ sung:**
   $$\tilde{A} = \begin{pmatrix} 1 & -4 & 2 & \frac{1}{2} \\ 2 & -1 & 5 & -4 \\ -1 & 3 & -1 & 1 \end{pmatrix}$$

2. **Bước 1: Khử các phần tử ở cột 1 dưới dòng 1 (sử dụng dòng 1 làm dòng trục xoay):**
   - Hệ số khử dòng 2: $m_{21} = \frac{2}{1} = 2$.
     Dòng $2 \leftarrow \text{Dòng } 2 - 2 \times \text{Dòng } 1$:
     $[2, -1, 5, -4] - 2 \times [1, -4, 2, \frac{1}{2}] = [0, 7, 1, -5]$.
   - Hệ số khử dòng 3: $m_{31} = \frac{-1}{1} = -1$.
     Dòng $3 \leftarrow \text{Dòng } 3 - (-1) \times \text{Dòng } 1 = \text{Dòng } 3 + \text{Dòng } 1$:
     $[-1, 3, -1, 1] + [1, -4, 2, \frac{1}{2}] = [0, -1, 1, \frac{3}{2}]$.
   - Ma trận sau bước 1:
     $$\begin{pmatrix} 1 & -4 & 2 & \frac{1}{2} \\ 0 & 7 & 1 & -5 \\ 0 & -1 & 1 & \frac{3}{2} \end{pmatrix}$$

3. **Bước 2: Khử phần tử ở cột 2 dưới dòng 2 (sử dụng dòng 2 làm dòng trục xoay):**
   - Hệ số khử dòng 3: $m_{32} = \frac{-1}{7}$.
     Dòng $3 \leftarrow \text{Dòng } 3 - \left(-\frac{1}{7}\right) \times \text{Dòng } 2 = \text{Dòng } 3 + \frac{1}{7} \times \text{Dòng } 2$:
     $[0, -1, 1, \frac{3}{2}] + \frac{1}{7} \times [0, 7, 1, -5] = [0, 0, 1 + \frac{1}{7}, \frac{3}{2} - \frac{5}{7}] = [0, 0, \frac{8}{7}, \frac{11}{14}]$.
   - Ma trận tam giác trên thu được $[U | y]$:
     $$\begin{pmatrix} 1 & -4 & 2 & \frac{1}{2} \\ 0 & 7 & 1 & -5 \\ 0 & 0 & \frac{8}{7} & \frac{11}{14} \end{pmatrix}$$

4. **Bước 3: Thế ngược (Back Substitution):**
   - Từ dòng 3: $\frac{8}{7} x_3 = \frac{11}{14} \implies x_3 = \frac{11}{14} \times \frac{7}{8} = \frac{11}{16}$.
   - Từ dòng 2: $7 x_2 + x_3 = -5 \implies 7 x_2 = -5 - \frac{11}{16} = -\frac{91}{16} \implies x_2 = -\frac{13}{16}$.
   - Từ dòng 1: $x_1 - 4 x_2 + 2 x_3 = \frac{1}{2} \implies x_1 = \frac{1}{2} + 4 \left(-\frac{13}{16}\right) - 2 \left(\frac{11}{16}\right) = \frac{8}{16} - \frac{52}{16} - \frac{22}{16} = -\frac{66}{16} = -\frac{33}{8}$.
- **Kết luận nghiệm:**
  $$x_1 = -\frac{33}{8} = -4.125, \quad x_2 = -\frac{13}{16} = -0.8125, \quad x_3 = \frac{11}{16} = 0.6875$$

---

### Bài 6.2.2: Tìm phân rã LU từ quá trình Khử Gauss
> **Đề bài:**
> a. Áp dụng kết quả khử Gauss từ Bài 1 để xác định phân rã $A = LU$ của ma trận hệ số:
> $$A = \begin{pmatrix} 1 & -4 & 2 \\ 2 & -1 & 5 \\ -1 & 3 & -1 \end{pmatrix}$$
> b. Phân rã LU thuộc biến thể nào của chiến lược Biến đổi để trị?

**Lời giải chi tiết:**
- **a. Xác định ma trận L và U:**
  - Ma trận tam giác trên $U$ chính là ma trận hệ số thu được sau bước khử Gauss ở Bài 1:
    $$U = \begin{pmatrix} 1 & -4 & 2 \\ 0 & 7 & 1 \\ 0 & 0 & \frac{8}{7} \end{pmatrix}$$
  - Ma trận tam giác dưới $L$ có các phần tử trên đường chéo bằng 1, và các phần tử dưới đường chéo chính là các hệ số nhân khử dòng $m_{ji}$:
    $m_{21} = 2$, $m_{31} = -1$, $m_{32} = -\frac{1}{7}$.
    $$L = \begin{pmatrix} 1 & 0 & 0 \\ m_{21} & 1 & 0 \\ m_{31} & m_{32} & 1 \end{pmatrix} = \begin{pmatrix} 1 & 0 & 0 \\ 2 & 1 & 0 \\ -1 & -\frac{1}{7} & 1 \end{pmatrix}$$
  - **Kiểm tra lại tích $L \cdot U$:**
    $$L \cdot U = \begin{pmatrix} 1 & 0 & 0 \\ 2 & 1 & 0 \\ -1 & -\frac{1}{7} & 1 \end{pmatrix} \begin{pmatrix} 1 & -4 & 2 \\ 0 & 7 & 1 \\ 0 & 0 & \frac{8}{7} \end{pmatrix} = \begin{pmatrix} 1 & -4 & 2 \\ 2 & -8 + 7 & 4 + 1 \\ -1 & 4 - 1 & -2 - \frac{1}{7} + \frac{8}{7} \end{pmatrix} = \begin{pmatrix} 1 & -4 & 2 \\ 2 & -1 & 5 \\ -1 & 3 & -1 \end{pmatrix} = A$$
    Khớp chính xác 100%!

- **b. Phân loại biến thể:**
  Phân rã LU thuộc biến thể **Thay đổi biểu diễn (Representation Change)**, vì ta giữ nguyên thể hiện toán học của ma trận $A$ nhưng biểu diễn nó dưới dạng tích của hai ma trận đặc biệt $L$ và $U$ để các phép toán giải hệ phương trình sau đó trở nên cực kỳ nhanh chóng ($\Theta(n^2)$ thay vì $\Theta(n^3)$).

---

### Bài 6.2.3: Tìm ma trận nghịch đảo $A^{-1}$ bằng Phân rã LU
> **Đề bài:**
> Tìm ma trận nghịch đảo $A^{-1}$ của ma trận $A$ trong Bài 2 bằng cách sử dụng phân rã $A = LU$.

**Lời giải chi tiết:**
- Ma trận nghịch đảo $X = A^{-1} = [x^{(1)} | x^{(2)} | x^{(3)}]$ thỏa mãn $A X = I_3$, tương đương giải 3 hệ phương trình:
  $$A x^{(1)} = e_1 = \begin{pmatrix} 1 \\ 0 \\ 0 \end{pmatrix}, \quad A x^{(2)} = e_2 = \begin{pmatrix} 0 \\ 1 \\ 0 \end{pmatrix}, \quad A x^{(3)} = e_3 = \begin{pmatrix} 0 \\ 0 \\ 1 \end{pmatrix}$$
  Với mỗi $k \in \{1, 2, 3\}$, giải $L y^{(k)} = e_k$ rồi giải $U x^{(k)} = y^{(k)}$.

1. **Cột 1: Giải với $e_1 = (1, 0, 0)^T$:**
   - $L y^{(1)} = e_1 \implies y_1 = 1$; $2(1) + y_2 = 0 \implies y_2 = -2$; $-1(1) - \frac{1}{7}(-2) + y_3 = 0 \implies y_3 = 1 - \frac{2}{7} = \frac{5}{7}$.
     Vậy $y^{(1)} = (1, -2, \frac{5}{7})^T$.
   - $U x^{(1)} = y^{(1)}$:
     $\frac{8}{7} x_3 = \frac{5}{7} \implies x_3 = \frac{5}{8}$.
     $7 x_2 + x_3 = -2 \implies 7 x_2 = -2 - \frac{5}{8} = -\frac{21}{8} \implies x_2 = -\frac{3}{8}$.
     $x_1 - 4 x_2 + 2 x_3 = 1 \implies x_1 = 1 + 4(-\frac{3}{8}) - 2(\frac{5}{8}) = 1 - \frac{12}{8} - \frac{10}{8} = 1 - \frac{22}{8} = -\frac{14}{8} = -\frac{7}{4}$.
     Vậy $x^{(1)} = (-\frac{7}{4}, -\frac{3}{8}, \frac{5}{8})^T = (-\frac{14}{8}, -\frac{3}{8}, \frac{5}{8})^T$.

2. **Cột 2: Giải với $e_2 = (0, 1, 0)^T$:**
   - $L y^{(2)} = e_2 \implies y_1 = 0$; $y_2 = 1$; $-\frac{1}{7}(1) + y_3 = 0 \implies y_3 = \frac{1}{7}$.
     Vậy $y^{(2)} = (0, 1, \frac{1}{7})^T$.
   - $U x^{(2)} = y^{(2)}$:
     $\frac{8}{7} x_3 = \frac{1}{7} \implies x_3 = \frac{1}{8}$.
     $7 x_2 + \frac{1}{8} = 1 \implies 7 x_2 = \frac{7}{8} \implies x_2 = \frac{1}{8}$.
     $x_1 - 4(\frac{1}{8}) + 2(\frac{1}{8}) = 0 \implies x_1 = \frac{2}{8} = \frac{1}{4}$.
     Vậy $x^{(2)} = (\frac{2}{8}, \frac{1}{8}, \frac{1}{8})^T$.

3. **Cột 3: Giải với $e_3 = (0, 0, 1)^T$:**
   - $L y^{(3)} = e_3 \implies y_1 = 0$; $y_2 = 0$; $y_3 = 1$.
     Vậy $y^{(3)} = (0, 0, 1)^T$.
   - $U x^{(3)} = y^{(3)}$:
     $\frac{8}{7} x_3 = 1 \implies x_3 = \frac{7}{8}$.
     $7 x_2 + \frac{7}{8} = 0 \implies 7 x_2 = -\frac{7}{8} \implies x_2 = -\frac{1}{8}$.
     $x_1 - 4(-\frac{1}{8}) + 2(\frac{7}{8}) = 0 \implies x_1 = -\frac{4}{8} - \frac{14}{8} = -\frac{18}{8} = -\frac{9}{4}$.
     Vậy $x^{(3)} = (-\frac{18}{8}, -\frac{1}{8}, \frac{7}{8})^T$.

- **Kết quả ma trận nghịch đảo:**
  $$A^{-1} = \frac{1}{8} \begin{pmatrix} -14 & 2 & -18 \\ -3 & 1 & -1 \\ 5 & 1 & 7 \end{pmatrix} = \begin{pmatrix} -1.75 & 0.25 & -2.25 \\ -0.375 & 0.125 & -0.125 \\ 0.625 & 0.125 & 0.875 \end{pmatrix}$$

---

### Bài 6.2.4: Lỗi sai trong chứng minh công thức số phép nhân của Khử Gauss
> **Đề bài:**
> Trong sách giáo trình, tổng số phép nhân trong thuật toán khử Gauss được tính bằng:
> $$M(n) = \sum_{i=1}^{n-1} \sum_{j=i+1}^n (n - i + 1)$$
> Có một cách lập luận cho rằng: "Vì mỗi bước khử một dòng cần $(n - i + 1)$ phép nhân và có $(n - i)$ dòng cần khử, nên tổng là $\sum_{i=1}^{n-1} (n - i)(n - i + 1)$".
> Hãy chỉ ra lỗi lập luận (nếu có) trong biến đổi tổng của công thức này.

**Lời giải chi tiết:**
- Công thức chính xác của số phép nhân chia trong giai đoạn khử xuôi:
  Tại bước $i$ ($i = 1, \dots, n-1$):
  - Ta cần tính tỷ số $temp = A[j, i] / A[i, i]$: tốn 1 phép chia.
  - Sau đó nhân $temp$ với các phần tử từ cột $i+1$ đến cột $n+1$: tốn $(n - i + 1)$ phép nhân.
  - Tổng số phép nhân và chia cho mỗi dòng $j$ là $1 + (n - i + 1) = n - i + 2$.
  - Số dòng cần khử là $n - i$.
  - Do đó tổng chính xác là:
    $$M(n) = \sum_{i=1}^{n-1} (n - i)(n - i + 2)$$
- Sự nhầm lẫn trong sách giáo trình thường xảy ra khi:
  - Bỏ quên phép chia tính tỷ số $temp$, chỉ tính các phép nhân trong vòng lặp trong.
  - Hoặc tính cả phần tử tại cột $i$ (dù biết trước phần tử đó sau khi trừ sẽ bằng 0, không cần thực hiện phép nhân).

---

### Bài 6.2.5: Thiết kế giải thuật Khử Gauss cho Hệ phương trình ba đường chéo (Tridiagonal Systems / Thomas Algorithm)
> **Đề bài:**
> Một ma trận $A$ kích thước $n \times n$ được gọi là ma trận ba đường chéo (tridiagonal matrix) nếu $a_{ij} = 0$ với mọi $|i - j| > 1$ (chỉ có đường chéo chính, đường chéo ngay phía trên và đường chéo ngay phía dưới chứa các phần tử khác 0).
> Thiết kế thuật toán Khử Gauss chuyên biệt hóa cho hệ ba đường chéo và phân tích độ phức tạp thời gian.

**Lời giải chi tiết:**
- **Khai thác cấu trúc đặc biệt:**
  - Ở bước $i$, dưới phần tử trục xoay $A[i, i]$ chỉ có **duy nhất 1 phần tử khác 0** ở dòng $i+1$ (là $A[i+1, i]$). Tất cả các dòng $i+2, \dots, n-1$ đều đã có giá trị 0 sẵn!
  - Khi lấy dòng $i+1$ trừ đi bội số của dòng $i$, dòng $i$ cũng chỉ có 2 phần tử khác 0: $A[i, i]$ và $A[i, i+1]$ (và phần tử tự do vế phải $b[i]$).
- **Mã giả Thuật toán Thomas (Tridiagonal Matrix Algorithm - TDMA):**
```text
function: SolveTridiagonal(a[1..n], b[1..n], c[1..n], d[1..n]): Array[1..n] of Real
    input: b[1..n]: main diagonal – đường chéo chính.
           a[2..n]: sub-diagonal – đường chéo dưới.
           c[1..n - 1]: super-diagonal – đường chéo trên.
           d[1..n]: right-hand side – vế phải.
    output: x[1..n]: solution vector.

 1  – Giai đoạn khử xuôi:
 2  for i = 2 to n do
 3      m = a[i] / b[i - 1]
 4      b[i] = b[i] - m * c[i - 1]
 5      d[i] = d[i] - m * d[i - 1]
 6  end-for
 7  – Giai đoạn thế ngược:
 8  x[n] = d[n] / b[n]
 9  for i = n - 1 downto 1 do
10      x[i] = (d[i] - c[i] * x[i + 1]) / b[i]
11  end-for
12  return x.
```
- **Độ phức tạp tính toán:**
  - Vòng khử xuôi chạy $n-1$ bước, mỗi bước tốn 1 phép chia, 2 phép nhân, 2 phép trừ $\implies 5(n-1)$ phép tính.
  - Vòng thế ngược chạy $n-1$ bước, mỗi bước tốn 1 phép nhân, 1 phép trừ, 1 phép chia $\implies 3(n-1) + 1$ phép tính.
  - **Tổng thời gian: $\Theta(n)$ (Tuyến tính tuyệt đối!)**, giảm ngoạn mục từ $\Theta(n^3)$ xuống $\Theta(n)$.

---

### Bài 6.2.6: Tính định thức của ma trận bằng Khử Gauss
> **Đề bài:**
> Giải thích cách tính định thức $\det(A)$ của ma trận vuông $A$ kích thước $n \times n$ bằng thuật toán Khử Gauss. So sánh hiệu quả thời gian của phương pháp này với định nghĩa khai triển Laplace (theo phần bù đại số).

**Lời giải chi tiết:**
1. **Phương pháp Khử Gauss:**
   - Sử dụng các phép biến đổi sơ cấp trên dòng để đưa $A$ về ma trận tam giác trên $U$:
     + Phép cộng bội số của một dòng vào dòng khác: Không làm thay đổi định thức.
     + Phép đổi chỗ hai dòng: Đổi dấu định thức ($\det$ nhân với $-1$).
   - Sau khi khử xuôi, nếu ta đã thực hiện $s$ lần đổi dòng:
     $$\det(A) = (-1)^s \cdot \det(U) = (-1)^s \prod_{i=1}^n u_{ii}$$
   - Độ phức tạp thời gian: Đúng bằng thời gian khử xuôi: $\Theta(n^3)$.

2. **So sánh với Khai triển Laplace (Khai triển theo dòng/cột):**
   - Theo định nghĩa khai triển Laplace:
     $$\det(A) = \sum_{j=1}^n (-1)^{1+j} a_{1j} M_{1j}$$
     Trong đó $M_{1j}$ là định thức cấp $n-1$.
   - Phương trình thời gian: $T(n) = n T(n-1) \implies T(n) \in \Theta(n!)$.
   - So sánh với $n = 30$:
     + Khử Gauss: $\approx \frac{1}{3} \times 30^3 = 9.000$ phép tính (thực hiện trong chưa đầy $0.00001$ giây).
     + Khai triển Laplace: $30! \approx 2.65 \times 10^{32}$ phép tính (mất hàng tỷ năm trên siêu máy tính).

---

### Bài 6.2.7: Điều kiện tồn tại nghiệm duy nhất của hệ phương trình
> **Đề bài:**
> Trong quá trình khử Gauss, dấu hiệu nào cho biết hệ phương trình:
> a. Có vô số nghiệm?
> b. Vô nghiệm?

**Lời giải chi tiết:**
Trong ma trận bậc thang tam giác trên sau khi khử xuôi:
- **a. Hệ có vô số nghiệm:**
  Xuất hiện ít nhất một dòng có toàn bộ hệ số bên trái đều bằng 0 và hệ số vế phải cũng bằng 0:
  $$[0, 0, \dots, 0 \mid 0]$$
  Phương trình này trở thành $0 \cdot x_1 + \dots + 0 \cdot x_n = 0$ (luôn thỏa mãn với mọi $x$). Khi đó hạng của ma trận hệ số $\text{rank}(A) = \text{rank}(\tilde{A}) < n$, các ẩn tương ứng được chọn làm ẩn tự do.
- **b. Hệ vô nghiệm:**
  Xuất hiện ít nhất một dòng có các hệ số bên trái đều bằng 0 nhưng hệ số vế phải khác 0:
  $$[0, 0, \dots, 0 \mid c] \quad (c \ne 0)$$
  Phương trình trở thành $0 \cdot x_1 + \dots + 0 \cdot x_n = c$ (vô lý). Khi đó $\text{rank}(A) < \text{rank}(\tilde{A})$, hệ hoàn toàn không có nghiệm.

---

### Bài 6.2.8: Khử Gauss trên vành số nguyên modulo $p$ ($GF(p)$)
> **Đề bài:**
> Liệu thuật toán Khử Gauss có thể áp dụng trực tiếp để giải hệ phương trình tuyến tính trên trường hữu hạn $\mathbb{Z}_p$ (với $p$ là số nguyên tố) hay không? Cần điều chỉnh thao tác nào trong thuật toán?

**Lời giải chi tiết:**
- **Trả lời: HOÀN TOÀN ĐƯỢC.**
- Vì $p$ là số nguyên tố, tập hợp $\mathbb{Z}_p = \{0, 1, \dots, p-1\}$ cùng với phép cộng và nhân modulo $p$ tạo thành một trường hữu hạn (Galois Field $GF(p)$). Trong trường này, mọi phần tử khác 0 đều có phần tử nghịch đảo nhân duy nhất.
- **Các điều chỉnh bắt buộc:**
  1. Mọi phép cộng, trừ, nhân đều được thực hiện theo $\pmod p$.
  2. Phép chia $\frac{a}{b}$ được thay thế bằng phép nhân với nghịch đảo modulo $p$:
     $$a / b \equiv a \cdot b^{-1} \pmod p$$
     Nghịch đảo $b^{-1} \pmod p$ được tìm nhanh chóng bằng thuật toán Euclid mở rộng (Extended Euclidean Algorithm) trong thời gian $O(\log p)$.
  3. Không áp dụng chọn phần tử trục xoay theo giá trị tuyệt đối thực; thay vào đó, chỉ cần chọn bất kỳ dòng nào có phần tử pivot khác 0 ($\not\equiv 0 \pmod p$).

---

### Bài 6.2.9: Phép khử Jordan (Gauss-Jordan Elimination)
> **Đề bài:**
> Thuật toán Gauss-Jordan biến đổi ma trận bổ sung không phải thành ma trận tam giác trên mà thành ma trận đường chéo (hoặc ma trận đơn vị).
> a. Mô tả tóm tắt thuật toán Gauss-Jordan.
> b. So sánh số phép nhân giữa Khử Gauss (kết hợp thế ngược) và Khử Gauss-Jordan.

**Lời giải chi tiết:**
- **a. Mô tả thuật toán Gauss-Jordan:**
  Tại mỗi bước $i$, sau khi chọn pivot $A[i, i]$:
  1. Chia toàn bộ dòng $i$ cho $A[i, i]$ để biến phần tử trên đường chéo thành 1.
  2. Khử tất cả các phần tử ở cột $i$ trong **cả các dòng bên dưới LẪN các dòng bên trên** về 0.
  3. Kết quả thu được trực tiếp ma trận đơn vị bên trái, và vế phải chính là vector nghiệm mà không cần bước thế ngược.
- **b. So sánh số phép nhân:**
  - Khử Gauss chuẩn + thế ngược:
    $$M_{\text{Gauss}}(n) \approx \frac{1}{3} n^3 + \frac{1}{2} n^2 \in \Theta(n^3)$$
  - Khử Gauss-Jordan:
    Tại mỗi bước $i$, khử ở cả $n-1$ dòng còn lại, mỗi dòng nhân $n - i + 1$ phần tử:
    $$M_{\text{Jordan}}(n) \approx \sum_{i=1}^n (n - 1)(n - i + 1) \approx \frac{1}{2} n^3 \in \Theta(n^3)$$
  - Tỷ số:
    $$\frac{M_{\text{Jordan}}(n)}{M_{\text{Gauss}}(n)} \approx \frac{\frac{1}{2} n^3}{\frac{1}{3} n^3} = \frac{3}{2} = 1.5$$
  - **Kết luận:** Khử Gauss-Jordan tốn nhiều hơn khoảng **50% số phép nhân** so với Khử Gauss kết hợp thế ngược. Do đó, Khử Gauss chuẩn hiệu quả hơn khi giải hệ phương trình.

---

### Bài 6.2.10: Biến đổi hệ phương trình để giải phương pháp ma trận khối
> **Đề bài:**
> Cho ma trận khối kích thước $2n \times 2n$:
> $$M = \begin{pmatrix} A & B \\ C & D \end{pmatrix}$$
> Trong đó $A, B, C, D$ là các ma trận khối vuông $n \times n$ và $A$ khả nghịch.
> Áp dụng tư tưởng khử Gauss để biểu diễn phân rã khối của ma trận này.

**Lời giải chi tiết:**
- Nhân ma trận khối với ma trận khử khối từ bên trái:
  $$\begin{pmatrix} I & 0 \\ -C A^{-1} & I \end{pmatrix} \begin{pmatrix} A & B \\ C & D \end{pmatrix} = \begin{pmatrix} A & B \\ 0 & D - C A^{-1} B \end{pmatrix}$$
- Ma trận $S = D - C A^{-1} B$ được gọi là **Bổ sung Schur (Schur Complement)** của khối $A$.
- Từ đây ta có phân rã khối:
  $$\begin{pmatrix} A & B \\ C & D \end{pmatrix} = \begin{pmatrix} I & 0 \\ C A^{-1} & I \end{pmatrix} \begin{pmatrix} A & 0 \\ 0 & D - C A^{-1} B \end{pmatrix} \begin{pmatrix} I & A^{-1} B \\ 0 & I \end{pmatrix}$$
- Định thức của ma trận khối:
  $$\det(M) = \det(A) \cdot \det(D - C A^{-1} B)$$

---

### Bài 6.2.11: Độ phức tạp tính toán của Nghịch đảo ma trận
> **Đề bài:**
> Chứng minh rằng việc tìm ma trận nghịch đảo $A^{-1}$ của một ma trận vuông cấp $n$ bằng thuật toán phân rã LU tốn đúng:
> $$M(n) = n^3 \text{ phép nhân}$$

**Lời giải chi tiết:**
1. **Phân rã $A = LU$:**
   Tốn $\frac{1}{3} n^3$ phép nhân.
2. **Giải $n$ hệ phương trình $L y^{(k)} = e_k$ và $U x^{(k)} = y^{(k)}$:**
   - Với vector cột $e_k$, vì $k-1$ phần tử đầu tiên của $e_k$ bằng 0, nên $y_1 = \dots = y_{k-1} = 0$.
   - Do đó, giải $L y^{(k)} = e_k$ chỉ tốn: $\sum_{i=k}^n (i - k) = \frac{(n-k)(n-k+1)}{2}$ phép nhân.
   - Lấy tổng trên cả $n$ cột:
     $$\sum_{k=1}^n \frac{(n-k)(n-k+1)}{2} = \frac{1}{6} n(n^2 - 1) \approx \frac{1}{6} n^3$$
   - Giải tiếp $n$ hệ tam giác trên $U x^{(k)} = y^{(k)}$: mỗi hệ tốn $\frac{1}{2} n^2$ phép nhân, trên $n$ hệ tốn $n \times \frac{1}{2} n^2 = \frac{1}{2} n^3$ phép nhân.
3. **Tổng số phép nhân:**
   $$M(n) = \frac{1}{3} n^3 + \frac{1}{6} n^3 + \frac{1}{2} n^3 = \left(\frac{1}{3} + \frac{1}{6} + \frac{1}{2}\right) n^3 = 1 \cdot n^3$$
   Đúng chính xác $n^3$ phép nhân! (Điều phải chứng minh).

---

### Bài 6.2.12: Giải hệ phương trình phi tuyến tính bằng Phương pháp Newton-Raphson kết hợp Khử Gauss
> **Đề bài:**
> Trình bày cách kết hợp phương pháp lặp Newton-Raphson nhiều chiều với thuật toán Khử Gauss để tìm nghiệm xấp xỉ của hệ phương trình phi tuyến tính:
> $$\begin{cases} f_1(x_1, x_2, \dots, x_n) = 0 \\ f_2(x_1, x_2, \dots, x_n) = 0 \\ \dots \\ f_n(x_1, x_2, \dots, x_n) = 0 \end{cases}$$

**Lời giải chi tiết:**
- **Nguyên lý:** Tuyến tính hóa hệ phi tuyến tại điểm lặp thứ $k$ bằng chuỗi Taylor cấp 1:
  $$F(x^{(k)} + \Delta x) \approx F(x^{(k)}) + J(x^{(k)}) \Delta x = 0$$
  Trong đó $J(x^{(k)})$ là **Ma trận Jacobi** kích thước $n \times n$:
  $$J_{ij} = \frac{\partial f_i}{\partial x_j} (x^{(k)})$$
- **Quy trình lặp Newton-Raphson nhiều chiều:**
  1. Chọn nghiệm khởi tạo $x^{(0)}$.
  2. Tại mỗi bước lặp $k = 0, 1, 2, \dots$:
     - Tính ma trận Jacobi $J_k = J(x^{(k)})$ và vector phần dư $F_k = F(x^{(k)})$.
     - Giải hệ phương trình đại số tuyến tính:
       $$J_k \cdot \Delta x = -F_k$$
       bằng thuật toán **Khử Gauss (hoặc Phân rã LU)** tốn $\Theta(n^3)$.
     - Cập nhật điểm lặp mới:
       $$x^{(k+1)} = x^{(k)} + \Delta x$$
     - Kiểm tra điều kiện dừng: Nếu $\|\Delta x\| < \epsilon$ hoặc $\|F_k\| < \epsilon$ thì dừng lại và trả về $x^{(k+1)}$.
- **Độ phức tạp:** Mỗi bước lặp tốn $\Theta(n^3)$ cho phép khử Gauss, nhưng tốc độ hội tụ đạt bậc hai (Quadratic Convergence) gần nghiệm, thường chỉ cần từ 4 đến 6 bước lặp để đạt độ chính xác máy.
