/*
Given a list, rotate the list to the right by k places, where k is non-negative.
For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
Tags: Linked List, Two Pointers
Similar Problems: 189
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k <1) return head;
        
        auto listLen = [&]()->int
        {
            int len = 0;
            ListNode* pHead = head;
            while (pHead != nullptr)
            {
                ++len;
                pHead = pHead->next;
            }
            return len;
        };
        
        int len = listLen();
        k %= len;
        if(k%len == 0) return head;

        ListNode* pPre = head;
        for (int i = 0, iEnd = len - k - 1; i < iEnd; ++i)
            pPre = pPre->next;
            
        ListNode* pLast = pPre->next;
        while (pLast->next != nullptr)
            pLast = pLast->next;
            
        pLast->next = head;
        head = pPre->next;
        pPre->next = nullptr;
        return head;
    }
};
