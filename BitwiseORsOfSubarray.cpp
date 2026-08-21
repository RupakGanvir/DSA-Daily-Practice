#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int subarrayBitwiseORs(vector<int> &arr)
    {
        vector<int> res;
        int left = 0, right = 0;

        for (int a : arr)
        {
            int new_right = res.size();
            res.push_back(a);

            for (int i = left; i < right; ++i)
            {
                if (res.back() != (res[i] | a))
                {
                    res.push_back(res[i] | a);
                }
            }

            left = new_right;
            right = res.size();
        }

        return unordered_set<int>(res.begin(), res.end()).size();
    }
};

int main()
{
    Solution solver;

    vector<int> arr1 = {0};
    cout << solver.subarrayBitwiseORs(arr1) << "\n";

    vector<int> arr2 = {1, 1, 2};
    cout << solver.subarrayBitwiseORs(arr2) << "\n";

    vector<int> arr3 = {1, 2, 4};
    cout << solver.subarrayBitwiseORs(arr3) << "\n";

    return 0;
}