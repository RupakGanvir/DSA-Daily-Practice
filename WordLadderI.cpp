#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end())
            return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while (!q.empty())
        {
            string currentWord = q.front().first;
            int level = q.front().second;
            q.pop();

            if (currentWord == endWord)
                return level;

            for (int i = 0; i < currentWord.length(); ++i)
            {
                char originalChar = currentWord[i];

                for (char c = 'a'; c <= 'z'; ++c)
                {
                    currentWord[i] = c;
                    if (wordSet.find(currentWord) != wordSet.end())
                    {
                        q.push({currentWord, level + 1});
                        wordSet.erase(currentWord);
                    }
                }
                currentWord[i] = originalChar;
            }
        }

        return 0;
    }
};

int main()
{
    Solution solver;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    cout << "Shortest transformation length: " << solver.ladderLength(beginWord, endWord, wordList) << endl;

    return 0;
}