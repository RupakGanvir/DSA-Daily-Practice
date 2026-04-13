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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == NULL || headB == NULL)
            return NULL;

        ListNode *a = headA;
        ListNode *b = headB;
        while (a != b)
        {
            a = (a == NULL) ? headB : a->next;
            b = (b == NULL) ? headA : b->next;
        }

        return a;
    }
};

void printList(ListNode *node)
{
    while (node)
    {
        cout << node->val << " -> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Solution sol;

    ListNode *common = new ListNode(8);
    common->next = new ListNode(4);
    common->next->next = new ListNode(5);

    ListNode *headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = common;

    ListNode *headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = common;

    cout << "List A ends with the common section." << endl;
    cout << "List B ends with the same common section." << endl;

    ListNode *intersection = sol.getIntersectionNode(headA, headB);

    if (intersection)
    {
        cout << "\nIntersection found at node with value: " << intersection->val << endl;
        // cout << "Memory Address: " << intersection << endl;
    }
    else
    {
        cout << "\nNo intersection found." << endl;
    }

    return 0;
}