#include <iostream>
using namespace std;

struct ListNode
{
    int data;
    ListNode *next;
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
    if (l1 == nullptr)
        return l2;
    if (l2 == nullptr)
        return l1;
    if (l1->data < l2->data)
    {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}