#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    string mapWordWeights(vector<string> &words, vector<int> &weights)
    {
        string result = "";

        for (const string &word : words)
        {
            int totalWeight = 0;
            for (char c : word)
            {
                totalWeight += weights[c - 'a'];
            }
            int remainder = totalWeight % 26;
            char mappedChar = 'z' - remainder;
            result += mappedChar;
        }

        return result;
    }
};

int main()
{
    Solution solver;

    vector<string> words1 = {"abcd", "def", "xyz"};
    vector<int> weights1 = {5, 3, 12, 14, 1, 2, 3, 2, 10, 6, 6, 9, 7, 8, 7, 10, 8, 9, 6, 9, 9, 8, 3, 7, 7, 2};

    vector<string> words2 = {"a", "b", "c"};
    vector<int> weights2 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    cout << "--- Weighted Word Mapping Tests ---" << endl;
    cout << "Test 1: " << solver.mapWordWeights(words1, weights1) << endl;
    cout << "Test 2: " << solver.mapWordWeights(words2, weights2) << endl;

    return 0;
}