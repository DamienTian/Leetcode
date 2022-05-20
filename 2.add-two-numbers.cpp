/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode result(-1);
        ListNode *head = &result;
        int increment = 0;
        while(l1 && l2){
            int sum = l1->val + l2->val + increment;
            int digit = sum % 10;
            increment = sum / 10;
            head->next = new ListNode(digit);
            l1 = l1->next;
            l2 = l2->next;
            head = head->next;
        }
        ListNode* remain = nullptr;
        if(l1)
            remain = l1;
        else if(l2)
            remain = l2;
        while(remain){
            int sum = remain->val + increment;
            int digit = sum % 10;
            increment = sum / 10;
            head->next = new ListNode(digit);
            remain = remain->next;
            head = head->next;
        }
        if(increment > 0)
            head->next = new ListNode(increment);
        return result.next;
    }
};
// @lc code=end
