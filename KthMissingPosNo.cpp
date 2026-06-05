#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int left = 0;
        int right = arr.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            int missing_numbers = arr[mid] - (mid + 1);

            if (missing_numbers < k)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return left + k;
    }
};

int main()
{
    Solution solver;

    vector<int> arr1 = {2, 3, 4, 7, 11};
    int k1 = 5;

    vector<int> arr2 = {1, 2, 3, 4};
    int k2 = 2;

    vector<int> arr3 = {4, 5, 6, 7};
    int k3 = 3;

    cout << "--- Kth Missing Positive Number Tests ---" << endl;
    cout << "Test 1: " << solver.findKthPositive(arr1, k1) << endl;
    cout << "Test 2: " << solver.findKthPositive(arr2, k2) << endl;
    cout << "Test 3: " << solver.findKthPositive(arr3, k3) << endl;

    return 0;
}