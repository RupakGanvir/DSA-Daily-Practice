#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    long long subArrayRanges(vector<int> &nums)
    {
        int n = nums.size();
        long long sumMax = 0;
        long long sumMin = 0;
        stack<int> st;

        for (int i = 0; i <= n; i++)
        {
            while (!st.empty() && (i == n || nums[st.top()] >= nums[i]))
            {
                int mid = st.top();
                st.pop();
                int left = st.empty() ? -1 : st.top();
                sumMin += (long long)nums[mid] * (mid - left) * (i - mid);
            }
            st.push(i);
        }

        while (!st.empty())
        {
            st.pop();
        }

        for (int i = 0; i <= n; i++)
        {
            while (!st.empty() && (i == n || nums[st.top()] <= nums[i]))
            {
                int mid = st.top();
                st.pop();
                int left = st.empty() ? -1 : st.top();
                sumMax += (long long)nums[mid] * (mid - left) * (i - mid);
            }
            st.push(i);
        }

        return sumMax - sumMin;
    }
};

int main()
{
    Solution solver;

    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {1, 3, 3};
    vector<int> nums3 = {4, -2, -3, 4, 1};

    cout << "--- Sum of Subarray Ranges Tests ---" << endl;
    cout << "Test 1: " << solver.subArrayRanges(nums1) << endl;
    cout << "Test 2: " << solver.subArrayRanges(nums2) << endl;
    cout << "Test 3: " << solver.subArrayRanges(nums3) << endl;

    return 0;
}