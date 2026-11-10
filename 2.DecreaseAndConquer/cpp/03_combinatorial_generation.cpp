#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 1. Thuật toán Johnson-Trotter sinh hoán vị thay đổi tối thiểu
void johnsonTrotter(int n) {
    cout << "\n--- Thuật toán Johnson-Trotter sinh " << n << "! hoán vị ---" << endl;
    vector<int> A(n);
    vector<int> dir(n, -1); // -1: trái (<-), 1: phải (->)
    for (int i = 0; i < n; ++i) A[i] = i + 1;

    int count = 1;
    auto printPerm = [&]() {
        cout << count++ << ": [ ";
        for (int x : A) cout << x << " ";
        cout << "]" << endl;
    };

    printPerm();

    while (true) {
        // Tìm phần tử di động lớn nhất
        int max_mobile = -1;
        int mobile_idx = -1;

        for (int i = 0; i < n; ++i) {
            int target = i + dir[i];
            if (target >= 0 && target < n && A[i] > A[target]) {
                if (A[i] > max_mobile) {
                    max_mobile = A[i];
                    mobile_idx = i;
                }
            }
        }

        if (mobile_idx == -1) break; // Không còn phần tử di động nào

        int target = mobile_idx + dir[mobile_idx];
        // Đổi chỗ phần tử di động với phần tử láng giềng
        swap(A[mobile_idx], A[target]);
        swap(dir[mobile_idx], dir[target]);

        // Đảo chiều tất cả phần tử lớn hơn max_mobile
        for (int i = 0; i < n; ++i) {
            if (A[i] > max_mobile) {
                dir[i] = -dir[i];
            }
        }

        printPerm();
    }
}

// 2. Thuật toán sinh Mã Gray nhị phân phản xạ (BRGC)
vector<string> generateBRGC(int n) {
    if (n == 1) return {"0", "1"};
    vector<string> L1 = generateBRGC(n - 1);
    vector<string> L2 = L1;
    reverse(L2.begin(), L2.end());

    vector<string> result;
    for (const string& s : L1) result.push_back("0" + s);
    for (const string& s : L2) result.push_back("1" + s);
    return result;
}

// 3. Thuật toán Heap (Heap's Algorithm) sinh hoán vị
void heapPermute(int n, vector<int>& A, int& count) {
    if (n == 1) {
        cout << ++count << ": ";
        for (int x : A) cout << x << " ";
        cout << endl;
        return;
    }
    for (int i = 0; i < n; ++i) {
        heapPermute(n - 1, A, count);
        if (n % 2 == 1) {
            swap(A[0], A[n - 1]);
        } else {
            swap(A[i], A[n - 1]);
        }
    }
}

int main() {
    cout << "=== SINH CÁC ĐỐI TƯỢNG TỔ HỢP (COMBINATORIAL OBJECTS - LEVITIN CHƯƠNG 4.3) ===" << endl;

    // Chạy Johnson-Trotter cho n = 3
    johnsonTrotter(3);

    // Sinh mã Gray bậc 4
    cout << "\n--- Mã Gray nhị phân phản xạ bậc 4 (BRGC) ---" << endl;
    vector<string> gray4 = generateBRGC(4);
    for (size_t i = 0; i < gray4.size(); ++i) {
        cout << i << ": " << gray4[i] << endl;
    }

    // Chạy thuật toán Heap cho n = 3
    cout << "\n--- Thuật toán HeapPermute cho n = 3 ---" << endl;
    vector<int> heapArr = {1, 2, 3};
    int heapCount = 0;
    heapPermute(3, heapArr, heapCount);

    cout << "\n=============================================================================\n";
    return 0;
}
