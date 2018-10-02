/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
Tags: Tree Depth-first Search Breadth-first Search
*/

//Code:
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
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr ) return true;
        std::function<bool(TreeNode*, TreeNode*)>
        isSymmetricHelper = [&](TreeNode* pLeft, TreeNode* pRight)->bool
        {
            if(pLeft == nullptr && pRight == nullptr)
                return true;
            if(pLeft == nullptr || pRight == nullptr)
                return false;
            if(pLeft->val != pRight->val)
                return false;
            return isSymmetricHelper(pLeft->left, pRight->right) && isSymmetricHelper(pLeft->right, pRight->left); 
        };
        return isSymmetricHelper(root->left, root->right);
    }
};

//Code 2: 非递归 （对于很大的树有Time limit Exceeded的错误
class Solution {
public:
bool isSymmetric(TreeNode* root) {
    if (root == nullptr || (root->left == nullptr && root->right == nullptr))
        return true;
    if ((root->left != nullptr && root->right == nullptr)
        || (root->left == nullptr && root->right != nullptr)
        || (root->left->val != root->right->val))
        return false;

    std::function<int(TreeNode* root)>
        treeDepth = [&](TreeNode* root)->int
    {
        if (root == nullptr)
            return 0;
        if (root->left == nullptr && root->right == nullptr)
            return 1;
        return std::max(treeDepth(root->left), treeDepth(root->right)) + 1;
    };

    int loopTime = treeDepth(root) - 2;

    std::vector<TreeNode*> nodeVec;
    nodeVec.push_back(root->left);
    nodeVec.push_back(root->right);
    int len = 2;
    for (int count = 0; count < loopTime; ++count)
    {
        for (int i = 0, j = len - 1; i < j; ++i, --j)
        {
            if (nodeVec[i] == nullptr && nodeVec[j] == nullptr)
                continue;

            if ((nodeVec[i]->left == nullptr && nodeVec[j]->right == nullptr)
                || ((nodeVec[i]->left != nullptr && nodeVec[j]->right != nullptr)
                    && (nodeVec[i]->left->val == nodeVec[j]->right->val)))
            {
                if ((nodeVec[i]->right == nullptr && nodeVec[j]->left == nullptr)
                    || ((nodeVec[i]->right != nullptr && nodeVec[j]->left != nullptr)
                        && (nodeVec[i]->right->val == nodeVec[j]->left->val)))
                    ;
                else
                    return false;
            }
            else
                return false;
        }

        int iEnd = nodeVec.size();
        for (int i = 0; i < iEnd; ++i)
        {
            if (nodeVec[i] == nullptr)
            {
                nodeVec.push_back(nullptr);
                nodeVec.push_back(nullptr);
            }
            else
            {
                nodeVec.push_back(nodeVec[i]->left);
                nodeVec.push_back(nodeVec[i]->right);
            }
        }
        for (int i = 0; i < iEnd; ++i)
            nodeVec.erase(nodeVec.begin());
        len *= 2;
    }
    return true;
}
};
