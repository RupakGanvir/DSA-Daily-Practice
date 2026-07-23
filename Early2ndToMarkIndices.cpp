#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int earliestSecondToMarkIndices(vector<int> &nums, vector<int> &changeIndices)
    {
        int numIndices = nums.size();
        int numSeconds = changeIndices.size();

        int left = 1;
        int right = numSeconds;
        int earliestSecond = -1;

        auto canMarkAll = [&](int seconds)
        {
            vector<int> lastOccurrence(numIndices + 1, -1);
            for (int i = 0; i < seconds; ++i)
            {
                lastOccurrence[changeIndices[i]] = i;
            }

            for (int i = 1; i <= numIndices; ++i)
            {
                if (lastOccurrence[i] == -1)
                {
                    return false;
                }
            }

            int availableOperations = 0;
            for (int i = 0; i < seconds; ++i)
            {
                if (i == lastOccurrence[changeIndices[i]])
                {
                    if (availableOperations < nums[changeIndices[i] - 1])
                    {
                        return false;
                    }
                    availableOperations -= nums[changeIndices[i] - 1];
                }
                else
                {
                    availableOperations++;
                }
            }
            return true;
        };

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (canMarkAll(mid))
            {
                earliestSecond = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return earliestSecond;
    }
};

int main()
{
    Solution solver;

    vector<int> nums1 = {2, 2, 0};
    vector<int> changeIndices1 = {2, 2, 2, 2, 3, 2, 2, 1};
    cout << solver.earliestSecondToMarkIndices(nums1, changeIndices1) << "\n";

    vector<int> nums2 = {1, 3};
    vector<int> changeIndices2 = {1, 1, 1, 2, 1, 1, 1};
    cout << solver.earliestSecondToMarkIndices(nums2, changeIndices2) << "\n";

    vector<int> nums3 = {0, 1};
    vector<int> changeIndices3 = {2, 2, 2};
    cout << solver.earliestSecondToMarkIndices(nums3, changeIndices3) << "\n";

    vector<int> nums4 = {0, 0};
    vector<int> changeIndices4 = {1, 2};
    cout << solver.earliestSecondToMarkIndices(nums4, changeIndices4) << "\n";

    return 0;
}