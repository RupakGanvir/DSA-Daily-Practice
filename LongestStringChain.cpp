#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
private:
    static bool compareLength(const string &s1, const string &s2)
    {
        return s1.length() < s2.length();
    }

public:
    int longestStrChain(vector<string> &words)
    {
        // Sort the words by their lengths
        sort(words.begin(), words.end(), compareLength);

        unordered_map<string, int> dp;
        int max_chain = 1;

        for (const string &word : words)
        {
            dp[word] = 1;

            // Generate all possible predecessors by removing one character at a time
            for (size_t i = 0; i < word.length(); ++i)
            {
                string predecessor = word.substr(0, i) + word.substr(i + 1);

                if (dp.find(predecessor) != dp.end())
                {
                    dp[word] = max(dp[word], dp[predecessor] + 1);
                }
            }

            max_chain = max(max_chain, dp[word]);
        }

        return max_chain;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    vector<string> words1 = {"a", "b", "ba", "bca", "bda", "bdca"};
    cout << "--- Test Case 1 ---\n";
    cout << "Longest String Chain: " << solver.longestStrChain(words1) << "\n\n";

    vector<string> words2 = {"xbc", "pcxbcf", "xb", "cxbc", "pcxbc"};
    cout << "--- Test Case 2 ---\n";
    cout << "Longest String Chain: " << solver.longestStrChain(words2) << "\n\n";

    vector<string> words3 = {"abcd", "dbqca"};
    cout << "--- Test Case 3 ---\n";
    cout << "Longest String Chain: " << solver.longestStrChain(words3) << "\n";

    return 0;
}