#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> result;
        deque<int> dq;

        for (int i = 0; i < nums.size(); i++)
        {
            if (!dq.empty() && dq.front() == i - k)
            {
                dq.pop_front();
            }

            while (!dq.empty() && nums[dq.back()] <= nums[i])
            {
                dq.pop_back();
            }

            dq.push_back(i);

            if (i >= k - 1)
            {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};

int main()
{
    Solution solver;

    vector<int> nums1 = {1, 3, -1, -3, 5, 3, 6, 7};
    int k1 = 3;

    vector<int> nums2 = {1};
    int k2 = 1;

    vector<int> res1 = solver.maxSlidingWindow(nums1, k1);
    vector<int> res2 = solver.maxSlidingWindow(nums2, k2);

    cout << "--- Sliding Window Maximum Tests ---" << endl;

    cout << "Test 1: [";
    for (size_t i = 0; i < res1.size(); i++)
    {
        cout << res1[i] << (i < res1.size() - 1 ? ", " : "");
    }
    cout << "]" << endl;

    cout << "Test 2: [";
    for (size_t i = 0; i < res2.size(); i++)
    {
        cout << res2[i] << (i < res2.size() - 1 ? ", " : "");
    }
    cout << "]" << endl;

    return 0;
}