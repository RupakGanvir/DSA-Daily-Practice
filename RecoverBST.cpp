#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
private:
    TreeNode *first = nullptr, *second = nullptr, *prev = new TreeNode(INT_MIN);

public:
    void recoverTree(TreeNode *root)
    {
        inorder(root);
        swap(first->val, second->val);
    }

    void inorder(TreeNode *root)
    {
        if (!root)
            return;

        inorder(root->left);

        if (first == nullptr && prev->val > root->val)
        {
            first = prev;
        }
        if (first != nullptr && prev->val > root->val)
        {
            second = root;
        }
        prev = root;

        inorder(root->right);
    }
};

int main()
{
    Solution solver;

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->left->right = new TreeNode(2);

    solver.recoverTree(root);

    cout << "--- Recover Binary Search Tree Test ---" << endl;
    cout << "Root: " << root->val << ", Left: " << root->left->val << ", Left-Right: " << root->left->right->val << endl;

    return 0;
}