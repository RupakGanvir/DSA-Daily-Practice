#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int candidate = 0;
        int count = 0;

        for (int num : nums)
        {
            if (count == 0)
            {
                candidate = num;
            }

            if (num == candidate)
            {
                count++;
            }
            else
            {
                count--;
            }
        }

        return candidate;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    cout << "The majority element is: " << sol.majorityElement(nums) << endl;

    return 0;
}