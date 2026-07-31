#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minimumPushes(string word)
    {
        vector<int> freq(26, 0);
        for (char c : word)
        {
            freq[c - 'a']++;
        }

        sort(freq.rbegin(), freq.rend());

        int totalPushes = 0;
        for (int i = 0; i < 26; ++i)
        {
            if (freq[i] == 0)
            {
                break;
            }
            int pushes = (i / 8) + 1;
            totalPushes += freq[i] * pushes;
        }

        return totalPushes;
    }
};

int main()
{
    Solution solver;

    cout << solver.minimumPushes("abcde") << "\n";
    cout << solver.minimumPushes("xyzxyzxyzxyz") << "\n";
    cout << solver.minimumPushes("aabbccddeeffgghhiiiiii") << "\n";

    return 0;
}