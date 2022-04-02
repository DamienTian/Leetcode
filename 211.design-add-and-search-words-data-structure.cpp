/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
 */

// @lc code=start

// #include "dummyHead.h"

// Failed Solution: TLE but passed all cases
// class WordDictionary
// {
// public:
//     WordDictionary() : root(new WordNode()) {}

//     void addWord(string word)
//     {
//         WordNode *p = root.get();
//         for (const char &c : word)
//         {
//             if (!p->children.count(c))
//                 p->children[c] = new WordNode();
//             p = p->children[c];
//         }
//         p->isWord = true;
//     }

//     // Solution for search: DFS
//     //  ref: https://www.cnblogs.com/grandyang/p/4507286.html
//     bool search(string word)
//     {
//         WordNode* p = root.get();
//         return searchWord(word, p, 0);
//     }

// private:
//     struct WordNode
//     {
//         WordNode() : isWord(false) {}
//         ~WordNode()
//         {
//             for (const auto &c : children)
//             {
//                 if (c.second)
//                     delete c.second;
//             }
//         }
//         bool isWord;
//         unordered_map<char, WordNode *> children;
//     };

//     bool searchWord(const string& word, WordNode* p, int index){
//         if(index == word.size())
//             return p->isWord;
//         if(word[index] == '.'){
//             for(auto& c : p->children){
//                 if(searchWord(word, c.second, index + 1)){
//                     return true;
//                 }
//             }
//             return false;
//         }
//         else{
//             return p->children.count(word[index]) && searchWord(word, p->children[word[index]], index + 1);
//         }
//     }

//     unique_ptr<WordNode> root;
// };

// Solution：Grandyang
//  ref: https://www.cnblogs.com/grandyang/p/4507286.html
//  note: have destructor in solution might cause TLE, WTF ????
class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    ~WordDictionary() {
        if(root)
            delete root;
    }

    struct TrieNode {
        TrieNode *child[26];
        bool isWord;
        TrieNode() : isWord(false) {
            for (auto &a : child) a = NULL;
        }
        ~TrieNode(){
            for (auto &a : child){
                if(a)
                    delete a;
            }
        }
    };

    
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode *p = root;
        for (auto &a : word) {
            int i = a - 'a';
            if (!p->child[i]) p->child[i] = new TrieNode();
            p = p->child[i];
        }
        p->isWord = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return searchWord(word, root, 0);
    }
    
    bool searchWord(string &word, TrieNode *p, int i) {
        if (i == word.size()) return p->isWord;
        if (word[i] == '.') {
            for (auto &a : p->child) {
                if (a && searchWord(word, a, i + 1)) return true;
            }
            return false;
        } else {
            return p->child[word[i] - 'a'] && searchWord(word, p->child[word[i] - 'a'], i + 1);
        }
    }
    
private:
    TrieNode *root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end
