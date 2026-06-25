#include <iostream>
#include <algorithm>
#include <cmath>

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
public:
    bool isBalanced(TreeNode *root)
    {
        return checkHeight(root) != -1;
    }

private:
    int checkHeight(TreeNode *node)
    {
        if (node == nullptr)
        {
            return 0;
        }

        int leftHeight = checkHeight(node->left);
        if (leftHeight == -1)
        {
            return -1;
        }

        int rightHeight = checkHeight(node->right);
        if (rightHeight == -1)
        {
            return -1;
        }

        if (abs(leftHeight - rightHeight) > 1)
        {
            return -1;
        }

        return max(leftHeight, rightHeight) + 1;
    }
};

int main()
{
    Solution solver;

    // Test 1: A balanced tree
    TreeNode *root1 = new TreeNode(3);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20);
    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(7);

    // Test 2: An unbalanced tree
    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(2);
    root2->left->left = new TreeNode(3);
    root2->left->right = new TreeNode(3);
    root2->left->left->left = new TreeNode(4);
    root2->left->left->right = new TreeNode(4);

    cout << "--- Balanced Binary Tree Tests ---" << endl;
    cout << "Test 1: " << (solver.isBalanced(root1) ? "True" : "False") << endl;
    cout << "Test 2: " << (solver.isBalanced(root2) ? "True" : "False") << endl;

    return 0;
}