void printInReverse(ListNode *head)
{
    if (head == nullptr)
        return;
    printInReverse(head->next);
    cout << head->data << endl;
}