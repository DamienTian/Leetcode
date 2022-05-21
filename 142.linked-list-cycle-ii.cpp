/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
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
    // Solution: slow + fast pointer
    //  ref1: https://www.cnblogs.com/grandyang/p/4137302.html
    //  ref2: https://www.cnblogs.com/hiddenfox/p/3408931.html
    ListNode *detectCycle(ListNode *head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                break;
        }
        if(!fast || !fast->next)
            return nullptr;
        // start over to find begin of the cycle (see proof in ref2)
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};
// @lc code=end
