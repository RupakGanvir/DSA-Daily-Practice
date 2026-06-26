#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>

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
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> result;
        if (root == nullptr)
        {
            return result;
        }

        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode *, pair<int, int>>> q;

        q.push({root, {0, 0}});

        while (!q.empty())
        {
            auto p = q.front();
            q.pop();

            TreeNode *node = p.first;
            int col = p.second.first;
            int row = p.second.second;

            nodes[col][row].insert(node->val);

            if (node->left != nullptr)
            {
                q.push({node->left, {col - 1, row + 1}});
            }
            if (node->right != nullptr)
            {
                q.push({node->right, {col + 1, row + 1}});
            }
        }

        // Clean iterator loop fully compatible across C++11, C++14, and C++17
        for (auto colIt = nodes.begin(); colIt != nodes.end(); ++colIt)
        {
            vector<int> colVec;
            const auto &rowMap = colIt->second;

            for (auto rowIt = rowMap.begin(); rowIt != rowMap.end(); ++rowIt)
            {
                const auto &valSet = rowIt->second;
                colVec.insert(colVec.end(), valSet.begin(), valSet.end());
            }
            result.push_back(colVec);
        }

        return result;
    }
};

int main()
{
    Solution solver;

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> res = solver.verticalTraversal(root);

    cout << "--- Vertical Order Traversal Tests ---" << endl;
    for (size_t i = 0; i < res.size(); i++)
    {
        cout << "Column " << i << ": [";
        for (size_t j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << (j < res[i].size() - 1 ? ", " : "");
        }
        cout << "]" << endl;
    }

    return 0;
}