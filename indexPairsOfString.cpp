#include <iostream>
#include <vector>
#include <string>
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
    TrieNode* root;
    Trie() 
    {
        root = new TrieNode();
    }
    
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
    
    bool search(string word) 
    {
        TrieNode* node = searchPrefix(word);
        return node != nullptr && node->isEnd;
    }
    
    bool startsWith(string prefix) 
    {
        TrieNode* node = searchPrefix(prefix);
        return node != nullptr;
    }
};

class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        vector<vector<int>> res;
        
        // insert words into trie
        Trie trie = Trie();
        for (string& word : words)
            trie.insert(word);
        
        // if text[i] is in trie, set j = i and do a greedy search text[j] is no longer contained in trie
        for (int i = 0; i < text.size(); i++)
        {
            char c = text[i];
            TrieNode* node = trie.root;
            if (node->containsKey(c))
            {
                for (int j = i; j < text.size(); j++)
                {
                    if (!node->containsKey(text[j]))
                        break;
                    node = node->get(text[j]);
                    if (node->isEnd)
                        res.push_back({i, j});
                }
            }
        }
        return res;
    }
};
