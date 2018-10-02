/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
*/

//Code:
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        
        std::vector<std::vector<int>> result;
        std::vector<int> temp;
        std::deque<TreeNode*> deq;
        
        deq.emplace_back(root);
        deq.emplace_back(nullptr);
        while(!deq.empty())
        {
            auto pNode = deq.front();
            deq.pop_front();
            if(pNode == nullptr)
            {
                result.emplace_back(temp);
                temp.clear();
                if(!deq.empty())  //This condition is important
                    deq.emplace_back(nullptr);
            }
            else
            {
                temp.emplace_back(pNode->val);
                if(pNode->left != nullptr)
                    deq.emplace_back(pNode->left);
                if(pNode->right != nullptr)
                    deq.emplace_back(pNode->right);
            }
        }
        
        return result;
    }
};
