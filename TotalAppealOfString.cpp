#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    long long appealSum(string s)
    {
        vector<int> last_pos(26, -1);
        long long total_appeal = 0;
        long long current_appeal = 0;

        for (int i = 0; i < s.length(); ++i)
        {
            current_appeal += i - last_pos[s[i] - 'a'];
            total_appeal += current_appeal;
            last_pos[s[i] - 'a'] = i;
        }

        return total_appeal;
    }
};

int main()
{
    Solution solver;

    string s1 = "abbca";
    cout << solver.appealSum(s1) << "\n";

    string s2 = "code";
    cout << solver.appealSum(s2) << "\n";

    return 0;
}