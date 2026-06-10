#include <iostream>

using namespace std;

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
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *evenHead = even;

        while (even != nullptr && even->next != nullptr)
        {
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenHead;
        return head;
    }
};

void printList(ListNode *head)
{
    ListNode *temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << (temp->next != nullptr ? " -> " : "");
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Solution solver;

    ListNode *head1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    ListNode *head2 = new ListNode(2, new ListNode(1, new ListNode(3, new ListNode(5, new ListNode(6, new ListNode(4, new ListNode(7)))))));

    cout << "--- Odd Even Linked List Tests ---" << endl;

    ListNode *res1 = solver.oddEvenList(head1);
    cout << "Test 1: ";
    printList(res1);

    ListNode *res2 = solver.oddEvenList(head2);
    cout << "Test 2: ";
    printList(res2);

    return 0;
}