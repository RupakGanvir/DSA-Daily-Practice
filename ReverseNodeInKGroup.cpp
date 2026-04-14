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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *curr = head;
        for (int i = 0; i < k; i++)
        {
            if (curr == NULL)
                return head;
            curr = curr->next;
        }

        ListNode *prev = NULL;
        ListNode *nextNode = NULL;
        curr = head;
        for (int i = 0; i < k; i++)
        {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        if (nextNode != NULL)
        {
            head->next = reverseKGroup(nextNode, k);
        }

        return prev;
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
    head = sol.reverseKGroup(head, 2);

    cout << "Reversed in groups of 2: ";
    printList(head);

    return 0;
}