/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
public:
    // Solution 1: BFS
    //  NOTE: 
    //  1) this is my solution using BFS, no optimization, very slow...
    //  2) ref: https://zxi.mytechroad.com/blog/searching/leetcode-17-letter-combinations-of-a-phone-number/
    //      (see how to use a dummy vector<string> to do BFS)
    vector<string> letterCombinations(string digits) {
        if(digits == ""){
            return {};
        }
        
        deque<string> q {""};

        for(char d : digits){
            size_t currentSize = q.size();
            for(size_t i = 0; i < currentSize; ++i){
                for(char l : letters[d]){
                    string combine = q.front() + l;
                    q.push_back(combine);
                }
                q.pop_front(); 
            }
        }

        return vector<string>(make_move_iterator(q.begin()), make_move_iterator(q.end()));
    }

    // Solution 2: DFS
    //  NOTE: this is my solution using DFS, no optimization, very slow...
    // vector<string> letterCombinations(string digits) {
    //     if(digits == ""){
    //         return {};
    //     }

    //     vector<string> result;
    //     string current = "";
    //     dfs(digits, 0, current, result);
    //     return result;
    // }

private:
    void dfs(const string& digits, int index, string& current, vector<string>& result){
        if(index >= digits.length()){
            result.push_back(current);
            return;
        }
        for(const char& c : letters[digits[index]]){
            current += c;
            dfs(digits, index + 1, current, result);
            current.pop_back();
        }
    }

    unordered_map<char, string> letters = 
        unordered_map<char, string> ({
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"} 
        });
};
// @lc code=end

