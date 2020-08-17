#include <vector>
#include <queue>
#include <unordered_set>
#include <map>
using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        // starting with arr[start], use bfs to traverse the array
        // if a value is out of bounds, simply ignore it
        // whenever we visit something, mark it as seen (set of indexes)
        // repeat until found, or queue is empty
        unordered_set<int> seen;  // set of visited indexes
        queue<int> queue;
        int len = arr.size();
        queue.push(start);
        int i = start, curr = arr[start];

        while (!queue.empty())
        {
            // the only hard part about this question is differentiating between index and value
            // i = index, curr = value at arr[i]
            i = queue.front();
            curr = arr[i];
            queue.pop();
            if (curr == 0)
                return true;
            // only push new data to the queue if we have not visited the current index before
            if (seen.find(i) == seen.end())
            {
                if (i + curr < len)
                    queue.push(i + curr);
                if (i - curr >= 0)
                    queue.push(i - curr);
            }
            seen.insert(i);
        }
        
        return false;
    }
};