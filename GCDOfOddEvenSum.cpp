#include <iostream>

using namespace std;

class Solution
{
public:
    int gcdOfOddEvenSums(int n)
    {
        return n;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    int n1 = 10;
    cout << "--- Test Case 1 ---\n";
    cout << "Input: n = " << n1 << "\n";
    cout << "Output: " << solver.gcdOfOddEvenSums(n1) << "\n\n";

    int n2 = 4;
    cout << "--- Test Case 2 ---\n";
    cout << "Input: n = " << n2 << "\n";
    cout << "Output: " << solver.gcdOfOddEvenSums(n2) << "\n\n";

    int n3 = 5;
    cout << "--- Test Case 3 ---\n";
    cout << "Input: n = " << n3 << "\n";
    cout << "Output: " << solver.gcdOfOddEvenSums(n3) << "\n";

    return 0;
}