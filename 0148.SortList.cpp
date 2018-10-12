/*
Sort a linked list in O(n log n) time using constant space complexity.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5
*/

//Code:
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func splict(head *ListNode) *ListNode {
	pSlow, pFast := head, head.Next
	for pFast != nil && pFast.Next != nil {
		pSlow = pSlow.Next
		pFast = pFast.Next.Next
	}
	pFast = pSlow.Next
	pSlow.Next = nil
	return pFast
}

func merge(left, right *ListNode) *ListNode {
	if left == nil {
		return right
	}
	if right == nil {
		return left
	}
	dummyHead := ListNode{}
	pre := &dummyHead
	for left != nil && right != nil {
		if left.Val < right.Val {
			pre.Next = left
			left = left.Next
		} else {
			pre.Next = right
			right = right.Next
		}
		pre = pre.Next
	}
	if left != nil {
		pre.Next = left
	}
	if right != nil {
		pre.Next = right
	}

	return dummyHead.Next
}

func sortList(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	mid := splict(head)

	return merge(sortList(head), sortList(mid))
}
