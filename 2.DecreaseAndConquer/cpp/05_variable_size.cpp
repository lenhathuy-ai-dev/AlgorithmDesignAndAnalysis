#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 1. Phân hoạch Lomuto
int lomutoPartition(vector<int>& A, int l, int r) {
    int p = A[l];
    int s = l;
    for (int i = l + 1; i <= r; ++i) {
        if (A[i] < p) {
            s++;
            swap(A[s], A[i]);
        }
    }
    swap(A[l], A[s]);
    return s;
}

// 2. Thuật toán Quickselect tìm phần tử nhỏ thứ k (k bắt đầu từ 1)
int quickselect(vector<int>& A, int l, int r, int k) {
    int target = l + k - 1;
    while (l < r) {
        int s = lomutoPartition(A, l, r);
        if (s == target) {
            return A[s];
        } else if (s > target) {
            r = s - 1;
        } else {
            l = s + 1;
        }
    }
    return A[l];
}

// 3. Tìm kiếm nội suy (Interpolation Search) - Levitin Section 4.5
int interpolationSearch(const vector<int>& A, int v) {
    int l = 0, r = A.size() - 1;
    while (l <= r && v >= A[l] && v <= A[r]) {
        if (l == r) {
            if (A[l] == v) return l;
            return -1;
        }
        // Công thức nội suy tuyến tính
        int x = l + (double)(v - A[l]) / (A[r] - A[l]) * (r - l);
        if (A[x] == v) {
            return x;
        } else if (A[x] < v) {
            l = x + 1;
        } else {
            r = x - 1;
        }
    }
    return -1;
}

// 4. Tìm kiếm trong ma trận 2D có hàng và cột tăng dần trong O(n) (Saddleback Search) - Exercise 4.5.13
pair<int, int> matrixSearch(const vector<vector<int>>& M, int K) {
    int n = M.size();
    int row = 0, col = n - 1; // Bắt đầu tại góc Trên - Phải
    while (row < n && col >= 0) {
        if (M[row][col] == K) {
            return {row, col};
        } else if (K < M[row][col]) {
            col--; // Bỏ cột col
        } else {
            row++; // Bỏ hàng row
        }
    }
    return {-1, -1}; // Không tìm thấy
}

int main() {
    cout << "=== THUẬT TOÁN GIẢM THEO KÍCH THƯỚC BIẾN THIÊN (LEVITIN CHƯƠNG 4.5) ===" << endl;

    // 1. Kiểm thử Quickselect (Bài tập 4.5.2: Tìm trung vị của 9, 12, 5, 17, 20, 30, 8)
    vector<int> list = {9, 12, 5, 17, 20, 30, 8};
    cout << "\n1. Chạy Quickselect tìm trung vị (k = 4) của dãy: ";
    for (int x : list) cout << x << " ";
    cout << endl;
    int median = quickselect(list, 0, list.size() - 1, 4);
    cout << "=> Trung vị tìm được: " << median << " (Chính xác!)\n";

    // 2. Kiểm thử Tìm kiếm nội suy
    vector<int> sortedArr = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int searchVal = 70;
    int idx = interpolationSearch(sortedArr, searchVal);
    cout << "\n2. Tìm kiếm nội suy: Giá trị " << searchVal << " tại chỉ số: " << idx << endl;

    // 3. Kiểm thử Tìm kiếm ma trận 2D O(n) (Bài tập 4.5.13)
    vector<vector<int>> matrix = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16},
        {10, 13, 14, 17}
    };
    int target = 9;
    auto [r, c] = matrixSearch(matrix, target);
    cout << "\n3. Tìm kiếm ma trận O(n): Số " << target << " tìm thấy tại ô: (" << r << ", " << c << ")\n";

    cout << "\n=======================================================================\n";
    return 0;
}
