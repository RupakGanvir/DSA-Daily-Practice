#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Group
{
    int start;
    int length;
};

class SparseTable
{
public:
    SparseTable(const vector<int> &nums) : n(nums.size())
    {
        if (n == 0)
            return;
        int max_bit = 31 - __builtin_clz(n);
        st.assign(max_bit + 1, vector<int>(n));
        for (int i = 0; i < n; ++i)
            st[0][i] = nums[i];
        for (int i = 1; i <= max_bit; ++i)
        {
            for (int j = 0; j + (1 << i) <= n; ++j)
            {
                st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    int query(int l, int r) const
    {
        if (l > r)
            return 0;
        int i = 31 - __builtin_clz(r - l + 1);
        return max(st[i][l], st[i][r - (1 << i) + 1]);
    }

private:
    int n;
    vector<vector<int>> st;
};

class Solution
{
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>> &queries)
    {
        auto zeroInfo = getZeroGroups(s);
        const vector<Group> &zeroGroups = zeroInfo.first;
        const vector<int> &zeroGroupIndex = zeroInfo.second;

        int ones = 0;
        for (char c : s)
            if (c == '1')
                ones++;

        vector<int> adjacentSums;
        for (size_t i = 0; i + 1 < zeroGroups.size(); ++i)
        {
            adjacentSums.push_back(zeroGroups[i].length + zeroGroups[i + 1].length);
        }
        SparseTable st(adjacentSums);

        vector<int> ans;
        for (const auto &q : queries)
        {
            int l = q[0];
            int r = q[1];

            int left = zeroGroupIndex[l] == -1 ? -1 : zeroGroups[zeroGroupIndex[l]].length - (l - zeroGroups[zeroGroupIndex[l]].start);
            int right = zeroGroupIndex[r] == -1 ? -1 : r - zeroGroups[zeroGroupIndex[r]].start + 1;

            auto adjPair = mapToAdjacentGroupIndices(
                zeroGroupIndex[l] + 1,
                s[r] == '1' ? zeroGroupIndex[r] : zeroGroupIndex[r] - 1);
            int startAdjacentGroupIndex = adjPair.first;
            int endAdjacentGroupIndex = adjPair.second;

            int activeSections = ones;

            if (s[l] == '0' && s[r] == '0' && zeroGroupIndex[l] + 1 == zeroGroupIndex[r])
            {
                activeSections = max(activeSections, ones + left + right);
            }
            else if (startAdjacentGroupIndex <= endAdjacentGroupIndex)
            {
                activeSections = max(activeSections, ones + st.query(startAdjacentGroupIndex, endAdjacentGroupIndex));
            }

            if (s[l] == '0' && zeroGroupIndex[l] + 1 <= (s[r] == '1' ? zeroGroupIndex[r] : zeroGroupIndex[r] - 1))
            {
                activeSections = max(activeSections, ones + left + zeroGroups[zeroGroupIndex[l] + 1].length);
            }

            if (s[r] == '0' && zeroGroupIndex[l] < zeroGroupIndex[r] - 1)
            {
                activeSections = max(activeSections, ones + right + zeroGroups[zeroGroupIndex[r] - 1].length);
            }

            ans.push_back(activeSections);
        }
        return ans;
    }

private:
    pair<vector<Group>, vector<int>> getZeroGroups(const string &s)
    {
        vector<Group> zeroGroups;
        vector<int> zeroGroupIndex;
        for (int i = 0; i < (int)s.length(); i++)
        {
            if (s[i] == '0')
            {
                if (i > 0 && s[i - 1] == '0')
                {
                    zeroGroups.back().length++;
                }
                else
                {
                    zeroGroups.push_back({i, 1});
                }
            }
            zeroGroupIndex.push_back(zeroGroups.empty() ? -1 : (int)zeroGroups.size() - 1);
        }
        return {zeroGroups, zeroGroupIndex};
    }

    pair<int, int> mapToAdjacentGroupIndices(int startGroupIndex, int endGroupIndex)
    {
        return {startGroupIndex, endGroupIndex - 1};
    }
};

int main()
{
    Solution sol;

    string s1 = "01";
    vector<vector<int>> queries1 = {{0, 1}};
    vector<int> res1 = sol.maxActiveSectionsAfterTrade(s1, queries1);
    for (int x : res1)
        cout << x << " ";
    cout << "\n";

    string s2 = "0100";
    vector<vector<int>> queries2 = {{0, 3}, {0, 2}, {1, 3}, {2, 3}};
    vector<int> res2 = sol.maxActiveSectionsAfterTrade(s2, queries2);
    for (int x : res2)
        cout << x << " ";
    cout << "\n";

    string s3 = "1000100";
    vector<vector<int>> queries3 = {{1, 5}, {0, 6}, {0, 4}};
    vector<int> res3 = sol.maxActiveSectionsAfterTrade(s3, queries3);
    for (int x : res3)
        cout << x << " ";
    cout << "\n";

    string s4 = "01010";
    vector<vector<int>> queries4 = {{0, 3}, {1, 4}, {1, 3}};
    vector<int> res4 = sol.maxActiveSectionsAfterTrade(s4, queries4);
    for (int x : res4)
        cout << x << " ";
    cout << "\n";

    return 0;
}