#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        vector<int> freq(26, 0);
        for (char task : tasks)
        {
            freq[task - 'A']++;
        }

        int max_freq = 0;
        for (int f : freq)
        {
            max_freq = max(max_freq, f);
        }

        int max_freq_count = 0;
        for (int f : freq)
        {
            if (f == max_freq)
            {
                max_freq_count++;
            }
        }

        int chunks = max_freq - 1;
        int chunk_size = n + 1;
        int total_slots = chunks * chunk_size + max_freq_count;

        return max((int)tasks.size(), total_slots);
    }
};

int main()
{
    Solution solver;

    vector<char> tasks1 = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n1 = 2;

    vector<char> tasks2 = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n2 = 0;

    vector<char> tasks3 = {'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    int n3 = 2;

    cout << "--- Task Scheduler Tests ---" << endl;
    cout << "Test 1: " << solver.leastInterval(tasks1, n1) << endl;
    cout << "Test 2: " << solver.leastInterval(tasks2, n2) << endl;
    cout << "Test 3: " << solver.leastInterval(tasks3, n3) << endl;

    return 0;
}