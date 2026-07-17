#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> gcdValues(vector<int> &nums, vector<long long> &queries)
    {
        int max_val = 0;
        for (int num : nums)
        {
            if (num > max_val)
            {
                max_val = num;
            }
        }

        vector<int> freq(max_val + 1, 0);
        for (int num : nums)
        {
            freq[num]++;
        }

        vector<long long> gcd_pair_count(max_val + 1, 0);

        for (int i = max_val; i >= 1; --i)
        {
            long long mult_count = 0;
            for (int j = i; j <= max_val; j += i)
            {
                mult_count += freq[j];
            }

            long long pairs = mult_count * (mult_count - 1) / 2;

            for (int j = 2 * i; j <= max_val; j += i)
            {
                pairs -= gcd_pair_count[j];
            }

            gcd_pair_count[i] = pairs;
        }

        vector<long long> pref(max_val + 1, 0);
        for (int i = 1; i <= max_val; ++i)
        {
            pref[i] = pref[i - 1] + gcd_pair_count[i];
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (long long q : queries)
        {
            int l = 1, r = max_val, res = max_val;
            while (l <= r)
            {
                int mid = l + (r - l) / 2;
                if (pref[mid] > q)
                {
                    res = mid;
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            ans.push_back(res);
        }

        return ans;
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

    vector<int> nums1 = {2, 3, 4};
    vector<long long> queries1 = {0, 2, 2};
    cout << "--- Test Case 1 ---\n";
    cout << "Output: ";
    printVector(solver.gcdValues(nums1, queries1));
    cout << "\n\n";

    vector<int> nums2 = {4, 4, 2, 1};
    vector<long long> queries2 = {5, 3, 1, 0};
    cout << "--- Test Case 2 ---\n";
    cout << "Output: ";
    printVector(solver.gcdValues(nums2, queries2));
    cout << "\n\n";

    vector<int> nums3 = {2, 2, 2, 2, 2};
    vector<long long> queries3 = {0, 3, 9};
    cout << "--- Test Case 3 ---\n";
    cout << "Output: ";
    printVector(solver.gcdValues(nums3, queries3));
    cout << "\n";

    return 0;
}