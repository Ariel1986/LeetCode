/* Question:
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
Tags: Trees, Deepth-first search
*/

/* Method:
方法一：
直接借助递归实现
方法二：非递归
借助两个栈，栈s1用来保存要访问的树的节点，实现树的深度遍历；
栈s2保存从根节点到当前节点的路径上的所有节点；
对于每一个根节点判断curSum?=sum,如果是，则返回true； 否则，则要对curSum做相应处理。
如果访问的节点是右节点／或者左节点，但是其父节点没有右子节点，那么curSum也要减去其父节点的值。这就是s2存在的意义。
同时，为了方便判断是否需要curSum减去父节点的值，需要在栈中保存额外的判断信息。
*/

// code:
//Code 1:
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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == nullptr) return false;
        if(root->left == nullptr && root->right == nullptr && root->val == sum)
            return true;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};

// Code 2:
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == nullptr) return false;
        
        std::pair<TreeNode*, bool> pNode;
        std::stack<std::pair<TreeNode*, bool>> s;
        std::stack<std::pair<int, bool>> sHelper;   //保存从根节点到当前节点的所有路径节点
        
        int curSum = 0;
        s.emplace(std::make_pair(root, false));
        
        while(!s.empty())
        {
            pNode = s.top();
            s.pop();
            
            curSum += pNode.first->val;
            
            if(pNode.first->left == nullptr && pNode.first->right == nullptr)
            {
                if(curSum == sum)
                    return true;
                else 
                {
                    curSum -= pNode.first->val;

                    if(pNode.second)
                    {
                        auto tmp = sHelper.top();
                        sHelper.pop();
                        curSum -= tmp.first;
                        
                        while(tmp.second)
                        {
                            tmp = sHelper.top();
                            sHelper.pop();
                            curSum -= tmp.first;
                        }
                    }
                }
            }
            else 
            {
                sHelper.emplace(std::make_pair(pNode.first->val, pNode.second));
                
                if(pNode.first->right != nullptr) 
                    s.emplace(std::make_pair(pNode.first->right, true));
                    
                if(pNode.first->left != nullptr) 
                {
                    if(pNode.first->right != nullptr)
                        s.emplace(std::make_pair(pNode.first->left,false));
                    else 
                        s.emplace(std::make_pair(pNode.first->left,true));
                }
                    
            }
        }
        
        return false;
    }
};
