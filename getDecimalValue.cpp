#include <iostream>
#include <math.h>
using namespace std;

struct ListNode
{
    int data;
    ListNode *next;
};

int getDecimalValue(ListNode *head)
{
    int sum = 0;
    vector<int> nums;
    while (head != nullptr)
    {
        nums.push_back(head->data);
        head = head->next;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
            sum += pow(2, nums.size() - i - 1);
    }

    // cout << sum << endl;
    return sum;
}