#include <iostream>

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
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr || root == p || root == q)
        {
            return root;
        }

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (left != nullptr && right != nullptr)
        {
            return root;
        }

        return left != nullptr ? left : right;
    }
};

int main()
{
    Solution solver;

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    TreeNode *p = root->left;  // Node 5
    TreeNode *q = root->right; // Node 1
    TreeNode *res1 = solver.lowestCommonAncestor(root, p, q);

    TreeNode *q2 = root->left->right->right; // Node 4
    TreeNode *res2 = solver.lowestCommonAncestor(root, p, q2);

    cout << "--- Lowest Common Ancestor Tests ---" << endl;
    cout << "Test 1 LCA(5, 1): " << (res1 ? to_string(res1->val) : "null") << endl;
    cout << "Test 2 LCA(5, 4): " << (res2 ? to_string(res2->val) : "null") << endl;

    return 0;
}