#include <iostream>
#include <vector>
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

struct NodeData
{
    bool isBST;
    int sum;
    int minVal;
    int maxVal;
};

class Solution
{
private:
    int maxSum = 0;

    NodeData solve(TreeNode *root)
    {
        if (!root)
        {
            return {true, 0, INT_MAX, INT_MIN};
        }

        NodeData left = solve(root->left);
        NodeData right = solve(root->right);

        if (left.isBST && right.isBST && root->val > left.maxVal && root->val < right.minVal)
        {
            int currentSum = root->val + left.sum + right.sum;
            maxSum = max(maxSum, currentSum);
            return {true, currentSum, min(root->val, left.minVal), max(root->val, right.maxVal)};
        }

        return {false, 0, 0, 0};
    }

public:
    int maxSumBST(TreeNode *root)
    {
        solve(root);
        return maxSum;
    }
};

int main()
{
    Solution solver;

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(5);
    root->right->right->left = new TreeNode(4);
    root->right->right->right = new TreeNode(6);

    cout << "--- Maximum Sum BST in Binary Tree Test ---" << endl;
    cout << "Maximum BST sum: " << solver.maxSumBST(root) << endl;

    return 0;
}