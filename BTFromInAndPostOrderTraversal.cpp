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
    int postorderIndex;

    TreeNode *buildTreeHelper(const vector<int> &postorder, int inorderStart, int inorderEnd)
    {
        if (inorderStart > inorderEnd)
        {
            return nullptr;
        }

        int rootValue = postorder[postorderIndex--];
        TreeNode *root = new TreeNode(rootValue);

        int rootInorderIndex = inorderMap[rootValue];

        root->right = buildTreeHelper(postorder, rootInorderIndex + 1, inorderEnd);
        root->left = buildTreeHelper(postorder, inorderStart, rootInorderIndex - 1);

        return root;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        inorderMap.clear();
        for (int i = 0; i < inorder.size(); i++)
        {
            inorderMap[inorder[i]] = i;
        }

        postorderIndex = postorder.size() - 1;
        return buildTreeHelper(postorder, 0, inorder.size() - 1);
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

    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    TreeNode *root = solver.buildTree(inorder, postorder);

    cout << "--- Construct Binary Tree Tests ---" << endl;
    cout << "Reconstructed Tree (In-Order Verification): ";
    printTreeInOrder(root);
    cout << endl;

    return 0;
}