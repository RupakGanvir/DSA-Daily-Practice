#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution
{
private:
    vector<int> parent;
    vector<int> rank;

    int find_set(int v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);
        if (a != b)
        {
            if (rank[a] < rank[b])
                swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
    }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        int n = accounts.size();
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        rank.assign(n, 0);

        unordered_map<string, int> emailToIndex;

        for (int i = 0; i < n; ++i)
        {
            for (size_t j = 1; j < accounts[i].size(); ++j)
            {
                const string &email = accounts[i][j];
                if (emailToIndex.find(email) == emailToIndex.end())
                {
                    emailToIndex[email] = i;
                }
                else
                {
                    union_sets(i, emailToIndex[email]);
                }
            }
        }

        unordered_map<int, vector<string>> mergedAccounts;
        for (const auto &pair : emailToIndex)
        {
            const string &email = pair.first;
            int accountIdx = pair.second;
            int rootIdx = find_set(accountIdx);
            mergedAccounts[rootIdx].push_back(email);
        }

        vector<vector<string>> ans;
        for (auto &pair : mergedAccounts)
        {
            int rootIdx = pair.first;
            vector<string> &emails = pair.second;
            sort(emails.begin(), emails.end());

            vector<string> account;
            account.push_back(accounts[rootIdx][0]);
            account.insert(account.end(), emails.begin(), emails.end());
            ans.push_back(account);
        }

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    vector<vector<string>> accounts1 = {
        {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
        {"John", "johnsmith@mail.com", "john00@mail.com"},
        {"Mary", "mary@mail.com"},
        {"John", "johnnybravo@mail.com"}};

    cout << "--- Test Case 1 ---\n";
    vector<vector<string>> res1 = solver.accountsMerge(accounts1);
    for (const auto &acc : res1)
    {
        for (const auto &str : acc)
        {
            cout << str << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    vector<vector<string>> accounts2 = {
        {"Gabe", "Gabe0@m.co", "Gabe3@m.co", "Gabe1@m.co"},
        {"Kevin", "Kevin3@m.co", "Kevin5@m.co", "Kevin0@m.co"},
        {"Ethan", "Ethan5@m.co", "Ethan4@m.co", "Ethan0@m.co"},
        {"Hanzo", "Hanzo3@m.co", "Hanzo1@m.co", "Hanzo0@m.co"},
        {"Fern", "Fern5@m.co", "Fern1@m.co", "Fern0@m.co"}};

    cout << "--- Test Case 2 ---\n";
    vector<vector<string>> res2 = solver.accountsMerge(accounts2);
    for (const auto &acc : res2)
    {
        for (const auto &str : acc)
        {
            cout << str << " ";
        }
        cout << "\n";
    }

    return 0;
}