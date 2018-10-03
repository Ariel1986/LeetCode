/*Question:
Given a linked list, determine if it has a cycle in it.
Follow up:
Can you solve it without using extra space?
Subscribe to see which companies asked this question
Show Tags
Show Similar Problems
*/

/*思路：
两个指针pSlow和pFast同时走，在pSlow=pSlow->next, pFast=pFast->next->next(中间注意判断pFast是否为nullptr)
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
    bool hasCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr){ return false; }
        ListNode *pSlow = head, *pFast = head;
        while(pFast != nullptr && pFast->next != nullptr){
            pSlow = pSlow->next;
            pFast = pFast->next->next;
            if(pFast == pSlow){
                return true;
            }
        }
        
        return false;
    }
};

