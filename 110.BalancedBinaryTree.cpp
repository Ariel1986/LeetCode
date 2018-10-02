/*
Given a binary tree, determine if it is height-balanced.
For this problem, a height-balanced binary tree is defined as a binary tree 
in which the depth of the two subtrees of every node never differ by more than 1.
*/

//Code:
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        
        std::function<int(TreeNode*)>
        getDepth = [&](TreeNode* root) -> int
        {
            if(root == nullptr) return 0;
            return std::max(getDepth(root->left), getDepth(root->right)) + 1;
        };

        if(std::abs(getDepth(root->left) - getDepth(root->right)) > 1)
            return false;
        return isBalanced(root->left) &&  isBalanced(root->right);
    }
