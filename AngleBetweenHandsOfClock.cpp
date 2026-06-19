#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution
{
public:
    double angleClock(int hour, int minutes)
    {
        double hourAngle = (hour % 12) * 30.0 + minutes * 0.5;
        double minuteAngle = minutes * 6.0;

        double diff = abs(hourAngle - minuteAngle);

        return min(diff, 360.0 - diff);
    }
};

int main()
{
    Solution solver;

    int h1 = 12, m1 = 20;
    int h2 = 3, m2 = 30;
    int h3 = 3, m3 = 15;

    cout << "--- Angle Between Hands of a Clock Tests ---" << endl;
    cout << "Test 1: " << solver.angleClock(h1, m1) << endl;
    cout << "Test 2: " << solver.angleClock(h2, m2) << endl;
    cout << "Test 3: " << solver.angleClock(h3, m3) << endl;

    return 0;
}