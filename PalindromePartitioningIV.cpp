#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    bool checkPartitioning(string s)
    {
        int n = s.length();
        vector<vector<bool>> isPal(n, vector<bool>(n, false));

        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = i; j < n; ++j)
            {
                if (s[i] == s[j])
                {
                    if (j - i <= 2)
                    {
                        isPal[i][j] = true;
                    }
                    else
                    {
                        isPal[i][j] = isPal[i + 1][j - 1];
                    }
                }
            }
        }

        for (int i = 0; i < n - 2; ++i)
        {
            if (isPal[0][i])
            {
                for (int j = i + 1; j < n - 1; ++j)
                {
                    if (isPal[i + 1][j] && isPal[j + 1][n - 1])
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << boolalpha;

    Solution solver;

    string s1 = "abcbdd";
    cout << "--- Test Case 1 ---\n";
    cout << "String: " << s1 << "\n";
    cout << "Output: " << solver.checkPartitioning(s1) << "\n\n";

    string s2 = "bcbddxy";
    cout << "--- Test Case 2 ---\n";
    cout << "String: " << s2 << "\n";
    cout << "Output: " << solver.checkPartitioning(s2) << "\n\n";

    string s3 = "ababa";
    cout << "--- Test Case 3 ---\n";
    cout << "String: " << s3 << "\n";
    cout << "Output: " << solver.checkPartitioning(s3) << "\n";

    return 0;
}