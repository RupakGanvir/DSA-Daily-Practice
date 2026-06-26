#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec
{
private:
    void serializeHelper(TreeNode *root, ostringstream &out)
    {
        if (root == nullptr)
        {
            out << "#,";
            return;
        }
        out << root->val << ",";
        serializeHelper(root->left, out);
        serializeHelper(root->right, out);
    }

    TreeNode *deserializeHelper(stringstream &in)
    {
        string val;
        if (!getline(in, val, ','))
        {
            return nullptr;
        }
        if (val == "#")
        {
            return nullptr;
        }

        TreeNode *node = new TreeNode(stoi(val));
        node->left = deserializeHelper(in);
        node->right = deserializeHelper(in);
        return node;
    }

public:
    string serialize(TreeNode *root)
    {
        ostringstream out;
        serializeHelper(root, out);
        return out.str();
    }

    TreeNode *deserialize(string data)
    {
        stringstream in(data);
        return deserializeHelper(in);
    }
};

void printTreePreOrder(TreeNode *root)
{
    if (root == nullptr)
    {
        cout << "# ";
        return;
    }
    cout << root->val << " ";
    printTreePreOrder(root->left);
    printTreePreOrder(root->right);
}

int main()
{
    Codec ser, deser;

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    cout << "--- Serialize and Deserialize Binary Tree Tests ---" << endl;

    string serializedData = ser.serialize(root);
    cout << "Serialized String: " << serializedData << endl;

    TreeNode *deserializedRoot = deser.deserialize(serializedData);

    cout << "Deserialized Tree (Pre-Order Verification): ";
    printTreePreOrder(deserializedRoot);
    cout << endl;

    return 0;
}