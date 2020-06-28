#include <iostream>
#include <deque>
using namespace std;

struct ListNode
{
    int data;
    ListNode *next;
};

bool isPalindrome(ListNode *head)
{
    // never forget the empty case...
    if (head == nullptr || head->next == nullptr)
        return true;
    deque<int> d;
    ListNode *curr = head;
    while (curr != nullptr)
    {
        d.push_back(curr->data);
        curr = curr->next;
    }
    // for (int& i : d) cout << i << endl;
    while (1)
    {
        if (d.size() == 1 || d.size() == 0)
            break;
        if (d.front() != d.back())
            return false;
        d.pop_back();
        d.pop_front();
    }
    return true;
}