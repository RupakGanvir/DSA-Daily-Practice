#include <iostream>
#include <vector>
#include <queue>
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
    int widthOfBinaryTree(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        long long maxWidth = 0;
        queue<pair<TreeNode *, long long>> q;
        q.push({root, 0});

        while (!q.empty())
        {
            int size = q.size();
            long long minIndex = q.front().second;
            long long first = 0, last = 0;

            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front().first;
                long long currentIndex = q.front().second - minIndex;
                q.pop();

                if (i == 0)
                    first = currentIndex;
                if (i == size - 1)
                    last = currentIndex;

                if (node->left != nullptr)
                {
                    q.push({node->left, 2 * currentIndex + 1});
                }
                if (node->right != nullptr)
                {
                    q.push({node->right, 2 * currentIndex + 2});
                }
            }
            maxWidth = max(maxWidth, last - first + 1);
        }

        return maxWidth;
    }
};

int main()
{
    Solution solver;

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);

    cout << "--- Maximum Width of Binary Tree Tests ---" << endl;
    cout << "Test 1: " << solver.widthOfBinaryTree(root) << endl;

    return 0;
}