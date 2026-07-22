#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string strWithout3a3b(int countA, int countB)
    {
        string resultString = "";

        while (countA > 0 || countB > 0)
        {
            int currentLength = resultString.length();
            bool appendA = false;

            if (currentLength >= 2 && resultString[currentLength - 1] == resultString[currentLength - 2])
            {
                if (resultString[currentLength - 1] == 'b')
                {
                    appendA = true;
                }
            }
            else
            {
                if (countA >= countB)
                {
                    appendA = true;
                }
            }

            if (appendA)
            {
                countA--;
                resultString += 'a';
            }
            else
            {
                countB--;
                resultString += 'b';
            }
        }

        return resultString;
    }
};

int main()
{
    Solution solver;

    cout << solver.strWithout3a3b(1, 2) << "\n";
    cout << solver.strWithout3a3b(4, 1) << "\n";
    cout << solver.strWithout3a3b(3, 3) << "\n";
    cout << solver.strWithout3a3b(2, 5) << "\n";
    cout << solver.strWithout3a3b(6, 2) << "\n";
    cout << solver.strWithout3a3b(8, 4) << "\n";

    return 0;
}