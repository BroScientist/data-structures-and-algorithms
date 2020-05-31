#include <iostream>
#include <vector>
using namespace std;


class CustomStack {

public:
    vector<int> stack;
    int maxSize;
    
    
    CustomStack(int i) { maxSize = i;}
    
    void push(int x) {
        if (stack.size() < maxSize) stack.push_back(x);
    }

    int pop() {
        if (stack.size() <= 0) return -1;
        int top = stack.back();
        stack.pop_back();
        return top;
    }
    
    void increment(int k, int val) {
        if (k > stack.size()) k = stack.size();
        for (int i = 0; i < k; i++) stack[i] += val;
    }

    void display() {
        for (int& i : stack) cout << i << " ";
        cout << endl;
    }

};

int main() {
    // vector<int> nums = {1, 3, 5, 7};
    // cout << nums.back() << endl;
    // nums[0] += 100;
    // for (int i = 0; i < 3; i++) nums[i] += 100;
    // for (int& i : nums) cout << i << endl;
    // cout << nums.pop_back() << endl;
    // int maxSize = 30;
    CustomStack* obj = new CustomStack(3);
    obj->push(1);
    obj->push(2);
    obj->push(3);
    obj->push(4);
    obj->push(5);
    obj->push(6);
    int param_2 = obj->pop();
    obj->display();
    obj->increment(2,100);
    obj->display();
    obj->pop();
    obj->pop();
    obj->pop();
    obj->pop();
    obj->display();

}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */