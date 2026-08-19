#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> numMovesStonesII(vector<int> &stones)
    {
        sort(stones.begin(), stones.end());
        int n = stones.size();

        int max_moves = max(stones[n - 1] - stones[1] - n + 2, stones[n - 2] - stones[0] - n + 2);

        int min_moves = n;
        int i = 0;

        for (int j = 0; j < n; ++j)
        {
            while (stones[j] - stones[i] >= n)
            {
                i++;
            }

            if (j - i + 1 == n - 1 && stones[j] - stones[i] == n - 2)
            {
                min_moves = min(min_moves, 2);
            }
            else
            {
                min_moves = min(min_moves, n - (j - i + 1));
            }
        }

        return {min_moves, max_moves};
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

    vector<int> stones1 = {7, 4, 9};
    printVector(solver.numMovesStonesII(stones1));

    vector<int> stones2 = {6, 5, 4, 3, 10};
    printVector(solver.numMovesStonesII(stones2));

    vector<int> stones3 = {100, 101, 104, 102, 103};
    printVector(solver.numMovesStonesII(stones3));

    return 0;
}