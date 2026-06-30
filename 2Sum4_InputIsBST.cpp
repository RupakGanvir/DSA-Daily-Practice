#include <iostream>
#include <vector>
#include <unordered_set>

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
    bool findTarget(TreeNode *root, int k)
    {
        unordered_set<int> seen;
        return dfs(root, k, seen);
    }

private:
    bool dfs(TreeNode *node, int k, unordered_set<int> &seen)
    {
        if (!node)
            return false;

        if (seen.count(k - node->val))
            return true;
        seen.insert(node->val);

        return dfs(node->left, k, seen) || dfs(node->right, k, seen);
    }
};

int main()
{
    Solution solver;

    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    int k = 9;
    cout << "--- Two Sum IV - Input is BST Test ---" << endl;
    cout << "Target " << k << " exists: " << (solver.findTarget(root, k) ? "True" : "False") << endl;

    return 0;
}