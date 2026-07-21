#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    bool parseBoolExpr(string expression)
    {
        vector<char> st;

        for (char c : expression)
        {
            if (c == ',')
            {
                continue;
            }
            else if (c != ')')
            {
                st.push_back(c);
            }
            else
            {
                bool hasTrue = false;
                bool hasFalse = false;

                // Pop all the boolean values inside the current parentheses
                while (st.back() != '(')
                {
                    char val = st.back();
                    st.pop_back();
                    if (val == 't')
                        hasTrue = true;
                    if (val == 'f')
                        hasFalse = true;
                }

                // Pop the '('
                st.pop_back();

                // Pop the operator before the '('
                char op = st.back();
                st.pop_back();

                // Evaluate the expression based on the operator
                char res;
                if (op == '!')
                {
                    res = hasTrue ? 'f' : 't';
                }
                else if (op == '&')
                {
                    res = hasFalse ? 'f' : 't';
                }
                else
                { // op == '|'
                    res = hasTrue ? 't' : 'f';
                }

                // Push the evaluated result back onto the stack
                st.push_back(res);
            }
        }

        return st.back() == 't';
    }
};

int main()
{
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Print booleans as true/false instead of 1/0
    cout << boolalpha;

    Solution solver;

    string expr1 = "!(f)";
    cout << "--- Test Case 1 ---\n";
    cout << "Expression: " << expr1 << "\n";
    cout << "Result: " << solver.parseBoolExpr(expr1) << "\n\n";

    string expr2 = "|(f,t)";
    cout << "--- Test Case 2 ---\n";
    cout << "Expression: " << expr2 << "\n";
    cout << "Result: " << solver.parseBoolExpr(expr2) << "\n\n";

    string expr3 = "&(t,f)";
    cout << "--- Test Case 3 ---\n";
    cout << "Expression: " << expr3 << "\n";
    cout << "Result: " << solver.parseBoolExpr(expr3) << "\n\n";

    string expr4 = "|(&(t,f,t),!(t))";
    cout << "--- Test Case 4 ---\n";
    cout << "Expression: " << expr4 << "\n";
    cout << "Result: " << solver.parseBoolExpr(expr4) << "\n";

    return 0;
}