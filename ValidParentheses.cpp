#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;

        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                st.push(c);
            }
            else
            {
                if (st.empty())
                    return false;

                char top = st.top();
                if ((c == ')' && top == '(') ||
                    (c == '}' && top == '{') ||
                    (c == ']' && top == '['))
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }

        return st.empty();
    }
};

int main()
{
    Solution sol;

    string t1 = "()[]{}";
    string t2 = "([)]";
    string t3 = "{[]}";

    cout << boolalpha;
    cout << "Is \"" << t1 << "\" valid? " << sol.isValid(t1) << endl; // true
    cout << "Is \"" << t2 << "\" valid? " << sol.isValid(t2) << endl; // false
    cout << "Is \"" << t3 << "\" valid? " << sol.isValid(t3) << endl; // true

    return 0;
}