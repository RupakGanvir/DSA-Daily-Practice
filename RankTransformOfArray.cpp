#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        vector<int> sorted_arr = arr;
        sort(sorted_arr.begin(), sorted_arr.end());

        unordered_map<int, int> rank_map;
        int rank = 1;
        for (int num : sorted_arr)
        {
            if (rank_map.find(num) == rank_map.end())
            {
                rank_map[num] = rank++;
            }
        }

        vector<int> res(arr.size());
        for (size_t i = 0; i < arr.size(); ++i)
        {
            res[i] = rank_map[arr[i]];
        }

        return res;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    vector<int> arr1 = {40, 10, 20, 30};
    cout << "--- Test Case 1 ---\n";
    vector<int> res1 = solver.arrayRankTransform(arr1);
    for (int val : res1)
        cout << val << " ";
    cout << "\n\n";

    vector<int> arr2 = {100, 100, 100};
    cout << "--- Test Case 2 ---\n";
    vector<int> res2 = solver.arrayRankTransform(arr2);
    for (int val : res2)
        cout << val << " ";
    cout << "\n\n";

    vector<int> arr3 = {37, 12, 28, 9, 100, 56, 80, 5, 12};
    cout << "--- Test Case 3 ---\n";
    vector<int> res3 = solver.arrayRankTransform(arr3);
    for (int val : res3)
        cout << val << " ";
    cout << "\n";

    return 0;
}