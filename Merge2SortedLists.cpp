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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode dummy(0);
        ListNode *tail = &dummy;

        while (list1 != NULL && list2 != NULL)
        {
            if (list1->val <= list2->val)
            {
                tail->next = list1;
                list1 = list1->next;
            }
            else
            {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        if (list1 != NULL)
        {
            tail->next = list1;
        }
        else
        {
            tail->next = list2;
        }

        return dummy.next;
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
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);

    ListNode *l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    Solution sol;
    ListNode *merged = sol.mergeTwoLists(l1, l2);

    cout << "Merged List: ";
    printList(merged);

    return 0;
}