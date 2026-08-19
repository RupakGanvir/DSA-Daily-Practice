#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    vector<int> canSeePersonsCount(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> ans(n, 0);
        stack<int> st;

        for (int i = n - 1; i >= 0; --i)
        {
            int count = 0;
            while (!st.empty() && st.top() < heights[i])
            {
                st.pop();
                count++;
            }
            if (!st.empty())
            {
                count++;
            }
            ans[i] = count;
            st.push(heights[i]);
        }

        return ans;
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

    vector<int> heights1 = {10, 6, 8, 5, 11, 9};
    printVector(solver.canSeePersonsCount(heights1));

    vector<int> heights2 = {5, 1, 2, 3, 10};
    printVector(solver.canSeePersonsCount(heights2));

    return 0;
}