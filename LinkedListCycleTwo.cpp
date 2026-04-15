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
    ListNode *detectCycle(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return NULL;

        ListNode *slow = head;
        ListNode *fast = head;
        bool hasCycle = false;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                hasCycle = true;
                break;
            }
        }

        if (!hasCycle)
            return NULL;

        fast = head;
        while (fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }

        return fast;
    }
};

int main()
{
    ListNode *head = new ListNode(3);
    ListNode *entry = new ListNode(2);
    head->next = entry;
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = entry;

    Solution sol;
    ListNode *result = sol.detectCycle(head);

    if (result)
    {
        cout << "Cycle begins at node with value: " << result->val << endl;
    }
    else
    {
        cout << "No cycle detected." << endl;
    }

    return 0;
}