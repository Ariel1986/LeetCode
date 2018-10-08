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

//code 3:
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeHelper(list1 *ListNode, list2 *ListNode) *ListNode {
	if list1 == nil && list2 == nil {
		return nil
	} else if list1 == nil {
		return list2
	} else if list2 == nil {
		return list1
	} else if list1.Val < list2.Val {
		list1.Next = mergeHelper(list1.Next, list2)
		return list1
	} else {
		list2.Next = mergeHelper(list1, list2.Next)
		return list2
	}
}

func mergeKLists(lists []*ListNode) *ListNode {
	if len(lists) == 0 {
		return nil
	}
	for true {
		if len(lists) == 1 {
			break
		}
		var dummyLists []*ListNode
		i := 0
		for iEnd := len(lists) - 1; i < iEnd; i += 2 {
			dummyLists = append(dummyLists, mergeHelper(lists[i], lists[i+1]))
		}
		if i == len(lists)-1 {
			dummyLists = append(dummyLists, lists[i])
		}
		lists = dummyLists
	}
	return lists[0]
}
