#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

class Solution
{
private:
    unordered_map<string, vector<string>> adj;
    unordered_map<string, int> visited_level;
    vector<vector<string>> ans;

    void dfs(const string &word, const string &beginWord, vector<string> &path)
    {
        if (word == beginWord)
        {
            vector<string> curr_path = path;
            reverse(curr_path.begin(), curr_path.end());
            ans.push_back(curr_path);
            return;
        }

        int curr_level = visited_level[word];
        for (const string &prev : adj[word])
        {
            if (visited_level.find(prev) != visited_level.end() && visited_level[prev] == curr_level - 1)
            {
                path.push_back(prev);
                dfs(prev, beginWord, path);
                path.pop_back();
            }
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end())
            return {};

        queue<string> q;
        q.push(beginWord);
        visited_level[beginWord] = 0;
        dict.erase(beginWord);

        bool found = false;

        while (!q.empty() && !found)
        {
            int size = q.size();
            unordered_set<string> local_visited;

            for (int i = 0; i < size; ++i)
            {
                string curr = q.front();
                q.pop();

                string temp = curr;
                for (int j = 0; j < temp.size(); ++j)
                {
                    char original = temp[j];
                    for (char c = 'a'; c <= 'z'; ++c)
                    {
                        if (c == original)
                            continue;
                        temp[j] = c;

                        if (dict.find(temp) != dict.end())
                        {
                            if (visited_level.find(temp) == visited_level.end())
                            {
                                visited_level[temp] = visited_level[curr] + 1;
                                q.push(temp);
                                local_visited.insert(temp);
                            }
                            if (visited_level[temp] == visited_level[curr] + 1)
                            {
                                adj[temp].push_back(curr);
                            }
                            if (temp == endWord)
                                found = true;
                        }
                    }
                    temp[j] = original;
                }
            }
            for (const string &word : local_visited)
            {
                dict.erase(word);
            }
        }

        if (found)
        {
            vector<string> path = {endWord};
            dfs(endWord, beginWord, path);
        }

        return ans;
    }
};

int main()
{
    Solution solver;

    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    vector<vector<string>> result = solver.findLadders(beginWord, endWord, wordList);

    for (const auto &path : result)
    {
        for (int i = 0; i < path.size(); ++i)
        {
            cout << path[i] << (i == path.size() - 1 ? "" : " -> ");
        }
        cout << "\n";
    }

    return 0;
}