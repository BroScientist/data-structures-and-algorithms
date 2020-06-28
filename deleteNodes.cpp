#include <iostream>
using namespace std;

struct ListNode
{
    int data;
    ListNode *next;
};

// delete N nodes after M nodes in a linked list
ListNode *deleteNodes(ListNode *head, int m, int n)
{
    ListNode *curr = head;
    while (true)
    {
        for (int i = 0; i < m - 1; i++)
        {
            // traverse
            if (curr == nullptr)
                break;
            curr = curr->next;
        }
        ListNode *tmp = curr->next;
        if (tmp == nullptr)
            break;
        for (int i = 0; i < n; i++)
        {
            // advance tmp to the node that should be the next of curr
            if (tmp == nullptr)
            {
                curr->next = nullptr;
                return head;
            }
            tmp = tmp->next;
        }
        curr->next = tmp;
        curr = tmp;
    }
    return head;
}