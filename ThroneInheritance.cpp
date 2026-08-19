#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class ThroneInheritance
{
private:
    string king;
    unordered_map<string, vector<string>> family_tree;
    unordered_set<string> dead;

    void dfs(const string &current, vector<string> &order)
    {
        if (dead.find(current) == dead.end())
        {
            order.push_back(current);
        }
        for (const string &child : family_tree[current])
        {
            dfs(child, order);
        }
    }

public:
    ThroneInheritance(string kingName)
    {
        king = kingName;
    }

    void birth(string parentName, string childName)
    {
        family_tree[parentName].push_back(childName);
    }

    void death(string name)
    {
        dead.insert(name);
    }

    vector<string> getInheritanceOrder()
    {
        vector<string> order;
        dfs(king, order);
        return order;
    }
};

void printVector(const vector<string> &vec)
{
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i)
    {
        cout << "\"" << vec[i] << "\"" << (i + 1 == vec.size() ? "" : ", ");
    }
    cout << "]\n";
}

int main()
{
    ThroneInheritance t("king");

    t.birth("king", "andy");
    t.birth("king", "bob");
    t.birth("king", "catherine");
    t.birth("andy", "matthew");
    t.birth("bob", "alex");
    t.birth("bob", "asha");

    printVector(t.getInheritanceOrder());

    t.death("bob");

    printVector(t.getInheritanceOrder());

    return 0;
}