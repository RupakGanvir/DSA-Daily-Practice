#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
private:
    bool isPalindrome(const string &s, int left, int right)
    {
        while (left < right)
        {
            if (s[left++] != s[right--])
            {
                return false;
            }
        }
        return true;
    }

public:
    vector<vector<int>> palindromePairs(vector<string> &words)
    {
        unordered_map<string, int> wordMap;
        vector<vector<int>> result;

        for (int i = 0; i < words.size(); ++i)
        {
            string reversedWord = words[i];
            reverse(reversedWord.begin(), reversedWord.end());
            wordMap[reversedWord] = i;
        }

        for (int i = 0; i < words.size(); ++i)
        {
            const string &word = words[i];
            int len = word.length();

            for (int j = 0; j <= len; ++j)
            {
                if (isPalindrome(word, 0, j - 1))
                {
                    string rightSuffix = word.substr(j);
                    if (wordMap.find(rightSuffix) != wordMap.end() && wordMap[rightSuffix] != i)
                    {
                        result.push_back({wordMap[rightSuffix], i});
                    }
                }

                if (j != len && isPalindrome(word, j, len - 1))
                {
                    string leftPrefix = word.substr(0, j);
                    if (wordMap.find(leftPrefix) != wordMap.end() && wordMap[leftPrefix] != i)
                    {
                        result.push_back({i, wordMap[leftPrefix]});
                    }
                }
            }
        }

        return result;
    }
};

void printResult(const vector<vector<int>> &result)
{
    for (const auto &pair : result)
    {
        cout << "[" << pair[0] << ", " << pair[1] << "] ";
    }
    cout << "\n";
}

int main()
{
    Solution solver;

    vector<string> words1 = {"abcd", "dcba", "lls", "s", "sssll"};
    cout << "Test Case 1:\n";
    printResult(solver.palindromePairs(words1));

    vector<string> words2 = {"bat", "tab", "cat"};
    cout << "Test Case 2:\n";
    printResult(solver.palindromePairs(words2));

    vector<string> words3 = {"a", ""};
    cout << "Test Case 3:\n";
    printResult(solver.palindromePairs(words3));

    vector<string> words4 = {"a", "abc", "aba", ""};
    cout << "Test Case 4:\n";
    printResult(solver.palindromePairs(words4));

    return 0;
}