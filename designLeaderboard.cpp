#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Compare {
public:
    bool operator () (pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
}; 

class Leaderboard {
public:
    unordered_map<int, int> table;
    priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> heap;
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        table[playerId] += score;
    }
    
    int top(int K) {
        for (auto& item : table)
        {
            heap.push(item);
            if (heap.size() > K)
                heap.pop();
        }
        int total = 0;
        while (!heap.empty())
        {
            total += heap.top().second;
            heap.pop();
        }
        return total;
    }
    
    void reset(int playerId) {
        table.erase(playerId);
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */