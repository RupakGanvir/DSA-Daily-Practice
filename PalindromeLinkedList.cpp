#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return true;

        ListNode *slow = head, *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *prev = NULL;
        ListNode *curr = slow;
        while (curr != NULL)
        {
            ListNode *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        ListNode *left = head;
        ListNode *right = prev;
        while (right != NULL)
        {
            if (left->val != right->val)
                return false;
            left = left->next;
            right = right->next;
        }

        return true;
    }
};

ListNode *createList(vector<int> arr)
{
    if (arr.empty())
        return NULL;
    ListNode *head = new ListNode(arr[0]);
    ListNode *curr = head;
    for (size_t i = 1; i < arr.size(); i++)
    {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

int main()
{
    Solution sol;

    vector<int> v1 = {1, 2, 2, 1};
    ListNode *head1 = createList(v1);

    if (sol.isPalindrome(head1))
    {
        cout << "Test 1: {1, 2, 2, 1} is a Palindrome." << endl;
    }
    else
    {
        cout << "Test 1: {1, 2, 2, 1} is NOT a Palindrome." << endl;
    }

    vector<int> v2 = {1, 2, 3};
    ListNode *head2 = createList(v2);

    if (sol.isPalindrome(head2))
    {
        cout << "Test 2: {1, 2, 3} is a Palindrome." << endl;
    }
    else
    {
        cout << "Test 2: {1, 2, 3} is NOT a Palindrome." << endl;
    }

    return 0;
}