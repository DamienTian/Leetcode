/*
 * @lc app=leetcode id=1268 lang=cpp
 *
 * [1268] Search Suggestions System
 */

// @lc code=start

// #include "dummyHead.h"

class Solution {
public:
    // Solution 1: BFS
    // vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
    //     sort(products.begin(), products.end());
    //     vector<vector<string>> result;
    //     for(int i = 0; i < searchWord.length(); ++i){
    //         string searching = searchWord.substr(0, i + 1);
    //         vector<string> current;
    //         for(const string& p : products){
    //             string sub = p.substr(0, i + 1);
    //             if(sub == searching && current.size() < 3)
    //                 current.push_back(p);
    //         }
    //         result.push_back(current);
    //     }
    //     return result;
    // }

    // Solution 2: Trie
    //  ref: https://www.cnblogs.com/grandyang/p/15679711.html
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> res;
        sort(products.begin(), products.end());
        for (string word : products) {
            TrieNode *node = root;
            for (char c : word) {
                if (!node->next[c - 'a']) {
                    node->next[c - 'a'] = new TrieNode();
                }
                node = node->next[c - 'a'];
                if(node->suggestions.size() < 3)
                    node->suggestions.push_back(word);
            }
        }
        TrieNode *node = root;
        for (char c : searchWord) {
            if (node) {
                node = node->next[c - 'a'];
            }
            res.push_back(node ? node->suggestions : vector<string>());
        }
        return res;
    }


private:
    struct TrieNode {
        TrieNode *next[26];
        vector<string> suggestions;
    };
    TrieNode *root = new TrieNode();
};
// @lc code=end

