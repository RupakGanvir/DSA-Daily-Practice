#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        stack<int> st;
        st.push(-1);
        int max_len = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                st.push(i);
            }
            else
            {
                st.pop();

                if (st.empty())
                {
                    st.push(i);
                }
                else
                {
                    max_len = std::max(max_len, i - st.top());
                }
            }
        }
        return max_len;
    }
};

int main()
{
    Solution sol;

    // Test cases
    vector<string> testCases = {
        "(()",
        ")()())",
        "",
        "()(())",
        "()(()"};

    for (const string &test : testCases)
    {
        int result = sol.longestValidParentheses(test);
        cout << "Input: \"" << test << "\" -> Longest Valid: " << result << endl;
    }

    return 0;
}