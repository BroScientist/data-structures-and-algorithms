#include <iostream>
#include <stack>
using namespace std;

class MaxStack {
public:
    // initialize a stack of pairs, where pair.first = number and pair.second = current max
    // also initialize a tmp stack for holding items during the popMax operation
    stack<pair<int,int>> stack, tmpStack;    

    MaxStack() {
        
    }
    
    void push(int x) {
        if (stack.empty())
            stack.push(make_pair(x, x));
        else
        {
            // if x is larger than the current max, set it's max attribute as itself
            if (x > stack.top().second)
                stack.push(make_pair(x, x));
            // otherwise, this pair's max is set to be the current max, represented by the max of the top of the stack
            else
                stack.push(make_pair(x, stack.top().second));
        }
    }
    
    int pop() {
        int tmp = stack.top().first;
        stack.pop();
        return tmp;
    }
    
    int top() {
        return stack.top().first;
    }
    
    int peekMax() {
        return stack.top().second;
    }
    
    int popMax() {
        int maxElem = stack.top().second;
        for (;;)
        {
            if (stack.top().first == maxElem)
            {
                stack.pop();
                break;
            }
            tmpStack.push(stack.top());
            stack.pop();
        }
        while (!tmpStack.empty())
        {
            push(tmpStack.top().first);
            tmpStack.pop();
        }
        return maxElem;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */