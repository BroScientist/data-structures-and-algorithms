class HitCounter {
public:
    /** Initialize your data structure here. */
    vector<int> times;
    HitCounter() {
        
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        times.push_back(timestamp);
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        int count = 0;
        int minVal = timestamp - 300 > 0 ? timestamp - 300 : 0;
        for (int i = times.size() - 1; i >= 0; i--)
            if (times[i] > minVal)
                count++;
        return count;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */