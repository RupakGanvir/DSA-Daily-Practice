#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findLatestStep(vector<int> &arr, int m)
    {
        int n = arr.size();
        if (m == n)
            return n;

        vector<int> length(n + 2, 0);
        int count = 0;
        int latest_step = -1;

        for (int i = 0; i < n; ++i)
        {
            int x = arr[i];
            int left_len = length[x - 1];
            int right_len = length[x + 1];

            int new_len = left_len + right_len + 1;

            length[x - left_len] = new_len;
            length[x + right_len] = new_len;

            if (left_len == m)
                count--;
            if (right_len == m)
                count--;
            if (new_len == m)
                count++;

            if (count > 0)
            {
                latest_step = i + 1;
            }
        }

        return latest_step;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    vector<int> arr1 = {3, 5, 1, 2, 4};
    int m1 = 1;
    cout << "--- Test Case 1 ---\n";
    cout << "Latest Step: " << solver.findLatestStep(arr1, m1) << "\n\n";

    vector<int> arr2 = {3, 1, 5, 4, 2};
    int m2 = 2;
    cout << "--- Test Case 2 ---\n";
    cout << "Latest Step: " << solver.findLatestStep(arr2, m2) << "\n\n";

    vector<int> arr3 = {1};
    int m3 = 1;
    cout << "--- Test Case 3 ---\n";
    cout << "Latest Step: " << solver.findLatestStep(arr3, m3) << "\n";

    return 0;
}