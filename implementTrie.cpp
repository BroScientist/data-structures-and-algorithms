#include <iostream>
using namespace std;

struct TrieNode
{
    TrieNode* links[26] = {nullptr};
    bool isEnd = false;
    TrieNode() {}
    
    bool containsKey(char c)
    {
        return links[c - 'a'] != nullptr;
    }
    
    TrieNode* get(char c)
    {
        return links[c - 'a'];
    }
    
    void put(char c, TrieNode* node)
    {
        links[c - 'a'] = node;
    }
    
    void setEnd()
    {
        isEnd = true;
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    TrieNode* root;
    Trie() 
    {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) 
    {
        TrieNode* node = root;
        for (char& c : word)
        {
            if (!node->containsKey(c))
                node->put(c, new TrieNode());
            node = node->get(c);
        }
        node->setEnd();
    }
    
    TrieNode* searchPrefix(string& word)
    {
        TrieNode* node = root;
        for (char& c : word)
        {
            if (node->containsKey(c))
                node = node->get(c);
            else
                return nullptr;
        }
        return node;
    }
    /** Returns if the word is in the trie. */
    bool search(string word) 
    {
        TrieNode* node = searchPrefix(word);
        return node != nullptr && node->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) 
    {
        TrieNode* node = searchPrefix(prefix);
        return node != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */