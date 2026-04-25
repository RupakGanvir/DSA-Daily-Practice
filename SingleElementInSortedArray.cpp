#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int left = 0;
        int right = nums.size() - 2;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == nums[mid ^ 1])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return nums[left];
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};

    cout << "The single element is: " << sol.singleNonDuplicate(nums) << endl;

    return 0;
}