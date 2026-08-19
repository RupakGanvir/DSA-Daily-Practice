#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class LockingTree
{
private:
    vector<int> parent;
    vector<vector<int>> children;
    vector<int> locked_by;

public:
    LockingTree(vector<int> &parent)
    {
        this->parent = parent;
        int n = parent.size();
        children.resize(n);
        locked_by.assign(n, -1);

        for (int i = 1; i < n; ++i)
        {
            children[parent[i]].push_back(i);
        }
    }

    bool lock(int num, int user)
    {
        if (locked_by[num] == -1)
        {
            locked_by[num] = user;
            return true;
        }
        return false;
    }

    bool unlock(int num, int user)
    {
        if (locked_by[num] == user)
        {
            locked_by[num] = -1;
            return true;
        }
        return false;
    }

    bool upgrade(int num, int user)
    {
        if (locked_by[num] != -1)
        {
            return false;
        }

        int curr = parent[num];
        while (curr != -1)
        {
            if (locked_by[curr] != -1)
            {
                return false;
            }
            curr = parent[curr];
        }

        bool has_locked_descendant = false;
        queue<int> q;
        q.push(num);
        vector<int> to_unlock;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (int child : children[node])
            {
                if (locked_by[child] != -1)
                {
                    has_locked_descendant = true;
                    to_unlock.push_back(child);
                }
                q.push(child);
            }
        }

        if (!has_locked_descendant)
        {
            return false;
        }

        for (int descendant : to_unlock)
        {
            locked_by[descendant] = -1;
        }

        locked_by[num] = user;
        return true;
    }
};

int main()
{
    vector<int> parent = {-1, 0, 0, 1, 1, 2, 2};
    LockingTree lockingTree(parent);

    cout << (lockingTree.lock(2, 2) ? "true" : "false") << "\n";
    cout << (lockingTree.unlock(2, 3) ? "true" : "false") << "\n";
    cout << (lockingTree.unlock(2, 2) ? "true" : "false") << "\n";
    cout << (lockingTree.lock(4, 5) ? "true" : "false") << "\n";
    cout << (lockingTree.upgrade(0, 1) ? "true" : "false") << "\n";
    cout << (lockingTree.lock(0, 1) ? "true" : "false") << "\n";

    return 0;
}