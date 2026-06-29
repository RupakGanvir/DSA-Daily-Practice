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

class Solution
{
public:
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int index = 0;
        return build(preorder, index, INT_MIN, INT_MAX);
    }

private:
    TreeNode *build(vector<int> &preorder, int &index, int minVal, int maxVal)
    {
        if (index >= preorder.size() || preorder[index] < minVal || preorder[index] > maxVal)
        {
            return nullptr;
        }

        TreeNode *root = new TreeNode(preorder[index++]);
        root->left = build(preorder, index, minVal, root->val);
        root->right = build(preorder, index, root->val, maxVal);

        return root;
    }
};

void printPreorder(TreeNode *root)
{
    if (!root)
        return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main()
{
    Solution solver;
    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    TreeNode *root = solver.bstFromPreorder(preorder);

    cout << "--- Construct BST from Preorder Traversal Test ---" << endl;
    cout << "Preorder result: ";
    printPreorder(root);
    cout << endl;

    return 0;
}