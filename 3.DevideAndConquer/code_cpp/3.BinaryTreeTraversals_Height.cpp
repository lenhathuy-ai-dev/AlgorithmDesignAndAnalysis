#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

// Thuật toán tính Chiều cao của cây nhị phân Height(T) - Levitin Section 5.3
// Chiều cao là số cạnh của đường đi dài nhất từ gốc tới lá; cây rỗng trả về -1
int height(TreeNode* root) {
    if (!root) return -1;
    return std::max(height(root->left), height(root->right)) + 1;
}

// Tính chiều cao không dùng ngăn xếp (Stack-free) bằng Queue BFS - Bài tập 5.3 (Bài 3)
int heightQueueBFS(TreeNode* root) {
    if (!root) return -1;
    std::queue<TreeNode*> Q;
    Q.push(root);
    int h = -1;
    
    while (!Q.empty()) {
        int levelSize = Q.size();
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* curr = Q.front();
            Q.pop();
            if (curr->left) Q.push(curr->left);
            if (curr->right) Q.push(curr->right);
        }
        h++;
    }
    return h;
}

// Thuật toán đếm số lá đã được sửa đúng (CorrectLeafCounter) - Bài tập 5.3 (Bài 2)
int correctLeafCounter(TreeNode* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return correctLeafCounter(root->left) + correctLeafCounter(root->right);
}

// Duyệt cây cổ điển
void preorder(TreeNode* root) {
    if (!root) return;
    std::cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    std::cout << root->val << " ";
    inorder(root->right);
}

void postorder(TreeNode* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    std::cout << root->val << " ";
}

// Dựng lại cây nhị phân từ Inorder và Postorder - Bài tập 5.3 (Bài 8)
TreeNode* buildTreeRec(const std::vector<int>& in, int inL, int inR,
                       const std::vector<int>& post, int postL, int postR) {
    if (inL > inR) return nullptr;
    int rootVal = post[postR];
    TreeNode* root = new TreeNode(rootVal);
    
    int idx = -1;
    for (int i = inL; i <= inR; ++i) {
        if (in[i] == rootVal) {
            idx = i;
            break;
        }
    }
    int leftSize = idx - inL;
    root->left = buildTreeRec(in, inL, idx - 1, post, postL, postL + leftSize - 1);
    root->right = buildTreeRec(in, idx + 1, inR, post, postL + leftSize, postR - 1);
    return root;
}

int main() {
    std::cout << "=== DUYỆT CÂY NHỊ PHÂN & CHIỀU CAO - LEVITIN SECTION 5.3 ===" << std::endl;
    
    // Xây dựng cây mẫu theo Bài 5 trang 186
    TreeNode* root = new TreeNode(1); // 'a'
    root->left = new TreeNode(2);     // 'b'
    root->right = new TreeNode(3);    // 'c'
    root->left->left = new TreeNode(4);   // 'd'
    root->left->right = new TreeNode(5);  // 'e'
    root->right->right = new TreeNode(6); // 'f'
    
    std::cout << "Chieu cao de quy: " << height(root) << std::endl;
    std::cout << "Chieu cao dung Queue BFS: " << heightQueueBFS(root) << std::endl;
    std::cout << "So nut la (Leaves): " << correctLeafCounter(root) << std::endl;
    
    std::cout << "Preorder:  "; preorder(root); std::cout << std::endl;
    std::cout << "Inorder:   "; inorder(root); std::cout << std::endl;
    std::cout << "Postorder: "; postorder(root); std::cout << std::endl;
    
    // Kiểm tra dựng lại cây từ Bài tập 8
    std::vector<int> inList = {9, 3, 1, 0, 4, 2, 7, 6, 8, 5};
    std::vector<int> postList = {9, 1, 4, 0, 3, 6, 7, 5, 8, 2};
    TreeNode* reconstructed = buildTreeRec(inList, 0, inList.size() - 1, postList, 0, postList.size() - 1);
    std::cout << "\nDung lai cay tu Inorder & Postorder thanh cong! Root = " << reconstructed->val << std::endl;
    std::cout << "Inorder cua cay dung lai: "; inorder(reconstructed); std::cout << std::endl;
    
    return 0;
}
