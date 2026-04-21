#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void backtrack(int index, int target, vector<int> &candidates, vector<int> &current, vector<vector<int>> &result)
    {
        if (target == 0)
        {
            result.push_back(current);
            return;
        }

        if (target < 0 || index == candidates.size())
        {
            return;
        }

        current.push_back(candidates[index]);
        backtrack(index, target - candidates[index], candidates, current, result);

        current.pop_back();

        backtrack(index + 1, target, candidates, current, result);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(0, target, candidates, current, result);
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> result = sol.combinationSum(candidates, target);

    cout << "Combinations that sum to " << target << ":" << endl;
    for (const auto &combo : result)
    {
        cout << "[";
        for (int i = 0; i < combo.size(); i++)
        {
            cout << combo[i] << (i == combo.size() - 1 ? "" : ", ");
        }
        cout << "]" << endl;
    }

    return 0;
}