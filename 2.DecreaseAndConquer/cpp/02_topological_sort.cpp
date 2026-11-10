#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Cấu trúc đồ thị có hướng (Digraph)
class Digraph {
public:
    int V;
    vector<vector<int>> adj;

    Digraph(int vertices) : V(vertices), adj(vertices) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    // 1. Thuật toán Sắp xếp Tô-pô dựa trên DFS (DFS-based Topological Sort)
    // Trả về false nếu phát hiện chu trình (Back edge)
    bool topologicalSortDFS(vector<int>& result) {
        vector<int> visited(V, 0); // 0: chưa thăm, 1: đang thăm (trên stack), 2: đã xong
        vector<int> order;
        bool hasCycle = false;

        auto dfs = [&](auto self, int u) -> void {
            visited[u] = 1;
            for (int v : adj[u]) {
                if (visited[v] == 1) {
                    hasCycle = true; // Cung ngược -> Có chu trình!
                    return;
                }
                if (visited[v] == 0) {
                    self(self, v);
                    if (hasCycle) return;
                }
            }
            visited[u] = 2;
            order.push_back(u); // Ghi nhận khi trở thành dead-end
        };

        for (int i = 0; i < V; ++i) {
            if (visited[i] == 0) {
                dfs(dfs, i);
                if (hasCycle) return false;
            }
        }

        reverse(order.begin(), order.end());
        result = order;
        return true;
    }

    // 2. Thuật toán Xóa đỉnh nguồn (Source-Removal / Kahn's Algorithm)
    // Trả về false nếu phát hiện chu trình
    bool topologicalSortKahn(vector<int>& result) {
        vector<int> inDegree(V, 0);
        for (int u = 0; u < V; ++u) {
            for (int v : adj[u]) {
                inDegree[v]++;
            }
        }

        queue<int> Q;
        for (int i = 0; i < V; ++i) {
            if (inDegree[i] == 0) {
                Q.push(i);
            }
        }

        result.clear();
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            result.push_back(u);

            for (int v : adj[u]) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    Q.push(v);
                }
            }
        }

        return (result.size() == (size_t)V);
    }
};

int main() {
    cout << "=== THUẬT TOÁN SẮP XẾP TÔ-PÔ (TOPOLOGICAL SORTING - LEVITIN CHƯƠNG 4.2) ===" << endl;

    // Đồ thị (a) trong Bài tập 4.2.1: 7 đỉnh {0:a, 1:b, 2:c, 3:d, 4:e, 5:f, 6:g}
    // d -> a, b, c, f, g; a -> b, c; c -> f; b -> e, g; g -> e, f
    Digraph g_a(7);
    vector<string> names = {"a", "b", "c", "d", "e", "f", "g"};
    g_a.addEdge(3, 0); g_a.addEdge(3, 1); g_a.addEdge(3, 2); g_a.addEdge(3, 5); g_a.addEdge(3, 6);
    g_a.addEdge(0, 1); g_a.addEdge(0, 2);
    g_a.addEdge(2, 5);
    g_a.addEdge(1, 4); g_a.addEdge(1, 6);
    g_a.addEdge(6, 4); g_a.addEdge(6, 5);

    cout << "\n1. Chạy thuật toán trên Đồ thị (a) Bài tập 4.2.1:" << endl;
    vector<int> resDFS, resKahn;
    if (g_a.topologicalSortDFS(resDFS)) {
        cout << "- Kết quả theo DFS: ";
        for (int u : resDFS) cout << names[u] << " ";
        cout << endl;
    }

    if (g_a.topologicalSortKahn(resKahn)) {
        cout << "- Kết quả theo Kahn: ";
        for (int u : resKahn) cout << names[u] << " ";
        cout << endl;
    }

    // Đồ thị (b) trong Bài tập 4.2.1 (Chứa chu trình: a -> b -> c -> d -> g -> e -> a)
    Digraph g_b(7);
    g_b.addEdge(0, 1); g_b.addEdge(1, 2); g_b.addEdge(2, 3); g_b.addEdge(3, 6);
    g_b.addEdge(6, 4); g_b.addEdge(4, 0); // chu trình
    g_b.addEdge(5, 4); g_b.addEdge(5, 1); g_b.addEdge(5, 2); g_b.addEdge(5, 6);

    cout << "\n2. Chạy thuật toán trên Đồ thị (b) Bài tập 4.2.1:" << endl;
    if (!g_b.topologicalSortDFS(resDFS)) {
        cout << "- DFS thông báo: Phát hiện chu trình có hướng! Không có thứ tự tô-pô." << endl;
    }
    if (!g_b.topologicalSortKahn(resKahn)) {
        cout << "- Kahn thông báo: Phát hiện chu trình có hướng! Không có thứ tự tô-pô." << endl;
    }
    cout << "\n========================================================================\n";

    return 0;
}
