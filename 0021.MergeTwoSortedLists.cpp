/*Question:
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
*/

/*思路：
方法一： 一次处理链表
方法二：递归合并链表
*/

//Code:
//Code 1:
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummyHead(0);
        ListNode* pPre = &dummyHead;
        while(l1 != nullptr && l2 != nullptr)
        {
            if(l1->val < l2->val)
            {
                pPre->next = l1;
                l1 = l1->next;
            }
            else
            {
                pPre->next = l2;
                l2 = l2->next;
            }
            pPre = pPre->next;
        }
        
        while(l1 != nullptr)
        {
            pPre->next = l1;
            l1 = l1->next;
            pPre = pPre->next;
        }
        while(l2 != nullptr)
        {
            pPre->next = l2;
            l2 = l2->next;
            pPre = pPre->next;
        }
        
        return dummyHead.next;
    }
};

//Code2:
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        
        if(l1->val < l2->val)
        {
           l1->next = mergeTwoLists(l1->next, l2);
           return l1;
        }
        else
        {
           l2->next = mergeTwoLists(l1, l2->next);
           return l2; 
        }
    }
};
