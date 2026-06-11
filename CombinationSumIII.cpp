#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    void backtrack(int k, int n, int start, vector<int> &current, vector<vector<int>> &result)
    {
        if (current.size() == k && n == 0)
        {
            result.push_back(current);
            return;
        }
        if (current.size() == k || n < 0)
        {
            return;
        }

        for (int i = start; i <= 9; i++)
        {
            current.push_back(i);
            backtrack(k, n - i, i + 1, current, result);
            current.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(k, n, 1, current, result);
        return result;
    }
};

int main()
{
    Solution solver;

    int k1 = 3, n1 = 7;
    int k2 = 3, n2 = 9;
    int k3 = 4, n3 = 1;

    vector<vector<int>> res1 = solver.combinationSum3(k1, n1);
    vector<vector<int>> res2 = solver.combinationSum3(k2, n2);
    vector<vector<int>> res3 = solver.combinationSum3(k3, n3);

    cout << "--- Combination Sum III Tests ---" << endl;

    cout << "Test 1:" << endl;
    for (const auto &comb : res1)
    {
        cout << "  [";
        for (size_t i = 0; i < comb.size(); i++)
        {
            cout << comb[i] << (i < comb.size() - 1 ? ", " : "");
        }
        cout << "]" << endl;
    }

    cout << "Test 2:" << endl;
    for (const auto &comb : res2)
    {
        cout << "  [";
        for (size_t i = 0; i < comb.size(); i++)
        {
            cout << comb[i] << (i < comb.size() - 1 ? ", " : "");
        }
        cout << "]" << endl;
    }

    cout << "Test 3:" << endl;
    for (const auto &comb : res3)
    {
        cout << "  [";
        for (size_t i = 0; i < comb.size(); i++)
        {
            cout << comb[i] << (i < comb.size() - 1 ? ", " : "");
        }
        cout << "]" << endl;
    }

    return 0;
}