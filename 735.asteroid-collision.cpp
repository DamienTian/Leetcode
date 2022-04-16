/*
 * @lc app=leetcode id=735 lang=cpp
 *
 * [735] Asteroid Collision
 */

// @lc code=start

// #include "dummyHead.h"

class Solution
{
public:
    // Solution: Stack
    //  ref: http://zxi.mytechroad.com/blog/simulation/leetcode-735-asteroid-collision/
    //  note: use vector as stack
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vector<int> result;
        for(int i = 0; i < asteroids.size(); ++i){
            if(asteroids[i] > 0)
                result.push_back(asteroids[i]);
            else{
                if(result.empty() || result.back() < 0)
                    result.push_back(asteroids[i]);
                else if(abs(result.back()) <= abs(asteroids[i])){
                    if(abs(result.back()) < abs(asteroids[i]))  // if the left move asteroid is bigger
                        --i;    // the left move asteroid remains alive and will be used for next loop
                    result.pop_back();
                }
            }
        }
        return result;
    }
};
// @lc code=end
