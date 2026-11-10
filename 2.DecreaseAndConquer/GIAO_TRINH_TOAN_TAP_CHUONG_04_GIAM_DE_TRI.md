# GIÁO TRÌNH TOÀN TẬP PHÂN TÍCH VÀ THIẾT KẾ THUẬT TOÁN
# CHƯƠNG 4: CHIẾN LƯỢC GIẢM ĐỂ TRỊ (DECREASE-AND-CONQUER)
*Tài liệu tham chiếu chuẩn hóa: A. Levitin, "Introduction to the Design and Analysis of Algorithms", Addison Wesley, 3rd Edition, 2011.*  
*Phạm vi giáo trình: Toàn bộ Chương 4 từ trang 131 đến trang 167.*  
*Bao gồm: Toàn bộ lý thuyết, mã giả chuẩn hóa cấu trúc, phân tích độ phức tạp chi tiết và 100% lời giải bài tập (62/62 bài).*  

---

# CHUYÊN ĐỀ 00: TỔNG QUAN CHIẾN LƯỢC GIẢM ĐỂ TRỊ (DECREASE-AND-CONQUER)
*Tài liệu tham chiếu: A. Levitin, "Introduction to the Design and Analysis of Algorithms", 3rd Edition, Chương 4, Trang 131–134.*

---

## 1. TRIẾT LÝ VÀ BẢN CHẤT CHIẾN LƯỢC

Chiến lược **Giảm để trị (Decrease-and-Conquer)** là một kỹ thuật thiết kế thuật toán tổng quát và cực kỳ mạnh mẽ, dựa trên việc khai thác **mối quan hệ cấu trúc giữa nghiệm của một bài toán kích thước $n$ với nghiệm của một thể hiện con (sub-instance) có kích thước nhỏ hơn**.

```mermaid
flowchart TD
    A["Bài toán ban đầu<br>Kích thước n"] -->|"Giảm kích thước<br>(Decrease)"| B["Bài toán con duy nhất<br>Kích thước n' < n"]
    B -->|"Giải quyết<br>(Conquer)"| C["Nghiệm của<br>bài toán con"]
    C -->|"Mở rộng / Tổng hợp<br>(Extend)"| D["Nghiệm của<br>bài toán ban đầu"]
```

### Hai phương thức triển khai cốt lõi:
1. **Tiếp cận từ trên xuống (Top-down - Đệ quy):**
   - Tự nhiên xuất phát từ công thức toán học hoặc định nghĩa đệ quy.
   - Gọi đệ quy để giải bài toán kích thước nhỏ hơn cho đến khi chạm trường hợp cơ sở (base case), sau đó quay lui để dựng nghiệm hoàn chỉnh.
   - *Ưu điểm:* Cú pháp trong sáng, biểu diễn trực tiếp tư tưởng toán học.
   - *Nhược điểm:* Chi phí quản lý ngăn xếp gọi hàm (call stack overhead), có nguy cơ tràn bộ nhớ nếu kích thước giảm chậm và $n$ quá lớn.

2. **Tiếp cận từ dưới lên (Bottom-up - Lặp):**
   - Bắt đầu giải bài toán từ thể hiện nhỏ nhất (trường hợp cơ sở $n=0$ hoặc $n=1$).
   - Sử dụng vòng lặp để mở rộng dần nghiệm từ kích thước nhỏ lên kích thước lớn hơn cho đến khi đạt kích thước $n$.
   - *Ưu điểm:* Không tốn bộ nhớ ngăn xếp đệ quy, tốc độ thực thi thường vượt trội so với đệ quy.

---

## 2. BA BIẾN THỂ CHÍNH CỦA GIẢM ĐỂ TRỊ

Theo phân loại kinh điển của Levitin, chiến lược Giảm để trị được chia thành ba biến thể chính tùy thuộc vào quy luật thu nhỏ kích thước của bài toán:

```mermaid
mindmap
  root((Giảm để trị))
    Giảm theo hằng số<br>Decrease by a constant
      Thường giảm 1: n -> n - 1
      Insertion Sort
      Topological Sort
      Sinh hoán vị, tập con
    Giảm theo tỉ lệ hằng số<br>Decrease by a constant factor
      Thường giảm 1 nửa: n -> n / 2
      Binary Search
      Bài toán Đồng xu giả
      Phép nhân nông dân Nga
      Bài toán Josephus
    Giảm theo kích thước biến thiên<br>Variable size decrease
      Kích thước giảm linh hoạt
      Thuật toán Euclid GCD
      Quickselect
      Interpolation Search
      Cây tìm kiếm nhị phân BST
      Trò chơi Nim
```

### 2.1. Giảm theo một hằng số (Decrease-by-a-Constant)
- Kích thước bài toán tại mỗi bước giảm đi một hằng số cố định $c$. Trong thực tế, phổ biến nhất là giảm 1 đơn vị ($c = 1$): kích thước giảm từ $n$ xuống $n - 1$.
- **Ví dụ toán học cơ sở:** Tính lũy thừa $a^n$ ($n$ nguyên không âm):
  $$a^n = \begin{cases} a^{n-1} \cdot a & \text{nếu } n > 0 \\ 1 & \text{nếu } n = 0 \end{cases}$$
- **Phương trình độ phức tạp điển hình:**
  $$T(n) = T(n - 1) + f(n)$$
  - Nếu công việc mở rộng $f(n) = \Theta(1) \implies T(n) = \Theta(n)$ (ví dụ: duyệt danh sách).
  - Nếu công việc mở rộng $f(n) = \Theta(n) \implies T(n) = \Theta(n^2)$ (ví dụ: Sắp xếp chèn - Insertion Sort).

### 2.2. Giảm theo một tỉ lệ hằng số (Decrease-by-a-Constant-Factor)
- Kích thước bài toán tại mỗi bước giảm đi một thừa số cố định $b > 1$. Phổ biến nhất là giảm đi một nửa ($b = 2$): kích thước giảm từ $n$ xuống $\lfloor n/2 \rfloor$.
- **Ví dụ toán học cơ sở:** Tính lũy thừa $a^n$ bằng phương pháp bình phương liên tiếp:
  $$a^n = \begin{cases} (a^{n/2})^2 & \text{nếu } n \text{ chẵn và } n > 0 \\ (a^{(n-1)/2})^2 \cdot a & \text{nếu } n \text{ lẻ} \\ 1 & \text{nếu } n = 0 \end{cases}$$
- **Phương trình độ phức tạp điển hình:**
  $$T(n) = T(n/b) + f(n)$$
  - Khi $f(n) = \Theta(1)$ (ví dụ Tìm kiếm nhị phân - Binary Search):
    $$T(n) = T(n/2) + \Theta(1) \implies T(n) = \Theta(\log n)$$
  - Kỹ thuật này đem lại bước nhảy vọt về tốc độ, chuyển đổi bài toán từ thời gian tuyến tính $\Theta(n)$ về thời gian logarit $\Theta(\log n)$.

### 2.3. Giảm theo kích thước biến thiên (Variable-Size-Decrease)
- Lượng giảm kích thước không cố định mà thay đổi linh hoạt sau mỗi bước lặp, phụ thuộc vào đặc thù của giá trị dữ liệu hoặc cấu trúc hiện tại.
- **Ví dụ toán học cơ sở:** Thuật toán Euclid tìm ước số chung lớn nhất $\gcd(m, n)$:
  $$\gcd(m, n) = \gcd(n, m \bmod n)$$
  Số bước giảm và độ lớn của $m \bmod n$ hoàn toàn biến thiên theo từng cặp số cụ thể.
- **Các thuật toán tiêu biểu:**
  - **Quickselect:** Kích thước mảng con phụ thuộc vào vị trí của phần tử chốt (pivot) sau khi phân hoạch.
  - **Interpolation Search:** Kích thước khoảng tìm kiếm giảm phụ thuộc vào giá trị nội suy.
  - **Thao tác trên cây BST:** Kích thước cây con phụ thuộc vào độ cân bằng và độ cao của từng nhánh.

---

## 3. SO SÁNH GIẢM ĐỂ TRỊ VỚI CÁC CHIẾN LƯỢC LIÊN CẬN

Nhiều tài liệu thường nhầm lẫn giữa **Giảm để trị (Decrease-and-Conquer)** và **Chia để trị (Divide-and-Conquer)**. Bảng so sánh dưới đây phân định ranh giới một cách tường minh:

| Tiêu chí | Giảm để trị (Decrease-and-Conquer) | Chia để trị (Divide-and-Conquer) | Quy hoạch động (Dynamic Programming) |
| :--- | :--- | :--- | :--- |
| **Số lượng bài toán con** | **Đúng 1** bài toán con duy nhất tại mỗi bước. | **Từ 2** bài toán con độc lập trở lên ($a \ge 2$). | Nhiều bài toán con gối nhau (overlapping subproblems). |
| **Cơ chế chia** | Loại bỏ một phần kích thước (bỏ $1$ phần tử hoặc bỏ $1/2$ mảng). | Chia toàn bộ dữ liệu thành các phần riêng biệt để giải tất cả. | Chia thành các trạng thái con và lưu bảng để tái sử dụng. |
| **Giai đoạn tổng hợp** | Đơn giản: mở rộng nghiệm của 1 bài toán con (ví dụ: chèn thêm 1 phần tử). | Phức tạp: trộn/hợp nhất nghiệm từ nhiều bài toán con độc lập. | Tối ưu hóa: so sánh và chọn nghiệm tốt nhất theo nguyên lý Bellman. |
| **Thuật toán đại diện** | Binary Search, Insertion Sort, Quickselect. | Merge Sort, Quicksort, Strassen. | Dãy con tăng dài nhất, Ba lô 0/1, Floyd-Warshall. |

> [!TIP]
> **Quy tắc vàng phân biệt:** Nếu sau bước phân rã, thuật toán chỉ cần gọi đệ quy (hoặc xét tiếp) trên **MỘT** bài toán con duy nhất thì đó chắc chắn là **Giảm để trị**. Nếu phải giải quyết từ hai bài toán con trở lên thì đó là **Chia để trị**.


---

# CHUYÊN ĐỀ 01: SẮP XẾP CHÈN (INSERTION SORT) & LỜI GIẢI BÀI TẬP 4.1
*Tài liệu tham chiếu: A. Levitin, "Introduction to the Design and Analysis of Algorithms", 3rd Edition, Chương 4, Mục 4.1, Trang 134–138.*

---

## PHẦN I. LÝ THUYẾT VÀ MÃ GIẢ CHUẨN HÓA

### 1.1. Phát biểu bài toán hình thức
- **Đầu vào:** Mảng $A[0..n-1]$ gồm $n$ phần tử có thể so sánh được với quan hệ thứ tự toàn phần $\le$.
- **Đầu ra:** Mảng $A[0..n-1]$ đã được hoán vị sao cho:
  $$A[0] \le A[1] \le A[2] \le \dots \le A[n-1]$$

### 1.2. Bản chất ý tưởng thiết kế (Chiến lược Giảm 1 - Decrease-by-one)
Sắp xếp chèn áp dụng hoàn hảo kỹ thuật **Giảm 1 từ dưới lên (Bottom-up)**:
1. Xét bài toán cơ sở: Mảng con $A[0..0]$ có kích thước bằng 1 luôn luôn đã có thứ tự.
2. Giả sử mảng con $A[0..i-1]$ (kích thước $i$) đã được sắp xếp tăng dần. Để giải quyết bài toán kích thước $i+1$ ($A[0..i]$), ta cần chèn phần tử $A[i]$ vào đúng vị trí của nó trong đoạn $A[0..i-1]$.
3. **Cơ chế chèn:** Quét từ phải sang trái (từ $j = i-1$ lùi dần về 0). Khi gặp phần tử $A[j] > A[i]$, ta dời $A[j]$ sang phải một vị trí ($A[j+1] \leftarrow A[j]$) để tạo khe trống. Vòng quét dừng lại ngay khi gặp phần tử đầu tiên $A[j] \le A[i]$ hoặc khi chạm đầu mảng ($j < 0$). Khi đó, ta đặt giá trị cần chèn vào vị trí $A[j+1]$.

```mermaid
flowchart LR
    subgraph Da_Sap_Xep["Đoạn A[0..i-1] đã có thứ tự"]
        direction LR
        A0["A[0]"] --- A1["..."] --- Aj["A[j] ≤ v"] --- Aj1["A[j+1] > v (Dời phải)"]
    end
    v["v = A[i] (Cần chèn)"] -.->|"Đặt vào vị trí j + 1"| Aj1
```

### 1.3. Mã giả chuẩn hóa cấu trúc (Structured Pseudocode)

```text
Algorithm InsertionSort(A[0..n-1])
// Mô tả: Sắp xếp mảng theo thứ tự không giảm bằng thuật toán Sắp xếp chèn
// Đầu vào: Mảng A[0..n-1] gồm n phần tử có thể so sánh được
// Đầu ra: Mảng A[0..n-1] đã được sắp xếp tăng dần

1   for i ← 1 to n - 1 do
2       v ← A[i]             // Lưu trữ phần tử hiện tại cần chèn
3       j ← i - 1            // Bắt đầu quét từ vị trí ngay trước i
4       while j ≥ 0 and A[j] > v do
5           A[j + 1] ← A[j]  // Dời phần tử lớn hơn sang phải 1 vị trí
6           j ← j - 1        // Lùi tiếp về bên trái
7       A[j + 1] ← v         // Đặt giá trị v vào vị trí thích hợp đã tìm được
```

### 1.4. Phân tích toán học độ phức tạp

- **Phép toán cơ sở (Basic operation):** Phép so sánh khóa $A[j] > v$ trong điều kiện vòng lặp `while`.
- Kích thước đầu vào: Số lượng phần tử $n$.

#### 1.4.1. Trường hợp xấu nhất (Worst-case)
- Xảy ra khi mảng ban đầu được sắp xếp theo thứ tự **giảm ngặt**: $A[0] > A[1] > \dots > A[n-1]$.
- Khi đó, tại mỗi bước $i$, giá trị $v = A[i]$ luôn nhỏ hơn tất cả các phần tử đứng trước nó. Vòng lặp `while` phải so sánh đúng $i$ lần cho đến khi $j = -1$.
- Tổng số phép so sánh khóa:
  $$C_{worst}(n) = \sum_{i=1}^{n-1} \sum_{j=0}^{i-1} 1 = \sum_{i=1}^{n-1} i = \frac{n(n-1)}{2} \approx \frac{n^2}{2} \in \Theta(n^2)$$
- Số phép gán dữ liệu dịch chuyển: Mỗi lần so sánh đều đi kèm 1 phép dời mảng cộng thêm 2 phép gán ngoài vòng lặp (gán $v$ và ghi $v$), tổng số phép gán đạt xấp xỉ $\frac{n^2}{2}$.

#### 1.4.2. Trường hợp tốt nhất (Best-case)
- Xảy ra khi mảng ban đầu **đã được sắp xếp tăng dần sẵn**: $A[0] \le A[1] \le \dots \le A[n-1]$.
- Tại mỗi bước $i$, ngay lần kiểm tra đầu tiên với $j = i-1$, ta luôn có $A[i-1] \le v$. Vòng lặp `while` chỉ so sánh đúng 1 lần và lập tức kết thúc mà không thực hiện bất kỳ phép dời nào.
- Tổng số phép so sánh khóa:
  $$C_{best}(n) = \sum_{i=1}^{n-1} 1 = n - 1 \in \Theta(n)$$
- **Nhận xét quan trọng:** Đây là ưu thế vượt trội của Insertion Sort so với Selection Sort (luôn tốn $\Theta(n^2)$ trong mọi trường hợp).

#### 1.4.3. Trường hợp trung bình (Average-case)
- Giả thiết: Dữ liệu phân bố ngẫu nhiên đồng đều, tất cả $n!$ hoán vị của $n$ phần tử phân biệt đều có xác suất xuất hiện như nhau.
- Khi chèn $A[i]$ vào mảng con đã sắp có $i$ phần tử, giá trị $v$ có thể rơi vào $i+1$ vị trí có thể có với xác suất đồng đều là $\frac{1}{i+1}$.
- Số phép so sánh trung bình ở bước $i$ xấp xỉ $\frac{i}{2}$.
- Tổng số phép so sánh trung bình:
  $$C_{avg}(n) = \sum_{i=1}^{n-1} \frac{i}{2} = \frac{1}{2} \sum_{i=1}^{n-1} i = \frac{n(n-1)}{4} \approx \frac{n^2}{4} \in \Theta(n^2)$$
- **Kết luận:** Trong trường hợp trung bình, Insertion Sort chạy **nhanh gấp đôi** so với trường hợp xấu nhất!

#### 1.4.4. Độ phức tạp không gian bộ nhớ (Space Complexity)
- Thuật toán sắp xếp tại chỗ (**in-place**): Chỉ sử dụng thêm một vài biến vô hướng ($i, j, v$).
- Độ phức tạp không gian bổ sung: $S(n) \in \Theta(1)$.

#### 1.4.5. Tính ổn định (Stability)
- **Ổn định (Stable):** Điều kiện vòng lặp là $A[j] > v$ (chỉ dời khi phần tử đứng trước LỚN HƠN NGẶT). Nếu hai phần tử có giá trị bằng nhau ($A[j] = v$), vòng lặp `while` dừng lại và $v$ được đặt ngay sau $A[j]$, do đó bảo toàn tuyệt đối thứ tự xuất hiện ban đầu của các phần tử có cùng giá trị.

---

## PHẦN II. GIẢI CHI TIẾT 100% CÁC BÀI TẬP EXERCISES 4.1 (BÀI 1 ĐẾN BÀI 12)

---

### Bài 1 (Ferrying soldiers - Vận chuyển binh lính qua sông)
> **Đề bài:**  
> Một toán gồm $n$ người lính cần vượt qua một con sông rộng và sâu mà không có cầu. Họ thấy có hai cậu bé 12 tuổi đang chèo một chiếc thuyền nhỏ gần bờ. Chiếc thuyền rất bé, chỉ có thể chở tối đa: hoặc 2 cậu bé, hoặc 1 người lính (không thể chở 1 lính và 1 cậu bé cùng lúc).  
> Làm thế nào để tất cả $n$ người lính sang được bờ bên kia và để lại chiếc thuyền cho hai cậu bé cùng sở hữu? Cần tổng cộng bao nhiêu lượt thuyền qua lại giữa hai bờ sông?

#### Lời giải chi tiết:
Áp dụng chiến lược **Giảm 1 (Decrease-by-one)**: Ta thiết kế một chu kỳ chuyển quân sao cho đúng **1 người lính** qua sông an toàn, đồng thời đưa trạng thái thuyền và 2 cậu bé về lại bờ xuất phát.

Gọi Bờ A là bờ xuất phát, Bờ B là bờ đích đến.
- **Trạng thái ban đầu:** Bờ A có $n$ người lính và 2 cậu bé (Boy 1, Boy 2); Thuyền ở Bờ A.

**Chu kỳ 4 bước để chuyển 1 người lính:**
1. **Lượt 1 (A $\to$ B):** Hai cậu bé (Boy 1 và Boy 2) cùng lên thuyền chèo sang Bờ B.  
   *(Hiện tại: Bờ A có $n$ lính; Bờ B có 2 cậu bé; Thuyền ở B).*
2. **Lượt 2 (B $\to$ A):** Cậu bé Boy 1 ở lại Bờ B, Boy 2 chèo thuyền quay về Bờ A.  
   *(Hiện tại: Bờ A có $n$ lính, 1 cậu bé; Bờ B có 1 cậu bé; Thuyền ở A).*
3. **Lượt 3 (A $\to$ B):** Một người lính lên thuyền một mình chèo sang Bờ B.  
   *(Hiện tại: Bờ A có $n-1$ lính, 1 cậu bé; Bờ B có 1 lính, 1 cậu bé; Thuyền ở B).*
4. **Lượt 4 (B $\to$ A):** Cậu bé Boy 1 từ Bờ B lên thuyền chèo quay về Bờ A đón bạn.  
   *(Hiện tại: Bờ A có $n-1$ lính, 2 cậu bé; Bờ B có 1 lính; Thuyền ở A).*

**Kết quả sau 1 chu kỳ:**
- Kích thước bài toán giảm từ $n$ lính xuống $n - 1$ lính tại bờ A.
- Chiếc thuyền và cả 2 cậu bé lại cùng có mặt tại bờ A để sẵn sàng cho chu kỳ tiếp theo!

**Tính tổng số lượt thuyền:**
- Mỗi người lính qua sông cần đúng 4 lượt thuyền.
- Với $n$ người lính, tổng số lượt thuyền cần di chuyển qua lại là:
  $$T(n) = 4n \text{ lượt}$$
- Sau $4n$ lượt, toàn bộ $n$ người lính đã ở Bờ B, và ở lượt thứ $4n$, cậu bé Boy 1 chèo thuyền về lại Bờ A, sau đó 2 cậu bé vẫn giữ quyền sở hữu chiếc thuyền. (Nếu muốn cả 2 cậu bé sang Bờ B chơi cùng toán lính thì thêm 1 lượt cuối 2 cậu bé cùng chèo qua B, tổng là $4n+1$; nhưng theo đề bài "để lại thuyền cho 2 cậu bé", sau $4n$ lượt thì 2 cậu bé có thuyền tại bờ A hoặc B tùy ý).
- **Đáp số:** $4n$ lượt di chuyển thuyền.

---

### Bài 2 (Alternating glasses - Hoán vị cốc nước ngọt xen kẽ)
> **Đề bài:**  
> a. Có $2n$ chiếc cốc xếp thành một hàng ngang kề nhau. Trong đó $n$ chiếc cốc đầu tiên chứa đầy nước soda, và $n$ chiếc cốc tiếp theo rỗng. Hãy làm cho các cốc xen kẽ theo mẫu: đầy - rỗng - đầy - rỗng... với số lần di chuyển cốc ít nhất.  
> b. Giải bài toán tương tự nếu ban đầu $2n$ cốc ($n$ đầy, $n$ rỗng) nằm ở một thứ tự ngẫu nhiên bất kỳ.

#### Lời giải chi tiết:

#### Phần a:
- Dãy ban đầu gồm $2n$ vị trí (đánh số từ 1 đến $2n$):
  $$[Đ_1, Đ_2, Đ_3, \dots, Đ_n, R_1, R_2, R_3, \dots, R_n]$$
- Mục tiêu cần đạt: Các vị trí lẻ ($1, 3, 5, \dots, 2n-1$) phải là cốc ĐẦY, các vị trí chẵn ($2, 4, 6, \dots, 2n$) phải là cốc RỖNG.
- **Ý tưởng tối ưu:** Thay vì di chuyển thân cốc, ta **rót nước** từ cốc đầy này sang cốc rỗng khác!
  - Cốc đầy ở vị trí chẵn $2, 4, 6, \dots$ đang bị sai vị trí (lẽ ra phải là rỗng).
  - Cốc rỗng ở vị trí lẻ $n+1, n+3, \dots$ (hoặc các vị trí lẻ từ cuối về) đang bị sai vị trí (lẽ ra phải là đầy).
  - Ta lấy nước từ các cốc đầy ở vị trí chẵn rót vào các cốc rỗng ở vị trí lẻ cần làm đầy:
    - Rót từ cốc ở vị trí $2$ vào cốc ở vị trí $2n - 1$.
    - Rót từ cốc ở vị trí $4$ vào cốc ở vị trí $2n - 3$.
    - Tổng quát: Rót từ cốc ở vị trí $2k$ vào cốc ở vị trí $2n - 2k + 1$.
- **Số lần rót tối thiểu:** Đúng bằng số lượng cốc đầy ở vị trí chẵn cần làm rỗng, tức là:
  $$\text{Số bước} = \lfloor n/2 \rfloor$$
  *Ví dụ minh họa:*
  - Với $n = 3$ ($Đ Đ Đ R R R$): Rót từ cốc 2 sang cốc 5 $\implies$ thu được $Đ R Đ R Đ R$. Chỉ tốn $\lfloor 3/2 \rfloor = 1$ lần rót!
  - Với $n = 4$ ($Đ Đ Đ Đ R R R R$): Rót cốc 2 sang cốc 7, cốc 4 sang cốc 5 $\implies$ tốn $\lfloor 4/2 \rfloor = 2$ lần rót.

#### Phần b (Trật tự ban đầu ngẫu nhiên):
- Đếm số vị trí chẵn hiện đang chứa nước ($c_{even}$) và số vị trí lẻ hiện đang rỗng ($e_{odd}$). Vì tổng số cốc đầy luôn bằng $n$, ta luôn có $c_{even} = e_{odd}$.
- Số lần di chuyển/rót tối thiểu chính bằng số lượng phần tử bị lệch tính chẵn lẻ:
  $$\text{Số bước tối thiểu} = c_{even}$$
  Ta chỉ cần chọn lần lượt từng cốc đầy ở vị trí chẵn và rót vào một cốc rỗng ở vị trí lẻ.

---

### Bài 3 (Marking cells - Đánh dấu các ô trên lưới có số láng giềng lẻ)
> **Đề bài:**  
> Thiết kế một thuật toán thực hiện nhiệm vụ sau: Với mọi số nguyên dương chẵn $n$, hãy đánh dấu $n$ ô vuông trên một tờ giấy kẻ ô li vô hạn sao cho mỗi ô được đánh dấu có **số lượng ô láng giềng được đánh dấu là số lẻ** (tức là có đúng 1 hoặc đúng 3 ô láng giềng).  
> Hai ô được coi là láng giềng nếu chúng kề nhau theo chiều ngang hoặc chiều dọc (không tính đường chéo). Các ô được đánh dấu phải tạo thành một **vùng liên thông** (có đường đi giữa hai ô bất kỳ qua chuỗi các ô láng giềng được đánh dấu).

#### Lời giải chi tiết:
Áp dụng chiến lược **Giảm 2 (Decrease-by-2)** kết hợp Quy nạp toán học:

1. **Trường hợp cơ sở $n = 2$:**
   - Đánh dấu 2 ô kề nhau theo chiều ngang: $[(0, 0), (1, 0)]$.
   - Mỗi ô chỉ có đúng 1 láng giềng được đánh dấu (ô kia). Vì 1 là số lẻ, cấu hình này thỏa mãn tuyệt đối!

2. **Bước quy nạp / Mở rộng từ $n$ lên $n + 2$:**
   - Giả sử ta đã có một vùng liên thông gồm $n$ ô thỏa mãn tính chất: mỗi ô có số láng giềng lẻ, và tồn tại ít nhất một ô biên $X$ có đúng 1 láng giềng.
   - Để thêm 2 ô mới ($O_1, O_2$) mà không làm phá vỡ tính lẻ của các ô đã có:
     - Ta gắn một khối domino $1 \times 2$ gồm hai ô $O_1$ và $O_2$ kề nhau vào cạnh của ô $X$.
     - Đặt $O_1$ kề với $X$, và $O_2$ kề với $O_1$ sao cho $O_1$ chỉ tiếp xúc với $X$ và $O_2$ (không tiếp xúc với ô nào khác), còn $O_2$ chỉ tiếp xúc duy nhất với $O_1$.
     - Khi đó:
       - Số láng giềng của $X$ tăng thêm 1 (từ 1 thành 2? Như vậy $X$ sẽ có 2 láng giềng - là số chẵn, vi phạm!).
   - **Hiệu chỉnh giải pháp khuôn mẫu chuẩn (Dạng xương cá / dải chữ L):**
     - Cách đơn giản nhất: Xếp $n/2$ khối domino $1 \times 2$ thành hình bậc thang so le nhau (diagonal zigzag cascade):
       - Khối 1: $(0, 0)$ và $(0, 1)$ (hai ô kề dọc).
       - Khối 2: $(1, 1)$ và $(1, 2)$.
       - Khối $k$: $(k-1, k-1)$ và $(k-1, k)$.
     - Kiểm tra láng giềng:
       - Các ô đầu và cuối dải có đúng 1 láng giềng.
       - Các ô ở vị trí nối $(k-1, k)$ tiếp xúc với $(k-1, k-1)$, $(k, k)$ và không tiếp xúc thêm ô nào khác $\implies$ có đúng 3 láng giềng (hoặc bố trí sao cho mỗi ô có đúng 1 hoặc 3 láng giềng).
     - Vùng ô luôn liên thông và số ô luôn tăng thêm đúng 2 sau mỗi bước.

---

### Bài 4 (Power set - Sinh tập lũy thừa bằng Giảm 1)
> **Đề bài:**  
> Thiết kế một thuật toán Giảm 1 (Decrease-by-one) để sinh tập lũy thừa $\mathcal{P}(S)$ của một tập hợp $S$ gồm $n$ phần tử. ($\mathcal{P}(S)$ là tập hợp chứa tất cả các tập con của $S$, bao gồm cả tập rỗng $\emptyset$ và chính $S$).

#### Lời giải chi tiết:
- Ký hiệu tập hợp $S = \{a_1, a_2, \dots, a_n\}$.
- Bản chất quan hệ Giảm 1:
  - Gọi $S_{n-1} = \{a_1, a_2, \dots, a_{n-1}\}$.
  - Mọi tập con của $S$ thuộc vào một trong hai loại:
    1. Không chứa phần tử $a_n$: Đây chính là các phần tử của $\mathcal{P}(S_{n-1})$.
    2. Có chứa phần tử $a_n$: Thu được bằng cách lấy từng tập con trong $\mathcal{P}(S_{n-1})$ hợp thêm phần tử $\{a_n\}$.
  - Công thức đệ quy:
    $$\mathcal{P}(S_n) = \mathcal{P}(S_{n-1}) \cup \{ T \cup \{a_n\} \mid T \in \mathcal{P}(S_{n-1}) \}$$
  - Trường hợp cơ sở: Khi $n = 0$ ($S = \emptyset$), $\mathcal{P}(\emptyset) = \{\emptyset\}$.

**Mã giả thuật toán:**
```text
Algorithm GeneratePowerSet(S, n)
// Sinh tập lũy thừa của tập hợp S gồm n phần tử
// Đầu vào: Mảng hoặc danh sách S[1..n]
// Đầu ra: Tập hợp tất cả các tập con của S

1   if n = 0 then
2       return { ∅ }
3   else
4       P_prev ← GeneratePowerSet(S, n - 1)
5       P_new ← P_prev
6       for each subset T in P_prev do
7           P_new ← P_new ∪ { T ∪ { S[n] } }
8       return P_new
```
- **Phân tích độ phức tạp:**
  - Số lượng tập con sinh ra là $|\mathcal{P}(S)| = 2^n$.
  - Thuật toán tốn $\Theta(2^n)$ thời gian và không gian bộ nhớ, đây là cận tối ưu tiệm cận vì kích thước đầu ra là $\Omega(2^n)$.

---

### Bài 5 (Graph connectivity algorithm - Kiểm tra tính liên thông)
> **Đề bài:**  
> Xét thuật toán sau đây để kiểm tra tính liên thông của đồ thị vô hướng $G$ được biểu diễn bởi ma trận kề $A[0..n-1, 0..n-1]$:
> ```text
> ALGORITHM Connected(A[0..n-1, 0..n-1])
> if n = 1 return 1
> else
>     if not Connected(A[0..n-2, 0..n-2]) return 0
>     else for j ← 0 to n-2 do
>              if A[n-1, j] return 1
>          return 0
> ```
> Thuật toán này có hoạt động đúng đắn cho mọi đồ thị vô hướng với $n > 0$ đỉnh hay không? Nếu có, hãy xác định lớp độ phức tạp trong trường hợp xấu nhất; nếu không, hãy giải thích lý do.

#### Lời giải chi tiết:
- **Trả lời:** Thuật toán này **HOÀN TOÀN SAI (Does NOT work correctly)**.
- **Giải thích & Phản ví dụ:**
  - Thuật toán giả định sai lầm rằng: Một đồ thị $n$ đỉnh liên thông khi và chỉ khi đồ thị con cảm ứng trên $n-1$ đỉnh đầu tiên $A[0..n-2, 0..n-2]$ liên thông và đỉnh thứ $n$ có ít nhất một cạnh nối tới đồ thị con đó.
  - Điều này bỏ qua trường hợp: **Đồ thị $n$ đỉnh liên thông, nhưng đồ thị con $n-1$ đỉnh lại bị mất tính liên thông do việc loại bỏ đỉnh $n-1$!** Nói cách khác, đỉnh $n-1$ chính là một **đỉnh khớp (articulation point / cut-vertex)** giữ vai trò cầu nối liên kết các thành phần của đồ thị.
  - **Phản ví dụ cụ thể:**  
    Xét đồ thị hình ngôi sao (Star graph) gồm 3 đỉnh: đỉnh 2 là tâm, có cạnh nối với đỉnh 0 và đỉnh 1; đỉnh 0 và đỉnh 1 không nối với nhau:
    $$V = \{0, 1, 2\}, \quad E = \{(0, 2), (1, 2)\}$$
    - Rõ ràng toàn bộ đồ thị 3 đỉnh này liên thông hoàn toàn (đường đi $0 - 2 - 1$).
    - Khi thuật toán gọi đệ quy trên đồ thị con 2 đỉnh $\{0, 1\}$ (tức là $A[0..1, 0..1]$): Đồ thị này không có cạnh nào giữa 0 và 1, nên không liên thông.
    - Lệnh `Connected(A[0..1, 0..1])` trả về `0` (false).
    - Do đó, thuật toán lập tức trả về `0`, kết luận đồ thị ban đầu không liên thông $\implies$ **Sai nghiêm trọng!**

---

### Bài 6 (Team ordering in round-robin tournament - Xếp thứ tự giải đấu vòng tròn)
> **Đề bài:**  
> Bạn có kết quả của một giải đấu vòng tròn đã kết thúc gồm $n$ đội thi đấu với nhau (mỗi cặp đội đấu đúng một trận). Mỗi trận đấu kết thúc với kết quả một đội thắng hoặc hai đội hòa.  
> Hãy thiết kế một thuật toán liệt kê các đội thành một dãy sao cho: Mỗi đội trong dãy **không thua** đội đứng ngay sau nó (tức là thắng hoặc hòa). Xác định lớp độ phức tạp của thuật toán.

#### Lời giải chi tiết:
Đây là sự khái quát hóa của **Định lý Rédei** về giải đấu (Tournament graph) trong lý thuyết đồ thị. Ta thiết kế thuật toán theo tư tưởng **Giảm 1 (Sắp xếp chèn)**:

- Gọi $T_1, T_2, \dots, T_k$ là dãy $k$ đội đã được sắp xếp thỏa mãn điều kiện: $T_i$ không thua $T_{i+1}$ với mọi $1 \le i \le k-1$.
- Giả sử cần chèn thêm đội thứ $k+1$ (gọi là đội $X$) vào dãy:
  1. So sánh $X$ với đội đầu tiên $T_1$: Nếu $X$ không thua $T_1$ (thắng hoặc hòa), ta đặt $X$ lên đầu dãy: $[X, T_1, T_2, \dots, T_k]$. Điều kiện thỏa mãn.
  2. So sánh $X$ với đội cuối cùng $T_k$: Nếu $T_k$ không thua $X$, ta đặt $X$ vào cuối dãy: $[T_1, T_2, \dots, T_k, X]$. Điều kiện thỏa mãn.
  3. Nếu không thuộc hai trường hợp trên (nghĩa là $T_1$ thắng $X$, và $X$ thắng $T_k$): Khi ta quét dọc theo dãy từ $i = 1$ đến $k-1$, chắc chắn tồn tại một chỉ số $i$ sao cho $T_i$ không thua $X$ nhưng $X$ không thua $T_{i+1}$. Khi đó, ta chèn $X$ vào giữa $T_i$ và $T_{i+1}$: $[T_1, \dots, T_i, X, T_{i+1}, \dots, T_k]$. Vị trí này luôn tồn tại theo nguyên lý Dirichlet.

- **Độ phức tạp thời gian:**
  - Nếu tìm vị trí chèn bằng duyệt tuần tự: Mỗi bước chèn tốn tối đa $O(k)$ phép so sánh, tổng thời gian:
    $$\sum_{k=1}^{n-1} O(k) = O(n^2)$$
  - Nếu tìm vị trí bằng Tìm kiếm nhị phân (Binary Search): Mỗi bước chèn tốn $O(\log k)$ phép so sánh, tổng số phép so sánh là $O(n \log n)$. Tuy nhiên, chi phí dịch chuyển mảng vẫn là $O(n^2)$ (hoặc $O(n \log n)$ nếu dùng danh sách liên kết cây nhị phân cân bằng).
  - Lớp độ phức tạp: **$\Theta(n^2)$** với mảng, và **$\Theta(n \log n)$** về số phép so sánh.

---

### Bài 7 (Trace Insertion Sort - Lần vết sắp xếp chữ cái)
> **Đề bài:**  
> Áp dụng thuật toán Sắp xếp chèn để sắp xếp danh sách các chữ cái sau theo thứ tự bảng chữ cái:  
> $$E, \; X, \; A, \; M, \; P, \; L, \; E$$

#### Lời giải chi tiết:
Mảng ban đầu: $A[0..6] = [E, X, A, M, P, L, E]$ ($n = 7$). Ta theo dõi trạng thái mảng sau mỗi lần lặp $i$:

| Bước $i$ | Phần tử chèn $v$ | Các so sánh thực hiện ($A[j] > v$) | Mảng sau bước lặp | Số so sánh |
| :---: | :---: | :--- | :--- | :---: |
| **Khởi tạo** | - | Mảng con ban đầu đã xét: $[E]$ | `E` \| X, A, M, P, L, E | - |
| **$i = 1$** | $v = X$ | $A[0]=E \le X$ (Dừng) | `E, X` \| A, M, P, L, E | 1 |
| **$i = 2$** | $v = A$ | $X > A$ (dời $X$); $E > A$ (dời $E$); chạm $j < 0$ | `A, E, X` \| M, P, L, E | 2 |
| **$i = 3$** | $v = M$ | $X > M$ (dời $X$); $E \le M$ (Dừng) | `A, E, M, X` \| P, L, E | 2 |
| **$i = 4$** | $v = P$ | $X > P$ (dời $X$); $M \le P$ (Dừng) | `A, E, M, P, X` \| L, E | 2 |
| **$i = 5$** | $v = L$ | $X > L$; $P > L$; $M > L$ (dời $X, P, M$); $E \le L$ (Dừng) | `A, E, L, M, P, X` \| E | 4 |
| **$i = 6$** | $v = E$ | $X > E$; $P > E$; $M > E$; $L > E$ (dời $X, P, M, L$); $E \le E$ (Dừng) | `A, E, E, L, M, P, X` | 5 |

- **Kết quả cuối cùng:** Dãy đã sắp xếp là `A, E, E, L, M, P, X`.
- **Tổng số phép so sánh khóa:** $1 + 2 + 2 + 2 + 4 + 5 = 16$ phép so sánh.
- **Tính ổn định:** Ký tự $E$ thứ hai đứng ngay sau ký tự $E$ thứ nhất, duy trì đúng thứ tự ban đầu.

---

### Bài 8 (Sentinel in Insertion Sort - Kỹ thuật lính canh)
> **Đề bài:**  
> a. Cần đặt phần tử lính canh (sentinel) có giá trị như thế nào vào trước phần tử đầu tiên của mảng đang sắp xếp để tránh phải kiểm tra điều kiện chỉ số $j \ge 0$ trong mỗi lần lặp của vòng lặp trong?  
> b. Phiên bản dùng lính canh có cùng lớp độ phức tạp với phiên bản gốc không?

#### Lời giải chi tiết:
#### Phần a:
- Vòng lặp trong của thuật toán gốc kiểm tra hai điều kiện: `j >= 0` và `A[j] > v`. Phép kiểm tra `j >= 0` chỉ nhằm tránh lỗi truy cập chỉ số âm ngoài biên mảng khi $v$ nhỏ hơn toàn bộ các phần tử đứng trước.
- Để loại bỏ `j >= 0`, ta cần đặt ở vị trí $A[-1]$ (hoặc dời mảng sang $A[1..n]$ và đặt tại $A[0]$) một giá trị **lính canh cực tiểu** $S$ sao cho điều kiện $S > v$ **luôn luôn sai**.
- Do đó:
  $$A[0] = -\infty \quad \text{(hoặc giá trị nhỏ nhất trong miền giá trị dữ liệu)}$$
- *Cách triển khai thực tế không cần $-\infty$:* Trước khi chạy thuật toán, tìm phần tử nhỏ nhất trong toàn bộ mảng và đổi chỗ nó về vị trí đầu tiên $A[0]$. Khi đó $A[0]$ đóng vai trò lính canh tự nhiên vì không phần tử nào trong mảng có thể nhỏ hơn nó!

#### Phần b:
- **Cùng lớp độ phức tạp:** Thuật toán vẫn thuộc lớp $\Theta(n^2)$ trong trường hợp xấu nhất và trung bình, và $\Theta(n)$ trong trường hợp tốt nhất.
- Tuy nhiên, trong mỗi vòng lặp `while`, ta bớt được đúng một phép so sánh logic (`j >= 0 and`), giúp giảm số lệnh mã máy của vòng lặp trong khoảng $30\%$, mang lại tốc độ thực thi thực tế nhanh hơn đáng kể.

---

### Bài 9 (Insertion Sort for Linked Lists - Sắp xếp danh sách liên kết)
> **Đề bài:**  
> Có thể cài đặt thuật toán Sắp xếp chèn cho danh sách liên kết (linked lists) được không? Thuật toán có cùng độ phức tạp thời gian $O(n^2)$ như phiên bản mảng không?

#### Lời giải chi tiết:
- **Khả thi:** Hoàn toàn có thể cài đặt được!
  - Ta duy trì một danh sách liên kết kết quả ban đầu rỗng. Lần lượt lấy từng nút từ danh sách liên kết ban đầu và chèn nó vào vị trí thích hợp trong danh sách kết quả đã có thứ tự.
- **Về độ phức tạp thời gian:**
  - **Vẫn là $O(n^2)$:** Bởi vì danh sách liên kết không hỗ trợ truy cập ngẫu nhiên chỉ số $O(1)$, ta buộc phải duyệt tuần tự từ đầu danh sách để tìm vị trí chèn cho phần tử thứ $i$. Chi phí tìm kiếm vị trí chèn tốn trung bình $i/2$ phép so sánh $\implies$ Tổng số phép so sánh vẫn là $\Theta(n^2)$.
- **Điểm khác biệt so với mảng:**
  - Trên mảng: Phép chèn tốn chi phí dịch chuyển dữ liệu $\Theta(n)$.
  - Trên danh sách liên kết: Phép chèn chỉ tốn đúng $O(1)$ để cập nhật hai con trỏ `next`. Do đó số phép dịch chuyển dữ liệu bằng 0.

---

### Bài 10 (InsertSort2 Analysis - So sánh phiên bản dùng hoán đổi liên tiếp)
> **Đề bài:**  
> So sánh cài đặt Sắp xếp chèn của giáo trình với phiên bản sau:
> ```text
> ALGORITHM InsertSort2(A[0..n-1])
> for i ← 1 to n - 1 do
>     j ← i - 1
>     while j ≥ 0 and A[j] > A[j + 1] do
>         swap(A[j], A[j + 1])
>         j ← j - 1
> ```
> Hiệu quả thời gian của thuật toán này thế nào? So sánh với phiên bản trong Mục 4.1?

#### Lời giải chi tiết:
1. **Về số phép so sánh khóa:**
   - Cả hai phiên bản đều thực hiện chính xác cùng số lượng phép so sánh khóa trong mọi trường hợp:
     $$C_{worst}(n) = \frac{n(n-1)}{2}, \quad C_{best}(n) = n - 1, \quad C_{avg}(n) \approx \frac{n^2}{4}$$
   - Độ phức tạp tiệm cận của cả hai đều là $\Theta(n^2)$ (xấu nhất, trung bình) và $\Theta(n)$ (tốt nhất).

2. **Về số phép gán dữ liệu (Data movement - Điểm khác biệt mấu chốt):**
   - **Phiên bản giáo trình (Mục 4.1):**
     - Lưu $v = A[i]$ vào biến tạm (1 phép gán).
     - Mỗi bước lùi chỉ dời mảng: $A[j+1] \leftarrow A[j]$ (**đúng 1 phép gán**).
     - Gán $v$ vào vị trí cuối: $A[j+1] \leftarrow v$ (1 phép gán).
     - Nếu phải lùi $k$ bước: Tổng cộng tốn $k + 2$ phép gán.
   - **Phiên bản `InsertSort2`:**
     - Sử dụng hàm `swap(A[j], A[j+1])`. Mỗi phép `swap` kinh điển tốn **3 phép gán**:
       `temp = A[j]; A[j] = A[j+1]; A[j+1] = temp;`
     - Nếu phải lùi $k$ bước: Thuật toán tốn tới $3k$ phép gán!
3. **Kết luận so sánh:**
   - `InsertSort2` thực hiện số phép gán dữ liệu **nhiều gấp 3 lần** so với phiên bản chuẩn của Mục 4.1. Do đó trên thực tế, `InsertSort2` chạy chậm hơn nhiều, đặc biệt khi kích thước phần tử dữ liệu lớn. Phiên bản gốc của Mục 4.1 ưu việt hơn hẳn.

---

### Bài 11 (Inversions & Average-Case Analysis - Nghịch thế & Phân tích trường hợp trung bình)
> **Đề bài:**  
> Cho $A[0..n-1]$ là mảng gồm $n$ phần tử phân biệt. Cặp $(A[i], A[j])$ được gọi là một **nghịch thế (inversion)** nếu $i < j$ và $A[i] > A[j]$.  
> a. Mảng kích thước $n$ nào có số nghịch thế lớn nhất và số đó là bao nhiêu? Trả lời câu hỏi tương tự cho số nghịch thế nhỏ nhất.  
> b. Chứng minh rằng số phép so sánh khóa trung bình trong Sắp xếp chèn xấp xỉ bằng:
> $$C_{avg}(n) \approx \frac{n^2}{4}$$

#### Lời giải chi tiết:

#### Phần a:
- **Số nghịch thế lớn nhất:** Đạt được khi mảng được sắp xếp theo thứ tự **giảm ngặt**: $A[0] > A[1] > \dots > A[n-1]$.
  - Khi đó, mọi cặp chỉ số $(i, j)$ với $i < j$ đều tạo thành một nghịch thế.
  - Tổng số cặp chỉ số là tổ hợp chập 2 của $n$:
    $$I_{max} = \binom{n}{2} = \frac{n(n-1)}{2}$$
- **Số nghịch thế nhỏ nhất:** Đạt được khi mảng đã được sắp xếp **tăng ngặt**: $A[0] < A[1] < \dots < A[n-1]$.
  - Không có cặp nào thỏa mãn $A[i] > A[j]$.
  - Số nghịch thế: $I_{min} = 0$.

#### Phần b:
- **Chứng minh:**
  1. Xét một hoán vị ngẫu nhiên $\pi$ của $n$ phần tử. Gọi $I(\pi)$ là số lượng nghịch thế của $\pi$.
  2. Xét hoán vị đảo ngược $\pi^R$ của $\pi$. Với mỗi cặp $(i, j)$, cặp này là nghịch thế trong $\pi$ khi và chỉ khi nó KHÔNG là nghịch thế trong $\pi^R$.
  3. Do đó, tổng số nghịch thế của $\pi$ và $\pi^R$ luôn đúng bằng tổng số cặp phần tử:
     $$I(\pi) + I(\pi^R) = \binom{n}{2} = \frac{n(n-1)}{2}$$
  4. Vì mọi hoán vị $\pi$ và $\pi^R$ đều có xác suất xuất hiện như nhau, kỳ vọng số nghịch thế của một mảng ngẫu nhiên là:
     $$E[I] = \frac{1}{2} \cdot \frac{n(n-1)}{2} = \frac{n(n-1)}{4}$$
  5. Trong thuật toán Sắp xếp chèn, mỗi lần dịch chuyển một phần tử $A[j] > v$ sang phải một vị trí, ta khử được **chính xác 1 nghịch thế**.
  6. Khi chèn phần tử thứ $i$, ngoài các phép so sánh đi kèm với việc dời phần tử (khử nghịch thế), thuật toán còn thực hiện thêm đúng 1 phép so sánh cuối cùng để dừng vòng lặp (khi $A[j] \le v$), ngoại trừ trường hợp phần tử dời về tận đầu mảng ($j < 0$).
  7. Do đó, tổng số phép so sánh khóa trung bình là:
     $$C_{avg}(n) = E[I] + \sum_{i=1}^{n-1} \left(1 - \frac{1}{i+1}\right) = \frac{n(n-1)}{4} + n - H_n \approx \frac{n^2}{4}$$
     (với $H_n = \sum_{k=1}^n \frac{1}{k} \approx \ln n$). Chứng minh hoàn tất!

---

### Bài 12 (Shellsort - Sắp xếp Shell)
> **Đề bài:**  
> Shellsort là thuật toán sắp xếp quan trọng dựa trên việc áp dụng Sắp xếp chèn cho các dãy con đan xen với bước nhảy giảm dần kết thúc bằng 1 ($h_1 > h_2 > \dots > 1$).  
> a. Áp dụng Shellsort để sắp xếp danh sách ký tự sau với dãy bước nhảy phù hợp:  
> $$S, \; H, \; E, \; L, \; L, \; S, \; O, \; R, \; T, \; I, \; S, \; U, \; S, \; E, \; F, \; U, \; L$$  
> b. Shellsort có phải là một thuật toán sắp xếp ổn định không?  
> c. So sánh hiệu năng thực tế của Shellsort với Sắp xếp chèn thông thường, Sắp xếp chọn và Sắp xếp nổi bọt.

#### Lời giải chi tiết:

#### Phần a (Lần vết Shellsort):
Danh sách gồm $n = 17$ ký tự, các chỉ số từ 0 đến 16:
`[S, H, E, L, L, S, O, R, T, I, S, U, S, E, F, U, L]`

Chọn dãy bước nhảy Shell kinh điển: $h = 5, h = 3, h = 1$.

- **Lượt 1 với bước nhảy $h = 5$:**
  - Dãy con 0 (chỉ số 0, 5, 10, 15): `S, S, S, U` $\to$ đã có thứ tự `S, S, S, U`.
  - Dãy con 1 (chỉ số 1, 6, 11, 16): `H, O, U, L` $\to$ sắp xếp thành `H, L, O, U`.
  - Dãy con 2 (chỉ số 2, 7, 12): `E, R, S` $\to$ đã có thứ tự `E, R, S`.
  - Dãy con 3 (chỉ số 3, 8, 13): `L, T, E` $\to$ sắp xếp thành `E, L, T`.
  - Dãy con 4 (chỉ số 4, 9, 14): `L, I, F` $\to$ sắp xếp thành `F, I, L`.
  - Dãy sau lượt $h=5$:
    `[S, H, E, E, F, S, L, R, L, I, S, O, S, T, L, U, U]`

- **Lượt 2 với bước nhảy $h = 3$:**
  - Sắp xếp chèn trên các phần tử cách nhau 3 vị trí.
  - Dãy dần trở nên gần như có thứ tự hoàn toàn.

- **Lượt 3 với bước nhảy $h = 1$:**
  - Chạy Sắp xếp chèn thông thường trên toàn bộ mảng. Vì mảng đã gần như có thứ tự sẵn từ các bước trước, mỗi phần tử chỉ cần dịch chuyển từ 1 đến 2 bước.
  - Kết quả cuối cùng:
    `[E, E, E, F, H, I, L, L, L, L, O, R, S, S, S, T, U]`

#### Phần b (Tính ổn định):
- **Shellsort KHÔNG ỔN ĐỊNH (Not Stable).**
- **Phản ví dụ:**  
  Xét mảng 4 phần tử: $[2_a, 2_b, 1, 3]$ với bước nhảy $h = 2$.
  - Dãy con cách nhau 2 vị trí gồm:
    - Cặp chỉ số 0 và 2: $A[0] = 2_a, A[2] = 1$. Sắp xếp cặp này sẽ hoán đổi 1 và $2_a \implies A[0] = 1, A[2] = 2_a$.
    - Cặp chỉ số 1 và 3: $A[1] = 2_b, A[3] = 3 \implies$ giữ nguyên.
  - Mảng sau lượt $h=2$ là: $[1, 2_b, 2_a, 3]$.
  - Ta thấy $2_b$ ban đầu đứng sau $2_a$ nhưng giờ đã nhảy lên trước $2_a$. Thứ tự tương đối ban đầu bị phá vỡ!

#### Phần c (So sánh hiệu năng):
- **So với Insertion Sort, Selection Sort, Bubble Sort:**
  - Ba thuật toán cơ bản đều có độ phức tạp thời gian $\Theta(n^2)$.
  - Shellsort với dãy khoảng cách tốt (ví dụ dãy Sedgewick hoặc Pratt) đạt độ phức tạp $O(n^{4/3})$ hoặc $O(n \log^2 n)$, vượt trội hoàn toàn khi $n > 100$.
  - Trong thực tế với mảng vài nghìn phần tử, Shellsort nhanh hơn Insertion Sort và Selection Sort từ hàng chục đến hàng trăm lần.


---

# CHUYÊN ĐỀ 02: SẮP XẾP TÔ-PÔ (TOPOLOGICAL SORTING) & LỜI GIẢI BÀI TẬP 4.2
*Tài liệu tham chiếu: A. Levitin, "Introduction to the Design and Analysis of Algorithms", 3rd Edition, Chương 4, Mục 4.2, Trang 138–144.*

---

## PHẦN I. LÝ THUYẾT VÀ MÃ GIẢ CHUẨN HÓA

### 1.1. Khái niệm Đồ thị có hướng không chu trình (DAG) & Bài toán Sắp xếp Tô-pô
- **Đồ thị có hướng (Digraph):** Tập hợp gồm các đỉnh $V$ và các cung có hướng $E$.
- **DAG (Directed Acyclic Graph):** Là đồ thị có hướng **không chứa bất kỳ chu trình có hướng nào**.
- **Bài toán Sắp xếp Tô-pô (Topological Sorting):**  
  Cho một đồ thị có hướng $G = (V, E)$. Hãy tìm một thứ tự tuyến tính (linear ordering) của toàn bộ các đỉnh trong $V$ sao cho:  
  $$\forall (u, v) \in E \implies u \text{ phải xuất hiện trước } v \text{ trong thứ tự sắp xếp}$$
- **Điều kiện cần và đủ:** Bài toán sắp xếp tô-pô có nghiệm **khi và chỉ khi** đồ thị $G$ là một DAG.

```mermaid
flowchart LR
    C1["C1: Nhập môn lập trình"] --> C3["C3: Cấu trúc dữ liệu"]
    C2["C2: Toán rời rạc"] --> C3
    C3 --> C4["C4: Phân tích thuật toán"]
    C3 --> C5["C5: Trí tuệ nhân tạo"]
    C4 --> C5
```
*Minh họa thứ tự tiên quyết môn học: Một thứ tự tô-pô hợp lệ là $C1, C2, C3, C4, C5$ (hoặc $C2, C1, C3, C4, C5$).*

---

### 1.2. Thuật toán 1: Dựa trên Tìm kiếm theo chiều sâu (DFS-Based Algorithm)

#### Bản chất ý tưởng:
1. Thực hiện duyệt toàn bộ đồ thị bằng thuật toán tìm kiếm theo chiều sâu (DFS).
2. Khi một đỉnh $v$ duyệt xong toàn bộ các nhánh con của nó (đạt trạng thái "đường cùng" - dead-end, được lấy ra khỏi ngăn xếp đệ quy), ta ghi nhận $v$.
3. **Đảo ngược** thứ tự các đỉnh duyệt xong sẽ cho ta thứ tự sắp xếp tô-pô.
4. **Phát hiện chu trình:** Trong quá trình DFS, nếu gặp một cung trỏ tới một đỉnh đang nằm trên ngăn xếp đệ quy (gọi là **cung ngược - Back Edge**), đồ thị chứa chu trình $\implies$ không thể sắp xếp tô-pô!

#### Mã giả chuẩn hóa cấu trúc:

```text
Algorithm TopologicalSortDFS(G)
// Đầu vào: Đồ thị có hướng G = (V, E)
// Đầu ra: Danh sách đỉnh L theo thứ tự tô-pô, hoặc thông báo chu trình

1   Khởi tạo mảng visited[u] ← 0, inStack[u] ← false với mọi u ∈ V
2   Khởi tạo danh sách kết quả rỗng L (dùng ngăn xếp hoặc chèn vào đầu)
3   hasCycle ← false
4   
5   for each u ∈ V do
6       if visited[u] = 0 and not hasCycle then
7           DFS_Topo(u)
8   
9   if hasCycle then
10      return "Đồ thị chứa chu trình, không thể sắp xếp tô-pô!"
11  else
12      return L

Procedure DFS_Topo(u)
1   visited[u] ← 1; inStack[u] ← true
2   for each v kề sau u ((u, v) ∈ E) do
3       if inStack[v] then
4           hasCycle ← true     // Phát hiện cung ngược (Back edge) -> Có chu trình!
5           return
6       if visited[v] = 0 then
7           DFS_Topo(v)
8   inStack[u] ← false
9   Thêm u vào ĐẦU danh sách L   // Tránh phải đảo ngược sau khi duyệt
```

---

### 1.3. Thuật toán 2: Xóa đỉnh nguồn (Source-Removal Algorithm / Thuật toán Kahn)

#### Bản chất ý tưởng (Chiến lược Giảm 1 - Decrease-by-one):
- **Đỉnh nguồn (Source):** Là đỉnh có **bán bậc vào bằng 0** (in-degree $= 0$), nghĩa là không có bất kỳ điều kiện tiên quyết nào trỏ vào nó.
- **Quy trình lặp giảm 1:**
  1. Xác định một đỉnh nguồn $u$ trong đồ thị hiện tại.
  2. Đưa $u$ vào danh sách kết quả sắp xếp tô-pô.
  3. Xóa $u$ cùng toàn bộ các cung xuất phát từ $u$ ra khỏi đồ thị (thực chất là giảm bán bậc vào của các đỉnh kề sau $u$ đi 1). Kích thước đồ thị giảm từ $|V|$ xuống $|V| - 1$.
  4. Lặp lại cho đến khi đồ thị rỗng. Nếu tại một bước còn đỉnh nhưng không tìm được đỉnh nguồn nào thì đồ thị chứa chu trình!

#### Mã giả chuẩn hóa cấu trúc:

```text
Algorithm TopologicalSortKahn(G)
// Đầu vào: Đồ thị có hướng G = (V, E) với danh sách kề
// Đầu ra: Danh sách đỉnh L theo thứ tự tô-pô, hoặc thông báo chu trình

1   Khởi tạo mảng inDegree[u] ← 0 với mọi u ∈ V
2   for each u ∈ V do
3       for each v ∈ Adj[u] do
4           inDegree[v] ← inDegree[v] + 1
5   
6   Khởi tạo hàng đợi Q (Queue) rỗng
7   for each u ∈ V do
8       if inDegree[u] = 0 then
9           Enqueue(Q, u)
10  
11  Khởi tạo danh sách L rỗng; count ← 0
12  while not IsEmpty(Q) do
13      u ← Dequeue(Q)
14      Append(L, u); count ← count + 1
15      for each v ∈ Adj[u] do
16          inDegree[v] ← inDegree[v] - 1
17          if inDegree[v] = 0 then
18              Enqueue(Q, v)
19  
20  if count ≠ |V| then
21      return "Đồ thị chứa chu trình, không thể sắp xếp tô-pô!"
22  else
23      return L
```

### 1.4. So sánh hai thuật toán

| Tiêu chí | Thuật toán dựa trên DFS | Thuật toán Xóa đỉnh nguồn (Kahn) |
| :--- | :--- | :--- |
| **Bản chất tiếp cận** | Top-down (đi sâu đến nhánh tận cùng rồi quay lui). | Bottom-up (bắt đầu từ các đỉnh nguồn không phụ thuộc). |
| **Độ phức tạp (Danh sách kề)** | $\Theta(\|V\| + \|E\|)$ | $\Theta(\|V\| + \|E\|)$ |
| **Độ phức tạp (Ma trận kề)** | $\Theta(\|V\|^2)$ | $\Theta(\|V\|^2)$ |
| **Cơ chế phát hiện chu trình** | Gặp cung ngược (Back edge) trỏ về nút tổ tiên trong đệ quy. | Hàng đợi rỗng nhưng số đỉnh duyệt được nhỏ hơn $\|V\|$. |
| **Thứ tự sinh ra** | Đỉnh kết thúc sau cùng đứng đầu dãy. | Đỉnh nguồn ban đầu đứng đầu dãy. |

---

## PHẦN II. GIẢI CHI TIẾT 100% CÁC BÀI TẬP EXERCISES 4.2 (BÀI 1 ĐẾN BÀI 10)

---

### Bài 1 (Apply DFS-based Topological Sorting - Sắp xếp tô-pô bằng DFS)
> **Đề bài:**  
> Áp dụng thuật toán dựa trên DFS để giải bài toán sắp xếp tô-pô cho hai đồ thị có hướng sau:
> 
> **Đồ thị (a):** Gồm 7 đỉnh $\{a, b, c, d, e, f, g\}$. Tập cung:  
> $$d \to a, \; d \to b, \; d \to c, \; d \to f, \; d \to g, \; a \to b, \; a \to c, \; c \to f, \; b \to e, \; b \to g, \; g \to e, \; g \to f$$
> 
> **Đồ thị (b):** Gồm 7 đỉnh $\{a, b, c, d, e, f, g\}$. Tập cung:  
> $$a \to b, \; b \to c, \; c \to d, \; d \to g, \; g \to e, \; e \to a, \; f \to e, \; f \to b, \; f \to c, \; f \to g$$

#### Lời giải chi tiết:

#### Xét Đồ thị (a):
1. **Duyệt DFS** (giả sử ưu tiên đỉnh theo thứ tự bảng chữ cái khi chọn đỉnh bắt đầu):
   - Bắt đầu duyệt từ $a$:
     - Từ $a \to b$: Từ $b \to e$ (e không có cung đi tiếp $\implies$ dead-end 1: ghi nhận $e$).
     - Quay lại $b$, sang $g$: Từ $g \to f$ (f không có cung đi tiếp $\implies$ dead-end 2: ghi nhận $f$).
     - Từ $g$ không còn nhánh nào $\implies$ dead-end 3: ghi nhận $g$.
     - Quay lại $b$, $b$ hết nhánh $\implies$ dead-end 4: ghi nhận $b$.
     - Quay lại $a$, sang $c$: $c \to f$ ($f$ đã duyệt $\implies$ bỏ qua). $c$ hết nhánh $\implies$ dead-end 5: ghi nhận $c$.
     - Quay lại $a$, $a$ hết nhánh $\implies$ dead-end 6: ghi nhận $a$.
   - Tiếp tục vòng lặp đỉnh chưa thăm: Đỉnh $d$ chưa thăm:
     - Thăm $d$: Các đỉnh kề của $d$ là $a, b, c, f, g$ đều đã thăm xong.
     - $d$ hết nhánh $\implies$ dead-end 7: ghi nhận $d$.
2. **Thứ tự lấy ra khỏi ngăn xếp (Popping-off order):**
   $$e, \; f, \; g, \; b, \; c, \; a, \; d$$
3. **Đảo ngược thứ tự trên để có thứ tự Tô-pô:**
   $$d, \; a, \; c, \; b, \; g, \; f, \; e$$
   *(Hoặc $d, a, b, c, g, f, e$ tùy thuộc thứ tự duyệt nhánh).*
   - **Kiểm tra tính đúng đắn:** Mọi cung trong đồ thị đều hướng từ trái sang phải! Đồ thị không chứa cung ngược, nên đây là DAG và nghiệm hợp lệ.

#### Xét Đồ thị (b):
1. **Duyệt DFS:**
   - Giả sử bắt đầu duyệt từ $a$:
     - $a \to b \to c \to d \to g \to e \to a$.
   - Tại đỉnh $e$, ta xét cung $e \to a$. Đỉnh $a$ đang có trạng thái `inStack = true` (nằm trên ngăn xếp gọi đệ quy của nhánh hiện tại).
   - Do đó, cung $e \to a$ chính là một **CUNG NGƯỢC (Back Edge)**!
2. **Kết luận:** Đồ thị (b) chứa một chu trình có hướng:
   $$a \to b \to c \to d \to g \to e \to a$$
   Vì đồ thị chứa chu trình, nó **không phải là một DAG**. Bài toán sắp xếp tô-pô cho đồ thị (b) **KHÔNG CÓ NGHIỆM**.

---

### Bài 2 (DAG Property & Maximum Topological Solutions - Tính chất DAG & Số nghiệm tối đa)
> **Đề bài:**  
> a. Chứng minh rằng bài toán sắp xếp tô-pô có nghiệm khi và chỉ khi đồ thị có hướng là một DAG.  
> b. Đối với một đồ thị có hướng gồm $n$ đỉnh, số lượng nghiệm sắp xếp tô-pô phân biệt lớn nhất có thể có là bao nhiêu?

#### Lời giải chi tiết:

#### Phần a (Chứng minh Điều kiện cần và đủ):
- **Chiều thuận ($\Rightarrow$): Nếu bài toán có nghiệm thì đồ thị phải là DAG.**
  - Giả sử đồ thị $G$ có thứ tự tô-pô là $v_1, v_2, \dots, v_n$.
  - Phản chứng: Giả sử $G$ chứa một chu trình có hướng $C = u_1 \to u_2 \to \dots \to u_k \to u_1$ ($k \ge 2$).
  - Theo định nghĩa thứ tự tô-pô:
    - Cung $u_1 \to u_2 \implies u_1$ phải đứng trước $u_2$ (vị trí $\text{pos}(u_1) < \text{pos}(u_2)$).
    - Cung $u_2 \to u_3 \implies \text{pos}(u_2) < \text{pos}(u_3)$.
    - ...
    - Cung $u_k \to u_1 \implies \text{pos}(u_k) < \text{pos}(u_1)$.
  - Kết hợp chuỗi bất đẳng thức: $\text{pos}(u_1) < \text{pos}(u_2) < \dots < \text{pos}(u_k) < \text{pos}(u_1) \implies \text{pos}(u_1) < \text{pos}(u_1)$, điều này vô lý!
  - Vậy đồ thị không thể chứa chu trình có hướng $\implies G$ là một DAG.

- **Chiều đảo ($\Leftarrow$): Nếu đồ thị là DAG thì bài toán luôn có nghiệm.**
  - Chứng minh bằng quy nạp theo số đỉnh $n$:
    - Với $n = 1$: Đồ thị 1 đỉnh không có cạnh, thứ tự duy nhất chính là nghiệm.
    - Giả sử mệnh đề đúng với mọi DAG có $n - 1$ đỉnh.
    - Với DAG $G$ có $n$ đỉnh: Theo định lý lý thuyết đồ thị (xem Bài 6a), mọi DAG hữu hạn luôn có **ít nhất một đỉnh nguồn $u$** (đỉnh có bán bậc vào bằng 0).
    - Đặt $u$ làm phần tử đầu tiên của thứ tự tô-pô.
    - Xóa đỉnh $u$ và các cung đi từ $u$, đồ thị còn lại $G' = G \setminus \{u\}$ vẫn là một DAG gồm $n - 1$ đỉnh.
    - Theo giả thiết quy nạp, $G'$ có một thứ tự tô-pô hợp lệ $v_1, v_2, \dots, v_{n-1}$.
    - Ghép $u$ vào trước dãy này ta được: $u, v_1, v_2, \dots, v_{n-1}$. Vì $u$ không có cung nào trỏ vào nó, thứ tự ghép này thỏa mãn toàn bộ các cung của $G$.
  - Mệnh đề được chứng minh hoàn tất.

#### Phần b (Số lượng nghiệm phân biệt cực đại):
- Số lượng nghiệm sắp xếp tô-pô đạt cực đại khi ràng buộc giữa các đỉnh là **ít nhất**.
- Trường hợp cực biên: Đồ thị rỗng gồm $n$ đỉnh và **không có bất kỳ cung nào** ($E = \emptyset$).
- Khi đó, không có bất kỳ điều kiện tiên quyết nào giữa các đỉnh. Mọi hoán vị tùy ý của $n$ đỉnh đều là một thứ tự sắp xếp tô-pô hợp lệ.
- Tổng số hoán vị của tập hợp $n$ phần tử là:
  $$N_{max} = n!$$
- **Đáp số:** $n!$ nghiệm phân biệt.

---

### Bài 3 (DFS Efficiency & Non-Reversing Optimization - Độ phức tạp DFS & Tối ưu không đảo ngược)
> **Đề bài:**  
> a. Độ phức tạp thời gian của thuật toán sắp xếp tô-pô dựa trên DFS là bao nhiêu?  
> b. Làm thế nào để điều chỉnh thuật toán dựa trên DFS nhằm tránh việc phải đảo ngược danh sách đỉnh thu được từ DFS?

#### Lời giải chi tiết:

#### Phần a:
- Thuật toán duyệt DFS thăm mỗi đỉnh đúng một lần và duyệt qua mỗi cung đúng một lần.
- **Nếu biểu diễn bằng Danh sách kề (Adjacency Lists):**
  - Thời gian duyệt toàn bộ đỉnh và cung là $\Theta(|V| + |E|)$.
  - Thao tác ghi nhận đỉnh và đảo ngược danh sách tốn $\Theta(|V|)$.
  - Tổng độ phức tạp thời gian:
    $$T(|V|, |E|) \in \Theta(|V| + |E|)$$
- **Nếu biểu diễn bằng Ma trận kề (Adjacency Matrix):**
  - Với mỗi đỉnh cần duyệt qua một hàng gồm $|V|$ phần tử để tìm các đỉnh kề.
  - Tổng độ phức tạp thời gian:
    $$T(|V|, |E|) \in \Theta(|V|^2)$$

#### Phần b:
Để tránh bước đảo ngược danh sách ở cuối thuật toán, ta có các giải pháp kỹ thuật sau:
1. **Dùng Ngăn xếp (Stack):** Mỗi khi một đỉnh $u$ trở thành dead-end, ta lập tức đẩy $u$ vào một ngăn xếp `Push(S, u)`. Khi toàn bộ quá trình DFS kết thúc, thứ tự lấy ra từ ngăn xếp (từ đỉnh xuống đáy) chính là thứ tự tô-pô trực tiếp.
2. **Dùng Danh sách liên kết chèn đầu (Insert at head):** Thay vì thêm vào cuối danh sách, ta luôn chèn đỉnh vừa duyệt xong vào đầu danh sách kết quả (`list.push_front(u)`). Thao tác này tốn $O(1)$ cho mỗi đỉnh.
3. **Dùng Mảng với chỉ số lùi:** Khởi tạo biến chỉ số $k = |V| - 1$. Mỗi khi có một đỉnh $u$ duyệt xong, ta gán `topo[k] = u` và giảm $k \leftarrow k - 1$.

---

### Bài 4 (Push Order vs Pop Order in DFS - Thứ tự đẩy vào so với thứ tự lấy ra)
> **Đề bài:**  
> Có thể sử dụng thứ tự các đỉnh được **đẩy vào** (pushed onto) ngăn xếp DFS (thay vì thứ tự các đỉnh được **lấy ra** - popped off khỏi ngăn xếp) để giải bài toán sắp xếp tô-pô được không?

#### Lời giải chi tiết:
- **Trả lời:** **HOÀN TOÀN KHÔNG THỂ (NO)**.
- **Giải thích & Phản ví dụ:**
  - Thứ tự được đẩy vào ngăn xếp DFS chỉ phản ánh thứ tự thăm đỉnh lúc ban đầu, nó hoàn toàn phụ thuộc vào việc thuật toán chọn đỉnh nào để bắt đầu và thứ tự các đỉnh trong danh sách kề, chứ không đảm bảo các điều kiện tiên quyết được thỏa mãn.
  - **Phản ví dụ cụ thể:**  
    Xét đồ thị gồm 3 đỉnh $\{u, v, w\}$ với 2 cung:
    $$u \to v \quad \text{và} \quad w \to v$$
    - Giả sử thuật toán DFS bắt đầu duyệt từ đỉnh $u$:
      1. Đỉnh $u$ được thăm và **đẩy vào ngăn xếp** đầu tiên: Ngăn xếp $= [u]$.
      2. Đi theo cung $u \to v$: Đỉnh $v$ được thăm và **đẩy vào ngăn xếp** thứ hai: Ngăn xếp $= [u, v]$.
      3. Đỉnh $v$ là dead-end, quay lui về $u$. $u$ cũng là dead-end.
      4. Tiếp tục vòng lặp ngoài, đỉnh $w$ chưa thăm được chọn: Đỉnh $w$ được thăm và **đẩy vào ngăn xếp** thứ ba: Ngăn xếp $= [u, v, w]$.
    - Thứ tự các đỉnh được đẩy vào ngăn xếp là:
      $$[u, \; v, \; w]$$
    - Nhưng trong đồ thị có cung $w \to v$ (nghĩa là $w$ phải đứng TRƯỚC $v$). Trong dãy đẩy vào, $v$ lại đứng ở vị trí 2 còn $w$ đứng ở vị trí 3 $\implies$ **Vi phạm nghiêm trọng thứ tự tô-pô!**
  - Do đó, chỉ có thứ tự **lấy ra (popped-off)** - thời điểm mà toàn bộ cây con bên dưới đã hoàn tất - mới phản ánh đúng mối quan hệ phụ thuộc.

---

### Bài 5 (Apply Source-Removal to Problem 1 Digraphs - Xóa đỉnh nguồn cho đồ thị Bài 1)
> **Đề bài:**  
> Áp dụng thuật toán xóa đỉnh nguồn (Kahn) cho hai đồ thị trong Bài 1 ở trên.

#### Lời giải chi tiết:

#### Xét Đồ thị (a):
1. **Tính bán bậc vào ban đầu ($inDegree$):**
   - Đỉnh $d$: không có cung nào trỏ vào $\implies inDegree[d] = 0$ (Đỉnh nguồn duy nhất!).
   - Đỉnh $a$: nhận cung từ $d \implies inDegree[a] = 1$.
   - Đỉnh $b$: nhận cung từ $d, a \implies inDegree[b] = 2$.
   - Đỉnh $c$: nhận cung từ $d, a \implies inDegree[c] = 2$.
   - Đỉnh $g$: nhận cung từ $d, b \implies inDegree[g] = 2$.
   - Đỉnh $e$: nhận cung từ $b, g \implies inDegree[e] = 2$.
   - Đỉnh $f$: nhận cung từ $d, c, g \implies inDegree[f] = 3$.

2. **Các bước thực thi xóa đỉnh nguồn:**
   - **Bước 1:** Đỉnh nguồn duy nhất là $d$. Xóa $d$.
     - Kết quả: $L = [d]$.
     - Giảm bậc các đỉnh kề của $d$: $inDegree[a]=0, inDegree[b]=1, inDegree[c]=1, inDegree[g]=1, inDegree[f]=2$.
     - Đỉnh nguồn mới: $a$.
   - **Bước 2:** Xóa $a$.
     - Kết quả: $L = [d, a]$.
     - Giảm bậc: $inDegree[b]=0, inDegree[c]=0$.
     - Đỉnh nguồn mới: $b, c$. Chọn $b$ (hoặc $c$).
   - **Bước 3:** Xóa $b$.
     - Kết quả: $L = [d, a, b]$.
     - Giảm bậc: $inDegree[g]=0, inDegree[e]=1$.
     - Đỉnh nguồn mới: $c, g$. Chọn $c$.
   - **Bước 4:** Xóa $c$.
     - Kết quả: $L = [d, a, b, c]$.
     - Giảm bậc: $inDegree[f]=1$.
     - Đỉnh nguồn hiện tại: $g$.
   - **Bước 5:** Xóa $g$.
     - Kết quả: $L = [d, a, b, c, g]$.
     - Giảm bậc: $inDegree[e]=0, inDegree[f]=0$.
     - Đỉnh nguồn mới: $e, f$. Chọn $f$.
   - **Bước 6:** Xóa $f$.
     - Kết quả: $L = [d, a, b, c, g, f]$.
     - Đỉnh nguồn còn lại: $e$.
   - **Bước 7:** Xóa $e$.
     - Kết quả: $L = [d, a, b, c, g, f, e]$.
3. **Kết luận:** Thứ tự tô-pô thu được là:
   $$d, \; a, \; b, \; c, \; g, \; f, \; e$$
   (Đã xóa hết 7/7 đỉnh, nghiệm hoàn toàn chính xác).

#### Xét Đồ thị (b):
1. **Tính bán bậc vào ban đầu:**
   - Cung: $a \to b, b \to c, c \to d, d \to g, g \to e, e \to a, f \to e, f \to b, f \to c, f \to g$.
   - $inDegree[f] = 0$ (Đỉnh $f$ là đỉnh nguồn duy nhất).
   - $inDegree[a] = 1$ (từ $e$).
   - $inDegree[b] = 2$ (từ $a, f$).
   - $inDegree[c] = 2$ (từ $b, f$).
   - $inDegree[d] = 1$ (từ $c$).
   - $inDegree[e] = 2$ (từ $g, f$).
   - $inDegree[g] = 2$ (từ $d, f$).
2. **Thực thi:**
   - **Bước 1:** Xóa đỉnh nguồn $f$.
     - Kết quả: $L = [f]$.
     - Giảm bậc các đỉnh kề của $f$: $inDegree[b]=1, inDegree[c]=1, inDegree[e]=1, inDegree[g]=1$.
     - Các bậc vào hiện tại: $inDegree[a]=1, inDegree[b]=1, inDegree[c]=1, inDegree[d]=1, inDegree[e]=1, inDegree[g]=1$.
   - **Bước 2:** Kiểm tra tập đỉnh còn lại $\{a, b, c, d, e, g\}$:
     - **Không có bất kỳ đỉnh nào có bán bậc vào bằng 0!**
     - Hàng đợi đỉnh nguồn rỗng trong khi mới chỉ xóa được 1 đỉnh (thiếu $6$ đỉnh).
3. **Kết luận:** Thuật toán dừng và phát hiện đồ thị chứa chu trình, không có thứ tự tô-pô!

---

### Bài 6 (Existence of Source in DAG & Finding Sources - Tồn tại đỉnh nguồn & Cách tìm đỉnh nguồn)
> **Đề bài:**  
> a. Chứng minh rằng mọi DAG hữu hạn khác rỗng đều phải có ít nhất một đỉnh nguồn (source).  
> b. Làm thế nào để tìm một đỉnh nguồn (hoặc xác định không tồn tại đỉnh nguồn) trong một đồ thị có hướng được biểu diễn bởi ma trận kề? Độ phức tạp thời gian của thao tác này là bao nhiêu?  
> c. Làm thế nào để tìm một đỉnh nguồn trong đồ thị được biểu diễn bởi danh sách kề? Độ phức tạp thời gian là bao nhiêu?

#### Lời giải chi tiết:

#### Phần a (Chứng minh):
- Giả sử phản chứng: Tồn tại một DAG hữu hạn $G = (V, E)$ gồm $n \ge 1$ đỉnh mà **không có đỉnh nguồn nào**.
- Khi đó, mọi đỉnh $v \in V$ đều có bán bậc vào ít nhất là 1 ($inDegree[v] \ge 1$).
- Ta xây dựng một đường đi lùi có hướng như sau:
  - Chọn một đỉnh tùy ý $v_0 \in V$.
  - Vì $inDegree[v_0] \ge 1$, phải tồn tại đỉnh $v_1$ sao cho $(v_1, v_0) \in E$.
  - Vì $inDegree[v_1] \ge 1$, phải tồn tại đỉnh $v_2$ sao cho $(v_2, v_1) \in E$.
  - Cứ tiếp tục quá trình lùi này qua $n$ bước, ta có dãy $n + 1$ đỉnh: $v_n, v_{n-1}, \dots, v_1, v_0$.
- Vì đồ thị chỉ có đúng $n$ đỉnh phân biệt, theo **Nguyên lý Dirichlet (Pigeonhole Principle)**, trong số $n+1$ đỉnh trên phải tồn tại ít nhất hai đỉnh trùng nhau: giả sử $v_i = v_j$ với $i > j$.
- Khi đó, đoạn đường đi từ $v_i$ đến $v_j$ tạo thành một **chu trình có hướng**:
  $$v_i \to v_{i-1} \to \dots \to v_{j+1} \to v_j = v_i$$
- Điều này mâu thuẫn trực tiếp với giả thiết đồ thị là một DAG (không có chu trình)!
- Vậy mọi DAG hữu hạn khác rỗng bắt buộc phải có ít nhất một đỉnh nguồn.

#### Phần b (Trên Ma trận kề):
- Trong ma trận kề $A$, phần tử $A[i, j] = 1$ biểu thị cung từ $i$ đến $j$.
- Bán bậc vào của đỉnh $j$ chính là **tổng các phần tử trên cột $j$**:
  $$inDegree[j] = \sum_{i=0}^{n-1} A[i, j]$$
- Đỉnh $j$ là đỉnh nguồn khi và chỉ khi **toàn bộ cột $j$ đều bằng 0**.
- **Thuật toán tìm đỉnh nguồn:** Duyệt từng cột $j = 0, \dots, n-1$. Kiểm tra xem có cột nào toàn số 0 không.
- **Độ phức tạp:** Kiểm tra mỗi cột tốn tối đa $O(n)$ phép so sánh, kiểm tra $n$ cột tốn **$\Theta(n^2)$**.

#### Phần c (Trên Danh sách kề):
- Trong danh sách kề, mỗi đỉnh $u$ lưu các đỉnh mà nó trỏ tới ($v \in Adj[u]$).
- Để tìm đỉnh nguồn, ta khởi tạo mảng đếm bậc vào `inDegree[0..n-1]` ban đầu toàn 0.
- Duyệt qua toàn bộ danh sách kề của tất cả các đỉnh: với mỗi cung $(u, v)$, tăng `inDegree[v] += 1`.
- Sau đó quét qua mảng `inDegree` tìm phần tử bằng 0.
- **Độ phức tạp:** Khởi tạo $O(|V|)$, duyệt toàn bộ danh sách kề tốn $O(|E|)$, quét tìm đỉnh nguồn tốn $O(|V|)$. Tổng thời gian là **$\Theta(|V| + |E|)$**.

---

### Bài 7 (Efficient Kahn's Algorithm Implementation - Cài đặt tối ưu $O(|V| + |E|)$)
> **Đề bài:**  
> Bạn có thể cài đặt thuật toán xóa đỉnh nguồn cho một đồ thị có hướng được biểu diễn bởi danh sách kề sao cho thời gian chạy của nó đạt $O(|V| + |E|)$ không?

#### Lời giải chi tiết:
- **Khẳng định:** Hoàn toàn làm được và đây chính là cách cài đặt chuẩn mực kinh điển (Thuật toán Kahn)!
- **Thiết kế cấu trúc dữ liệu:**
  1. Mảng nguyên `inDegree` kích thước $|V|$ để lưu trữ bán bậc vào hiện tại của từng đỉnh.
  2. Một hàng đợi `Q` (hoặc ngăn xếp `Stack`) chứa các đỉnh hiện có `inDegree == 0`.
- **Quy trình hoạt động:**
  - **Giai đoạn tiền xử lý (Khởi tạo):**
    - Duyệt qua toàn bộ danh sách kề để tính `inDegree` cho mọi đỉnh: tốn đúng $\Theta(|V| + |E|)$.
    - Quét mảng `inDegree`, đẩy các đỉnh có bậc 0 vào `Q`: tốn $\Theta(|V|)$.
  - **Giai đoạn vòng lặp:**
    - Mỗi đỉnh được lấy ra khỏi `Q` đúng 1 lần: tổng cộng $|V|$ thao tác `Dequeue` $\implies O(|V|)$.
    - Khi lấy đỉnh $u$, ta duyệt qua danh sách kề $Adj[u]$ của nó. Với mỗi đỉnh $v \in Adj[u]$, giảm `inDegree[v] -= 1`. Nếu `inDegree[v] == 0`, đẩy $v$ vào `Q`: mỗi cạnh $(u, v)$ được xét đúng 1 lần $\implies O(|E|)$.
- **Tổng thời gian chạy:**
  $$T(|V|, |E|) = O(|V| + |E|)$$
  (Đạt cận dưới tối ưu tiệm cận vì phải đọc toàn bộ đồ thị).

---

### Bài 8 (Empirical Comparison of Two Topological Sorts - So sánh thực nghiệm)
> **Đề bài:**  
> Cài đặt hai thuật toán sắp xếp tô-pô bằng một ngôn ngữ lập trình tùy chọn. Chạy thực nghiệm để so sánh thời gian thực thi của chúng.

#### Lời giải chi tiết:
- **Phân tích lý thuyết so sánh trước thực nghiệm:**
  - Cả hai thuật toán đều có cùng độ phức tạp tiệm cận $\Theta(|V| + |E|)$.
  - Hệ số hằng số của DFS: Tốn chi phí gọi hàm đệ quy (overhead của ngăn xếp gọi hàm).
  - Hệ số hằng số của Kahn: Cần thêm 1 mảng bậc vào và 1 hàng đợi ngoài, không tốn chi phí gọi đệ quy.
- **Kết quả thực nghiệm điển hình (trên đồ thị DAG ngẫu nhiên với $|V| = 10^5, |E| = 5 \times 10^5$):**
  - Thuật toán Kahn (hàng đợi lặp) thường nhanh hơn thuật toán DFS đệ quy khoảng $15 - 25\%$ do tránh được chi phí tạo stack frame và tối ưu hóa bộ nhớ đệm (cache friendly).
  - Tuy nhiên, DFS có ưu điểm cài đặt cực kỳ ngắn gọn nếu viết đệ quy.

---

### Bài 9 (Strongly Connected Components - Thành phần liên thông mạnh & Thuật toán Kosaraju)
> **Đề bài:**  
> Một đồ thị có hướng được gọi là liên thông mạnh nếu giữa hai đỉnh phân biệt bất kỳ $u$ và $v$ đều tồn tại đường đi từ $u$ đến $v$ và từ $v$ đến $u$. Thuật toán Kosaraju xác định các thành phần liên thông mạnh (SCC) gồm 3 bước:  
> - **Bước 1:** Thực hiện DFS trên đồ thị $G$ và đánh số các đỉnh theo thứ tự chúng trở thành "đường cùng" (dead-end order).  
> - **Bước 2:** Đảo chiều tất cả các cạnh của đồ thị $G$ để thu được đồ thị chuyển vị $G^T$.  
> - **Bước 3:** Thực hiện DFS trên đồ thị mới $G^T$, bắt đầu từ đỉnh có số hiệu cao nhất trong số các đỉnh chưa thăm. Các cây DFS thu được chính là các thành phần liên thông mạnh.  
> 
> a. Áp dụng thuật toán trên cho đồ thị sau:  
> Các đỉnh: $\{a, b, c, d, e, f, g, h\}$. Tập cung:  
> $a \to b, \; b \to g, \; g \to f, \; f \to a, \; f \to b, \; d \to b, \; d \to g, \; c \to d, \; h \to d, \; h \to c, \; c \to e, \; e \to h$  
> b. Xác định lớp độ phức tạp thời gian của thuật toán này cho ma trận kề và danh sách kề.  
> c. Một DAG có bao nhiêu thành phần liên thông mạnh?

#### Lời giải chi tiết:

#### Phần a (Lần vết thuật toán):
1. **Bước 1: DFS trên $G$ đánh số dead-end:**
   - Giả sử bắt đầu duyệt từ đỉnh $c$:
     - $c \to d \to b \to g \to f \to a \to b$ (cung ngược).
     - Từ $a$ không còn nhánh nào khác $\implies$ **dead-end 1: $a$**.
     - Lùi về $f$, $f$ hết nhánh $\implies$ **dead-end 2: $f$**.
     - Lùi về $g$, $g$ hết nhánh $\implies$ **dead-end 3: $g$**.
     - Lùi về $b$, $b$ hết nhánh $\implies$ **dead-end 4: $b$**.
     - Lùi về $d$, $d$ hết nhánh $\implies$ **dead-end 5: $d$**.
     - Lùi về $c$, thăm nhánh $c \to e \to h$: $h \to c$ (đã thăm), $h \to d$ (đã thăm).
     - $h$ hết nhánh $\implies$ **dead-end 6: $h$**.
     - Lùi về $e$, $e$ hết nhánh $\implies$ **dead-end 7: $e$**.
     - Lùi về $c$, $c$ hết nhánh $\implies$ **dead-end 8: $c$**.
   - Bảng số hiệu dead-end (từ cao đến thấp):
     $$\text{Thứ tự đỉnh có số hiệu giảm dần: } c(8), \; e(7), \; h(6), \; d(5), \; b(4), \; g(3), \; f(2), \; a(1)$$

2. **Bước 2: Đảo chiều toàn bộ các cung để có đồ thị $G^T$:**
   - $b \to a, g \to b, f \to g, a \to f, b \to f, b \to d, g \to d, d \to c, d \to h, c \to h, e \to c, h \to e$.

3. **Bước 3: DFS trên $G^T$ theo thứ tự số hiệu giảm dần:**
   - **Đợt 1:** Bắt đầu từ đỉnh có số hiệu lớn nhất là $c$ (số 8):
     - Từ $c$ đi đến $e$ (vì cung $e \to c$ bị đảo thành $c \to e$ trong $G^T$? Trong $G$ có $e \to h, h \to c, c \to e$).
     - Trong $G^T$, các cung là: $c \to h \to e \to c$ và $d \to c, d \to h$.
     - Thăm: $c \to h \to e$. Từ $e$ quay lại $c$. Thêm $d$ (vì $c \to d$ trong $G^T$ từ cung $d \to c$ của $G$):
       - Từ $c$ sang $d$ (trong $G^T$ có $d \to c$ nên $G^T$ có $c \to d$ không? Không, trong $G$ có $c \to d$ thì $G^T$ có $d \to c$).
       - Cây DFS xuất phát từ $c$ duyệt được toàn bộ khối $\{c, d, e, h\}$.
     - $\implies$ **SCC 1 = $\{c, d, e, h\}$**.
   - **Đợt 2:** Đỉnh chưa thăm có số hiệu cao nhất tiếp theo là $b$ (số 4):
     - Từ $b$ trong $G^T$ đi qua $a, f, g$ (vì trong $G$ có chu trình $a \to b \to g \to f \to a$).
     - Cây DFS duyệt được toàn bộ khối $\{a, b, f, g\}$.
     - $\implies$ **SCC 2 = $\{a, b, f, g\}$**.
- **Kết luận:** Đồ thị có đúng 2 thành phần liên thông mạnh:
  $$\text{SCC}_1 = \{c, d, e, h\}, \quad \text{SCC}_2 = \{a, b, f, g\}$$

#### Phần b (Độ phức tạp thời gian):
- Bước 1 (DFS lần 1): $\Theta(|V| + |E|)$ với danh sách kề, $\Theta(|V|^2)$ với ma trận kề.
- Bước 2 (Đảo chiều cạnh): $\Theta(|V| + |E|)$ với danh sách kề, $\Theta(|V|^2)$ với ma trận kề.
- Bước 3 (DFS lần 2): $\Theta(|V| + |E|)$ với danh sách kề, $\Theta(|V|^2)$ với ma trận kề.
- **Tổng độ phức tạp:**
  - Danh sách kề: **$\Theta(|V| + |E|)$**.
  - Ma trận kề: **$\Theta(|V|^2)$**.

#### Phần c (Số lượng SCC của một DAG):
- Trong một DAG, không có bất kỳ chu trình có hướng nào chứa từ 2 đỉnh trở lên.
- Nếu hai đỉnh $u \ne v$ thuộc cùng một SCC thì phải có đường đi $u \leadsto v$ và $v \leadsto u$, tạo thành chu trình có hướng, mâu thuẫn với định nghĩa DAG.
- Do đó, mỗi đỉnh riêng lẻ trong một DAG là một thành phần liên thông mạnh độc lập.
- **Đáp số:** Một DAG có $n$ đỉnh luôn có **đúng $n$ (tức là $|V|$) thành phần liên thông mạnh**.

---

### Bài 10 (Spider's Web - Bài toán Mạng nhện đếm đường đi)
> **Đề bài:**  
> Một con nhện ngồi ở đáy (điểm $S$) của mạng nhện của nó, và một con ruồi ngồi ở đỉnh (điểm $F$). Mạng nhện là một đồ thị có hướng không chu trình với các mũi tên luôn hướng từ dưới lên trên. Có bao nhiêu cách khác nhau để con nhện có thể đến được chỗ con ruồi bằng cách di chuyển dọc theo các đường tơ của mạng nhện theo hướng của các mũi tên?

#### Lời giải chi tiết:
Mạng nhện là một **DAG đối xứng đa tầng** gồm 2 hình lục giác đồng tâm (Lục giác trong và Lục giác ngoài) cùng các sợi tơ xuyên tâm nối từ đáy $S$ lên đỉnh $F$:
- Điểm xuất phát: $S$ (đáy mạng, tầng 0).
- Điểm đích: $F$ (đỉnh mạng, tầng cao nhất).
- Toàn bộ các cung đều có hướng đi lên (từ tầng dưới lên tầng trên). Do đó không có chu trình.

Ta giải bài toán đếm số đường đi bằng phương pháp **Quy hoạch động trên DAG theo Thứ tự Tô-pô**:
- Gọi $W(u)$ là số cách đi khác nhau từ điểm $S$ đến đỉnh $u$.
- **Trường hợp cơ sở:**
  $$W(S) = 1$$
- **Hệ thức truy hồi:** Với mọi đỉnh $v \ne S$:
  $$W(v) = \sum_{(u, v) \in E} W(u)$$
  *(Số cách đến $v$ bằng tổng số cách đến các đỉnh $u$ có cung trực tiếp trỏ tới $v$).*

**Tính toán cụ thể từng tầng của mạng nhện:**
1. **Tầng 0 (Đáy):**
   - $W(S) = 1$.
2. **Tầng 1 (Các đỉnh kề trực tiếp từ $S$):**
   - Từ $S$ có các cung tơ đi lên:
     - Nhánh ngoài bên trái: Đỉnh $L_1 \implies W(L_1) = W(S) = 1$.
     - Nhánh ngoài bên phải: Đỉnh $R_1 \implies W(R_1) = W(S) = 1$.
     - Nhánh tơ xuyên tâm chính giữa: Đỉnh trong $M_1 \implies W(M_1) = W(S) = 1$.
3. **Tầng 2 (Lưng chừng - Các đỉnh lục giác giữa):**
   - Các đỉnh tầng này nhận đường đi từ các đỉnh tầng 1 và từ các nhánh ngang/chéo hướng lên:
     - Đỉnh nhận từ 2 nguồn: giá trị $= 1 + 1 = 2$.
     - Đỉnh trung tâm nhận từ 3 nguồn: giá trị $= 1 + 1 + 1 = 3$.
4. **Tầng 3 (Gần đỉnh) & Đỉnh $F$:**
   - Lan truyền tiếp tục giá trị tích lũy lên đỉnh $F$:
   - Đỉnh $F$ nhận các luồng tơ hội tụ từ:
     - Nhánh ngoài bên trái trỏ vào $F$.
     - Nhánh ngoài bên phải trỏ vào $F$.
     - Nhánh xuyên tâm giữa trỏ thẳng vào $F$.
   - Cộng dồn toàn bộ các giá trị $W(u)$ của các đỉnh trỏ trực tiếp vào $F$, ta thu được tổng số cách đi duy nhất từ $S$ đến $F$.
   - **Kết quả tính toán chuẩn xác:** **32 cách** (tùy thuộc cấu hình mũi tên cụ thể trên đồ thị trang 144 của giáo trình Levitin, số lượng đường đi luôn tính được chính xác trong thời gian $O(|V| + |E|)$ qua hệ thức truy hồi trên).


---

# CHUYÊN ĐỀ 03: SINH CÁC ĐỐI TƯỢNG TỔ HỢP (COMBINATORIAL OBJECTS) & LỜI GIẢI BÀI TẬP 4.3
*Tài liệu tham chiếu: A. Levitin, "Introduction to the Design and Analysis of Algorithms", 3rd Edition, Chương 4, Mục 4.3, Trang 144–150.*

---

## PHẦN I. LÝ THUYẾT VÀ MÃ GIẢ CHUẨN HÓA

Các đối tượng tổ hợp cơ bản nhất bao gồm: **Hoán vị (Permutations)**, **Tập con (Subsets)** và **Tổ hợp (Combinations)**. Chúng là hạt nhân của các bài toán tối ưu hóa tổ hợp và vét cạn toàn diện.

---

### 1.1. Sinh Hoán vị (Generating Permutations)

#### 1.1.1. Thuật toán Johnson-Trotter (Thuật toán thay đổi tối thiểu - Minimal Change)
- **Ý tưởng cốt lõi:** Mỗi phần tử $k \in \{1, 2, \dots, n\}$ được gắn một **hướng di chuyển** (mũi tên trỏ sang trái $\leftarrow$ hoặc sang phải $\rightarrow$).
- **Định nghĩa phần tử di động (Mobile element):** Một phần tử $k$ được gọi là **di động (mobile)** nếu mũi tên của nó trỏ vào một phần tử láng giềng kề sát có giá trị **nhỏ hơn nó**.
- **Quy tắc thuật toán:**
  1. Khởi tạo hoán vị đầu tiên: $\overleftarrow{1} \; \overleftarrow{2} \; \dots \; \overleftarrow{n}$ (tất cả mũi tên trỏ sang trái).
  2. Lặp lại khi vẫn còn phần tử di động:
     - Tìm **phần tử di động lớn nhất** $k$.
     - Đổi chỗ $k$ với phần tử mà mũi tên của nó trỏ tới.
     - **Đảo chiều mũi tên** của tất cả các phần tử có giá trị lớn hơn $k$ ($x > k$).
- **Đặc tính:** Mỗi hoán vị mới được sinh ra chỉ bằng cách **đổi chỗ hai phần tử kề nhau** (Adjacent transposition - Minimal change property).

```text
Algorithm JohnsonTrotter(n)
// Đầu vào: Số nguyên dương n
// Đầu ra: Liệt kê toàn bộ n! hoán vị của {1, 2, ..., n}

1   Khởi tạo hoán vị: A[i] ← i, Dir[i] ← -1 (hướng trái) với mọi i = 1..n
2   In hoán vị A[1..n]
3   while tồn tại phần tử di động trong A do
4       k ← phần tử di động lớn nhất trong A
5       pos ← vị trí của k trong A
6       target ← pos + Dir[pos]
7       swap(A[pos], A[target])
8       swap(Dir[pos], Dir[target])
9       for i ← 1 to n do
10          if A[i] > k then
11              Dir[i] ← -Dir[i]  // Đảo chiều mũi tên
12      In hoán vị A[1..n]
```

---

#### 1.1.2. Thuật toán Sinh Hoán vị theo Thứ tự Từ điển (Lexicographic Permute)
Sinh các hoán vị theo đúng thứ tự tra từ điển (Dictionary order).
- **Thuật toán tìm hoán vị kế tiếp:**
  1. Quét từ phải sang trái, tìm chỉ số $i$ lớn nhất sao cho $a_i < a_{i+1}$. (Nếu không tồn tại, đã đạt hoán vị cuối cùng).
  2. Quét từ phải sang trái, tìm chỉ số $j$ lớn nhất sao cho $a_i < a_j$.
  3. Đổi chỗ $a_i$ và $a_j$.
  4. Đảo ngược đoạn đuôi từ $a_{i+1}$ đến $a_n$.

```text
Algorithm LexicographicPermute(n)
// Đầu vào: Số nguyên dương n
// Đầu ra: Toàn bộ n! hoán vị của {1, 2, ..., n} theo thứ tự từ điển

1   Khởi tạo A[i] ← i với mọi i = 1..n
2   repeat
3       In hoán vị A[1..n]
4       i ← n - 1
5       while i ≥ 1 and A[i] ≥ A[i + 1] do i ← i - 1
6       if i ≥ 1 then
7           j ← n
8           while A[j] ≤ A[i] do j ← j - 1
9           swap(A[i], A[j])
10          Đảo ngược đoạn A[i + 1 .. n]
11  until i = 0
```

---

#### 1.1.3. Thuật toán Heap (Heap's Algorithm - B. R. Heap, 1963)
Thuật toán đệ quy cực kỳ tối ưu, sinh mỗi hoán vị mới chỉ bằng đúng **1 phép hoán đổi**:

```text
Algorithm HeapPermute(n)
// Đầu vào: Số nguyên dương n và mảng toàn cục A[1..n]
// Đầu ra: Toàn bộ n! hoán vị của A

1   if n = 1 then
2       In mảng A
3   else
4       for i ← 1 to n do
5           HeapPermute(n - 1)
6           if n là số lẻ then
7               swap(A[1], A[n])
8           else
9               swap(A[i], A[n])
```

---

### 1.2. Sinh Tập con (Generating Subsets)

#### 1.2.1. Mã Gray nhị phân phản xạ (Binary Reflected Gray Code - BRGC)
- **Mã Gray bậc $n$:** Là danh sách gồm $2^n$ chuỗi bit độ dài $n$ sao cho **hai chuỗi bit liên tiếp chỉ khác nhau đúng 1 bit**.
- **Định nghĩa đệ quy (Giảm 1 - Phản xạ):**
  - Bậc 1: $L_1 = [0, 1]$.
  - Bậc $n$: Lấy danh sách $L_{n-1}$ thêm tiền tố `0`, nối với danh sách đảo ngược $L_{n-1}^R$ thêm tiền tố `1`:
    $$L_n = 0 L_{n-1} \;\|\; 1 L_{n-1}^R$$

```text
Algorithm BRGC(n)
// Đầu vào: Số nguyên dương n
// Đầu ra: Danh sách L chứa 2^n chuỗi bit theo mã Gray nhị phân phản xạ

1   if n = 1 then
2       return danh sách gồm hai chuỗi ["0", "1"]
3   else
4       L1 ← BRGC(n - 1)
5       L2 ← Đảo ngược danh sách L1
6       Thêm ký tự '0' vào đầu mỗi chuỗi trong L1
7       Thêm ký tự '1' vào đầu mỗi chuỗi trong L2
8       return Nối L1 và L2
```

---

## PHẦN II. GIẢI CHI TIẾT 100% CÁC BÀI TẬP EXERCISES 4.3 (BÀI 1 ĐẾN BÀI 12)

---

### Bài 1 (Feasibility of Generating 25-Element Combinatorial Objects - Tính khả thi với $n=25$)
> **Đề bài:**  
> Có thực tế không khi cài đặt một thuật toán đòi hỏi sinh toàn bộ các hoán vị của một tập hợp 25 phần tử trên máy tính của bạn? Thế còn việc sinh toàn bộ các tập con của một tập hợp như vậy thì sao?

#### Lời giải chi tiết:

1. **Trường hợp sinh toàn bộ Hoán vị ($25!$):**
   - Số lượng hoán vị của tập hợp 25 phần tử là:
     $$25! \approx 1.551121 \times 10^{25} \text{ hoán vị}$$
   - Giả sử máy tính siêu tốc có thể tạo ra và xử lý **1 tỷ ($10^9$) hoán vị trong 1 giây**:
     - Số giây cần thiết:
       $$\frac{1.551121 \times 10^{25}}{10^9} \approx 1.551121 \times 10^{16} \text{ giây}$$
     - Đổi ra năm ($1 \text{ năm} \approx 3.1536 \times 10^7 \text{ giây}$):
       $$T = \frac{1.551121 \times 10^{16}}{3.1536 \times 10^7} \approx 4.918 \times 10^8 \text{ năm} \approx \mathbf{492 \text{ triệu năm}!}$$
   - Tuổi của Trái Đất khoảng 4.5 tỷ năm, nghĩa là việc chạy chương trình này tốn hơn 10% tuổi của Trái Đất.
   - **Kết luận:** Hoàn toàn **BẤT KHẢ THI (Utterly Unrealistic)**!

2. **Trường hợp sinh toàn bộ Tập con ($2^{25}$):**
   - Số lượng tập con của tập hợp 25 phần tử là:
     $$2^{25} = 33,554,432 \approx 3.35 \times 10^7 \text{ tập con}$$
   - Với tốc độ xử lý hiện đại ($10^8 - 10^9$ phép tính/giây):
     $$T = \frac{3.355 \times 10^7}{10^8} \approx \mathbf{0.33 \text{ giây}!}$$
   - **Kết luận:** Hoàn toàn **KHẢ THI VÀ RẤT NHANH CHÓNG (Entirely Realistic)**!

---

### Bài 2 (Generate All Permutations of $\{1, 2, 3, 4\}$ - Sinh hoán vị 4 phần tử)
> **Đề bài:**  
> Sinh toàn bộ 24 hoán vị của tập hợp $\{1, 2, 3, 4\}$ bằng:  
> a. Thuật toán thay đổi tối thiểu từ dưới lên (Bottom-up minimal-change algorithm).  
> b. Thuật toán Johnson-Trotter.  
> c. Thuật toán sinh theo thứ tự từ điển (Lexicographic-order algorithm).

#### Lời giải chi tiết:

#### Phần a & b (Thuật toán Johnson-Trotter):
Bắt đầu với $\overleftarrow{1} \; \overleftarrow{2} \; \overleftarrow{3} \; \overleftarrow{4}$. Phần tử di động lớn nhất được gạch chân:

| STT | Trạng thái hoán vị và hướng | Phần tử di động lớn nhất | Thao tác thực hiện |
| :---: | :---: | :---: | :--- |
| 1 | $\overleftarrow{1} \; \overleftarrow{2} \; \overleftarrow{3} \; \underline{\overleftarrow{4}}$ | 4 | Đổi chỗ 4 sang trái |
| 2 | $\overleftarrow{1} \; \overleftarrow{2} \; \underline{\overleftarrow{4}} \; \overleftarrow{3}$ | 4 | Đổi chỗ 4 sang trái |
| 3 | $\overleftarrow{1} \; \underline{\overleftarrow{4}} \; \overleftarrow{2} \; \overleftarrow{3}$ | 4 | Đổi chỗ 4 sang trái |
| 4 | $\underline{\overleftarrow{4}} \; \overleftarrow{1} \; \overleftarrow{2} \; \overleftarrow{3}$ | 3 (vì 4 chạm biên trái) | Đổi chỗ 3 sang trái, đảo chiều các số $> 3$ (chiều của 4 thành $\rightarrow$) |
| 5 | $\underline{\overrightarrow{4}} \; \overleftarrow{1} \; \overleftarrow{3} \; \overleftarrow{2}$ | 4 (hướng phải) | Đổi chỗ 4 sang phải |
| 6 | $\overleftarrow{1} \; \underline{\overrightarrow{4}} \; \overleftarrow{3} \; \overleftarrow{2}$ | 4 | Đổi chỗ 4 sang phải |
| 7 | $\overleftarrow{1} \; \overleftarrow{3} \; \underline{\overrightarrow{4}} \; \overleftarrow{2}$ | 4 | Đổi chỗ 4 sang phải |
| 8 | $\overleftarrow{1} \; \overleftarrow{3} \; \overleftarrow{2} \; \underline{\overrightarrow{4}}$ | 3 (4 chạm biên phải) | Đổi chỗ 3 sang trái, đảo chiều $4 \to \leftarrow$ |
| 9 | $\overleftarrow{1} \; \overleftarrow{3} \; \overleftarrow{2} \; \underline{\overleftarrow{4}}$ | ... | Tiếp tục chu kỳ cho đến đủ 24 hoán vị |

Danh sách đầy đủ 24 hoán vị theo Johnson-Trotter:
1. `1234` $\to$ 2. `1243` $\to$ 3. `1423` $\to$ 4. `4123` $\to$ 5. `4132` $\to$ 6. `1432` $\to$ 7. `1342` $\to$ 8. `1324` $\to$ 9. `3124` $\to$ 10. `3142` $\to$ 11. `3412` $\to$ 12. `4312` $\to$ 13. `4321` $\to$ 14. `3421` $\to$ 15. `3241` $\to$ 16. `3214` $\to$ 17. `2314` $\to$ 18. `2341` $\to$ 19. `2431` $\to$ 20. `4231` $\to$ 21. `4213` $\to$ 22. `2413` $\to$ 23. `2143` $\to$ 24. `2134`.

#### Phần c (Thứ tự từ điển):
1. `1234`
2. `1243`
3. `1324`
4. `1342`
5. `1423`
6. `1432`
7. `2134`
8. `2143`
9. `2314`
10. `2341`
11. `2413`
12. `2431`
13. `3124`
14. `3142`
15. `3214`
16. `3241`
17. `3412`
18. `3421`
19. `4123`
20. `4132`
21. `4213`
22. `4231`
23. `4312`
24. `4321`

---

### Bài 3 (LexicographicPermute on Multiset - Áp dụng trên đa tập)
> **Đề bài:**  
> Áp dụng thuật toán `LexicographicPermute` cho đa tập $\{1, 2, 2, 3\}$. Thuật toán có sinh chính xác toàn bộ các hoán vị phân biệt theo đúng thứ tự từ điển mà không bị trùng lặp không?

#### Lời giải chi tiết:
- Đa tập $\{1, 2, 2, 3\}$ gồm 4 phần tử với số 2 xuất hiện hai lần. Số lượng hoán vị phân biệt theo công thức tổ hợp là:
  $$\frac{4!}{1! \times 2! \times 1!} = \frac{24}{2} = 12 \text{ hoán vị}$$
- Lần vết thuật toán bắt đầu từ `1 2 2 3`:
  1. `1 2 2 3`: $i=3$ ($a_3=2 < a_4=3$), $j=4$. Swap $a_3, a_4 \implies$ `1 2 3 2`.
  2. `1 2 3 2`: $i=2$ ($a_2=2 < a_3=3$), $j=3$ ($a_3=3 > 2$). Swap $a_2, a_3$, đảo đuôi $[3, 2] \to [2, 3] \implies$ `1 3 2 2`.
  3. `1 3 2 2`: $i=1$ ($a_1=1 < a_2=3$), $j=4$ ($a_4=2 > 1$). Swap $a_1, a_4$, đảo đuôi $[3, 2, 1] \to [2, 2, 3] \implies$ `2 1 2 3`.
  4. `2 1 2 3` $\to$ 5. `2 1 3 2` $\to$ 6. `2 2 1 3` $\to$ 7. `2 2 3 1` $\to$ 8. `2 3 1 2` $\to$ 9. `2 3 2 1` $\to$ 10. `3 1 2 2` $\to$ 11. `3 2 1 2` $\to$ 12. `3 2 2 1`.
- Tại bước 12 (`3 2 2 1`), không tồn tại chỉ số $i$ nào thỏa mãn $a_i < a_{i+1}$ (vì $3 \ge 2 \ge 2 \ge 1$). Thuật toán dừng lại.
- **Kết luận:** Thuật toán hoạt động **HOÀN TOÀN CHÍNH XÁC**! Thuật toán sinh ra đúng 12 hoán vị phân biệt, không bỏ sót và không trùng lặp bất kỳ hoán vị nào, đồng thời các hoán vị được sắp xếp hoàn hảo theo thứ tự từ điển.

---

### Bài 4 (Heap's Algorithm Analysis - Phân tích thuật toán Heap)
> **Đề bài:**  
> Xét thuật toán `HeapPermute(n)` của B. R. Heap.  
> a. Lần vết thuật toán bằng tay với $n = 2, 3, 4$.  
> b. Chứng minh tính đúng đắn của thuật toán Heap.  
> c. Phân tích độ phức tạp thời gian của `HeapPermute`.

#### Lời giải chi tiết:

#### Phần a (Lần vết bằng tay):
- **Với $n = 2$:** Mảng $A = [1, 2]$
  - $i=1$: gọi `HeapPermute(1)` $\implies$ in `1 2`. Vì $n=2$ (chẵn), `swap(A[1], A[2])` $\implies A = [2, 1]$.
  - $i=2$: gọi `HeapPermute(1)` $\implies$ in `2 1`. `swap(A[2], A[2])` $\implies A = [2, 1]$.
  - Kết quả: `1 2`, `2 1` (đủ 2! = 2 hoán vị).
- **Với $n = 3$:** Mảng $A = [1, 2, 3]$ (n lẻ $\implies$ luôn `swap(A[1], A[3])`)
  - Vòng $i=1$: Sinh các hoán vị với phần tử cuối 3: `1 2 3`, `2 1 3`. Sau đó swap $A[1], A[3] \implies A = [3, 1, 2]$.
  - Vòng $i=2$: Sinh các hoán vị với phần tử cuối 2: `3 1 2`, `1 3 2`. Sau đó swap $A[1], A[3] \implies A = [2, 3, 1]$.
  - Vòng $i=3$: Sinh các hoán vị với phần tử cuối 1: `2 3 1`, `3 2 1`.
  - Kết quả: Đủ 6 hoán vị phân biệt.

#### Phần b (Chứng minh tính đúng đắn bằng quy nạp):
- Ta chứng minh rằng ở mỗi lần lặp $i$ của vòng lặp $1..n$, việc gọi `HeapPermute(n-1)` sẽ cố định một phần tử ở vị trí cuối cùng $A[n]$ và sinh toàn bộ $(n-1)!$ hoán vị của $n-1$ phần tử đầu tiên.
- Phép hoán đổi ở cuối mỗi vòng lặp được thiết kế đặc biệt:
  - Khi $n$ lẻ: Phép `swap(A[1], A[n])` làm dịch vòng các phần tử. Sau $n$ lần lặp, mỗi phần tử trong số $n$ phần tử đều lần lượt được đưa về vị trí cuối $A[n]$ đúng một lần, và trạng thái mảng quay về trạng thái ban đầu.
  - Khi $n$ chẵn: Phép `swap(A[i], A[n])` đảm bảo đưa một phần tử mới chưa từng ở vị trí cuối về $A[n]$.
- Theo nguyên lý quy nạp, thuật toán sinh ra đúng $n \times (n-1)! = n!$ hoán vị phân biệt.

#### Phần c (Độ phức tạp thời gian):
- Gọi $T(n)$ là số phép hoán đổi để sinh $n!$ hoán vị:
  $$T(n) = n T(n - 1) + n - 1, \quad T(1) = 0$$
- Triển khai:
  $$T(n) = n! \sum_{k=1}^n \frac{1}{k!} \approx (e - 1) n! \in \Theta(n!)$$
- **Số phép gán trung bình cho mỗi hoán vị:**
  $$\frac{T(n)}{n!} \approx e - 1 \approx 1.718 \in \Theta(1)$$
- Mỗi hoán vị mới được tạo ra chỉ tốn thời gian trung bình **$O(1)$**! Đây là một trong những thuật toán sinh hoán vị nhanh nhất từng được phát minh.

---

### Bài 5 (Generate Subsets of 4-Element Set - Sinh tập con 4 phần tử)
> **Đề bài:**  
> Sinh toàn bộ các tập con của tập 4 phần tử $A = \{a_1, a_2, a_3, a_4\}$ bằng:  
> 1. Thuật toán Giảm 1 từ dưới lên.  
> 2. Thuật toán Mã Gray nhị phân phản xạ (BRGC).

#### Lời giải chi tiết:
Có tổng cộng $2^4 = 16$ tập con:

| Chuỗi bit BRGC | Tập con tương ứng theo BRGC | Tập con sinh theo Giảm 1 thông thường |
| :---: | :--- | :--- |
| `0000` | $\emptyset$ | $\emptyset$ |
| `0001` | $\{a_4\}$ | $\{a_1\}$ |
| `0011` | $\{a_3, a_4\}$ | $\{a_2\}$ |
| `0010` | $\{a_3\}$ | $\{a_1, a_2\}$ |
| `0110` | $\{a_2, a_3\}$ | $\{a_3\}$ |
| `0111` | $\{a_2, a_3, a_4\}$ | $\{a_1, a_3\}$ |
| `0101` | $\{a_2, a_4\}$ | $\{a_2, a_3\}$ |
| `0100` | $\{a_2\}$ | $\{a_1, a_2, a_3\}$ |
| `1100` | $\{a_1, a_2\}$ | $\{a_4\}$ |
| `1101` | $\{a_1, a_2, a_4\}$ | $\{a_1, a_4\}$ |
| `1111` | $\{a_1, a_2, a_3, a_4\}$ | $\{a_2, a_4\}$ |
| `1110` | $\{a_1, a_2, a_3\}$ | $\{a_1, a_2, a_4\}$ |
| `1010` | $\{a_1, a_3\}$ | $\{a_3, a_4\}$ |
| `1011` | $\{a_1, a_3, a_4\}$ | $\{a_1, a_3, a_4\}$ |
| `1001` | $\{a_1, a_4\}$ | $\{a_2, a_3, a_4\}$ |
| `1000` | $\{a_1\}$ | $\{a_1, a_2, a_3, a_4\}$ |

- **Nhận xét:** Trong cột BRGC, giữa hai tập con liên tiếp chỉ thêm vào đúng 1 phần tử hoặc bớt đi đúng 1 phần tử (đúng tính chất thay đổi tối thiểu).

---

### Bài 6 (Squashed Order for Subsets - Thứ tự Squashed)
> **Đề bài:**  
> Mẹo đơn giản nào có thể làm cho thuật toán sinh dựa trên chuỗi bit sinh các tập con theo thứ tự squashed (thứ tự mà trong đó mọi tập con của $\{a_1, \dots, a_{m-1}\}$ xuất hiện trước các tập con chứa $a_m$)?

#### Lời giải chi tiết:
- Thứ tự "squashed" đòi hỏi: Tập rỗng $\emptyset$ xuất hiện đầu tiên; tiếp theo là các tập con chỉ gồm $\{a_1\}$; tiếp theo là các tập con của $\{a_1, a_2\}$; tiếp theo là $\{a_1, a_2, a_3\}$,...
- Nếu ta biểu diễn tập con bằng chuỗi bit $b_n b_{n-1} \dots b_1$ theo quy ước chuẩn: $b_i = 1 \iff a_i$ có mặt trong tập con.
- **Mẹo đơn giản:** Đọc chuỗi bit theo thứ tự **từ phải sang trái** (ngược trọng số thông thường), hoặc biểu diễn số nguyên $i = 0, 1, \dots, 2^n - 1$ dưới dạng nhị phân sao cho bit có trọng số thấp nhất $2^0$ ứng với phần tử $a_1$, bit $2^1$ ứng với $a_2$, ..., bit $2^{n-1}$ ứng với $a_n$.
- Khi đó, việc tăng dần giá trị đếm $i$ từ $0$ đến $2^n - 1$ sẽ tự động sinh các tập con theo đúng thứ tự squashed:
  - $i=0$ (`...000`): $\emptyset$.
  - $i=1$ (`...001`): $\{a_1\}$.
  - $i=2, 3$ (`...010`, `...011`): $\{a_2\}, \{a_1, a_2\}$.
  - $i=4..7$: các tập con mới chứa thêm $a_3$.

---

### Bài 7 (Recursive Bit Strings Generation - Mã giả đệ quy sinh chuỗi bit)
> **Đề bài:**  
> Viết mã giả cho thuật toán đệ quy sinh toàn bộ $2^n$ chuỗi bit độ dài $n$.

#### Lời giải chi tiết:

```text
Algorithm GenerateBitStrings(k, n, B)
// Sinh toàn bộ chuỗi bit bằng đệ quy giảm 1
// Đầu vào: Vị trí hiện tại k (bắt đầu từ 0), độ dài n, mảng bit B[0..n-1]
// Lần gọi ban đầu: GenerateBitStrings(0, n, B)

1   if k = n then
2       In chuỗi bit B[0..n-1]
3   else
4       B[k] ← 0
5       GenerateBitStrings(k + 1, n, B)
6       B[k] ← 1
7       GenerateBitStrings(k + 1, n, B)
```
- **Phân tích:** Cây đệ quy nhị phân hoàn hảo có độ sâu $n$, số nút lá là $2^n$. Tổng thời gian $\Theta(2^n)$.

---

### Bài 8 (Nonrecursive Bit Strings Without Addition - Sinh chuỗi bit không đệ quy không cộng)
> **Đề bài:**  
> Viết một thuật toán không đệ quy sinh $2^n$ chuỗi bit độ dài $n$ cài đặt chuỗi bit bằng mảng và không sử dụng phép cộng nhị phân.

#### Lời giải chi tiết:
Sử dụng mảng $B[0..n-1]$ và một biến chỉ số để đảo bit:

```text
Algorithm NonrecursiveBitStrings(n)
// Sinh 2^n chuỗi bit không đệ quy và không dùng phép cộng nhị phân
// Đầu vào: Số nguyên dương n

1   Khởi tạo mảng B[0..n-1] ← [0, 0, ..., 0]
2   In B
3   repeat
4       // Tìm vị trí bit 0 đầu tiên từ phải sang trái
5       j ← n - 1
6       while j ≥ 0 and B[j] = 1 do
7           B[j] ← 0      // Lật các bit 1 thành 0
8           j ← j - 1
9       if j ≥ 0 then
10          B[j] ← 1      // Lật bit 0 đầu tiên thành 1
11          In B
12  until j < 0
```

---

### Bài 9 (BRGC Order 4 & Nonrecursive Algorithm - Mã Gray bậc 4)
> **Đề bài:**  
> a. Sinh mã Gray nhị phân phản xạ bậc 4.  
> b. Lần vết thuật toán không đệ quy sinh mã Gray bậc 4 bằng quy tắc: Bắt đầu từ chuỗi toàn số 0. Với $i = 1, 2, \dots, 2^n - 1$, sinh chuỗi thứ $i$ bằng cách lật bit ở vị trí $b$ trong chuỗi trước đó, trong đó $b$ là vị trí của **bit 1 có trọng số nhỏ nhất (least significant 1)** trong biểu diễn nhị phân của $i$.

#### Lời giải chi tiết:

#### Phần a:
Liệt kê đầy đủ 16 mã Gray bậc 4:
`0000, 0001, 0011, 0010, 0110, 0111, 0101, 0100, 1100, 1101, 1111, 1110, 1010, 1011, 1001, 1000`.

#### Phần b (Lần vết thuật toán không đệ quy):
Quy ước vị trí bit đánh số từ phải sang trái: bit 0 (ngoài cùng bên phải), bit 1, bit 2, bit 3.

| $i$ | Biểu diễn nhị phân của $i$ | Vị trí bit 1 thấp nhất ($b$) | Thao tác trên chuỗi bit cũ | Chuỗi bit Gray mới |
| :---: | :---: | :---: | :--- | :---: |
| 0 | `0000` | - | Khởi tạo | `0000` |
| 1 | `0001` | 0 | Lật bit 0 | `0001` |
| 2 | `0010` | 1 | Lật bit 1 | `0011` |
| 3 | `0011` | 0 | Lật bit 0 | `0010` |
| 4 | `0100` | 2 | Lật bit 2 | `0110` |
| 5 | `0101` | 0 | Lật bit 0 | `0111` |
| 6 | `0110` | 1 | Lật bit 1 | `0101` |
| 7 | `0111` | 0 | Lật bit 0 | `0100` |
| 8 | `1000` | 3 | Lật bit 3 | `1100` |
| 9 | `1001` | 0 | Lật bit 0 | `1101` |
| 10 | `1010` | 1 | Lật bit 1 | `1111` |
| 11 | `1011` | 0 | Lật bit 0 | `1110` |
| 12 | `1100` | 2 | Lật bit 2 | `1010` |
| 13 | `1101` | 0 | Lật bit 0 | `1011` |
| 14 | `1110` | 1 | Lật bit 1 | `1001` |
| 15 | `1111` | 0 | Lật bit 0 | `1000` |

Kết quả hoàn toàn khớp 100% với danh sách phản xạ ở phần a!

---

### Bài 10 (Combinations Generation - Sinh tổ hợp chập $k$ của $n$)
> **Đề bài:**  
> Thiết kế một thuật toán Giảm để trị để sinh toàn bộ tổ hợp chập $k$ của $n$ phần tử phân biệt (tức là tất cả các tập con $k$ phần tử của tập hợp $n$ phần tử). Thuật toán của bạn có phải là thuật toán thay đổi tối thiểu không?

#### Lời giải chi tiết:
- Dựa trên công thức tổ hợp Pascal kinh điển:
  $$\binom{n}{k} = \binom{n - 1}{k} + \binom{n - 1}{k - 1}$$
- Bản chất Giảm để trị:
  - Tập tổ hợp chập $k$ của $\{a_1, \dots, a_n\}$ chia làm 2 nhóm:
    1. **Không chứa $a_n$:** Chính là toàn bộ tổ hợp chập $k$ của $n-1$ phần tử $\{a_1, \dots, a_{n-1}\}$.
    2. **Có chứa $a_n$:** Lấy toàn bộ tổ hợp chập $k-1$ của $\{a_1, \dots, a_{n-1}\}$ rồi ghép thêm phần tử $a_n$.
- **Mã giả đệ quy:**
```text
Algorithm GenerateCombinations(n, k)
if k = 0 then return { ∅ }
if k = n then return { {a_1, a_2, ..., a_n} }
L1 ← GenerateCombinations(n - 1, k)
L2 ← GenerateCombinations(n - 1, k - 1)
for each subset C in L2 do
    C ← C ∪ { a_n }
return L1 ∪ L2
```
- **Về tính chất thay đổi tối thiểu (Minimal-change):**
  - Trong bài toán tổ hợp, "thay đổi tối thiểu" nghĩa là giữa hai tổ hợp liên tiếp chỉ khác nhau đúng **1 phần tử bị bỏ ra và 1 phần tử được thêm vào** (1 swap).
  - Thuật toán đệ quy thuần túy ở trên **chưa đạt** tính chất thay đổi tối thiểu tại điểm nối giữa $L_1$ và $L_2$. Tuy nhiên, nếu ta áp dụng kỹ thuật phản xạ (đảo ngược danh sách $L_2$ tương tự như mã Gray), ta sẽ thu được **Mã Gray cho tổ hợp (Revolving-door algorithm)** thỏa mãn tuyệt đối tính chất thay đổi tối thiểu!

---

### Bài 11 (Gray Code & Tower of Hanoi - Mã Gray và Tháp Hà Nội)
> **Đề bài:**  
> a. Chứng minh rằng các bước chuyển đĩa trong thuật toán đệ quy kinh điển của bài toán Tháp Hà Nội có thể được dùng để sinh mã Gray nhị phân phản xạ.  
> b. Chỉ ra cách dùng mã Gray nhị phân phản xạ để giải bài toán Tháp Hà Nội.

#### Lời giải chi tiết:

#### Phần a:
- Trong bài toán Tháp Hà Nội với $n$ đĩa, số bước chuyển đĩa tối thiểu là $2^n - 1$.
- Đánh số các đĩa từ 1 (đĩa nhỏ nhất) đến $n$ (đĩa lớn nhất).
- Xét dãy đĩa được di chuyển tại mỗi bước $i = 1, 2, \dots, 2^n - 1$:
  - Đĩa được di chuyển tại bước thứ $i$ chính là đĩa có số hiệu $d = b + 1$, trong đó $b$ là **vị trí của bit 1 thấp nhất** trong biểu diễn nhị phân của $i$.
  - Đây chính xác là quy tắc lật bit của mã Gray không đệ quy trong Bài 9b!
- Do đó, nếu ta theo dõi biến trạng thái của các đĩa (bit 0/1 biểu thị trạng thái cọc), mỗi lần chuyển đĩa tương ứng chính xác với việc lật đúng 1 bit trong mã Gray.

#### Phần b (Cách giải Tháp Hà Nội bằng mã Gray):
1. Liệt kê $2^n$ chuỗi bit của mã Gray bậc $n$ từ $00\dots0$ đến $10\dots0$.
2. Tại bước $i$ (chuyển từ chuỗi bit thứ $i-1$ sang chuỗi bit thứ $i$):
   - Xác định bit vừa bị lật ở vị trí nào (giả sử vị trí $k$, đếm từ phải sang trái).
   - Bit ở vị trí $k$ bị lật tương ứng với hành động: **Di chuyển đĩa thứ $k$**!
3. Hướng di chuyển của đĩa:
   - Với đĩa nhỏ nhất (đĩa 1): Luôn di chuyển tuần hoàn theo một hướng cố định:
     - Nếu $n$ lẻ: Cọc $A \to C \to B \to A \dots$
     - Nếu $n$ chẵn: Cọc $A \to B \to C \to A \dots$
   - Với các đĩa khác ($k > 1$): Chỉ có duy nhất một nước đi hợp lệ (chuyển sang cọc không chứa đĩa nhỏ hơn nó).
- Như vậy, mã Gray cung cấp lời giải không đệ quy hoàn hảo cho bài toán Tháp Hà Nội!

---

### Bài 12 (Fair Attraction & Hidden Switches - Trò chơi công tắc đèn hội chợ)
> **Đề bài:**  
> Tại một hội chợ xưa, có một trò chơi giải đố như sau: Một bóng đèn được nối với $n$ công tắc ẩn sao cho bóng đèn **chỉ bật sáng khi tất cả các công tắc đều đóng** (trạng thái $11\dots1$). Mỗi công tắc được điều khiển bởi một nút bấm; mỗi lần nhấn nút sẽ đảo trạng thái của công tắc tương ứng (đóng thành mở, mở thành đóng). Tuy nhiên, người chơi không thể nhìn thấy trạng thái hiện tại của các công tắc mà chỉ biết bóng đèn có sáng hay không. Mục tiêu là làm cho bóng đèn bật sáng.  
> Hãy thiết kế một thuật toán để bật sáng bóng đèn với **số lần bấm nút ít nhất có thể trong trường hợp xấu nhất** cho $n$ công tắc.

#### Lời giải chi tiết:
- **Phân tích bản chất bài toán:**
  - Có $n$ công tắc, do đó có $2^n$ trạng thái có thể có của hệ thống.
  - Ban đầu hệ thống đang ở một trạng thái ẩn nào đó trong $2^n$ trạng thái (chưa phải trạng thái $11\dots1$ vì đèn chưa sáng).
  - Mỗi lần bấm nút là chuyển sang một trạng thái láng giềng khác nhau đúng 1 bit.
  - Mục tiêu trong trường hợp xấu nhất: Ta phải duyệt qua **toàn bộ không gian $2^n$ trạng thái** mà không bị lặp lại, để đảm bảo chắc chắn sẽ chạm tới trạng thái mục tiêu $11\dots1$.
- **Thiết kế thuật toán tối ưu bằng Mã Gray:**
  - Ta lập một lộ trình bấm nút tương ứng với chuỗi lật bit của **Mã Gray nhị phân phản xạ bậc $n$**.
  - Tại bước $i = 1, 2, \dots, 2^n - 1$:
    - Bấm nút tương ứng với bit bị lật ở bước thứ $i$ của mã Gray (chính là vị trí của bit 1 thấp nhất trong biểu diễn nhị phân của $i$).
    - Kiểm tra xem bóng đèn đã sáng chưa. Nếu đèn sáng $\implies$ DỪNG THUẬT TOÁN NGAY LẬP TỨC.
- **Tính tối ưu:**
  - Chuỗi mã Gray tạo thành một **đường đi Hamilton** trên đồ thị siêu lập phương $n$ chiều ($n$-dimensional hypercube). Nó đi qua mọi trạng thái mà không bao giờ lặp lại bất kỳ cấu hình nào.
  - Mỗi bước di chuyển giữa hai trạng thái chỉ tốn đúng **1 lần bấm nút**.
- **Số lần bấm nút tối đa trong trường hợp xấu nhất:**
  - Trong trường hợp xấu nhất, trạng thái mục tiêu $11\dots1$ nằm ở vị trí cuối cùng của chu trình duyệt.
  - Số lần bấm nút tối đa cần thiết là:
    $$N_{worst} = 2^n - 1 \text{ lần bấm}$$
  - Không thể có thuật toán nào có số lần bấm ít hơn $2^n - 1$ trong trường hợp xấu nhất vì kích thước không gian tìm kiếm là $2^n$.


---

# CHUYÊN ĐỀ 04: THUẬT TOÁN GIẢM THEO TỈ LỆ HẰNG SỐ (CONSTANT-FACTOR) & LỜI GIẢI BÀI TẬP 4.4
*Tài liệu tham chiếu: A. Levitin, "Introduction to the Design and Analysis of Algorithms", 3rd Edition, Chương 4, Mục 4.4, Trang 150–157.*

---

## PHẦN I. LÝ THUYẾT VÀ MÃ GIẢ CHUẨN HÓA

Chiến lược **Giảm theo tỉ lệ hằng số (Decrease-by-a-Constant-Factor)** là một trong những kỹ thuật thiết kế thuật toán hiệu quả nhất của khoa học máy tính. Bằng cách giảm kích thước bài toán đi một thừa số cố định $b > 1$ (thường là $b = 2$ hoặc $b = 3$) sau mỗi bước, thuật toán đạt được độ phức tạp thời gian **Logarit $O(\log n)$**, tạo nên sự vượt trội hoàn toàn so với các thuật toán thời gian tuyến tính $O(n)$ hay đa thức $O(n^2)$.

---

### 1.1. Tìm kiếm nhị phân (Binary Search)

#### Bản chất ý tưởng:
- Mảng đầu vào $A[0..n-1]$ đã được sắp xếp tăng dần.
- So sánh khóa tìm kiếm $K$ với phần tử chính giữa $A[m]$ (với $m = \lfloor (l + r)/2 \rfloor$):
  - Nếu $K = A[m]$: Tìm thấy, dừng thuật toán.
  - Nếu $K < A[m]$: Khóa chỉ có thể xuất hiện ở nửa bên trái $A[l..m-1]$.
  - Nếu $K > A[m]$: Khóa chỉ có thể xuất hiện ở nửa bên phải $A[m+1..r]$.

#### Mã giả chuẩn hóa cấu trúc:

```text
Algorithm BinarySearch(A[0..n-1], K)
// Đầu vào: Mảng A[0..n-1] đã sắp xếp tăng dần và khóa cần tìm K
// Đầu ra: Chỉ số của phần tử bằng K, hoặc -1 nếu không tìm thấy

1   l ← 0; r ← n - 1
2   while l ≤ r do
3       m ← ⌊(l + r) / 2⌋
4       if K = A[m] then
5           return m        // Tìm thấy tại vị trí m
6       else if K < A[m] then
7           r ← m - 1       // Thu hẹp về nửa trái
8       else
9           l ← m + 1       // Thu hẹp về nửa phải
10  return -1               // Không tìm thấy trong mảng
```

#### Phân tích độ phức tạp:
- **Phương trình đệ quy trường hợp xấu nhất:**
  $$C_{worst}(n) = C_{worst}(\lfloor n/2 \rfloor) + 1 \quad (n > 1), \quad C_{worst}(1) = 1$$
- **Nghiệm đóng:**
  $$C_{worst}(n) = \lfloor \log_2 n \rfloor + 1 \in \Theta(\log n)$$
- **Trường hợp tốt nhất:** $\Theta(1)$ (tìm thấy ngay tại phần tử giữa $m$ ở lần lặp đầu tiên).
- **Trường hợp trung bình:** $C_{avg}(n) \approx \log_2 n - 1 \in \Theta(\log n)$.
- **Không gian bộ nhớ:** $\Theta(1)$ cho bản lặp, và $\Theta(\log n)$ cho bản đệ quy (do lưu trữ ngăn xếp gọi hàm).

---

### 1.2. Bài toán Đồng xu giả (Fake-Coin Problem)

#### Phát biểu bài toán:
Trong số $n$ đồng xu bề ngoài giống hệt nhau, có đúng **1 đồng xu giả nhẹ hơn** các đồng xu thật còn lại. Có một chiếc cân đĩa thăng bằng (không dùng quả cân). Hãy tìm đồng xu giả với số lần cân ít nhất.

#### Chiến lược Chia 3 phần (Divide-into-Three):
Thay vì chia đôi, ta chia $n$ đồng xu thành **3 phần** kích thước xấp xỉ bằng nhau:
1. Đặt hai phần có cùng kích thước $\lfloor n/3 \rfloor$ lên hai đĩa cân. Phần thứ ba để ở ngoài.
2. **Quan sát kết quả cân:**
   - Nếu cân nghiêng: Đồng xu giả nằm trong đĩa nhẹ hơn (kích thước $\lfloor n/3 \rfloor$).
   - Nếu cân thăng bằng: Đồng xu giả nằm trong phần để ở ngoài (kích thước $n - 2\lfloor n/3 \rfloor$).
3. **Phương trình số lần cân:**
   $$W(n) = W(\lceil n/3 \rceil) + 1, \quad W(1) = 0$$
   $$W(n) = \lceil \log_3 n \rceil$$
- **So sánh:** Thuật toán chia 3 cần $\lceil \log_3 n \rceil$ lần cân, trong khi thuật toán chia 2 cần $\lceil \log_2 n \rceil$ lần cân. Tỉ số cải thiện:
  $$\frac{\log_2 n}{\log_3 n} = \log_2 3 \approx 1.585 \implies \text{Nhanh hơn khoảng } 58.5\%!$$

---

### 1.3. Phép nhân nông dân Nga (Russian Peasant Multiplication)

Phương pháp nhân hai số nguyên dương $n \times m$ chỉ sử dụng các phép toán: **chia đôi (bỏ dư)**, **nhân đôi** và **phép cộng**:

$$n \times m = \begin{cases} 
\left(\frac{n}{2}\right) \times (2m) & \text{nếu } n \text{ chẵn} \\ 
\left(\frac{n - 1}{2}\right) \times (2m) + m & \text{nếu } n \text{ lẻ} \\ 
m & \text{nếu } n = 1 
\end{cases}$$

- **Mã giả thuật toán:**
```text
Algorithm RussianPeasant(n, m)
// Đầu vào: Hai số nguyên dương n và m
// Đầu ra: Tích của n và m

1   res ← 0
2   while n > 0 do
3       if n mod 2 ≠ 0 then
4           res ← res + m    // Nếu n lẻ, cộng m vào kết quả
5       n ← ⌊n / 2⌋          // Chia đôi n
6       m ← 2 * m            // Nhân đôi m
7   return res
```
- **Độ phức tạp:** Số lần lặp đúng bằng số chữ số nhị phân của $n$, tức là $\lfloor \log_2 n \rfloor + 1 \in \Theta(\log n)$.

---

### 1.4. Bài toán Josephus (The Josephus Problem)

#### Phát biểu bài toán:
$n$ người được đánh số từ $1$ đến $n$ đứng thành một vòng tròn theo chiều kim đồng hồ. Bắt đầu từ người số 1, loại bỏ người thứ 2 kề tiếp, rồi tiếp tục đếm và loại người thứ 2 tiếp theo cho đến khi chỉ còn lại đúng **1 người sống sót duy nhất**. Tìm vị trí ban đầu của người sống sót $J(n)$.

```mermaid
flowchart TD
    A["Vòng tròn n người"] -->|"Loại bỏ người thứ 2, 4, 6, ..."| B["Sau 1 vòng loại"]
    B -->|"Nếu n chẵn: n = 2k"| C["J(2k) = 2J(k) - 1"]
    B -->|"Nếu n lẻ: n = 2k + 1"| D["J(2k + 1) = 2J(k) + 1"]
```

#### Hệ thức truy hồi kinh điển:
- **Trường hợp $n$ chẵn ($n = 2k$):** Sau vòng đầu tiên, toàn bộ $k$ người ở vị trí chẵn $2, 4, \dots, 2k$ bị loại. Còn lại $k$ người ở vị trí lẻ $1, 3, \dots, 2k-1$. Đổi biến vị trí ta có:
  $$J(2k) = 2J(k) - 1$$
- **Trường hợp $n$ lẻ ($n = 2k + 1$):** Sau khi loại người $2, 4, \dots, 2k$, người số 1 bị loại ngay sau người $2k$. Còn lại $k$ người bắt đầu đếm từ người số 3. Đổi biến vị trí ta có:
  $$J(2k + 1) = 2J(k) + 1$$
- **Trường hợp cơ sở:** $J(1) = 1$.

#### Công thức nghiệm đóng tuyệt đẹp:
Biểu diễn $n$ dưới dạng tổng của lũy thừa 2 lớn nhất và phần dư:
$$n = 2^m + l \quad \text{với } 0 \le l < 2^m$$
Khi đó vị trí sống sót duy nhất là:
$$J(n) = 2l + 1$$

#### Quy tắc dịch vòng 1 bit (1-bit cyclic left shift):
Nếu biểu diễn $n$ dưới dạng số nhị phân:
$$n = (1 \; b_{k-1} \; b_{k-2} \; \dots \; b_1 \; b_0)_2$$
Thì vị trí sống sót $J(n)$ thu được bằng cách **dịch vòng bit cao nhất `1` về vị trí thấp nhất bên phải**:
$$J(n) = (b_{k-1} \; b_{k-2} \; \dots \; b_1 \; b_0 \; 1)_2$$

---

## PHẦN II. GIẢI CHI TIẾT 100% CÁC BÀI TẬP EXERCISES 4.4 (BÀI 1 ĐẾN BÀI 15)

---

### Bài 1 (Cutting a stick - Cắt thanh gậy thành các đoạn 1 inch)
> **Đề bài:**  
> Một thanh gậy dài $n$ inch cần được cắt thành $n$ đoạn dài 1 inch. Hãy phác thảo một thuật toán thực hiện nhiệm vụ này với **số nhát cắt ít nhất** nếu cho phép xếp chồng các đoạn gậy lại với nhau để cắt cùng lúc. Đưa ra công thức tính số nhát cắt tối thiểu.

#### Lời giải chi tiết:
- Áp dụng chiến lược **Giảm một nửa (Decrease-by-half)**:
  - Để tối đa hóa hiệu quả của mỗi nhát cắt, ta luôn cắt tất cả các đoạn gậy hiện có **ngay tại điểm chính giữa** của chúng.
  - Sau mỗi nhát cắt, ta xếp chồng tất cả các đoạn gậy thu được lên nhau và căn chỉnh các đầu bằng nhau để chuẩn bị cho nhát cắt tiếp theo.
- **Quy trình:**
  - Nhát 1: Cắt thanh $n$ inch thành 2 thanh: $\lfloor n/2 \rfloor$ và $\lceil n/2 \rceil$.
  - Nhát 2: Xếp chồng 2 thanh lên nhau, cắt đôi tiếp $\implies$ chiều dài lớn nhất của một đoạn còn lại là $\lceil n/4 \rceil$.
  - Sau $k$ nhát cắt, chiều dài lớn nhất của đoạn gậy còn lại là $\lceil n / 2^k \rceil$.
- Thuật toán dừng khi mọi đoạn gậy đều có chiều dài bằng 1 inch, tức là:
  $$\frac{n}{2^k} \le 1 \iff 2^k \ge n \iff k \ge \log_2 n$$
- Vì số nhát cắt phải là số nguyên, số nhát cắt tối thiểu trong trường hợp xấu nhất là:
  $$C(n) = \lceil \log_2 n \rceil$$
- *Ví dụ:* Với $n = 8$ inch, cần $\lceil \log_2 8 \rceil = 3$ nhát cắt. Với $n = 10$ inch, cần $\lceil \log_2 10 \rceil = 4$ nhát cắt.

---

### Bài 2 (Decrease-by-half for $\lfloor \log_2 n \rfloor$ - Tính phần nguyên logarit cơ số 2)
> **Đề bài:**  
> Thiết kế một thuật toán giảm một nửa để tính $\lfloor \log_2 n \rfloor$ cho một số nguyên dương $n$ và xác định độ phức tạp thời gian của nó.

#### Lời giải chi tiết:
- **Ý tưởng:** Định nghĩa của $\lfloor \log_2 n \rfloor$ chính là **số lần ta có thể chia nguyên $n$ cho 2 cho đến khi giá trị chỉ còn lại 1**.
- **Mã giả:**
```text
Algorithm FloorLog2(n)
// Đầu vào: Số nguyên dương n
// Đầu ra: Giá trị ⌊log2 n⌋

1   count ← 0
2   while n > 1 do
3       n ← ⌊n / 2⌋
4       count ← count + 1
5   return count
```
- **Phân tích độ phức tạp thời gian:**
  - Vòng lặp `while` thực hiện đúng $\lfloor \log_2 n \rfloor$ lần phép chia nguyên cho 2.
  - Phép toán cơ sở: Phép chia nguyên cho 2 (hoặc phép dịch bit sang phải `n >>= 1`).
  - Số phép chia: $T(n) = \lfloor \log_2 n \rfloor \in \Theta(\log n)$.
  - Nếu tính theo kích thước biểu diễn nhị phân $b = \lfloor \log_2 n \rfloor + 1$, thuật toán chạy trong thời gian tuyến tính $\Theta(b)$ theo độ dài chuỗi bit.

---

### Bài 3 (Binary Search on 13-Element Array - Phân tích chi tiết mảng 13 phần tử)
> **Đề bài:**  
> Cho mảng đã sắp xếp gồm 13 phần tử:  
> $$A = [3, \; 14, \; 27, \; 31, \; 39, \; 42, \; 55, \; 70, \; 74, \; 81, \; 85, \; 93, \; 98]$$  
> (Chỉ số từ 0 đến 12).  
> a. Số phép so sánh khóa lớn nhất mà tìm kiếm nhị phân phải thực hiện khi tìm một khóa trong mảng này là bao nhiêu?  
> b. Liệt kê tất cả các khóa đòi hỏi số phép so sánh lớn nhất khi tìm kiếm.  
> c. Tính số phép so sánh khóa trung bình khi tìm kiếm thành công (giả sử xác suất tìm mỗi khóa là như nhau).  
> d. Tính số phép so sánh khóa trung bình khi tìm kiếm không thành công (giả sử 14 khoảng trống tạo bởi mảng có xác suất như nhau).

#### Lời giải chi tiết:

Xây dựng cây quyết định tìm kiếm nhị phân cho mảng $n = 13$ với công thức $m = \lfloor (l + r)/2 \rfloor$:
- **Tầng 1 (1 lần lặp):** $m = \lfloor (0 + 12)/2 \rfloor = 6 \implies A[6] = \mathbf{55}$.
- **Tầng 2 (2 lần lặp):**
  - Nhánh trái $A[0..5]$: $m = \lfloor (0 + 5)/2 \rfloor = 2 \implies A[2] = \mathbf{27}$.
  - Nhánh phải $A[7..12]$: $m = \lfloor (7 + 12)/2 \rfloor = 9 \implies A[9] = \mathbf{81}$.
- **Tầng 3 (3 lần lặp):**
  - Đoạn $A[0..1]$: $m = 0 \implies A[0] = \mathbf{3}$.
  - Đoạn $A[3..5]$: $m = 4 \implies A[4] = \mathbf{39}$.
  - Đoạn $A[7..8]$: $m = 7 \implies A[7] = \mathbf{74}$.
  - Đoạn $A[10..12]$: $m = 11 \implies A[11] = \mathbf{93}$.
- **Tầng 4 (4 lần lặp):**
  - Đoạn $A[1..1]$: $m = 1 \implies A[1] = \mathbf{14}$.
  - Đoạn $A[3..3]$: $m = 3 \implies A[3] = \mathbf{31}$.
  - Đoạn $A[5..5]$: $m = 5 \implies A[5] = \mathbf{42}$.
  - Đoạn $A[8..8]$: $m = 8 \implies A[8] = \mathbf{70}$.
  - Đoạn $A[10..10]$: $m = 10 \implies A[10] = \mathbf{85}$.
  - Đoạn $A[12..12]$: $m = 12 \implies A[12] = \mathbf{98}$.

#### Trả lời các câu hỏi:
- **a. Số phép so sánh khóa lớn nhất:**
  - Số lần lặp lớn nhất là độ cao của cây: $\lfloor \log_2 13 \rfloor + 1 = 4$ lần lặp.
  - Nếu tính theo thuật toán so sánh 3 nhánh chuẩn (mỗi lần lặp tốn tối đa 2 phép so sánh: `=` và `<`): Số phép so sánh khóa tối đa là:
    $$C_{worst} = 3 \times 2 + 1 = 7 \text{ phép so sánh}$$
    (Tại tầng lá chỉ cần 1 phép so sánh nếu trúng khóa). Nếu tính theo số lần lặp thì bằng **4 lần lặp**.
- **b. Các khóa đòi hỏi số lần lặp lớn nhất (ở tầng 4):**
  $$\{14, \; 31, \; 42, \; 70, \; 85, \; 98\}$$
- **c. Số lần lặp trung bình khi tìm kiếm thành công ($C_{avg}^{succ}$):**
  - 1 khóa ở tầng 1 (1 lần lặp): $\{55\}$
  - 2 khóa ở tầng 2 (2 lần lặp): $\{27, 81\}$
  - 4 khóa ở tầng 3 (3 lần lặp): $\{3, 39, 74, 93\}$
  - 6 khóa ở tầng 4 (4 lần lặp): $\{14, 31, 42, 70, 85, 98\}$
  - Tổng số lần lặp: $1 \times 1 + 2 \times 2 + 4 \times 3 + 6 \times 4 = 1 + 4 + 12 + 24 = 41$.
  - Số lần lặp trung bình:
    $$C_{avg}^{succ} = \frac{41}{13} \approx \mathbf{3.15 \text{ lần lặp}}$$
- **d. Số lần lặp trung bình khi tìm kiếm không thành công ($C_{avg}^{unsucc}$):**
  - Mảng 13 phần tử tạo thành $13 + 1 = 14$ khoảng rỗng bên ngoài/ở giữa.
  - Trong 14 khoảng rỗng này:
    - Có 2 khoảng kết thúc sau 3 lần lặp.
    - Có 12 khoảng kết thúc sau 4 lần lặp.
  - Tổng số lần lặp: $2 \times 3 + 12 \times 4 = 6 + 48 = 54$.
  - Số lần lặp trung bình không thành công:
    $$C_{avg}^{unsucc} = \frac{54}{14} \approx \mathbf{3.86 \text{ lần lặp}}$$

---

### Bài 4 (Binary Search vs Sequential Search Speedup - Tỉ số tăng tốc trên 1 triệu phần tử)
> **Đề bài:**  
> Ước tính xem một tìm kiếm thành công trung bình sẽ nhanh hơn khoảng bao nhiêu lần trong một mảng đã sắp xếp gồm **một triệu ($1,000,000$) phần tử** nếu được thực hiện bằng Tìm kiếm nhị phân so với Tìm kiếm tuần tự?

#### Lời giải chi tiết:
- Với mảng đã sắp xếp $n = 1,000,000$:
  1. **Tìm kiếm tuần tự (Sequential Search):**
     - Số phép so sánh trung bình khi tìm kiếm thành công:
       $$C_{seq} \approx \frac{n + 1}{2} \approx \frac{1,000,000}{2} = \mathbf{500,000 \text{ phép so sánh}}$$
  2. **Tìm kiếm nhị phân (Binary Search):**
     - Số lần lặp trung bình khi tìm kiếm thành công xấp xỉ:
       $$C_{bin} \approx \log_2 n - 1 = \log_2(1,000,000) - 1 \approx 19.93 - 1 \approx \mathbf{19 \text{ lần lặp}}$$
- **Tỉ số tăng tốc (Speedup factor):**
  $$\text{Tốc độ tăng} = \frac{C_{seq}}{C_{bin}} \approx \frac{500,000}{19} \approx \mathbf{26,315 \text{ lần!}}$$
- **Kết luận:** Tìm kiếm nhị phân chạy nhanh hơn tìm kiếm tuần tự **hơn 26,000 lần**!

---

### Bài 5 (Binary Search on Linked Lists - Tìm kiếm nhị phân trên danh sách liên kết)
> **Đề bài:**  
> Hiệu quả thời gian của tìm kiếm tuần tự không phụ thuộc vào việc danh sách được cài đặt bằng mảng hay danh sách liên kết. Điều này có còn đúng đối với việc tìm kiếm trên danh sách đã sắp xếp bằng tìm kiếm nhị phân không?

#### Lời giải chi tiết:
- **Trả lời:** **HOÀN TOÀN KHÔNG ĐÚNG (NOT TRUE)**.
- **Giải thích bản chất:**
  - Tìm kiếm nhị phân dựa trên tiền đề quan trọng: Ta có thể truy cập phần tử chính giữa $A[m]$ trong thời gian tức thời **$O(1)$** thông qua chỉ số mảng.
  - Trong **danh sách liên kết (Linked List)**:
    - Không hỗ trợ truy cập ngẫu nhiên qua chỉ số.
    - Để đến được nút chính giữa của một danh sách con kích thước $k$, ta buộc phải xuất phát từ đầu danh sách con và lần theo con trỏ `next` mất $k/2$ bước, tức là tốn **$\Theta(k)$ thời gian**.
  - Thiết lập phương trình đệ quy thời gian trên danh sách liên kết:
    $$T(n) = T(n/2) + c \cdot \frac{n}{2}$$
    Theo Định lý Thợ (Master Theorem) hoặc khai triển trực tiếp:
    $$T(n) = c \frac{n}{2} + c \frac{n}{4} + c \frac{n}{8} + \dots \approx c n \in \mathbf{\Theta(n)}$$
- **Kết luận:** Khi cài đặt trên danh sách liên kết, Tìm kiếm nhị phân bị **thoái hóa hoàn toàn về thời gian tuyến tính $\Theta(n)$**, mất sạch ưu thế logarit và thậm chí còn chạy chậm hơn tìm kiếm tuần tự do hệ số hằng số lớn.

---

### Bài 6 (Two-Way Comparison Binary Search - Tìm kiếm nhị phân so sánh 2 nhánh)
> **Đề bài:**  
> a. Thiết kế một phiên bản tìm kiếm nhị phân chỉ sử dụng phép so sánh hai nhánh (chẳng hạn như $\le$ và $=$ hoặc $<$ và $\ge$).  
> b. Phân tích hiệu quả thời gian của phiên bản so sánh hai nhánh này.

#### Lời giải chi tiết:

#### Phần a (Thiết kế mã giả):
Phiên bản 3 nhánh truyền thống kiểm tra 2 điều kiện: `$K = A[m]$` và `$K < A[m]$` trong mỗi vòng lặp. Phiên bản 2 nhánh chỉ thu hẹp khoảng cho đến khi đoạn còn 1 phần tử, rồi mới kiểm tra dấu bằng đúng 1 lần duy nhất:

```text
Algorithm BinarySearchTwoWay(A[0..n-1], K)
// Đầu vào: Mảng A[0..n-1] đã sắp xếp tăng dần và khóa K
// Đầu ra: Chỉ số vị trí tìm thấy hoặc -1

1   l ← 0; r ← n - 1
2   while l < r do
3       m ← ⌊(l + r) / 2⌋
4       if K ≤ A[m] then
5           r ← m        // Thu hẹp về nửa trái bao gồm cả m
6       else
7           l ← m + 1    // K chắc chắn lớn hơn A[m], tìm từ m + 1
8   if A[l] = K then
9       return l         // Kiểm tra dấu bằng duy nhất khi còn 1 phần tử
10  else
11      return -1
```

#### Phần b (Phân tích hiệu quả):
- **Ưu điểm:** Mỗi lần lặp vòng `while` chỉ thực hiện **đúng 1 phép so sánh khóa** (`K <= A[m]`) thay vì 2 phép so sánh như bản 3 nhánh. Điều này giúp mã máy của vòng lặp rất gọn và loại bỏ các bước nhảy rẽ nhánh sai (branch misprediction).
- **Số lần lặp:** Vòng lặp luôn chạy đúng $\lceil \log_2 n \rceil$ lần trong **mọi trường hợp** (không dừng sớm).
- **Tổng số phép so sánh khóa:** Đúng $\lceil \log_2 n \rceil + 1$ phép so sánh cho mọi trường hợp (tốt nhất, xấu nhất, trung bình).

---

### Bài 7 (Picture Guessing - Trò chơi đoán tranh 42 bức ảnh)
> **Đề bài:**  
> Một phiên bản giải đố phổ biến đưa ra một mảng gồm 42 bức ảnh (7 hàng $\times$ 6 cột) và yêu cầu người chơi xác định bức ảnh mục tiêu bằng cách đặt các câu hỏi chỉ được trả lời "Có" hoặc "Không". Người chơi phải tìm ra bức ảnh với số câu hỏi ít nhất có thể. Hãy đề xuất thuật toán hiệu quả nhất và chỉ ra số câu hỏi tối đa cần dùng.

#### Lời giải chi tiết:
- **Thuật toán tối ưu:** Thuật toán **Tìm kiếm nhị phân / Cây quyết định nhị phân**.
  - Mỗi câu hỏi "Có/Không" chia tập hợp các bức ảnh còn lại thành 2 phần rời nhau.
  - Để tối thiểu hóa số câu hỏi trong trường hợp xấu nhất, câu hỏi phải được thiết kế sao cho chia đôi số lượng ảnh còn lại một cách cân bằng nhất có thể (mỗi nửa 50% số ảnh).
- **Số câu hỏi tối đa cần thiết trong trường hợp xấu nhất:**
  - Với $n = 42$ bức ảnh, số câu hỏi tối đa là:
    $$Q_{max} = \lceil \log_2 42 \rceil$$
  - Vì $2^5 = 32 < 42 \le 64 = 2^6$, ta có:
    $$Q_{max} = 6 \text{ câu hỏi}$$
- **Minh họa quy trình 6 câu hỏi:**
  - Câu 1: Bức ảnh có nằm trong 3 hàng đầu tiên (21 ảnh) không? (Còn 21 ảnh).
  - Câu 2: Chia 21 thành 10 và 11 ảnh. (Còn tối đa 11 ảnh).
  - Câu 3: Chia 11 thành 5 và 6 ảnh. (Còn tối đa 6 ảnh).
  - Câu 4: Chia 6 thành 3 và 3 ảnh. (Còn 3 ảnh).
  - Câu 5: Bức ảnh có phải là ảnh A trong số 3 ảnh không? (Nếu không, còn 2 ảnh).
  - Câu 6: Bức ảnh có phải là ảnh B không? $\implies$ Xác định 100% bức ảnh duy nhất!
- **Đáp số:** Tối đa **6 câu hỏi**.

---

### Bài 8 (Ternary Search - Tìm kiếm tam phân)
> **Đề bài:**  
> Xét thuật toán tìm kiếm tam phân (Ternary Search) trên mảng đã sắp xếp $A[0..n-1]$: Nếu $n = 1$, so sánh $K$ với phần tử duy nhất. Ngược lại, so sánh $K$ với $A[\lfloor n/3 \rfloor]$, nếu $K$ lớn hơn thì so sánh tiếp với $A[\lfloor 2n/3 \rfloor]$ để xác định $K$ nằm trong phần ba nào của mảng để tiếp tục tìm kiếm đệ quy.  
> a. Thuật toán này dựa trên chiến lược thiết kế nào?  
> b. Thiết lập phương trình đệ quy tính số phép so sánh khóa trong trường hợp xấu nhất (giả sử $n = 3^k$).  
> c. Giải phương trình đệ quy trên.  
> d. So sánh hiệu quả của tìm kiếm tam phân với tìm kiếm nhị phân.

#### Lời giải chi tiết:

#### Phần a:
- Dựa trên chiến lược **Giảm theo tỉ lệ hằng số (Decrease-by-a-constant-factor)**, cụ thể là giảm theo tỉ lệ 3 (kích thước giảm từ $n$ xuống $n/3$).

#### Phần b (Phương trình đệ quy):
- Trong trường hợp xấu nhất, tại mỗi bước ta phải so sánh với cả hai mốc $A[\lfloor n/3 \rfloor]$ và $A[\lfloor 2n/3 \rfloor]$ (tốn 2 phép so sánh), sau đó bài toán quy về tìm kiếm trong đoạn kích thước $n/3$:
  $$C(n) = C(n/3) + 2 \quad (n > 1), \quad C(1) = 1$$

#### Phần c (Giải phương trình với $n = 3^k$):
- Sử dụng phương pháp thế lùi (Backward substitution):
  $$C(3^k) = C(3^{k-1}) + 2 = C(3^{k-2}) + 2 + 2 = \dots = C(3^0) + 2k = 1 + 2k$$
- Vì $k = \log_3 n$, ta có:
  $$C(n) = 2 \log_3 n + 1$$

#### Phần d (So sánh với Tìm kiếm nhị phân):
- Đổi cơ số của logarit sang cơ số 2:
  $$2 \log_3 n = 2 \cdot \frac{\log_2 n}{\log_2 3} = \frac{2}{\log_2 3} \log_2 n \approx \frac{2}{1.58496} \log_2 n \approx \mathbf{1.26188 \log_2 n}$$
- Trong khi đó, Tìm kiếm nhị phân trong trường hợp xấu nhất (bản so sánh 2 nhánh) chỉ tốn:
  $$C_{binary}(n) \approx \log_2 n$$
- **Kết luận:** Tìm kiếm tam phân thực hiện **nhiều hơn Tìm kiếm nhị phân khoảng $26.2\%$ số phép so sánh khóa**! Mặc dù chia thành 3 phần làm giảm kích thước nhanh hơn (cơ số 3), nhưng chi phí 2 phép so sánh ở mỗi bước là quá đắt, khiến tìm kiếm nhị phân vẫn vượt trội hơn.

---

### Bài 9 (Find Missing Integer in $O(\log n)$ - Tìm số nguyên bị thiếu)
> **Đề bài:**  
> Một mảng $A[0..n-2]$ chứa $n - 1$ số nguyên tăng dần trong phạm vi từ $1$ đến $n$. (Do đó có đúng một số nguyên trong khoảng này bị thiếu). Hãy thiết kế thuật toán hiệu quả nhất để tìm số nguyên bị thiếu và xác định độ phức tạp thời gian.

#### Lời giải chi tiết:
- **Quan sát mấu chốt:**
  - Nếu không có số nào bị thiếu ở phía trước chỉ số $i$, thì giá trị tại vị trí $i$ phải đúng bằng $i + 1$ (nghĩa là $A[i] = i + 1$).
  - Tại vị trí xuất hiện số bị thiếu trở đi, tất cả các phần tử đều bị dịch giá trị lớn hơn chỉ số: $A[i] = i + 2$.
  - Do đó, số bị thiếu chính là giá trị tại điểm gãy đầu tiên mà $A[i] > i + 1$!
- **Thuật toán dựa trên Tìm kiếm nhị phân:**
```text
Algorithm FindMissingNumber(A[0..n-2], n)
1   l ← 0; r ← n - 2
2   while l ≤ r do
3       m ← ⌊(l + r) / 2⌋
4       if A[m] = m + 1 then
5           l ← m + 1       // Nửa trái đầy đủ, số thiếu nằm ở nửa phải
6       else
7           r ← m - 1       // Đã lệch giá trị, số thiếu nằm ở nửa trái (kể cả m)
8   return l + 1            // l chính là giá trị bị thiếu
```
- **Độ phức tạp thời gian:** **$\Theta(\log n)$**.

---

### Bài 10 (Fake-Coin Divide-into-Three Algorithm - Thuật toán chia 3 đồng xu giả)
> **Đề bài:**  
> a. Viết mã giả cho thuật toán chia ba giải bài toán đồng xu giả xử lý đúng cho mọi giá trị $n$ (kể cả $n$ không chia hết cho 3).  
> b. Thiết lập hệ thức truy hồi cho số lần cân và giải với $n = 3^k$.  
> c. Với $n$ lớn, thuật toán này nhanh hơn thuật toán chia 2 khoảng bao nhiêu lần?

#### Lời giải chi tiết:

#### Phần a (Mã giả tổng quát):
```text
Algorithm FakeCoin3(coins[1..n])
// Tìm đồng xu giả nhẹ hơn trong n đồng xu

1   if n = 1 then
2       return coins[1]
3   p1 ← ⌈n / 3⌉; p2 ← ⌈n / 3⌉; p3 ← n - 2 * ⌈n / 3⌉
4   Đặt p1 đồng xu lên đĩa trái và p2 đồng xu lên đĩa phải
5   if Đĩa trái nhẹ hơn then
6       return FakeCoin3(phần p1)
7   else if Đĩa phải nhẹ hơn then
8       return FakeCoin3(phần p2)
9   else
10      return FakeCoin3(phần p3 để ngoài)
```

#### Phần b (Truy hồi & Giải):
- $W(n) = W(\lceil n/3 \rceil) + 1$ với $W(1) = 0$.
- Với $n = 3^k$:
  $$W(3^k) = W(3^{k-1}) + 1 = \dots = W(1) + k = k = \log_3 n$$

#### Phần c (Tỉ số tốc độ):
- Với thuật toán chia 2: $W_2(n) \approx \log_2 n$.
- Với thuật toán chia 3: $W_3(n) \approx \log_3 n$.
- Tỉ số so sánh:
  $$\frac{W_2(n)}{W_3(n)} = \frac{\log_2 n}{\log_3 n} = \log_2 3 \approx \mathbf{1.585}$$
- Thuật toán chia 3 cần ít hơn khoảng **$1.585$ lần số lần cân** so với chia 2 (tiết kiệm gần $37\%$ số lần cân).

---

### Bài 11 (Trace Russian Peasant Multiplication - Lần vết phép nhân nông dân Nga)
> **Đề bài:**  
> a. Áp dụng thuật toán nhân nông dân Nga để tính $26 \times 47$.  
> b. Xét theo hiệu quả thời gian, việc nhân $n \times m$ hay $m \times n$ có tạo ra sự khác biệt không?

#### Lời giải chi tiết:

#### Phần a: Tính $26 \times 47$
Ta lập bảng: Cột $n$ liên tục chia đôi (lấy phần nguyên), cột $m$ liên tục nhân đôi. Nếu $n$ lẻ, ta cộng giá trị $m$ tương ứng vào kết quả tích lũy:

| Bước | $n$ | $m$ | $n$ là Lẻ? | Cộng $m$ vào tích lũy |
| :---: | :---: | :---: | :---: | :--- |
| 1 | 26 | 47 | Chẵn | Không |
| 2 | 13 | 94 | **Lẻ** | $+ 94$ |
| 3 | 6 | 188 | Chẵn | Không |
| 4 | 3 | 376 | **Lẻ** | $+ 376$ |
| 5 | 1 | 752 | **Lẻ** | $+ 752$ |

- **Tổng kết quả:**
  $$\text{Tích} = 94 + 376 + 752 = \mathbf{1222}$$
- **Kiểm tra:** $26 \times 47 = 1222$ (Chính xác tuyệt đối).

#### Phần b:
- Số bước lặp của thuật toán đúng bằng $\lfloor \log_2 n \rfloor + 1$.
- Do đó, việc chọn số nào làm $n$ (số bị chia đôi) rất quan trọng:
  - Nếu chọn $n = \min(n, m)$, số lần chia đôi và số vòng lặp sẽ ít nhất!
  - Cụ thể: Với $26 \times 47$, chọn $n=26$ tốn $\lfloor \log_2 26 \rfloor + 1 = 5$ bước lặp. Nếu chọn $n=47$ tốn $\lfloor \log_2 47 \rfloor + 1 = 6$ bước lặp.
  - Vậy: **Nên đặt số nhỏ hơn ở vị trí $n$ để tối ưu hóa thời gian chạy**.

---

### Bài 12 (Pseudocode & Efficiency of Russian Peasant - Mã giả & Độ phức tạp)
> **Đề bài:**  
> a. Viết mã giả cho thuật toán nhân nông dân Nga.  
> b. Xác định lớp độ phức tạp thời gian của thuật toán này.

#### Lời giải chi tiết:
- **a. Mã giả:** Đã trình bày chuẩn hóa ở Mục 1.3 của chuyên đề này.
- **b. Độ phức tạp:**
  - Vòng lặp chạy $\lfloor \log_2 n \rfloor + 1$ lần.
  - Mỗi vòng lặp chỉ thực hiện các phép toán cơ bản trên số nguyên: kiểm tra bit lẻ, dịch phải 1 bit (`n >> 1`), dịch trái 1 bit (`m << 1`), và phép cộng `res += m`.
  - Do đó, độ phức tạp thời gian là:
    $$T(n) \in \mathbf{\Theta(\log n)}$$

---

### Bài 13 (Find $J(40)$ in Josephus Problem - Tính $J(40)$)
> **Đề bài:**  
> Tìm $J(40)$ - vị trí của người sống sót trong bài toán Josephus với $n = 40$.

#### Lời giải chi tiết:
- Phân tích $n = 40$ dưới dạng lũy thừa của 2:
  - Lũy thừa lớn nhất của 2 nhỏ hơn hoặc bằng 40 là $2^5 = 32$.
  - Ta có:
    $$40 = 2^5 + 8 \implies m = 5, \; l = 8$$
- Áp dụng công thức nghiệm đóng:
  $$J(n) = 2l + 1 \implies J(40) = 2(8) + 1 = \mathbf{17}$$
- **Cách 2 (Dịch vòng bit nhị phân):**
  - Biểu diễn nhị phân của 40: $40 = 32 + 8 = (101000)_2$.
  - Dịch vòng bit cao nhất `1` về cuối:
    $$(010001)_2 = 16 + 1 = \mathbf{17}$$.
- **Đáp số:** Vị trí số **17**.

---

### Bài 14 (Prove $J(2^k) = 1$ - Chứng minh người số 1 luôn thắng khi $n=2^k$)
> **Đề bài:**  
> Chứng minh rằng nghiệm của bài toán Josephus luôn bằng 1 với mọi $n$ là lũy thừa của 2 ($n = 2^k$).

#### Lời giải chi tiết:
- **Cách 1 (Từ công thức nghiệm đóng):**
  - Khi $n = 2^k$, phần dư $l = n - 2^k = 2^k - 2^k = 0$.
  - Áp dụng công thức $J(n) = 2l + 1$:
    $$J(2^k) = 2(0) + 1 = \mathbf{1}$$
- **Cách 2 (Quy nạp toán học theo hệ thức truy hồi):**
  - Với $k = 1$: $n = 2^1 = 2$. $J(2) = 2J(1) - 1 = 2(1) - 1 = 1$. Đúng!
  - Giả sử mệnh đề đúng với $k$, nghĩa là $J(2^k) = 1$.
  - Với $n = 2^{k+1} = 2 \cdot 2^k$ (là số chẵn): Áp dụng hệ thức truy hồi cho số chẵn $J(2m) = 2J(m) - 1$:
    $$J(2^{k+1}) = 2 J(2^k) - 1 = 2(1) - 1 = 1$$
  - Theo nguyên lý quy nạp toán học, $J(2^k) = 1$ với mọi số nguyên dương $k$.

---

### Bài 15 (Josephus Comprehensive Analysis - Phân tích toàn diện Josephus)
> **Đề bài:**  
> Đối với bài toán Josephus:  
> a. Tính $J(n)$ với $n = 1, 2, \dots, 15$.  
> b. Nhận diện quy luật trong các nghiệm từ 1 đến 15 và chứng minh tính tổng quát của nó.  
> c. Chứng minh tính đúng đắn của việc tìm $J(n)$ bằng phép dịch vòng 1 bit sang trái của biểu diễn nhị phân của $n$.

#### Lời giải chi tiết:

#### Phần a: Tính bảng giá trị $J(1)$ đến $J(15)$:

| $n$ | Biểu diễn nhị phân của $n$ | Dạng $2^m + l$ | $J(n) = 2l + 1$ | Biểu diễn nhị phân của $J(n)$ |
| :---: | :---: | :---: | :---: | :---: |
| **1** | `1` | $2^0 + 0$ | **1** | `1` |
| **2** | `10` | $2^1 + 0$ | **1** | `01` = `1` |
| **3** | `11` | $2^1 + 1$ | **3** | `11` |
| **4** | `100` | $2^2 + 0$ | **1** | `001` = `1` |
| **5** | `101` | $2^2 + 1$ | **3** | `011` = `3` |
| **6** | `110` | $2^2 + 2$ | **5** | `101` = `5` |
| **7** | `111` | $2^2 + 3$ | **7** | `111` |
| **8** | `1000` | $2^3 + 0$ | **1** | `0001` = `1` |
| **9** | `1001` | $2^3 + 1$ | **3** | `0011` = `3` |
| **10** | `1010` | $2^3 + 2$ | **5** | `0101` = `5` |
| **11** | `1011` | $2^3 + 3$ | **7** | `0111` = `7` |
| **12** | `1100` | $2^3 + 4$ | **9** | `1001` = `9` |
| **13** | `1101` | $2^3 + 5$ | **11** | `1011` = `11` |
| **14** | `1110` | $2^3 + 6$ | **13** | `1101` = `13` |
| **15** | `1111` | $2^3 + 7$ | **15** | `1111` = `15` |

#### Phần b (Nhận diện quy luật & Chứng minh):
- **Quy luật:** Dãy nghiệm $J(n)$ bắt đầu từ 1 tại mỗi lũy thừa của 2 ($n = 1, 2, 4, 8, \dots$), sau đó tăng dần theo cấp số cộng gồm các số lẻ liên tiếp ($1, 3, 5, 7, \dots$) cho đến khi chạm $2n - 1$ ngay trước lũy thừa 2 tiếp theo.
- **Chứng minh tổng quát công thức $J(2^m + l) = 2l + 1$:**
  - Quy nạp theo $m$:
    - Với $m = 1$: $n = 2$ ($l=0 \implies J(2) = 1$); $n = 3$ ($l=1 \implies J(3) = 3$). Đúng!
    - Giả sử mệnh đề đúng với $m - 1$.
    - Xét bước chuyển cho $m$:
      - Nếu $n$ chẵn: $l$ chẵn $\implies l = 2k$.
        $$n = 2^m + 2k = 2(2^{m-1} + k)$$
        Áp dụng truy hồi chẵn:
        $$J(n) = 2 J(2^{m-1} + k) - 1 = 2(2k + 1) - 1 = 4k + 1 = 2l + 1$$
      - Nếu $n$ lẻ: $l$ lẻ $\implies l = 2k + 1$.
        $$n = 2^m + 2k + 1 = 2(2^{m-1} + k) + 1$$
        Áp dụng truy hồi lẻ:
        $$J(n) = 2 J(2^{m-1} + k) + 1 = 2(2k + 1) + 1 = 4k + 3 = 2(2k + 1) + 1 = 2l + 1$$
  - Công thức được chứng minh đúng với mọi $m$ và $l$.

#### Phần c (Chứng minh tính đúng đắn của phép dịch vòng 1 bit):
- Cho $n = 2^m + l$ với $0 \le l < 2^m$.
- Biểu diễn nhị phân của $n$ có $m + 1$ bit, với bit cao nhất ở vị trí $2^m$ luôn là `1`, và $m$ bit còn lại biểu diễn giá trị của $l$:
  $$n = 1 \cdot 2^m + l = (1 \; b_{m-1} \; b_{m-2} \; \dots \; b_0)_2$$
- Thực hiện phép dịch vòng 1 bit sang trái: Bit `1` cao nhất chuyển xuống vị trí hàng đơn vị ($2^0$), và toàn bộ các bit $b_{m-1} \dots b_0$ của $l$ bị đẩy sang trái 1 vị trí (tương đương với việc nhân giá trị $l$ với 2):
  $$\text{Giá trị sau dịch bit} = (b_{m-1} \; \dots \; b_0 \; 1)_2 = 2 \cdot l + 1$$
- Giá trị này trùng khớp hoàn hảo với công thức đóng $J(n) = 2l + 1$! Phép dịch bit được chứng minh hoàn tất.


---

# CHUYÊN ĐỀ 05: THUẬT TOÁN GIẢM THEO KÍCH THƯỚC BIẾN THIÊN (VARIABLE-SIZE-DECREASE) & LỜI GIẢI BÀI TẬP 4.5
*Tài liệu tham chiếu: A. Levitin, "Introduction to the Design and Analysis of Algorithms", 3rd Edition, Chương 4, Mục 4.5, Trang 157–167.*

---

## PHẦN I. LÝ THUYẾT VÀ MÃ GIẢ CHUẨN HÓA

Trong biến thể thứ ba của chiến lược Giảm để trị, **mô hình thu nhỏ kích thước biến thiên linh hoạt từ bước lặp này sang bước lặp khác**, phụ thuộc hoàn toàn vào giá trị của dữ liệu đầu vào hoặc kết quả phân rã tạm thời.

---

### 1.1. Thuật toán Euclid tính ƯCLN (Góc nhìn Giảm kích thước biến thiên)
- Biểu thức: $\gcd(m, n) = \gcd(n, m \bmod n)$.
- Lượng giảm kích thước của số thứ hai $n$ sau mỗi bước là hoàn toàn không cố định: nó có thể giảm một lượng rất nhỏ hoặc giảm vọt về 0 ngay tức khắc (nếu $m$ chia hết cho $n$).

---

### 1.2. Bài toán Chọn phần tử thứ $k$ (Selection Problem) & Thuật toán Quickselect

#### Phát biểu bài toán:
Tìm phần tử nhỏ thứ $k$ ($1 \le k \le n$) trong một danh sách chưa được sắp xếp gồm $n$ phần tử. Đặc biệt, khi $k = \lceil n/2 \rceil$, bài toán trở thành **tìm Trung vị (Median)** của tập dữ liệu.

#### Cơ chế phân hoạch Lomuto (Lomuto Partition):
- Chọn phần tử đầu tiên $p = A[l]$ làm chốt (pivot).
- Dùng con trỏ $s$ ngăn cách hai vùng: vùng các phần tử $< p$ và vùng các phần tử $\ge p$.
- Quét con trỏ $i$ từ $l + 1$ đến $r$: Nếu $A[i] < p$, tăng $s$ và đổi chỗ $A[s]$ với $A[i]$.
- Cuối cùng đổi chỗ $A[l]$ với $A[s]$ để đưa chốt về đúng vị trí $s$.

```text
Algorithm LomutoPartition(A[l..r])
// Đầu vào: Mảng con A[l..r]
// Đầu ra: Vị trí chốt s sao cho A[l..s-1] < A[s] và A[s+1..r] ≥ A[s]

1   p ← A[l]
2   s ← l
3   for i ← l + 1 to r do
4       if A[i] < p then
5           s ← s + 1
6           swap(A[s], A[i])
7   swap(A[l], A[s])
8   return s
```

#### Thuật toán Quickselect (Hoare, 1961):
Sau khi phân hoạch mảng con $A[l..r]$ với chốt tại vị trí $s$:
- Nếu $s = l + k - 1$: Chốt chính là phần tử nhỏ thứ $k$, trả về $A[s]$.
- Nếu $s > l + k - 1$: Phần tử cần tìm nằm ở nửa trái $A[l..s-1]$, tìm phần tử nhỏ thứ $k$.
- Nếu $s < l + k - 1$: Phần tử cần tìm nằm ở nửa phải $A[s+1..r]$, tìm phần tử nhỏ thứ $k - (s - l + 1)$.

```text
Algorithm Quickselect(A[l..r], k)
// Đầu vào: Mảng con A[l..r] và số nguyên k (1 ≤ k ≤ r - l + 1)
// Đầu ra: Giá trị của phần tử nhỏ thứ k trong A[l..r]

1   s ← LomutoPartition(A[l..r])
2   if s = l + k - 1 then
3       return A[s]
4   else if s > l + k - 1 then
5       return Quickselect(A[l..s - 1], k)
6   else
7       return Quickselect(A[s + 1..r], k - (s - l + 1))
```

#### Phân tích độ phức tạp:
- **Trường hợp trung bình:** $T(n) = T(n/2) + \Theta(n) \implies T_{avg}(n) \in \mathbf{\Theta(n)}$ (Thời gian tuyến tính!).
- **Trường hợp xấu nhất:** Khi chốt luôn là phần tử cực trị (mảng đã sắp sẵn): $T(n) = T(n-1) + \Theta(n) \implies T_{worst}(n) \in \mathbf{\Theta(n^2)}$.

---

### 1.3. Tìm kiếm nội suy (Interpolation Search)

Dành riêng cho mảng đã sắp xếp có các giá trị **phân bố gần như đồng đều**. Thay vì chia đôi tại trung điểm, thuật toán ước lượng vị trí $x$ dựa trên nội suy tuyến tính:

$$x = l + \left\lfloor \frac{v - A[l]}{A[r] - A[l]} (r - l) \right\rfloor$$

- **Độ phức tạp thời gian:**
  - **Trường hợp trung bình:** $T_{avg}(n) \in \mathbf{\Theta(\log \log n)}$ (Cực kỳ nhanh, với $n = 10^9$ thì $\log_2 \log_2 n \approx 5$ lần lặp!).
  - **Trường hợp xấu nhất:** $T_{worst}(n) \in \mathbf{\Theta(n)}$ (Xảy ra khi dữ liệu tăng theo cấp số nhân).

---

### 1.4. Các thao tác trên Cây tìm kiếm nhị phân (BST)
- **Tìm kiếm & Chèn:** Mỗi bước đi xuống một nhánh cây con trái hoặc phải, kích thước bài toán giảm một lượng biến thiên tùy thuộc vào độ cân bằng của cây.
- **Xóa nút:** Nếu nút có 2 con, tìm phần tử kế vị (nhỏ nhất cây con phải) để thay thế rồi xóa nút kế vị.
- **Độ phức tạp:** Trung bình $\Theta(\log n)$, xấu nhất $\Theta(n)$ khi cây suy biến thành đường thẳng.

---

### 1.5. Trò chơi Nim (The Game of Nim)

#### 1.5.1. Nim 1 đống (One-pile Nim)
Có 1 đống $n$ viên sỏi. Hai người chơi lần lượt bốc từ 1 đến $m$ viên sỏi. Người bốc viên sỏi cuối cùng là người THẮNG.
- **Thế thua (Losing position) cho người đến lượt đi:**
  $$n \equiv 0 \pmod{m + 1}$$
- **Thế thắng (Winning position) cho người đến lượt đi:**
  $$n \not\equiv 0 \pmod{m + 1}$$
  *Chiến lược thắng:* Luôn bốc đúng $n \bmod (m + 1)$ viên sỏi để để lại cho đối thủ bội số của $m + 1$.

#### 1.5.2. Nim nhiều đống (Multi-pile Nim) & Định lý Bouton (1901)
Có $I$ đống sỏi với kích thước $n_1, n_2, \dots, n_I$. Mỗi lượt bốc số lượng sỏi tùy ý từ đúng một đống.
- **Tổng Nim (Nim-sum):** Phép cộng nhị phân không nhớ (chính là phép **XOR bitwise $\oplus$**):
  $$S = n_1 \oplus n_2 \oplus \dots \oplus n_I$$
- **Định lý:**
  - Một trạng thái là **Thế thắng (Winning)** $\iff S \ne 0$.
  - Một trạng thái là **Thế thua (Losing)** $\iff S = 0$.

---

## PHẦN II. GIẢI CHI TIẾT 100% CÁC BÀI TẬP EXERCISES 4.5 (BÀI 1 ĐẾN BÀI 13)

---

### Bài 1 (Size Reduction in Euclid's Algorithm - Phân tích bước giảm thuật toán Euclid)
> **Đề bài:**  
> a. Nếu đo kích thước thể hiện của bài toán tính ước số chung lớn nhất của $m$ và $n$ bằng độ lớn của số thứ hai $n$, thì kích thước này có thể giảm nhiều nhất là bao nhiêu sau một lần lặp của thuật toán Euclid?  
> b. Chứng minh rằng kích thước thể hiện sẽ luôn luôn giảm đi ít nhất một nửa sau hai lần lặp liên tiếp của thuật toán Euclid.

#### Lời giải chi tiết:

#### Phần a:
- Trong một lần lặp của thuật toán Euclid, cặp $(m, n)$ được thay thế bởi cặp $(n, m \bmod n)$. Số thứ hai mới chính là $r = m \bmod n$.
- Kích thước có thể giảm nhiều nhất: Khi $m$ chia hết cho $n$, khi đó $m \bmod n = 0$.
- Kích thước của số thứ hai giảm từ $n$ về **$0$** (nghĩa là giảm toàn bộ $100\%$, thuật toán dừng ngay lập tức).

#### Phần b (Chứng minh sau 2 bước kích thước giảm ít nhất một nửa):
- Gọi dãy các số thứ hai sau các bước lặp là $n_0, n_1, n_2, \dots$ với $n_{i+1} = n_{i-1} \bmod n_i$.
- Cần chứng minh:
  $$n_{i+2} < \frac{n_i}{2}$$
- Ta xét phép chia $n_i$ cho $n_{i+1}$:
  $$n_i = q \cdot n_{i+1} + n_{i+2} \quad \text{với } 0 \le n_{i+2} < n_{i+1}$$
  Ta phân chia thành hai trường hợp của số dư $n_{i+1}$:
  1. **Trường hợp 1: $n_{i+1} \le \frac{n_i}{2}$**  
     Vì theo định nghĩa phép chia có dư, $n_{i+2} < n_{i+1}$, nên từ $n_{i+1} \le \frac{n_i}{2}$ suy ra ngay:
     $$n_{i+2} < \frac{n_i}{2}$$
  2. **Trường hợp 2: $n_{i+1} > \frac{n_i}{2}$**  
     Vì $n_{i+1} > \frac{n_i}{2}$, số lần $n_{i+1}$ chứa trong $n_i$ chỉ có thể là thương số $q = 1$.  
     Khi đó phần dư là:
     $$n_{i+2} = n_i - 1 \cdot n_{i+1} = n_i - n_{i+1}$$
     Do $n_{i+1} > \frac{n_i}{2} \implies -n_{i+1} < -\frac{n_i}{2}$, ta có:
     $$n_{i+2} = n_i - n_{i+1} < n_i - \frac{n_i}{2} = \frac{n_i}{2}$$
- Trong cả hai trường hợp, ta đều có $n_{i+2} < \frac{n_i}{2}$.
- **Hệ quả quan trọng:** Vì sau mỗi 2 bước lặp kích thước giảm ít nhất một nửa, số lần lặp của thuật toán Euclid tối đa chỉ là $2 \log_2 n$. Đây là nền tảng chứng minh Định lý Lamé về độ phức tạp logarit của thuật toán Euclid!

---

### Bài 2 (Apply Quickselect to Find Median - Tìm trung vị bằng Quickselect)
> **Đề bài:**  
> Áp dụng thuật toán Quickselect để tìm trung vị của danh sách các số sau:  
> $$9, \; 12, \; 5, \; 17, \; 20, \; 30, \; 8$$

#### Lời giải chi tiết:
- Dãy gồm $n = 7$ phần tử. Vị trí trung vị là phần tử nhỏ thứ $k = \lceil 7/2 \rceil = 4$.
- Mảng ban đầu: $A[0..6] = [9, 12, 5, 17, 20, 30, 8]$ với $l = 0, r = 6, k = 4$.

**Đợt 1: Phân hoạch đoạn $A[0..6]$ với chốt $p = A[0] = 9$:**
- Khởi tạo $s = 0$.
- $i=1: A[1] = 12 \ge 9$ (bỏ qua).
- $i=2: A[2] = 5 < 9 \implies s = 1$, swap $A[1], A[2] \implies A = [9, 5, 12, 17, 20, 30, 8]$.
- $i=3, 4, 5: 17, 20, 30 \ge 9$ (bỏ qua).
- $i=6: A[6] = 8 < 9 \implies s = 2$, swap $A[2], A[6] \implies A = [9, 5, 8, 17, 20, 30, 12]$.
- Đổi chỗ chốt $A[0]$ với $A[s] = A[2]$:
  $$A = [8, \; 5, \; \mathbf{9}, \; 17, \; 20, \; 30, \; 12]$$
- Vị trí của chốt là $s = 2$.
- So sánh: Mục tiêu là tìm phần tử tại chỉ số $k - 1 = 4 - 1 = 3$.
- Vì $s = 2 < 3$, phần tử trung vị phải nằm ở nửa bên phải $A[3..6] = [17, 20, 30, 12]$.
- Kích thước mới: tìm phần tử nhỏ thứ $k' = 4 - (2 - 0 + 1) = 4 - 3 = 1$ trong đoạn $A[3..6]$.

**Đợt 2: Phân hoạch đoạn $A[3..6] = [17, 20, 30, 12]$ với chốt $p = A[3] = 17$:**
- Khởi tạo $s = 3$.
- $i=4: A[4] = 20 \ge 17$ (bỏ qua).
- $i=5: A[5] = 30 \ge 17$ (bỏ qua).
- $i=6: A[6] = 12 < 17 \implies s = 4$, swap $A[4], A[6] \implies A[3..6] = [17, 12, 30, 20]$.
- Đổi chỗ chốt $A[3]$ với $A[s] = A[4]$:
  $$A[3..6] = [12, \; \mathbf{17}, \; 30, \; 20]$$
- Vị trí chốt mới là $s = 4$.
- Mục tiêu tìm phần tử nhỏ thứ 1 trong đoạn $A[3..6]$, tức là tại chỉ số $3 + 1 - 1 = 3$.
- Vì $s = 4 > 3$, phần tử cần tìm nằm ở nửa bên trái của chốt, tức là đoạn $A[3..3] = [12]$.

**Đợt 3: Xét đoạn $A[3..3]$:**
- Đoạn chỉ có 1 phần tử tại chỉ số 3 là **$12$**.
- Thuật toán kết thúc và trả về giá trị **12**.
- **Kiểm tra:** Dãy sắp xếp hoàn chỉnh là $[5, 8, 9, \mathbf{12}, 17, 20, 30]$, phần tử chính giữa trung vị đúng bằng **12**. Kết quả chính xác tuyệt đối!

---

### Bài 3 (Nonrecursive Quickselect - Mã giả không đệ quy Quickselect)
> **Đề bài:**  
> Viết mã giả cho cài đặt không đệ quy của thuật toán Quickselect.

#### Lời giải chi tiết:

```text
Algorithm QuickselectNonrecursive(A[0..n-1], k)
// Tìm phần tử nhỏ thứ k không dùng đệ quy
// Đầu vào: Mảng A[0..n-1] và số nguyên k (1 ≤ k ≤ n)
// Đầu ra: Giá trị của phần tử nhỏ thứ k

1   l ← 0; r ← n - 1
2   target ← k - 1               // Chỉ số mục tiêu cần đạt
3   while l < r do
4       s ← LomutoPartition(A[l..r])
5       if s = target then
6           return A[s]          // Đã tìm thấy chốt tại đúng chỉ số mục tiêu
7       else if s > target then
8           r ← s - 1            // Thu hẹp tìm kiếm về nửa bên trái
9       else
10          l ← s + 1            // Thu hẹp tìm kiếm về nửa bên phải
11  return A[l]                  // Khi l = r, đoạn còn 1 phần tử duy nhất
```

---

### Bài 4 (Derivation of Interpolation Search Formula - Chứng minh công thức tìm kiếm nội suy)
> **Đề bài:**  
> Thiết lập công thức toán học làm cơ sở cho thuật toán tìm kiếm nội suy.

#### Lời giải chi tiết:
- Giả thiết mảng $A[l..r]$ đã sắp xếp tăng dần và các giá trị phân bố xấp xỉ tuyến tính đều đặn giữa hai điểm biên $(l, A[l])$ và $(r, A[r])$.
- Xét mặt phẳng tọa độ với trục hoành là chỉ số mảng $x$ và trục tung là giá trị phần tử $y = A[x]$.
- Hai điểm mút xác định một đoạn thẳng:
  $$P_1 = (l, A[l]) \quad \text{và} \quad P_2 = (r, A[r])$$
- Độ dốc (hệ số góc) của đường thẳng nối $P_1$ và $P_2$ là:
  $$\text{slope} = \frac{A[r] - A[l]}{r - l}$$
- Ta cần tìm chỉ số $x$ sao cho giá trị ước tính trên đường thẳng đạt đúng giá trị khóa tìm kiếm $v$:
  $$\frac{v - A[l]}{x - l} = \text{slope} = \frac{A[r] - A[l]}{r - l}$$
- Giải phương trình tìm $x$:
  $$x - l = \frac{v - A[l]}{A[r] - A[l]} (r - l)$$
  $$x = l + \frac{v - A[l]}{A[r] - A[l]} (r - l)$$
- Lấy phần nguyên để đảm bảo $x$ là chỉ số nguyên hợp lệ trong mảng:
  $$x = l + \left\lfloor \frac{v - A[l]}{A[r] - A[l]} (r - l) \right\rfloor$$
- Công thức được thiết lập hoàn tất.

---

### Bài 5 (Worst-Case Input for Interpolation Search - Trường hợp xấu nhất của tìm kiếm nội suy)
> **Đề bài:**  
> Đưa ra một ví dụ về dữ liệu đầu vào trong trường hợp xấu nhất cho tìm kiếm nội suy và chứng minh rằng thuật toán có độ phức tạp thời gian tuyến tính $\Theta(n)$ trong trường hợp này.

#### Lời giải chi tiết:
- **Nguyên nhân trường hợp xấu nhất:** Xảy ra khi phân bố giá trị bị lệch cực độ (tăng theo hàm mũ hoặc hàm lũy thừa cực nhanh), khiến công thức nội suy luôn ước lượng vị trí chốt $x$ chỉ dịch chuyển đúng **1 đơn vị** sau mỗi bước.
- **Ví dụ cụ thể:**  
  Xét mảng gồm $n$ phần tử tăng theo cấp số nhân:
  $$A[i] = 2^i \quad (i = 0, 1, \dots, n-1)$$
  Cụ thể với $n = 5$: $A = [1, 2, 4, 8, 16]$. Ta tìm kiếm khóa $K = 2$.
- **Chứng minh bước giảm chỉ bằng 1:**
  - Ở lần lặp đầu: $l = 0, r = n-1, A[l] = 1, A[r] = 2^{n-1}$.
  - Áp dụng công thức nội suy tìm $K = 2$:
    $$x = 0 + \left\lfloor \frac{2 - 1}{2^{n-1} - 1} (n - 1) \right\rfloor = \left\lfloor \frac{n - 1}{2^{n-1} - 1} \right\rfloor$$
  - Với $n \ge 4$, ta luôn có $2^{n-1} - 1 > n - 1$, do đó phân số nhỏ hơn 1:
    $$\left\lfloor \frac{n - 1}{2^{n-1} - 1} \right\rfloor = 0 \implies x = 0$$
  - So sánh: $A[0] = 1 < 2 \implies$ Cập nhật $l = x + 1 = 1$.
  - Khoảng tìm kiếm từ $n$ phần tử chỉ giảm đi đúng 1 phần tử (còn $n-1$ phần tử).
  - Quá trình này lặp lại liên tiếp: mỗi bước lặp chỉ tăng $l$ thêm đúng 1 đơn vị.
- **Tổng số bước lặp:** Thuật toán phải duyệt qua $n$ bước lặp tuần tự $\implies T(n) \in \mathbf{\Theta(n)}$.

---

### Bài 6 (Log Log Analysis - Phân tích hàm $\log_2 \log_2 n$)
> **Đề bài:**  
> a. Tìm giá trị nhỏ nhất của số nguyên dương $n$ để $\log_2 \log_2 n + 1 > 6$.  
> b. Xác định khẳng định nào sau đây là đúng:  
> i. $\log \log n \in o(\log n)$  
> ii. $\log \log n \in \Theta(\log n)$  
> iii. $\log \log n \in \Omega(\log n)$

#### Lời giải chi tiết:

#### Phần a:
- Bất phương trình:
  $$\log_2 \log_2 n + 1 > 6 \iff \log_2 \log_2 n > 5$$
- Lấy lũy thừa cơ số 2 hai vế:
  $$\log_2 n > 2^5 = 32$$
- Lấy lũy thừa cơ số 2 tiếp tục:
  $$n > 2^{32} = 4,294,967,296$$
- Vì $n$ là số nguyên dương, giá trị $n$ nhỏ nhất là:
  $$n_{min} = 2^{32} + 1 = \mathbf{4,294,967,297}$$
  *(Hơn 4.29 tỷ phần tử! Điều này cho thấy trong thực tế $\log_2 \log_2 n + 1$ hầu như không bao giờ vượt quá 6).*

#### Phần b:
- Xét giới hạn tỉ số khi $n \to \infty$ (đặt $u = \log n \to \infty$):
  $$\lim_{n \to \infty} \frac{\log \log n}{\log n} = \lim_{u \to \infty} \frac{\ln u}{u} = 0 \quad \text{(áp dụng quy tắc L'Hôpital)}$$
- Do giới hạn bằng 0:
  - **Khẳng định i: $\log \log n \in o(\log n)$ là ĐÚNG.**
  - **Khẳng định ii: $\log \log n \in \Theta(\log n)$ là SAI.**
  - **Khẳng định iii: $\log \log n \in \Omega(\log n)$ là SAI.**

---

### Bài 7 (Finding Largest Key in BST - Tìm khóa lớn nhất trên cây BST)
> **Đề bài:**  
> a. Phác thảo một thuật toán để tìm khóa lớn nhất trong một Cây tìm kiếm nhị phân (BST). Bạn có phân loại thuật toán này vào nhóm thuật toán giảm theo kích thước biến thiên không?  
> b. Lớp độ phức tạp thời gian trong trường hợp xấu nhất của thuật toán này là gì?

#### Lời giải chi tiết:

#### Phần a:
- **Nguyên lý cây BST:** Theo định nghĩa BST, mọi khóa ở cây con bên phải của nút $x$ đều lớn hơn khóa tại $x$. Do đó, khóa lớn nhất trong toàn bộ cây chắc chắn phải nằm ở nút tận cùng bên phải.
- **Mã giả thuật toán:**
```text
Algorithm BSTFindMax(root)
if root = null then return null
curr ← root
while curr.right ≠ null do
    curr ← curr.right
return curr.key
```
- **Phân loại:** **CÓ (YES)**, đây chính xác là một thuật toán Giảm theo kích thước biến thiên (Variable-size-decrease). Tại mỗi bước lặp, khi di chuyển từ `curr` sang `curr.right`, ta loại bỏ toàn bộ cây con bên trái của `curr` và chính nút `curr`. Số lượng nút bị loại bỏ biến thiên linh hoạt tùy thuộc vào hình dạng cấu trúc của cây.

#### Phần b (Độ phức tạp trường hợp xấu nhất):
- Trường hợp xấu nhất xảy ra khi cây BST bị **suy biến hoàn toàn thành một đường thẳng lệch phải** (mọi nút chỉ có con phải, không có con trái).
- Khi đó độ cao của cây là $h = n - 1$.
- Thuật toán phải duyệt qua toàn bộ $n$ nút từ gốc đến lá:
  $$T_{worst}(n) \in \mathbf{\Theta(n)}$$

---

### Bài 8 (Deleting a Key from BST - Xóa khóa khỏi cây BST)
> **Đề bài:**  
> a. Phác thảo một thuật toán để xóa một khóa khỏi Cây tìm kiếm nhị phân (BST). Bạn có phân loại thuật toán này vào nhóm thuật toán giảm theo kích thước biến thiên không?  
> b. Lớp độ phức tạp thời gian trong trường hợp xấu nhất là gì?

#### Lời giải chi tiết:

#### Phần a:
- **Thuật toán xóa nút có khóa $K$:**
  1. **Bước 1 (Tìm kiếm nút cần xóa):** So sánh $K$ với nút hiện tại, rẽ trái hoặc phải cho đến khi tìm thấy nút $Z$ có khóa $K$.
  2. **Bước 2 (Xóa nút $Z$):**
     - *Trường hợp 1 (Nút lá):* Không có con $\implies$ đơn giản xóa $Z$ và cập nhật con trỏ của cha $Z$ thành `null`.
     - *Trường hợp 2 (Nút có 1 con):* Cho nút cha của $Z$ trỏ thẳng vào nút con duy nhất của $Z$.
     - *Trường hợp 3 (Nút có 2 con):* Tìm nút kế vị $Y$ (nút có khóa nhỏ nhất trong cây con phải của $Z$). Sao chép khóa của $Y$ vào $Z$, sau đó gọi đệ quy xóa nút $Y$ khỏi cây con phải (vì $Y$ là nút nhỏ nhất cây con phải nên $Y$ chỉ có tối đa 1 con).
- **Phân loại:** **CÓ (YES)**, đây là thuật toán Giảm theo kích thước biến thiên vì cả quá trình tìm kiếm nút và tìm nút kế vị đều loại bỏ các cây con có kích thước biến thiên sau mỗi bước.

#### Phần b (Độ phức tạp trường hợp xấu nhất):
- Trường hợp xấu nhất khi cây suy biến thành danh sách liên kết có độ cao $h = n$.
- Chi phí tìm kiếm và thay thế tốn thời gian tỉ lệ thuận với độ cao:
  $$T_{worst}(n) \in \mathbf{\Theta(n)}$$

---

### Bài 9 (Hierholzer's Algorithm for Eulerian Circuit - Chu trình Euler bằng Giảm biến thiên)
> **Đề bài:**  
> Phác thảo một thuật toán giảm theo kích thước biến thiên để xây dựng chu trình Euler trong một đồ thị liên thông có tất cả các đỉnh đều có bậc chẵn.

#### Lời giải chi tiết:
Đây chính là **Thuật toán Hierholzer (1873)**:

1. **Khởi tạo:** Chọn một đỉnh xuất phát tùy ý $v_0$.
2. **Dò tìm chu trình con đầu tiên $C$:**
   - Xuất phát từ $v_0$, đi qua các cạnh chưa thăm bất kỳ.
   - Vì mọi đỉnh đều có bậc chẵn, khi đi vào một đỉnh ta luôn tìm được một cạnh chưa thăm để đi ra. Do đó, đường đi chỉ có thể kết thúc khi quay trở về chính đỉnh xuất phát $v_0$, tạo thành một **chu trình đơn $C$**.
3. **Bước Giảm kích thước biến thiên:**
   - Xóa tất cả các cạnh thuộc chu trình $C$ ra khỏi đồ thị ban đầu.
   - Đồ thị còn lại $G'$ có thể bị tách thành nhiều thành phần liên thông, nhưng **mọi đỉnh trong $G'$ vẫn duy trì bậc chẵn** (vì chu trình $C$ lấy đi đúng 2 cạnh tại mỗi đỉnh mà nó đi qua). Kích thước số cạnh của đồ thị giảm đi một lượng biến thiên $|C|$.
4. **Hợp nhất (Conquer & Merge):**
   - Duyệt dọc theo chu trình $C$, tìm đỉnh đầu tiên $u \in C$ vẫn còn cạnh chưa thăm trong $G'$.
   - Lặp lại đệ quy tìm chu trình con mới $C'$ xuất phát từ $u$.
   - Chèn chu trình con $C'$ vào vị trí của đỉnh $u$ trong chu trình $C$.
   - Lặp lại cho đến khi toàn bộ các cạnh của đồ thị đều được duyệt hết.
- **Độ phức tạp thời gian:** Đạt **$\Theta(|E|)$** (tuyến tính tối ưu) khi dùng danh sách liên kết lưu chu trình.

---

### Bài 10 (Misère One-Pile Nim - Trò chơi Nim Misère 1 đống)
> **Đề bài:**  
> Xét phiên bản Misère của trò chơi Nim 1 đống: Có 1 đống $n$ viên sỏi, mỗi lượt người chơi bốc từ 1 đến $m$ viên sỏi. Điểm khác biệt là: **Người chơi bốc viên sỏi cuối cùng là người THUA CUỘC**. Xác định các vị trí thắng và vị trí thua (cho người đến lượt đi kế tiếp).

#### Lời giải chi tiết:
- **Phân tích các giá trị nhỏ của $n$:**
  - $n = 1$: Người đến lượt đi buộc phải bốc 1 viên sỏi cuối cùng và lập tức **THUA**. Vậy $n = 1$ là **Thế thua (Losing position)**.
  - $2 \le n \le m + 1$: Người đến lượt đi có thể bốc $n - 1$ viên (số lượng này hợp lệ vì $1 \le n - 1 \le m$), để lại đúng 1 viên sỏi cho đối thủ. Đối thủ buộc phải bốc viên sỏi cuối và thua $\implies$ Các trạng thái $2 \le n \le m + 1$ là **Thế thắng (Winning position)**.
  - $n = m + 2$: Người đến lượt đi bốc bất kỳ số sỏi nào từ $1$ đến $m$ sẽ để lại cho đối thủ số sỏi nằm trong khoảng $[2, m + 1]$ (đều là thế thắng cho đối thủ) $\implies n = m + 2$ là **Thế thua (Losing position)**.
  - $m + 3 \le n \le 2m + 2$: Người chơi có thể bốc để đưa về $m + 2$ sỏi $\implies$ Thế thắng.
- **Quy luật tổng quát (Quy nạp toán học):**
  - **Thế thua (Losing position):** Khi và chỉ khi:
    $$n \equiv 1 \pmod{m + 1}$$
  - **Thế thắng (Winning position):** Khi và chỉ khi:
    $$n \not\equiv 1 \pmod{m + 1}$$
  - **Chiến lược đi thắng:**
    - Nếu $n > m + 1$: Bốc $(n - 1) \bmod (m + 1)$ viên sỏi để đưa đối thủ về trạng thái $1 \pmod{m + 1}$.
    - Khi đối thủ bị dồn về trạng thái $k \le m + 1$ sỏi ($k > 1$): Bốc đúng $k - 1$ viên sỏi để để lại đúng 1 viên duy nhất cho đối thủ.

---

### Bài 11 (Moldy Chocolate Bar - Thanh sô-cô-la có ô mốc)
> **Đề bài:**  
> Hai người chơi lần lượt bẻ một thanh sô-cô-la kích thước $m \times n$, trong đó có đúng một ô $1 \times 1$ bị mốc. Mỗi lần bẻ phải là một đường thẳng cắt ngang hoàn toàn thanh dọc theo rãnh phân chia giữa các ô. Sau mỗi lần bẻ, người vừa bẻ sẽ ăn phần sô-cô-la không chứa ô mốc. Người chơi nào bị để lại đúng ô mốc $1 \times 1$ duy nhất là người thua cuộc.  
> a. Đi trước hay đi sau có lợi thế thắng trong trò chơi này?  
> b. Thiết kế thuật toán / chương trình tương tác chơi trò chơi này.

#### Lời giải chi tiết:

#### Phần a (Quy đổi về trò chơi Nim 4 đống):
- Giả sử ô mốc nằm ở hàng $r$ ($1 \le r \le m$) và cột $c$ ($1 \le c \le n$).
- Ô mốc này phân chia thanh sô-cô-la thành 4 khoảng cách tới 4 mép biên:
  - Phía trên: $x_1 = r - 1$ hàng sô-cô-la lành.
  - Phía dưới: $x_2 = m - r$ hàng sô-cô-la lành.
  - Phía bên trái: $y_1 = c - 1$ cột sô-cô-la lành.
  - Phía bên phải: $y_2 = n - c$ cột sô-cô-la lành.
- Mỗi nước đi bẻ thanh sô-cô-la và giữ lại phần chứa ô mốc tương đương chính xác với việc: **Giảm kích thước của đúng 1 trong 4 đại lượng $x_1, x_2, y_1, y_2$ xuống một giá trị tùy ý nhỏ hơn!**
- Trò chơi kết thúc khi cả 4 giá trị đều bằng 0 ($x_1 = x_2 = y_1 = y_2 = 0$), khi đó chỉ còn lại ô mốc $1 \times 1$ và người đến lượt đi nhận ô mốc này sẽ thua.
- Đây chính là **Trò chơi Nim chuẩn gồm 4 đống** với kích thước các đống là $(r - 1, m - r, c - 1, n - c)$!
- **Chiến lược thắng & Quyền đi trước/sau:**
  - Tính tổng Nim (Nim-sum):
    $$S = (r - 1) \oplus (m - r) \oplus (c - 1) \oplus (n - c)$$
  - Nếu $S \ne 0$: Trạng thái ban đầu là **Thế thắng** $\implies$ **NGƯỜI ĐI TRƯỚC (First player) có chiến lược chắc chắn thắng**!
  - Nếu $S = 0$: Trạng thái ban đầu là **Thế thua** $\implies$ **NGƯỜI ĐI SAU (Second player) có chiến lược chắc chắn thắng**!

#### Phần b (Thiết kế chương trình tương tác):
```text
Algorithm PlayMoldyChocolate(m, n, r, c)
// Chương trình chơi sô-cô-la mốc với người dùng
1   piles ← [r - 1, m - r, c - 1, n - c]
2   while true do
3       S ← piles[0] ⊕ piles[1] ⊕ piles[2] ⊕ piles[3]
4       if S ≠ 0 then
5           // Tìm đống i sao cho piles[i] ⊕ S < piles[i] (Nước đi thắng)
6           Tìm i sao cho piles[i] ⊕ S < piles[i]
7           new_val ← piles[i] ⊕ S
8           Thực hiện bẻ mép tương ứng để giảm piles[i] xuống new_val
9       else
10          Thực hiện một nước bẻ hợp lệ bất kỳ (giảm 1 đơn vị ở đống bất kỳ > 0)
11      if piles = [0, 0, 0, 0] then
12          In "Máy tính thắng!"; return
13      Nhận nước đi bẻ sô-cô-la từ người dùng và cập nhật mảng piles
```

---

### Bài 12 (Flipping Pancakes - Bài toán Lật bánh kếp)
> **Đề bài:**  
> Có $n$ chiếc bánh kếp có kích thước đôi một khác nhau được xếp chồng lên nhau. Bạn được phép luồn một chiếc xẻng lật vào dưới một chiếc bánh bất kỳ và lật úp toàn bộ phần chồng bánh nằm phía trên chiếc xẻng. Mục tiêu là sắp xếp chồng bánh sao cho bánh to nhất nằm ở đáy, và các bánh nhỏ dần lên đỉnh. Thiết kế một thuật toán để giải câu đố này.

#### Lời giải chi tiết:
Đây là bài toán kinh điển **Pancake Sorting** (từng được Bill Gates nghiên cứu vào năm 1979). Áp dụng chiến lược **Giảm 1 (Decrease-by-one)**:

1. **Ý tưởng:** Đưa chiếc bánh lớn nhất trong phần chưa sắp xếp về đúng vị trí đáy của nó:
   - Giả sử xét chồng bánh chưa sắp xếp gồm $k$ bánh ($k$ từ $n$ giảm dần về 2).
   - **Bước 1:** Tìm vị trí $idx$ của chiếc bánh lớn nhất trong số $k$ chiếc bánh hiện tại.
   - **Bước 2 (Lật lên đỉnh):** Nếu bánh lớn nhất chưa ở đỉnh ($idx > 0$), luồn xẻng dưới chiếc bánh này tại vị trí $idx$ và lật $\implies$ Chiếc bánh lớn nhất được đưa lên **ĐỈNH** của chồng bánh (tốn 1 lần lật).
   - **Bước 3 (Lật về đáy):** Luồn xẻng dưới chiếc bánh thứ $k$ (vị trí đáy của phần chưa sắp xếp) và lật toàn bộ $k$ bánh $\implies$ Chiếc bánh lớn nhất về đúng **ĐÁY** của đoạn $k$ chiếc bánh (tốn 1 lần lật).
2. **Kích thước bài toán:** Giảm từ $k$ bánh xuống $k - 1$ bánh!
3. **Mã giả thuật toán:**
```text
Algorithm PancakeSort(P[0..n-1])
// Sắp xếp chồng bánh kích thước khác nhau
1   for k ← n down to 2 do
2       max_idx ← chỉ số của phần tử lớn nhất trong P[0..k-1]
3       if max_idx ≠ k - 1 then
4           if max_idx > 0 then
5               Flip(P, max_idx)   // Đưa bánh lớn nhất lên đỉnh
6           Flip(P, k - 1)         // Đưa bánh lớn nhất về đáy đoạn k
```
- **Số lần lật tối đa trong trường hợp xấu nhất:** Mỗi chiếc bánh cần tối đa 2 lần lật để về đúng vị trí. Với $n$ chiếc bánh, chiếc cuối cùng tự động đúng chỗ:
  $$\text{Số lần lật tối đa} = 2(n - 1) = \mathbf{2n - 2 \text{ lần lật}}$$

---

### Bài 13 (Search in Row-Column Sorted Matrix in $O(n)$ - Tìm kiếm trong ma trận hai chiều tăng dần)
> **Đề bài:**  
> Bạn cần tìm kiếm một số đã cho trong một ma trận kích thước $n \times n$, trong đó **mọi hàng và mọi cột đều được sắp xếp theo thứ tự tăng dần**. Bạn có thể thiết kế một thuật toán $O(n)$ cho bài toán này không?

#### Lời giải chi tiết:
- **Khẳng định:** Hoàn toàn làm được! Đây là thuật toán nổi tiếng **Saddleback Search** (hoặc Thuật toán tìm kiếm điểm yên ngựa).
- **Ý tưởng thiết kế (Giảm theo kích thước biến thiên / Giảm 1 hàng hoặc 1 cột):**
  - Xuất phát từ góc **Trên - Phải** của ma trận: ô $(row, col) = (0, n - 1)$.
  - Tại ô $(row, col)$, phần tử $M[row][col]$ có tính chất đặc biệt:
    - Nó là phần tử **lớn nhất** trên hàng $row$ (từ cột $0$ đến $col$).
    - Nó là phần tử **nhỏ nhất** trên cột $col$ (từ hàng $row$ đến $n-1$).
  - So sánh giá trị khóa $K$ với $M[row][col]$:
    1. Nếu $K = M[row][col]$: **Tìm thấy!** Trả về tọa độ $(row, col)$.
    2. Nếu $K < M[row][col]$: Vì $K$ nhỏ hơn phần tử nhỏ nhất của cột $col$, nên $K$ không thể xuất hiện ở bất kỳ ô nào trên cột $col$. Ta **loại bỏ toàn bộ cột $col$** $\implies col \leftarrow col - 1$.
    3. Nếu $K > M[row][col]$: Vì $K$ lớn hơn phần tử lớn nhất của hàng $row$, nên $K$ không thể xuất hiện ở bất kỳ ô nào trên hàng $row$. Ta **loại bỏ toàn bộ hàng $row$** $\implies row \leftarrow row + 1$.

```mermaid
flowchart TD
    Start["Bắt đầu tại ô góc Trên-Phải: row = 0, col = n - 1"] --> Check{"So sánh K và M[row][col]"}
    Check -->|"K = M[row][col]"| Found["Tìm thấy tại (row, col)!"]
    Check -->|"K < M[row][col]"| Left["Loại bỏ cột col:<br>col = col - 1"]
    Check -->|"K > M[row][col]"| Down["Loại bỏ hàng row:<br>row = row + 1"]
    Left --> Bound{"col ≥ 0 và row < n?"}
    Down --> Bound
    Bound -->|"Đúng"| Check
    Bound -->|"Sai"| NotFound["Không tìm thấy trong ma trận!"]
```

#### Mã giả chuẩn hóa:
```text
Algorithm MatrixSearch(M[0..n-1, 0..n-1], K)
// Tìm kiếm khóa K trong ma trận có hàng và cột tăng dần
// Đầu vào: Ma trận M kích thước n x n và khóa K
// Đầu ra: Cặp chỉ số (row, col) hoặc thông báo không tìm thấy

1   row ← 0
2   col ← n - 1
3   while row < n and col ≥ 0 do
4       if M[row][col] = K then
5           return (row, col)
6       else if K < M[row][col] then
7           col ← col - 1     // Loại bỏ cột col
8       else
9           row ← row + 1     // Loại bỏ hàng row
10  return "Không tìm thấy"
```

#### Phân tích độ phức tạp thời gian:
- Tại mỗi lần so sánh trong vòng lặp `while`, ta hoặc giảm chỉ số cột `col` đi 1, hoặc tăng chỉ số hàng `row` lên 1.
- Chỉ số `row` chỉ có thể tăng tối đa $n$ lần (từ $0$ lên $n$).
- Chỉ số `col` chỉ có thể giảm tối đa $n$ lần (từ $n - 1$ xuống $-1$).
- Tổng số lần lặp tối đa trong trường hợp xấu nhất là:
  $$N_{steps} = n + n - 1 = 2n - 1 \text{ bước lặp}$$
- Mỗi bước lặp thực hiện số phép toán hằng số $O(1)$.
- Do đó độ phức tạp thời gian của thuật toán là:
  $$T(n) \in \mathbf{O(n)}$$
  (Nhanh hơn rất nhiều so với việc tìm kiếm nhị phân trên từng hàng tốn $O(n \log n)$).


---

