/*
 * @lc app=leetcode id=353 lang=cpp
 *
 * [353] Design Snake Game
 */

// @lc code=start
#include "../dummyHead.h"

class SnakeGame {
public:
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        w = width;
        h = height;
        for(vector<int> f : food)
            foods.push(f);
        map[{0,0}] = 1;
        position.push({0,0});
    }
    
    int move(string direction) {
        while(!foods.empty() && currentFoodNull()){
            currentFood = foods.front();
            foods.pop();
        }
        vector<int> moveDir = dir(direction);
        vector<int> headNext = movePos(position.front(), moveDir);
        if(dead(headNext))
            return -1;
        map.clear();
        if(eatFood(headNext)){
            currentFood = {-1,-1};
            int moveSize = position.size();
            position.push(headNext);
            map.insert(pair<vector<int>, int>(headNext, 1));
            for(int i = 0; i < moveSize; ++i){
                vector<int> p = position.front();
                position.pop();
                position.push(p);
                map.insert(pair<vector<int>, int>(p, 1));
            }
        }
        else{
            vector<int> next = headNext;
            int moveSize = position.size();
            for(int i = 0; i < moveSize; ++i){
                position.push(next);
                next = position.front();
                position.pop();
                map.insert(pair<vector<int>, int>(next, 1));
            }
        }
        return position.size() - 1;
    }

private:
    vector<int> dir(string direction){
        if(direction == "U") return {0,-1};
        if(direction == "D") return {0,1};
        if(direction == "L") return {-1,0};
        if(direction == "R") return {1,0};
        return {0,0};
    }

    vector<int> movePos(vector<int> pos, vector<int> dir){
        return {pos[0] + dir[0], pos[1] + dir[1]};
    }

    bool currentFoodNull(){
        return currentFood[0] == -1 && currentFood[1] == -1;
    }

    bool dead(vector<int> pos){
        return pos[0] < 0 || pos[0] >= w || pos[1] < 0 || pos[1] >= h || map.find(pos) != map.end();
    }

    bool eatFood(vector<int> pos){
        return pos[0] == currentFood[0] && pos[1] == currentFood[1];
    }

    int w, h; // width and height
    vector<int> currentFood = {-1,-1};
    queue<vector<int>> foods;
    queue<vector<int>> position;    // position of body segments
    unordered_map<vector<int>, int> map;
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */
// @lc code=end

