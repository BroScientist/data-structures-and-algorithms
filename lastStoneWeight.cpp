#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap;
        for (int& n : stones)
            heap.push(n);
        while (heap.size() > 1)
        {
            int x = heap.top();
            heap.pop();
            int y = heap.top();
            heap.pop();
            if (x != y)
                x > y ? heap.push(x - y) : heap.push(y - x);
        }
        if (heap.empty())
            return 0;
        return heap.top();
    }
};

int main() {

    return 0;
}