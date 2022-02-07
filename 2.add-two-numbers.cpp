/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
//
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
    // My Solution: too many codes and redundent codes...
    // ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    // {
    //     ListNode *result = new ListNode();
    //     ListNode *current = result;
    //     int carry = 0;

    //     // Loop both linked list
    //     while (l1 && l2)
    //     {
    //         // Calculate
    //         current->val = (l1->val + l2->val + carry) % 10;
    //         carry = (l1->val + l2->val + carry) / 10;

    //         // Move to next digit
    //         l1 = l1->next;
    //         l2 = l2->next;
    //         if(l1 || l2 || carry){
    //             current->next = new ListNode();
    //             current = current->next;
    //         }
    //     }

    //     // Loop remaining list
    //     if(l1){
    //         while(l1){
    //             current->val = (l1->val + carry) % 10;
    //             carry = (l1->val + carry) / 10;
    //             l1 = l1->next;
    //             if(l1 || carry){
    //                 current->next = new ListNode();
    //                 current = current->next;
    //             }
    //         }
    //     }
    //     else if(l2){
    //         while(l2){
    //             current->val = (l2->val + carry) % 10;
    //             carry = (l2->val + carry) / 10;
    //             l2 = l2->next;
    //             if(l2 || carry){
    //                 current->next = new ListNode();
    //                 current = current->next;
    //             }
    //         }
    //     }

    //     if(carry > 0){
    //         current->val += carry;
    //     }

    //     return result;
    // }

    // Grandyang Solution
    //  ref: https://grandyang.com/leetcode/2/
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode* result = new ListNode(0);
        ListNode* cursor = result;
        int carry = 0;
        while(l1 || l2){
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int sum = (n1 + n2 + carry) % 10;
            carry = (n1 + n2 + carry) / 10;
            cursor->next = new ListNode(sum);
            cursor = cursor->next;
            if(l1){
                l1 = l1->next;
            }
            if(l2){
                l2 = l2->next;
            }
        }
        if(carry){
            cursor->next = new ListNode(carry);
        }
        return result->next;
    }
};
// @lc code=end
