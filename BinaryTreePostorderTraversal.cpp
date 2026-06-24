#include <iostream>
#include <vector>
#include <stack>
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
public:
    vector<int> postorderTraversal(TreeNode *root)
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

            if (node->left != nullptr)
            {
                s.push(node->left);
            }
            if (node->right != nullptr)
            {
                s.push(node->right);
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

int main()
{
    Solution solver;

    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> res = solver.postorderTraversal(root);

    cout << "--- Binary Tree Postorder Traversal Tests ---" << endl;
    cout << "Test 1: [";
    for (size_t i = 0; i < res.size(); i++)
    {
        cout << res[i] << (i < res.size() - 1 ? ", " : "");
    }
    cout << "]" << endl;

    return 0;
}