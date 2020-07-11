
#include <iostream>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


class Solution {
public:
    // if node has no child, don't do shit
    // if it has a child, store a reference to curr->next as tmp, link node and child
    // perform this recursively until curr has reached the end of the list
    void relink(Node* curr, Node* end)
    {
        while (curr->child || curr->next)
        {
            if (curr->child)
            {
                Node* tmpNext = curr->next;
                curr->next = curr->child;
                curr->next->prev = curr;
                curr->child = nullptr;  // remember the detach the kid... otherwise it's not a valid DDL
                relink(curr->next, tmpNext);
                if (tmpNext) // this is for the case where the original curr->next was already nullptr
                    curr = tmpNext;
            }
            else
                curr = curr->next;
            
        }
        if (end)
            end->prev = curr;
        curr->next = end;
        return;
    }
    Node* flatten(Node* head) {
        if (!head)
            return head;
        relink(head, nullptr);
        return head;
    }
};