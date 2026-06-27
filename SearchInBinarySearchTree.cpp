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
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        TreeNode *curr = root;

        while (curr != nullptr && curr->val != val)
        {
            if (val < curr->val)
            {
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
        }

        return curr;
    }
};

void printSubtree(TreeNode *root)
{
    if (root == nullptr)
    {
        cout << "null";
        return;
    }
    cout << root->val << " ";
    if (root->left != nullptr || root->right != nullptr)
    {
        printSubtree(root->left);
        printSubtree(root->right);
    }
}

int main()
{
    Solution solver;

    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2, new TreeNode(1), new TreeNode(3));
    root->right = new TreeNode(7);

    int target = 2;
    TreeNode *result = solver.searchBST(root, target);

    cout << "--- Search in a Binary Search Tree Tests ---" << endl;
    cout << "Search target " << target << " -> Subtree root val: ";
    if (result != nullptr)
    {
        cout << result->val << " (Full subtree preorder: [ ";
        printSubtree(result);
        cout << "])" << endl;
    }
    else
    {
        cout << "null" << endl;
    }

    return 0;
}