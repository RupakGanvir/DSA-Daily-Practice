#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void backtrack(int start, vector<int> &nums, vector<int> &current, vector<vector<int>> &result)
    {
        result.push_back(current);

        for (int i = start; i < nums.size(); i++)
        {
            if (i > start && nums[i] == nums[i - 1])
            {
                continue;
            }

            current.push_back(nums[i]);

            backtrack(i + 1, nums, current, result);

            current.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> current;

        sort(nums.begin(), nums.end());

        backtrack(0, nums, current, result);
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> result = sol.subsetsWithDup(nums);

    cout << "Unique Subsets:" << endl;
    for (const auto &subset : result)
    {
        cout << "[";
        for (int i = 0; i < subset.size(); i++)
        {
            cout << subset[i] << (i == subset.size() - 1 ? "" : ", ");
        }
        cout << "]" << endl;
    }

    return 0;
}