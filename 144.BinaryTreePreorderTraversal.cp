/*
Given a binary tree, return the preorder traversal of its nodes' values.
For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].
Note: Recursive solution is trivial, could you do it iteratively?
Tag: Tree, stack
*/

//Code:
//Code 1:递归实现
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
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == nullptr)
            return {};
        std::vector<int> result;
        
        std::function<void(TreeNode*)>
        preorderTraversalHelper = [&](TreeNode* pRoot)
        {
            if(pRoot == nullptr) return;
            result.emplace_back(pRoot->val);
            preorderTraversalHelper(pRoot->left);
            preorderTraversalHelper(pRoot->right);
        };
       preorderTraversalHelper(root);
       
       return result;
    }
};

//Code 2:非递归，用栈
 vector<int> preorderTraversal(TreeNode* root) {
     if (root == nullptr)
         return{};
     std::vector<int> result;
     std::stack<TreeNode*> s;
     TreeNode* pCur = root;

     while (pCur != nullptr || !s.empty())
     {
         if (pCur != nullptr)    //Also can use: while (pCur != nullptr)
         {
             result.emplace_back(pCur->val);
             if (pCur->right != nullptr)
                 s.emplace(pCur->right);
             pCur = pCur->left;
         }
         else    //if(!s.empty())
         {
             pCur = s.top();
             s.pop();
         }
     }
     return result;
 }
 
 //Code 3: Another method use stack
  vector<int> preorderTraversal(TreeNode* root) {
     if (root == nullptr)
         return{};
     std::vector<int> result;
     std::stack<TreeNode*> s;
     s.emplace(root);
     
     while (!s.empty())
     {
         auto p = s.top();
         s.pop();
         result.emplace_back(p->val);
         
         if(p->right != nullptr)
            s.emplace(p->right);
            
         if(p->left != nullptr)
            s.emplace(p->left);
     }
     
     return result;
 }
