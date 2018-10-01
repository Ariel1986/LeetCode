/*
Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr){ return head;}
        ListNode dummyHead(0);
        dummyHead.next= head;
        
        ListNode* pPre = &dummyHead;
        ListNode* pCur = head;
        while(pCur != nullptr){
            if(pCur->val == val){
                pPre->next = pCur->next;
                delete pCur;
                pCur = pPre->next;
            }else{
                pPre = pCur;
                pCur = pCur->next;
            }
        }
        
        return dummyHead.next;
    }
};
