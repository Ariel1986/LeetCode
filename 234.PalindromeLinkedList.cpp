/*
Given a singly linked list, determine if it is a palindrome.
Follow up:
Could you do it in O(n) time and O(1) space?
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
   bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
			return true;
		ListNode* pFast = head;
		ListNode* pSlow = head;
		while(pFast != nullptr && pFast->next != nullptr)
		{
			pSlow = pSlow->next;
			pFast = pFast->next;
			if(pFast != nullptr)
				pFast = pFast->next;
		}

		if(pFast != nullptr)
			pSlow = pSlow->next;

		auto reverseList = [](ListNode* head)->ListNode*{
			if(head == nullptr || head->next == nullptr)
				return head;
			ListNode* pre = nullptr;
			ListNode* cur = head;
			ListNode* nex = nullptr;
			while(cur != nullptr)
			{
				nex = cur->next;
				cur->next = pre;
				pre = cur;
				cur = nex;
			}
			return pre;
		};

		ListNode* pRight = reverseList(pSlow);
		pFast = head;
		while(pRight != nullptr)
		{
			if(pFast->val != pRight->val)
				return false;
			pRight = pRight->next;
			pFast = pFast->next;
		}

		return true;
    }
};
