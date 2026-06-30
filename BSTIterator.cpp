#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BSTIterator
{
private:
    stack<TreeNode *> nodes;

    void pushLeft(TreeNode *node)
    {
        while (node)
        {
            nodes.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode *root)
    {
        pushLeft(root);
    }

    int next()
    {
        TreeNode *top = nodes.top();
        nodes.pop();
        pushLeft(top->right);
        return top->val;
    }

    bool hasNext()
    {
        return !nodes.empty();
    }
};

int main()
{
    TreeNode *root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    BSTIterator *obj = new BSTIterator(root);

    cout << "--- BST Iterator Test ---" << endl;
    cout << "Next: " << obj->next() << endl;
    cout << "Next: " << obj->next() << endl;
    cout << "Has next: " << (obj->hasNext() ? "True" : "False") << endl;

    return 0;
}