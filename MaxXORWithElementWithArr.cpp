#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class TrieNode
{
public:
    TrieNode *child[2];
    TrieNode()
    {
        child[0] = nullptr;
        child[1] = nullptr;
    }
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(int num)
    {
        TrieNode *curr = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (!curr->child[bit])
            {
                curr->child[bit] = new TrieNode();
            }
            curr = curr->child[bit];
        }
    }

    int getMaxXor(int num)
    {
        TrieNode *curr = root;
        if (!curr->child[0] && !curr->child[1])
        {
            return -1;
        }

        int maxXor = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            int oppositeBit = 1 - bit;

            if (curr->child[oppositeBit])
            {
                maxXor |= (1 << i);
                curr = curr->child[oppositeBit];
            }
            else
            {
                curr = curr->child[bit];
            }
        }
        return maxXor;
    }
};

class Solution
{
public:
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
    {
        sort(nums.begin(), nums.end());

        int qCount = queries.size();
        vector<vector<int>> sortedQueries;
        for (int i = 0; i < qCount; i++)
        {
            sortedQueries.push_back({queries[i][1], queries[i][0], i});
        }
        sort(sortedQueries.begin(), sortedQueries.end());

        vector<int> ans(qCount, -1);
        Trie trie;
        int n = nums.size();
        int idx = 0;

        for (int i = 0; i < qCount; i++)
        {
            int m = sortedQueries[i][0];
            int x = sortedQueries[i][1];
            int qIdx = sortedQueries[i][2];

            while (idx < n && nums[idx] <= m)
            {
                trie.insert(nums[idx]);
                idx++;
            }

            if (idx > 0)
            {
                ans[qIdx] = trie.getMaxXor(x);
            }
        }

        return ans;
    }
};

void printVector(const vector<int> &v)
{
    if (v.empty())
    {
        cout << "[]\n";
        return;
    }
    for (int num : v)
    {
        cout << num << " ";
    }
    cout << "\n";
}

int main()
{
    Solution solver;

    vector<int> nums1 = {0, 1, 2, 3, 4};
    vector<vector<int>> queries1 = {{3, 1}, {1, 3}, {5, 6}};
    printVector(solver.maximizeXor(nums1, queries1));

    vector<int> nums2 = {5, 2, 4, 6, 6, 3};
    vector<vector<int>> queries2 = {{12, 4}, {8, 1}, {6, 3}};
    printVector(solver.maximizeXor(nums2, queries2));

    return 0;
}