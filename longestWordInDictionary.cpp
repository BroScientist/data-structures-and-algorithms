#include <iostream>
#include <vector>

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
    
    int maxDepth = 0;
    vector<string> longestWords;
    
    void dfs(TrieNode* node, int depth, string curr)
    {
        // if depth is greater than max, clear the array
        if (depth > maxDepth)
            longestWords.clear();
        
        // update max and push the current word (because there could multiple words with max depth)
        if (depth >= maxDepth)
        {
            maxDepth = depth;
            longestWords.push_back(curr);
        }

        for (int i = 0; i < 26; i++)
        {
            TrieNode* child = node->links[i];
            if (child != nullptr && child->isEnd)
                dfs(child, depth + 1, curr + "abcdefghijklmnopqrstuvwxyz"[i]);
        }
        
    }
    
    string longestWord(vector<string>& words) {
        // insert words into trie
        Trie trie = Trie();
        for (string& word : words)
            trie.insert(word);
        
        // find the longest sequence of consecutive isEnds
        TrieNode* node = trie.root;
        dfs(node, 0, "");
        
        sort(begin(longestWords), end(longestWords));
        return longestWords[0];
    }
};