#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost)
    {
        long long diff[2] = {0, 0};
        int n = s.size();
        for (int i = 0; i < n; ++i)
        {
            if (s[i] != t[i])
            {
                diff[s[i] - '0']++;
            }
        }

        long long fc = flipCost;
        long long sc = swapCost;
        long long cc = crossCost;

        long long mx = max(diff[0], diff[1]);
        long long mn = min(diff[0], diff[1]);

        long long ans = (mx + mn) * fc;
        ans = min(ans, mn * sc + (mx - mn) * fc);

        long long avg = (mx + mn) / 2;
        ans = min(ans, (avg - mn) * cc + avg * sc + (mx + mn - avg * 2) * fc);

        return ans;
    }
};

int main()
{
    Solution solver;

    string s1 = "01000", t1 = "10111";
    int fc1 = 10, sc1 = 2, cc1 = 2;
    cout << solver.minimumCost(s1, t1, fc1, sc1, cc1) << "\n";

    string s2 = "001", t2 = "110";
    int fc2 = 2, sc2 = 100, cc2 = 100;
    cout << solver.minimumCost(s2, t2, fc2, sc2, cc2) << "\n";

    string s3 = "1010", t3 = "1010";
    int fc3 = 5, sc3 = 5, cc3 = 5;
    cout << solver.minimumCost(s3, t3, fc3, sc3, cc3) << "\n";

    return 0;
}