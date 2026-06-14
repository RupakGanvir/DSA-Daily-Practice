#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> nextGreater;
        stack<int> st;

        for (int num : nums2)
        {
            while (!st.empty() && st.top() < num)
            {
                nextGreater[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        vector<int> result;
        for (int num : nums1)
        {
            if (nextGreater.count(num))
            {
                result.push_back(nextGreater[num]);
            }
            else
            {
                result.push_back(-1);
            }
        }

        return result;
    }
};

int main()
{
    Solution solver;

    vector<int> nums1_1 = {4, 1, 2};
    vector<int> nums2_1 = {1, 3, 4, 2};

    vector<int> nums1_2 = {2, 4};
    vector<int> nums2_2 = {1, 2, 3, 4};

    vector<int> res1 = solver.nextGreaterElement(nums1_1, nums2_1);
    vector<int> res2 = solver.nextGreaterElement(nums1_2, nums2_2);

    cout << "--- Next Greater Element I Tests ---" << endl;

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