#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
    {
        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<>> pq;
        int n = arr.size();

        for (int j = 1; j < n; ++j)
        {
            pq.push({(double)arr[0] / arr[j], {0, j}});
        }

        while (--k > 0)
        {
            auto top = pq.top();
            pq.pop();
            int i = top.second.first;
            int j = top.second.second;

            if (i + 1 < j)
            {
                pq.push({(double)arr[i + 1] / arr[j], {i + 1, j}});
            }
        }

        auto result = pq.top();
        return {arr[result.second.first], arr[result.second.second]};
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

    vector<int> arr1 = {1, 2, 3, 5};
    int k1 = 3;
    printVector(solver.kthSmallestPrimeFraction(arr1, k1));

    vector<int> arr2 = {1, 7};
    int k2 = 1;
    printVector(solver.kthSmallestPrimeFraction(arr2, k2));

    return 0;
}