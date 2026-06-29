#include <iostream>
#include <climits>

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
    bool isValidBST(TreeNode *root)
    {
        return validate(root, LONG_MIN, LONG_MAX);
    }

private:
    bool validate(TreeNode *node, long minVal, long maxVal)
    {
        if (node == nullptr)
        {
            return true;
        }

        if (node->val <= minVal || node->val >= maxVal)
        {
            return false;
        }

        return validate(node->left, minVal, node->val) &&
               validate(node->right, node->val, maxVal);
    }
};

int main()
{
    Solution solver;

    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    cout << "--- Validate Binary Search Tree Test ---" << endl;
    cout << "Is valid BST: " << (solver.isValidBST(root) ? "True" : "False") << endl;

    return 0;
}