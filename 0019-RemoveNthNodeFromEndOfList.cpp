/*
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?
*/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if( n <= 0 || head == nullptr) {return head;}
        
        ListNode* pFast = head;
        for(int i = 0; i < n & pFast != nullptr; ++i){
            pFast = pFast->next;
        }
        
        //这一步一定不要有，因为有可能删除的是队列头部
        //if(pFast == nullptr){ return head; }
        
        ListNode dumpHead(0);
        dumpHead.next = head;
        ListNode* pSlow = &dumpHead;
        
        while(pFast != nullptr){
            pFast = pFast->next;
            pSlow = pSlow->next;
        }
        
        ListNode* pDel = pSlow->next;
        pSlow->next = pDel->next;
        delete pDel;
        
        return dumpHead.next;
    }
};
