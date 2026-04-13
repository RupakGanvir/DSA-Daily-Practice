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
    void deleteNode(ListNode *node)
    {
        if (node->next->next == NULL)
        {
            node->val = node->next->val;
            delete node->next;
            node->next = NULL;
            return;
        }

        node->val = node->next->val;
        deleteNode(node->next);
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
    ListNode *head = new ListNode(4);
    ListNode *node5 = new ListNode(5);
    head->next = node5;
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    Solution sol;
    cout << "Before: ";
    printList(head);

    sol.deleteNode(node5);

    cout << "After:  ";
    printList(head);

    return 0;
}