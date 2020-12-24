class FreqStack {
public:
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> group; // stack of numbers with that frequency
    int maxFreq;
    
    FreqStack() 
    {
        maxFreq = 0;
    }
    
    void push(int x) 
    {
        freq[x]++;
        maxFreq = max(maxFreq, freq[x]);
        group[freq[x]].push(x);
    }
    
    int pop() 
    {
        int x = group[maxFreq].top();
        group[maxFreq].pop();
        freq[x]--;
        if (group[maxFreq].empty())
            maxFreq--;
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */