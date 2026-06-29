#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int numOfStrings(vector<string> &patterns, string word)
    {
        int count = 0;
        for (const string &s : patterns)
        {
            if (word.find(s) != string::npos)
            {
                count++;
            }
        }
        return count;
    }
};

int main()
{
    Solution solver;
    vector<string> patterns = {"a", "abc", "bc", "d"};
    string word = "abc";

    cout << "--- Number of Strings that Appear as Substring in Word Test ---" << endl;
    cout << "Count: " << solver.numOfStrings(patterns, word) << endl;

    return 0;
}