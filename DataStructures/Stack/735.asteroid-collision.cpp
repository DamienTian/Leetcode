/*
 * @lc app=leetcode id=735 lang=cpp
 *
 * [735] Asteroid Collision
 */

// @lc code=start

//#include "dummyHead.h"

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (int a : asteroids){
            if(st.empty() || !willCollide(st.top(), a))
                st.push(a);
            else if(willCollide(st.top(), a)){
                int c = a;
                while(!st.empty() && willCollide(st.top(), c)){
                    c = collision(st.top(), c);
                    st.pop();
                }
                if(c != 0)
                    st.push(c);
            }
        }

        vector<int> result;
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }

    bool willCollide(int left, int right) {
        return sign(left) == 1 && sign(right) == -1;
    }

    int collision(int x, int y) {
        if(abs(x) == abs(y))
            return 0;
        return abs(x) > abs(y) ? x : y;
    }

    int sign(int x) {
        if (x > 0) return 1;
        if (x < 0) return -1;
        return 0;
    }
};

/*
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
*/

// @lc code=end
