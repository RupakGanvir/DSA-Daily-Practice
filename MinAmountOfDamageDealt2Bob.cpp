#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
    long long minDamage(int power, vector<int> &damage, vector<int> &health)
    {
        int n = damage.size();
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);

        vector<long long> times(n);
        for (int i = 0; i < n; ++i)
        {
            times[i] = (health[i] + power - 1) / power;
        }

        sort(indices.begin(), indices.end(), [&](int i, int j)
             { return times[i] * damage[j] < times[j] * damage[i]; });

        long long total_damage = 0;
        long long current_time = 0;

        for (int i : indices)
        {
            current_time += times[i];
            total_damage += current_time * damage[i];
        }

        return total_damage;
    }
};

int main()
{
    Solution solver;

    int power1 = 4;
    vector<int> damage1 = {1, 2, 3, 4};
    vector<int> health1 = {4, 5, 6, 8};
    cout << solver.minDamage(power1, damage1, health1) << "\n";

    int power2 = 1;
    vector<int> damage2 = {1, 1, 1, 1};
    vector<int> health2 = {1, 2, 3, 4};
    cout << solver.minDamage(power2, damage2, health2) << "\n";

    int power3 = 8;
    vector<int> damage3 = {40};
    vector<int> health3 = {59};
    cout << solver.minDamage(power3, damage3, health3) << "\n";

    return 0;
}