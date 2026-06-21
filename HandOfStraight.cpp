#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        if (hand.size() % groupSize != 0)
        {
            return false;
        }

        map<int, int> count;
        for (int card : hand)
        {
            count[card]++;
        }

        // Safe iterator loop compatible across C++11, C++14, and C++17
        for (auto it = count.begin(); it != count.end(); ++it)
        {
            int card = it->first;
            int freq = it->second;

            if (freq > 0)
            {
                int current_freq = freq;
                for (int i = 0; i < groupSize; i++)
                {
                    int next_card = card + i;

                    // Use find() instead of [] to safely check without inserting keys
                    auto next_it = count.find(next_card);
                    if (next_it == count.end() || next_it->second < current_freq)
                    {
                        return false;
                    }
                    next_it->second -= current_freq;
                }
            }
        }

        return true;
    }
};

int main()
{
    Solution solver;

    vector<int> hand1 = {1, 2, 3, 6, 2, 3, 4, 7, 8};
    int groupSize1 = 3;

    vector<int> hand2 = {1, 2, 3, 4, 5};
    int groupSize2 = 4;

    cout << "--- Hand of Straights Tests ---" << endl;
    cout << "Test 1: " << (solver.isNStraightHand(hand1, groupSize1) ? "true" : "false") << endl;
    cout << "Test 2: " << (solver.isNStraightHand(hand2, groupSize2) ? "true" : "false") << endl;

    return 0;
}