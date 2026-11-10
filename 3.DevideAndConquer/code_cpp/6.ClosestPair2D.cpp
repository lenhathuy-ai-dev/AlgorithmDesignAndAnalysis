#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

struct Point {
    double x, y;
};

double dist(Point p1, Point p2) {
    return std::sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double bruteForce(const std::vector<Point>& P, int l, int r, Point& bestA, Point& bestB) {
    double minD = 1e18;
    for (int i = l; i <= r; ++i) {
        for (int j = i + 1; j <= r; ++j) {
            double d = dist(P[i], P[j]);
            if (d < minD) {
                minD = d;
                bestA = P[i];
                bestB = P[j];
            }
        }
    }
    return minD;
}

// Xử lý dải hẹp với quy tắc kiểm tra tối đa 7 điểm kế tiếp theo trục y - Levitin Section 5.5
double stripClosest(std::vector<Point>& strip, double d, Point& bestA, Point& bestB) {
    double minD = d;
    std::sort(strip.begin(), strip.end(), [](const Point& a, const Point& b) {
        return a.y < b.y;
    });
    
    int n = strip.size();
    for (int i = 0; i < n; ++i) {
        // Tối đa 7 lần lặp do nguyên lý Dirichlet trên hình chữ nhật 2d x d
        for (int j = i + 1; j < n && (strip[j].y - strip[i].y) < minD; ++j) {
            double curD = dist(strip[i], strip[j]);
            if (curD < minD) {
                minD = curD;
                bestA = strip[i];
                bestB = strip[j];
            }
        }
    }
    return minD;
}

double closestPairRec(std::vector<Point>& Px, int l, int r, Point& bestA, Point& bestB) {
    if (r - l + 1 <= 3) {
        return bruteForce(Px, l, r, bestA, bestB);
    }
    
    int mid = l + (r - l) / 2;
    Point midPoint = Px[mid];
    
    Point aL, bL, aR, bR;
    double dl = closestPairRec(Px, l, mid, aL, bL);
    double dr = closestPairRec(Px, mid + 1, r, aR, bR);
    
    double d = dl;
    bestA = aL; bestB = bL;
    if (dr < d) {
        d = dr;
        bestA = aR; bestB = bR;
    }
    
    std::vector<Point> strip;
    for (int i = l; i <= r; ++i) {
        if (std::abs(Px[i].x - midPoint.x) < d) {
            strip.push_back(Px[i]);
        }
    }
    
    Point aS, bS;
    double dStrip = stripClosest(strip, d, aS, bS);
    if (dStrip < d) {
        bestA = aS;
        bestB = bS;
        return dStrip;
    }
    return d;
}

int main() {
    std::cout << "=== BÀI TOÁN CẶP ĐIỂM GẦN NHẤT 2D (SHAMOS-HOEY) - LEVITIN SECTION 5.5 ===" << std::endl;
    
    std::vector<Point> points = {
        {2.0, 3.0}, {12.0, 30.0}, {40.0, 50.0}, {5.0, 1.0},
        {12.0, 10.0}, {3.0, 4.0}, {2.5, 3.2}
    };
    
    std::sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
        return a.x < b.x;
    });
    
    Point pA, pB;
    double minDistance = closestPairRec(points, 0, points.size() - 1, pA, pB);
    
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Cap diem gan nhat: (" << pA.x << ", " << pA.y << ") va (" 
              << pB.x << ", " << pB.y << ")" << std::endl;
    std::cout << "Khoang cach nho nhat: " << minDistance << std::endl;
    
    return 0;
}
