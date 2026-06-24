#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    long long MOD = 1000000007;

    vector<vector<long long>> multiply(const vector<vector<long long>> &A, const vector<vector<long long>> &B)
    {
        int n = A.size();
        vector<vector<long long>> C(n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int k = 0; k < n; k++)
            {
                if (A[i][k] == 0)
                    continue;
                for (int j = 0; j < n; j++)
                {
                    if (B[k][j] == 0)
                        continue;
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    vector<vector<long long>> power(vector<vector<long long>> base, long long exp)
    {
        int n = base.size();
        vector<vector<long long>> res(n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++)
        {
            res[i][i] = 1;
        }
        while (exp > 0)
        {
            if (exp & 1)
            {
                res = multiply(res, base);
            }
            base = multiply(base, base);
            exp >>= 1;
        }
        return res;
    }

    vector<long long> multiplyVector(const vector<vector<long long>> &A, const vector<long long> &v)
    {
        int n = A.size();
        vector<long long> res(n, 0);
        for (int i = 0; i < n; i++)
        {
            long long cur = 0;
            for (int j = 0; j < n; j++)
            {
                if (A[i][j] == 0)
                    continue;
                cur = (cur + A[i][j] * v[j]) % MOD;
            }
            res[i] = cur;
        }
        return res;
    }

public:
    int zigZagArrays(int n, int l, int r)
    {
        int m = r - l + 1;
        int states = 2 * m;
        vector<vector<long long>> T(states, vector<long long>(states, 0));

        for (int x = 0; x < m; x++)
        {
            int downState = x;
            int upState = x + m;

            for (int y = x + 1; y < m; y++)
            {
                T[y][upState] = 1;
            }

            for (int y = 0; y < x; y++)
            {
                T[y + m][downState] = 1;
            }
        }

        vector<long long> start(states, 1);
        vector<vector<long long>> P = power(T, n - 1);
        vector<long long> final_v = multiplyVector(P, start);

        long long total = 0;
        for (long long val : final_v)
        {
            total = (total + val) % MOD;
        }

        return total;
    }
};

int main()
{
    Solution solver;

    cout << "--- Number of ZigZag Arrays II Tests ---" << endl;
    cout << "Test 1: " << solver.zigZagArrays(3, 4, 5) << endl;
    cout << "Test 2: " << solver.zigZagArrays(3, 1, 3) << endl;

    return 0;
}