/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start

// #include "dummyHead.h"

// Solution
//  ref: http://zxi.mytechroad.com/blog/data-structure/leetcode-208-implement-trie-prefix-tree/
class Trie {
public:
    Trie() : root(new TrieNode()){}
    
    void insert(string word) {
        TrieNode* p = root.get();
        // read every char in word
        for(const char& c : word){
            if(!p->children.count(c))
                p->children[c] = new TrieNode();
            p = p->children[c];
        }
        // assign the last char of word as the end of the word
        p->isWord = true;
    }
    
    bool search(string word) {
        const TrieNode* p = find(word);
        return p && p->isWord;
    }
    
    bool startsWith(string prefix) {
        return find(prefix) != nullptr;
    }

private:
    struct TrieNode{
        TrieNode() : isWord(false) {}
        ~TrieNode(){
            for(const auto& c : children){
                if(c.second)
                    delete c.second;
            }
        }

        bool isWord;
        unordered_map<char, TrieNode*> children;
    };

    const TrieNode* find(const string& word) const {
        const TrieNode* p = root.get();
        for(const char& c : word){
            if(!p->children.count(c))
                return nullptr;
            p = p->children.at(c);  // use for assign const
        }
        return p;
    }

    unique_ptr<TrieNode> root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

