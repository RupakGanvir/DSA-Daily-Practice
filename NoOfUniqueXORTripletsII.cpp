#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int uniqueXorTriplets(vector<int> &numbers)
    {
        int arrayLength = numbers.size();
        int maxElement = 0;

        for (int number : numbers)
        {
            maxElement = max(maxElement, number);
        }

        int limit = 1;
        while (limit <= maxElement)
        {
            limit <<= 1;
        }

        vector<bool> pairXorExists(limit, false);
        vector<bool> tripletXorExists(limit, false);

        for (int i = 0; i < arrayLength; i++)
        {
            for (int j = i; j < arrayLength; j++)
            {
                pairXorExists[numbers[i] ^ numbers[j]] = true;
            }
        }

        for (int i = 0; i < limit; i++)
        {
            if (pairXorExists[i])
            {
                for (int number : numbers)
                {
                    tripletXorExists[i ^ number] = true;
                }
            }
        }

        int uniqueCount = 0;
        for (int i = 0; i < limit; i++)
        {
            if (tripletXorExists[i])
            {
                uniqueCount++;
            }
        }

        return uniqueCount;
    }
};

int main()
{
    Solution solver;

    vector<int> numbers1 = {1, 3};
    cout << solver.uniqueXorTriplets(numbers1) << "\n";

    vector<int> numbers2 = {6, 7, 8, 9};
    cout << solver.uniqueXorTriplets(numbers2) << "\n";

    vector<int> numbers3 = {1, 2, 3};
    cout << solver.uniqueXorTriplets(numbers3) << "\n";

    vector<int> numbers4 = {10, 20, 30};
    cout << solver.uniqueXorTriplets(numbers4) << "\n";

    vector<int> numbers5 = {1, 1, 1, 1};
    cout << solver.uniqueXorTriplets(numbers5) << "\n";

    return 0;
}