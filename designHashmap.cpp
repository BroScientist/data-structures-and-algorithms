#include <vector>
#include <list>
using namespace std;

class Bucket
{
public:
    list<pair<int,int>> bucket;
    Bucket() {}
    int get(int key)
    {
        for (pair<int,int>& pair : bucket)
            if (pair.first == key)
                return pair.second;
        return -1;
    }
    
    void update(int key, int value)
    {
        bool found = false;
        for (pair<int,int>& pair : bucket)
        {
            if (pair.first == key)
            {
                found = true;
                pair.second = value;
            }
        }
        if (!found)
            bucket.push_back(make_pair(key, value));
    }
    
    void remove(int key)
    {
        for (pair<int,int>& pair : bucket)
        {
            if (pair.first == key)
            {
                bucket.remove(pair);
                break;
            }
        }
    }  
};
class MyHashMap {
public:
    /** Initialize your data structure here. */
    vector<Bucket> hashtable;
    MyHashMap() {
        for (int i = 0; i < 2069; i++)
            hashtable.push_back(Bucket());
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int hashkey = key % 2069;
        hashtable[hashkey].update(key, value);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int hashkey = key % 2069;
        return hashtable[hashkey].get(key);
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int hashkey = key % 2069;
        hashtable[hashkey].remove(key);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
