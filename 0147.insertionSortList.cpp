/*
Sort a linked list using insertion sort.


A graphical example of insertion sort. The partial sorted list (black) initially contains only the first element in the list.
With each iteration one element (red) is removed from the input data and inserted in-place into the sorted list
*/

//code:
func insertionSortList(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	head2 := &ListNode{Next: head}
	sort := head //指向前面排序元素的最后一个元素

	cur := head.Next
	head.Next = nil
	for cur != nil {
		next := cur.Next
		cur.Next = nil
		if sort.Val <= cur.Val { //最后一个元素<当前元素，直接插入
			sort.Next = cur
			sort = sort.Next
		} else {
			pPos := head2
			for pPos.Next != nil && pPos.Next.Val < cur.Val {
				pPos = pPos.Next
			}
			cur.Next = pPos.Next
			pPos.Next = cur
		}
		cur = next
	}

	return head2.Next
}
