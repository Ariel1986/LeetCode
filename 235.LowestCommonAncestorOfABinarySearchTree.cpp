/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
According to the definition of LCA on Wikipedia: 
“The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants 
(where we allow a node to be a descendant of itself).”
        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5
For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6.
Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
Tag: tree
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
 
 //Code:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
     if (p == q) return p;
     if (p == nullptr || q == nullptr) return nullptr;
     
     TreeNode* pAnc = root;
     while (pAnc != nullptr)
     {
         if (pAnc == p || pAnc == q
             || pAnc->val > p->val && pAnc->val < q->val
             || pAnc->val < p->val && pAnc->val > q->val)
             return pAnc;
             
         else if (pAnc->val > p->val)
             pAnc = pAnc->left;
             
         else pAnc = pAnc->right;
     }

     return pAnc;
 }
