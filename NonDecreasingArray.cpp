#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool checkPossibility(vector<int> &numbers)
    {
        int modifications = 0;
        int arraySize = numbers.size();

        for (int i = 1; i < arraySize; i++)
        {
            if (numbers[i] < numbers[i - 1])
            {
                modifications++;

                if (modifications > 1)
                {
                    return false;
                }

                if (i == 1 || numbers[i - 2] <= numbers[i])
                {
                    numbers[i - 1] = numbers[i];
                }
                else
                {
                    numbers[i] = numbers[i - 1];
                }
            }
        }

        return true;
    }
};

int main()
{
    Solution solver;

    vector<int> numbers1 = {4, 2, 3};
    cout << (solver.checkPossibility(numbers1) ? "true" : "false") << "\n";

    vector<int> numbers2 = {4, 2, 1};
    cout << (solver.checkPossibility(numbers2) ? "true" : "false") << "\n";

    vector<int> numbers3 = {3, 4, 2, 3};
    cout << (solver.checkPossibility(numbers3) ? "true" : "false") << "\n";

    vector<int> numbers4 = {1, 2, 3, 4};
    cout << (solver.checkPossibility(numbers4) ? "true" : "false") << "\n";

    vector<int> numbers5 = {5, 7, 1, 8};
    cout << (solver.checkPossibility(numbers5) ? "true" : "false") << "\n";

    vector<int> numbers6 = {1, 2, 5, 3, 3};
    cout << (solver.checkPossibility(numbers6) ? "true" : "false") << "\n";

    return 0;
}