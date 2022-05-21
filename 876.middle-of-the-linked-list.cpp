/*
 * @lc app=leetcode id=876 lang=cpp
 *
 * [876] Middle of the Linked List
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
    // Solution 1: calculate length
    // ListNode *middleNode(ListNode *head)
    // {
    //     int len = getLen(head);
    //     int target = len / 2;
    //     for(int i = 0; i < target; ++i)
    //         head = head->next;
    //     return head; 
    // }

    // Solution 2: fast and slow ptrs
    ListNode* middleNode(ListNode* head) {
		ListNode *slow = head, *fast = head;
		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
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
};
// @lc code=end
