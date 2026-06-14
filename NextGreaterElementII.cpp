#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> st;

        for (int i = 2 * n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= nums[i % n])
            {
                st.pop();
            }

            if (i < n)
            {
                if (!st.empty())
                {
                    result[i] = st.top();
                }
            }

            st.push(nums[i % n]);
        }

        return result;
    }
};

int main()
{
    Solution solver;

    vector<int> nums1 = {1, 2, 1};
    vector<int> nums2 = {1, 2, 3, 4, 3};

    vector<int> res1 = solver.nextGreaterElements(nums1);
    vector<int> res2 = solver.nextGreaterElements(nums2);

    cout << "--- Next Greater Element II Tests ---" << endl;

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