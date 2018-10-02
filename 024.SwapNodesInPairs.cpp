/*Question:
Given a linked list, swap every two adjacent nodes and return its head.
For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.
Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
Subscribe to see which companies asked this question
Tags: Lined List
*/

/*思路：
连续处理链表的两个元素，注意考虑链表有偶数个元素和奇数个元素两种情况
Note：对于头结点指针要处理的情况，可以添加一个链表节点指向链表的第一个节点，从而将第一个节点的处理情况与后面节点的处理情况一致化
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
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
            return head;
        ListNode dummyHead(0);
        
        ListNode* pre = &dummyHead;
        ListNode* cur1 = head;
        ListNode* cur2 = cur1->next;
        
        while(cur1!=nullptr && cur2!=nullptr)
        {
            pre->next = cur2;
            cur1->next = cur2->next;
            cur2->next = cur1;
            
            pre = cur1;
            cur1 = cur1->next;
            if(cur1 != nullptr)
                cur2 = cur1->next;
        }
        return dummyHead.next;
    }
};
