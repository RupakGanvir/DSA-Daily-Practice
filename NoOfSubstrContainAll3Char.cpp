#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int count[3] = {0, 0, 0};
        int res = 0;
        int i = 0;
        int n = s.length();

        for (int j = 0; j < n; ++j)
        {
            count[s[j] - 'a']++;
            while (count[0] && count[1] && count[2])
            {
                res += n - j;
                count[s[i] - 'a']--;
                i++;
            }
        }
        return res;
    }
};

int main()
{
    Solution solver;
    string s = "abcabc";

    cout << "--- Number of Substrings Containing All 3 Characters Test ---" << endl;
    cout << "Result: " << solver.numberOfSubstrings(s) << endl;

    return 0;
}