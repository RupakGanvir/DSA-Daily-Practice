#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        // We use an unordered_set because it provides O(1) average time complexity for lookups
        unordered_set<int> seen;

        for (int num : nums)
        {
            // .count() returns 1 if the element exists, 0 otherwise
            if (seen.count(num))
            {
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};

int main()
{
    Solution sol;

    // Test Case 1: Should be true (contains duplicates)
    vector<int> test1 = {1, 2, 3, 1};
    // Test Case 2: Should be false (all unique)
    vector<int> test2 = {1, 2, 3, 4};

    cout << boolalpha; // Prints "true/false" instead of "1/0"
    cout << "Test 1 [1, 2, 3, 1]: " << sol.containsDuplicate(test1) << endl;
    cout << "Test 2 [1, 2, 3, 4]: " << sol.containsDuplicate(test2) << endl;

    return 0;
}