#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> counts;
        for (int num : nums)
        {
            counts[num]++;
        }

        int n = nums.size();
        vector<vector<int>> buckets(n + 1);
        for (auto const &p : counts)
        {
            buckets[p.second].push_back(p.first);
        }

        vector<int> result;
        for (int i = n; i >= 0; i--)
        {
            for (int num : buckets[i])
            {
                result.push_back(num);
                if (result.size() == k)
                {
                    return result;
                }
            }
        }

        return result;
    }
};

int main()
{
    Solution solver;

    vector<int> nums1 = {1, 1, 1, 2, 2, 3};
    int k1 = 2;

    vector<int> nums2 = {1};
    int k2 = 1;

    vector<int> res1 = solver.topKFrequent(nums1, k1);
    vector<int> res2 = solver.topKFrequent(nums2, k2);

    cout << "--- Top K Frequent Elements Tests ---" << endl;

    cout << "Test 1: [";
    for (size_t i = 0; i < res1.size(); i++)
    {
        cout << res1[i] << (i < res1.size() - 1 ? ", " : "");
    }
    cout << "]" << endl;

    cout << "Test 2: [";
    for (size_t i = 0; i < res2.size(); i++)
    {
        cout << res2[i] << (i < res2.size() - 1 ? ", " : "");
    }
    cout << "]" << endl;

    return 0;
}