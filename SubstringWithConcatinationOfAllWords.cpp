#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> res;
        if (s.empty() || words.empty())
            return res;

        int n = s.length(), num = words.size(), len = words[0].length();
        unordered_map<string, int> counts;
        for (string word : words)
            counts[word]++;

        for (int i = 0; i <= n - num * len; i++)
        {
            unordered_map<string, int> seen;
            int j = 0;
            while (j < num)
            {
                string word = s.substr(i + j * len, len);
                if (counts.find(word) != counts.end())
                {
                    seen[word]++;
                    if (seen[word] > counts[word])
                        break;
                }
                else
                {
                    break;
                }
                j++;
            }
            if (j == num)
                res.push_back(i);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    string s = "barfoothefoobarman";
    vector<string> words = {"foo", "bar"};

    vector<int> result = sol.findSubstring(s, words);

    cout << "Starting indices: ";
    for (int idx : result)
        cout << idx << " ";
    cout << endl;

    return 0;
}