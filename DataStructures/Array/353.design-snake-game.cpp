/*
 * @lc app=leetcode id=353 lang=cpp
 *
 * [353] Design Snake Game
 */

// @lc code=start
//#include "../dummyHead.h"

// Solution: using array to stimulate the move
//  ref: https://grandyang.com/leetcode/353/
class SnakeGame {
public:
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        w = width, h = height;
        foods = food;
        bodys.push_back({0, 0});
    }
    
    int move(string direction) {
        vector<int> head = bodys.front(), tail = bodys.back();
        bodys.pop_back(); // pop the tail first to preserve movement. if eat food, push it back
        vector<int> newHead = afterMove(head, direction);
        if(count(bodys.begin(), bodys.end(), newHead) || newHead[0] < 0 || newHead[0] >= h || newHead[1] < 0 || newHead[1] >= w){
            return -1;
        }
        bodys.insert(bodys.begin(), newHead);
        if(!foods.empty() && newHead == foods.front()){
            foods.erase(foods.begin());
            bodys.push_back(tail);
            s++;
        }
        return s;
    }

private:
    vector<int> afterMove(vector<int> pos, string dir){
        if(dir == "U")  pos[0]--;
        else if(dir == "D")  pos[0]++;
        else if(dir == "L")  pos[1]--;
        else if(dir == "R")  pos[1]++;
        return pos;
    }

    int w, h, s = 0;    // width, height, score
    vector<vector<int>> foods, bodys;
};
/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */
// @lc code=end

