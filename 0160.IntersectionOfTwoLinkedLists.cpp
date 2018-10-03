/*
Write a program to find the node at which the intersection of two singly linked lists begins.
For example, the following two linked lists:
A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.
Notes:
If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
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

//Code 1:
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr)
            return nullptr;
        
        auto getListLength = [](ListNode* head) -> int
        {
            int len = 0;
            for(ListNode* p = head; p != nullptr; p = p->next)
                ++len;
                
            return len;
        };
        
        int lenA = getListLength(headA);
        int lenB = getListLength(headB);
        if(lenB > lenA)
        {
            std::swap(headA, headB);
            std::swap(lenA, lenB);
        }
        
        for(int i = 0, iEnd = lenA - lenB; i < iEnd; ++i)
            headA = headA->next;
            
        while(headA != nullptr && headB != nullptr && headA != headB)
        {
            headA = headA->next;
            headB = headB->next;
        }
        
        return headA;
    }
};

//Code 2:
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curA = headA, *curB = headB;
        while(curA != curB){
            curA = curA == nullptr? headA: curA->next;
            curB = curB == nullptr? headB: curB->next;
        }
        
        return curA;
    }
};

//Code 3:
/*转变成有环链表的第一个节点问题*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr){ return nullptr; }
        ListNode *curA = headA;
        while(curA->next != nullptr){
            curA = curA->next;
        }
        curA->next = headB;
        
        //Find the start of loop
        ListNode *pSlow = headA, *pFast = headA;
        while(pFast != nullptr && pFast->next!= nullptr){
            pSlow = pSlow->next;
            pFast = pFast->next->next;
            
            if(pSlow == pFast){
                pFast = headA;
                while(pFast != pSlow){
                    pFast = pFast->next;
                    pSlow = pSlow->next;
                }
                curA->next = nullptr;
                return pSlow;
            }
        }
        
        //no loop find, return nullptr
        curA->next = nullptr;
        return nullptr;
    }
};
