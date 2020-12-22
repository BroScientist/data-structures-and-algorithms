class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 1)
            return nums;
        
        vector<int> res;
        priority_queue<int, vector<int>> heap;
        unordered_map<int, int> freq;
        
        // initialize by creating the initial heap and adding the top element to res
        for (int i = 0; i < k; i++)
            heap.push(nums[i]), freq[nums[i]]++;
        res.push_back(heap.top());
        
        // slide the window of size k
        
        for (int i = 0; i < nums.size() - k; i++)
        {
            // decrease the frequency of the first element in the window (the one that's being removed)
            // if this number happens to be the top of the heap, pop it immediately
            freq[nums[i]]--;
            if (nums[i] == heap.top())
                heap.pop();
            
            // push the next element to extend the window
            heap.push(nums[i + k]);
            freq[nums[i + k]]++;
            
            // there may be dead elements not removed from heap.pop()
            // deal with them by repeatedly popping the top of the heap if their frequency is 0
            while (freq[heap.top()] == 0)
                heap.pop();
            
            // finally, push the top of the heap to res
            res.push_back(heap.top());

        }
        
        return res;
    }
};