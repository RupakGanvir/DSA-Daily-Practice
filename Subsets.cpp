#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    void backtrack(const vector<int> &nums, int index, vector<int> &current, vector<vector<int>> &result)
    {
        result.push_back(current);

        for (int i = index; i < nums.size(); i++)
        {
            current.push_back(nums[i]);
            backtrack(nums, i + 1, current, result);
            current.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(nums, 0, current, result);
        return result;
    }
};

int main()
{
    Solution solver;

    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {0};

    vector<vector<int>> res1 = solver.subsets(nums1);
    vector<vector<int>> res2 = solver.subsets(nums2);

    cout << "--- Subsets Tests ---" << endl;

    cout << "Test 1:" << endl;
    for (const auto &sub : res1)
    {
        cout << "  [";
        for (size_t i = 0; i < sub.size(); i++)
        {
            cout << sub[i] << (i < sub.size() - 1 ? ", " : "");
        }
        cout << "]" << endl;
    }

    cout << "Test 2:" << endl;
    for (const auto &sub : res2)
    {
        cout << "  [";
        for (size_t i = 0; i < sub.size(); i++)
        {
            cout << sub[i] << (i < sub.size() - 1 ? ", " : "");
        }
        cout << "]" << endl;
    }

    return 0;
}