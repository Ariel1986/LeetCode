/*
Given a (singly) linked list with head node root, write a function to split the linked list into k consecutive linked list "parts".

The length of each part should be as equal as possible: no two parts should have a size differing by more than 1. This may lead to some parts being null.

The parts should be in order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal parts occurring later.

Return a List of ListNode's representing the linked list parts that are formed.

Examples 1->2->3->4, k = 5 // 5 equal parts [ [1], [2], [3], [4], null ]
Example 1:
Input: 
root = [1, 2, 3], k = 5
Output: [[1],[2],[3],[],[]]
Explanation:
The input and each element of the output are ListNodes, not arrays.
For example, the input root has root.val = 1, root.next.val = 2, \root.next.next.val = 3, and root.next.next.next = null.
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but it's string representation as a ListNode is [].
Example 2:
Input: 
root = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 3
Output: [[1, 2, 3, 4], [5, 6, 7], [8, 9, 10]]
Explanation:
The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.
Note:

The length of root will be in the range [0, 1000].
Each value of a node in the input will be an integer in the range [0, 999].
k will be an integer in the range [1, 50].
Seen this question in a real interview before?


*/

//Code:
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func splitListToParts(root *ListNode, k int) []*ListNode {
	resp := make([]*ListNode, k)
    
    //Note:为空的时候，返回多个空[],所以一下判断是错误的
	// if root == nil || k < 0 {
	// 	return []*ListNode{root}
	// }
	ListLen := func(root *ListNode) int {
		resp := 0
		for root != nil {
			resp++
			root = root.Next
		}

		return resp
	}

	len := ListLen(root)

	mod := len % k
	pCur := root
	for i := 0; i < k && pCur != nil; i++ {
		resp[i] = pCur

		//pCur后移subLen个长度 && resp[i]的最后一个元素的next置为nil
		subLen := len / k
		if mod > 0 {
			subLen++
		}
		mod--
		for j := 0; j < subLen-1; j++ {
			if pCur == nil {
				break
			}
			pCur = pCur.Next
		}
		pNext := pCur.Next
		pCur.Next = nil
		pCur = pNext
	}

	return resp
}
