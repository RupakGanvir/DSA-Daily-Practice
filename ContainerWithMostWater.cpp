#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;

        while (left < right)
        {
            int currentHeight = min(height[left], height[right]);
            int width = right - left;
            int currentArea = currentHeight * width;

            maxWater = max(maxWater, currentArea);

            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return maxWater;
    }
};

int main()
{
    Solution sol;
    vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Maximum water container: " << sol.maxArea(heights) << " units" << endl;
    return 0;
}