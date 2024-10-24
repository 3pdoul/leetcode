#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) {
            return true;
        }
        if (root1 == nullptr || root2 == nullptr || root1->val != root2->val) {
            return false;
        }

        return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) ||
               (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
    }
};

// Helper function to build a binary tree
TreeNode* createNode(int value) {
    return new TreeNode(value);
}

// Test cases for flipEquiv
int main() {
    Solution sol;

    // Test Case 1: Equivalent Flip Binary Trees
    TreeNode* root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(3);
    root1->left->left = createNode(4);
    root1->left->right = createNode(5);
    root1->right->left = createNode(6);
    root1->left->right->left = createNode(7);
    root1->left->right->right = createNode(8);

    TreeNode* root2 = createNode(1);
    root2->left = createNode(3);
    root2->right = createNode(2);
    root2->left->right = createNode(6);
    root2->right->left = createNode(4);
    root2->right->right = createNode(5);
    root2->right->right->left = createNode(8);
    root2->right->right->right = createNode(7);

    // Check flip equivalence
    if (sol.flipEquiv(root1, root2)) {
        cout << "The trees are flip equivalent." << endl;
    } else {
        cout << "The trees are not flip equivalent." << endl;
    }

    // Test Case 2: Non-equivalent Trees
    TreeNode* root3 = createNode(1);
    root3->left = createNode(2);
    root3->right = createNode(3);

    TreeNode* root4 = createNode(1);
    root4->left = createNode(3);

    if (sol.flipEquiv(root3, root4)) {
        cout << "The trees are flip equivalent." << endl;
    } else {
        cout << "The trees are not flip equivalent." << endl;
    }

    return 0;
}
