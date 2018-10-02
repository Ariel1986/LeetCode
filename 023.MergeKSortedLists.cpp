/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
Tags: Divide and Conquer Linked List Heap
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        ListNode dummyHead(-1);
        ListNode* pre = &dummyHead;
        pre->next = lists[0];

        for(int i = 1, iEnd = lists.size(); i < iEnd; ++i)
        {
            pre = &dummyHead;
            ListNode* p1 = pre->next;
            ListNode* p2 = lists[i];
            while(p1 != nullptr && p2 != nullptr)
            {
                if(p1->val < p2->val)
                {
                    pre->next = p1;
                    p1 = p1->next;
                }
                else 
                {
                    pre->next = p2;
                    p2 = p2->next;
                }
                pre = pre->next;
            }
            
            while(p1 != nullptr)
            {
                pre->next = p1;
                p1 = p1->next;
                pre = pre->next;
            }
            
            while(p2 != nullptr)
            {
                pre->next = p2;
                p2 = p2->next;
                pre = pre->next;
            }
        }
        
        return dummyHead.next;
    }
};

//Code 2:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        ListNode dummyHead(-1);
        ListNode* pre = &dummyHead;
        pre->next = lists[0];
        
        std::function<void(ListNode*, ListNode*, ListNode*)>
        mergeList = [&](ListNode* pre, ListNode* p1, ListNode* p2)
        {
            while(p1 != nullptr && p2 != nullptr)
            {
                if(p1->val < p2->val)
                {
                    pre->next = p1;
                    p1 = p1->next;
                }
                else 
                {
                    pre->next = p2;
                    p2 = p2->next;
                }
                pre = pre->next;
            }
            
            while(p1 != nullptr)
            {
                pre->next = p1;
                p1 = p1->next;
                pre = pre->next;
            }
            
            while(p2 != nullptr)
            {
                pre->next = p2;
                p2 = p2->next;
                pre = pre->next;
            }
        };
        
        for(int i = 1, iEnd = lists.size(); i < iEnd; ++i)
        {
             ListNode* p1 = dummyHead.next;
             ListNode* p2 = lists[i];
             pre = &dummyHead;
             mergeList(pre, p1, p2);
        }
        
        return dummyHead.next;
    }
