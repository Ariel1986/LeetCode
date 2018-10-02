/* Question:
Find the sum of all left leaves in a given binary tree.
Example:
    3
   / \
  9  20
    /  \
   15   7
There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
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
int sumOfLeftLeaves(TreeNode* root) {
    if(root == nullptr)
        return 0;
    int sum = 0;
    TreeNode* p = nullptr;
    std::stack<TreeNode*> s;
    s.push(root);
    
    while(!s.empty())
    {
        p = s.top();
        s.pop();
        if(p->right != nullptr)
        {
            s.push(p->right);
        }
        if(p->left != nullptr)
        {
            if(p->left->left == nullptr && p->left->right == nullptr)
                sum += p->left->val;
            else
            {
                s.push(p->left);
            }
        }
    }

    return sum;
}
};
