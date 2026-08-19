#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    // Custom GCD implementation
    int gcd(int a, int b)
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
    bool isGoodArray(vector<int> &nums)
    {
        int g = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            g = gcd(g, nums[i]);
            if (g == 1)
            {
                return true;
            }
        }
        return g == 1;
    }
};

int main()
{
    Solution solver;

    vector<int> nums1 = {12, 5, 7, 23};
    cout << (solver.isGoodArray(nums1) ? "true" : "false") << "\n";

    vector<int> nums2 = {29, 6, 10};
    cout << (solver.isGoodArray(nums2) ? "true" : "false") << "\n";

    vector<int> nums3 = {3, 6};
    cout << (solver.isGoodArray(nums3) ? "true" : "false") << "\n";

    return 0;
}