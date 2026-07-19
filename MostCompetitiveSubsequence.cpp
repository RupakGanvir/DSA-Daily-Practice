#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> mostCompetitive(vector<int> &nums, int k)
    {
        vector<int> stack;
        int n = nums.size();

        for (int i = 0; i < n; ++i)
        {
            while (!stack.empty() && stack.back() > nums[i] && stack.size() - 1 + n - i >= k)
            {
                stack.pop_back();
            }
            if (stack.size() < k)
            {
                stack.push_back(nums[i]);
            }
        }

        return stack;
    }
};

void printVector(const vector<int> &vec)
{
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << (i == vec.size() - 1 ? "" : ", ");
    }
    cout << "]";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    vector<int> nums1 = {3, 5, 2, 6};
    int k1 = 2;
    cout << "--- Test Case 1 ---\n";
    cout << "Output: ";
    printVector(solver.mostCompetitive(nums1, k1));
    cout << "\n\n";

    vector<int> nums2 = {2, 4, 3, 3, 5, 4, 9, 6};
    int k2 = 4;
    cout << "--- Test Case 2 ---\n";
    cout << "Output: ";
    printVector(solver.mostCompetitive(nums2, k2));
    cout << "\n\n";

    vector<int> nums3 = {7, 1, 5, 3, 6, 4};
    int k3 = 3;
    cout << "--- Test Case 3 ---\n";
    cout << "Output: ";
    printVector(solver.mostCompetitive(nums3, k3));
    cout << "\n";

    return 0;
}