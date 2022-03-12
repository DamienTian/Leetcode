/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
// Definition for singly-linked list.
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };
// #include "dummyHead.h"

class Solution
{
public:
    // Solution 1: cut the longer list to equal the length of the shorter one, then do the search again
    //  ref for solution 1: https://www.cnblogs.com/grandyang/p/4128461.html
    // Solution 2: use hash table
    //  note: skip first two solutions

    // Solution 3: Treat as linked list cycle
    //  ref: https://www.cnblogs.com/grandyang/p/4128461.html
    //  note: read the explanation in the ref
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if(!headA || !headB)
            return nullptr;
        ListNode* a = headA;
        ListNode* b = headB;
        while (a != b)
        {
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }
        return a;
    }
};
// @lc code=end
