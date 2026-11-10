#include <iostream>
#include <vector>

using Matrix = std::vector<std::vector<int>>;

Matrix add(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

Matrix sub(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

Matrix standardMultiply(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
        for (int k = 0; k < n; ++k)
            for (int j = 0; j < n; ++j)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}

// Thuật toán Strassen chia để trị nhân 2 ma trận n x n (dừng khi n <= 2)
Matrix strassen(const Matrix& A, const Matrix& B) {
    int n = A.size();
    if (n <= 2) {
        return standardMultiply(A, B);
    }
    
    int k = n / 2;
    Matrix A00(k, std::vector<int>(k)), A01(k, std::vector<int>(k)),
           A10(k, std::vector<int>(k)), A11(k, std::vector<int>(k));
    Matrix B00(k, std::vector<int>(k)), B01(k, std::vector<int>(k)),
           B10(k, std::vector<int>(k)), B11(k, std::vector<int>(k));
           
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            A00[i][j] = A[i][j];
            A01[i][j] = A[i][j + k];
            A10[i][j] = A[i + k][j];
            A11[i][j] = A[i + k][j + k];
            
            B00[i][j] = B[i][j];
            B01[i][j] = B[i][j + k];
            B10[i][j] = B[i + k][j];
            B11[i][j] = B[i + k][j + k];
        }
    }
    
    // 7 phép nhân ma trận con của Strassen
    Matrix M1 = strassen(add(A00, A11), add(B00, B11));
    Matrix M2 = strassen(add(A10, A11), B00);
    Matrix M3 = strassen(A00, sub(B01, B11));
    Matrix M4 = strassen(A11, sub(B10, B00));
    Matrix M5 = strassen(add(A00, A01), B11);
    Matrix M6 = strassen(sub(A10, A00), add(B00, B01));
    Matrix M7 = strassen(sub(A01, A11), add(B10, B11));
    
    Matrix C00 = add(sub(add(M1, M4), M5), M7);
    Matrix C01 = add(M3, M5);
    Matrix C10 = add(M2, M4);
    Matrix C11 = add(add(sub(M1, M2), M3), M6);
    
    Matrix C(n, std::vector<int>(n));
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            C[i][j] = C00[i][j];
            C[i][j + k] = C01[i][j];
            C[i + k][j] = C10[i][j];
            C[i + k][j + k] = C11[i][j];
        }
    }
    return C;
}

int main() {
    std::cout << "=== PHÉP NHÂN MA TRẬN STRASSEN - LEVITIN SECTION 5.4 ===" << std::endl;
    
    // Hai ma trận 4x4 trong Bài tập 5.4 - Bài 7
    Matrix A = {
        {1, 0, 2, 1},
        {4, 1, 1, 0},
        {0, 1, 3, 0},
        {5, 0, 2, 1}
    };
    
    Matrix B = {
        {0, 1, 0, 1},
        {2, 1, 0, 4},
        {2, 0, 1, 1},
        {1, 3, 5, 0}
    };
    
    Matrix C_strassen = strassen(A, B);
    Matrix C_standard = standardMultiply(A, B);
    
    std::cout << "Ket qua nhan Strassen:" << std::endl;
    for (const auto& row : C_strassen) {
        for (int val : row) std::cout << val << "\t";
        std::cout << std::endl;
    }
    
    std::cout << "\nKiem tra voi nhan thong thuong O(n^3):" << std::endl;
    for (const auto& row : C_standard) {
        for (int val : row) std::cout << val << "\t";
        std::cout << std::endl;
    }
    
    return 0;
}
