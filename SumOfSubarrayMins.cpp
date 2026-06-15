#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        long long MOD = 1000000007;
        vector<int> left(n), right(n);
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            left[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }

        while (!st.empty())
        {
            st.pop();
        }

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] > arr[i])
            {
                st.pop();
            }
            right[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }

        long long totalSum = 0;
        for (int i = 0; i < n; i++)
        {
            long long count = (left[i] * right[i]) % MOD;
            totalSum = (totalSum + (count * arr[i]) % MOD) % MOD;
        }

        return totalSum;
    }
};

int main()
{
    Solution solver;

    vector<int> arr1 = {3, 1, 2, 4};
    vector<int> arr2 = {11, 81, 94, 43, 3};

    cout << "--- Sum of Subarray Minimums Tests ---" << endl;
    cout << "Test 1: " << solver.sumSubarrayMins(arr1) << endl;
    cout << "Test 2: " << solver.sumSubarrayMins(arr2) << endl;

    return 0;
}