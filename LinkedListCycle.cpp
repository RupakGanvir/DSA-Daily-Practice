#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return false;
        }

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    ListNode *head = new ListNode(3);
    ListNode *cycleStart = new ListNode(2);
    head->next = cycleStart;
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = cycleStart;

    Solution sol;
    if (sol.hasCycle(head))
    {
        cout << "Cycle detected!" << endl;
    }
    else
    {
        cout << "No cycle detected." << endl;
    }

    return 0;
}