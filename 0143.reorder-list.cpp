/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.
Example 2:

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.

*/

//code:
func reorderList(head *ListNode) {
	if head == nil || head.Next == nil {
		return
	}
	reverseList := func(head *ListNode) *ListNode {
		if head == nil {
			return head
		}
		pre := &ListNode{Next: head}
		cur := head.Next
		head.Next = nil
		for cur != nil {
			next := cur.Next
			cur.Next = pre.Next
			pre.Next = cur
			cur = next
		}
		return pre.Next
	}

	ps := head
	pf := head.Next
	for pf != nil && pf.Next != nil {
		ps = ps.Next
		pf = pf.Next.Next
	}

	if pf != nil {
		ps = ps.Next
	}

	//处理尾元素 && 反转
	pf = ps.Next
	pf = reverseList(pf)
	ps.Next = nil
	ps = head
	for pf != nil {
		pNext := pf.Next

		pf.Next = ps.Next
		ps.Next = pf
		ps = ps.Next.Next
		pf = pNext
	}
	return
}
