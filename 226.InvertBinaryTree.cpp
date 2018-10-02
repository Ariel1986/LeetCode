/*
Invert a binary tree.
     4
   /   \
  2     7
 / \   / \
1   3 6   9
to
     4
   /   \
  7     2
 / \   / \
9   6 3   1
*/

//Code:
//Code 1:递归
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
    TreeNode* invertTree(TreeNode* root) {
        std::function<void(TreeNode*)> 
        invertTreeHelper = [&](TreeNode* root)
        {
            if(root == nullptr) return;
            TreeNode* pTemp = root->left;
            root->left = root->right;
            root->right = pTemp;
            invertTreeHelper(root->left);
            invertTreeHelper(root->right);
        };
        
        invertTreeHelper(root);
        return root;
    }
};

//Code 2：非递归
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;
        
        std::stack<TreeNode*> s;
        s.emplace(root);
        while(!s.empty())
        {
            TreeNode* pCur = s.top();
            s.pop();
            std::swap(pCur->left, pCur->right);
            if(pCur->left != nullptr) 
                s.emplace(pCur->left);
            if(pCur->right != nullptr) 
                s.emplace(pCur->right);   
        }
        
        return root;
    }
