#include <iostream>
using namespace std;

struct ListNode
{
    int data;
    ListNode *next;
};

LinkedList sumTwoLists(LinkedList l1, LinkedList l2)
{
    // create a new list and insert the value of every node in l1 into this new list
    LinkedList newList;
    ListNode *curr = l1.head;
    while (curr != nullptr)
    {
        newList.insert(curr->data);
        curr = curr->next;
    }

    // navigate l2 and while new list has not been exhausted, add it's value at the respective positon in new list
    // if new list has been exhuasted, start creating new nodes for new list using values from l2
    curr = l2.head;
    ListNode *list1Curr = newList.head;
    while (curr != nullptr)
    {
        if (list1Curr == nullptr)
        {
            newList.insert(curr->data);
            curr = curr->next;
        }
        else
        {
            list1Curr->data += curr->data;
            list1Curr = list1Curr->next;
            curr = curr->next;
        }
    }

    curr = newList.head;
    while (curr != nullptr)
    {
        if (curr->data >= 10)
        {
            curr->data = curr->data % 10;
            curr->next->data += 1;
        }
        if (curr->next == nullptr && curr->data >= 10)
        {
            curr->data = curr->data % 10;
            ListNode *tmp;
            tmp->data = 1;
            curr->next = tmp;
            tmp->next = nullptr;
            break;
        }
        curr = curr->next;
    }
    return newList;
}