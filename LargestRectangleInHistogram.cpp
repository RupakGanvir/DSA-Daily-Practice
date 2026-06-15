#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; i++)
        {
            int currentHeight = (i == n) ? 0 : heights[i];

            while (!st.empty() && heights[st.top()] > currentHeight)
            {
                int height = heights[st.top()];
                st.pop();

                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }

        return maxArea;
    }
};

int main()
{
    Solution solver;

    vector<int> heights1 = {2, 1, 5, 6, 2, 3};
    vector<int> heights2 = {2, 4};

    cout << "--- Largest Rectangle in Histogram Tests ---" << endl;
    cout << "Test 1: " << solver.largestRectangleArea(heights1) << endl;
    cout << "Test 2: " << solver.largestRectangleArea(heights2) << endl;

    return 0;
}