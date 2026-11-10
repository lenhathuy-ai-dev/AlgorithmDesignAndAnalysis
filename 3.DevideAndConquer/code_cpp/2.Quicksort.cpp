#include <iostream>
#include <vector>
#include <algorithm>

// Phân hoạch Hoare (Hoare Partition) chuẩn hóa theo giáo trình Levitin (Section 5.2)
int hoarePartition(std::vector<int>& A, int l, int r, long long& comps) {
    int p = A[l]; // Chọn phần tử đầu tiên làm chốt (pivot)
    int i = l;
    int j = r + 1;
    
    while (true) {
        do {
            i++;
            comps++;
        } while (i <= r && A[i] < p);
        
        do {
            j--;
            comps++;
        } while (A[j] > p);
        
        if (i >= j) break;
        std::swap(A[i], A[j]);
    }
    
    std::swap(A[l], A[j]); // Đưa chốt về vị trí phân hoạch chính xác
    return j;
}

// Quicksort với tối ưu hóa đệ quy đuôi (Tail Recursion) bảo đảm chiều sâu ngăn xếp O(log n)
void quicksort(std::vector<int>& A, int l, int r, long long& comps) {
    while (l < r) {
        int s = hoarePartition(A, l, r, comps);
        // Luôn gọi đệ quy cho nửa nhỏ hơn trước, dùng vòng lặp cho nửa lớn hơn
        if (s - l < r - s) {
            quicksort(A, l, s - 1, comps);
            l = s + 1;
        } else {
            quicksort(A, s + 1, r, comps);
            r = s - 1;
        }
    }
}

// Phân hoạch 3 chiều Dijkstra (Dutch National Flag Partition) - Bài tập 5.2 (Bài 9)
// Xử lý cực nhanh mảng có nhiều phần tử trùng lặp O(n)
void threeWayPartition(std::vector<int>& A, int l, int r, int& i, int& j) {
    int pivot = A[l];
    int mid = l;
    i = l;
    j = r;
    
    while (mid <= j) {
        if (A[mid] < pivot) {
            std::swap(A[i], A[mid]);
            i++;
            mid++;
        } else if (A[mid] == pivot) {
            mid++;
        } else {
            std::swap(A[mid], A[j]);
            j--;
        }
    }
}

void quicksort3Way(std::vector<int>& A, int l, int r) {
    if (l >= r) return;
    int i, j;
    threeWayPartition(A, l, r, i, j);
    quicksort3Way(A, l, i - 1);
    quicksort3Way(A, j + 1, r);
}

int main() {
    std::cout << "=== THUẬT TOÁN SẮP XẾP NHANH (QUICKSORT) - LEVITIN SECTION 5.2 ===" << std::endl;
    std::vector<int> A = {5, 2, 9, 3, 7, 6, 1, 8, 4};
    std::cout << "Mang ban dau: ";
    for (int x : A) std::cout << x << " ";
    std::cout << std::endl;
    
    long long comps = 0;
    quicksort(A, 0, A.size() - 1, comps);
    
    std::cout << "Mang sau Quicksort (Hoare): ";
    for (int x : A) std::cout << x << " ";
    std::cout << std::endl;
    std::cout << "So phep so sanh: " << comps << std::endl;
    
    std::vector<int> A_dups = {3, 1, 4, 3, 2, 3, 1, 4, 3, 3};
    std::cout << "\nMang co nhieu phan tu trung lap: ";
    for (int x : A_dups) std::cout << x << " ";
    std::cout << std::endl;
    
    quicksort3Way(A_dups, 0, A_dups.size() - 1);
    std::cout << "Mang sau 3-Way Quicksort (Dutch National Flag): ";
    for (int x : A_dups) std::cout << x << " ";
    std::cout << std::endl;
    
    return 0;
}
