# CHUYÊN ĐỀ 03: DUYỆT CÂY NHỊ PHÂN VÀ CÁC TÍNH CHẤT LIÊN QUAN & LỜI GIẢI CHI TIẾT 100% BÀI TẬP 5.3
## Trích dẫn: Anany Levitin, "Introduction to the Design and Analysis of Algorithms", 3rd Edition, Mục 5.3 (pp. 182–186)

---

## PHẦN 1: LÝ THUYẾT NỀN TẢNG & MÃ GIẢ CHUẨN HÓA

### 1.1. Định nghĩa Đệ quy của Cây Nhị phân và Tư tưởng Chia để trị
Một **cây nhị phân (Binary Tree)** $T$ được định nghĩa đệ quy như sau:
- Hoặc $T$ là một cây rỗng ($\emptyset$).
- Hoặc $T$ bao gồm một nút gốc $r$ cùng với hai cây nhị phân rời nhau được gọi là **cây con trái** ($T_L$) và **cây con phải** ($T_R$).

Bản thân định nghĩa cấu trúc dữ liệu cây nhị phân đã mang bản chất đệ quy phân đôi hoàn hảo, do đó hầu hết các thuật toán xử lý trên cây nhị phân đều là sự thể hiện tự nhiên của chiến lược **Chia để trị**:
1. **Chia**: Tách cây thành hai cây con $T_L$ và $T_R$.
2. **Trị**: Giải quyết bài toán trên $T_L$ và $T_R$ bằng các lời gọi đệ quy độc lập.
3. **Kết hợp**: Tổng hợp kết quả từ hai cây con cùng với dữ liệu tại nút gốc $r$.

---

### 1.2. Thuật toán Tính Chiều cao của Cây Nhị phân (Height of Binary Tree)

**Quy ước trong giáo trình Levitin**:  
- Chiều cao của cây là độ dài của đường đi dài nhất từ gốc tới một nút lá (tính bằng số cạnh).
- Cây rỗng có chiều cao quy ước là $-1$.
- Cây chỉ có đúng 1 nút gốc có chiều cao là $0$.

```text
algorithm: Height(T)
    input:  Cây nhị phân T.
   output:  Chiều cao của T (số cạnh của đường đi dài nhất từ gốc tới lá; trả về -1 nếu cây rỗng).

1   if T = ∅ then
2       return -1
3   else
4       return max(Height(T_left), Height(T_right)) + 1
```

#### Phân tích Hiệu năng Thuật toán `Height(T)`:
Gọi $n$ là tổng số nút trong cây $T$.
1. **Số phép cộng $A(n)$**:  
   Tại dòng 4, mỗi nút khác rỗng thực hiện đúng 1 phép cộng $+ 1$:
   $$A(n) = A(n(T_L)) + A(n(T_R)) + 1 \quad (n > 0), \quad A(0) = 0$$
   Với $n = n(T_L) + n(T_R) + 1$, bằng quy nạp toán học ta có:
   $$A(n) = n$$
2. **Số phép kiểm tra rỗng $C(n)$**:  
   Mỗi lần gọi hàm đều thực hiện kiểm tra `T = ∅`.
   - Một cây có $n$ nút sẽ có đúng $n + 1$ liên kết rỗng (con trỏ `null`).
   - Tổng số lời gọi hàm kiểm tra là số nút thực cộng số nút rỗng:
     $$C(n) = n + (n + 1) = 2n + 1 \in \Theta(n)$$
- **Độ phức tạp thời gian**: $\Theta(n)$. Thuật toán duyệt qua mọi nút trong cây đúng 1 lần.
- **Độ phức tạp không gian (Call Stack)**: Tỷ lệ thuận với chiều cao của cây:
  - Trường hợp xấu nhất (cây suy biến thành danh sách liên kết): $O(n)$.
  - Trường hợp tốt nhất (cây cân bằng hoàn hảo): $O(\log n)$.

---

### 1.3. Ba Thuật toán Duyệt Cây Cổ điển (Classic Traversals)

| Thứ tự duyệt | Tên gọi | Thứ tự xử lý | Ứng dụng tiêu biểu |
| :--- | :--- | :--- | :--- |
| **Preorder** | Tiền thứ tự | **Gốc $\to$ Cây con trái $\to$ Cây con phải** | Sao chép cây, tính biểu thức tiền tố (Prefix / Polish Notation) |
| **Inorder** | Trung thứ tự | **Cây con trái $\to$ Gốc $\to$ Cây con phải** | Xuất khóa theo thứ tự tăng dần trên Cây tìm kiếm nhị phân (BST) |
| **Postorder** | Hậu thứ tự | **Cây con trái $\to$ Cây con phải $\to$ Gốc** | Giải phóng bộ nhớ cây, tính biểu thức hậu tố (Postfix / RPN) |

```text
algorithm: Preorder(T)
1   if T ≠ ∅ then
2       thăm(root(T))
3       Preorder(T_left)
4       Preorder(T_right)

algorithm: Inorder(T)
1   if T ≠ ∅ then
2       Inorder(T_left)
3       thăm(root(T))
4       Inorder(T_right)

algorithm: Postorder(T)
1   if T ≠ ∅ then
2       Postorder(T_left)
3       Postorder(T_right)
4       thăm(root(T))
```

---

### 1.4. Cây Nhị phân Mở rộng (Extended Binary Tree) và Các Tính chất Cốt lõi
- **Cây nhị phân mở rộng**: Cây nhị phân ban đầu được bổ sung các **nút ngoài (external nodes)** dạng hình vuông thay thế cho mọi con trỏ rỗng (`null`). Các nút ban đầu được gọi là **nút trong (internal nodes)** dạng hình tròn.
- **Định lý 1 (Số nút ngoài)**: Nếu cây có $n$ nút trong, thì số nút ngoài luôn luôn là:
  $$x = n + 1$$
- **Định lý 2 (Quan hệ độ dài đường đi)**:
  - Gọi $I$ là **độ dài đường đi trong (Internal Path Length)**: tổng khoảng cách từ gốc tới tất cả các nút trong.
  - Gọi $E$ là **độ dài đường đi ngoài (External Path Length)**: tổng khoảng cách từ gốc tới tất cả các nút ngoài.
  - Khi đó ta luôn có hệ thức bất biến:
    $$E = I + 2n$$

---

## PHẦN 2: LỜI GIẢI CHI TIẾT 100% BÀI TẬP 5.3 (BÀI 1 ĐẾN BÀI 11)

---

### Bài 1 (Exercises 5.3 - Trang 185)
**Đề bài:**  
*Thiết kế một thuật toán chia để trị tính số tầng (number of levels) trong một cây nhị phân. (Cụ thể, thuật toán phải trả về 0 đối với cây rỗng và 1 đối với cây chỉ có đúng một nút). Cho biết lớp hiệu năng thời gian của thuật toán.*

#### Lời giải chi tiết:

**Phân tích:**  
Số tầng của một cây nhị phân liên hệ mật thiết với chiều cao: $\text{Số tầng} = \text{Height} + 1$.
- Cây rỗng: $\text{Số tầng} = 0$.
- Cây 1 nút: $\text{Số tầng} = 1$.
- Với cây tổng quát, số tầng bằng 1 (cho nút gốc) cộng với giá trị lớn nhất giữa số tầng của cây con trái và số tầng của cây con phải.

**Mã giả chuẩn hóa:**
```text
algorithm: NumLevels(T)
    input:  Cây nhị phân T.
   output:  Số tầng của cây T (trả về 0 nếu T rỗng).

1   if T = ∅ then
2       return 0
3   else
4       return max(NumLevels(T_left), NumLevels(T_right)) + 1
```

**Lớp hiệu năng thời gian:**
Thuật toán thăm mọi nút của cây đúng một lần. Số phép toán cơ bản thỏa mãn:
$$T(n) = T(n_L) + T(n_R) + \Theta(1) \implies T(n) \in \Theta(n)$$
Không gian ngăn xếp tiêu tốn $O(h)$ với $h$ là chiều cao của cây.

---

### Bài 2 (Exercises 5.3 - Trang 185)
**Đề bài:**  
*Xét thuật toán đếm số nút lá trong cây nhị phân được đề xuất như sau:*
```text
ALGORITHM LeafCounter(T)
// Computes recursively the number of leaves in a binary tree
// Input: A binary tree T
// Output: The number of leaves in T
if T = ∅ return 0
else return LeafCounter(T_left) + LeafCounter(T_right)
```
*Thuật toán này có đúng không? Nếu đúng hãy chứng minh; nếu sai hãy chỉ ra lỗi và sửa lại cho chính xác.*

#### Lời giải chi tiết:

**1. Khẳng định: Thuật toán trên HOÀN TOÀN SAI!**

**2. Chỉ ra lỗi sai:**  
- Xét một cây chỉ có đúng **một nút lá duy nhất** (nút gốc không có con: $T_L = \emptyset$ và $T_R = \emptyset$).
- Khi gọi `LeafCounter(T)`:
  - Vì $T \ne \emptyset$, thuật toán nhảy vào nhánh `else`.
  - Nhánh `else` trả về: `LeafCounter(T_left) + LeafCounter(T_right)`.
  - Nhưng $T_L = \emptyset \implies \text{LeafCounter}(T_L) = 0$.
  - Và $T_R = \emptyset \implies \text{LeafCounter}(T_R) = 0$.
  - Kết quả trả về là: $0 + 0 = 0$!
- Do đó, với cây gồm đúng 1 lá, thuật toán trả về 0 thay vì 1.
- Tệ hơn nữa, vì thuật toán luôn trả về tổng các lời gọi con trên các nút rỗng, **nó sẽ trả về 0 đối với MỌI cây nhị phân** bất kể cây lớn đến đâu!

**3. Sửa lại cho chính xác:**  
Cần bổ sung trường hợp cơ sở nhận diện đúng một nút lá (nút có cả hai con trái và phải đều là rỗng):
```text
algorithm: CorrectLeafCounter(T)
    input:  Cây nhị phân T.
   output:  Số lượng nút lá thực tế trong cây T.

1   if T = ∅ then
2       return 0
3   if T_left = ∅ and T_right = ∅ then
4       return 1
5   return CorrectLeafCounter(T_left) + CorrectLeafCounter(T_right)
```

---

### Bài 3 (Exercises 5.3 - Trang 185)
**Đề bài:**  
*Có thể tính chiều cao của cây nhị phân với cùng độ phức tạp thời gian tiệm cận $\Theta(n)$ nhưng hoàn toàn KHÔNG sử dụng ngăn xếp (stack) cả một cách tường minh lẫn ngầm định (không dùng đệ quy) hay không?*

#### Lời giải chi tiết:

**Khẳng định: HOÀN TOÀN CÓ THỂ ĐƯỢC.**

**Giải pháp:**  
Thay vì dùng ngăn xếp (duyệt theo chiều sâu - DFS), ta sử dụng **cấu trúc dữ liệu Hàng đợi (Queue)** để duyệt cây theo **chiều rộng / theo từng mức (Breadth-First Search / Level-Order Traversal)**:
- Hàng đợi FIFO hoạt động hoàn toàn độc lập với ngăn xếp LIFO.
- Tại mỗi mức (level), ta đếm số lượng nút hiện tại trong hàng đợi ($levelSize$), sau đó lấy lần lượt từng nút ra và đẩy tất cả các nút con hợp lệ của chúng vào hàng đợi.
- Mỗi lần xử lý xong một mức, ta tăng biến đếm chiều cao thêm 1.

**Mã giả chuẩn hóa dùng Queue (BFS):**
```text
algorithm: HeightUsingQueue(T)
    input:  Cây nhị phân T.
   output:  Chiều cao của cây T (-1 nếu rỗng).

1   if T = ∅ then return -1
2   Khởi tạo hàng đợi Q
3   Q.enqueue(T)
4   height ← -1
5   while not Q.isEmpty() do
6       levelSize ← Q.size()
7       for i ← 1 to levelSize do
8           node ← Q.dequeue()
9           if node.left ≠ ∅ then Q.enqueue(node.left)
10          if node.right ≠ ∅ then Q.enqueue(node.right)
11      height ← height + 1
12  return height
```
- **Độ phức tạp**: Thời gian $\Theta(n)$ vì mỗi nút vào/ra hàng đợi đúng một lần. Bộ nhớ phụ dùng Queue thay vì Stack, thỏa mãn 100% yêu cầu đề bài.

---

### Bài 4 (Exercises 5.3 - Trang 185)
**Đề bài:**  
*Chứng minh đẳng thức (5.2) trong giáo trình: $A(n) = n$ (với $A(n)$ là số phép cộng được thực hiện bởi thuật toán `Height` trên cây có $n$ nút) bằng phương pháp quy nạp toán học.*

#### Lời giải chi tiết:

**Chứng minh bằng quy nạp toán học mạnh theo số nút $n$:**

**1. Cơ sở quy nạp ($n = 0$):**  
Cây có $n = 0$ nút là cây rỗng ($T = \emptyset$). Thuật toán gặp dòng `if T = ∅ return -1`, kết thúc ngay mà không thực hiện phép cộng nào.  
$\implies A(0) = 0$. Công thức $A(n) = n$ đúng với $n = 0$.

**2. Giả thiết quy nạp:**  
Giả sử công thức đúng với mọi cây nhị phân có số nút $k < n$ ($n \ge 1$), tức là số phép cộng trên cây có $k$ nút luôn bằng $A(k) = k$.

**3. Bước quy nạp:**  
Xét cây $T$ bất kỳ có $n$ nút ($n \ge 1$).  
- Cây $T$ gồm một nút gốc $r$, cây con trái $T_L$ có $n_L$ nút, và cây con phải $T_R$ có $n_R$ nút.  
- Do $n_L$ và $n_R$ đều không chứa gốc $r$, ta có hệ thức:
  $$n_L + n_R = n - 1 \implies n_L < n \text{ và } n_R < n$$
- Theo thuật toán `Height(T)`: Khi $T \ne \emptyset$, thuật toán tính `max(Height(T_left), Height(T_right)) + 1`.  
- Số phép cộng thực hiện bằng tổng số phép cộng trên hai cây con cộng thêm đúng **1 phép cộng** với $1$:
  $$A(n) = A(n_L) + A(n_R) + 1$$
- Áp dụng giả thiết quy nạp cho $T_L$ (có $n_L < n$ nút) và $T_R$ (có $n_R < n$ nút):
  $$A(n_L) = n_L \quad \text{và} \quad A(n_R) = n_R$$
- Thay vào phương trình:
  $$A(n) = n_L + n_R + 1 = (n - 1) + 1 = n$$
Vậy công thức đúng với mọi $n \ge 0$. Theo nguyên lý quy nạp toán học, ta có điều phải chứng minh: $A(n) = n$. $\blacksquare$

---

### Bài 5 (Exercises 5.3 - Trang 185)
**Đề bài:**  
*Duyệt cây nhị phân trong hình vẽ (trang 186):*
```text
        a
       / \
      b   c
     / \   \
    d   e   f
```
*a. Theo thứ tự Preorder.*  
*b. Theo thứ tự Inorder.*  
*c. Theo thứ tự Postorder.*

#### Lời giải chi tiết:

- **a. Preorder (Gốc $\to$ Trái $\to$ Phải):**
  1. Thăm gốc: `a`.
  2. Duyệt nhánh trái gốc $a$ (gốc $b$): thăm `b` $\to$ duyệt con trái thăm `d` $\to$ duyệt con phải thăm `e`.
  3. Duyệt nhánh phải gốc $a$ (gốc $c$): thăm `c` $\to$ duyệt con phải thăm `f`.  
  **Kết quả Preorder:** `a, b, d, e, c, f`.

- **b. Inorder (Trái $\to$ Gốc $\to$ Phải):**
  1. Duyệt nhánh trái gốc $a$:
     - Cây con trái gốc $b$: duyệt con trái `d` $\to$ thăm gốc `b` $\to$ duyệt con phải `e` $\implies$ `d, b, e`.
  2. Thăm gốc: `a`.
  3. Duyệt nhánh phải gốc $a$:
     - Cây con phải gốc $c$: con trái rỗng $\to$ thăm gốc `c` $\to$ duyệt con phải `f` $\implies$ `c, f`.  
  **Kết quả Inorder:** `d, b, e, a, c, f`.

- **c. Postorder (Trái $\to$ Phải $\to$ Gốc):**
  1. Duyệt nhánh trái gốc $a$:
     - Duyệt con trái `d` $\to$ duyệt con phải `e` $\to$ thăm gốc `b` $\implies$ `d, e, b`.
  2. Duyệt nhánh phải gốc $a$:
     - Con trái rỗng $\to$ duyệt con phải `f` $\to$ thăm gốc `c` $\implies$ `f, c`.
  3. Thăm gốc: `a`.  
  **Kết quả Postorder:** `d, e, b, f, c, a`.

---

### Bài 6 (Exercises 5.3 - Trang 186)
**Đề bài:**  
*Viết mã giả cho một trong các thuật toán duyệt kinh điển (preorder, inorder, hoặc postorder) cho cây nhị phân. Giả sử thuật toán được cài đặt đệ quy, hãy tìm số lượng lời gọi đệ quy được thực hiện.*

#### Lời giải chi tiết:

**Mã giả chuẩn hóa cho Inorder:**
```text
algorithm: InorderTraversal(T)
    input:  Cây nhị phân T có n nút.
   output:  In ra nhãn của các nút theo thứ tự Inorder.

1   if T ≠ ∅ then
2       InorderTraversal(T_left)
3       Print(T.key)
4       InorderTraversal(T_right)
```

**Tính toán chính xác số lời gọi đệ quy $R(n)$:**
- Mỗi nút khác rỗng thực hiện 2 lời gọi đệ quy (một cho con trái, một cho con phải).
- Lời gọi đệ quy ban đầu tính là 1.
- Một cây nhị phân có $n$ nút trong (nút thực) luôn có đúng:
  $$x = n + 1 \text{ liên kết rỗng (con trỏ null)}$$
- Mỗi nút thực sẽ được gọi 1 lần (tổng cộng $n$ lần cho nút thực).
- Mỗi liên kết rỗng sẽ dẫn đến 1 lời gọi đệ quy với tham số $T = \emptyset$ (dừng tại dòng 1, tổng cộng $n + 1$ lần cho nút rỗng).
- Do đó, tổng số lần gọi hàm đệ quy là:
  $$R(n) = n + (n + 1) = 2n + 1$$
- **Kết luận**: Với cây có $n$ nút, thuật toán thực hiện chính xác **$2n + 1$ lời gọi đệ quy**.

---

### Bài 7 (Exercises 5.3 - Trang 186)
**Đề bài:**  
*Thuật toán nào trong ba thuật toán duyệt kinh điển sẽ cho ra danh sách các khóa đã được sắp xếp tăng dần khi áp dụng lên Cây tìm kiếm nhị phân (Binary Search Tree - BST)? Hãy chứng minh tính chất này.*

#### Lời giải chi tiết:

**Khẳng định: Thuật toán duyệt TRUNG THỨ TỰ (Inorder Traversal).**

**Chứng minh chặt chẽ bằng quy nạp toán học:**  
1. **Định nghĩa BST**: Trong một cây tìm kiếm nhị phân $T$ với gốc $r$:
   - Mọi khóa $k_L$ trong cây con trái $T_L$ đều thỏa mãn: $k_L < key(r)$.
   - Mọi khóa $k_R$ trong cây con phải $T_R$ đều thỏa mãn: $key(r) < k_R$.
   - Cả $T_L$ và $T_R$ đều là các BST.
2. **Quy nạp theo số nút $n$**:
   - **Cơ sở ($n \le 1$)**: Cây rỗng hoặc cây 1 nút hiển nhiên có thứ tự tăng dần.
   - **Bước quy nạp**: Giả sử Inorder cho thứ tự tăng dần với mọi BST có ít hơn $n$ nút ($n \ge 2$).
   - Xét BST có $n$ nút với gốc $r$.
     - Theo giả thiết quy nạp, `Inorder(T_L)` duyệt qua toàn bộ các khóa của $T_L$ theo thứ tự tăng dần hoàn chỉnh.
     - Tiếp theo, thuật toán thăm khóa $key(r)$. Vì mọi khóa trong $T_L$ đều $< key(r)$, nên $key(r)$ đứng ngay sau phần tử lớn nhất của $T_L$ vẫn giữ nguyên tính tăng dần.
     - Cuối cùng, `Inorder(T_R)` duyệt qua toàn bộ các khóa của $T_R$ theo thứ tự tăng dần. Vì mọi khóa trong $T_R$ đều $> key(r)$, toàn bộ dãy của $T_R$ đứng sau $key(r)$ tiếp tục duy trì tính tăng dần hoàn hảo.
3. Vậy dãy khóa thu được từ `Inorder(T)` trên BST luôn có thứ tự tăng dần nghiêm ngặt. $\blacksquare$

---

### Bài 8 (Exercises 5.3 - Trang 186)
**Đề bài:**  
*a. Vẽ một cây nhị phân gồm 10 nút được đánh nhãn $0, 1, \dots, 9$ sao cho kết quả duyệt Inorder và Postorder lần lượt là:*  
*Inorder: `9, 3, 1, 0, 4, 2, 7, 6, 8, 5`*  
*Postorder: `9, 1, 4, 0, 3, 6, 7, 5, 8, 2`*  
*b. Đưa ra ví dụ về hai hoán vị của cùng $n$ nhãn $0, 1, \dots, n-1$ không thể là danh sách duyệt Inorder và Postorder của cùng một cây nhị phân.*  
*c. Thiết kế thuật toán chia để trị dựng lại cây nhị phân từ hai danh sách Inorder và Postorder, đồng thời nhận diện trường hợp dữ liệu đầu vào không hợp lệ (vô nghiệm).*

#### Lời giải chi tiết:

**a. Dựng lại cây nhị phân:**
1. **Tìm gốc tổng thể**: Phần tử cuối cùng của Postorder là `2` $\implies$ Gốc của cây là **`2`**.
2. **Phân chia theo Inorder**:
   - Vị trí của `2` trong Inorder chia danh sách thành 2 nửa:
     - Nửa trái Inorder: `9, 3, 1, 0, 4` (5 phần tử).
     - Nửa phải Inorder: `7, 6, 8, 5` (4 phần tử).
3. **Phân chia Postorder tương ứng**:
   - 5 phần tử đầu Postorder: `9, 1, 4, 0, 3` $\implies$ thuộc nhánh trái. Phần tử cuối là `3` $\implies$ **Gốc con trái là `3`**.
   - 4 phần tử tiếp Postorder: `6, 7, 5, 8` $\implies$ thuộc nhánh phải. Phần tử cuối là `8` $\implies$ **Gốc con phải là `8`**.
4. **Phân rã tiếp nhánh trái (gốc 3)**:
   - Inorder: `9, 3, 1, 0, 4` $\implies$ Bên trái `3` là `9` (lá); Bên phải `3` là `1, 0, 4`.
   - Postorder của `1, 0, 4` là `1, 4, 0` $\implies$ **Gốc là `0`**, con trái là `1`, con phải là `4`.
5. **Phân rã tiếp nhánh phải (gốc 8)**:
   - Inorder: `7, 6, 8, 5` $\implies$ Bên trái `8` là `7, 6`; Bên phải `8` là `5` (lá).
   - Postorder của `7, 6` là `6, 7` $\implies$ **Gốc là `7`**, con trái rỗng, **con phải là `6`**.

**Cấu trúc Cây Nhị phân hoàn chỉnh:**
```text
                  2
               /     \
             3         8
           /   \      /  \
          9     0    7    5
               / \    \
              1   4    6
```

**b. Ví dụ phản chứng hai hoán vị không hợp lệ:**  
Xét $n = 3$ với các nhãn $0, 1, 2$:
- Giả sử Inorder: `0, 1, 2`.
- Giả sử Postorder: `2, 1, 0`.
- Phân tích:
  - Postorder kết thúc bằng `0` $\implies$ Gốc cây phải là `0`.
  - Trong Inorder `0, 1, 2`, nhãn `0` nằm ở đầu mảng, nghĩa là toàn bộ các nhãn `1, 2` phải nằm ở cây con bên phải của `0`, nhánh con bên trái phải rỗng.
  - Nhưng trong Postorder `2, 1, 0`, trước gốc `0` phải là toàn bộ các nút của cây con phải. Cây con phải có hai nút $1, 2$ với Inorder là `1, 2` và Postorder là `2, 1`.
  - Từ Postorder `2, 1`, gốc cây con phải là `1`.
  - Nhưng trong Inorder `1, 2`, nhãn `1` đứng trước `2`, nghĩa là `2` phải là con phải của `1`.
  - Khi đó Postorder của cây phải là `2, 1, 0`. Trông có vẻ hợp lệ!
- Hãy xét ví dụ thực sự mâu thuẫn:
  - Cho Inorder: `0, 1, 2` và Postorder: `1, 0, 2`.
  - Gốc là `2`. Inorder là `0, 1, 2` $\implies$ toàn bộ $0, 1$ thuộc cây con trái.
  - Nhánh trái có Inorder `0, 1` và Postorder `1, 0`.
  - Gốc nhánh trái là `0`. Trong Inorder, `0` đứng trước `1` $\implies$ `1` là con phải của `0`.
- **Ví dụ vi phạm tập hợp phần tử**: Inorder: `0, 1, 2`, Postorder: `0, 3, 2` (khác tập nhãn).
- **Ví dụ mâu thuẫn cấu trúc**: Inorder: `1, 2, 3`, Postorder: `3, 1, 2`.
  - Gốc là `2`. Inorder chia thành trái $\{1\}$ và phải $\{3\}$.
  - Trong Postorder, thứ tự phải là (toàn bộ con trái) rồi (toàn bộ con phải), tức là $\{1\}$ phải đứng trước $\{3\}$.
  - Nhưng ở đây Postorder lại là `3, 1, 2` (nút `3` thuộc cây con phải lại xuất hiện trước nút `1` thuộc cây con trái) $\implies$ **Vô nghiệm, không thể tồn tại cây như vậy!**

**c. Mã giả chia để trị phục hồi cây và bắt lỗi:**
```text
algorithm: BuildTree(inorder[inL..inR], postorder[postL..postR])
    input:  Đoạn Inorder và đoạn Postorder tương ứng.
   output:  Nút gốc của cây nhị phân được dựng lại; báo lỗi nếu dữ liệu mâu thuẫn.

1   if inL > inR then return null
2   rootVal ← postorder[postR]
3   Tạo nút root mới với khóa rootVal
4
5   // Tìm rootVal trong Inorder
6   idx ← -1
7   for i ← inL to inR do
8       if inorder[i] = rootVal then
9           idx ← i; break
10  if idx = -1 then BÁO_LỖI("Dữ liệu không hợp lệ: Không tìm thấy gốc trong Inorder!")
11
12  leftSize ← idx - inL
13  root.left ← BuildTree(inorder[inL..idx - 1], postorder[postL..postL + leftSize - 1])
14  root.right ← BuildTree(inorder[idx + 1..inR], postorder[postL + leftSize..postR - 1])
15  return root
```

---

### Bài 9 (Exercises 5.3 - Trang 186)
**Đề bài:**  
*Trong một cây nhị phân mở rộng có $n$ nút trong:*  
*- Độ dài đường đi trong $I$ là tổng khoảng cách từ gốc tới tất cả các nút trong.*  
*- Độ dài đường đi ngoài $E$ là tổng khoảng cách từ gốc tới tất cả các nút ngoài.*  
*Chứng minh rằng: $E = I + 2n$.*

#### Lời giải chi tiết:

**Chứng minh bằng quy nạp toán học mạnh theo số nút trong $n$:**

**1. Cơ sở quy nạp ($n = 0$):**  
- Khi $n = 0$: Cây rỗng, cây mở rộng chỉ có duy nhất $1$ nút ngoài chính là nút gốc.
- Khoảng cách từ gốc tới nút ngoài này bằng $0 \implies E = 0$.
- Không có nút trong nào $\implies I = 0$.
- Ta có: $E = 0 = 0 + 2(0) = I + 2n$. Đẳng thức đúng với $n = 0$.

**2. Giả thiết quy nạp:**  
Giả sử đẳng thức $E = I + 2k$ đúng với mọi cây nhị phân mở rộng có số nút trong $k < n$ ($n \ge 1$).

**3. Bước quy nạp:**  
Xét cây $T$ bất kỳ có $n$ nút trong ($n \ge 1$).  
- Cây $T$ gồm gốc $r$, cây con trái $T_L$ có $n_L$ nút trong, và cây con phải $T_R$ có $n_R$ nút trong ($n_L + n_R = n - 1$).
- Gọi $I_L, E_L$ và $I_R, E_R$ lần lượt là độ dài đường đi trong và ngoài của $T_L$ và $T_R$ khi xét cục bộ đối với gốc của riêng chúng.
- Theo giả thiết quy nạp:
  $$E_L = I_L + 2n_L \quad \text{và} \quad E_R = I_R + 2n_R$$
- Khi ghép $T_L$ và $T_R$ làm con của gốc $r$:
  - Mỗi nút trong của $T_L$ cách gốc $r$ thêm đúng $1$ đơn vị $\implies I$ tăng thêm $n_L$.
  - Mỗi nút trong của $T_R$ cách gốc $r$ thêm đúng $1$ đơn vị $\implies I$ tăng thêm $n_R$.
  - Gốc $r$ có khoảng cách tới chính nó bằng $0$.
  - Do đó:
    $$I = I_L + n_L + I_R + n_R = I_L + I_R + (n - 1) \quad (1)$$
  - Tương tự với các nút ngoài: $T_L$ có $n_L + 1$ nút ngoài, $T_R$ có $n_R + 1$ nút ngoài. Khoảng cách từ gốc $r$ tới mỗi nút ngoài tăng thêm 1:
    $$E = E_L + (n_L + 1) + E_R + (n_R + 1) = E_L + E_R + (n_L + n_R + 2) = E_L + E_R + (n + 1) \quad (2)$$
- Thay giả thiết quy nạp $E_L = I_L + 2n_L$ và $E_R = I_R + 2n_R$ vào $(2)$:
  $$\begin{aligned}
  E &= (I_L + 2n_L) + (I_R + 2n_R) + n + 1 \\
    &= (I_L + I_R) + 2(n_L + n_R) + n + 1 \\
    &= (I_L + I_R) + 2(n - 1) + n + 1 \\
    &= (I_L + I_R) + 3n - 1
  \end{aligned}$$
- Từ $(1)$, ta có $I_L + I_R = I - (n - 1) = I - n + 1$. Thay vào biểu thức của $E$:
  $$E = (I - n + 1) + 3n - 1 = I + 2n$$
Đẳng thức được chứng minh hoàn tất cho mọi $n \ge 0$. $\blacksquare$

---

### Bài 10 (Exercises 5.3 - Trang 186)
**Đề bài:**  
*Viết chương trình tính độ dài đường đi trong $I$ của cây nhị phân mở rộng. Sử dụng chương trình để khảo sát thực nghiệm số phép so sánh khóa trung bình khi tìm kiếm trên Cây tìm kiếm nhị phân (BST) được tạo ngẫu nhiên.*

#### Lời giải chi tiết:

**Cơ sở lý thuyết:**  
Số phép so sánh trung bình để tìm kiếm thành công một khóa trong BST có $n$ nút liên hệ trực tiếp với $I$:
$$\bar{C}_{success} = \frac{I}{n} + 1 \approx 2 \ln n \approx 1.386 \log_2 n$$

**Chương trình C++ hoàn chỉnh:**
```cpp
#include <iostream>
#include <vector>
#include <random>
#include <numeric>

struct Node {
    int key;
    Node *left = nullptr, *right = nullptr;
    Node(int k) : key(k) {}
};

Node* insertBST(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->key) root->left = insertBST(root->left, key);
    else root->right = insertBST(root->right, key);
    return root;
}

int computeInternalPathLength(Node* root, int depth = 0) {
    if (!root) return 0;
    return depth + computeInternalPathLength(root->left, depth + 1)
                 + computeInternalPathLength(root->right, depth + 1);
}

int main() {
    int n = 1000;
    std::vector<int> vals(n);
    std::iota(vals.begin(), vals.end(), 1);
    std::mt19937 g(42);
    std::shuffle(vals.begin(), vals.end(), g);

    Node* root = nullptr;
    for (int v : vals) root = insertBST(root, v);

    int I = computeInternalPathLength(root);
    double avgComp = (double)I / n + 1.0;
    std::cout << "So nut n = " << n << std::endl;
    std::cout << "Do dai duong di trong I = " << I << std::endl;
    std::cout << "So phep so sanh trung binh: " << avgComp << std::endl;
    std::cout << "Ly thuyet (2 * ln(n)): " << 2.0 * std::log(n) << std::endl;
    return 0;
}
```

---

### Bài 11 (Exercises 5.3 - Trang 186)
**Đề bài: Câu đố Bẻ thanh Sô-cô-la (Chocolate Bar Puzzle)**  
*Cho một thanh sô-cô-la hình chữ nhật kích thước $n \times m$, bạn cần bẻ rời nó thành $nm$ miếng nhỏ kích thước $1 \times 1$. Bạn chỉ được phép bẻ một thanh theo một đường thẳng duy nhất và mỗi lần chỉ được bẻ một thanh (không được xếp chồng các thanh để bẻ cùng lúc). Hãy thiết kế thuật toán giải quyết bài toán với số lần bẻ tối thiểu. Số lần bẻ tối thiểu này là bao nhiêu? Hãy chứng minh câu trả lời bằng cách sử dụng các tính chất của cây nhị phân.*

#### Lời giải chi tiết:

**1. Khẳng định số lần bẻ tối thiểu:**  
Số lần bẻ tối thiểu **LUÔN LUÔN LÀ $nm - 1$**, bất kể bạn lựa chọn thứ tự hay chiến lược bẻ như thế nào!

**2. Chứng minh chặt chẽ bằng Cây Nhị phân:**  
- Hãy mô hình hóa toàn bộ quá trình bẻ thanh sô-cô-la bằng một **cây nhị phân**:
  - **Gốc của cây**: Đại diện cho thanh sô-cô-la nguyên bản ban đầu kích thước $n \times m$.
  - **Mỗi phép bẻ**: Chia một thanh hiện có thành hai thanh nhỏ hơn $\implies$ tương ứng với một **nút trong (internal node)** có đúng hai nhánh con.
  - **Mỗi miếng sô-cô-la $1 \times 1$ cuối cùng**: Là một mảnh không thể bẻ thêm được nữa $\implies$ tương ứng với một **nút lá (external node / leaf)** của cây.
- Vì mục tiêu cuối cùng là thu được $nm$ miếng kích thước $1 \times 1$, cây nhị phân kết thúc bắt buộc phải có đúng:
  $$L = nm \text{ nút lá}$$
- Cây nhị phân này là một **cây nhị phân nghiêm ngặt (strict / proper binary tree)**, nghĩa là mỗi nút trong đều có đúng 2 nút con (mỗi nhát bẻ luôn sinh ra đúng 2 mảnh).
- Theo định lý cơ bản về cây nhị phân nghiêm ngặt: Trong mọi cây nhị phân nghiêm ngặt có $L$ nút lá, số nút trong $I$ luôn thỏa mãn:
  $$I = L - 1$$
- Vì mỗi nhát bẻ tương ứng với đúng một nút trong, nên tổng số nhát bẻ thực hiện bắt buộc phải bằng:
  $$\text{Số lần bẻ} = I = L - 1 = nm - 1$$

**3. Kết luận bất biến:**  
Vì công thức $nm - 1$ là một bất biến toán học phụ thuộc duy nhất vào số lá cuối cùng, **mọi chiến lược bẻ hợp lệ đều cần chính xác $nm - 1$ lần bẻ**. Không có bất kỳ thuật toán nào có thể làm với ít hơn hoặc nhiều hơn $nm - 1$ lần bẻ. $\blacksquare$
