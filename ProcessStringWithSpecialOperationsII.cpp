#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    char processStr(string s, long long k)
    {
        long long m = 0;
        for (char c : s)
        {
            if (c == '*')
            {
                m = max(0LL, m - 1);
            }
            else if (c == '#')
            {
                m <<= 1;
            }
            else if (c != '%')
            {
                m += 1;
            }
        }

        if (k >= m)
        {
            return '.';
        }

        for (int i = s.length() - 1; i >= 0; i--)
        {
            char c = s[i];
            if (c == '*')
            {
                m += 1;
            }
            else if (c == '#')
            {
                m /= 2;
                if (k >= m)
                {
                    k -= m;
                }
            }
            else if (c == '%')
            {
                k = m - 1 - k;
            }
            else
            {
                m -= 1;
                if (k == m)
                {
                    return c;
                }
            }
        }
        return '.';
    }
};

int main()
{
    Solution solver;

    string s1 = "a#b%*";
    long long k1 = 1;

    string s2 = "cd%#*#";
    long long k2 = 3;

    string s3 = "z*#";
    long long k3 = 0;

    cout << "--- Process String with Special Operations II Tests ---" << endl;
    cout << "Test 1: " << solver.processStr(s1, k1) << endl;
    cout << "Test 2: " << solver.processStr(s2, k2) << endl;
    cout << "Test 3: " << solver.processStr(s3, k3) << endl;

    return 0;
}