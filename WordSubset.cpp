#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {
        vector<int> maxFreq(26, 0);

        for (const string &word : words2)
        {
            vector<int> currentFreq(26, 0);
            for (char c : word)
            {
                currentFreq[c - 'a']++;
            }
            for (int i = 0; i < 26; i++)
            {
                maxFreq[i] = max(maxFreq[i], currentFreq[i]);
            }
        }

        vector<string> result;
        for (const string &word : words1)
        {
            vector<int> currentFreq(26, 0);
            for (char c : word)
            {
                currentFreq[c - 'a']++;
            }

            bool isUniversal = true;
            for (int i = 0; i < 26; i++)
            {
                if (currentFreq[i] < maxFreq[i])
                {
                    isUniversal = false;
                    break;
                }
            }

            if (isUniversal)
            {
                result.push_back(word);
            }
        }

        return result;
    }
};

int main()
{
    Solution solver;

    vector<string> words1_1 = {"amazon", "apple", "facebook", "google", "leetcode"};
    vector<string> words2_1 = {"e", "o"};
    vector<string> res1 = solver.wordSubsets(words1_1, words2_1);
    for (const string &s : res1)
        cout << s << " ";
    cout << "\n";

    vector<string> words1_2 = {"amazon", "apple", "facebook", "google", "leetcode"};
    vector<string> words2_2 = {"l", "e"};
    vector<string> res2 = solver.wordSubsets(words1_2, words2_2);
    for (const string &s : res2)
        cout << s << " ";
    cout << "\n";

    vector<string> words1_3 = {"amazon", "apple", "facebook", "google", "leetcode"};
    vector<string> words2_3 = {"e", "oo"};
    vector<string> res3 = solver.wordSubsets(words1_3, words2_3);
    for (const string &s : res3)
        cout << s << " ";
    cout << "\n";

    vector<string> words1_4 = {"amazon", "apple", "facebook", "google", "leetcode"};
    vector<string> words2_4 = {"lo", "eo"};
    vector<string> res4 = solver.wordSubsets(words1_4, words2_4);
    for (const string &s : res4)
        cout << s << " ";
    cout << "\n";

    return 0;
}