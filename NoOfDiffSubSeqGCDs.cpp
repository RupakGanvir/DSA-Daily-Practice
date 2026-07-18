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
    int countDifferentSubsequenceGCDs(vector<int> &nums)
    {
        int max_val = 0;
        for (int num : nums)
        {
            if (num > max_val)
            {
                max_val = num;
            }
        }

        vector<bool> present(max_val + 1, false);
        for (int num : nums)
        {
            present[num] = true;
        }

        int count = 0;
        for (int x = 1; x <= max_val; ++x)
        {
            int current_gcd = 0;
            for (int y = x; y <= max_val; y += x)
            {
                if (present[y])
                {
                    current_gcd = getGcd(current_gcd, y);
                    if (current_gcd == x)
                    {
                        count++;
                        break;
                    }
                }
            }
        }

        return count;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    vector<int> nums1 = {6, 10, 3};
    cout << "--- Test Case 1 ---\n";
    cout << "Output: " << solver.countDifferentSubsequenceGCDs(nums1) << "\n\n";

    vector<int> nums2 = {5, 15, 40, 5, 6};
    cout << "--- Test Case 2 ---\n";
    cout << "Output: " << solver.countDifferentSubsequenceGCDs(nums2) << "\n\n";

    vector<int> nums3 = {4, 2, 8};
    cout << "--- Test Case 3 ---\n";
    cout << "Output: " << solver.countDifferentSubsequenceGCDs(nums3) << "\n";

    return 0;
}