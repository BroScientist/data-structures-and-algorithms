#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        // "Maintain two pointers and update one with a delay of n steps." Oh. Wow.
        ListNode *fast = head, *slow = head;
        int size = 0, count = n;
        bool headChange = false;
        while (fast)
        {
            size++;
            fast = fast->next;
            if (count < 0)
            {
                slow = slow->next;
            }
            else
                count--;
        }
        // cout << size << endl;
        // cout << n << endl;
        // cout << slow->val << endl;
        if (size < 2)
            return nullptr;
        if (size == n)
        {
            ListNode* tmp = head->next;
            delete head;
            return tmp;
        }
        ListNode* tmp = slow->next->next;
        delete slow->next;
        slow->next = tmp;
        return head;
    }
};