#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> resultArray(vector<int> &nums)
    {
        vector<int> arr1;
        vector<int> arr2;

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        for (int i = 2; i < nums.size(); ++i)
        {
            if (arr1.back() > arr2.back())
            {
                arr1.push_back(nums[i]);
            }
            else
            {
                arr2.push_back(nums[i]);
            }
        }

        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        return arr1;
    }
};

void printVector(const vector<int> &vec)
{
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << (i + 1 == vec.size() ? "" : ", ");
    }
    cout << "]\n";
}

int main()
{
    Solution solver;

    vector<int> nums1 = {2, 1, 3};
    printVector(solver.resultArray(nums1));

    vector<int> nums2 = {5, 4, 3, 8};
    printVector(solver.resultArray(nums2));

    return 0;
}