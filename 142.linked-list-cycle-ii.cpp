/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//  ref:   https://www.cnblogs.com/hiddenfox/p/3408931.html + https://www.cnblogs.com/grandyang/p/4137302.html#4138738
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }
        if (!fast || !fast->next)
            return NULL;
        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};
// @lc code=end
