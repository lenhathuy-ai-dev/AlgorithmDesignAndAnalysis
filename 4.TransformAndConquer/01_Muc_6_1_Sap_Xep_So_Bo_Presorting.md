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
