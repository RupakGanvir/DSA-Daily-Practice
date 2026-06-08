#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }

        int mapS[256] = {0};
        int mapT[256] = {0};

        for (int i = 0; i < s.length(); i++)
        {
            if (mapS[s[i]] != mapT[t[i]])
            {
                return false;
            }
            mapS[s[i]] = i + 1;
            mapT[t[i]] = i + 1;
        }

        return true;
    }
};

int main()
{
    Solution solver;

    string s1 = "egg";
    string t1 = "add";

    string s2 = "foo";
    string t2 = "bar";

    string s3 = "paper";
    string t3 = "title";

    cout << "--- Isomorphic Strings Tests ---" << endl;
    cout << "Test 1: " << (solver.isIsomorphic(s1, t1) ? "True" : "False") << endl;
    cout << "Test 2: " << (solver.isIsomorphic(s2, t2) ? "True" : "False") << endl;
    cout << "Test 3: " << (solver.isIsomorphic(s3, t3) ? "True" : "False") << endl;

    return 0;
}