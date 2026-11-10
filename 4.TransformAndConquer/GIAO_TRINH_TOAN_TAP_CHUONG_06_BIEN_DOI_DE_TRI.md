# GIÁO TRÌNH TOÀN TẬP PHÂN TÍCH VÀ THIẾT KẾ THUẬT TOÁN

## CHƯƠNG 6: CHIẾN LƯỢC BIẾN ĐỔI ĐỂ TRỊ (TRANSFORM-AND-CONQUER)

> **Tài liệu học thuật chuẩn hóa:**
> - Tác giả giáo trình: Anany Levitin, Introduction to the Design and Analysis of Algorithms (3rd Edition, Addison-Wesley, 2011).
> - Định dạng mã giả: Chuẩn hóa khối (boxed structure) với `function:`, `input:`, `output:`, đánh số dòng và từ khóa đóng tường minh.
> - Định dạng toán học: 100% công thức toán học Word Equation (OMML) & LaTeX chuẩn hóa.
> - Phạm vi nội dung: Toàn bộ lý thuyết, 8 thuật toán kinh điển và lời giải chi tiết 100% của toàn bộ 66 bài tập từ Mục 6.1 đến 6.6 (Trang 201–252).

---


# CHƯƠNG 6: CHIẾN LƯỢC BIẾN ĐỔI ĐỂ TRỊ (TRANSFORM-AND-CONQUER)
*Tài liệu tham chiếu chuẩn hóa: A. Levitin, "Introduction to the Design and Analysis of Algorithms", 3rd Edition, Chương 6, Trang 201–252.*

---

# CHUYÊN ĐỀ 00: TỔNG QUAN CHIẾN LƯỢC BIẾN ĐỔI ĐỂ TRỊ (TRANSFORM-AND-CONQUER)

## 1. TRIẾT LÝ VÀ BẢN CHẤT CỐT LÕI
Chiến lược **Biến đổi để trị (Transform-and-Conquer)** là một họ các phương pháp thiết kế thuật toán hoạt động dựa trên nguyên lý hai bước:
1. **Giai đoạn Biến đổi (Transformation Stage):** Chuyển đổi thể hiện bài toán ban đầu thành một thể hiện khác:
   - Dễ giải quyết hơn (more convenient / simpler instance).
   - Có dạng cấu trúc biểu diễn dữ liệu thuận lợi hơn (different data representation).
   - Hoặc chuyển đổi hoàn toàn sang một bài toán khác đã có sẵn thuật toán giải hiệu quả (different problem).
2. **Giai đoạn Trị / Giải quyết (Conquering Stage):** Giải quyết thể hiện sau khi biến đổi để thu được nghiệm của bài toán gốc.

## 2. BA BIẾN THỂ CHÍNH CỦA BIẾN ĐỔI ĐỂ TRỊ
Tùy thuộc vào bản chất của phép biến đổi, chiến lược được chia thành ba nhóm lớn:

```
                          ┌──────────────────────────────────────────────┐
                          │     TRANSFORM-AND-CONQUER (BIẾN ĐỔI ĐỂ TRỊ)  │
                          └──────────────────────┬───────────────────────┘
                                                 │
          ┌──────────────────────────────────────┼──────────────────────────────────────┐
          │                                      │                                      │
          ▼                                      ▼                                      ▼
┌───────────────────────────┐          ┌───────────────────────────┐          ┌───────────────────────────┐
│     1. BIẾN ĐỔI THỂ HIỆN   │          │   2. THAY ĐỔI BIỂU DIỄN   │          │   3. THU GỌN BÀI TOÁN     │
│   (Instance Simplification)│          │   (Representation Change) │          │    (Problem Reduction)    │
├───────────────────────────┤          ├───────────────────────────┤          ├───────────────────────────┤
│ • Chuyển sang thể hiện    │          │ • Giữ nguyên thể hiện     │          │ • Chuyển đổi bài toán A   │
│   cùng loại nhưng dễ hơn. │          │   nhưng đổi cấu trúc lưu. │          │   thành bài toán B.       │
│ • Ví dụ: Sắp xếp sơ bộ   │          │ • Ví dụ: Cây AVL, 2-3 Tree│          │ • Ví dụ: Tính lcm qua gcd,│
│   (Presorting), Khử Gauss │          │   Đống (Heap), Horner,    │          │   đường đi qua nhân ma trận│
│   (Gaussian Elimination). │          │   Lũy thừa nhị phân.      │          │   quy hoạch tuyến tính LP.│
└───────────────────────────┘          └───────────────────────────┘          └───────────────────────────┘
```

1. **Biến đổi thể hiện (Instance Simplification):**
   - Chuyển thể hiện bài toán ban đầu thành một thể hiện mới của *cùng một bài toán* nhưng có tính chất đơn giản hơn.
   - *Ví dụ 1:* **Sắp xếp sơ bộ (Presorting)** – Biến mảng lộn xộn thành mảng đã sắp xếp; nhờ đó bài toán kiểm tra tính duy nhất (Uniqueness) giảm từ $\Theta(n^2)$ xuống $\Theta(n \log n)$, tìm yếu vị (Mode) giảm từ $\Theta(n^2)$ xuống $\Theta(n \log n)$.
   - *Ví dụ 2:* **Khử Gauss (Gaussian Elimination)** – Biến hệ phương trình đại số tuyến tính $Ax = b$ với ma trận đầy đủ thành hệ tương đương với ma trận tam giác trên $Ux = y$, cho phép giải bằng phép thế ngược cực kỳ đơn giản.

2. **Thay đổi biểu diễn (Representation Change):**
   - Chuyển đổi cấu trúc dữ liệu biểu diễn của bài toán sang một cấu trúc dữ liệu mới hỗ trợ các thao tác nhanh hơn vượt bậc.
   - *Ví dụ 1:* **Cây tìm kiếm cân bằng (Balanced Search Trees - AVL & 2-3 Trees)** – Thay vì dùng cây tìm kiếm nhị phân có nguy cơ thoái hóa thành đường thẳng ($\Theta(n)$), ta duy trì cấu trúc cân bằng để đảm bảo thời gian tìm kiếm, chèn, xóa luôn là $\Theta(\log n)$ trong mọi trường hợp.
   - *Ví dụ 2:* **Cấu trúc Đống (Heap) & Heapsort** – Biểu diễn danh sách bằng cây nhị phân gần hoàn chỉnh thỏa mãn tính chất trội của cha, cho phép tìm và xóa phần tử cực trị trong $\Theta(\log n)$ và sắp xếp trong $\Theta(n \log n)$.
   - *Ví dụ 3:* **Luật Horner & Lũy thừa nhị phân** – Biến đổi đa thức thành dạng ngoặc lồng nhau và số mũ thành dạng biểu diễn nhị phân để giảm số phép nhân từ $\Theta(n^2)$ xuống $\Theta(n)$ và từ $\Theta(n)$ xuống $\Theta(\log n)$.

3. **Thu gọn bài toán (Problem Reduction):**
   - Chuyển đổi toàn bộ bài toán cần giải thành một bài toán hoàn toàn khác mà lời giải hiệu quả đã được biết rõ.
   - *Ví dụ 1:* Tìm BCNN $\text{lcm}(m, n) = \frac{m \cdot n}{\gcd(m, n)}$ (thu gọn về thuật toán Euclid).
   - *Ví dụ 2:* Đếm số đường đi độ dài $k$ trong đồ thị thu gọn về phép nhân lũy thừa ma trận kề $A^k$.
   - *Ví dụ 3:* Thu gọn các bài toán tối ưu hóa tổ hợp (Maximum Flow, Bipartite Matching) về Quy hoạch tuyến tính (Linear Programming - Simplex Method).



---


# CHUYÊN ĐỀ 01: SẮP XẾP SƠ BỘ (PRESORTING) & LỜI GIẢI BÀI TẬP 6.1
*Tài liệu tham chiếu: A. Levitin, "Introduction to the Design and Analysis of Algorithms", 3rd Edition, Chương 6, Mục 6.1, Trang 202–208.*

---

## PHẦN I. LÝ THUYẾT VÀ MÃ GIẢ CHUẨN HÓA

### 1.1. Khái niệm và Nguyên lý Sắp xếp sơ bộ (Presorting)
Nhiều bài toán xử lý danh sách có thể được giải quyết nhanh hơn đáng kể nếu danh sách dữ liệu đầu vào được **sắp xếp thứ tự trước**. 
- Chi phí sắp xếp: Với các thuật toán sắp xếp dựa trên so sánh tối ưu (như Mergesort hay Heapsort), chi phí thời gian là $\Theta(n \log n)$.
- Để chiến lược sắp xếp sơ bộ mang lại hiệu quả: Sau khi sắp xếp, thời gian giải quyết bài toán trên danh sách đã sắp xếp phải nhỏ hơn hoặc bằng $\Theta(n \log n)$, giúp tổng thời gian toàn bộ thuật toán đạt $O(n \log n)$, vượt trội hơn các giải pháp vét cạn $\Theta(n^2)$.

---

### 1.2. Các ứng dụng kinh điển của Sắp xếp sơ bộ

#### Ứng dụng 1: Kiểm tra tính duy nhất của các phần tử (Element Uniqueness)
- **Bài toán:** Cho mảng $A[0..n-1]$. Xác định xem tất cả các phần tử trong mảng có đôi một phân biệt hay không.
- **Tiếp cận vét cạn:** So sánh mọi cặp phần tử $(A[i], A[j])$ với $i < j$.
  $$C_{\text{brute}}(n) = \sum_{i=0}^{n-2} \sum_{j=i+1}^{n-1} 1 = \frac{n(n-1)}{2} \in \Theta(n^2)$$
- **Tiếp cận Sắp xếp sơ bộ:**
  1. Sắp xếp mảng $A$ theo thứ tự tăng dần bằng thuật toán $\Theta(n \log n)$.
  2. Quét một lần qua mảng đã sắp xếp: Các phần tử bằng nhau bắt buộc phải nằm ở hai vị trí kề nhau. Do đó, chỉ cần so sánh $A[i]$ với $A[i+1]$ với mọi $0 \le i < n-1$.
  3. Chi phí quét: Tối đa $n-1$ phép so sánh $\implies \Theta(n)$.
  4. Tổng chi phí:
     $$T(n) = T_{\text{sort}}(n) + T_{\text{scan}}(n) \in \Theta(n \log n) + \Theta(n) = \Theta(n \log n)$$

##### Mã giả chuẩn hóa:
```text
function: PresortElementUniqueness(A[0..n - 1]): Boolean
    input: A[0..n - 1]: Array of comparable elements – mảng cần kiểm tra.
           n: integer (n ≥ 1) – số lượng phần tử.
    output: true nếu tất cả các phần tử phân biệt, false nếu có ít nhất 2 phần tử trùng nhau.

 1  Sort(A) – sắp xếp mảng A theo thứ tự tăng dần bằng thuật toán O(n log n).
 2  for i = 0 to n - 2 do
 3      if A[i] = A[i + 1] then
 4          return false – phát hiện hai phần tử trùng nhau kề nhau.
 5      end-if
 6  end-for
 7  return true – tất cả phần tử đều phân biệt.
```

- **Tính tối ưu:** Theo lý thuyết cận dưới, trong mô hình cây quyết định dựa trên so sánh đại số, bài toán Element Uniqueness có cận dưới $\Omega(n \log n)$. Do đó thuật toán `PresortElementUniqueness` là tối ưu tiệm cận.

---

#### Ứng dụng 2: Tìm yếu vị của mảng (Computing a Mode)
- **Khái niệm:** Yếu vị (Mode) của một danh sách là giá trị xuất hiện với tần số lớn nhất (ví dụ: trong dãy $1, 3, 2, 3, 5, 3, 2$, yếu vị là $3$ với tần số 3).
- **Tiếp cận vét cạn:** Quét mảng, đếm tần số xuất hiện của từng phần tử bằng cách duyệt lại toàn bộ mảng $\implies \Theta(n^2)$.
- **Tiếp cận Sắp xếp sơ bộ:**
  1. Sắp xếp mảng $A$ trong $\Theta(n \log n)$.
  2. Trong mảng đã sắp xếp, tất cả các phần tử có cùng giá trị sẽ nằm liên tiếp nhau tạo thành một đoạn (run).
  3. Quét một lượt từ trái sang phải, đếm độ dài từng đoạn liên tiếp và ghi nhận đoạn có độ dài lớn nhất.
  4. Chi phí quét: Đúng $n-1$ phép so sánh kề $\implies \Theta(n)$.
  5. Tổng chi phí: $\Theta(n \log n) + \Theta(n) = \Theta(n \log n)$.

##### Mã giả chuẩn hóa:
```text
function: PresortMode(A[0..n - 1]): ElementType
    input: A[0..n - 1]: Array of comparable elements – mảng dữ liệu.
           n: integer (n ≥ 1) – số lượng phần tử.
    output: mode_val: ElementType – giá trị có tần số xuất hiện lớn nhất.

 1  Sort(A) – sắp xếp mảng tăng dần trong O(n log n).
 2  i = 0 – chỉ số bắt đầu của đoạn hiện tại.
 3  mode_frequency = 0 – độ dài đoạn dài nhất tìm thấy.
 4  mode_val = A[0]
 5  while i < n do
 6      run_length = 1
 7      run_val = A[i]
 8      while i + run_length < n and A[i + run_length] = run_val do
 9          run_length = run_length + 1
10      end-while
11      if run_length > mode_frequency then
12          mode_frequency = run_length
13          mode_val = run_val
14      end-if
15      i = i + run_length – nhảy tới đoạn tiếp theo.
16  end-while
17  return mode_val.
```

---

#### Ứng dụng 3: Bài toán Tìm kiếm nhiều lần (Searching Problem with Multiple Queries)
- Nếu chỉ tìm kiếm một lần ($q = 1$ truy vấn):
  - Tìm kiếm tuần tự trên mảng chưa sắp: $O(n)$.
  - Sắp xếp trước rồi tìm nhị phân: $O(n \log n) + O(\log n) = O(n \log n)$ (kém hơn).
- Nếu thực hiện $q$ truy vấn tìm kiếm độc lập:
  - Tiếp cận không sắp xếp: $q \times O(n) = O(q \cdot n)$.
  - Tiếp cận sắp xếp sơ bộ: Sắp xếp 1 lần tốn $O(n \log n)$, sau đó mỗi truy vấn dùng tìm kiếm nhị phân $O(\log n)$:
    $$T(n, q) \in O(n \log n + q \log n) = O((n + q) \log n)$$
  - Khi số truy vấn $q > \frac{n}{\log n}$, sắp xếp sơ bộ đem lại hiệu quả vượt trội.

---

## PHẦN II. GIẢI CHI TIẾT 100% BÀI TẬP EXERCISES 6.1 (BÀI 1 ĐẾN BÀI 11)

### Bài 6.1.1: Tìm hai phần tử có khoảng cách nhỏ nhất (Closest Pair in 1D)
> **Đề bài:**
> Cho một mảng số thực $A[0..n-1]$ gồm $n$ phần tử ($n \ge 2$). Hãy thiết kế thuật toán hiệu quả nhất để tìm hai phần tử có khoảng cách nhỏ nhất, tức là cặp $(A[i], A[j])$ với $i \ne j$ sao cho $|A[i] - A[j]|$ đạt giá trị nhỏ nhất.

> **Gợi ý của tác giả (Levitin):**
> Bài toán này tương tự như một trong các ví dụ được trình bày trong mục lý thuyết (áp dụng sắp xếp sơ bộ).

**Phân tích phương pháp giải:**
1. **Tiếp cận vét cạn (Brute-force):** Duyệt qua tất cả các cặp chỉ số $(i, j)$ với $0 \le i < j < n$, tính khoảng cách $|A[i] - A[j]|$ và tìm giá trị nhỏ nhất. Số cặp cần xét là $\frac{n(n-1)}{2} \in \Theta(n^2)$.
2. **Tiếp cận Sắp xếp sơ bộ (Presorting):**
   - Trên trục số thực, khoảng cách giữa hai điểm bất kỳ luôn lớn hơn hoặc bằng khoảng cách giữa các điểm kề nhau trong dãy đã được sắp xếp tăng dần!
   - Thật vậy, nếu $x \le y \le z$, thì $|x - z| = (z - y) + (y - x) \ge \min(|x - y|, |y - z|)$.
   - Do đó, sau khi sắp xếp mảng theo thứ tự tăng dần, cặp điểm gần nhau nhất **chắc chắn là hai phần tử đứng cạnh nhau** $A[i]$ và $A[i+1]$.

**Lời giải chi tiết:**
- **Bước 1:** Sắp xếp mảng $A$ theo thứ tự tăng dần bằng Mergesort hoặc Heapsort: chi phí $O(n \log n)$.
- **Bước 2:** Khởi tạo khoảng cách nhỏ nhất $\text{min\_diff} = A[1] - A[0]$, cặp chỉ số nghiệm $(idx_1, idx_2) = (0, 1)$.
- **Bước 3:** Quét qua mảng với $i$ chạy từ 1 đến $n-2$:
  - Nếu $A[i+1] - A[i] < \text{min\_diff}$ thì cập nhật $\text{min\_diff} = A[i+1] - A[i]$ và lưu cặp $(i, i+1)$.
- **Độ phức tạp thời gian:**
  $$T(n) = T_{\text{sort}}(n) + T_{\text{scan}}(n) = \Theta(n \log n) + \Theta(n) = \Theta(n \log n)$$
  Nhanh hơn đáng kể so với thuật toán vét cạn $\Theta(n^2)$.

```text
function: MinDistancePresort(A[0..n - 1]): Pair<Real, Real>
    input: A[0..n - 1]: Array of real numbers (n ≥ 2).
    output: (p, q): Pair of elements with minimum absolute difference.

 1  Sort(A) – sắp xếp mảng tăng dần trong O(n log n).
 2  min_diff = A[1] - A[0]
 3  best_pair = (A[0], A[1])
 4  for i = 1 to n - 2 do
 5      diff = A[i + 1] - A[i]
 6      if diff < min_diff then
 7          min_diff = diff
 8          best_pair = (A[i], A[i + 1])
 9      end-if
10  end-for
11  return best_pair.
```

---

### Bài 6.1.2: Kiểm tra tập hợp rời nhau (Disjoint Sets Problem)
> **Đề bài:**
> Cho hai tập hợp $A$ và $B$ lần lượt chứa $m$ và $n$ phần tử. Cần kiểm tra xem hai tập hợp có rời nhau hay không (nghĩa là $A \cap B = \emptyset$).
> a. Hãy phân tích độ phức tạp thời gian của thuật toán vét cạn giải bài toán này.
> b. Thiết kế ba thuật toán khác nhau sử dụng kỹ thuật sắp xếp sơ bộ (presorting) và so sánh hiệu quả thời gian của chúng.

> **Gợi ý của tác giả (Levitin):**
> a. So sánh từng phần tử của tập này với tất cả phần tử của tập kia. b. Có ba cách dùng presorting: sắp xếp 1 tập, sắp xếp cả 2 tập riêng rẽ, hoặc gộp 2 tập lại rồi sắp xếp chung.

**Phân tích & Lời giải chi tiết:**

**a. Thuật toán vét cạn (Brute-force):**
- Lấy từng phần tử $x \in A$, duyệt tuần tự qua tất cả các phần tử $y \in B$ để kiểm tra xem $x$ có bằng $y$ không. Nếu tìm thấy, kết luận ngay hai tập không rời nhau.
- Trường hợp xấu nhất (hai tập rời nhau): Thuật toán phải thực hiện $m \times n$ phép so sánh.
- Độ phức tạp thời gian trường hợp xấu nhất: $\Theta(m \cdot n)$.

**b. Ba thuật toán sử dụng Sắp xếp sơ bộ:**

- **Phương án 1: Sắp xếp một tập hợp (giả sử sắp xếp tập $B$ có $n$ phần tử):**
  1. Sắp xếp mảng $B$ trong $\Theta(n \log n)$.
  2. Với mỗi phần tử $x \in A$, thực hiện tìm kiếm nhị phân (Binary Search) trên mảng $B$ đã sắp xếp: chi phí $\Theta(\log n)$ cho mỗi phần tử.
  3. Tổng thời gian: $\Theta(n \log n + m \log n) = \Theta((n + m) \log n)$.
  *(Nếu $m < n$, ta nên sắp xếp tập $B$ để tận dụng $\log n$; nếu $n < m$, ta sắp xếp tập $A$ để tốn $\Theta((m + n) \log m)$).*

- **Phương án 2: Sắp xếp cả hai tập hợp riêng rẽ rồi Trộn (Sort both and Merge-scan):**
  1. Sắp xếp $A$ tốn $\Theta(m \log m)$.
  2. Sắp xếp $B$ tốn $\Theta(n \log n)$.
  3. Dùng hai con trỏ $i=0$ (trên $A$) và $j=0$ (trên $B$) tương tự thao tác trộn của Mergesort:
     - Nếu $A[i] == B[j]$: Dừng lại, kết luận không rời nhau.
     - Nếu $A[i] < B[j]$: Tăng $i = i + 1$.
     - Nếu $A[i] > B[j]$: Tăng $j = j + 1$.
  4. Quá trình quét tốn tối đa $m + n$ phép so sánh.
  5. Tổng thời gian: $\Theta(m \log m + n \log n + m + n) = \Theta(m \log m + n \log n)$.

- **Phương án 3: Gộp hai tập hợp lại và sắp xếp chung (Merge into single array and Sort):**
  1. Tạo mảng $C$ kích thước $m + n$ chứa tất cả phần tử của $A$ và $B$. Mỗi phần tử lưu kèm nhãn nguồn gốc (thuộc $A$ hay $B$).
  2. Sắp xếp mảng $C$ tốn $\Theta((m + n) \log(m + n))$.
  3. Quét qua mảng $C$, so sánh $C[k]$ và $C[k+1]$: Nếu hai phần tử bằng nhau và đến từ hai tập khác nhau $\implies$ giao khác rỗng. Chi phí quét: $\Theta(m + n)$.
  4. Tổng thời gian: $\Theta((m + n) \log(m + n))$.

**So sánh hiệu quả:**
- Cả ba phương án đều có cùng bậc độ phức tạp xấp xỉ $\Theta((m + n) \log(\max(m, n)))$ khi $m \approx n$.
- Tuy nhiên, nếu một tập nhỏ hơn tập kia rất nhiều (ví dụ $m \ll n$):
  - Phương án 1 (sắp xếp tập lớn $B$ rồi tìm nhị phân $m$ lần) tốn $O(n \log n + m \log n) = O(n \log n)$.
  - Hoặc sắp xếp tập nhỏ $A$ tốn $O(m \log m)$, sau đó tìm nhị phân $n$ lần tốn $O(n \log m)$ $\implies$ tổng chi phí chỉ là $O(n \log m)$, đây là phương án nhanh nhất khi $m \ll n$!

---

### Bài 6.1.3: Tìm phần tử nhỏ nhất và lớn nhất đồng thời (Min-Max Problem)
> **Đề bài:**
> Cho mảng $n$ phần tử.
> a. Có nên dùng kỹ thuật sắp xếp sơ bộ để tìm phần tử nhỏ nhất và lớn nhất của mảng hay không?
> b. So sánh hiệu quả của cách tiếp cận đó với thuật toán vét cạn và thuật toán chia để trị.

> **Gợi ý của tác giả (Levitin):**
> a. Làm thế nào để tìm phần tử nhỏ nhất và lớn nhất trong danh sách đã sắp xếp? b. Thuật toán vét cạn và chia để trị đều có độ phức tạp tuyến tính.

**Lời giải chi tiết:**
- **a. Trả lời: KHÔNG NÊN.**
  - Nếu áp dụng sắp xếp sơ bộ: Sắp xếp mảng tốn ít nhất $\Theta(n \log n)$ phép so sánh. Sau đó phần tử nhỏ nhất là $A[0]$ và lớn nhất là $A[n-1]$ (lấy trong $O(1)$). Tổng chi phí là $\Theta(n \log n)$.
  - Đây là sự lãng phí tài nguyên tính toán nghiêm trọng vì ta đã giải một bài toán khó hơn rất nhiều (sắp xếp toàn bộ mảng) chỉ để lấy hai giá trị cực trị.

- **b. So sánh hiệu quả:**
  1. **Thuật toán quét tuyến tính chuẩn (Vét cạn cải tiến / So sánh theo cặp):**
     - Ghép các phần tử thành từng cặp, so sánh hai phần tử trong cặp với nhau (tốn $\lfloor n/2 \rfloor$ phép so sánh).
     - So sánh kẻ thắng với Max hiện tại, kẻ thua với Min hiện tại (tốn $2 \times \lfloor n/2 \rfloor$ phép so sánh).
     - Tổng số phép so sánh: Đúng $\lceil \frac{3n}{2} \rceil - 2 \in \Theta(n)$.
  2. **Thuật toán Chia để trị (Divide-and-Conquer):**
     - Chia mảng làm hai nửa, đệ quy tìm $(\min_1, \max_1)$ và $(\min_2, \max_2)$, sau đó so sánh $\min = \min(\min_1, \min_2)$ và $\max = \max(\max_1, \max_2)$ (tốn 2 phép so sánh).
     - Phương trình truy hồi: $C(n) = 2C(n/2) + 2$ với $C(2) = 1, C(1) = 0$.
     - Nghiệm giải tích: $C(n) = \frac{3n}{2} - 2 \in \Theta(n)$.
  3. **Kết luận:** Cả vét cạn ghép cặp và chia để trị đều chạy trong thời gian tuyến tính $\Theta(n)$ với đúng $\approx 1.5n$ phép so sánh, tối ưu hơn hẳn phương pháp sắp xếp sơ bộ $\Theta(n \log n)$.

---

### Bài 6.1.4: So sánh số phép so sánh trung bình giữa Tìm kiếm tuần tự và Tìm nhị phân sau sắp xếp
> **Đề bài:**
> Giả sử cần thực hiện $q$ truy vấn tìm kiếm độc lập trên một mảng ngẫu nhiên gồm $n$ phần tử phân biệt.
> Xác định điều kiện của $q$ (theo $n$) để phương pháp sắp xếp sơ bộ mảng rồi dùng tìm kiếm nhị phân có số phép so sánh trung bình ít hơn so với việc tìm kiếm tuần tự trên mảng chưa sắp xếp.

> **Gợi ý của tác giả (Levitin):**
> Sử dụng kết quả về số phép so sánh trung bình của các thuật toán đã học trong Chương 2 và Chương 4.

**Lời giải chi tiết:**
1. **Số phép so sánh trung bình của Tìm kiếm tuần tự (Sequential Search):**
   - Với mảng ngẫu nhiên, xác suất tìm thấy là $p \approx 1$ và các vị trí có xác suất như nhau:
     $$C_{\text{seq}}^{\text{avg}}(n) \approx \frac{n + 1}{2} \approx \frac{n}{2}$$
   - Với $q$ lần tìm kiếm tuần tự:
     $$C_{\text{total\_seq}} \approx q \cdot \frac{n}{2}$$

2. **Số phép so sánh của phương pháp Sắp xếp sơ bộ + Tìm nhị phân:**
   - Sắp xếp mảng bằng Mergesort (hoặc Quicksort trung bình):
     $$C_{\text{sort}}(n) \approx n \log_2 n$$
   - Mỗi lần tìm kiếm nhị phân tốn trung bình:
     $$C_{\text{bin}}^{\text{avg}}(n) \approx \log_2 n - 1$$
   - Với $q$ lần tìm kiếm nhị phân:
     $$C_{\text{total\_presort}} \approx n \log_2 n + q (\log_2 n - 1)$$

3. **Điều kiện để Sắp xếp sơ bộ thắng Tìm kiếm tuần tự:**
   $$C_{\text{total\_presort}} < C_{\text{total\_seq}} \iff n \log_2 n + q (\log_2 n - 1) < q \cdot \frac{n}{2}$$
   $$\iff n \log_2 n < q \left( \frac{n}{2} - \log_2 n + 1 \right)$$
   $$\iff q > \frac{n \log_2 n}{\frac{n}{2} - \log_2 n + 1} \approx \frac{n \log_2 n}{n / 2} = 2 \log_2 n$$
- **Kết luận:** Chỉ cần số truy vấn $q > 2 \log_2 n$, phương pháp sắp xếp sơ bộ kết hợp tìm kiếm nhị phân sẽ có tổng số phép so sánh trung bình ít hơn tìm kiếm tuần tự!

---

### Bài 6.1.5: Sắp xếp sinh viên theo điểm và số báo danh (Student Records Presorting)
> **Đề bài:**
> Một danh sách gồm $n$ sinh viên với thông tin gồm: Họ tên, Số báo danh (duy nhất), Điểm thi tốt nghiệp (số nguyên từ 0 đến 100).
> Cần sắp xếp danh sách sinh viên theo thứ tự giảm dần của điểm thi; nếu các sinh viên có cùng điểm thi, sắp xếp tăng dần theo Số báo danh.
> a. Đề xuất một thuật toán hiệu quả giải bài toán này.
> b. Nếu chỉ dùng cách tiếp cận phân loại thực tế ngoài đời (ví dụ phân loại thẻ giấy), bạn sẽ giải bài toán này như thế nào?

**Lời giải chi tiết:**
- **a. Giải pháp thuật toán tối ưu (Presorting kết hợp khóa phức hợp hoặc Bucket Sort):**
  - **Cách 1 (So sánh với quan hệ thứ tự phức hợp):**
    Định nghĩa quan hệ so sánh giữa hai sinh viên $S_1$ và $S_2$:
    $$S_1 < S_2 \iff (S_1.\text{diem} > S_2.\text{diem}) \lor (S_1.\text{diem} == S_2.\text{diem} \land S_1.\text{SBD} < S_2.\text{SBD})$$
    Áp dụng Mergesort với hàm so sánh trên: thời gian chạy $\Theta(n \log n)$, bộ nhớ $O(n)$, thuật toán có tính ổn định.
  - **Cách 2 (Thuật toán đếm phân phối / Bucket Sort đạt thời gian tuyến tính $\Theta(n)$):**
    Vì điểm thi là số nguyên giới hạn từ $0$ đến $100$ (chỉ có 101 giá trị khả dĩ):
    1. Tạo 101 danh sách liên kết con (buckets) ứng với các điểm từ 100 lùi về 0.
    2. Sắp xếp sơ bộ toàn bộ danh sách sinh viên theo Số báo danh tăng dần: tốn $O(n \log n)$ hoặc $O(n)$ nếu dùng Radix Sort.
    3. Quét qua danh sách đã sắp xếp theo SBD, đưa sinh viên vào bucket tương ứng với điểm thi. Vì sinh viên được duyệt theo thứ tự SBD tăng dần, trong mỗi bucket các sinh viên tự động có SBD tăng dần!
    4. Nối 101 bucket từ 100 về 0 lại với nhau tốn $O(n)$. Tổng thời gian là $\Theta(n)$ nếu SBD được đánh số nhỏ.

- **b. Tiếp cận thực tế ngoài đời thường (Phân loại thẻ giấy):**
  - Người thực tế sẽ chia một cái bàn thành 101 ngăn (từ 0 đến 100).
  - Cầm tập thẻ sinh viên, nhìn điểm và thả thẻ vào đúng ngăn điểm tương ứng.
  - Sau đó, với mỗi ngăn điểm (chỉ chứa một số lượng nhỏ sinh viên có cùng điểm), sắp xếp các thẻ trong ngăn đó theo SBD tăng dần.
  - Cuối cùng gom các xấp thẻ từ ngăn 100 xuống ngăn 0 xếp chồng lên nhau. Đây chính là nguyên lý của thuật toán **Bucket Sort (Sắp xếp theo thùng)**.

---

### Bài 6.1.6: Dựng đa giác đơn từ tập hợp điểm (Constructing a Simple Polygon)
> **Đề bài:**
> Cho $n$ điểm trên mặt phẳng tọa độ $(n \ge 3)$, không có ba điểm nào thẳng hàng.
> Hãy thiết kế thuật toán sử dụng sắp xếp sơ bộ (presorting) để dựng một đa giác đơn (simple polygon) có các đỉnh là chính xác $n$ điểm đã cho.

> **Gợi ý của tác giả (Levitin):**
> Thử giải cho một vài ví dụ nhỏ ngẫu nhiên. Hãy sắp xếp các điểm theo góc cực đối với một điểm mốc.

**Lời giải chi tiết:**
- **Định nghĩa đa giác đơn:** Là đa giác có các cạnh không tự cắt nhau, chỉ giao nhau tại các đỉnh chung của hai cạnh liên tiếp.
- **Thuật toán dựa trên Sắp xếp sơ bộ theo góc cực (Graham's Scan preprocessing):**
  1. **Bước 1 (Chọn điểm mốc):** Tìm điểm $P_0(x_0, y_0)$ có tung độ $y$ nhỏ nhất (nếu trùng nhau, chọn điểm có hoành độ $x$ nhỏ nhất). Điểm $P_0$ chắc chắn là một đỉnh lồi của bao lồi, nằm ở góc dưới cùng.
  2. **Bước 2 (Biến đổi thể hiện qua sắp xếp):**
     - Với mỗi điểm $P_i$ còn lại ($i = 1, \dots, n-1$), tính góc cực $\theta_i$ tạo bởi tia $P_0 P_i$ với chiều dương trục hoành $Ox$:
       $$\theta_i = \text{atan2}(y_i - y_0, x_i - x_0)$$
     - Sắp xếp $n-1$ điểm theo thứ tự tăng dần của góc cực $\theta$:
       $$P_{i_1}, P_{i_2}, \dots, P_{i_{n-1}}$$
  3. **Bước 3 (Nối đa giác):**
     - Nối lần lượt các điểm theo thứ tự:
       $$P_0 \to P_{i_1} \to P_{i_2} \to \dots \to P_{i_{n-1}} \to P_0$$
- **Chứng minh tính không tự cắt (Đa giác đơn):**
  - Vì các tia quét từ $P_0$ quét ngược chiều kim đồng hồ theo thứ tự góc cực tăng ngặt (không có 3 điểm thẳng hàng), các tam giác hình quạt $P_0 P_{i_k} P_{i_{k+1}}$ có phần trong rời nhau đôi một.
  - Do đó, đường bao ngoài khép kín tạo thành một đa giác hình sao (star-shaped polygon) nhận $P_0$ làm tâm sao, hoàn toàn không có hai cạnh nào cắt nhau.
- **Độ phức tạp thời gian:**
  - Tìm $P_0$: $\Theta(n)$.
  - Sắp xếp $n-1$ điểm theo góc cực: $\Theta(n \log n)$.
  - Nối các cạnh: $\Theta(n)$.
  - Tổng chi phí: $\Theta(n \log n)$ – Tối ưu bậc nhất!

---

### Bài 6.1.7: Tìm cặp phần tử có tổng bằng số $s$ cho trước (Two Sum Problem)
> **Đề bài:**
> Cho mảng số thực $A[0..n-1]$ và một số thực $s$. Thiết kế thuật toán có độ phức tạp $O(n \log n)$ để kiểm tra xem có tồn tại hai phần tử $A[i], A[j]$ ($i \ne j$) sao cho $A[i] + A[j] = s$ hay không.

> **Gợi ý của tác giả (Levitin):**
> Sắp xếp mảng trước, sau đó sử dụng kỹ thuật hai con trỏ duyệt từ hai đầu.

**Lời giải chi tiết:**
- **Tiếp cận:**
  1. **Bước 1 (Sắp xếp sơ bộ):** Sắp xếp mảng $A$ theo thứ tự tăng dần: $O(n \log n)$.
  2. **Bước 2 (Hai con trỏ - Two Pointers):**
     - Đặt con trỏ trái $L = 0$, con trỏ phải $R = n - 1$.
     - Lặp khi $L < R$:
       + Tính tổng hiện tại $\text{sum} = A[L] + A[R]$.
       + Nếu $\text{sum} == s$: Trả về `true` (tìm thấy cặp).
       + Nếu $\text{sum} < s$: Vì mảng đã sắp xếp, để tăng tổng, ta bắt buộc phải tăng phần tử nhỏ hơn $\implies L = L + 1$.
       + Nếu $\text{sum} > s$: Để giảm tổng, ta bắt buộc phải giảm phần tử lớn hơn $\implies R = R - 1$.
     - Nếu vòng lặp kết thúc mà chưa tìm thấy: Trả về `false`.
- **Độ phức tạp:**
  - Sắp xếp: $\Theta(n \log n)$.
  - Vòng lặp hai con trỏ: Mỗi bước $L$ tăng hoặc $R$ giảm, tối đa $n$ bước $\implies \Theta(n)$.
  - Tổng thời gian: $\Theta(n \log n) + \Theta(n) = \Theta(n \log n)$.

```text
function: TwoSumPresort(A[0..n - 1], s): Boolean
    input: A[0..n - 1]: Array of real numbers.
           s: real number – target sum.
    output: true nếu tồn tại A[i] + A[j] = s (i ≠ j), false nếu không.

 1  Sort(A) – sắp xếp tăng dần trong O(n log n).
 2  left = 0
 3  right = n - 1
 4  while left < right do
 5      current_sum = A[left] + A[right]
 6      if current_sum = s then
 7          return true
 8      else if current_sum < s then
 9          left = left + 1
10      else
11          right = right - 1
12      end-if
13  end-while
14  return false.
```

---

### Bài 6.1.8: Kiểm tra bao hàm tập hợp đa phần tử (Multiset Inclusion Problem)
> **Đề bài:**
> Cho hai đa tập hợp (multiset - tập hợp cho phép các phần tử trùng lặp) $A = \{a_1, \dots, a_n\}$ và $B = \{b_1, \dots, b_m\}$.
> Thiết kế thuật toán hiệu quả để kiểm tra xem $A$ có phải là đa tập con của $B$ hay không (nghĩa là mọi phần tử trong $A$ đều xuất hiện trong $B$ với số lần xuất hiện trong $A$ không vượt quá số lần xuất hiện trong $B$).

> **Gợi ý của tác giả (Levitin):**
> Sau khi sắp xếp $A$ và $B$, bài toán có thể giải trong thời gian tuyến tính.

**Lời giải chi tiết:**
- **Điều kiện cần:** Nếu $n > m$ thì $A$ không thể là tập con của $B$, trả về `false` ngay lập tức.
- **Thuật toán:**
  1. Sắp xếp mảng $A$ theo thứ tự tăng dần: chi phí $O(n \log n)$.
  2. Sắp xếp mảng $B$ theo thứ tự tăng dần: chi phí $O(m \log m)$.
  3. Dùng hai con trỏ $i = 0$ (trên $A$) và $j = 0$ (trên $B$):
     - Lặp khi $i < n$ và $j < m$:
       + Nếu $A[i] == B[j]$: Phần tử $A[i]$ đã được ghép với $B[j]$, tăng cả hai $i = i + 1, j = j + 1$.
       + Nếu $A[i] > B[j]$: Phần tử $B[j]$ quá nhỏ, bỏ qua $B[j]$, tăng $j = j + 1$.
       + Nếu $A[i] < B[j]$: Vì $B$ đã sắp xếp tăng dần, tất cả các phần tử còn lại trong $B$ đều lớn hơn $A[i]$, do đó $A[i]$ không thể xuất hiện thêm trong $B \implies$ Trả về `false` ngay!
     - Khi vòng lặp kết thúc: Nếu $i == n$ (đã tìm đủ tất cả phần tử của $A$) thì trả về `true`, ngược lại trả về `false`.
- **Độ phức tạp:**
  $$T(n, m) = O(n \log n + m \log m + (n + m))$$
  Nếu $n \le m$, độ phức tạp là $O(m \log m)$.

---

### Bài 6.1.9: Tìm phần tử xuất hiện nhiều hơn $n/2$ lần (Majority Element via Presorting)
> **Đề bài:**
> Cho mảng $A[0..n-1]$. Một phần tử được gọi là đa số (majority element) nếu nó xuất hiện nghiêm ngặt nhiều hơn $n/2$ lần trong mảng.
> Thiết kế thuật toán sử dụng sắp xếp sơ bộ để tìm phần tử đa số hoặc kết luận mảng không có phần tử đa số.

> **Gợi ý của tác giả (Levitin):**
> Bắt đầu bằng việc sắp xếp danh sách đã cho. Nếu có phần tử đa số, nó bắt buộc phải nằm ở vị trí nào?

**Lời giải chi tiết:**
- **Tính chất then chốt:** Nếu mảng có một phần tử đa số, phần tử đó chiếm hơn $50\%$ số lượng phần tử. Do đó, trong mảng đã được sắp xếp tăng dần, phần tử này **bắt buộc phải đi qua và chiếm giữ vị trí phần tử trung vị** tại chỉ số $m = \lfloor n/2 \rfloor$!
- **Thuật toán:**
  1. Sắp xếp mảng $A$ theo thứ tự tăng dần trong $O(n \log n)$.
  2. Ứng viên duy nhất có thể là phần tử đa số chính là $candidate = A[\lfloor n/2 \rfloor]$.
  3. Đếm số lần xuất hiện của $candidate$ trong mảng $A$:
     - Có thể duyệt tuyến tính trong $O(n)$, hoặc dùng tìm kiếm nhị phân tìm biên trái (vị trí đầu tiên) và biên phải (vị trí cuối cùng) của $candidate$ trong $O(\log n)$.
     - Số lần xuất hiện $\text{count} = \text{last\_pos} - \text{first\_pos} + 1$.
  4. Nếu $\text{count} > n/2$: Trả về $candidate$. Ngược lại, trả về thông báo không có phần tử đa số.
- **Độ phức tạp thời gian:** $O(n \log n) + O(n) = O(n \log n)$.
*(Lưu ý học thuật: Thuật toán Boyer-Moore Voting Algorithm có thể giải bài này trong $O(n)$ không cần sắp xếp, nhưng phương pháp sắp xếp sơ bộ cho lời giải cực kỳ trực quan và chỉ mất vài dòng code).*

---

### Bài 6.1.10: Tìm tập hợp điểm cực đại (Maximal Points / Pareto Frontier in 2D)
> **Đề bài:**
> Cho tập hợp $n$ điểm trên mặt phẳng tọa độ $S = \{(x_1, y_1), \dots, (x_n, y_n)\}$. Điểm $P(x, y)$ được gọi là bị trội (dominated) bởi điểm $P'(x', y')$ nếu $x \le x'$ và $y \le y'$ (với ít nhất một bất đẳng thức là ngặt).
> Một điểm không bị trội bởi bất kỳ điểm nào khác được gọi là điểm cực đại (maximal point hay điểm tối ưu Pareto).
> a. Thiết kế thuật toán $O(n \log n)$ sử dụng sắp xếp sơ bộ để tìm tất cả các điểm cực đại.
> b. Nêu một ứng dụng thực tế của bài toán này.

> **Gợi ý của tác giả (Levitin):**
> a. Sắp xếp các điểm theo thứ tự không giảm của hoành độ x, sau đó quét các điểm từ phải sang trái. b. Nghĩ về các bài toán lựa chọn với hai tiêu chí mong muốn.

**Lời giải chi tiết:**
- **a. Thiết kế thuật toán:**
  1. **Bước 1 (Sắp xếp sơ bộ):**
     - Sắp xếp các điểm theo thứ tự hoành độ $x$ tăng dần. Nếu cùng $x$, sắp xếp theo tung độ $y$ tăng dần: chi phí $O(n \log n)$.
  2. **Bước 2 (Quét từ phải sang trái):**
     - Điểm cuối cùng trong danh sách đã sắp xếp $P_{n-1} = (x_{n-1}, y_{n-1})$ chắc chắn là điểm cực đại (vì không có điểm nào có hoành độ lớn hơn nó). Thêm $P_{n-1}$ vào tập cực đại.
     - Duy trì giá trị tung độ lớn nhất đã gặp từ bên phải: $y_{\max} = y_{n-1}$.
     - Lùi dần từ $i = n-2$ về $0$:
       + Nếu $y_i > y_{\max}$: Điểm $P_i$ có tung độ lớn hơn tất cả các điểm nằm bên phải nó (những điểm có $x \ge x_i$). Do đó $P_i$ không thể bị trội bởi bất kỳ điểm nào $\implies P_i$ là điểm cực đại!
       + Thêm $P_i$ vào tập kết quả và cập nhật $y_{\max} = y_i$.
       + Ngược lại ($y_i \le y_{\max}$): Điểm $P_i$ đã có $x_i \le x_{\text{right}}$ và $y_i \le y_{\max}$, tức là bị trội bởi điểm tạo ra $y_{\max} \implies$ Loại bỏ $P_i$.
  3. **Độ phức tạp:** Sắp xếp tốn $O(n \log n)$, quét một lượt tốn $O(n)$. Tổng chi phí là $O(n \log n)$.

- **b. Ứng dụng thực tế:**
  - Bài toán tối ưu hóa đa mục tiêu (Multi-objective optimization):
    - Ví dụ mua xe ô tô với hai tiêu chí: $x$ là Tốc độ tối đa (càng cao càng tốt), $y$ là Hiệu quả tiết kiệm nhiên liệu (càng cao càng tốt).
    - Các điểm cực đại chính là Tập tối ưu Pareto (Pareto Frontier) gồm các mẫu xe đáng mua nhất (không có chiếc xe nào khác vừa chạy nhanh hơn vừa tiết kiệm xăng hơn).

---

### Bài 6.1.11: Kiểm tra xem mảng $A$ có phải là hoán vị của mảng $B$ không (Anagram / Permutation Check)
> **Đề bài:**
> Cho hai mảng $A[0..n-1]$ và $B[0..n-1]$. Thiết kế thuật toán dựa trên sắp xếp sơ bộ để kiểm tra xem mảng $A$ có phải là một hoán vị của mảng $B$ hay không.

> **Gợi ý của tác giả (Levitin):**
> Sử dụng ý tưởng sắp xếp sơ bộ hai lần (cho cả hai mảng).

**Lời giải chi tiết:**
- **Nguyên lý:** Hai mảng là hoán vị của nhau khi và chỉ khi sau khi được sắp xếp theo cùng một thứ tự (ví dụ tăng dần), hai mảng trở nên giống hệt nhau từng vị trí:
  $$A_{\text{sorted}}[i] == B_{\text{sorted}}[i] \quad \forall 0 \le i < n$$
- **Thuật toán:**
  1. Sắp xếp mảng $A$ bằng Mergesort: chi phí $\Theta(n \log n)$.
  2. Sắp xếp mảng $B$ bằng Mergesort: chi phí $\Theta(n \log n)$.
  3. Quét đồng thời qua cả hai mảng từ $i = 0$ đến $n - 1$:
     - Nếu tồn tại $A[i] \ne B[i]$: Trả về `false` ngay lập tức.
  4. Nếu quét hết mảng mà tất cả các cặp đều bằng nhau: Trả về `true`.
- **Độ phức tạp thời gian:** $\Theta(n \log n) + \Theta(n \log n) + \Theta(n) = \Theta(n \log n)$.
- **Bộ nhớ phụ trợ:** $O(n)$ nếu dùng Mergesort, hoặc $O(1)$ nếu dùng Heapsort.



---


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



---


# CHUYÊN ĐỀ 03: CÂY TÌM KIẾM CÂN BẰNG (BALANCED SEARCH TREES) & LỜI GIẢI BÀI TẬP 6.3
*Tài liệu tham chiếu: A. Levitin, "Introduction to the Design and Analysis of Algorithms", 3rd Edition, Chương 6, Mục 6.3, Trang 218–226.*

---

## PHẦN I. LÝ THUYẾT VÀ MÃ GIẢ CHUẨN HÓA

### 3.1. Hạn chế của Cây tìm kiếm nhị phân thông thường (BST)
Trong cây tìm kiếm nhị phân thông thường (Binary Search Tree - BST):
- Chi phí tìm kiếm, chèn, xóa phụ thuộc trực tiếp vào **chiều cao $h$** của cây: $O(h)$.
- Trong trường hợp tốt nhất (cây cân bằng hoàn hảo): $h = \lfloor \log_2 n \rfloor \implies \Theta(\log n)$.
- Trong trường hợp xấu nhất (các khóa được chèn theo thứ tự tăng dần hoặc giảm dần): Cây thoái hóa hoàn toàn thành một danh sách liên kết với chiều cao $h = n - 1 \implies \Theta(n)$!
- **Ý tưởng Biến đổi để trị (Thay đổi biểu diễn - Representation Change):** Duy trì cấu trúc cây luôn luôn ở trạng thái cân bằng sau mỗi thao tác chèn hoặc xóa, đảm bảo chiều cao $h \in O(\log n)$ trong mọi trường hợp.

---

### 3.2. Cây AVL (Adelson-Velsky & Landis, 1962)

#### Định nghĩa và Hệ số cân bằng
Một cây tìm kiếm nhị phân được gọi là **Cây AVL** nếu tại mọi nút $v$ trong cây, độ chênh lệch chiều cao giữa cây con trái và cây con phải không vượt quá 1:
$$\text{BalanceFactor}(v) = h(v.\text{left}) - h(v.\text{right}) \in \{-1, 0, 1\}$$
*(Quy ước: Cây rỗng có chiều cao $h = -1$, nút lá có chiều cao $h = 0$).*

#### Bốn phép quay tái cân bằng (AVL Rotations)
Khi chèn một khóa mới vào cây AVL, hệ số cân bằng của một số nút tổ tiên có thể trở thành $+2$ hoặc $-2$. Ta tìm nút mất cân bằng thấp nhất (gần nút mới chèn nhất) và thực hiện đúng một trong bốn phép quay cục bộ:

1. **Phép quay đơn phải (Single Right Rotation - Quay R hay LL):**
   - Xảy ra khi chèn vào cây con **trái** của con **trái** (nút mất cân bằng có $BF = +2$, con trái có $BF = +1$).
   - Nút con trái $L$ được kéo lên làm gốc mới, gốc cũ $R$ trở thành con phải của $L$.

```text
       r (+2)                     L (0)
      /    \                     /     \
     L (+1) T3      ──>        T1       r (0)
    / \                                / \
   T1  T2                             T2  T3
```

2. **Phép quay đơn trái (Single Left Rotation - Quay L hay RR):**
   - Xảy ra khi chèn vào cây con **phải** của con **phải** (nút mất cân bằng có $BF = -2$, con phải có $BF = -1$).
   - Nút con phải $R$ được kéo lên làm gốc mới, gốc cũ $L$ trở thành con trái của $R$.

```text
     r (-2)                       R (0)
    /    \                       /     \
   T1     R (-1)    ──>        r (0)    T3
         / \                  / \
        T2  T3               T1  T2
```

3. **Phép quay kép trái-phải (Double Left-Right Rotation - Quay LR):**
   - Xảy ra khi chèn vào cây con **phải** của con **trái** (nút mất cân bằng có $BF = +2$, con trái có $BF = -1$).
   - Thực hiện quay trái tại con trái, sau đó quay phải tại gốc cũ.

```text
       r (+2)                  r (+2)                   C (0)
      /    \                  /    \                   /     \
     L (-1) T4      ──>      C      T4      ──>       L       r
    / \                     / \                      / \     / \
   T1  C                   L   T3                   T1 T2   T3 T4
      / \                 / \
     T2  T3              T1  T2
```

4. **Phép quay kép phải-trái (Double Right-Left Rotation - Quay RL):**
   - Xảy ra khi chèn vào cây con **trái** của con **phải** (nút mất cân bằng có $BF = -2$, con phải có $BF = +1$).
   - Thực hiện quay phải tại con phải, sau đó quay trái tại gốc cũ.

#### Chiều cao giới hạn của Cây AVL
Gọi $N(h)$ là số nút ít nhất của một cây AVL có chiều cao $h$:
$$N(0) = 1, \quad N(1) = 2$$
$$N(h) = N(h - 1) + N(h - 2) + 1 \quad \forall h \ge 2$$
Dãy $N(h)$ tăng tương tự dãy Fibonacci: $N(h) = F(h + 3) - 1$.
Từ công thức Binet, ta chứng minh được chiều cao tối đa của cây AVL chứa $n$ nút là:
$$h < 1.4404 \log_2(n + 2) - 0.3277 \in \Theta(\log n)$$
Do đó, các thao tác tìm kiếm, chèn, xóa trên cây AVL luôn đảm bảo thời gian chạy **$\Theta(\log n)$ trong trường hợp xấu nhất**.

---

### 3.3. Cây 2-3 (Hopcroft, 1970)

#### Định nghĩa và Tính chất hoàn hảo
Cây 2-3 là một cây tìm kiếm đa hướng thỏa mãn:
1. **Mọi nút lá đều nằm ở cùng một mức (chiều sâu hoàn hảo).**
2. Mỗi nút nội có thể là:
   - **Nút 2 (2-node):** Chứa 1 khóa $k$ và có 2 con. Mọi khóa ở cây con trái $< k <$ mọi khóa ở cây con phải.
   - **Nút 3 (3-node):** Chứa 2 khóa $k_1 < k_2$ và có 3 con. Cây con trái $< k_1 <$ cây con giữa $< k_2 <$ cây con phải.

#### Thuật toán Chèn vào Cây 2-3
1. Luôn luôn chèn khóa mới vào một **nút lá**.
2. Nếu nút lá là nút 2 (chỉ có 1 khóa): Đơn giản bổ sung khóa mới vào nút lá đó để biến nó thành nút 3 $\implies$ Kết thúc.
3. Nếu nút lá là nút 3 (đã có 2 khóa): Việc thêm khóa tạo ra trạng thái quá tải tạm thời với 3 khóa $k_{\min} < k_{\text{mid}} < k_{\max}$.
   - Nút bị **tách đôi (split)** thành hai nút 2 chứa $k_{\min}$ và $k_{\max}$.
   - Khóa giữa $k_{\text{mid}}$ được **đẩy lên nút cha**.
   - Quá trình đẩy khóa lên nút cha tiếp tục đệ quy lên trên. Nếu gốc bị tách, một gốc mới được tạo ra $\implies$ **Chiều cao của cây tăng thêm 1 từ gốc lên trên!**

#### Chiều cao của Cây 2-3:
$$\lfloor \log_3(n + 1) \rfloor \le h \le \lfloor \log_2(n + 1) \rfloor$$
Tìm kiếm, chèn và xóa luôn chạy trong thời gian $\Theta(\log n)$.

---

## PHẦN II. GIẢI CHI TIẾT 100% BÀI TẬP EXERCISES 6.3 (BÀI 1 ĐẾN BÀI 10)

### Bài 6.3.1: Kiểm tra tính hợp lệ của Cây AVL
> **Đề bài:**
> Cho các cây nhị phân sau. Hãy xác định cây nào là cây AVL hợp lệ, cây nào không và giải thích lý do:
> a. Cây chỉ có một nút gốc.
> b. Cây có 3 nút: gốc có con trái, con trái có con trái (dạng đường thẳng $3 \to 2 \to 1$).
> c. Cây tìm kiếm nhị phân gồm các khóa $10, 5, 15, 2, 7, 12, 20$.

**Lời giải chi tiết:**
- **a. Cây chỉ có một nút gốc:**
  - Cây con trái rỗng ($h = -1$), cây con phải rỗng ($h = -1$).
  - Hệ số cân bằng: $BF = (-1) - (-1) = 0 \in \{-1, 0, 1\}$.
  - Thỏa mãn tính chất BST $\implies$ **Là cây AVL hợp lệ**.
- **b. Cây có dạng $3 \to 2 \to 1$ (Left-Left degenerate):**
  - Tại nút 1: $BF = 0$.
  - Tại nút 2: Con trái có chiều cao 0, con phải rỗng ($-1$) $\implies BF = 0 - (-1) = +1$.
  - Tại nút 3 (gốc): Cây con trái có chiều cao 1 (chứa nút 2 và 1), cây con phải rỗng ($-1$) $\implies BF = 1 - (-1) = +2 \notin \{-1, 0, 1\}$.
  - $\implies$ **Không phải cây AVL** (bị mất cân bằng tại nút gốc, cần thực hiện phép quay phải R).
- **c. Cây gồm các khóa $10, 5, 15, 2, 7, 12, 20$:**
  - Gốc 10 có con trái là 5 (với con 2, 7) và con phải là 15 (với con 12, 20).
  - Cả cây con trái và phải đều là cây nhị phân đầy đủ chiều cao 1 $\implies BF(\text{gốc}) = 1 - 1 = 0$.
  - Tại nút 5: $BF = 0 - 0 = 0$. Tại nút 15: $BF = 0 - 0 = 0$.
  - Tại các nút lá 2, 7, 12, 20: $BF = 0$.
  - Mọi nút đều có $BF = 0$ và thỏa mãn tính chất BST $\implies$ **Là cây AVL hoàn hảo**.

---

### Bài 6.3.2: Dựng cây AVL có số nút nhỏ nhất với chiều cao cho trước (Fibonacci Trees)
> **Đề bài:**
> a. Dựng cây AVL có chiều cao $h = 1, 2, 3, 4$ với số lượng nút ít nhất có thể (gọi là cây Fibonacci).
> b. Xác định số lượng nút tối thiểu $N(h)$ tương ứng.

**Lời giải chi tiết:**
- **a. và b. Công thức truy hồi số nút tối thiểu:**
  $$N(h) = N(h - 1) + N(h - 2) + 1$$
  - $h = 0$: Cây gồm đúng 1 nút $\implies N(0) = 1$.
  - $h = 1$: Gốc có 1 con $\implies N(1) = 1 + 1 = 2$ nút.
  - $h = 2$: Gốc có một cây con chiều cao 1 ($N(1) = 2$) và một cây con chiều cao 0 ($N(0) = 1$) $\implies N(2) = 2 + 1 + 1 = 4$ nút.
  - $h = 3$: Gốc có cây con chiều cao 2 ($N(2) = 4$) và cây con chiều cao 1 ($N(1) = 2$) $\implies N(3) = 4 + 2 + 1 = 7$ nút.
  - $h = 4$: Gốc có cây con chiều cao 3 ($N(3) = 7$) và cây con chiều cao 2 ($N(2) = 4$) $\implies N(4) = 7 + 4 + 1 = 12$ nút.
- **Cấu trúc hình học cây Fibonacci:**
  - Tại mọi nút nội, một cây con luôn có chiều cao lớn hơn cây con kia đúng 1 ($BF = \pm 1$ tại mọi nút không phải lá).

---

### Bài 6.3.3: Đối xứng gương của các phép quay AVL
> **Đề bài:**
> Mô tả chi tiết phép quay đơn trái L (quay RR) và phép quay kép phải-trái RL dưới dạng hình ảnh đối xứng gương của phép quay đơn phải R (quay LL) và phép quay kép trái-phải LR.

**Lời giải chi tiết:**
1. **Phép quay đơn L (RR) là đối xứng gương của quay R (LL):**
   - Đổi vai trò của con Trái (Left) và con Phải (Right).
   - Nút mất cân bằng $A$ có $BF(A) = -2$, con phải $B$ có $BF(B) \le 0$.
   - Con trái của $B$ được gán làm con phải của $A$.
   - $A$ trở thành con trái của $B$. $B$ trở thành gốc mới của cây con.

2. **Phép quay kép RL là đối xứng gương của quay LR:**
   - Nút mất cân bằng $A$ có $BF(A) = -2$, con phải $B$ có $BF(B) = +1$ (chèn vào cây con trái của con phải).
   - Gọi $C$ là con trái của $B$.
   - Thực hiện quay phải (R) tại $B$, đưa $C$ lên làm con phải của $A$.
   - Sau đó thực hiện quay trái (L) tại $A$, đưa $C$ lên làm gốc mới.

---

### Bài 6.3.4: Chèn dãy khóa vào Cây AVL từng bước
> **Đề bài:**
> Chèn lần lượt các khóa sau vào một cây AVL ban đầu rỗng và chỉ rõ các phép quay cần thực hiện:
> $$5, 6, 8, 3, 2, 4, 7$$

**Lời giải chi tiết từng bước:**
1. **Chèn 5:** Cây có 1 nút: $(5)$.
2. **Chèn 6:** $6 > 5 \implies$ con phải của 5. Cây: $5 - 6$. $BF(5) = -1$. Cân bằng.
3. **Chèn 8:** $8 > 6 \implies$ con phải của 6. Cây: $5 \to 6 \to 8$.
   - $BF(5) = -2, BF(6) = -1 \implies$ Vi phạm nhánh RR tại nút 5.
   - **Thực hiện phép quay đơn trái (L / RR) tại nút 5:**
   - 6 lên làm gốc, 5 là con trái, 8 là con phải.
   - Cây sau bước 3: Gốc 6, con trái 5, con phải 8. (Hoàn toàn cân bằng).
4. **Chèn 3:** $3 < 6, 3 < 5 \implies 3$ là con trái của 5. Cây cân bằng ($BF(6) = +1, BF(5) = +1$).
5. **Chèn 2:** $2 < 3 \implies 2$ là con trái của 3.
   - Xét đường đi từ 2 lên gốc: $BF(3) = +1$, $BF(5) = +2, BF(3) = +1 \implies$ Mất cân bằng LL tại nút 5!
   - **Thực hiện phép quay đơn phải (R / LL) tại nút 5:**
   - Nút 3 lên thay 5, 2 là con trái của 3, 5 là con phải của 3.
   - Cây sau bước 5: Gốc 6, con trái là cây $(3 \text{ với con } 2, 5)$, con phải là 8.
6. **Chèn 4:** $4 < 6, 4 > 3, 4 < 5 \implies 4$ là con trái của 5.
   - Hệ số cân bằng: $BF(5) = +1, BF(3) = -1, BF(6) = 2 - 1 = +1$. Mọi nút đều có $|BF| \le 1 \implies$ Cây cân bằng, không cần quay!
7. **Chèn 7:** $7 > 6, 7 < 8 \implies 7$ là con trái của 8.
   - Hệ số cân bằng: $BF(8) = +1, BF(6) = 3 - 2 = +1$.
   - Mọi nút đều có $|BF| \le 1$.
- **Cấu trúc cây AVL cuối cùng:**
  - Gốc: **6**
  - Cây con trái: Nút 3; con trái của 3 là **2**; con phải của 3 là **5**; con trái của 5 là **4**.
  - Cây con phải: Nút **8**; con trái của 8 là **7**.
  - Chiều cao cây: $h = 3$. Tổng số nút: $7$. Cân bằng hoàn hảo!

---

### Bài 6.3.5: Thuật toán tìm khóa nhỏ nhất và lớn nhất trong Cây AVL
> **Đề bài:**
> a. Trình bày thuật toán tìm khóa nhỏ nhất và khóa lớn nhất trong cây AVL. Phân tích độ phức tạp thời gian.
> b. Có phải trong mọi cây AVL, khóa nhỏ nhất và lớn nhất luôn nằm ở mức sâu nhất (mức lá xa nhất) không?

**Lời giải chi tiết:**
- **a. Thuật toán:**
  - Vì cây AVL là một cây tìm kiếm nhị phân (BST):
    + Khóa nhỏ nhất luôn là nút tận cùng bên trái (đi theo con trỏ `left` liên tục từ gốc cho đến khi gặp nút không có con trái).
    + Khóa lớn nhất luôn là nút tận cùng bên phải (đi theo con trỏ `right` liên tục từ gốc cho đến khi gặp nút không có con phải).
  - Độ phức tạp thời gian: Số bước đi bằng độ sâu của nút, không vượt quá chiều cao $h$ của cây.
    Vì $h < 1.4404 \log_2 n \implies T(n) \in O(\log n)$.
- **b. Trả lời: KHÔNG.**
  - Phản ví dụ: Xét cây AVL gồm 3 nút: gốc 5, con trái 2, con phải 8.
    Bây giờ chèn 1 vào: 1 là con trái của 2. Sau đó chèn 0: 0 là con trái của 1 $\implies$ sau khi quay, nút nhỏ nhất có thể nằm ở lá sâu nhất, nhưng nếu ta chèn nút vào nhánh phải, nhánh phải có thể sâu hơn nhánh trái!
  - Cụ thể: Xét cây AVL có gốc 10, con trái là 5 (không có con), con phải là 15 (với con 12 và 20).
    Chiều cao nhánh trái là 1 (nút 5 ở mức 1), chiều cao nhánh phải là 2 (nút 12, 20 ở mức 2).
    Khóa nhỏ nhất là 5, nằm ở **Mức 1**, trong khi mức sâu nhất của cây là **Mức 2**!

---

### Bài 6.3.6: So sánh chi phí tìm kiếm trung bình: BST ngẫu nhiên vs. Cây AVL
> **Đề bài:**
> So sánh số phép so sánh trung bình khi tìm kiếm thành công trong một cây tìm kiếm nhị phân ngẫu nhiên (Random BST) và một cây AVL cùng chứa $n$ khóa.

**Lời giải chi tiết:**
- **Trong BST ngẫu nhiên:**
  Theo kết quả giải tích của Hibbard và Knuth, chiều cao trung bình là $O(\log n)$ và số phép so sánh trung bình khi tìm kiếm thành công là:
  $$C_{\text{BST}}^{\text{avg}}(n) \approx 2 \ln n \approx 1.386 \log_2 n$$
- **Trong Cây AVL:**
  Do cây AVL luôn duy trì độ lệch chiều cao $\le 1$, cấu trúc cây rất gần với cây nhị phân đầy đủ. Chiều cao trung bình của cây AVL xấp xỉ $1.01 \log_2 n$, và số phép so sánh trung bình khi tìm kiếm thành công là:
  $$C_{\text{AVL}}^{\text{avg}}(n) \approx \log_2 n + c \approx 1.00 \log_2 n$$
- **Kết luận:** Cây AVL giúp tiết kiệm khoảng $28\%$ số phép so sánh trung bình so với BST ngẫu nhiên, và đặc biệt loại bỏ hoàn toàn nguy cơ thoái hóa thành $O(n)$ trong trường hợp xấu nhất.

---

### Bài 6.3.7: Dựng Cây 2-3 từ dãy khóa
> **Đề bài:**
> Chèn lần lượt các khóa sau vào một Cây 2-3 ban đầu rỗng:
> $$9, 5, 8, 3, 2, 4, 7$$

**Lời giải chi tiết từng bước:**
1. **Chèn 9:** Cây có 1 nút 2: $[9]$.
2. **Chèn 5:** Nút lá còn chỗ, thêm 5 vào: Nút 3: $[5, 9]$.
3. **Chèn 8:** Nút $[5, 9]$ quá tải với 3 khóa $\{5, 8, 9\}$.
   - Khóa giữa 8 được đẩy lên làm gốc mới.
   - Hai khóa 5 và 9 tách thành hai nút 2 con.
   - Cây sau bước 3: Gốc $[8]$, con trái $[5]$, con phải $[9]$.
4. **Chèn 3:** $3 < 8 \implies$ xuống con trái $[5]$. Nút $[5]$ là nút 2, nhận thêm 3 thành nút 3: $[3, 5]$.
   - Cây sau bước 4: Gốc $[8]$, con trái $[3, 5]$, con phải $[9]$.
5. **Chèn 2:** $2 < 8 \implies$ xuống con trái $[3, 5]$.
   - Nút $[3, 5]$ quá tải với $\{2, 3, 5\}$.
   - Khóa giữa 3 được đẩy lên gốc $[8]$. Gốc $[8]$ là nút 2 nên nhận thêm 3 thành $[3, 8]$.
   - Khóa 2 và 5 tách thành hai nút 2 con: con trái $[2]$, con giữa $[5]$. Con phải vẫn là $[9]$.
   - Cây sau bước 5: Gốc $[3, 8]$, 3 con lần lượt là $[2]$, $[5]$, $[9]$. (Chiều cao $h = 1$).
6. **Chèn 4:** $3 < 4 < 8 \implies$ vào con giữa $[5]$. Nút $[5]$ nhận thêm 4 thành nút 3: $[4, 5]$.
   - Cây sau bước 6: Gốc $[3, 8]$, 3 con là $[2]$, $[4, 5]$, $[9]$.
7. **Chèn 7:** $3 < 7 < 8 \implies$ vào con giữa $[4, 5]$.
   - Nút con giữa quá tải với $\{4, 5, 7\}$. Khóa giữa 5 được đẩy lên gốc.
   - Nhưng gốc $[3, 8]$ đã là nút 3! Gốc quá tải với $\{3, 5, 8\}$.
   - Gốc tách đôi: Khóa giữa 5 được đẩy lên làm **gốc mới của toàn cây**.
   - Gốc cũ tách thành hai nút 2: nút $[3]$ (quản lý con $[2]$ và $[4]$) và nút $[8]$ (quản lý con $[7]$ và $[9]$).
- **Kết quả Cây 2-3 cuối cùng (Chiều cao tăng lên $h = 2$):**
  - **Gốc:** $[5]$
  - **Mức 1:** Con trái $[3]$, con phải $[8]$.
  - **Mức 2 (Các lá hoàn hảo cùng mức):**
    + Con của $[3]$: con trái $[2]$, con phải $[4]$.
    + Con của $[8]$: con trái $[7]$, con phải $[9]$.

---

### Bài 6.3.8: Nhận định về việc xóa trên Cây 2-3
> **Đề bài:**
> Đúng hay sai: "Việc xóa một khóa khỏi cây 2-3 luôn luôn làm giảm chiều cao của cây đi 1 đơn vị"?

**Lời giải chi tiết:**
- **Khẳng định: SAI (FALSE).**
- **Phản ví dụ:**
  - Xét cây 2-3 có gốc $[3, 8]$ (nút 3) và 3 con lá là $[2], [5], [9]$. Chiều cao của cây là $h = 1$.
  - Ta thực hiện xóa khóa 5: Nút giữa bị rỗng, mượn khóa hoặc gộp với nút bên cạnh. Gốc chuyển từ nút 3 $[3, 8]$ thành nút 2 $[8]$, con trái thành $[2, 3]$, con phải là $[9]$.
  - Chiều cao của cây sau khi xóa **vẫn giữ nguyên là $h = 1$**!
  - Chiều cao của cây 2-3 chỉ giảm đi 1 khi và chỉ khi thao tác xóa làm tiêu biến hoàn toàn cả hai khóa của nút gốc (nút gốc rỗng và hai con của nó gộp lại thành gốc mới).

---

### Bài 6.3.9: Vị trí của khóa nhỏ nhất và lớn nhất trong Cây 2-3
> **Đề bài:**
> Trong một cây 2-3 bất kỳ, khóa nhỏ nhất và khóa lớn nhất được định vị ở đâu?

**Lời giải chi tiết:**
- **Khóa nhỏ nhất:** Luôn luôn là **khóa đầu tiên của nút lá ngoài cùng bên trái** của cây 2-3 (đi theo con trỏ con trái nhất liên tục từ gốc cho đến khi chạm nút lá).
- **Khóa lớn nhất:** Luôn luôn là **khóa cuối cùng của nút lá ngoài cùng bên phải** của cây 2-3 (đi theo con trỏ con phải nhất liên tục từ gốc cho đến khi chạm nút lá).
- Vì tất cả các lá trong cây 2-3 đều nằm ở cùng một độ sâu $h$, hai khóa cực trị này luôn luôn nằm ở mức sâu nhất của cây!

---

### Bài 6.3.10: Biến đổi Cây 2-3 thành Cây Đỏ-Đen (Red-Black Trees equivalence)
> **Đề bài:**
> Giải thích cách ánh xạ tương đương 1-1 giữa một Cây 2-3 và một Cây Đỏ-Đen (Red-Black Tree).

**Lời giải chi tiết:**
- Cây Đỏ-Đen (Sedgewick, Guibas, 1978) là một dạng biểu diễn nhị phân đẳng cấu của Cây 2-3 (hoặc 2-3-4):
  1. **Nút 2 trong cây 2-3 (chứa 1 khóa $A$):** Biểu diễn bằng một nút đen bình thường trong cây đỏ-đen với hai con.
  2. **Nút 3 trong cây 2-3 (chứa 2 khóa $A < B$):** Biểu diễn bằng một cạnh đỏ nối giữa hai nút nhị phân:
     - Nút $B$ mang màu đen, nút $A$ mang màu đỏ và là con trái của $B$ (trong Left-Leaning Red-Black Tree - LLRB).
     - Cạnh đỏ biểu thị rằng $A$ và $B$ thực chất thuộc về **cùng một nút 3 logic** trong cây 2-3!
  3. **Tính chất cân bằng màu đen (Black Height):** Vì mọi lá trong cây 2-3 ở cùng một mức, mọi đường đi từ gốc đến lá trong cây đỏ-đen đều có **cùng số lượng nút đen**!



---


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



---


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



---


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



---
# TỔNG KẾT TOÀN DIỆN CHƯƠNG 6 (SUMMARY)

1. **Bản chất hai giai đoạn:** Biến đổi thể hiện bài toán ban đầu sang một dạng thuận lợi hơn, sau đó giải quyết thể hiện mới để thu được nghiệm.
2. **Ba biến thể cốt lõi:**
   - **Biến đổi thể hiện (Instance Simplification):** Sắp xếp sơ bộ (Presorting) giải Element Uniqueness và Mode trong $\Theta(n \log n)$; Khử Gauss biến hệ phương trình thành tam giác trên trong $\Theta(n^3)$.
   - **Thay đổi biểu diễn (Representation Change):** Cây AVL và Cây 2-3 duy trì cân bằng đảm bảo tìm kiếm/chèn/xóa trong $\Theta(\log n)$; Đống (Heap) cho phép Heapify tuyến tính $\Theta(n)$ và Heapsort tại chỗ $\Theta(n \log n)$; Luật Horner tính đa thức trong đúng $n$ phép nhân; Lũy thừa nhị phân tính $a^n$ trong $\Theta(\log n)$.
   - **Thu gọn bài toán (Problem Reduction):** Tính BCNN qua UCLN; Đếm đường đi qua lũy thừa ma trận kề $A^k$; Thu gọn về Quy hoạch tuyến tính (Simplex).
