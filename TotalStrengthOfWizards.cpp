#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int totalStrength(vector<int> &strength)
    {
        int n = strength.size();
        long long mod = 1e9 + 7;

        vector<int> left(n, -1);
        vector<int> right(n, n);
        vector<int> st;

        for (int i = 0; i < n; ++i)
        {
            while (!st.empty() && strength[st.back()] >= strength[i])
            {
                st.pop_back();
            }
            if (!st.empty())
            {
                left[i] = st.back();
            }
            st.push_back(i);
        }

        st.clear();

        for (int i = n - 1; i >= 0; --i)
        {
            while (!st.empty() && strength[st.back()] > strength[i])
            {
                st.pop_back();
            }
            if (!st.empty())
            {
                right[i] = st.back();
            }
            st.push_back(i);
        }

        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; ++i)
        {
            pref[i + 1] = (pref[i] + strength[i]) % mod;
        }

        vector<long long> ppref(n + 2, 0);
        for (int i = 0; i <= n; ++i)
        {
            ppref[i + 1] = (ppref[i] + pref[i]) % mod;
        }

        long long ans = 0;
        for (int i = 0; i < n; ++i)
        {
            long long l = left[i] + 1;
            long long r = right[i] - 1;

            long long ln = i - l + 1;
            long long rn = r - i + 1;

            long long right_sum = (ppref[r + 2] - ppref[i + 1] + mod) % mod;
            long long left_sum = (ppref[i + 1] - ppref[l] + mod) % mod;

            long long total_sum = (ln * right_sum % mod - rn * left_sum % mod + mod) % mod;

            ans = (ans + total_sum * strength[i]) % mod;
        }

        return ans;
    }
};

int main()
{
    Solution solver;

    vector<int> strength1 = {1, 3, 1, 2};
    cout << solver.totalStrength(strength1) << "\n";

    vector<int> strength2 = {5, 4, 6};
    cout << solver.totalStrength(strength2) << "\n";

    return 0;
}