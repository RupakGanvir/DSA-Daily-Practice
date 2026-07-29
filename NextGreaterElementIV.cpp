#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> secondGreaterElement(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, -1);
        vector<int> s1, s2, temp;

        for (int i = 0; i < n; i++)
        {
            while (!s2.empty() && nums[s2.back()] < nums[i])
            {
                ans[s2.back()] = nums[i];
                s2.pop_back();
            }

            while (!s1.empty() && nums[s1.back()] < nums[i])
            {
                temp.push_back(s1.back());
                s1.pop_back();
            }

            while (!temp.empty())
            {
                s2.push_back(temp.back());
                temp.pop_back();
            }

            s1.push_back(i);
        }

        return ans;
    }
};

void printVector(const vector<int> &v)
{
    for (int num : v)
    {
        cout << num << " ";
    }
    cout << "\n";
}

int main()
{
    Solution solver;

    vector<int> nums1 = {2, 4, 0, 9, 6};
    printVector(solver.secondGreaterElement(nums1));

    vector<int> nums2 = {3, 3};
    printVector(solver.secondGreaterElement(nums2));

    vector<int> nums3 = {1, 2, 4, 3};
    printVector(solver.secondGreaterElement(nums3));

    vector<int> nums4 = {10, 5, 6, 4, 7};
    printVector(solver.secondGreaterElement(nums4));

    return 0;
}