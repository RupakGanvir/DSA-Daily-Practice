#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
private:
    void extract(int d, int &d2, int &d3, int &d5, int &d7)
    {
        d2 = d3 = d5 = d7 = 0;
        if (d == 0)
            return;
        while (d % 2 == 0)
        {
            d2++;
            d /= 2;
        }
        while (d % 3 == 0)
        {
            d3++;
            d /= 3;
        }
        while (d % 5 == 0)
        {
            d5++;
            d /= 5;
        }
        while (d % 7 == 0)
        {
            d7++;
            d /= 7;
        }
    }

    int get_min_digits(int c2, int c3)
    {
        if (c2 <= 0 && c3 <= 0)
            return 0;
        c2 = max(0, c2);
        c3 = max(0, c3);
        int d9 = c3 / 2;
        c3 %= 2;
        int d8 = c2 / 3;
        c2 %= 3;
        int res = d9 + d8;
        if (c3 == 1 && c2 == 2)
            res += 2;
        else if (c3 == 1 && c2 == 1)
            res += 1;
        else if (c3 == 1 && c2 == 0)
            res += 1;
        else if (c3 == 0 && c2 == 2)
            res += 1;
        else if (c3 == 0 && c2 == 1)
            res += 1;
        return res;
    }

    bool is_valid(const string &num, int t2, int t3, int t5, int t7)
    {
        int c2 = 0, c3 = 0, c5 = 0, c7 = 0;
        for (char c : num)
        {
            if (c == '0')
                return false;
            int d = c - '0';
            int d2, d3, d5, d7;
            extract(d, d2, d3, d5, d7);
            c2 += d2;
            c3 += d3;
            c5 += d5;
            c7 += d7;
        }
        return c2 >= t2 && c3 >= t3 && c5 >= t5 && c7 >= t7;
    }

public:
    string smallestNumber(string num, long long t)
    {
        int t2 = 0, t3 = 0, t5 = 0, t7 = 0;
        long long temp_t = t;
        while (temp_t % 2 == 0)
        {
            t2++;
            temp_t /= 2;
        }
        while (temp_t % 3 == 0)
        {
            t3++;
            temp_t /= 3;
        }
        while (temp_t % 5 == 0)
        {
            t5++;
            temp_t /= 5;
        }
        while (temp_t % 7 == 0)
        {
            t7++;
            temp_t /= 7;
        }

        if (temp_t > 1)
            return "-1";

        if (is_valid(num, t2, t3, t5, t7))
            return num;

        int n = num.length();
        int first_zero = -1;
        for (int i = 0; i < n; ++i)
        {
            if (num[i] == '0')
            {
                first_zero = i;
                break;
            }
        }

        vector<vector<int>> pref(n + 1, vector<int>(4, 0));
        for (int i = 0; i < n; ++i)
        {
            int d2, d3, d5, d7;
            extract(num[i] - '0', d2, d3, d5, d7);
            pref[i + 1][0] = pref[i][0] + d2;
            pref[i + 1][1] = pref[i][1] + d3;
            pref[i + 1][2] = pref[i][2] + d5;
            pref[i + 1][3] = pref[i][3] + d7;
        }

        int start_i = (first_zero != -1) ? first_zero : n - 1;

        for (int i = start_i; i >= 0; --i)
        {
            int p2 = pref[i][0];
            int p3 = pref[i][1];
            int p5 = pref[i][2];
            int p7 = pref[i][3];

            int req2 = max(0, t2 - p2);
            int req3 = max(0, t3 - p3);
            int req5 = max(0, t5 - p5);
            int req7 = max(0, t7 - p7);

            for (int d = (num[i] - '0') + 1; d <= 9; ++d)
            {
                int d2, d3, d5, d7;
                extract(d, d2, d3, d5, d7);

                int rem2 = max(0, req2 - d2);
                int rem3 = max(0, req3 - d3);
                int rem5 = max(0, req5 - d5);
                int rem7 = max(0, req7 - d7);

                int rem_len = n - 1 - i;
                if (rem5 + rem7 + get_min_digits(rem2, rem3) <= rem_len)
                {
                    string ans = num.substr(0, i);
                    ans += to_string(d);

                    for (int j = 0; j < rem_len; ++j)
                    {
                        for (int next_d = 1; next_d <= 9; ++next_d)
                        {
                            int nd2, nd3, nd5, nd7;
                            extract(next_d, nd2, nd3, nd5, nd7);

                            int n_rem2 = max(0, rem2 - nd2);
                            int n_rem3 = max(0, rem3 - nd3);
                            int n_rem5 = max(0, rem5 - nd5);
                            int n_rem7 = max(0, rem7 - nd7);

                            if (n_rem5 + n_rem7 + get_min_digits(n_rem2, n_rem3) <= rem_len - 1 - j)
                            {
                                ans += to_string(next_d);
                                rem2 = n_rem2;
                                rem3 = n_rem3;
                                rem5 = n_rem5;
                                rem7 = n_rem7;
                                break;
                            }
                        }
                    }
                    return ans;
                }
            }
        }

        int req_total = t5 + t7 + get_min_digits(t2, t3);
        int target_len = max(n + 1, req_total);

        string ans = "";
        int rem2 = t2, rem3 = t3, rem5 = t5, rem7 = t7;
        for (int j = 0; j < target_len; ++j)
        {
            for (int next_d = 1; next_d <= 9; ++next_d)
            {
                int nd2, nd3, nd5, nd7;
                extract(next_d, nd2, nd3, nd5, nd7);

                int n_rem2 = max(0, rem2 - nd2);
                int n_rem3 = max(0, rem3 - nd3);
                int n_rem5 = max(0, rem5 - nd5);
                int n_rem7 = max(0, rem7 - nd7);

                if (n_rem5 + n_rem7 + get_min_digits(n_rem2, n_rem3) <= target_len - 1 - j)
                {
                    ans += to_string(next_d);
                    rem2 = n_rem2;
                    rem3 = n_rem3;
                    rem5 = n_rem5;
                    rem7 = n_rem7;
                    break;
                }
            }
        }

        return ans;
    }
};

int main()
{
    Solution solver;

    cout << "\"" << solver.smallestNumber("1234", 256) << "\"\n";
    cout << "\"" << solver.smallestNumber("12355", 50) << "\"\n";
    cout << "\"" << solver.smallestNumber("11111", 26) << "\"\n";

    return 0;
}