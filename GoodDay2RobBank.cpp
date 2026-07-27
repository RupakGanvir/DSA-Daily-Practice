#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> goodDaysToRobBank(vector<int> &security, int time)
    {
        int totalDays = security.size();
        vector<int> goodDays;

        if (time == 0)
        {
            for (int i = 0; i < totalDays; i++)
            {
                goodDays.push_back(i);
            }
            return goodDays;
        }

        if (totalDays <= time * 2)
        {
            return goodDays;
        }

        vector<int> consecutiveNonIncreasing(totalDays, 0);
        vector<int> consecutiveNonDecreasing(totalDays, 0);

        for (int i = 1; i < totalDays; i++)
        {
            if (security[i] <= security[i - 1])
            {
                consecutiveNonIncreasing[i] = consecutiveNonIncreasing[i - 1] + 1;
            }
        }

        for (int i = totalDays - 2; i >= 0; i--)
        {
            if (security[i] <= security[i + 1])
            {
                consecutiveNonDecreasing[i] = consecutiveNonDecreasing[i + 1] + 1;
            }
        }

        for (int i = time; i < totalDays - time; i++)
        {
            if (consecutiveNonIncreasing[i] >= time && consecutiveNonDecreasing[i] >= time)
            {
                goodDays.push_back(i);
            }
        }

        return goodDays;
    }
};

int main()
{
    Solution solver;

    vector<int> security1 = {5, 3, 3, 3, 5, 6, 2};
    int time1 = 2;
    vector<int> result1 = solver.goodDaysToRobBank(security1, time1);
    for (int day : result1)
    {
        cout << day << " ";
    }
    cout << "\n";

    vector<int> security2 = {1, 1, 1, 1, 1};
    int time2 = 0;
    vector<int> result2 = solver.goodDaysToRobBank(security2, time2);
    for (int day : result2)
    {
        cout << day << " ";
    }
    cout << "\n";

    vector<int> security3 = {1, 2, 3, 4, 5, 6};
    int time3 = 2;
    vector<int> result3 = solver.goodDaysToRobBank(security3, time3);
    for (int day : result3)
    {
        cout << day << " ";
    }
    cout << "\n";

    vector<int> security4 = {4, 3, 2, 1};
    int time4 = 1;
    vector<int> result4 = solver.goodDaysToRobBank(security4, time4);
    for (int day : result4)
    {
        cout << day << " ";
    }
    cout << "\n";

    return 0;
}