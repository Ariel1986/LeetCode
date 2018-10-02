/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
*/

//Code:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
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
        
        std::reverse(result.begin(), result.end());
        return result;
    }
