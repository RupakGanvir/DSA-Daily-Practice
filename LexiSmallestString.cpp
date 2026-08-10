#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string lexSmallestAfterDeletion(string s)
    {
        vector<int> cnt(26, 0);
        for (char c : s)
        {
            cnt[c - 'a']++;
        }

        string stk = "";
        for (char c : s)
        {
            while (!stk.empty() && stk.back() > c && cnt[stk.back() - 'a'] > 1)
            {
                cnt[stk.back() - 'a']--;
                stk.pop_back();
            }
            stk.push_back(c);
        }

        while (!stk.empty() && cnt[stk.back() - 'a'] > 1)
        {
            cnt[stk.back() - 'a']--;
            stk.pop_back();
        }

        return stk;
    }
};

int main()
{
    Solution solver;

    cout << "\"" << solver.lexSmallestAfterDeletion("aaccb") << "\"\n";
    cout << "\"" << solver.lexSmallestAfterDeletion("z") << "\"\n";
    cout << "\"" << solver.lexSmallestAfterDeletion("abacaba") << "\"\n";
    cout << "\"" << solver.lexSmallestAfterDeletion("cbacdcb") << "\"\n";

    return 0;
}