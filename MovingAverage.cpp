#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class MovingAverage {
public:
    int size_limit;
    vector<int> q;
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        size_limit = size;
    }
    
    double next(int val) {
        // if queue is full, dequeue and push the current element
        if (q.size() == size_limit) q.erase(q.begin());
        q.push_back(val);
        double sum = accumulate(q.begin(), q.end(), 0);
        return sum / q.size();
    }
};

int main() {
    
    MovingAverage* obj = new MovingAverage(3);
    double param_1 = obj->next(5);
    cout << param_1 << endl;
    // MovingAverage m(3);
    // m.next(100);
    // m.next(5);
    // m.next(6);
    // m.next(111);
    // cout << m.next(200) << endl;
    
    return 0;
}