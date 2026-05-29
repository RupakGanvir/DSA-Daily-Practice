#include <iostream>
#include <vector>
#include <algorithm> // Required for sorting

using namespace std;

class Solution
{
private:
    void backtrack(vector<int> &nums, vector<bool> &used, vector<int> &current_permutation, vector<vector<int>> &result)
    {

        if (current_permutation.size() == nums.size())
        {
            result.push_back(current_permutation);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {

            if (used[i])
            {
                continue;
            }

            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
            {
                continue;
            }

            used[i] = true;
            current_permutation.push_back(nums[i]);

            backtrack(nums, used, current_permutation, result);

            used[i] = false;
            current_permutation.pop_back();
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> current_permutation;
        vector<bool> used(nums.size(), false);

        sort(nums.begin(), nums.end());

        backtrack(nums, used, current_permutation, result);

        return result;
    }
};

// Helper function to print out a 2D vector cleanly
void printResult(const vector<vector<int>> &result)
{
    cout << "[\n";
    for (const auto &perm : result)
    {
        cout << "  [";
        for (int i = 0; i < perm.size(); i++)
        {
            cout << perm[i] << (i < perm.size() - 1 ? ", " : "");
        }
        cout << "]\n";
    }
    cout << "]\n";
}

int main()
{
    Solution solver;

    vector<int> nums1 = {1, 1, 2};
    cout << "--- Permutations II Tests ---" << endl;
    cout << "Input: [1, 1, 2]" << endl;
    vector<vector<int>> result1 = solver.permuteUnique(nums1);
    printResult(result1);

    cout << "\n-----------------------------\n";

    vector<int> nums2 = {1, 2, 3};
    cout << "Input: [1, 2, 3]" << endl;
    vector<vector<int>> result2 = solver.permuteUnique(nums2);
    printResult(result2);

    return 0;
}