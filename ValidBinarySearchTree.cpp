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
    bool validate(TreeNode *node, long long min_val, long long max_val)
    {

        if (node == nullptr)
        {
            return true;
        }

        if (node->val <= min_val || node->val >= max_val)
        {
            return false;
        }

        bool isLeftValid = validate(node->left, min_val, node->val);

        bool isRightValid = validate(node->right, node->val, max_val);

        return isLeftValid && isRightValid;
    }

public:
    bool isValidBST(TreeNode *root)
    {
        return validate(root, -10000000000LL, 10000000000LL);
    }
};

int main()
{
    Solution solver;

    TreeNode *root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(3);

    TreeNode *root2 = new TreeNode(5);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(4);
    root2->right->left = new TreeNode(3);
    root2->right->right = new TreeNode(6);

    cout << "--- Valid Binary Search Tree Tests ---" << endl;
    cout << "Test 1 (Expected Valid/True):   " << (solver.isValidBST(root1) ? "True" : "False") << endl;
    cout << "Test 2 (Expected Invalid/False): " << (solver.isValidBST(root2) ? "True" : "False") << endl;

    return 0;
}