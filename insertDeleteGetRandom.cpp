#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_map<int, int> table;
    vector<int> nums;
    int index = 0;
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (table.find(val) == table.end())
        {
            table[val] = index++;
            nums.push_back(val);
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (table.find(val) != table.end())
        {
            // set the num to be deleted to the last number in the array
            // table[val] contains the index of that element
            nums[table[val]] = nums.back();
            table[nums.back()] = table[val]; 
            nums.pop_back();
            table.erase(val);
            index--;
            return true;
        }
        return false;
    }
    
    /** Get a random element from the                                      set. */
    int getRandom() {
        int i = rand() % nums.size();
        return (nums[i]);
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
