# CHUYÊN ĐỀ 06: THU GỌN BÀI TOÁN (PROBLEM REDUCTION) & LỜI GIẢI BÀI TẬP 6.6
*Tài liệu tham chiếu: A. Levitin, "Introduction to the Design and Analysis of Algorithms", 3rd Edition, Chương 6, Mục 6.6, Trang 244–252.*

---

## PHẦN I. LÝ THUYẾT VÀ MÃ GIẢ CHUẨN HÓA

### 6.1. Bản chất Chiến lược Thu gọn bài toán (Problem Reduction)
Thu gọn bài toán (Problem Reduction) là biến thể thứ ba của chiến lược Biến đổi để trị:
- Thay vì thay đổi thể hiện hoặc thay đổi cấu trúc dữ liệu của cùng một bài toán, ta **chuyển đổi hoàn toàn bài toán $P$ cần giải thành một bài toán $Q$ khác** mà thuật toán giải hiệu quả cho $Q$ đã được biết trước.
- **Sơ đồ thu gọn:**
  1. Biến đổi thể hiện $I_P$ của bài toán $P$ thành thể hiện $I_Q$ của bài toán $Q$.
  2. Áp dụng thuật toán đã biết để giải $I_Q$, thu được nghiệm $S_Q$.
  3. Ánh xạ ngược nghiệm $S_Q$ về nghiệm $S_P$ của bài toán gốc $P$.

```
           Thể hiện ban đầu IP ───────── Biến đổi (Transform) ─────────> Thể hiện IQ
                  │                                                              │
                  │                                                              │ Thuật toán
                  │ Nghiệm cần tìm                                               │ giải Q
                  ▼                                                              ▼
             Nghiệm SP <────────── Ánh xạ ngược (Map back) <──────────── Nghiệm SQ
```

---

### 6.2. Các ứng dụng kinh điển của Thu gọn bài toán

#### 1. Tính Bội chung nhỏ nhất qua Ước chung lớn nhất (LCM via GCD)
- Để tìm $\text{lcm}(m, n)$, ta không cần phân tích ra thừa số nguyên tố:
  $$\text{lcm}(m, n) = \frac{m \cdot n}{\gcd(m, n)}$$
  Thu gọn bài toán tính BCNN về bài toán tìm UCLN giải bằng Thuật toán Euclid trong thời gian $O(\log(\min(m, n)))$!

#### 2. Đếm số đường đi trong đồ thị qua Nhân lũy thừa Ma trận kề
- **Định lý:** Cho đồ thị $G = (V, E)$ có ma trận kề $A$. Phần tử tại hàng $i$, cột $j$ của ma trận lũy thừa $A^k$ (ký hiệu $A^k[i, j]$) bằng **chính xác số lượng đường đi có độ dài $k$** từ đỉnh $i$ đến đỉnh $j$ trong đồ thị $G$!
- Thu gọn bài toán đếm đường đi đồ thị về bài toán tính lũy thừa ma trận nhị phân trong thời gian $O(|V|^3 \log k)$.

#### 3. Thu gọn về Quy hoạch tuyến tính (Linear Programming - LP)
Nhiều bài toán tối ưu hóa tổ hợp quan trọng có thể được phát biểu dưới dạng bài toán Quy hoạch tuyến tính:
- Tìm vector $x \in \mathbb{R}^n$ cực đại hóa hàm mục tiêu: $c^T x$.
- Thỏa mãn các ràng buộc tuyến tính: $A x \le b$ và $x \ge 0$.
- Các bài toán như **Luồng cực đại trong mạng (Maximum Flow)**, **Cặp ghép cực đại trên đồ thị hai phía (Maximum Bipartite Matching)**, **Đường đi ngắn nhất (Shortest Path)** đều có thể thu gọn về LP và giải bằng thuật toán Simplex hoặc các thuật toán điểm trong (Interior Point Methods).

#### 4. Bài toán qua sông (River Crossing Puzzles) thu gọn về Đường đi ngắn nhất
- Các câu đố kinh điển như "Sói, Cừu và Bắp cải qua sông" hoặc "Các nhà truyền giáo và kẻ ăn thịt người" được thu gọn thành bài toán tìm đường đi ngắn nhất từ trạng thái bắt đầu $S_0$ đến trạng thái đích $S_{\text{goal}}$ trên đồ thị không gian trạng thái (State-space Graph) bằng thuật toán BFS!

---

## PHẦN II. GIẢI CHI TIẾT 100% BÀI TẬP EXERCISES 6.6 (BÀI 1 ĐẾN BÀI 12)

### Bài 6.6.1: Mối liên hệ giữa BCNN và UCLN
> **Đề bài:**
> a. Chứng minh rằng với hai số nguyên dương $m$ và $n$:
> $$\text{lcm}(m, n) \cdot \gcd(m, n) = m \cdot n$$
> b. Từ đó thiết kế thuật toán hiệu quả nhất để tìm BCNN của hai số nguyên dương.

**Lời giải chi tiết:**
- **a. Chứng minh qua phân tích thừa số nguyên tố (Định lý cơ bản của số học):**
  - Giả sử $m$ và $n$ được phân tích thành tích các số nguyên tố:
    $$m = p_1^{\alpha_1} p_2^{\alpha_2} \dots p_k^{\alpha_k}, \quad n = p_1^{\beta_1} p_2^{\beta_2} \dots p_k^{\beta_k} \quad (\alpha_i, \beta_i \ge 0)$$
  - Theo định nghĩa:
    $$\gcd(m, n) = p_1^{\min(\alpha_1, \beta_1)} \dots p_k^{\min(\alpha_k, \beta_k)}$$
    $$\text{lcm}(m, n) = p_1^{\max(\alpha_1, \beta_1)} \dots p_k^{\max(\alpha_k, \beta_k)}$$
  - Nhân hai biểu thức với nhau:
    $$\text{lcm}(m, n) \cdot \gcd(m, n) = \prod_{i=1}^k p_i^{\max(\alpha_i, \beta_i) + \min(\alpha_i, \beta_i)}$$
  - Với hai số thực bất kỳ, ta luôn có đẳng thức: $\max(a, b) + \min(a, b) = a + b$. Do đó:
    $$\max(\alpha_i, \beta_i) + \min(\alpha_i, \beta_i) = \alpha_i + \beta_i$$
    $$\implies \text{lcm}(m, n) \cdot \gcd(m, n) = \prod_{i=1}^k p_i^{\alpha_i + \beta_i} = \left(\prod_{i=1}^k p_i^{\alpha_i}\right) \left(\prod_{i=1}^k p_i^{\beta_i}\right) = m \cdot n$$
    (Điều phải chứng minh).

- **b. Thiết kế thuật toán tính $\text{lcm}(m, n)$ tối ưu:**
```text
function: LCM(m, n): Integer
    input: m, n: positive integers.
    output: lcm: positive integer – bội chung nhỏ nhất.

 1  g = EuclidGCD(m, n) – tính UCLN bằng thuật toán Euclid trong O(log(min(m, n))).
 2  return (m / g) * n – chia trước để tránh tràn số nguyên.
```
- **Độ phức tạp thời gian:** $O(\log(\min(m, n)))$.

---

### Bài 6.6.2: Thu gọn bài toán Cực tiểu hóa về Cực đại hóa
> **Đề bài:**
> Giải thích cách thu gọn một bài toán tối ưu hóa cực tiểu hóa (Minimization):
> $$\min_{x \in S} f(x)$$
> về một bài toán cực đại hóa (Maximization).

**Lời giải chi tiết:**
- **Nguyên lý đối ngẫu đổi dấu:**
  $$\min_{x \in S} f(x) = - \max_{x \in S} (-f(x))$$
- **Quy trình thu gọn:**
  1. Đặt hàm mục tiêu mới $g(x) = -f(x)$.
  2. Áp dụng thuật toán cực đại hóa để tìm nghiệm $x^* = \arg\max_{x \in S} g(x)$.
  3. Điểm tối ưu $x^*$ của bài toán cực đại hóa chính là điểm tối ưu của bài toán cực tiểu hóa ban đầu. Giá trị cực tiểu bằng $-g(x^*)$.

---

### Bài 6.6.3: Chứng minh Định lý số đường đi bằng Quy nạp toán học
> **Đề bài:**
> Chứng minh bằng quy nạp toán học theo $k$ rằng: Nếu $A$ là ma trận kề của đồ thị $G$, thì phần tử $A^k[i, j]$ chính là số lượng đường đi có độ dài $k$ từ đỉnh $i$ đến đỉnh $j$.

**Lời giải chi tiết:**
- **Cơ sở quy nạp ($k = 1$):**
  - $A^1 = A$. Theo định nghĩa ma trận kề, $A[i, j] = 1$ nếu có cạnh nối trực tiếp từ $i$ đến $j$ (đường đi độ dài 1), và bằng 0 nếu không có cạnh. Mệnh đề đúng với $k = 1$.
- **Bước quy nạp:**
  - Giả sử mệnh đề đúng với $k \ge 1$, tức là $A^k[i, m]$ là số đường đi độ dài $k$ từ $i$ đến $m$ với mọi cặp đỉnh $(i, m)$.
  - Xét $A^{k+1} = A^k \cdot A$. Theo định nghĩa phép nhân ma trận:
    $$A^{k+1}[i, j] = \sum_{m=1}^n A^k[i, m] \cdot A[m, j]$$
  - Bất kỳ đường đi độ dài $k+1$ nào từ $i$ đến $j$ đều bao gồm: một đường đi độ dài $k$ từ $i$ đến một đỉnh trung gian $m$, sau đó đi qua cạnh $(m, j)$ (độ dài 1) để tới $j$.
  - Theo quy tắc cộng và quy tắc nhân tổ hợp, tổng số đường đi độ dài $k+1$ từ $i$ đến $j$ chính là tổng trên tất cả các đỉnh trung gian $m$ khả dĩ: $\sum_{m=1}^n A^k[i, m] \cdot A[m, j]$.
  - Giá trị này đúng bằng phần tử tại dòng $i$, cột $j$ của ma trận tích $A^{k+1}$.
- **Kết luận:** Mệnh đề đúng với mọi số nguyên dương $k$.

---

### Bài 6.6.4: Phát hiện chu trình độ dài 3 (Tam giác) trong đồ thị
> **Đề bài:**
> a. Thiết kế thuật toán phát hiện xem đồ thị vô hướng $G$ có chứa chu trình độ dài 3 (tam giác) hay không bằng cách thu gọn về phép nhân ma trận.
> b. Phân tích độ phức tạp thời gian của thuật toán.

**Lời giải chi tiết:**
- **a. Thiết kế thuật toán:**
  - **Nhận xét cốt lõi:** Đồ thị $G$ chứa tam giác $\{i, j, k\}$ khi và chỉ khi tồn tại hai đỉnh $i, j$ kề nhau (tức là $A[i, j] = 1$) và đồng thời có ít nhất một đường đi độ dài 2 giữa $i$ và $j$ (tức là $A^2[i, j] > 0$).
  - Hoặc tương đương: Chu trình độ dài 3 xuất hiện khi và chỉ khi đường chéo chính của ma trận $A^3$ có phần tử khác 0! Thật vậy:
    $$\text{Tr}(A^3) = \sum_{i=1}^n A^3[i, i] = 6 \times (\text{Số tam giác trong } G)$$
    *(Mỗi tam giác được đếm 6 lần do có 3 đỉnh xuất phát và 2 chiều đi).*
  - **Thuật toán:**
    1. Tính ma trận $A^2 = A \times A$.
    2. Quét qua tất cả các cạnh $(i, j) \in E$ (với $i < j$):
       - Nếu $A[i, j] == 1$ và $A^2[i, j] > 0$: Đồ thị chứa chu trình độ dài 3 $\implies$ Trả về `true`.
    3. Nếu duyệt hết mà không thỏa mãn: Trả về `false`.
- **b. Độ phức tạp:**
  - Tính $A^2$: Tốn $\Theta(n^3)$ bằng nhân ma trận chuẩn, hoặc $O(n^{2.807})$ bằng thuật toán Strassen.
  - Quét kiểm tra các cạnh: Tốn $O(n^2)$.
  - Tổng thời gian: Bằng đúng thời gian nhân hai ma trận: $O(n^{2.807})$.

---

### Bài 6.6.5: Thu gọn bài toán Bao lồi sang Bài toán Cặp điểm xa nhất
> **Đề bài:**
> Giải thích cách thu gọn bài toán tìm cặp điểm có khoảng cách lớn nhất trong tập hợp $n$ điểm trên mặt phẳng (Farthest-Pair Problem) về bài toán Bao lồi (Convex Hull).

**Lời giải chi tiết:**
- **Định lý hình học:** Cặp điểm xa nhất trong một tập hợp điểm $S$ **bắt buộc phải là hai đỉnh của Bao lồi $\text{Conv}(S)$**!
- **Quy trình thu gọn:**
  1. Áp dụng thuật toán dựng bao lồi (như Quickhull hoặc Graham's scan) để tìm tập các đỉnh của bao lồi $H = \text{Conv}(S)$ gồm $h$ đỉnh ($h \le n$) trong thời gian $O(n \log n)$.
  2. Tìm cặp điểm xa nhất trên tập $H$:
     - Dùng thuật toán "Cặp ngàm quay" (Rotating Calipers của Shamos) quét qua các đỉnh đối đường kính của đa giác lồi $H$ chỉ tốn thời gian tuyến tính $O(h)$.
  3. Cặp điểm xa nhất của bao lồi chính là cặp điểm xa nhất của toàn bộ tập điểm $S$ ban đầu.
- **Tổng thời gian:** $O(n \log n) + O(h) = O(n \log n)$, nhanh hơn rất nhiều so với vét cạn $\Theta(n^2)$.

---

### Bài 6.6.6: Thu gọn bài toán Tối ưu hóa Diện tích sang Giải tích một biến
> **Đề bài:**
> Trong tất cả các hình chữ nhật có chu vi cố định $2P$, hình chữ nhật nào có diện tích lớn nhất? Hãy giải bài toán này bằng cách thu gọn về bài toán tìm cực trị của hàm số một biến.

**Lời giải chi tiết:**
- Gọi chiều rộng hình chữ nhật là $x$ ($0 < x < P$). Khi đó chiều dài là $y = P - x$.
- Diện tích hình chữ nhật:
  $$S(x) = x \cdot y = x (P - x) = P x - x^2$$
- Thu gọn về tìm cực đại của hàm số bậc hai $f(x) = -x^2 + P x$:
  - Đạo hàm: $f'(x) = P - 2x$.
  - Cho $f'(x) = 0 \implies x = \frac{P}{2}$.
  - Đạo hàm cấp hai: $f''(x) = -2 < 0 \implies$ Hàm đạt cực đại tuyệt đối tại $x = P/2$.
- Khi đó chiều dài $y = P - P/2 = P/2 = x$.
- **Kết luận:** Hình chữ nhật có diện tích lớn nhất là **Hình vuông** cạnh $P/2$, với diện tích cực đại $S_{\max} = \frac{P^2}{4}$.

---

### Bài 6.6.7: Thu gọn Bài toán Phân việc (Assignment Problem) về Quy hoạch Tuyến tính
> **Đề bài:**
> Biểu diễn bài toán phân việc $n$ người cho $n$ công việc với ma trận chi phí $C = [c_{ij}]_{n \times n}$ dưới dạng bài toán Quy hoạch nguyên tuyến tính (Integer Linear Programming).

**Lời giải chi tiết:**
- Đặt các biến quyết định nhị phân:
  $$x_{ij} = \begin{cases} 1 & \text{nếu người } i \text{ được phân việc } j \\ 0 & \text{ngược lại} \end{cases}$$
- **Hàm mục tiêu:** Cực tiểu hóa tổng chi phí:
  $$\min \sum_{i=1}^n \sum_{j=1}^n c_{ij} x_{ij}$$
- **Các ràng buộc:**
  1. Mỗi người $i$ được phân đúng 1 việc:
     $$\sum_{j=1}^n x_{ij} = 1 \quad \forall i = 1, \dots, n$$
  2. Mỗi việc $j$ được giao cho đúng 1 người:
     $$\sum_{i=1}^n x_{ij} = 1 \quad \forall j = 1, \dots, n$$
  3. Ràng buộc nhị phân: $x_{ij} \in \{0, 1\}$.
*(Nhờ tính chất hoàn toàn đơn mô-đun (Totally Unimodular) của ma trận ràng buộc, ta có thể thả lỏng điều kiện nguyên thành $0 \le x_{ij} \le 1$ và giải bằng thuật toán Simplex hoặc Thuật toán Hungary trong $\Theta(n^3)$).*

---

### Bài 6.6.8: Thu gọn hệ phương trình đối xứng
> **Đề bài:**
> Giải hệ phương trình:
> $$\begin{cases} x + y + z = 6 \\ x y + y z + z x = 11 \\ x y z = 6 \end{cases}$$
> bằng cách thu gọn về bài toán giải phương trình đa thức bậc ba.

**Lời giải chi tiết:**
- Theo **Định lý Viète cho phương trình bậc ba**: Các số $x, y, z$ là ba nghiệm của phương trình bậc ba ẩn $t$:
  $$t^3 - e_1 t^2 + e_2 t - e_3 = 0$$
  Trong đó:
  $e_1 = x + y + z = 6$
  $e_2 = x y + y z + z x = 11$
  $e_3 = x y z = 6$
- Thay số vào phương trình:
  $$t^3 - 6 t^2 + 11 t - 6 = 0$$
- Phân tích đa thức thành nhân tử:
  $$(t - 1)(t - 2)(t - 3) = 0$$
  Phương trình có 3 nghiệm phân biệt: $t_1 = 1, t_2 = 2, t_3 = 3$.
- **Kết luận:** Bộ nghiệm $(x, y, z)$ của hệ phương trình chính là tất cả $3! = 6$ hoán vị của bộ ba số $(1, 2, 3)$:
  $$(x, y, z) \in \{(1, 2, 3), (1, 3, 2), (2, 1, 3), (2, 3, 1), (3, 1, 2), (3, 2, 1)\}$$

---

### Bài 6.6.9: Thu gọn bài toán Đường đi dài nhất sang Đường đi ngắn nhất
> **Đề bài:**
> Có thể thu gọn bài toán tìm đường đi dài nhất (Longest Path) trong đồ thị có hướng không chu trình (DAG) về bài toán tìm đường đi ngắn nhất (Shortest Path) bằng cách nào?

**Lời giải chi tiết:**
- Trong đồ thị có hướng không chu trình (DAG):
  1. Với mỗi cạnh $(u, v)$ có trọng số $w(u, v)$, ta đổi dấu trọng số cạnh thành $-w(u, v)$.
  2. Áp dụng thuật toán tìm đường đi ngắn nhất trên DAG (sử dụng sắp xếp tô-pô tốn $O(|V| + |E|)$).
  3. Đường đi ngắn nhất trên đồ thị có trọng số đối chính là đường đi dài nhất trên đồ thị ban đầu!
  *(Lưu ý: Phép thu gọn này chỉ hợp lệ trên DAG vì không có chu trình. Trên đồ thị có chu trình, việc đổi dấu sẽ tạo ra chu trình âm, khiến bài toán trở thành NP-khó).*

---

### Bài 6.6.10: Bài toán đặt Bưu điện trong không gian đa chiều (Post Office Location Problem)
> **Đề bài:**
> Cho $n$ ngôi nhà có tọa độ $(x_i, y_i)$ trên mặt phẳng. Cần tìm tọa độ đặt một bưu điện $(x^*, y^*)$ sao cho tổng khoảng cách Manhattan đến tất cả các ngôi nhà đạt cực tiểu:
> $$\min \sum_{i=1}^n (|x^* - x_i| + |y^* - y_i|)$$
> Hãy thu gọn bài toán này về bài toán một chiều đã biết.

**Lời giải chi tiết:**
- Khai triển hàm mục tiêu:
  $$\sum_{i=1}^n (|x^* - x_i| + |y^* - y_i|) = \sum_{i=1}^n |x^* - x_i| + \sum_{i=1}^n |y^* - y_i|$$
- Vì biến $x^*$ và biến $y^*$ hoàn toàn độc lập với nhau, bài toán hai chiều được phân rã thành **hai bài toán một chiều hoàn toàn riêng biệt**:
  $$\min_{x^*} \sum_{i=1}^n |x^* - x_i| \quad \text{và} \quad \min_{y^*} \sum_{i=1}^n |y^* - y_i|$$
- Ở bài toán một chiều (đã giải ở Bài tập 3.3.3), giá trị cực tiểu đạt được khi và chỉ khi điểm đặt là **Trung vị (Median)** của tập tọa độ!
- **Thuật toán:**
  1. $x^*$ là trung vị của dãy hoành độ $\{x_1, \dots, x_n\}$.
  2. $y^*$ là trung vị của dãy tung độ $\{y_1, \dots, y_n\}$.
- Tìm trung vị bằng thuật toán Quickselect chỉ tốn thời gian tuyến tính $\Theta(n)$!

---

### Bài 6.6.11: Câu đố Sói, Cừu và Bắp cải qua sông (River Crossing Puzzle)
> **Đề bài:**
> Một người nông dân cần chở một con sói, một con cừu và một bắp cải qua sông bằng một chiếc thuyền nhỏ chỉ chở được người nông dân và một trong ba thứ.
> Nếu không có người nông dân: Sói sẽ ăn thịt cừu, cừu sẽ ăn bắp cải.
> Hãy mô hình hóa câu đố bằng đồ thị không gian trạng thái và tìm chuỗi hành động ngắn nhất bằng thuật toán BFS.

**Lời giải chi tiết:**
- **Không gian trạng thái:** Biểu diễn vị trí của 4 đối tượng (Người, Sói, Cừu, Bắp cải) ở bờ xuất phát bằng bộ 4 bit nhị phân $(N, S, C, B) \in \{0, 1\}^4$ (1 là ở bờ gốc, 0 là đã qua sông).
  - Trạng thái xuất phát: $(1, 1, 1, 1)$. Trạng thái đích: $(0, 0, 0, 0)$.
  - Trạng thái nguy hiểm (bị cấm): Khi người ở bờ khác ($N \ne C$) và ($C == S$ hoặc $C == B$).
- **Đồ thị trạng thái an toàn:**
  Chỉ có 10 trạng thái hợp lệ trên toàn bộ bài toán.
- **Áp dụng BFS tìm đường đi ngắn nhất:**
  1. Bước 1: Người chở Cừu sang $\implies (0, 1, 0, 1)$.
  2. Bước 2: Người chèo thuyền không quay về $\implies (1, 1, 0, 1)$.
  3. Bước 3: Người chở Sói sang $\implies (0, 0, 0, 1)$.
  4. Bước 4: Người mang Cừu quay về bờ cũ $\implies (1, 0, 1, 1)$.
  5. Bước 5: Người chở Bắp cải sang $\implies (0, 0, 1, 0)$.
  6. Bước 6: Người chèo thuyền không quay về $\implies (1, 0, 1, 0)$.
  7. Bước 7: Người chở Cừu sang $\implies (0, 0, 0, 0)$ $\implies$ **Hoàn thành!**
- **Kết luận:** Đúng 7 chuyến thuyền qua sông, tìm được bằng thuật toán BFS trên đồ thị trạng thái thu gọn.

---

### Bài 6.6.12: Thu gọn bài toán Tìm chu trình Hamilton về Bài toán Người du lịch (TSP)
> **Đề bài:**
> Chứng minh rằng bài toán kiểm tra xem đồ thị vô hướng $G = (V, E)$ có chứa Chu trình Hamilton hay không có thể thu gọn trong thời gian đa thức về Bài toán Người du lịch (TSP).

**Lời giải chi tiết:**
- **Quy trình thu gọn:**
  1. Cho đồ thị $G = (V, E)$ gồm $n$ đỉnh.
  2. Xây dựng một đồ thị đầy đủ có trọng số $G' = (V, E')$ với $n$ đỉnh của $G$. Trọng số của mỗi cạnh $(u, v)$ trong $G'$ được gán như sau:
     $$w(u, v) = \begin{cases} 1 & \text{nếu } (u, v) \in E \text{ (cạnh thuộc đồ thị gốc)} \\ 2 & \text{nếu } (u, v) \notin E \text{ (cạnh không thuộc đồ thị gốc)} \end{cases}$$
  3. Áp dụng thuật toán giải bài toán TSP trên đồ thị $G'$ để tìm chu trình có tổng trọng số nhỏ nhất $C^*$.
- **Chứng minh tính tương đương:**
  - Nếu đồ thị gốc $G$ có chu trình Hamilton: Chu trình này đi qua $n$ đỉnh bằng $n$ cạnh đều thuộc $E$, do đó mỗi cạnh có trọng số 1 $\implies$ Chi phí TSP bằng đúng $n \times 1 = n$.
  - Nếu đồ thị gốc $G$ không có chu trình Hamilton: Mọi chu trình đi qua $n$ đỉnh bắt buộc phải dùng ít nhất một cạnh có trọng số 2 $\implies$ Chi phí TSP sẽ $\ge (n - 1) \times 1 + 2 = n + 1 > n$.
- **Kết luận:** Đồ thị $G$ có chu trình Hamilton khi và chỉ khi nghiệm của bài toán TSP trên $G'$ có giá trị bằng đúng $n$. Phép biến đổi ma trận trọng số chỉ tốn $\Theta(n^2)$ thời gian đa thức.
