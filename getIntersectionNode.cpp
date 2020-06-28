#include <iostream>
using namespace std;

struct ListNode
{
    int data;
    ListNode *next;
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    // Hash table approach
    // traverse the first list and store the addresses of its nodes in vector seen
    // traverse the second list, if any node in it is already in seen, return that node
    // 45 / 45 test cases passed, but took too long...

    // Node *curr = headA;
    // vector<Node*> seen = {};
    // while (curr != nullptr)
    // {
    //     seen.push_back(curr);
    //     curr = curr->next;
    // }

    // curr = headB;
    // while (curr != nullptr)

    //     if (find(seen.begin(), seen.end(), curr) != seen.end()) return curr;
    //     curr = curr->next;
    // }

    // return nullptr;

    // Brute force approach
    // for every node in list A, check if any node in B is equal to it
    ListNode *currA = headA;
    ListNode *currB;
    while (currA != nullptr)
    {
        currB = headB;
        while (currB != nullptr)
        {
            if (currA == currB)
                return currA;
            currB = currB->next;
        }
        currA = currA->next;
    }

    return nullptr;
}