#include <iostream>

using namespace std;

class Solution
{
public:
    int minBitFlips(int start, int goal)
    {
        int xorResult = start ^ goal;
        int count = 0;

        while (xorResult > 0)
        {
            count += xorResult & 1;
            xorResult >>= 1;
        }

        return count;
    }
};

int main()
{
    Solution solver;

    int start1 = 10, goal1 = 7;
    int start2 = 3, goal2 = 4;

    cout << "--- Minimum Bit Flips Tests ---" << endl;
    cout << "Test 1: " << solver.minBitFlips(start1, goal1) << endl;
    cout << "Test 2: " << solver.minBitFlips(start2, goal2) << endl;

    return 0;
}