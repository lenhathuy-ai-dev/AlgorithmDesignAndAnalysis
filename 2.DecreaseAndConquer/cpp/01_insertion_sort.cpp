#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>

using namespace std;

// 1. Sắp xếp chèn chuẩn (Standard Insertion Sort) - Levitin Section 4.1
void insertionSort(vector<int>& A) {
    int n = A.size();
    for (int i = 1; i < n; ++i) {
        int v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            --j;
        }
        A[j + 1] = v;
    }
}

// 2. Sắp xếp chèn dùng lính canh (Sentinel Insertion Sort) - Exercise 4.1.8
// Đưa phần tử nhỏ nhất về vị trí đầu A[0], sau đó vòng lặp trong không cần kiểm tra j >= 0
void sentinelInsertionSort(vector<int>& A) {
    int n = A.size();
    if (n <= 1) return;
    
    // Tìm phần tử nhỏ nhất và đưa về A[0] làm lính canh
    int min_idx = 0;
    for (int i = 1; i < n; ++i) {
        if (A[i] < A[min_idx]) min_idx = i;
    }
    swap(A[0], A[min_idx]);

    // Chạy sắp xếp chèn không cần kiểm tra j >= 0
    for (int i = 2; i < n; ++i) {
        int v = A[i];
        int j = i - 1;
        while (A[j] > v) {
            A[j + 1] = A[j];
            --j;
        }
        A[j + 1] = v;
    }
}

// 3. Đếm số lượng nghịch thế (Inversion Count) - Exercise 4.1.11
long long countInversions(const vector<int>& A) {
    long long inv = 0;
    int n = A.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (A[i] > A[j]) ++inv;
        }
    }
    return inv;
}

int main() {
    cout << "=== THUẬT TOÁN SẮP XẾP CHÈN (INSERTION SORT - LEVITIN CHƯƠNG 4.1) ===" << endl;
    
    // Minh họa với dãy ký tự trong Bài tập 4.1.7: E, X, A, M, P, L, E
    vector<int> charArr = {'E', 'X', 'A', 'M', 'P', 'L', 'E'};
    cout << "\n1. Lần vết bài tập 4.1.7: ";
    for (char c : charArr) cout << c << " ";
    cout << "\nSố nghịch thế ban đầu: " << countInversions(charArr) << endl;

    insertionSort(charArr);
    cout << "Kết quả sau khi sắp xếp: ";
    for (char c : charArr) cout << c << " ";
    cout << endl;

    // Kiểm thử hiệu năng Sentinel Insertion Sort
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90, 88, 76, 50, 42};
    cout << "\n2. Kiểm thử Sentinel Insertion Sort:";
    cout << "\nMảng gốc: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    sentinelInsertionSort(arr);
    cout << "Mảng đã sắp xếp: ";
    for (int x : arr) cout << x << " ";
    cout << "\n====================================================================\n";

    return 0;
}
