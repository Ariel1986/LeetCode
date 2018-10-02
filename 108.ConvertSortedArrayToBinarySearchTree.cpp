// Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return nullptr;
        
        std::function<TreeNode* (int, int)>
        sortedArrayToBSTHelper = [&](int start, int end)->TreeNode*
        {
            if(start > end) return nullptr;
            if(start == end) return new TreeNode(nums[start]);
            
            int mid = start + (end - start) / 2;
            TreeNode* root = new TreeNode(nums[mid]);
            root->left = sortedArrayToBSTHelper(start, mid - 1);
            root->right = sortedArrayToBSTHelper(mid + 1, end);
            return root;
        };
        
        auto root = sortedArrayToBSTHelper(0, nums.size() - 1);
        return root;
    }
};
