class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        int total = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for (int& stick : sticks)
            pq.push(stick);
        
        while (pq.size() > 1)
        {
            int stick1 = pq.top();
            pq.pop();
            int stick2 = pq.top();
            pq.pop();
            
            total += stick1 + stick2;
            pq.push(stick1 + stick2);
        }
        
        return total;
    }
};