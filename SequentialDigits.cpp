#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> sequentialDigits(int low, int high)
    {
        vector<int> ans;

        for (int len = 2; len <= 9; ++len)
        {
            for (int start = 1; start <= 10 - len; ++start)
            {
                int num = 0;
                for (int i = 0; i < len; ++i)
                {
                    num = num * 10 + (start + i);
                }

                if (num >= low && num <= high)
                {
                    ans.push_back(num);
                }
            }
        }

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    int low1 = 100;
    int high1 = 300;
    cout << "--- Test Case 1 ---\n";
    vector<int> res1 = solver.sequentialDigits(low1, high1);
    cout << "Sequential Digits: ";
    for (int val : res1)
        cout << val << " ";
    cout << "\n\n";

    int low2 = 1000;
    int high2 = 13000;
    cout << "--- Test Case 2 ---\n";
    vector<int> res2 = solver.sequentialDigits(low2, high2);
    cout << "Sequential Digits: ";
    for (int val : res2)
        cout << val << " ";
    cout << "\n\n";

    int low3 = 10;
    int high3 = 1000000000;
    cout << "--- Test Case 3 ---\n";
    vector<int> res3 = solver.sequentialDigits(low3, high3);
    cout << "Sequential Digits: ";
    for (int val : res3)
        cout << val << " ";
    cout << "\n";

    return 0;
}