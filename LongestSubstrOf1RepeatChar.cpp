#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
private:
    struct Node
    {
        int pre_len, suf_len, max_len, size;
        char pre_char, suf_char;
    };

    vector<Node> tree;

    Node merge(const Node &left, const Node &right)
    {
        Node res;
        res.size = left.size + right.size;
        res.pre_char = left.pre_char;
        res.suf_char = right.suf_char;

        res.pre_len = left.pre_len;
        if (left.pre_len == left.size && left.pre_char == right.pre_char)
        {
            res.pre_len += right.pre_len;
        }

        res.suf_len = right.suf_len;
        if (right.suf_len == right.size && right.suf_char == left.suf_char)
        {
            res.suf_len += left.suf_len;
        }

        res.max_len = max(left.max_len, right.max_len);
        if (left.suf_char == right.pre_char)
        {
            res.max_len = max(res.max_len, left.suf_len + right.pre_len);
        }

        return res;
    }

    void build(int node, int start, int end, const string &s)
    {
        if (start == end)
        {
            tree[node] = {1, 1, 1, 1, s[start], s[start]};
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid, s);
        build(2 * node + 1, mid + 1, end, s);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, char c)
    {
        if (start == end)
        {
            tree[node] = {1, 1, 1, 1, c, c};
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid)
        {
            update(2 * node, start, mid, idx, c);
        }
        else
        {
            update(2 * node + 1, mid + 1, end, idx, c);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int> &queryIndices)
    {
        int n = s.length();
        tree.resize(4 * n);
        build(1, 0, n - 1, s);

        int k = queryCharacters.length();
        vector<int> ans(k);

        for (int i = 0; i < k; ++i)
        {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            ans[i] = tree[1].max_len;
        }

        return ans;
    }
};

void printVector(const vector<int> &vec)
{
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << (i + 1 == vec.size() ? "" : ", ");
    }
    cout << "]\n";
}

int main()
{
    Solution solver;

    string s1 = "babacc";
    string qc1 = "bcb";
    vector<int> qi1 = {1, 3, 3};
    printVector(solver.longestRepeating(s1, qc1, qi1));

    string s2 = "abyzz";
    string qc2 = "aa";
    vector<int> qi2 = {2, 1};
    printVector(solver.longestRepeating(s2, qc2, qi2));

    return 0;
}