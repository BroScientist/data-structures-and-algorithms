#include <iostream>
using namespace std;

struct ListNode
{
    int data;
    ListNode *next;
};

ListNode *reverse(ListNode *head)
{
    ListNode *curr = head;
    ListNode *prev = nullptr;
    while (curr != nullptr)
    {
        ListNode *tempNext = curr->next;
        // swap the link between prev and curr, then increment curr
        curr->next = prev;
        prev = curr;
        curr = tempNext;
    }
    head = prev;
    return head;
}