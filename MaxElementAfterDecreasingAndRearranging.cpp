#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        arr[0] = 1;

        for (size_t i = 1; i < arr.size(); ++i)
        {
            if (arr[i] > arr[i - 1] + 1)
            {
                arr[i] = arr[i - 1] + 1;
            }
        }

        return arr.back();
    }
};

int main()
{
    Solution solver;
    vector<int> arr = {2, 2, 1, 2, 1};

    cout << "--- Maximum Element After Decrementing and Rearranging Test ---" << endl;
    cout << "Result: " << solver.maximumElementAfterDecrementingAndRearranging(arr) << endl;

    return 0;
}