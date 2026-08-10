#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        vector<int> last_occ(26, 0);
        vector<bool> seen(26, false);

        for (int i = 0; i < s.length(); ++i)
        {
            last_occ[s[i] - 'a'] = i;
        }

        string ans = "";
        for (int i = 0; i < s.length(); ++i)
        {
            char c = s[i];

            if (seen[c - 'a'])
                continue;

            while (!ans.empty() && ans.back() > c && last_occ[ans.back() - 'a'] > i)
            {
                seen[ans.back() - 'a'] = false;
                ans.pop_back();
            }

            ans.push_back(c);
            seen[c - 'a'] = true;
        }

        return ans;
    }
};

int main()
{
    Solution solver;

    cout << "\"" << solver.removeDuplicateLetters("bcabc") << "\"\n";
    cout << "\"" << solver.removeDuplicateLetters("cbacdcbc") << "\"\n";

    return 0;
}