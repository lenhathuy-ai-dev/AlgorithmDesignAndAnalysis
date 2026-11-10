#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 1. Tìm kiếm nhị phân phiên bản 2 nhánh (Two-Way Comparison) - Exercise 4.4.6
int binarySearchTwoWay(const vector<int>& A, int K) {
    int l = 0, r = A.size() - 1;
    while (l < r) {
        int m = l + (r - l) / 2;
        if (K <= A[m]) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    if (l < (int)A.size() && A[l] == K) return l;
    return -1;
}

// 2. Phép nhân nông dân Nga (Russian Peasant Multiplication) - Levitin Section 4.4 & Ex 4.4.11-12
long long russianPeasant(long long n, long long m) {
    long long res = 0;
    cout << "Quá trình nhân " << n << " x " << m << ":" << endl;
    while (n > 0) {
        cout << "  n = " << n << ", m = " << m;
        if (n % 2 != 0) {
            res += m;
            cout << " (n lẻ -> cộng " << m << ", tích lũy = " << res << ")";
        }
        cout << endl;
        n /= 2;
        m *= 2;
    }
    return res;
}

// 3. Bài toán Josephus - Tính nghiệm bằng 3 phương pháp (Truy hồi, Đóng, Dịch bit)
// Cách 1: Truy hồi
int josephusRec(int n) {
    if (n == 1) return 1;
    if (n % 2 == 0) return 2 * josephusRec(n / 2) - 1;
    return 2 * josephusRec(n / 2) + 1;
}

// Cách 2: Công thức đóng J(2^m + l) = 2l + 1
int josephusClosed(int n) {
    int powerOf2 = 1;
    while (powerOf2 * 2 <= n) {
        powerOf2 *= 2;
    }
    int l = n - powerOf2;
    return 2 * l + 1;
}

// Cách 3: Dịch vòng 1 bit trái
int josephusBitShift(int n) {
    int msb = 31 - __builtin_clz(n); // Vị trí bit cao nhất
    int mask = (1 << msb) - 1;       // Mặt nạ lấy các bit sau bit cao nhất
    return ((n & mask) << 1) | 1;
}

int main() {
    cout << "=== THUẬT TOÁN GIẢM THEO TỈ LỆ HẰNG SỐ (LEVITIN CHƯƠNG 4.4) ===" << endl;

    // 1. Kiểm thử Tìm kiếm nhị phân 2 nhánh
    vector<int> A = {3, 14, 27, 31, 39, 42, 55, 70, 74, 81, 85, 93, 98};
    int key = 70;
    int idx = binarySearchTwoWay(A, key);
    cout << "\n1. Tìm kiếm nhị phân 2 nhánh: Khóa " << key << " tại chỉ số: " << idx << endl;

    // 2. Kiểm thử Phép nhân nông dân Nga (Bài tập 4.4.11: 26 x 47)
    cout << "\n2. Phép nhân nông dân Nga:" << endl;
    long long prod = russianPeasant(26, 47);
    cout << "=> Kết quả: 26 x 47 = " << prod << endl;

    // 3. Kiểm thử Bài toán Josephus (Bài tập 4.4.13: J(40))
    cout << "\n3. Bài toán Josephus với n = 40 (Bài tập 4.4.13):" << endl;
    cout << "- Theo công thức truy hồi: J(40) = " << josephusRec(40) << endl;
    cout << "- Theo công thức đóng:     J(40) = " << josephusClosed(40) << endl;
    cout << "- Theo dịch vòng bit:      J(40) = " << josephusBitShift(40) << endl;

    cout << "\n===============================================================\n";
    return 0;
}
