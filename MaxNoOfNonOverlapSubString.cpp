#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
private:
    int check(const string &s, int i, const vector<int> &first, const vector<int> &last)
    {
        int right = last[s[i] - 'a'];
        for (int j = i; j <= right; ++j)
        {
            if (first[s[j] - 'a'] < i)
                return -1;
            right = max(right, last[s[j] - 'a']);
        }
        return right;
    }

public:
    vector<string> maxNumOfSubstrings(string s)
    {
        int n = s.length();
        vector<int> first(26, -1);
        vector<int> last(26, -1);

        for (int i = 0; i < n; ++i)
        {
            if (first[s[i] - 'a'] == -1)
            {
                first[s[i] - 'a'] = i;
            }
            last[s[i] - 'a'] = i;
        }

        vector<string> ans;
        int right = -1;

        for (int i = 0; i < n; ++i)
        {
            if (i == first[s[i] - 'a'])
            {
                int new_right = check(s, i, first, last);
                if (new_right != -1)
                {
                    if (i > right)
                    {
                        ans.push_back("");
                    }
                    right = new_right;
                    ans.back() = s.substr(i, right - i + 1);
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

    string s1 = "adefaddaccc";
    cout << "--- Test Case 1 ---\n";
    vector<string> res1 = solver.maxNumOfSubstrings(s1);
    cout << "Substrings: ";
    for (const string &str : res1)
        cout << "\"" << str << "\" ";
    cout << "\n\n";

    string s2 = "abbac";
    cout << "--- Test Case 2 ---\n";
    vector<string> res2 = solver.maxNumOfSubstrings(s2);
    cout << "Substrings: ";
    for (const string &str : res2)
        cout << "\"" << str << "\" ";
    cout << "\n\n";

    string s3 = "cabcccbaa";
    cout << "--- Test Case 3 ---\n";
    vector<string> res3 = solver.maxNumOfSubstrings(s3);
    cout << "Substrings: ";
    for (const string &str : res3)
        cout << "\"" << str << "\" ";
    cout << "\n";

    return 0;
}