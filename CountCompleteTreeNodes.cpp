#include <iostream>
#include <cmath>
#include <vector>
#include <queue>

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
    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;

        int leftH = 0, rightH = 0;
        TreeNode *l = root, *r = root;

        while (l)
        {
            leftH++;
            l = l->left;
        }

        while (r)
        {
            rightH++;
            r = r->right;
        }

        if (leftH == rightH)
        {
            return (1 << leftH) - 1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

TreeNode *buildCompleteTree(const vector<int> &arr)
{
    if (arr.empty())
        return nullptr;
    TreeNode *root = new TreeNode(arr[0]);
    queue<TreeNode *> q;
    q.push(root);
    int i = 1;
    while (i < arr.size())
    {
        TreeNode *curr = q.front();
        q.pop();
        if (i < arr.size())
        {
            curr->left = new TreeNode(arr[i++]);
            q.push(curr->left);
        }
        if (i < arr.size())
        {
            curr->right = new TreeNode(arr[i++]);
            q.push(curr->right);
        }
    }
    return root;
}

int main()
{
    Solution sol;

    // Example: A complete tree with 6 nodes [1, 2, 3, 4, 5, 6]
    vector<int> nodes = {1, 2, 3, 4, 5, 6};
    TreeNode *root = buildCompleteTree(nodes);

    cout << "Total nodes in the complete tree: " << sol.countNodes(root) << endl;

    return 0;
}