#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    unordered_set<int> seen;
    void dfs(int key, vector<vector<int>>& rooms)
    {
        if (rooms[key].size() == 0)
            return;
        // if a key in the current room leads to a previously unseen room, add it to seen and call dfs with it
        // otherwise, this key has already been processed and we ignore it
        for (int& newKey : rooms[key])
        {
            if (seen.find(newKey) == seen.end())
            {
                seen.insert(newKey);
                dfs(newKey, rooms);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // start with inserting room 0 and calling dfs with room 0
        seen.insert(0);
        dfs(0, rooms);
        return seen.size() == rooms.size();
    }
};