#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution
{
private:
    bool solve(vector<double> &nums)
    {
        if (nums.size() == 1)
        {
            return abs(nums[0] - 24.0) < 1e-6;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = 0; j < nums.size(); ++j)
            {
                if (i != j)
                {
                    vector<double> nextNums;
                    for (int k = 0; k < nums.size(); ++k)
                    {
                        if (k != i && k != j)
                        {
                            nextNums.push_back(nums[k]);
                        }
                    }

                    vector<double> results = {
                        nums[i] + nums[j],
                        nums[i] - nums[j],
                        nums[i] * nums[j]};

                    if (abs(nums[j]) > 1e-6)
                    {
                        results.push_back(nums[i] / nums[j]);
                    }

                    for (double res : results)
                    {
                        nextNums.push_back(res);
                        if (solve(nextNums))
                        {
                            return true;
                        }
                        nextNums.pop_back();
                    }
                }
            }
        }

        return false;
    }

public:
    bool judgePoint24(vector<int> &cards)
    {
        vector<double> nums(cards.begin(), cards.end());
        return solve(nums);
    }
};

int main()
{
    Solution solver;

    vector<int> cards1 = {4, 1, 8, 7};
    cout << (solver.judgePoint24(cards1) ? "true" : "false") << "\n";

    vector<int> cards2 = {1, 2, 1, 2};
    cout << (solver.judgePoint24(cards2) ? "true" : "false") << "\n";

    vector<int> cards3 = {3, 3, 8, 8};
    cout << (solver.judgePoint24(cards3) ? "true" : "false") << "\n";

    vector<int> cards4 = {1, 3, 4, 6};
    cout << (solver.judgePoint24(cards4) ? "true" : "false") << "\n";

    return 0;
}