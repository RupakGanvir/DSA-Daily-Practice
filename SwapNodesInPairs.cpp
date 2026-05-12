#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;

        while (prev->next && prev->next->next)
        {
            ListNode *first = prev->next;
            ListNode *second = prev->next->next;

            first->next = second->next;
            second->next = first;
            prev->next = second;

            prev = first;
        }

        ListNode *newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};

void printList(ListNode *head)
{
    while (head)
    {
        std::cout << head->val << (head->next ? " -> " : "");
        head = head->next;
    }
    std::cout << std::endl;
}

int main()
{
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));

    std::cout << "Original List: ";
    printList(head);

    Solution sol;
    head = sol.swapPairs(head);

    std::cout << "Swapped List:  ";
    printList(head);

    return 0;
}