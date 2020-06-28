#include <iostream>
using namespace std;

struct ListNode
{
    int data;
    ListNode *next;
};

ListNode* swapPairs(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode* curr = head;
    ListNode *tmpNext, *tmpNextNext;
    head = head->next;
    while (curr->next != nullptr)
    {
        tmpNext = curr->next;
        tmpNextNext = tmpNext->next;
        if (curr->next->next == nullptr)
            curr->next = nullptr;
        // this handles the case where the list has odd number of elements (excluding nullptr)
        else if (curr->next->next->next == nullptr)
            curr->next = curr->next->next;
        // else, handle the case where the list has even number of elements
        else
            curr->next = curr->next->next->next;
        tmpNext->next = curr;
        curr = tmpNextNext;
        if (curr == nullptr)
            break;
    }
    return head;
}