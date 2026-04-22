#include <iostream>
#include <vector>
#include <algorithm>

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

        for (int i = index; i < candidates.size(); i++)
        {
            if (candidates[i] > target)
                break;

            if (i > index && candidates[i] == candidates[i - 1])
                continue;

            current.push_back(candidates[i]);

            backtrack(i + 1, target - candidates[i], candidates, current, result);

            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> current;

        sort(candidates.begin(), candidates.end());

        backtrack(0, target, candidates, current, result);
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    vector<vector<int>> result = sol.combinationSum2(candidates, target);

    cout << "Unique combinations for target " << target << ":" << endl;
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