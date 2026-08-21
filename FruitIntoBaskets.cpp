#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        unordered_map<int, int> fruit_counts;
        int max_fruits = 0;
        int left = 0;

        for (int right = 0; right < fruits.size(); ++right)
        {
            fruit_counts[fruits[right]]++;

            while (fruit_counts.size() > 2)
            {
                fruit_counts[fruits[left]]--;
                if (fruit_counts[fruits[left]] == 0)
                {
                    fruit_counts.erase(fruits[left]);
                }
                left++;
            }

            max_fruits = max(max_fruits, right - left + 1);
        }

        return max_fruits;
    }
};

int main()
{
    Solution solver;

    vector<int> fruits1 = {1, 2, 1};
    cout << solver.totalFruit(fruits1) << "\n";

    vector<int> fruits2 = {0, 1, 2, 2};
    cout << solver.totalFruit(fruits2) << "\n";

    vector<int> fruits3 = {1, 2, 3, 2, 2};
    cout << solver.totalFruit(fruits3) << "\n";

    return 0;
}