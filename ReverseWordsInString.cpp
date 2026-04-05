#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        stringstream ss(s);
        string word;
        vector<string> words;

        while (ss >> word)
        {
            words.push_back(word);
        }

        reverse(words.begin(), words.end());

        string result = "";
        for (int i = 0; i < words.size(); i++)
        {
            result += words[i];
            if (i != words.size() - 1)
            {
                result += " ";
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    string s = "  hello world  ";
    cout << "Original: '" << s << "'" << endl;
    cout << "Reversed: '" << sol.reverseWords(s) << "'" << endl;
    return 0;
}