#include <iostream>
#include <vector>
#include <unordered_map>

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
    unordered_map<int, int> inorderMap;
    int preorderIndex;

    TreeNode *buildTreeHelper(const vector<int> &preorder, int inorderStart, int inorderEnd)
    {
        if (inorderStart > inorderEnd)
        {
            return nullptr;
        }

        int rootValue = preorder[preorderIndex++];
        TreeNode *root = new TreeNode(rootValue);

        int rootInorderIndex = inorderMap[rootValue];

        root->left = buildTreeHelper(preorder, inorderStart, rootInorderIndex - 1);
        root->right = buildTreeHelper(preorder, rootInorderIndex + 1, inorderEnd);

        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        inorderMap.clear();
        for (int i = 0; i < inorder.size(); i++)
        {
            inorderMap[inorder[i]] = i;
        }

        preorderIndex = 0;
        return buildTreeHelper(preorder, 0, inorder.size() - 1);
    }
};

void printTreeInOrder(TreeNode *root)
{
    if (root == nullptr)
        return;
    printTreeInOrder(root->left);
    cout << root->val << " ";
    printTreeInOrder(root->right);
}

int main()
{
    Solution solver;

    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    TreeNode *root = solver.buildTree(preorder, inorder);

    cout << "--- Construct Binary Tree Tests ---" << endl;
    cout << "Reconstructed Tree (In-Order Verification): ";
    printTreeInOrder(root);
    cout << endl;

    return 0;
}