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
