#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;
const int MAX_VAL = 100000;
int primeScores[MAX_VAL + 1] = {0};
bool initialized = false;

void init()
{
    if (initialized)
        return;
    for (int i = 2; i <= MAX_VAL; ++i)
    {
        if (primeScores[i] == 0)
        {
            for (int j = i; j <= MAX_VAL; j += i)
            {
                primeScores[j]++;
            }
        }
    }
    initialized = true;
}

long long power(long long base, long long exp)
{
    long long res = 1;
    base %= MOD;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

class Solution
{
public:
    int maximumScore(vector<int> &nums, int k)
    {
        init();
        int n = nums.size();
        vector<int> scores(n);
        for (int i = 0; i < n; ++i)
        {
            scores[i] = primeScores[nums[i]];
        }

        vector<int> left(n, -1);
        vector<int> stack;
        for (int i = 0; i < n; ++i)
        {
            while (!stack.empty() && scores[stack.back()] < scores[i])
            {
                stack.pop_back();
            }
            if (!stack.empty())
            {
                left[i] = stack.back();
            }
            stack.push_back(i);
        }

        vector<int> right(n, n);
        stack.clear();
        for (int i = n - 1; i >= 0; --i)
        {
            while (!stack.empty() && scores[stack.back()] <= scores[i])
            {
                stack.pop_back();
            }
            if (!stack.empty())
            {
                right[i] = stack.back();
            }
            stack.push_back(i);
        }

        vector<pair<int, long long>> pairs(n);
        for (int i = 0; i < n; ++i)
        {
            pairs[i] = {nums[i], (long long)(i - left[i]) * (right[i] - i)};
        }

        sort(pairs.rbegin(), pairs.rend());

        long long ans = 1;
        long long rem = k;
        for (int i = 0; i < n && rem > 0; ++i)
        {
            long long take = min(rem, pairs[i].second);
            ans = (ans * power(pairs[i].first, take)) % MOD;
            rem -= take;
        }

        return ans;
    }
};

int main()
{
    Solution solver;

    vector<int> nums1 = {8, 3, 9, 3, 8};
    int k1 = 2;
    cout << solver.maximumScore(nums1, k1) << "\n";

    vector<int> nums2 = {19, 12, 14, 6, 10, 18};
    int k2 = 3;
    cout << solver.maximumScore(nums2, k2) << "\n";

    return 0;
}