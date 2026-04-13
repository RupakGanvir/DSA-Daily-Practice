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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *fast = dummy;
        ListNode *slow = dummy;

        for (int i = 0; i <= n; i++)
        {
            fast = fast->next;
        }

        while (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode *nodeToDelete = slow->next;
        slow->next = slow->next->next;
        delete nodeToDelete;

        return dummy->next;
    }
};

void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    head = sol.removeNthFromEnd(head, 2);

    cout << "Updated List: ";
    printList(head);

    return 0;
}