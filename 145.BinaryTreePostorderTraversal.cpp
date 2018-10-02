/*
Given a binary tree, return the postorder traversal of its nodes' values.
For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].
Note: Recursive solution is trivial, could you do it iteratively?
Tags: Tree, Stack
*/


//Code:
//Code 1: 递归
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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == nullptr)
            return {};
        std::vector<int> result;
        
        std::function<void(TreeNode*)>
        postorderTraversalHelper = [&](TreeNode* pRoot)
        {
            if(pRoot == nullptr) return;
            postorderTraversalHelper(pRoot->left);
            postorderTraversalHelper(pRoot->right);
            result.emplace_back(pRoot->val);
        };
        
        postorderTraversalHelper(root);
       
        return result;
    }
};

//Code 2: 递归，但是设置一个标志位在栈里，标志该节点的左右子树是否已被访问
 vector<int> postorderTraversal(TreeNode* root) {
     if (root == nullptr)
         return{};
     std::vector<int> result;
     std::stack<std::pair<TreeNode*, bool>> s;
     s.emplace(std::make_pair(root, false));

     while (!s.empty())
     {
         auto& pCur = s.top();
         if (!pCur.second)
         {
             if (pCur.first->right != nullptr)
                 s.emplace(std::make_pair(pCur.first->right, false));
             if (pCur.first->left != nullptr)
                 s.emplace(std::make_pair(pCur.first->left, false));
             pCur.second = true;
         }
         else
         {
             result.emplace_back(pCur.first->val);
             s.pop();
         }
     }
     return result;
 }
 
 //Code 3: 递归
  vector<int> postorderTraversal(TreeNode* root) {
     if (root == nullptr) return{};

     std::vector<int> result;
     std::stack<TreeNode*> s;

     s.emplace(root);
     TreeNode* pPre = nullptr;
     while (!s.empty())
     {
         auto pCur = s.top();

         if (pPre == nullptr || pPre->left == pCur || pPre->right == pCur)
         {
             if (pCur->left != nullptr)
                 s.emplace(pCur->left);
             else if (pCur->right != nullptr)
                 s.emplace(pCur->right);
         }
         // Left node has been visited, and then visited the right node
         else if (pCur->left == pPre)
             {
                 if (pCur->right != nullptr)
                     s.emplace(pCur->right);
             }
             else
             {
                 s.pop();
                 result.emplace_back(pCur->val);
             }
         pPre = pCur;
     }
     return result;
