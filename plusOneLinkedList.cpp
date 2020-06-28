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

ListNode *plusOne(ListNode *head)
{
    // reverse the list such that the least significant digit is the head
    // increment the head value by 1, if this value becomes >= 10, minus 10 from it and increment head->next until next next after increment is smaller than 10
    // reverse the list again to obtain the final answer
    if (head == nullptr)
        return head;
    head = reverse(head);
    ListNode *curr = head;
    // increment the value of the first node in the reversed list
    curr->data++;
    // while curr's data is greater or equal to 10, it needs modifcation
    while (curr->data >= 10)
    {
        curr->data -= 10;
        // handles the special case where the last node also needs modifying
        // in this case, create a new linked list node with value 1 and next pointed to null, and appened to the end of the list
        if (curr->next == nullptr)
        {
            ListNode *newNode = new ListNode;
            newNode->data = 1;
            newNode->next = nullptr;
            curr->next = newNode;
            break;
        }
        curr->next->data++;
        curr = curr->next;
    }
    // finally, reverse the list to obtain the proper order
    head = reverse(head);
    curr = head;
    // while(curr != nullptr)
    // {
    //     cout << curr->data << endl;
    //     curr = curr->next;
    // }
    return head;
}