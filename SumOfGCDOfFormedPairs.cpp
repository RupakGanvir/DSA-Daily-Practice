#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
private:
    int getGcd(int a, int b)
    {
        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

public:
    long long gcdSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> prefixGcd(n);
        int mx = 0;

        for (int i = 0; i < n; ++i)
        {
            mx = max(mx, nums[i]);
            prefixGcd[i] = getGcd(nums[i], mx);
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        long long sum = 0;
        int left = 0;
        int right = n - 1;

        while (left < right)
        {
            sum += getGcd(prefixGcd[left], prefixGcd[right]);
            left++;
            right--;
        }

        return sum;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    vector<int> nums1 = {2, 6, 4};
    cout << "--- Test Case 1 ---\n";
    cout << "Output: " << solver.gcdSum(nums1) << "\n\n";

    vector<int> nums2 = {3, 6, 2, 8};
    cout << "--- Test Case 2 ---\n";
    cout << "Output: " << solver.gcdSum(nums2) << "\n\n";

    vector<int> nums3 = {5, 10, 15};
    cout << "--- Test Case 3 ---\n";
    cout << "Output: " << solver.gcdSum(nums3) << "\n";

    return 0;
}