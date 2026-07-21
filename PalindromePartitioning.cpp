#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
private:
    bool isPalindrome(const string &s, int left, int right)
    {
        while (left < right)
        {
            if (s[left] != s[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    void backtrack(const string &s, int start, vector<string> &path, vector<vector<string>> &res)
    {
        if (start == s.length())
        {
            res.push_back(path);
            return;
        }

        for (int i = start; i < s.length(); ++i)
        {
            if (isPalindrome(s, start, i))
            {
                path.push_back(s.substr(start, i - start + 1));
                backtrack(s, i + 1, path, res);
                path.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        vector<string> path;
        backtrack(s, 0, path, res);
        return res;
    }
};

void printResult(const vector<vector<string>> &res)
{
    cout << "[\n";
    for (size_t i = 0; i < res.size(); ++i)
    {
        cout << "  [";
        for (size_t j = 0; j < res[i].size(); ++j)
        {
            cout << "\"" << res[i][j] << "\"" << (j == res[i].size() - 1 ? "" : ", ");
        }
        cout << "]" << (i == res.size() - 1 ? "" : ",") << "\n";
    }
    cout << "]\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    string s1 = "aab";
    cout << "--- Test Case 1 ---\n";
    cout << "Output: \n";
    printResult(solver.partition(s1));
    cout << "\n";

    string s2 = "a";
    cout << "--- Test Case 2 ---\n";
    cout << "Output: \n";
    printResult(solver.partition(s2));
    cout << "\n";

    string s3 = "efe";
    cout << "--- Test Case 3 ---\n";
    cout << "Output: \n";
    printResult(solver.partition(s3));

    return 0;
}