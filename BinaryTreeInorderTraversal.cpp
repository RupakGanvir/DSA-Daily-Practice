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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode *> s;
        TreeNode *curr = root;

        while (curr != nullptr || !s.empty())
        {
            while (curr != nullptr)
            {
                s.push(curr);
                curr = curr->left;
            }

            curr = s.top();
            s.pop();
            result.push_back(curr->val);

            curr = curr->right;
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

    vector<int> res = solver.inorderTraversal(root);

    cout << "--- Binary Tree Inorder Traversal Tests ---" << endl;
    cout << "Test 1: [";
    for (size_t i = 0; i < res.size(); i++)
    {
        cout << res[i] << (i < res.size() - 1 ? ", " : "");
    }
    cout << "]" << endl;

    return 0;
}