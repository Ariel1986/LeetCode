/*Question:
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
Note: Do not modify the linked list.
Follow up:
Can you solve it without using extra space?
Subscribe to see which companies asked this question
Tags: Linked List, Two Points
*/

/*思路：
关于有环链表通常有如下四种题目：
1. 判断链表是否有环 （题目141）
2. 求环的入口节点
3. 求环的长度
4. 求链表的总长度
2. 求环的入口节点：
1）设两个指针pSlow和pFast，然后pSlow每次走一步，pFast每次走两步；如果pFast==pSlow，则有环；否则，pFast==nullptr，无环，返回nullptr
2）如果pFast==pSlow，pSlow走到环入口节点需要的步数=从头节点走到环入口节点的步数，所以令pFast=head，pFast与pSlow相遇的节点就是环入口节点
3. 求环的长度：
在环上相遇后，记录第一次相遇点为Pos，之后指针slow继续每次走1步，fast每次走2步。在下次相遇的时候fast比slow正好又多走了一圈，也就是多走的距离等于环长。
设从第一次相遇到第二次相遇，设slow走了len步，则fast走了2*len步，相遇时多走了一圈：
环长=2*len-len。
4. 求链表的总长度:
在2中已经求出了环的入口节点，3中求出了环的长度，所以只需要再求出从头节点到入口节点的长度就可以得到总长度
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
    ListNode *detectCycle(ListNode *head) {
        if(head==nullptr || head->next==nullptr)
            return nullptr;
        ListNode* pSlow = head;
        ListNode* pFast = head;

        while(pFast != nullptr)
        {
            pSlow = pSlow->next;
            pFast = pFast->next;
            if(pFast != nullptr)
                pFast = pFast->next;
            if(pFast == pSlow)
                break;
        }
        if(pFast == nullptr)
            return nullptr;
       
        pFast = head;
        while(pFast != pSlow)
        {
            pFast = pFast->next;
            pSlow = pSlow->next;
        }

        return pSlow;
    }
};
