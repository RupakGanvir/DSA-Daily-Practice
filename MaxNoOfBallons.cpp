#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {
        int b = 0, a = 0, l = 0, o = 0, n = 0;

        for (char c : text)
        {
            if (c == 'b')
                b++;
            else if (c == 'a')
                a++;
            else if (c == 'l')
                l++;
            else if (c == 'o')
                o++;
            else if (c == 'n')
                n++;
        }

        l /= 2;
        o /= 2;

        return min({b, a, l, o, n});
    }
};

int main()
{
    Solution solver;

    string t1 = "nlaebolko";
    string t2 = "loonbalxballpoon";
    string t3 = "leetcode";

    cout << "--- Maximum Number of Balloons Tests ---" << endl;
    cout << "Test 1: " << solver.maxNumberOfBalloons(t1) << endl;
    cout << "Test 2: " << solver.maxNumberOfBalloons(t2) << endl;
    cout << "Test 3: " << solver.maxNumberOfBalloons(t3) << endl;

    return 0;
}