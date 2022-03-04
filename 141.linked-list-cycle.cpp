/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

// @lc code=start
// Definition for singly-linked list.
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };
// #include "dummyHead.h"

class Solution
{
public:
    // Solution: Two Pointers (one slow one fast)
    //  ref: https://www.cnblogs.com/grandyang/p/4137187.html
    bool hasCycle(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};
// @lc code=end
