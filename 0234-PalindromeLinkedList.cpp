/*
Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?
*/


//code 1:
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
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr){ return true; }
        
        auto reverseList = [](ListNode* head)->ListNode*{
            if(head == nullptr || head->next == nullptr){ return head; }
            ListNode *pPre = nullptr, *pCur = head;
            while(pCur != nullptr){
                ListNode* pNext = pCur->next;
                pCur->next = pPre;
                pPre = pCur;
                pCur = pNext;
            }
            return pPre;
        };
        
        ListNode *pSlow = head, *pFast = head;
        
        while(pFast != nullptr && pFast->next != nullptr){
            pSlow = pSlow->next;
            pFast = pFast->next;
            if(pFast != nullptr){
                pFast = pFast->next;
            }
        }
        if(pFast != nullptr){  //list长度为奇数
            pSlow = pSlow->next;
        }
        
        ListNode *pRight = reverseList(pSlow);
        while(pRight != nullptr){
            if(pRight->val != head->val){
                return false;
            }
            pRight = pRight->next;
            head = head->next;
        }
        return true;
    }
};

//code2:
class Solution {
public:
    bool helper(ListNode** root, ListNode* head){
        if(head == nullptr){return true;}
        bool result = helper(root, head->next);
        result = result && (*root)->val == head->val;
        *root = (*root)->next;
        
        return result;
    }
    
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr){ return true; }
        
        return helper(&head, head);
    }
};
