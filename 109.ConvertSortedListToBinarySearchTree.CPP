/* Question:
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
Tags: Depth-first Search Linked List
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 class Solution {
 public:

     TreeNode* sortedListToBST(ListNode* head) {
         if (head == nullptr) return nullptr;


         int len = 0;
         for (ListNode* p = head; p != nullptr; p = p->next)
             ++len;

         std::function<TreeNode* (ListNode*, int)>
             sortedListToBSTProxy = [&](ListNode* head, int len)->TreeNode*
         {
             if (head == nullptr || len < 1) return nullptr;
             if (len == 1)
                 return new TreeNode(head->val);

             auto goToMid = [&head](int len) -> ListNode*
             {
                 ListNode* pMid = head;
                 for (int i = 0, iEnd = len / 2; i < iEnd && pMid->next != nullptr; ++i)
                     pMid = pMid->next;
                 return pMid;
             };

             ListNode* pMid = goToMid(len);
             TreeNode* root = new TreeNode(pMid->val);
             root->left = sortedListToBSTProxy(head, len / 2);
             root->right = sortedListToBSTProxy(pMid->next, len - len / 2 - 1);

             return root;
         };
         TreeNode* root = sortedListToBSTProxy(head, len);
         return root;
     }
 };
