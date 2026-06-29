#include <iostream>
#include <vector>

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
    int kthSmallest(TreeNode *root, int k)
    {
        int count = 0;
        int result = -1;
        inorder(root, k, count, result);
        return result;
    }

private:
    void inorder(TreeNode *node, int k, int &count, int &result)
    {
        if (!node || count >= k)
            return;

        inorder(node->left, k, count, result);

        count++;
        if (count == k)
        {
            result = node->val;
            return;
        }

        inorder(node->right, k, count, result);
    }
};

int main()
{
    Solution solver;

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);

    int k = 1;
    cout << "--- Kth Smallest Element in BST Test ---" << endl;
    cout << "The " << k << "st smallest element is: " << solver.kthSmallest(root, k) << endl;

    return 0;
}