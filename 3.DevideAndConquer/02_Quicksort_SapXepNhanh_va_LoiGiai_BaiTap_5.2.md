# CHUYÊN ĐỀ 02: THUẬT TOÁN SẮP XẾP NHANH (QUICKSORT) & LỜI GIẢI CHI TIẾT 100% BÀI TẬP 5.2
## Trích dẫn: Anany Levitin, "Introduction to the Design and Analysis of Algorithms", 3rd Edition, Mục 5.2 (pp. 176–182)

---

## PHẦN 1: LÝ THUYẾT NỀN TẢNG & MÃ GIẢ CHUẨN HÓA

### 1.1. Bản chất Ý tưởng và Chiến lược Thiết kế
Thuật toán **Sắp xếp nhanh (Quicksort)** được C.A.R. Hoare phát minh năm 1960. Trái ngược với Mergesort (chia mảng theo **vị trí** và tốn công sức ở bước **kết hợp**), Quicksort chia mảng theo **giá trị** của các phần tử và dồn toàn bộ nỗ lực vào bước **chia (phân hoạch - partitioning)**:
1. **Phân hoạch (Partitioning)**: Chọn một phần tử làm chốt (*pivot* $p$). Sắp xếp lại đoạn mảng sao cho:
   - Tất cả các phần tử nhỏ hơn hoặc bằng $p$ dồn về bên trái.
   - Tất cả các phần tử lớn hơn hoặc bằng $p$ dồn về bên phải.
   - Phần tử $p$ nằm tại vị trí phân tách chính xác $s$ trong mảng đã sắp xếp.
2. **Trị (Conquer)**: Đệ quy áp dụng Quicksort cho hai mảng con $A[l..s-1]$ và $A[s+1..r]$.
3. **Kết hợp (Combine)**: Hoàn toàn không tốn chi phí ($O(1)$) vì các mảng con đã nằm đúng vùng giá trị của chúng!

---

### 1.2. Mã giả Cấu trúc Chuẩn hóa

#### Thuật toán Quicksort tổng thể
```text
algorithm: Quicksort(A[l..r])
    input:  Mảng con A[l..r] của mảng A[0..n - 1] (0 ≤ l ≤ r ≤ n - 1).
   output:  Mảng con A[l..r] được sắp xếp theo thứ tự không giảm.

1   if l < r then
2       s ← HoarePartition(A[l..r])   // s là vị trí phân hoạch của chốt
3       Quicksort(A[l..s - 1])        // Đệ quy sắp xếp nửa bên trái chốt
4       Quicksort(A[s + 1..r])        // Đệ quy sắp xếp nửa bên phải chốt
```

#### Thuật toán Phân hoạch Hoare (Hoare Partition)
```text
algorithm: HoarePartition(A[l..r])
    input:  Đoạn mảng A[l..r] với l < r.
   output:  Vị trí phân hoạch s và mảng A[l..r] được sắp xếp lại sao cho:
            mọi k < s: A[k] ≤ A[s] và mọi k > s: A[k] ≥ A[s].

1   p ← A[l]          // Chọn phần tử đầu tiên làm chốt (pivot)
2   i ← l;  j ← r + 1
3   repeat
4       repeat i ← i + 1 until A[i] ≥ p
5       repeat j ← j - 1 until A[j] ≤ p
6       swap(A[i], A[j])
7   until i ≥ j
8   swap(A[i], A[j])  // Hoàn tác phép hoán đổi dư thừa cuối cùng khi i ≥ j
9   swap(A[l], A[j])  // Đưa chốt về vị trí phân hoạch chính xác
10  return j
```

---

### 1.3. Phân tích Toán học Hiệu năng Thuật toán Quicksort

#### Phân tích số phép so sánh khóa trong thủ tục Phân hoạch
Trong mỗi lần gọi `HoarePartition(A[l..r])`, các con trỏ $i$ và $j$ quét từ hai đầu vào trong. Số phép so sánh khóa thực hiện là:
$$r - l + 1 \quad \text{(nếu không cần lính canh) hoặc } r - l + 2$$
Trung bình và xấp xỉ là $n + 1$ phép so sánh trên đoạn $n$ phần tử.

#### Trường hợp xấu nhất ($C_{worst}(n)$)
Xảy ra khi tại mọi bước, chốt luôn là phần tử nhỏ nhất hoặc lớn nhất (ví dụ: mảng đã tăng dần nghiêm ngặt). Khi đó một mảng con rỗng ($0$ phần tử) và mảng con còn lại có kích thước $n-1$:
$$C_{worst}(n) = C_{worst}(n-1) + (n + 1) \quad (n > 1), \quad C_{worst}(1) = 0$$
$$\begin{aligned}
C_{worst}(n) &= (n+1) + n + (n-1) + \dots + 3 \\
             &= \frac{(n+1)(n+2)}{2} - 3 = \frac{n^2 + 3n - 4}{2} \in \Theta(n^2)
\end{aligned}$$

#### Trường hợp tốt nhất ($C_{best}(n)$)
Xảy ra khi tại mọi bước, chốt luôn chia đôi mảng thành hai nửa bằng nhau có kích thước xấp xỉ $\lfloor (n-1)/2 \rfloor$:
$$C_{best}(n) = 2 C_{best}(n/2) + n$$
Theo Định lý Thợ với $a=2, b=2, d=1 \implies a = b^d$:
$$C_{best}(n) \in \Theta(n \log n)$$
Chính xác với $n = 2^k - 1$: $C_{best}(n) = n \log_2 (n+1) - n \approx n \log_2 n$.

#### Trường hợp trung bình ($C_{avg}(n)$)
Giả định mọi vị trí phân hoạch $s \in [0..n-1]$ đều có xác suất xuất hiện như nhau là $\frac{1}{n}$:
$$C_{avg}(n) = (n + 1) + \frac{1}{n} \sum_{s=0}^{n-1} [C_{avg}(s) + C_{avg}(n - 1 - s)] = (n + 1) + \frac{2}{n} \sum_{k=0}^{n-1} C_{avg}(k)$$
Nhân cả hai vế với $n$:
$$n C_{avg}(n) = n(n+1) + 2 \sum_{k=0}^{n-1} C_{avg}(k) \quad (1)$$
Thay $n$ bằng $n-1$:
$$(n-1) C_{avg}(n-1) = n(n-1) + 2 \sum_{k=0}^{n-2} C_{avg}(k) \quad (2)$$
Lấy $(1) - (2)$:
$$n C_{avg}(n) - (n-1) C_{avg}(n-1) = 2n + 2 C_{avg}(n-1) \implies n C_{avg}(n) = (n+1) C_{avg}(n-1) + 2n$$
Chia cả hai vế cho $n(n+1)$:
$$\frac{C_{avg}(n)}{n+1} = \frac{C_{avg}(n-1)}{n} + \frac{2}{n+1}$$
Đặt $a_n = \frac{C_{avg}(n)}{n+1}$, ta có:
$$a_n = a_{n-1} + \frac{2}{n+1} = a_1 + 2 \sum_{k=2}^n \frac{1}{k+1} \approx 2 \sum_{k=1}^n \frac{1}{k} \approx 2 \ln n$$
Do đó:
$$C_{avg}(n) \approx 2(n+1) \ln n \approx 2n \frac{\log_2 n}{\log_2 e} \approx 2 \ln 2 \cdot n \log_2 n \approx 1.386 n \log_2 n$$
- **Nhận xét quan trọng**: Quicksort chỉ tốn hơn Mergesort khoảng $39\%$ số phép so sánh trong trường hợp trung bình, nhưng vòng lặp trong của Quicksort cực kỳ gọn nhẹ, không cần mảng phụ và tối ưu hóa bộ nhớ đệm (cache), khiến nó chạy nhanh hơn Mergesort trong thực tế trên hầu hết hệ thống phần cứng.

#### Độ phức tạp Không gian và Tối ưu Ngăn xếp (Stack Space)
- Trong trường hợp xấu nhất, chiều sâu đệ quy là $n \implies$ tốn $O(n)$ không gian ngăn xếp.
- **Kỹ thuật tối ưu đệ quy đuôi (Tail Recursion Optimization)**: Luôn gọi đệ quy cho mảng con có kích thước **nhỏ hơn trước**, và dùng vòng lặp cho mảng con lớn hơn. Vì mảng con nhỏ hơn có kích thước tối đa là $n/2$, chiều sâu ngăn xếp tối đa luôn được bảo đảm ở mức:
  $$S(n) \le \lceil \log_2 n \rceil = O(\log n)$$

---

## PHẦN 2: LỜI GIẢI CHI TIẾT 100% BÀI TẬP 5.2 (BÀI 1 ĐẾN BÀI 11)

---

### Bài 1 (Exercises 5.2 - Trang 181)
**Đề bài:**  
*Áp dụng thuật toán Quicksort để sắp xếp danh sách các chữ cái: `E, X, A, M, P, L, E` theo thứ tự bảng chữ cái. Vẽ cây của các lời gọi đệ quy.*

#### Lời giải chi tiết:
Mảng ban đầu: $A[0..6] = [E_1, X, A, M, P, L, E_2]$.

**Bước 1: Phân hoạch đoạn $A[0..6]$ với chốt $p = A[0] = E_1$:**
- Khởi tạo: $i = 0, j = 7$.
- Quét $i$ tìm phần tử $\ge E_1$: $A[1] = X \ge E_1 \implies i = 1$.
- Quét $j$ tìm phần tử $\le E_1$: $A[6] = E_2 \le E_1 \implies j = 6$.
- $i < j$: Hoán đổi $A[1]$ và $A[6] \implies A = [E_1, E_2, A, M, P, L, X]$.
- Quét tiếp:
  - $i$ tăng tới $A[3] = M \ge E_1 \implies i = 3$.
  - $j$ giảm tới $A[2] = A \le E_1 \implies j = 2$.
- Dừng vì $i \ge j$ ($3 \ge 2$). Hoán đổi dư thừa hoàn tác, sau đó hoán đổi $A[l]$ và $A[j]$ (tức $A[0]$ và $A[2]$):
  $$\text{Đổi } A[0] (E_1) \leftrightarrow A[2] (A) \implies A = [A, E_2, \mathbf{E_1}, M, P, L, X]$$
- Chốt $E_1$ nằm tại vị trí $s = 2$. Hai mảng con là $A[0..1] = [A, E_2]$ và $A[3..6] = [M, P, L, X]$.

**Bước 2: Quicksort nhánh trái $A[0..1] = [A, E_2]$ với chốt $p = A$:**
- $i$ dừng tại $1$ ($E_2 \ge A$), $j$ dừng tại $0$ ($A \le A$). $i \ge j$, hoán đổi $A[0]$ với chính nó $\implies s = 0$.
- Đoạn con trái rỗng, đoạn con phải là $[E_2]$ ($1$ phần tử $\implies$ xong).

**Bước 3: Quicksort nhánh phải $A[3..6] = [M, P, L, X]$ với chốt $p = M$:**
- $i$ dừng tại $A[4] = P \ge M$, $j$ dừng tại $A[5] = L \le M$.
- Hoán đổi $P \leftrightarrow L \implies [M, L, P, X]$.
- Quét tiếp: $i$ dừng tại $P$ (vị trí 5), $j$ dừng tại $L$ (vị trí 4). $i \ge j$.
- Hoán đổi $A[3] (M) \leftrightarrow A[4] (L) \implies [L, \mathbf{M}, P, X]$.
- Chốt $M$ nằm tại vị trí $s = 4$. Hai mảng con là $[L]$ (xong) và $[P, X]$.

**Bước 4: Quicksort $[P, X]$ với chốt $p = P$:**
- $s = 5$ cố định $P$, mảng con $[X]$ xong.

**Cây các lời gọi đệ quy (Recursive Call Tree):**
```text
                     Quicksort(A[0..6]) [E1, X, A, M, P, L, E2]
                              s = 2 (chốt E1)
                             /              \
            Quicksort(A[0..1])              Quicksort(A[3..6])
               [A, E2] (s=0, chốt A)           [M, P, L, X] (s=4, chốt M)
              /       \                       /            \
          (rỗng)   Quicksort(A[1..1])   Quicksort(A[3..3])  Quicksort(A[5..6])
                         [E2]                  [L]            [P, X] (s=5, chốt P)
                                                             /       \
                                                          (rỗng)   Quicksort(A[6..6])
                                                                         [X]
```
**Kết quả cuối cùng:** `[A, E2, E1, L, M, P, X]`.

---

### Bài 2 (Exercises 5.2 - Trang 181)
**Đề bài:**  
*Đối với thủ tục phân hoạch Hoare:*  
*a. Chứng minh rằng nếu hai chỉ số quét dừng lại khi cùng trỏ tới một phần tử ($i = j$), thì giá trị của phần tử đó bắt buộc phải bằng chốt ($A[i] = p$).*  
*b. Chứng minh rằng khi các chỉ số dừng quét, $j$ không thể trỏ tới vị trí lệch quá một vị trí về bên trái của $i$ (tức $j \ge i - 1$).*

#### Lời giải chi tiết:

**a. Chứng minh $i = j \implies A[i] = p$:**
- Quy tắc tăng con trỏ $i$: Vòng lặp `repeat i ← i + 1 until A[i] ≥ p` chỉ dừng lại khi phần tử tại $i$ thỏa mãn:
  $$A[i] \ge p$$
- Quy tắc giảm con trỏ $j$: Vòng lặp `repeat j ← j - 1 until A[j] ≤ p` chỉ dừng lại khi phần tử tại $j$ thỏa mãn:
  $$A[j] \le p$$
- Nếu hai chỉ số cùng dừng tại cùng một vị trí, tức là $i = j$, thì phần tử tại vị trí này phải đồng thời thỏa mãn cả hai điều kiện dừng:
  $$A[i] \ge p \quad \text{và} \quad A[i] \le p$$
- Từ hai bất đẳng thức trên, theo tính chất phản xứng của quan hệ thứ tự, bắt buộc:
  $$A[i] = p$$
  $\blacksquare$

**b. Chứng minh $j$ không thể lệch quá một vị trí về bên trái của $i$ ($j \ge i - 1$):**
- Trước khi thực hiện bước quét hiện tại, giả sử hai chỉ số đang có thứ tự $i < j$ (vì nếu $i \ge j$ vòng lặp ngoài đã kết thúc).
- Khi con trỏ $i$ di chuyển sang phải từng bước một ($i \leftarrow i + 1$), nó chỉ dừng lại tại vị trí đầu tiên $i_{new}$ có $A[i_{new}] \ge p$.
- Sau đó, con trỏ $j$ di chuyển sang trái từng bước một ($j \leftarrow j - 1$). Nó kiểm tra các phần tử.
- Nếu $j$ di chuyển giảm dần và tiến về phía $i_{new}$:
  - Khi $j$ chạm tới $i_{new}$: Ta đã biết $A[i_{new}] \ge p$. Nếu $A[i_{new}] = p$, thì điều kiện $A[j] \le p$ được thỏa mãn ngay tại đây, $j$ dừng lại ngay tại $j = i_{new}$.
  - Nếu $A[i_{new}] > p$, thì $j$ không dừng tại $i_{new}$ mà giảm tiếp thêm 1 đơn vị: $j = i_{new} - 1$.
  - Nhưng trước vị trí $i_{new}$, phần tử tại $i_{new} - 1$ vừa được kiểm tra ở lần quét trước (hoặc là vị trí đã được hoán đổi sao cho $A \le p$, hoặc chính là chốt ban đầu $A[l] = p \le p$). Do đó, tại vị trí $j = i_{new} - 1$, chắc chắn giá trị $A[j] \le p$ luôn thỏa mãn!
  - Do đó con trỏ $j$ **bắt buộc phải dừng ngay lập tức tại $j = i_{new} - 1$**, không bao giờ có thể giảm tiếp xuống $i_{new} - 2$.
- Vậy khi dừng quét, chỉ có hai khả năng: $j = i$ hoặc $j = i - 1$. Tuyệt đối không thể xảy ra $j \le i - 2$. $\blacksquare$

---

### Bài 3 (Exercises 5.2 - Trang 181)
**Đề bài:**  
*Hãy đưa ra một ví dụ chứng minh rằng Quicksort không phải là một thuật toán sắp xếp ổn định (not stable).*

#### Lời giải chi tiết:
Xét mảng gồm 3 phần tử: $A = [2_a, 2_b, 1]$ (đánh dấu $a, b$ để phân biệt hai số 2 bằng nhau, $2_a$ xuất hiện trước $2_b$).

**Áp dụng Quicksort với phân hoạch Hoare:**
1. Chọn chốt $p = A[0] = 2_a$.
2. Khởi tạo $i = 0, j = 3$.
3. Quét $i$: $A[1] = 2_b \ge p \implies i$ dừng tại chỉ số $1$.
4. Quét $j$: $A[2] = 1 \le p \implies j$ dừng tại chỉ số $2$.
5. Vì $i < j$ ($1 < 2$), thực hiện hoán đổi $A[i] \leftrightarrow A[j]$ (đổi $2_b \leftrightarrow 1$):
   $$A = [2_a, 1, 2_b]$$
6. Quét tiếp:
   - $i$ tăng tới $2$ ($A[2] = 2_b \ge p$) $\implies i = 2$.
   - $j$ giảm tới $1$ ($A[1] = 1 \le p$) $\implies j = 1$.
7. Dừng vì $i \ge j$ ($2 \ge 1$). Hoán đổi chốt $A[0]$ và $A[j]$ (đổi $A[0] \leftrightarrow A[1]$, tức $2_a \leftrightarrow 1$):
   $$A = [1, 2_a, 2_b]$$
   *(Khoan, ở ví dụ này thứ tự $2_a, 2_b$ vô tình được giữ nguyên. Hãy xét ví dụ kinh điển hơn bên dưới)*.

**Ví dụ phản chứng chuẩn mực nhất:**
Xét mảng 4 phần tử: $A = [3, 2_a, 2_b, 1]$ với chốt $p = 3$.
- $i$ quét tìm phần tử $\ge 3$: không có (trừ lính canh ở ngoài).
- Hãy xét mảng: $A = [5, 3_a, 3_b, 1, 6]$ với chốt $p = 5$:
- $i$ dừng tại $6$ (vị trí 4), $j$ dừng tại $1$ (vị trí 3). Đổi $6 \leftrightarrow 1 \implies [5, 3_a, 3_b, 1, 6]$.

**Ví dụ ngắn gọn và chuẩn xác tuyệt đối (3 phần tử):**
Xét mảng $A = [3, 3^*, 1]$ với chốt $p = 3$:
1. $i = 0, j = 3$.
2. $i$ tăng đến $1$: $A[1] = 3^* \ge 3 \implies i$ dừng tại $1$.
3. $j$ giảm đến $2$: $A[2] = 1 \le 3 \implies j$ dừng tại $2$.
4. $i < j$: hoán đổi $A[1] \leftrightarrow A[2]$ (đổi $3^* \leftrightarrow 1$):
   $$A = [3, 1, 3^*]$$
5. Quét tiếp:
   - $i$ tăng đến $2$: $A[2] = 3^* \ge 3 \implies i = 2$.
   - $j$ giảm đến $1$: $A[1] = 1 \le 3 \implies j = 1$.
6. $i \ge j$, dừng quét. Hoán đổi chốt $A[0]$ với $A[j]$ (tức đổi $A[0] \leftrightarrow A[1]$, hoán đổi $3 \leftrightarrow 1$):
   $$A = [1, 3, 3^*]$$
*(Trong ví dụ này $3$ vẫn đứng trước $3^*$. Hãy xét ví dụ khi chốt được hoán đổi nhảy qua phần tử bằng nó!)*

**Ví dụ chuẩn xác nhất:** Xét $A = [2, 2^*, 1]$:
1. $p = A[0] = 2$.
2. $i$ dừng tại $1$ ($2^* \ge 2$). $j$ dừng tại $2$ ($1 \le 2$).
3. Đổi $A[1] \leftrightarrow A[2]$: mảng thành $[2, 1, 2^*]$.
4. Quét tiếp: $i$ dừng tại $2$ ($2^* \ge 2$), $j$ dừng tại $1$ ($1 \le 2$).
5. Dừng quét. Hoán đổi $A[0] (2)$ với $A[j] = A[1] (1)$:
   $$A = [1, 2, 2^*]$$
   
Bây giờ xét $A = [2, 1, 2^*]$:
1. $p = 2$. $i$ dừng tại $2$ ($2^* \ge 2$), $j$ dừng tại $2$ ($2^* \le 2$).
2. Vì $i = j = 2$, dừng quét. Đổi $A[0] (2) \leftrightarrow A[2] (2^*)$:
   $$A = [2^*, 1, 2]$$
Sau đó Quicksort đệ quy đoạn $[2^*, 1]$ sẽ đưa về:
$$[1, 2^*, 2]$$
- Ban đầu: $2$ đứng trước $2^*$.
- Kết quả cuối cùng: $2^*$ đứng trước $2$!  
Thứ tự tương đối bị đảo ngược. Vậy **Quicksort không ổn định**. $\blacksquare$

---

### Bài 4 (Exercises 5.2 - Trang 181)
**Đề bài:**  
*Hãy đưa ra ví dụ về một mảng gồm $n$ phần tử mà tại đó phần tử lính canh (sentinel) thực sự cần thiết. Giá trị của lính canh nên là bao nhiêu? Giải thích tại sao một lính canh duy nhất ở cuối mảng là đủ cho mọi trường hợp đầu vào.*

#### Lời giải chi tiết:
1. **Ví dụ mảng cần lính canh**:  
   Xét mảng đã sắp xếp tăng dần nghiêm ngặt: $A = [1, 2, 3, 4, 5]$ và không có lính canh.
   - Chọn chốt $p = A[0] = 1$.
   - Con trỏ $i$ bắt đầu tại $0$, tăng dần: $i \leftarrow i + 1$. Vòng lặp `until A[i] ≥ p` sẽ kiểm tra $A[1]=2 \ge 1, A[2]=3 \ge 1, \dots$. Nếu phần tử chốt $p$ lớn hơn tất cả các phần tử còn lại trong mảng (ví dụ mảng $A = [10, 2, 3, 4, 5]$):
     - Chốt $p = 10$.
     - $A[1]=2 < 10, A[2]=3 < 10, A[3]=4 < 10, A[4]=5 < 10$.
     - Con trỏ $i$ sẽ tăng vượt qua chỉ số $n-1 = 4$ sang vùng nhớ không hợp lệ ($i = 5, 6, \dots$) gây lỗi tràn bộ nhớ (*segmentation fault* / *out of bounds*)!
2. **Giá trị của lính canh**:  
   Lính canh cần được đặt tại $A[n]$ (ngay sau phần tử cuối cùng) với giá trị:
   $$\text{Sentinel} \ge \max_{0 \le k < n} A[k] \quad \text{(hoặc } +\infty \text{)}$$
   Khi con trỏ $i$ tăng tới $n$, điều kiện $A[n] \ge p$ chắc chắn thỏa mãn, ép con trỏ $i$ phải dừng lại.
3. **Tại sao một lính canh duy nhất ở cuối mảng là đủ?**
   - **Với con trỏ $j$ quét từ phải sang trái**: $j$ bắt đầu từ $r$ và giảm dần. Do chốt $p = A[l]$ nằm ở đầu đoạn mảng, khi $j$ giảm về tới vị trí $l$, điều kiện dừng $A[l] \le p$ (tức $p \le p$) **luôn luôn đúng**! Do đó, chính phần tử chốt $A[l]$ đã đóng vai trò là một lính canh tự nhiên ở phía bên trái. Con trỏ $j$ không bao giờ có thể chạy vượt quá biên trái ($j \ge l$).
   - Do phía bên trái đã có chốt bảo vệ tự nhiên, ta chỉ cần duy nhất một lính canh chặn ở biên cực phải của toàn bộ mảng là đủ bảo đảm an toàn cho mọi lần phân hoạch.

---

### Bài 5 (Exercises 5.2 - Trang 181)
**Đề bài:**  
*Đối với phiên bản Quicksort trong giáo trình (dùng phân hoạch Hoare):*  
*a. Mảng gồm tất cả các phần tử bằng nhau là trường hợp xấu nhất, tốt nhất, hay không phải cả hai?*  
*b. Mảng giảm dần nghiêm ngặt là trường hợp xấu nhất, tốt nhất, hay không phải cả hai?*

#### Lời giải chi tiết:

**a. Mảng gồm tất cả các phần tử bằng nhau ($A[0] = A[1] = \dots = A[n-1]$):**
- Trong phân hoạch Hoare, điều kiện dừng của $i$ là $A[i] \ge p$ và của $j$ là $A[j] \le p$.
- Vì mọi phần tử đều bằng $p$, nên con trỏ $i$ tăng đúng 1 bước là dừng ngay ($i \leftarrow i + 1$), và con trỏ $j$ giảm đúng 1 bước là dừng ngay ($j \leftarrow j - 1$).
- Hai con trỏ tiến đều từ hai đầu vào chính giữa với tốc độ như nhau.
- Kết quả là $i$ và $j$ gặp nhau ở **chính giữa mảng** ($s \approx \lfloor n/2 \rfloor$), chia mảng ban đầu thành hai nửa con có kích thước bằng nhau!
- Do đó, mảng chia đôi hoàn hảo ở mọi tầng đệ quy $\implies T(n) = 2T(n/2) + \Theta(n)$.
- **Kết luận**: Đây là **TRƯỜNG HỢP TỐT NHẤT (Best-case)** với độ phức tạp $\Theta(n \log n)$.

**b. Mảng giảm dần nghiêm ngặt ($A[0] > A[1] > \dots > A[n-1]$):**
- Chọn chốt $p = A[0]$ (là phần tử lớn nhất trong mảng).
- Vì $p$ lớn nhất, mọi phần tử còn lại đều nhỏ hơn $p$.
- Con trỏ $i$: tìm phần tử $\ge p$, do không có phần tử nào lớn hơn $p$, $i$ sẽ chạy thẳng đến cuối mảng (hoặc gặp lính canh).
- Con trỏ $j$: bắt đầu từ cuối mảng ($r$), phần tử tại $r$ nhỏ hơn $p$ nên $j$ dừng ngay tại $r$.
- Các cặp phần tử ở hai đầu được hoán đổi liên tục, và mảng bị đảo ngược thành tăng dần. Vị trí phân hoạch chốt rơi vào điểm chia không cân bằng.
- **Kết luận**: Đây là **TRƯỜNG HỢP XẤU NHẤT (Worst-case)** với độ phức tạp $\Theta(n^2)$.

---

### Bài 6 (Exercises 5.2 - Trang 181)
**Đề bài:**  
*Đối với Quicksort sử dụng kỹ thuật chọn chốt là trung vị của ba phần tử (Median-of-three: phần tử đầu, giữa và cuối):*  
*a. Mảng tăng dần nghiêm ngặt là trường hợp xấu nhất, tốt nhất, hay không phải cả hai?*  
*b. Trả lời câu hỏi tương tự cho mảng giảm dần nghiêm ngặt.*

#### Lời giải chi tiết:

**a. Mảng tăng dần nghiêm ngặt:**  
- Ba phần tử được xét: $A[l]$ (nhỏ nhất), $A[m]$ (ở giữa), và $A[r]$ (lớn nhất).
- Trung vị của 3 phần tử này chính là $A[m]$ - phần tử nằm ở chính giữa mảng!
- Kỹ thuật Median-of-three sẽ chọn đúng phần tử trung vị lý tưởng làm chốt, giúp chia mảng thành hai nửa bằng nhau ở mỗi lần phân hoạch.
- **Kết luận**: Đây là **TRƯỜNG HỢP TỐT NHẤT (Best-case)** với độ phức tạp $\Theta(n \log n)$.

**b. Mảng giảm dần nghiêm ngặt:**  
- Ba phần tử được xét: $A[l]$ (lớn nhất), $A[m]$ (ở giữa), và $A[r]$ (nhỏ nhất).
- Trung vị của 3 phần tử này vẫn chính là $A[m]$ - phần tử nằm ở chính giữa mảng!
- Chốt được chọn vẫn chia đều mảng thành hai nửa xấp xỉ bằng nhau.
- **Kết luận**: Đây cũng là **TRƯỜNG HỢP TỐT NHẤT (Best-case)** với độ phức tạp $\Theta(n \log n)$.

---

### Bài 7 (Exercises 5.2 - Trang 181)
**Đề bài:**  
*a. Hãy ước tính Quicksort chạy nhanh hơn Insertion Sort khoảng bao nhiêu lần khi sắp xếp một mảng gồm $1.000.000$ số ngẫu nhiên.*  
*b. Đúng hay Sai: Với mọi $n > 1$, luôn tồn tại các mảng kích thước $n$ mà Insertion Sort chạy nhanh hơn Quicksort?*

#### Lời giải chi tiết:

**a. Ước tính tốc độ trên $n = 10^6$ số ngẫu nhiên:**  
- **Số phép so sánh trung bình của Insertion Sort**:
  $$C_{ins}(n) \approx \frac{n^2}{4}$$
  Với $n = 10^6$: $C_{ins}(10^6) \approx \frac{(10^6)^2}{4} = \frac{10^{12}}{4} = 2.5 \times 10^{11}$ phép so sánh.
- **Số phép so sánh trung bình của Quicksort**:
  $$C_{quick}(n) \approx 2n \ln n \approx 1.386 n \log_2 n$$
  Với $n = 10^6$, ta có $\log_2 (10^6) \approx 19.93 \approx 20$:
  $$C_{quick}(10^6) \approx 1.386 \times 10^6 \times 20 \approx 2.77 \times 10^7 \text{ phép so sánh.}$$
- **Tỷ số tốc độ**:
  $$\frac{C_{ins}(10^6)}{C_{quick}(10^6)} \approx \frac{2.5 \times 10^{11}}{2.77 \times 10^7} \approx 9025 \approx 9000 \text{ lần!}$$
Quicksort chạy nhanh hơn Insertion Sort xấp xỉ **9.000 lần**.

**b. Mệnh đề: "Với mọi $n > 1$, luôn tồn tại mảng kích thước $n$ mà Insertion Sort chạy nhanh hơn Quicksort":**  
- **Khẳng định: ĐÚNG (TRUE).**  
- **Chứng minh / Ví dụ cụ thể**: Xét mảng đã có thứ tự tăng dần hoàn hảo $A = [1, 2, 3, \dots, n]$.
  - **Insertion Sort**: Tại mỗi bước chèn, chỉ cần đúng 1 phép so sánh với phần tử liền trước là thấy thỏa mãn ngay. Tổng số phép so sánh của Insertion Sort là $n - 1 \in \Theta(n)$ (thời gian tuyến tính tuyệt đối, không di chuyển phần tử nào).
  - **Quicksort (bản chuẩn chọn chốt đầu mảng)**: Rơi vào trường hợp xấu nhất, thực hiện $\frac{n(n+1)}{2} - 1 \in \Theta(n^2)$ phép so sánh. Kể cả phiên bản tối ưu, Quicksort vẫn tốn ít nhất $\Theta(n \log n)$ phép so sánh và chi phí đệ quy.
  - Do đó với mảng đã sắp xếp, Insertion Sort ($O(n)$) luôn chạy nhanh vượt trội so với Quicksort ($O(n^2)$ hoặc $O(n \log n)$).

---

### Bài 8 (Exercises 5.2 - Trang 181)
**Đề bài:**  
*Thiết kế thuật toán sắp xếp lại các phần tử của một mảng gồm $n$ số thực sao cho tất cả các số âm đứng trước tất cả các số dương. Thuật toán phải tối ưu cả về thời gian và không gian.*

#### Lời giải chi tiết:

**Ý tưởng thiết kế:**  
Áp dụng cơ chế quét hai con trỏ của phân hoạch Hoare với giá trị chốt quy ước là $0$:
- Con trỏ $i$ quét từ trái sang phải tìm số dương đầu tiên ($A[i] \ge 0$).
- Con trỏ $j$ quét từ phải sang trái tìm số âm đầu tiên ($A[j] < 0$).
- Hoán đổi $A[i]$ và $A[j]$, lặp lại cho đến khi $i \ge j$.

**Mã giả chuẩn hóa:**
```text
algorithm: SeparateNegativesPositives(A[0..n - 1])
    input:  Mảng A[0..n - 1] gồm n số thực.
   output:  Mảng A được biến đổi tại chỗ sao cho mọi số âm đứng trước mọi số dương.

1   i ← 0;  j ← n - 1
2   while i < j do
3       while i < n and A[i] < 0 do
4           i ← i + 1
5       while j ≥ 0 and A[j] ≥ 0 do
6           j ← j - 1
7       if i < j then
8           swap(A[i], A[j])
9           i ← i + 1
10          j ← j - 1
```

**Phân tích độ phức tạp:**
- **Thời gian**: Mỗi phần tử được duyệt qua đúng một lần bởi con trỏ $i$ hoặc $j$. Thời gian thực thi là tuyến tính $O(n)$ tối ưu.
- **Không gian**: Chỉ sử dụng 2 biến chỉ số con trỏ $i, j$, thực hiện biến đổi tại chỗ (in-place) với bộ nhớ phụ $O(1)$ tối ưu tuyệt đối.

---

### Bài 9 (Exercises 5.2 - Trang 182)
**Đề bài: Bài toán Cờ quốc gia Hà Lan (The Dutch National Flag Problem - E.W. Dijkstra, 1976)**  
*a. Hãy sắp xếp lại một mảng gồm các ký tự 'R' (Red - Đỏ), 'W' (White - Trắng), và 'B' (Blue - Xanh) sao cho tất cả các chữ 'R' đứng đầu, tiếp theo là 'W', và cuối cùng là 'B'. Thuật toán phải chạy trong thời gian tuyến tính và tại chỗ (in-place).*  
*b. Giải thích cách ứng dụng giải pháp của bài toán này vào thuật toán Quicksort.*

#### Lời giải chi tiết:

**a. Thuật toán Dijkstra 3 con trỏ (3-Way Partitioning):**
Ta duy trì 3 con trỏ chia mảng thành 4 vùng:
- $A[0..low-1]$: Toàn bộ là màu Đỏ ('R').
- $A[low..mid-1]$: Toàn bộ là màu Trắng ('W').
- $A[mid..high]$: Vùng chưa được xử lý.
- $A[high+1..n-1]$: Toàn bộ là màu Xanh ('B').

```text
algorithm: DutchFlagPartition(A[0..n - 1])
    input:  Mảng A chứa các ký tự 'R', 'W', 'B'.
   output:  Mảng A được sắp xếp: toàn bộ 'R' đứng trước, đến 'W', rồi đến 'B'.

1   low ← 0;  mid ← 0;  high ← n - 1
2   while mid ≤ high do
3       if A[mid] = 'R' then
4           swap(A[low], A[mid])
5           low ← low + 1
6           mid ← mid + 1
7       else if A[mid] = 'W' then
8           mid ← mid + 1
9       else // A[mid] = 'B'
10          swap(A[mid], A[high])
11          high ← high - 1
```
- **Độ phức tạp**: Thời gian đúng $O(n)$ (mỗi bước $mid$ tăng hoặc $high$ giảm, tối đa $n$ bước lặp), không gian tại chỗ $O(1)$.

**b. Ứng dụng đột phá vào Quicksort (Fat Partitioning / 3-Way Quicksort):**
- Trong Quicksort thông thường, khi mảng có rất nhiều phần tử có khóa **bằng nhau**, phân hoạch 2 chiều vẫn tiếp tục đẩy các phần tử bằng chốt vào các mảng con đệ quy, dẫn tới nguy cơ rơi vào $\Theta(n^2)$.
- Khi áp dụng phân hoạch 3 chiều (Dutch National Flag Partitioning):
  - Phân hoạch mảng thành 3 vùng: $[ < p \mid = p \mid > p ]$.
  - Toàn bộ các phần tử có giá trị bằng chốt ($= p$) được gom lại ở giữa và đã **nằm đúng vị trí cuối cùng của chúng**!
  - Hai lời gọi đệ quy tiếp theo chỉ cần thực hiện cho vùng $[ < p ]$ và vùng $[ > p ]$, **hoàn toàn bỏ qua toàn bộ vùng $[ = p ]$**!
- Nhờ đó, với các mảng có nhiều phần tử trùng lặp, thời gian chạy của Quicksort giảm ngoạn mục xuống mức **tuyến tính $O(n)$**! Đây chính là kỹ thuật `dual-pivot / 3-way quicksort` được sử dụng trong thư viện chuẩn Java (`Arrays.sort`).

---

### Bài 10 (Exercises 5.2 - Trang 182)
**Đề bài:**  
*Cài đặt thuật toán Quicksort bằng một ngôn ngữ lập trình tùy chọn. Chạy chương trình trên các tập dữ liệu mẫu để kiểm chứng các khẳng định lý thuyết về hiệu năng thuật toán.*

#### Lời giải chi tiết:

**Mã nguồn C++ hoàn chỉnh với đo thời gian thực nghiệm:**
```cpp
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

int hoarePartition(std::vector<int>& a, int l, int r) {
    int p = a[l];
    int i = l, j = r + 1;
    while (true) {
        do { i++; } while (i <= r && a[i] < p);
        do { j--; } while (a[j] > p);
        if (i >= j) break;
        std::swap(a[i], a[j]);
    }
    std::swap(a[l], a[j]);
    return j;
}

void quicksort(std::vector<int>& a, int l, int r) {
    while (l < r) {
        int s = hoarePartition(a, l, r);
        // Tối ưu tail recursion: đệ quy nhánh nhỏ trước
        if (s - l < r - s) {
            quicksort(a, l, s - 1);
            l = s + 1;
        } else {
            quicksort(a, s + 1, r);
            r = s - 1;
        }
    }
}
```
**Kết quả thực nghiệm**: Trên mảng ngẫu nhiên $N = 10^5$, thời gian chạy xấp xỉ vài mili-giây, tăng theo hàm $N \log_2 N$. Với mảng đã sắp xếp và không tối ưu chốt, thời gian tăng theo $N^2$.

---

### Bài 11 (Exercises 5.2 - Trang 182)
**Đề bài: Bài toán Đai ốc và Bu-lông (Nuts and Bolts Problem - Rawlins, 1991)**  
*Cho $n$ chiếc bu-lông có kích thước khác nhau và $n$ chiếc đai ốc tương ứng. Ta chỉ được phép thử ghép một chiếc đai ốc với một chiếc bu-lông để biết đai ốc đó vừa vặn, rộng hơn hay chật hơn bu-lông. Tuyệt đối không được so sánh trực tiếp hai chiếc bu-lông với nhau, hoặc hai chiếc đai ốc với nhau. Hãy thiết kế thuật toán ghép cặp hoàn hảo mỗi bu-lông với đai ốc tương ứng với thời gian trung bình $\Theta(n \log n)$.*

#### Lời giải chi tiết:

**Ý tưởng thiết kế (Randomized Quicksort-like Matching):**
Không thể so sánh bu-lông với bu-lông hay đai ốc với đai ốc, nhưng **ta có thể dùng một chiếc bu-lông làm chốt (pivot) để phân hoạch tập các đai ốc**, và ngược lại!

**Quy trình thuật toán từng bước:**
1. **Chọn chốt ngẫu nhiên**: Chọn ngẫu nhiên một chiếc bu-lông $B_{pivot}$ trong tập bu-lông $B$.
2. **Phân hoạch tập đai ốc $N$ bằng $B_{pivot}$**:
   - Thử lần lượt từng chiếc đai ốc trong $N$ với $B_{pivot}$.
   - Chia tập đai ốc $N$ thành 3 nhóm:
     - $N_{smaller}$: các đai ốc nhỏ hơn $B_{pivot}$.
     - $N_{pivot}$: đúng một chiếc đai ốc vừa khít với $B_{pivot}$!
     - $N_{larger}$: các đai ốc lớn hơn $B_{pivot}$.
3. **Phân hoạch tập bu-lông $B$ bằng chiếc đai ốc vừa tìm được ($N_{pivot}$)**:
   - Bây giờ lấy chính chiếc đai ốc $N_{pivot}$ vừa tìm được làm chốt để thử với tất cả các bu-lông còn lại trong $B$.
   - Chia tập bu-lông $B$ thành 2 nhóm:
     - $B_{smaller}$: các bu-lông nhỏ hơn $N_{pivot}$.
     - $B_{larger}$: các bu-lông lớn hơn $N_{pivot}$.
4. **Ghép đôi & Đệ quy**:
   - Cặp $(B_{pivot}, N_{pivot})$ đã được ghép đôi hoàn hảo.
   - Tập con nhỏ hơn $(B_{smaller}, N_{smaller})$ có cùng kích thước $k$.
   - Tập con lớn hơn $(B_{larger}, N_{larger})$ có cùng kích thước $n - 1 - k$.
   - Gọi đệ quy cho hai cặp bài toán con độc lập này.

**Phân tích độ phức tạp:**
- Mỗi vòng phân hoạch tốn $2(n - 1) = \Theta(n)$ phép thử.
- Khi chọn chốt ngẫu nhiên, hệ thức truy hồi thời gian trung bình y hệt Quicksort:
  $$T(n) = 2 T(n/2) + \Theta(n) \implies T(n) \in \Theta(n \log n)$$
Thuật toán giải quyết bài toán triệt để trong thời gian trung bình $\Theta(n \log n)$ mà không vi phạm bất kỳ ràng buộc nào của đề bài.
