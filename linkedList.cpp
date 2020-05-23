#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

bool isPrime(int n) {
    if (n == 1 || n == 2) return true;
    for (int i = 2; i < n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}



class LinkedList {
private:

public:
    Node *head, *tail;

    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    ~LinkedList() {
        cout << "destructed" << endl;
    }
    
    void insert(int n) {
        Node *temp = new Node;
        temp->data = n;
        temp->next = nullptr;

        if(head == nullptr) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = tail->next;
        }
    }

    void printList() {
        Node *curr = head;
        while (curr != nullptr) {
            cout << curr->data << " -> ";
            curr = curr->next;
        }
        cout << endl;
    }

    void removeDuplicates() {
        // if (head == nullptr) return head; (how is this a test case)
        Node *curr = head;
        while (curr->next != nullptr)
        {
            if (curr->data == curr->next->data) {
                curr->next = curr->next->next;
                if (curr->next == nullptr) break;
            }
            curr = (curr->data == curr->next->data) ? curr : curr->next;
        }
        
    }

    void reverse() {
        Node *curr = head;
        Node *prev = nullptr;
        while (curr != nullptr) {
            Node *tempNext = curr->next;
            // swap the link between prev and curr, then increment curr
            curr->next = prev;
            prev = curr;
            curr = tempNext;
        }
        head = prev;
    }

    void deleteNode(int x) {
        Node *curr = head;
        Node *prev = nullptr;
        while (curr != nullptr) {
            if (curr->data == x) {
                if (prev == nullptr) {
                    head = curr->next;
                    curr->next = nullptr;
                    break;
                }
                prev->next = curr->next;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    void removeElements(int x) {
        Node *curr = head;
        Node *prev = nullptr;
        while(curr != nullptr) {
            if (curr->data == x) {
                Node *nextTemp = curr->next;
                // if the current head is equal to x
                if (prev == nullptr) {
                    curr->next = nullptr;
                    curr = nextTemp;
                    head = curr;
                    continue;
                }
                prev->next = curr->next;
                curr = nextTemp;
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }
    }

    void deletePrimes() {
        Node *curr = head;
        Node *prev = head;
        bool flag = true;
        while (curr != nullptr) {
            // if head node is prime
            if (flag && isPrime(curr->data)) {
                head = curr->next;
                prev = head;
                delete curr;
            }
            else if (isPrime(curr->data)) {
                prev->next = curr->next;
                delete curr;
            }
            else {
                prev = curr;  // only increment prev if current node was not removed
                flag = false;
            }
            curr = curr->next;
        }
    }
/*
    bool hasCycle() {
        // store every element before tail, see if tail->next is equal to any of these
        Node *curr = head;
        if (curr == nullptr) return false;
        if (curr->next == nullptr) return false;
        vector<Node*> seen = {};
        while (curr != nullptr) {
            // if next is not null and has been seen before, return true
            if (find(seen.begin(), seen.end(), curr) != seen.end()) {
                // seen contains curr
                cout << seen.size() << endl;
                return true;
            } else {
                // seen does not contain curr
                seen.push_back(curr);
                curr = curr->next;
            }
        }
        return false;
    }
    */
};

LinkedList mergeTwoLists(LinkedList l1, LinkedList l2) {
    LinkedList newList;
    newList.head = l1.head;
    newList.head->data = l1.head->data;
    Node *curr = l2.head;
    Node *head = l1.head;
    while (curr != nullptr) {
        if (curr->data <= head->next->data)
        {
            curr->next = head->next;
            head = curr;
            newList.insert(curr->data);
            curr = curr->next;
        }
        else {
            newList.insert(head->data);
            head = head->next;
            curr = curr->next;
        }
    }
    return newList;
}


int main() {

    LinkedList l1;
    l1.insert(3);
    l1.insert(3);
    l1.insert(3);
    l1.insert(3);


    cout << "original list: " << endl;
    l1.printList();

    cout << "node removed list: " << endl;
    l1.removeElements(3);
    l1.printList();
    return 0;
}