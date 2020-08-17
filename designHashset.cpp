#include <vector>
#include <list>
using namespace std;

class Bucket
{
public:
    list<int> container;
    Bucket() {}
    void insert(int key)
    {
        if (find(begin(container), end(container), key) == container.end())
            container.push_front(key);
    }
    
    void deleteKey(int key)
    {
        container.remove(key);
    }
    
    bool contains(int key)
    {
        return find(begin(container), end(container), key) != container.end();
    }
};
class MyHashSet {
public:
    /** Initialize your data structure here. */
    int keyRange = 769;
    vector<Bucket> bucketArray;
    MyHashSet() {
        for (int i = 0; i < keyRange; i++)
            bucketArray.push_back(Bucket());
    }
    
    void add(int key) {
        int index = key % keyRange;
        bucketArray[index].insert(key);
    }
    
    void remove(int key) {
        int index = key % keyRange;
        bucketArray[index].deleteKey(key);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int index = key % keyRange;
        return bucketArray[index].contains(key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */