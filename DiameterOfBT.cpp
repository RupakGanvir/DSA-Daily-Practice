#include <iostream>
#include <algorithm>

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
    int maxDiameter = 0;

    int calculateHeight(TreeNode *node)
    {
        if (node == nullptr)
        {
            return 0;
        }

        int leftHeight = calculateHeight(node->left);
        int rightHeight = calculateHeight(node->right);

        maxDiameter = max(maxDiameter, leftHeight + rightHeight);

        return max(leftHeight, rightHeight) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        maxDiameter = 0;
        calculateHeight(root);
        return maxDiameter;
    }
};

int main()
{
    Solution solver;

    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);

    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);

    cout << "--- Diameter of Binary Tree Tests ---" << endl;
    cout << "Test 1: " << solver.diameterOfBinaryTree(root1) << endl;
    cout << "Test 2: " << solver.diameterOfBinaryTree(root2) << endl;

    return 0;
}