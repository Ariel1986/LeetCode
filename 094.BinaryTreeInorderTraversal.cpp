/*
Given a binary tree, return the inorder traversal of its nodes' values.
For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,3,2].
Note: Recursive solution is trivial, could you do it iteratively?
*/

/* Methods
可以用递归或非递归实现
*/

//Code:
//Code 1: 递归实现
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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr)
            return {};
            
        std::vector<int> result;
        
        std::function<void(std::vector<int>&, TreeNode*)>
        inorderTraversalHelper = [&](std::vector<int>& result, TreeNode* pNode)
        {
            if(pNode == nullptr) return;
            
            inorderTraversalHelper(result, pNode->left);
            result.emplace_back(pNode->val);
            inorderTraversalHelper(result, pNode->right);
        };
        
        inorderTraversalHelper(result, root);
        return result;
    }
};

//Code 2: 非递归实现
//先将根节点进栈，访问左子树；然后访问栈顶元素，再访问右节点
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr)
            return {};
            
        std::vector<int> result;
        std::stack<TreeNode*> s;
        TreeNode* pCur = root;
        while(pCur != nullptr || !s.empty())
        {
            if(pCur != nullptr)
            {
                s.push(pCur);
                pCur = pCur->left;
            }
            else
            {
                pCur = s.top();
                s.pop();
                result.emplace_back(pCur->val);
                pCur = pCur->right;
            }
        }
        return result;
    }
