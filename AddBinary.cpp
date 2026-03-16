#include <iostream>
#include <string>
#include <algorithm> // Required for reverse()

using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        string result = "";

        // Loop as long as there are digits to process or a carry remaining
        while (i >= 0 || j >= 0 || carry)
        {
            int sum = carry;

            if (i >= 0)
            {
                sum += a[i] - '0';
                i--;
            }

            if (j >= 0)
            {
                sum += b[j] - '0';
                j--;
            }

            // Binary logic: sum % 2 gives the bit, sum / 2 gives the carry
            result += (sum % 2) + '0';
            carry = sum / 2;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

int main()
{
    Solution sol;

    // Test cases
    string a1 = "11", b1 = "1";
    string a2 = "1010", b2 = "1011";

    cout << "Test 1: " << a1 << " + " << b1 << " = " << sol.addBinary(a1, b1) << endl; // Output: 100
    cout << "Test 2: " << a2 << " + " << b2 << " = " << sol.addBinary(a2, b2) << endl; // Output: 10101

    return 0;
}