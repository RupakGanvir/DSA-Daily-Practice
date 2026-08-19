#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int beautifulSubstrings(string s, int k)
    {
        int n = s.length();
        int count = 0;

        auto isVowel = [](char c)
        {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };

        for (int i = 0; i < n; ++i)
        {
            int vowels = 0;
            int consonants = 0;
            for (int j = i; j < n; ++j)
            {
                if (isVowel(s[j]))
                {
                    vowels++;
                }
                else
                {
                    consonants++;
                }

                if (vowels == consonants && (vowels * consonants) % k == 0)
                {
                    count++;
                }
            }
        }

        return count;
    }
};

int main()
{
    Solution solver;

    cout << solver.beautifulSubstrings("baeyh", 2) << "\n";
    cout << solver.beautifulSubstrings("abba", 1) << "\n";
    cout << solver.beautifulSubstrings("bcdf", 1) << "\n";

    return 0;
}