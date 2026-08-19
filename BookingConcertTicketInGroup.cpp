#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class BookMyShow
{
private:
    vector<long long> sum_tree;
    vector<int> max_tree;
    vector<int> seats;
    int n, m;
    int min_row;

    void build(int node, int l, int r)
    {
        if (l == r)
        {
            sum_tree[node] = m;
            max_tree[node] = m;
            return;
        }
        int mid = l + (r - l) / 2;
        build(2 * node, l, mid);
        build(2 * node + 1, mid + 1, r);
        sum_tree[node] = sum_tree[2 * node] + sum_tree[2 * node + 1];
        max_tree[node] = max(max_tree[2 * node], max_tree[2 * node + 1]);
    }

    void update(int node, int l, int r, int idx, int val)
    {
        if (l == r)
        {
            sum_tree[node] = val;
            max_tree[node] = val;
            return;
        }
        int mid = l + (r - l) / 2;
        if (idx <= mid)
        {
            update(2 * node, l, mid, idx, val);
        }
        else
        {
            update(2 * node + 1, mid + 1, r, idx, val);
        }
        sum_tree[node] = sum_tree[2 * node] + sum_tree[2 * node + 1];
        max_tree[node] = max(max_tree[2 * node], max_tree[2 * node + 1]);
    }

    long long query_sum(int node, int l, int r, int ql, int qr)
    {
        if (ql > r || qr < l)
            return 0;
        if (ql <= l && r <= qr)
            return sum_tree[node];
        int mid = l + (r - l) / 2;
        return query_sum(2 * node, l, mid, ql, qr) + query_sum(2 * node + 1, mid + 1, r, ql, qr);
    }

    int query_gather(int node, int l, int r, int maxRow, int k)
    {
        if (max_tree[node] < k || l > maxRow)
            return -1;
        if (l == r)
            return l;
        int mid = l + (r - l) / 2;
        int res = query_gather(2 * node, l, mid, maxRow, k);
        if (res == -1)
        {
            res = query_gather(2 * node + 1, mid + 1, r, maxRow, k);
        }
        return res;
    }

public:
    BookMyShow(int n, int m) : n(n), m(m), min_row(0)
    {
        seats.assign(n, m);
        sum_tree.assign(4 * n, 0);
        max_tree.assign(4 * n, 0);
        build(1, 0, n - 1);
    }

    vector<int> gather(int k, int maxRow)
    {
        int r = query_gather(1, 0, n - 1, maxRow, k);
        if (r == -1)
            return {};

        int c = m - seats[r];
        seats[r] -= k;
        update(1, 0, n - 1, r, seats[r]);

        return {r, c};
    }

    bool scatter(int k, int maxRow)
    {
        if (query_sum(1, 0, n - 1, 0, maxRow) < k)
        {
            return false;
        }

        for (int i = min_row; i <= maxRow && k > 0; ++i)
        {
            if (seats[i] > 0)
            {
                int take = min(k, seats[i]);
                seats[i] -= take;
                k -= take;
                update(1, 0, n - 1, i, seats[i]);
            }
            if (seats[i] == 0)
            {
                min_row = max(min_row, i + 1);
            }
        }

        return true;
    }
};

void printVector(const vector<int> &vec)
{
    if (vec.empty())
    {
        cout << "[]\n";
        return;
    }
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << (i + 1 == vec.size() ? "" : ", ");
    }
    cout << "]\n";
}

int main()
{
    BookMyShow bms(2, 5);

    printVector(bms.gather(4, 0));
    printVector(bms.gather(2, 0));
    cout << (bms.scatter(5, 1) ? "true" : "false") << "\n";
    cout << (bms.scatter(5, 1) ? "true" : "false") << "\n";

    return 0;
}