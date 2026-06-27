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
    void flatten(TreeNode *root)
    {
        TreeNode *curr = root;

        while (curr != nullptr)
        {
            if (curr->left != nullptr)
            {
                TreeNode *runner = curr->left;
                while (runner->right != nullptr)
                {
                    runner = runner->right;
                }

                runner->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }
            curr = curr->right;
        }
    }
};

void printFlattenedTree(TreeNode *root)
{
    TreeNode *curr = root;
    while (curr != nullptr)
    {
        cout << curr->val;
        if (curr->right != nullptr)
            cout << " -> ";
        if (curr->left != nullptr)
            cout << " (ERR: Left child exists!) ";
        curr = curr->right;
    }
    cout << endl;
}

int main()
{
    Solution solver;

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    solver.flatten(root);

    cout << "--- Flatten Binary Tree Tests ---" << endl;
    cout << "Flattened List: ";
    printFlattenedTree(root);

    return 0;
}