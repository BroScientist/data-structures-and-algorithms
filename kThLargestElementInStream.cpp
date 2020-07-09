#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class KthLargest {
public:
    priority_queue <double, vector<double>, greater<double> > heap; 
    int K;
    KthLargest(int k, vector<int>& nums) 
    {
        if (nums.size() > 0)
        {
            sort(nums.begin(), nums.end(), greater <int>());
            for (int i = 0; i < k && i < nums.size(); i++)
                heap.push(nums[i]);
        }
        K = k;
    }
    
    int add(int val) 
    {
        if (heap.size() < K)
        {
            heap.push(val);
        }
        else
        {
            if (val > heap.top())
            {
                heap.pop();
                heap.push(val);
            }
        }
        return heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */