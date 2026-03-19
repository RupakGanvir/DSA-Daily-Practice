#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int count0 = 0;
        int count1 = 0;
        int count2 = 0;

        // Pass 1: Count the occurrences of 0, 1, and 2
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                count0++;
            else if (nums[i] == 1)
                count1++;
            else if (nums[i] == 2)
                count2++;
        }

        // Pass 2: Overwrite the array based on those counts
        // Fill 0s
        for (int i = 0; i < count0; i++)
        {
            nums[i] = 0;
        }
        // Fill 1s starting where 0s ended
        for (int i = count0; i < (count0 + count1); i++)
        {
            nums[i] = 1;
        }
        // Fill 2s starting where 1s ended until the end of the vector
        for (int i = (count0 + count1); i < nums.size(); i++)
        {
            nums[i] = 2;
        }
    }
};

// Function to print the vector
void printVector(const vector<int> &nums)
{
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    Solution sol;
    vector<int> test = {2, 0, 2, 1, 1, 0};

    cout << "Before sorting: ";
    printVector(test);

    sol.sortColors(test);

    cout << "After sorting:  ";
    printVector(test);

    return 0;
}