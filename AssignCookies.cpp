#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int child = 0;
        int cookie = 0;

        while (child < g.size() && cookie < s.size())
        {
            if (s[cookie] >= g[child])
            {
                child++;
            }
            cookie++;
        }

        return child;
    }
};

int main()
{
    Solution solver;

    vector<int> g1 = {1, 2, 3};
    vector<int> s1 = {1, 1};

    vector<int> g2 = {1, 2};
    vector<int> s2 = {1, 2, 3};

    cout << "--- Assign Cookies Tests ---" << endl;
    cout << "Test 1: " << solver.findContentChildren(g1, s1) << endl;
    cout << "Test 2: " << solver.findContentChildren(g2, s2) << endl;

    return 0;
}