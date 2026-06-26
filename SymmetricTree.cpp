#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    bool isMirror(TreeNode *t1, TreeNode *t2)
    {
        if (t1 == nullptr && t2 == nullptr)
        {
            return true;
        }
        if (t1 == nullptr || t2 == nullptr)
        {
            return false;
        }

        return (t1->val == t2->val) && isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
    }

public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }
        return isMirror(root->left, root->right);
    }
};

int main()
{
    Solution solver;

    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2, new TreeNode(3), new TreeNode(4));
    root1->right = new TreeNode(2, new TreeNode(4), new TreeNode(3));

    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2, nullptr, new TreeNode(3));
    root2->right = new TreeNode(2, nullptr, new TreeNode(3));

    cout << "--- Symmetric Tree Tests ---" << endl;
    cout << "Test 1: " << (solver.isSymmetric(root1) ? "true" : "false") << endl;
    cout << "Test 2: " << (solver.isSymmetric(root2) ? "true" : "false") << endl;

    return 0;
}