#include <iostream>
#include <map>

using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return NULL;

        Node *curr = head;
        while (curr)
        {
            Node *temp = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = temp;
            curr = temp;
        }

        curr = head;
        while (curr)
        {
            if (curr->random)
            {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        Node *dummy = new Node(0);
        Node *copyCurr = dummy;
        curr = head;

        while (curr)
        {
            copyCurr->next = curr->next;
            copyCurr = copyCurr->next;

            curr->next = curr->next->next;
            curr = curr->next;
        }

        return dummy->next;
    }
};

void printList(Node *head)
{
    Node *curr = head;
    while (curr)
    {
        int rVal = (curr->random) ? curr->random->val : -1;
        cout << "[Val: " << curr->val << ", Random: " << rVal << "] -> ";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node *n1 = new Node(7);
    Node *n2 = new Node(13);
    Node *n3 = new Node(11);
    Node *n4 = new Node(10);
    Node *n5 = new Node(1);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    n1->random = NULL;
    n2->random = n1;
    n3->random = n5;
    n4->random = n3;
    n5->random = n1;

    cout << "Original List:" << endl;
    printList(n1);

    Solution sol;
    Node *copiedList = sol.copyRandomList(n1);

    cout << "\nCopied List:" << endl;
    printList(copiedList);

    cout << "\nMemory Check: Original Head (" << n1 << ") vs Copied Head (" << copiedList << ")" << endl;

    return 0;
}