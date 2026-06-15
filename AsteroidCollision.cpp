#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vector<int> st;

        for (int ast : asteroids)
        {
            bool destroyed = false;

            while (!st.empty() && ast < 0 && st.back() > 0)
            {
                if (st.back() < abs(ast))
                {
                    st.pop_back();
                    continue;
                }
                else if (st.back() == abs(ast))
                {
                    st.pop_back();
                }
                destroyed = true;
                break;
            }

            if (!destroyed)
            {
                st.push_back(ast);
            }
        }

        return st;
    }
};

int main()
{
    Solution solver;

    vector<int> ast1 = {5, 10, -5};
    vector<int> ast2 = {8, -8};
    vector<int> ast3 = {10, 2, -5};

    vector<int> res1 = solver.asteroidCollision(ast1);
    vector<int> res2 = solver.asteroidCollision(ast2);
    vector<int> res3 = solver.asteroidCollision(ast3);

    cout << "--- Asteroid Collision Tests ---" << endl;

    cout << "Test 1: [";
    for (size_t i = 0; i < res1.size(); i++)
    {
        cout << res1[i] << (i < res1.size() - 1 ? ", " : "");
    }
    cout << "]" << endl;

    cout << "Test 2: [";
    for (size_t i = 0; i < res2.size(); i++)
    {
        cout << res2[i] << (i < res2.size() - 1 ? ", " : "");
    }
    cout << "]" << endl;

    cout << "Test 3: [";
    for (size_t i = 0; i < res3.size(); i++)
    {
        cout << res3[i] << (i < res3.size() - 1 ? ", " : "");
    }
    cout << "]" << endl;

    return 0;
}