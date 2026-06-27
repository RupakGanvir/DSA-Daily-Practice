#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maximumLength(vector<int> &nums)
    {
        unordered_map<long long, int> freq;
        for (int n : nums)
        {
            freq[n]++;
        }

        int result = 1;

        if (freq.count(1))
        {
            int ones = freq[1];
            int maxOnes = (ones % 2 == 1) ? ones : ones - 1;
            result = max(result, maxOnes);
        }

        // Replaced structured bindings with standard C++11 iteration
        for (auto it = freq.begin(); it != freq.end(); ++it)
        {
            long long num = it->first;

            if (num == 1)
                continue;

            long long cur = num;
            int currentLength = 0;

            while (freq.count(cur) && freq[cur] >= 2)
            {
                currentLength += 2;
                cur = cur * cur;
            }

            if (freq.count(cur) && freq[cur] >= 1)
            {
                currentLength += 1;
            }
            else
            {
                currentLength -= 1;
            }

            result = max(result, currentLength);
        }

        return result;
    }
};

int main()
{
    Solution solver;

    vector<int> nums1 = {5, 4, 1, 2, 2};
    vector<int> nums2 = {1, 3, 2, 4};

    cout << "--- Maximum Number of Elements in Subset Tests ---" << endl;
    cout << "Test 1: " << solver.maximumLength(nums1) << endl;
    cout << "Test 2: " << solver.maximumLength(nums2) << endl;

    return 0;
}