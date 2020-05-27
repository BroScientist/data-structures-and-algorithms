#include <iostream>
#include <vector>
using namespace std;

struct Block {
    int num;
    int localMin;
};

class MinStack {
public:
    vector<Block> stack;

    MinStack() {}
    
    void push(int x) {
        Block *b = new Block;
        b->num = x;

        // if stack is empty, localMin gets set to the current number
        if (stack.empty()) {
            b->localMin = b->num;
            stack.push_back(*b);
        }
        else {
            // if current localMin is less or equal to the inserted number
            // localMin stays the same and also gets assigned to the current block
            if (stack.back().localMin <= b->num) {
                b->localMin = stack.back().localMin;
            }
            // if current localMin is greater than the inserted number
            // set current localMin to inserted number
            if (stack.back().localMin > b->num) {
                b->localMin = b->num;
            }
            stack.push_back(*b);
        }
    }
    
    // LeetCode promises not to call pop() top() and getMin() on empty stacks
    void pop() {
        stack.pop_back();
    }
    
    int top() {
        return stack.back().num;
    }
    
    int getMin() {
        return stack.back().localMin;
    }
};

int main() {
    // MinStack s;
    // s.push(1);
    // s.push(5);
    // s.push(8);
    // s.push(-1);
    // s.push(3);
    // s.pop();
    // cout << s.top() << endl;
    // cout << s.getMin() << endl;
    MinStack* obj = new MinStack();
    obj->push(1);
    obj->push(5);
    obj->push(7);
    obj->pop();
    obj->push(-1);
    obj->push(0);
    cout << obj->top() << endl;
    cout << obj->getMin() << endl;
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */