/*Question:
Given a sorted linked list, delete all duplicates such that each element appear only once.
For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
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
       ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr){
            return head;
        }
        
        auto preNode = head;
        auto curNode = head->next;
        ListNode* nextNode = nullptr;
        
        while (curNode != nullptr){
            if (curNode->val != preNode->val) {
                preNode = curNode;
                curNode = curNode->next;
            }
            else{
                nextNode = curNode->next;
                preNode->next = nextNode;
                delete(curNode);
                curNode = nextNode;
            }
        }
        return head;
    }
};

