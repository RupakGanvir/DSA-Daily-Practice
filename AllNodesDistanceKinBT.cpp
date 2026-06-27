#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
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
private:
    unordered_map<TreeNode *, TreeNode *> parentMap;

    void findParents(TreeNode *node, TreeNode *parent)
    {
        if (node == nullptr)
            return;
        if (parent != nullptr)
        {
            parentMap[node] = parent;
        }
        findParents(node->left, node);
        findParents(node->right, node);
    }

public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        vector<int> result;
        if (root == nullptr || target == nullptr)
            return result;

        parentMap.clear();
        findParents(root, nullptr);

        queue<TreeNode *> q;
        unordered_set<TreeNode *> visited;

        q.push(target);
        visited.insert(target);
        int currentDistance = 0;

        while (!q.empty())
        {
            int size = q.size();

            if (currentDistance == k)
            {
                for (int i = 0; i < size; i++)
                {
                    result.push_back(q.front()->val);
                    q.pop();
                }
                return result;
            }

            for (int i = 0; i < size; i++)
            {
                TreeNode *curr = q.front();
                q.pop();

                if (curr->left != nullptr && visited.find(curr->left) == visited.end())
                {
                    visited.insert(curr->left);
                    q.push(curr->left);
                }
                if (curr->right != nullptr && visited.find(curr->right) == visited.end())
                {
                    visited.insert(curr->right);
                    q.push(curr->right);
                }
                if (parentMap.find(curr) != parentMap.end() && visited.find(parentMap[curr]) == visited.end())
                {
                    visited.insert(parentMap[curr]);
                    q.push(parentMap[curr]);
                }
            }
            currentDistance++;
        }

        return result;
    }
};

int main()
{
    Solution solver;

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    TreeNode *target = root->left; // Node 5
    int k = 2;

    vector<int> res = solver.distanceK(root, target, k);

    cout << "--- All Nodes Distance K in Binary Tree Tests ---" << endl;
    cout << "Nodes at distance " << k << " from node " << target->val << ": [";
    for (size_t i = 0; i < res.size(); i++)
    {
        cout << res[i] << (i < res.size() - 1 ? ", " : "");
    }
    cout << "]" << endl;

    return 0;
}