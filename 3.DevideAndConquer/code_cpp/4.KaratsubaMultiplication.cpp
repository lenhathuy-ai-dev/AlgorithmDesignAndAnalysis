#include <iostream>
#include <string>
#include <algorithm>

// Thuật toán Karatsuba nhân số nguyên lớn - Levitin Section 5.4
// c2 = a1 * b1
// c0 = a0 * b0
// c1 = (a1 + a0) * (b1 + b0) - c2 - c0
// Kết quả = c2 * 10^(2m) + c1 * 10^m + c0

long long karatsuba(long long x, long long y) {
    if (x < 10 || y < 10) {
        return x * y;
    }
    
    std::string sX = std::to_string(x);
    std::string sY = std::to_string(y);
    int n = std::max(sX.length(), sY.length());
    int m = n / 2;
    
    long long p = 1;
    for (int i = 0; i < m; ++i) p *= 10;
    
    long long a1 = x / p;
    long long a0 = x % p;
    long long b1 = y / p;
    long long b0 = y % p;
    
    long long c2 = karatsuba(a1, b1);
    long long c0 = karatsuba(a0, b0);
    long long cSum = karatsuba(a1 + a0, b1 + b0);
    long long c1 = cSum - c2 - c0;
    
    return c2 * p * p + c1 * p + c0;
}

int main() {
    std::cout << "=== NHÂN SỐ NGUYÊN LỚN (KARATSUBA) - LEVITIN SECTION 5.4 ===" << std::endl;
    
    // Bài tập 5.4 - Bài 2: Tính 2101 * 1130
    long long x = 2101;
    long long y = 1130;
    
    long long result = karatsuba(x, y);
    std::cout << "Phep tinh: " << x << " * " << y << std::endl;
    std::cout << "Ket qua Karatsuba:  " << result << std::endl;
    std::cout << "Kiem tra nhan truc tiep: " << (x * y) << std::endl;
    
    if (result == x * y) {
        std::cout << "=> KET QUA CHINH XAC 100%!" << std::endl;
    }
    
    return 0;
}
