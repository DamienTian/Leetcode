/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */

// @lc code=start

// #include "dummyHead.h"

class Solution
{
public:
    // Falied Solution: BFS (Pass all cases but TLE)
    //  note: this version could solve more complicated cases, e.g. exist two word can be start of search
    // int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    // {
    //     // build graph
    //     unordered_map<string, unordered_set<string>> graph;
    //     for (int i = 0; i < wordList.size(); ++i)
    //     {
    //         for (int j = 0; j < wordList.size(); ++j)
    //         {
    //             if(i == j){
    //                 graph[wordList[j]].insert("");
    //             }
    //             else if (adjancentWords(wordList[i], wordList[j]) && i != j)
    //             {
    //                 graph[wordList[i]].insert(wordList[j]);
    //                 graph[wordList[j]].insert(wordList[i]);
    //             }
    //         }
    //     }
    //     // if (!graph.count(endWord))
    //     //     return 0;
    //     bool foundTarget = false;
    //     int result = INT_MAX;
    //     // loop all word in wordLists to do BFS
    //     for (const string &word : wordList)
    //     {
    //         cout << word << endl;
    //         if (!adjancentWords(beginWord, word))
    //             continue;
    //         cout << word << endl;
    //         int currentPath = (beginWord == word) ? 0 : 1;
    //         queue<string> q{{word}};
    //         unordered_set<string> visited;
    //         visited.insert(word);
    //         while (!q.empty())
    //         {
    //             ++currentPath;
    //             bool currFoundTarget = false;
    //             int size = q.size();
    //             for (int i = size; i > 0; --i)
    //             {
    //                 string curr = q.front();
    //                 q.pop();
    //                 if(curr == endWord){
    //                     cout << "found target with len: " << currentPath << endl;
    //                     result = min(currentPath, result);
    //                     foundTarget = true;
    //                     currFoundTarget = true;
    //                     break;
    //                 }
    //                 for (const string &adj : graph[curr])
    //                 {
    //                     if(visited.count(adj))
    //                         continue;
    //                     visited.insert(adj);
    //                     q.push(adj);
    //                 }
    //             }
    //             if(currFoundTarget)
    //                 break;
    //         }
    //     }
    //     return foundTarget ? result : 0;
    // }

    // Solution 1: BFS
    //  ref: https://www.cnblogs.com/grandyang/p/4539768.html
    // int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    // {
    //     unordered_set<string> wordSet(wordList.begin(), wordList.end());
    //     if(!wordSet.count(endWord))
    //         return 0;
    //     // record path cost
    //     unordered_map<string, int> pathCost{{beginWord, 1}};
    //     queue<string> q{{beginWord}};
    //     while(!q.empty()){
    //         string word = q.front();
    //         q.pop();
    //         for(int i = 0; i < word.size(); ++i){
    //             string newWord = word;
    //             for(char c = 'a'; c <= 'z'; ++c){
    //                 newWord[i] = c;
    //                 if(wordSet.count(newWord)){
    //                     if(newWord == endWord)
    //                         return pathCost[word] + 1;
    //                     if(!pathCost.count(newWord)){
    //                         pathCost[newWord] = pathCost[word] + 1;
    //                         q.push(newWord);
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //     return 0;
    // }

    // Solution 2: BFS Bidirectional
    //  ref: http://zxi.mytechroad.com/blog/searching/127-word-ladder/
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if(!wordSet.count(endWord))
            return 0;
        int wordLen = beginWord.length();
        // use hashset as queue
        unordered_set<string> q1{beginWord};
        unordered_set<string> q2{endWord};
        int result = 0;
        while(!q1.empty() && !q2.empty()){
            ++result;
            // search a smaller set
            if(q1.size() > q2.size())
                std::swap(q1, q2);
            unordered_set<string> q;
            for(string word : q1){
                for(int i = 0; i < wordLen; ++i){
                    char c = word[i];
                    for(char j = 'a'; j <= 'z'; ++j){
                        word[i] = j;
                        if(q2.count(word))
                            return result + 1;
                        if(!wordSet.count(word))
                            continue;
                        wordSet.erase(word);
                        q.insert(word);
                    }
                    word[i] = c;
                }
            }
            std::swap(q, q1);
        }
        return 0;
    }

private:
    bool adjancentWords(const string &word1, const string &word2)
    {
        if (word1.length() != word2.length())
            return false;
        int diffCount = 0;
        for (int i = 0; i < word1.length(); ++i)
        {
            if (word1[i] != word2[i])
                diffCount++;
        }
        return diffCount <= 1;
    }
};
// @lc code=end
