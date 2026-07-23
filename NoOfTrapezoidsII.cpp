#include <iostream>
#include <vector>
#include <map>
#include <array>
#include <numeric>
#include <cmath>

using namespace std;

class Solution
{
private:
    int getGcd(int a, int b)
    {
        a = abs(a);
        b = abs(b);
        while (b > 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

public:
    int countTrapezoids(vector<vector<int>> &points)
    {
        map<pair<int, int>, int> slopeCount;
        map<array<int, 3>, int> lineCount;
        map<array<int, 3>, int> slopeLenCount;
        map<array<int, 4>, int> lineLenCount;

        long long result = 0;
        long long same = 0;
        int n = points.size();

        for (int i = 0; i < n; ++i)
        {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = 0; j < i; ++j)
            {
                int x2 = points[j][0];
                int y2 = points[j][1];

                int dx = x2 - x1;
                int dy = y2 - y1;

                int g = getGcd(dx, dy);
                int a = dx / g;
                int b = dy / g;

                if (a < 0 || (a == 0 && b < 0))
                {
                    a = -a;
                    b = -b;
                }

                int c = b * x1 - a * y1;
                int l = dx * dx + dy * dy;

                result += slopeCount[{a, b}] - lineCount[{a, b, c}];
                slopeCount[{a, b}]++;
                lineCount[{a, b, c}]++;

                same += slopeLenCount[{a, b, l}] - lineLenCount[{a, b, c, l}];
                slopeLenCount[{a, b, l}]++;
                lineLenCount[{a, b, c, l}]++;
            }
        }

        return result - same / 2;
    }
};

int main()
{
    Solution solver;

    vector<vector<int>> points1 = {{-3, 2}, {3, 0}, {2, 3}, {3, 2}, {2, -3}};
    cout << solver.countTrapezoids(points1) << "\n";

    vector<vector<int>> points2 = {{0, 0}, {1, 0}, {0, 1}, {2, 1}};
    cout << solver.countTrapezoids(points2) << "\n";

    vector<vector<int>> points3 = {{0, 0}, {1, 1}, {2, 2}, {3, 3}};
    cout << solver.countTrapezoids(points3) << "\n";

    vector<vector<int>> points4 = {{0, 0}, {2, 0}, {1, 2}, {-1, 2}, {3, 4}};
    cout << solver.countTrapezoids(points4) << "\n";

    return 0;
}