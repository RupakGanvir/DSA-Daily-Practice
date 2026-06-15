#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution
{
private:
    int largestRectangleArea(const vector<int> &heights)
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

public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (matrix.empty() || matrix[0].empty())
        {
            return 0;
        }

        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int maxArea = 0;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == '1')
                {
                    heights[j]++;
                }
                else
                {
                    heights[j] = 0;
                }
            }
            maxArea = max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }
};

int main()
{
    Solution solver;

    vector<vector<char>> matrix1 = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}};

    vector<vector<char>> matrix2 = {
        {'0'}};

    vector<vector<char>> matrix3 = {
        {'1'}};

    cout << "--- Maximal Rectangle Tests ---" << endl;
    cout << "Test 1: " << solver.maximalRectangle(matrix1) << endl;
    cout << "Test 2: " << solver.maximalRectangle(matrix2) << endl;
    cout << "Test 3: " << solver.maximalRectangle(matrix3) << endl;

    return 0;
}