#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class TrieNode
{
public:
    TrieNode *children[2];

    TrieNode()
    {
        children[0] = nullptr;
        children[1] = nullptr;
    }
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(int number)
    {
        TrieNode *currentNode = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (number >> i) & 1;
            if (currentNode->children[bit] == nullptr)
            {
                currentNode->children[bit] = new TrieNode();
            }
            currentNode = currentNode->children[bit];
        }
    }

    int getMaximumXor(int number)
    {
        TrieNode *currentNode = root;
        int currentMaxXor = 0;

        for (int i = 31; i >= 0; i--)
        {
            int bit = (number >> i) & 1;
            int oppositeBit = 1 - bit;

            if (currentNode->children[oppositeBit] != nullptr)
            {
                currentMaxXor = currentMaxXor | (1 << i);
                currentNode = currentNode->children[oppositeBit];
            }
            else
            {
                currentNode = currentNode->children[bit];
            }
        }

        return currentMaxXor;
    }
};

class Solution
{
public:
    int findMaximumXOR(vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }

        Trie prefixTree;
        int maximumResult = 0;

        prefixTree.insert(nums[0]);

        for (int i = 1; i < nums.size(); i++)
        {
            maximumResult = max(maximumResult, prefixTree.getMaximumXor(nums[i]));
            prefixTree.insert(nums[i]);
        }

        return maximumResult;
    }
};

int main()
{
    Solution solver;

    vector<int> numbers1 = {3, 10, 5, 25, 2, 8};
    cout << solver.findMaximumXOR(numbers1) << "\n";

    vector<int> numbers2 = {14, 70, 53, 83, 49, 91, 36, 80, 92, 51, 66, 70};
    cout << solver.findMaximumXOR(numbers2) << "\n";

    vector<int> numbers3 = {2, 4};
    cout << solver.findMaximumXOR(numbers3) << "\n";

    vector<int> numbers4 = {8, 10, 2};
    cout << solver.findMaximumXOR(numbers4) << "\n";

    vector<int> numbers5 = {0};
    cout << solver.findMaximumXOR(numbers5) << "\n";

    vector<int> numbers6 = {2147483647, 0};
    cout << solver.findMaximumXOR(numbers6) << "\n";

    return 0;
}