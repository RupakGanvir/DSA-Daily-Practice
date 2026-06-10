#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> counts;
        for (char c : s)
        {
            counts[c]++;
        }

        vector<pair<char, int>> freq;
        for (auto &it : counts)
        {
            freq.push_back(it);
        }

        sort(freq.begin(), freq.end(), [](pair<char, int> &a, pair<char, int> &b)
             { return a.second > b.second; });

        string result = "";
        for (auto &p : freq)
        {
            result.append(p.second, p.first);
        }

        return result;
    }
};

int main()
{
    Solution solver;

    string s1 = "tree";
    string s2 = "cccaaa";
    string s3 = "Aabb";

    cout << "--- Sort Characters By Frequency Tests ---" << endl;
    cout << "Test 1: " << solver.frequencySort(s1) << endl;
    cout << "Test 2: " << solver.frequencySort(s2) << endl;
    cout << "Test 3: " << solver.frequencySort(s3) << endl;

    return 0;
}