#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct compare
{
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val; // Min-heap: parent is smaller than children
    }
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, compare> minHeap;

        for (auto list : lists)
        {
            if (list)
            {
                minHeap.push(list);
            }
        }

        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;

        while (!minHeap.empty())
        {
            ListNode *smallest = minHeap.top();
            minHeap.pop();

            tail->next = smallest;
            tail = tail->next;

            if (smallest->next)
            {
                minHeap.push(smallest->next);
            }
        }

        return dummy->next;
    }
};

void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val << (head->next ? " -> " : "");
        head = head->next;
    }
    cout << endl;
}

int main()
{
    ListNode *l1 = new ListNode(1, new ListNode(4, new ListNode(5)));
    ListNode *l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode *l3 = new ListNode(2, new ListNode(6));

    vector<ListNode *> lists = {l1, l2, l3};

    Solution sol;
    ListNode *result = sol.mergeKLists(lists);

    cout << "Merged List: ";
    printList(result);

    return 0;
}