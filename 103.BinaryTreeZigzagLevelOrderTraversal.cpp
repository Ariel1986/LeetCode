/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
*/

//Code:
 vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
     if (root == nullptr) return{};

     std::vector<std::vector<int>> result;
     std::vector<int> column;
     std::deque<TreeNode*> deq;
     bool leftToRight = true;
     deq.emplace_back(root);
     deq.emplace_back(nullptr);

     while (!deq.empty())
     {
         TreeNode* pCur = deq.front();
         deq.pop_front();

         if (pCur == nullptr)
         {
             if (!leftToRight)
                 std::reverse(column.begin(), column.end());
             result.emplace_back(column);
             column.clear();
             
             if(!deq.empty())
                deq.emplace_back(nullptr);
                
             leftToRight = !leftToRight;
         }
         else
         {
             column.emplace_back(pCur->val);
             if (pCur->left) deq.emplace_back(pCur->left);
             if (pCur->right) deq.emplace_back(pCur->right);
         }
     }

     return result;
 }
