#include <iostream>
using namespace std;

struct ListNode
{
    int data;
    ListNode *next;
};

ListNode *middleNode(ListNode *head)
{
    // if there are two middle elements, return the second one
    // traverse the list and count the number of nodes
    // traverse again to the node at index int(length/2)

    if (head->next == nullptr)
        return head;

    ListNode *curr = head;
    int count = 0;

    while (curr != nullptr)
    {
        count++;
        curr = curr->next;
    }

    cout << "number of nodes: " << count << endl;

    for (int i = 0; i < count / 2; i++)
    {
        head = head->next;
    }
    cout << "middle node: " << head->data << endl;
    return head;
}