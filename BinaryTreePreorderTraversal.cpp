#include <iostream>
#include <vector>
#include <stack>

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
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> result;
        if (root == nullptr)
        {
            return result;
        }

        stack<TreeNode *> s;
        s.push(root);

        while (!s.empty())
        {
            TreeNode *node = s.top();
            s.pop();
            result.push_back(node->val);

            if (node->right != nullptr)
            {
                s.push(node->right);
            }
            if (node->left != nullptr)
            {
                s.push(node->left);
            }
        }

        return result;
    }
};

int main()
{
    Solution solver;

    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> res = solver.preorderTraversal(root);

    cout << "--- Binary Tree Preorder Traversal Tests ---" << endl;
    cout << "Test 1: [";
    for (size_t i = 0; i < res.size(); i++)
    {
        cout << res[i] << (i < res.size() - 1 ? ", " : "");
    }
    cout << "]" << endl;

    return 0;
}