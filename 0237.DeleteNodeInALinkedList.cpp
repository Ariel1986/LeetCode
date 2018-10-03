/*Question:
Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.
Tags: Linked List
Similar Problem: 203
*/

/*思路:
把后一个节点的元素值拷到当前节点，然后删除后一个节点
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
    void deleteNode(ListNode* node) {
       if(node == nullptr || node->next == nullptr)
            return;
            
       ListNode* pNext = node->next;
       node->val = pNext->val;
       node->next = pNext->next;
       delete pNext;
    }
};
