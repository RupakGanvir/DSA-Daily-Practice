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
private:
    ListNode *getMid(ListNode *head)
    {
        ListNode *midPrev = nullptr;
        while (head != nullptr && head->next != nullptr)
        {
            midPrev = (midPrev == nullptr) ? head : midPrev->next;
            head = head->next->next;
        }
        ListNode *mid = midPrev->next;
        midPrev->next = nullptr;
        return mid;
    }

    ListNode *merge(ListNode *list1, ListNode *list2)
    {
        ListNode dummy(0);
        ListNode *tail = &dummy;

        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val < list2->val)
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

        if (list1 != nullptr)
        {
            tail->next = list1;
        }
        else
        {
            tail->next = list2;
        }

        return dummy.next;
    }

public:
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode *mid = getMid(head);
        ListNode *left = sortList(head);
        ListNode *right = sortList(mid);

        return merge(left, right);
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

    ListNode *head1 = new ListNode(4, new ListNode(2, new ListNode(1, new ListNode(3))));
    ListNode *head2 = new ListNode(-1, new ListNode(5, new ListNode(3, new ListNode(4, new ListNode(0)))));

    cout << "--- Sort Linked List Tests ---" << endl;

    ListNode *res1 = solver.sortList(head1);
    cout << "Test 1: ";
    printList(res1);

    ListNode *res2 = solver.sortList(head2);
    cout << "Test 2: ";
    printList(res2);

    return 0;
}