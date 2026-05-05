#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return {};

        vector<string> mapping = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector<string> result;
        string current;
        backtrack(0, digits, current, result, mapping);
        return result;
    }

private:
    void backtrack(int index, string &digits, string &current, vector<string> &result, vector<string> &mapping)
    {
        if (index == digits.length())
        {
            result.push_back(current);
            return;
        }

        string letters = mapping[digits[index] - '0'];

        for (char c : letters)
        {
            current.push_back(c);
            backtrack(index + 1, digits, current, result, mapping);
            current.pop_back();
        }
    }
};

int main()
{
    Solution sol;
    string input = "23";
    vector<string> combs = sol.letterCombinations(input);

    cout << "Combinations for '" << input << "':" << endl;
    for (const string &s : combs)
    {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}