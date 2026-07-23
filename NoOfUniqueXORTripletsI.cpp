#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int uniqueXorTriplets(vector<int> &numbers)
    {
        int arrayLength = numbers.size();
        if (arrayLength < 3)
        {
            return arrayLength;
        }

        int bitLength = 0;
        int temp = arrayLength;

        while (temp > 0)
        {
            bitLength++;
            temp >>= 1;
        }

        return 1 << bitLength;
    }
};

int main()
{
    Solution solver;

    vector<int> numbers1 = {1, 2};
    cout << solver.uniqueXorTriplets(numbers1) << "\n";

    vector<int> numbers2 = {3, 1, 2};
    cout << solver.uniqueXorTriplets(numbers2) << "\n";

    vector<int> numbers3 = {4, 1, 3, 2};
    cout << solver.uniqueXorTriplets(numbers3) << "\n";

    vector<int> numbers4 = {1, 5, 2, 4, 3};
    cout << solver.uniqueXorTriplets(numbers4) << "\n";

    vector<int> numbers5 = {1};
    cout << solver.uniqueXorTriplets(numbers5) << "\n";

    vector<int> numbers6 = {7, 6, 5, 4, 3, 2, 1};
    cout << solver.uniqueXorTriplets(numbers6) << "\n";

    return 0;
}