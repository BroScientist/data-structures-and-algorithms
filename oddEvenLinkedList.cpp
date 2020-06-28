#include <iostream>
using namespace std;

struct ListNode
{
    int data;
    ListNode *next;
};

ListNode *oddEvenList(ListNode *head)
{
    if (head == nullptr)
        return head;
    ListNode *curr1 = head;
    ListNode *curr2 = head->next;
    if (curr2 == nullptr || curr2->next == nullptr)
        return head;
    ListNode *head2 = head->next;
    while (curr1->next != nullptr && curr2->next != nullptr)
    {
        // ListNode *tmpNext1 = curr1->next->next;
        // ListNode *tmpNext2 = curr2->next->next;
        curr1->next = curr1->next->next;
        curr2->next = curr2->next->next;
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    curr1->next = head2;
    ListNode *curr = head;
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
    return head;
}