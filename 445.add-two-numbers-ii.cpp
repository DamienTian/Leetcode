/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
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
    // Solution 1: recursion
    //  ref: https://www.cnblogs.com/grandyang/p/6216480.html
    //  note: check another stack iteration, but follows same logic
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int len1 = getLen(l1), len2 = getLen(l2);
        // preallocate 1
        ListNode* result = new ListNode(1);
        result->next = (len1 > len2) ? helper(l1, l2, len1 - len2) : helper(l2, l1, len2 - len1);
        if(result->next->val > 9){
            result->next->val %= 10;
            return result;
        }
        return result->next;
    }

private:
    int getLen(ListNode *head){
        int len = 0;
        while(head){
            ++len;
            head = head->next;
        }
        return len;
    }

    // lenDiff: Length difference between two list
    ListNode *helper(ListNode *l1, ListNode *l2, int lenDiff){
        if(!l1)
            return nullptr;
        ListNode* currentDigit = (lenDiff == 0) ? new ListNode(l1->val + l2->val) : new ListNode(l1->val);
        ListNode* post = (lenDiff == 0) ? helper(l1->next, l2->next, 0) : helper(l1->next, l2, lenDiff - 1);
        if(post && post->val > 9){
            post->val %= 10;
            ++currentDigit->val;
        }
        currentDigit->next = post;
        return currentDigit;
    }
};
// @lc code=end
