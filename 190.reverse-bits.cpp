/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 * 
 * Category: Bit Manipulation, Divide and Conqure
 */

// @lc code=start
class Solution {
public:
    // Solution 1: convert to string
    // uint32_t reverseBits(uint32_t n) {
    //     bitset<32> bits(n);
    //     string s = bits.to_string();
    //     for(int i = 0; i < 32/2; ++i){
    //         int j = 31 - i;
    //         swap(s[i], s[j]);
    //     }
    //     bitset<32> bitsReversed(s);
    //     return bitsReversed.to_ulong();
    // }

    // Solution 2: bit manipulation
    //  ref: https://www.cnblogs.com/grandyang/p/4321355.html
    //  IDEA: let n right shift, check each bit == 1 by bit AND(&), and put the bit to the left of the result (use left shift)
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for(int i = 0; i < 32; ++i){
            result = ((n >> i) & 1) + (result << 1);
        }
        return result;
    }

    // Solution 3: bit manipulation (use Divide and conquer concept, very clever!!!)
    //  ref: https://leetcode.com/problems/reverse-bits/discuss/54741/O(1)-bit-operation-C++-solution-(8ms)
    // uint32_t reverseBits(uint32_t n) {
    //     n = (n >> 16) | (n << 16); 
    //     n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
    //     n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
    //     n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
    //     n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
    //     return n;
    // }
    // Solution 3 explain:
    /*
    This is done by reverse near by 16 bits, 8 bits, 4 bits, 2 bits and 1 bits of the n:
        n = (n >> 16) | (n << 16); 
        // first reverse of front and back 16 bits

        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        // 0xff00ff00 == 11111111000000001111111100000000
        // 0x00ff00ff == 00000000111111110000000011111111
        //  reverse near by 8 bits

        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        // 0xf0f0f0f0 == 11110000111100001111000011110000
        // 0x0f0f0f0f == 00001111000011110000111100001111
        //  reverse near by 4 bits

        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        // 0xcccccccc == 11001100110011001100110011001100
        // 0x33333333 == 00110011001100110011001100110011
        //  reverse near by 2 bits

        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        // 0xaaaaaaaa == 10101010101010101010101010101010
        // 0x55555555 == 01010101010101010101010101010101
        //  reverse near by 1 bits
        // FINISHED
    */ 

};
// @lc code=end

