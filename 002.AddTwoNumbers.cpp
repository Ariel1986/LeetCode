/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Subscribe to see which companies asked this question
Tags: Linked List, Math
*/

//Code:
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        
        ListNode dummyHead(0);
        ListNode* pre = &dummyHead;
        int carry = 0;
        
        while(l1 != nullptr && l2 != nullptr)
        {
            int sum = l1->val + l2->val + carry;
            carry = sum / 10;
            pre->next = new ListNode(sum % 10);
            l1 = l1->next;
            l2 = l2->next;
            pre = pre->next;
        }
        
        while(l1 != nullptr)
        {
            int sum = l1->val + carry;
            carry = sum / 10;
            pre->next = new ListNode(sum % 10);
            l1 = l1->next;
            pre = pre->next;
        }
        
        while(l2 != nullptr)
        {
            int sum = l2->val + carry;
            carry = sum / 10;
            pre->next = new ListNode(sum % 10);
            l2 = l2->next;
            pre = pre->next;
        }
        if(carry == 1)
            pre->next = new ListNode(carry);
            
        return dummyHead.next;
    }
};
