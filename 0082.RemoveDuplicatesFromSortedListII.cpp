/* Question:
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteDuplicates(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	dummyHead := ListNode{Next: head}
	pPre := &dummyHead
	pCur := head

	for pCur != nil {
		bDel := false
		for pCur != nil && pCur.Next != nil && pCur.Val == pCur.Next.Val {
			pCur = pCur.Next
			bDel = true
		}

		if !bDel { //无重复元素
			pPre.Next = pCur
			pPre = pPre.Next
		}
		pCur = pCur.Next
	}
	pPre.Next = nil
	return dummyHead.Next
}

//Code:
ListNode* deleteDuplicates(ListNode* head) {
    if(head == nullptr || head->next == nullptr)
        return head;
    
    ListNode dummyHead(0);
    ListNode* pPre = &dummyHead;
    ListNode* pCur = head;
    
    while(pCur != nullptr)
    {
        ListNode* pNext = pCur->next;
        
        while(pNext!= nullptr && pNext->val == pCur->val)
            pNext = pNext->next;
        
        //The node only exist one
        if(pNext == pCur->next)
        {
            pPre->next = pCur;
            pPre = pPre->next;
        }
        
        //Delete the duplicate nodes
        else
        {
            ListNode* pTmp = nullptr;
            while(pCur != pNext)
            {
                pTmp = pCur->next;
                delete pCur;
                pCur = pTmp;
            }
        }
        pCur = pNext;
    }
    
    pPre->next = nullptr;
    return dummyHead.next;
}
