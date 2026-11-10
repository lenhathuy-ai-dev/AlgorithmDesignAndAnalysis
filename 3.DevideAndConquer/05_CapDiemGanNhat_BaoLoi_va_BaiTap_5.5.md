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
