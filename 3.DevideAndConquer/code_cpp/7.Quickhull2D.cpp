#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>

struct Point {
    int x, y;
    bool operator<(const Point& o) const {
        return x < o.x || (x == o.x && y < o.y);
    }
};

// Định thức cấp 3 xác định vị trí tương đối và diện tích tam giác:
// > 0 nếu p nằm bên trái đường thẳng có hướng p1 -> p2
int findSide(Point p1, Point p2, Point p) {
    int val = (p.y - p1.y) * (p2.x - p1.x) - (p2.y - p1.y) * (p.x - p1.x);
    if (val > 0) return 1;
    if (val < 0) return -1;
    return 0;
}

// Khoảng cách từ p tới đường thẳng p1->p2 tỷ lệ thuận với giá trị tuyệt đối của định thức
int lineDist(Point p1, Point p2, Point p) {
    return std::abs((p.y - p1.y) * (p2.x - p1.x) - (p2.y - p1.y) * (p.x - p1.x));
}

void quickHullRec(const std::vector<Point>& pts, Point p1, Point p2, int side, std::set<Point>& hull) {
    int ind = -1;
    int maxDist = 0;
    
    // Tìm điểm p_max nằm xa đường thẳng nhất ở cùng phía
    for (int i = 0; i < (int)pts.size(); ++i) {
        int temp = lineDist(p1, p2, pts[i]);
        if (findSide(p1, p2, pts[i]) == side && temp > maxDist) {
            ind = i;
            maxDist = temp;
        }
    }
    
    // Nếu không còn điểm nào ở phía này, p1 và p2 là các đỉnh bao lồi
    if (ind == -1) {
        hull.insert(p1);
        hull.insert(p2);
        return;
    }
    
    // Đệ quy cho hai tam giác con bên ngoài tam giác Delta(p1, pts[ind], p2)
    quickHullRec(pts, pts[ind], p1, -findSide(pts[ind], p1, p2), hull);
    quickHullRec(pts, pts[ind], p2, -findSide(pts[ind], p2, p1), hull);
}

std::vector<Point> quickHull(std::vector<Point>& pts) {
    int n = pts.size();
    if (n < 3) return pts;
    
    int min_x = 0, max_x = 0;
    for (int i = 1; i < n; ++i) {
        if (pts[i].x < pts[min_x].x) min_x = i;
        if (pts[i].x > pts[max_x].x) max_x = i;
    }
    
    std::set<Point> hull;
    quickHullRec(pts, pts[min_x], pts[max_x], 1, hull);  // Bao trên
    quickHullRec(pts, pts[min_x], pts[max_x], -1, hull); // Bao dưới
    
    return std::vector<Point>(hull.begin(), hull.end());
}

int main() {
    std::cout << "=== BÀI TOÁN TÌM BAO LỒI (QUICKHULL) - LEVITIN SECTION 5.5 ===" << std::endl;
    
    std::vector<Point> points = {
        {0, 3}, {1, 1}, {2, 2}, {4, 4},
        {0, 0}, {1, 2}, {3, 1}, {3, 3}
    };
    
    std::vector<Point> hull = quickHull(points);
    
    std::cout << "Cac dinh cua Bao loi (Convex Hull):" << std::endl;
    for (const auto& p : hull) {
        std::cout << "(" << p.x << ", " << p.y << ")" << std::endl;
    }
    
    return 0;
}
