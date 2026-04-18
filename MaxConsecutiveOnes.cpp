#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int max_ones = 0;
        int current_count = 0;

        for (int num : nums)
        {
            if (num == 1)
            {
                current_count++;
                max_ones = max(max_ones, current_count);
            }
            else
            {
                current_count = 0;
            }
        }

        return max_ones;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 1, 0, 1, 1, 1};

    int result = sol.findMaxConsecutiveOnes(nums);
    cout << "Max consecutive ones: " << result << endl;

    return 0;
}