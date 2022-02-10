/*
 * @lc app=leetcode id=1656 lang=cpp
 *
 * [1656] Design an Ordered Stream
 */

// @lc code=start
class OrderedStream {
public:
    OrderedStream(int n) : size(n) {}
    
    vector<string> insert(int idKey, string value) {
        vector<string> concat = {};
        if(idKey > size){
            return concat;
        }
        m[idKey] = value;
        while(m.count(ptr)){
            concat.push_back(m[ptr]);
            ++ptr;
        }
        return concat;
    }

private:
    map<int, string> m;
    int size;
    int ptr = 1;
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
// @lc code=end

