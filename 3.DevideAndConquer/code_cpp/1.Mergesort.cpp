#include <iostream>
#include <vector>
#include <algorithm>

// Thuật toán Trộn (Merge) chuẩn hóa theo giáo trình Anany Levitin (Section 5.1)
long long merge(std::vector<int>& A, int l, int m, int r) {
    int p = m - l + 1;
    int q = r - m;
    
    std::vector<int> B(p);
    std::vector<int> C(q);
    
    for (int i = 0; i < p; ++i) B[i] = A[l + i];
    for (int j = 0; j < q; ++j) C[j] = A[m + 1 + j];
    
    int i = 0, j = 0, k = l;
    long long comparisons = 0;
    
    while (i < p && j < q) {
        comparisons++;
        if (B[i] <= C[j]) { // Điều kiện B[i] <= C[j] bảo đảm tính ổn định (Stable)
            A[k++] = B[i++];
        } else {
            A[k++] = C[j++];
        }
    }
    
    while (i < p) A[k++] = B[i++];
    while (j < q) A[k++] = C[j++];
    
    return comparisons;
}

// Thuật toán Sắp xếp trộn (Mergesort) đệ quy Top-down
long long mergesort(std::vector<int>& A, int l, int r) {
    long long comps = 0;
    if (l < r) {
        int m = l + (r - l) / 2;
        comps += mergesort(A, l, m);
        comps += mergesort(A, m + 1, r);
        comps += merge(A, l, m, r);
    }
    return comps;
}

// Thuật toán Đếm cặp nghịch thế O(n log n) (Bài tập 5.1 - Bài 9)
long long mergeAndCount(std::vector<int>& A, int l, int m, int r) {
    std::vector<int> left(A.begin() + l, A.begin() + m + 1);
    std::vector<int> right(A.begin() + m + 1, A.begin() + r + 1);
    
    int i = 0, j = 0, k = l;
    long long invCount = 0;
    
    while (i < (int)left.size() && j < (int)right.size()) {
        if (left[i] <= right[j]) {
            A[k++] = left[i++];
        } else {
            A[k++] = right[j++];
            invCount += (left.size() - i); // Toàn bộ phần tử còn lại của left đều > right[j]
        }
    }
    while (i < (int)left.size()) A[k++] = left[i++];
    while (j < (int)right.size()) A[k++] = right[j++];
    return invCount;
}

long long countInversions(std::vector<int>& A, int l, int r) {
    long long inv = 0;
    if (l < r) {
        int m = l + (r - l) / 2;
        inv += countInversions(A, l, m);
        inv += countInversions(A, m + 1, r);
        inv += mergeAndCount(A, l, m, r);
    }
    return inv;
}

int main() {
    std::cout << "=== THUẬT TOÁN SẮP XẾP TRỘN (MERGESORT) - LEVITIN SECTION 5.1 ===" << std::endl;
    std::vector<int> A = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    std::vector<int> A_inv = A;
    
    std::cout << "Mang ban dau: ";
    for (int x : A) std::cout << x << " ";
    std::cout << std::endl;
    
    long long totalComps = mergesort(A, 0, A.size() - 1);
    
    std::cout << "Mang sau Mergesort: ";
    for (int x : A) std::cout << x << " ";
    std::cout << std::endl;
    std::cout << "Tong so phep so sanh khoa: " << totalComps << std::endl;
    
    long long inversions = countInversions(A_inv, 0, A_inv.size() - 1);
    std::cout << "So cap nghich the (Inversions) cua mang goc: " << inversions << std::endl;
    
    return 0;
}
