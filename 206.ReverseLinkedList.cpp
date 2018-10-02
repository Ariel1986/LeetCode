/*Question:
Reverse a singly linked list.
click to show more hints.
Hint:
A linked list can be reversed either iteratively or recursively. Could you implement both?
Similar Problems: 92, 234
*/

/*思路:
循环或递归的方法实现
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
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        
        while(cur != nullptr)
        {
            ListNode* pNext = cur->next;
            cur->next = pre;
            pre = cur;
            cur = pNext;
        }
        
        return pre;
    }
};
