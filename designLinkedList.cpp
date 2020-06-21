#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class MyLinkedList
{
public:
    /** Initialize your data structure here. */
    ListNode *head, *tail;

    MyLinkedList()
    {
        head = tail = nullptr;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index)
    {
        if (index < 0 || head == nullptr)
            return -1;
        ListNode *curr = head;
        for (int i = 0; i < index; i++)
        {
            if (curr == nullptr || curr->next == nullptr)
                return -1;
            curr = curr->next;
        }
        return curr->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val)
    {
        ListNode *newNode = new ListNode(val);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val)
    {
        ListNode *newNode = new ListNode(val);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val)
    {
        if (index < 0)
            return;
        if (index == 0)
        {
            addAtHead(val);
            return;
        }
        ListNode *curr = head;
        for (int i = 0; i < index - 1; i++)
        {
            if (curr == nullptr)
                return;
            curr = curr->next;
        }
        ListNode *tmpNext = curr->next;
        ListNode *newNode = new ListNode(val);
        curr->next = newNode;
        newNode->next = tmpNext;
        if (newNode->next == nullptr)
            tail = newNode;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index)
    {
        if (index < 0 || head == nullptr)
            return;
        if (index == 0)
        {
            ListNode* tmpNext = head->next;
            delete head;
            head = tmpNext;
            return;
        }
        ListNode *curr = head;
        for (int i = 0; i < index - 1; i++)
        {
            if (curr == nullptr)
                return;
            // obtains the prev node before node to be deleted
            curr = curr->next;
        }
        if (curr->next == nullptr)
        {
            // if node to be deleted is the last node
            return;
        }
        else
        {
            ListNode *tmpNext = curr->next; // this points to the node that we want to delete
            curr->next = curr->next->next;
            delete tmpNext;
            if (curr->next == nullptr)
                tail = curr;
        }
        
    }

    void display()
    {
        ListNode *curr = head;
        while (curr != nullptr)
        {
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main()
{
    /* 
    ["MyLinkedList","addAtHead","addAtIndex","addAtTail","addAtHead","addAtIndex","addAtTail","addAtTail","addAtIndex",|"deleteAtIndex","deleteAtIndex","addAtTail"]
    [[],[0],[1,4],[8],[5],[4,3],[0],[5],[6,3],|[7],[5],[4]]
 */
    MyLinkedList l1;
    // l1.addAtHead(0);
    // l1.addAtIndex(1, 4);
    // l1.addAtTail(8);
    // l1.addAtHead(5);
    // l1.addAtIndex(4, 3);
    // l1.addAtTail(0);
    // l1.addAtTail(5);
    // l1.addAtIndex(6, 3);
    // l1.deleteAtIndex(7);
    // l1.addAtTail(100);
    // l1.deleteAtIndex(5);

    l1.addAtTail(1);
    l1.addAtTail(2);
    l1.addAtTail(3);
    l1.addAtTail(4);
    l1.deleteAtIndex(4);
    // l1.addAtTail(100);
    l1.display();
    // l1.addAtTail(4);

    l1.display();
    return 0;
}