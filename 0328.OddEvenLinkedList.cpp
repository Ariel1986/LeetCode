/*
Given a singly linked list, group all odd nodes together followed by the even nodes. 
Please note here we are talking about the node number and not the value in the nodes.
You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.
Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.
Note:
The relative order inside both the even and odd groups should remain as it was in the input. 
The first node is considered odd, the second node even and so on ...
*/
//code:
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func oddEvenList(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}

	h1 := ListNode{}
	h2 := ListNode{}
	pOdd, pEven := &h1, &h2
	pCur := head
	for pCur != nil && pCur.Next != nil {
		pOdd.Next = pCur
		pEven.Next = pCur.Next
		pCur = pCur.Next.Next
		pOdd = pOdd.Next
		pEven = pEven.Next
	}

	pEven.Next = nil
	if pCur != nil { //奇数个链表
		pOdd.Next = pCur
		pOdd = pOdd.Next
	}
	pOdd.Next = h2.Next
	return h1.Next
}

//Code:
//Code 1:同时处理奇偶节点
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
    ListNode* oddEvenList(ListNode* head) {
        ListNode dummyNode1(0), dummyNode2(0);
        ListNode* pOdd = &dummyNode1;
        ListNode* pEven = &dummyNode2;
        ListNode* pCur = head;
        
        while(pCur != nullptr && pCur->next != nullptr)
        {
            pOdd->next = pCur;
            pEven->next = pCur->next;
            
            pOdd = pOdd->next;
            pEven = pEven->next;
            pCur = pCur->next->next;
        }
        
        //处理链表节点个数为奇数的情况
        if(pCur != nullptr)
        {
            pOdd->next = pCur;
            pOdd = pOdd->next;
            pEven->next = nullptr;
        }
        
        pOdd->next = dummyNode2.next;
        return dummyNode1.next;
    }
};

//Code2: 在处理节点时分开处理奇偶节点，用一个数字测试是奇节点还是偶节点
ListNode* oddEvenList(ListNode* head)
{
    if (head == nullptr) return nullptr;

    ListNode dummyOdd(0);
    ListNode dummyEven(0);
    ListNode *odd = &dummyOdd;
    ListNode *even = &dummyEven;
    int num = 1;
    while (head != nullptr)
    {
        ListNode *next = head->next;
        if (num%2 != 0)
        {
            odd->next = head;
            odd = odd->next;
            odd->next = nullptr;
        }
        else
        {
            even->next = head;
            even = even->next;
            even->next = nullptr;
        }
        head = next;
        num++;
    }

    odd->next = dummyEven.next;
    return dummyOdd.next;
}
