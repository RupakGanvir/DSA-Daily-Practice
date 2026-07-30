#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minimumPushes(string word)
    {
        int n = word.length();
        int ans = 0;
        int pushCount = 1;

        while (n > 0)
        {
            int letters = min(8, n);
            ans += letters * pushCount;
            n -= letters;
            pushCount++;
        }

        return ans;
    }
};

int main()
{
    Solution solver;

    cout << solver.minimumPushes("abcde") << "\n";
    cout << solver.minimumPushes("xycdefghij") << "\n";
    cout << solver.minimumPushes("abcdefghijklmnopqrstuvwxyz") << "\n";
    cout << solver.minimumPushes("a") << "\n";

    return 0;
}