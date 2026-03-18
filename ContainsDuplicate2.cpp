#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> lastSeen;

        for (int i = 0; i < nums.size(); i++)
        {
            int currentNum = nums[i];

            if (lastSeen.find(currentNum) != lastSeen.end())
            {
                if (i - lastSeen[currentNum] <= k)
                {
                    return true;
                }
            }

            lastSeen[currentNum] = i;
        }

        return false;
    }
};

int main()
{
    Solution sol;

    // Test Case 1: True (1 is at index 0 and 3, distance 3 <= 3)
    vector<int> nums1 = {1, 2, 3, 1};
    int k1 = 3;

    // Test Case 2: False (1 is at index 0 and 3, distance 3 > 2)
    vector<int> nums2 = {1, 2, 3, 1, 2, 3};
    int k2 = 2;

    cout << boolalpha;
    cout << "Test 1: " << sol.containsNearbyDuplicate(nums1, k1) << endl;
    cout << "Test 2: " << sol.containsNearbyDuplicate(nums2, k2) << endl;

    return 0;
}