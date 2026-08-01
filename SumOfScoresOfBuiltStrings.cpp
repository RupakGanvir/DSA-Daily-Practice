#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    long long sumScores(string s)
    {
        int n = s.length();
        vector<int> z(n, 0);
        int l = 0, r = 0;

        long long total_score = n;

        for (int i = 1; i < n; ++i)
        {
            if (i <= r)
            {
                z[i] = min(r - i + 1, z[i - l]);
            }

            while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            {
                z[i]++;
            }

            if (i + z[i] - 1 > r)
            {
                l = i;
                r = i + z[i] - 1;
            }

            total_score += z[i];
        }

        return total_score;
    }
};

int main()
{
    Solution solver;

    cout << solver.sumScores("babab") << "\n";
    cout << solver.sumScores("azbazbzaz") << "\n";
    cout << solver.sumScores("a") << "\n";
    cout << solver.sumScores("aaaaa") << "\n";

    return 0;
}