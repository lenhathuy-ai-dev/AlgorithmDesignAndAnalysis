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
