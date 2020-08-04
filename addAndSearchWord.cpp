#include <iostream>
using namespace std;

struct TrieNode
{
    TrieNode* links[26] = {nullptr};
    bool isEnd = false;
    TrieNode() {}
    
    bool containsKey(char c)
    {
        int index = c - 'a';
        if (index < 0 || index > 25)
            return false;
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

class WordDictionary {
public:
    /** Initialize your data structure here. */
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* node = root;
        for (char& c : word)
        {
            if (!node->containsKey(c))
                node->put(c, new TrieNode());
            node = node->get(c);
        }
        node->setEnd();
    }
    
    bool searchPrefix(string& word, TrieNode* node)
    {
        for (int i = 0; i < word.size(); i++)
        {
            char c = word[i];
            // if the current char is not found, there are two possible cases:
            if (!node->containsKey(c))
            {
                // case 1: char is '.', which means it could be anything and we need to search the entire level
                if (c == '.')
                {
                    // splice the word string as if the current char is already found (".ad" becomes "ad")
                    string sub = word.substr(i+1);
                    
                    // search the current node's children (links) to see if this substring could be found
                    for (int j = 0; j < 26; j++)
                    {
                        TrieNode* child = node->links[j];
                        if (child != nullptr)
                        {
                            if (searchPrefix(sub, child))
                                return true;  
                        }
                    }
                }
                
                // case 2: the char is neither '.' nor is it found in trie, so simply return false
                return false;
            }
            else
                node = node->get(c);
        }
        return node->isEnd;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchPrefix(word, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
