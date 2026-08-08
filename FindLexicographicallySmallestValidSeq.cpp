#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<int> validSequence(string word1, string word2)
    {
        int m = word1.size();
        int n = word2.size();
        vector<int> right_match(n, -1);

        int i = m - 1;
        int j = n - 1;
        while (i >= 0 && j >= 0)
        {
            if (word1[i] == word2[j])
            {
                right_match[j] = i;
                j--;
            }
            i--;
        }

        vector<int> ans;
        bool changed = false;
        j = 0;

        for (i = 0; i < m && j < n; ++i)
        {
            if (word1[i] == word2[j])
            {
                ans.push_back(i);
                j++;
            }
            else if (!changed && (j + 1 == n || right_match[j + 1] > i))
            {
                changed = true;
                ans.push_back(i);
                j++;
            }
        }

        if (j == n)
        {
            return ans;
        }
        return {};
    }
};

void printVector(const vector<int> &vec)
{
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << (i + 1 == vec.size() ? "" : ", ");
    }
    cout << "]\n";
}

int main()
{
    Solution solver;

    printVector(solver.validSequence("vbcca", "abc"));
    printVector(solver.validSequence("bacba", "aba"));
    printVector(solver.validSequence("aaaaaa", "aaabc"));
    printVector(solver.validSequence("abc", "ab"));

    return 0;
}