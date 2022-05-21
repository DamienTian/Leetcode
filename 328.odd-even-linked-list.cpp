/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
 */

// @lc code=start
// Definition for singly-linked list.
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
// #include "dummyHead.h"
class Solution
{
public:
    // Solution 1: two ptrs
    //  ref: https://www.cnblogs.com/grandyang/p/5138936.html
    ListNode *oddEvenList(ListNode *head)
    {
        if(!head || !head->next)
            return head;
        ListNode *odd = head, *even = head->next, *evenHead = even;
        // break odd list and even list
        while(even && even->next){
            odd = odd->next = even->next;
            even = even->next = odd->next;
        }
        // connect odd and even list
        odd->next = evenHead;
        return head;
    }
};
// @lc code=end
