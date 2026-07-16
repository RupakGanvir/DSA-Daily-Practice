#include <iostream>
#include <vector>
#include <queue>
#include <climits>

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
    vector<int> largestValues(TreeNode *root)
    {
        vector<int> result;
        if (!root)
            return result;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            int max_val = INT_MIN;

            for (int i = 0; i < size; ++i)
            {
                TreeNode *node = q.front();
                q.pop();

                max_val = max(max_val, node->val);

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            result.push_back(max_val);
        }

        return result;
    }
};

void printVector(const vector<int> &vec)
{
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << (i == vec.size() - 1 ? "" : ", ");
    }
    cout << "]";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode(5);
    root1->left->right = new TreeNode(3);
    root1->right->right = new TreeNode(9);

    cout << "--- Test Case 1 ---\n";
    cout << "Largest Values: ";
    printVector(solver.largestValues(root1));
    cout << "\n\n";

    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);

    cout << "--- Test Case 2 ---\n";
    cout << "Largest Values: ";
    printVector(solver.largestValues(root2));
    cout << "\n\n";

    TreeNode *root3 = nullptr;

    cout << "--- Test Case 3 ---\n";
    cout << "Largest Values: ";
    printVector(solver.largestValues(root3));
    cout << "\n";

    return 0;
}