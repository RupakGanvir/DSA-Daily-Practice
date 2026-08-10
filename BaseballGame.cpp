#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int calPoints(vector<string> &operations)
    {
        vector<int> scores;

        for (const string &op : operations)
        {
            if (op == "+")
            {
                int n = scores.size();
                scores.push_back(scores[n - 1] + scores[n - 2]);
            }
            else if (op == "D")
            {
                scores.push_back(scores.back() * 2);
            }
            else if (op == "C")
            {
                scores.pop_back();
            }
            else
            {
                scores.push_back(stoi(op));
            }
        }

        int totalSum = 0;
        for (int score : scores)
        {
            totalSum += score;
        }

        return totalSum;
    }
};

int main()
{
    Solution solver;

    vector<string> ops1 = {"5", "2", "C", "D", "+"};
    cout << solver.calPoints(ops1) << "\n";

    vector<string> ops2 = {"5", "-2", "4", "C", "D", "9", "+", "+"};
    cout << solver.calPoints(ops2) << "\n";

    vector<string> ops3 = {"1", "C"};
    cout << solver.calPoints(ops3) << "\n";

    return 0;
}