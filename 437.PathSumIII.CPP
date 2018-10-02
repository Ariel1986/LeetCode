/*Question:
You are given a binary tree in which each node contains an integer value.
Find the number of paths that sum to a given value.
The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).
The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.
Example:
root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1
Return 3. The paths that sum to 8 are:
1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11
*/

/* Method:
//Method 1:
沿着树的访问路径，用一个hash table记录所有的和的出现次数，对于当前的prefix sum cur，检查（cur－sum）是否存在于hash table。
along the path, record all prefix sums in a hash table. For current prefix sum cur, check if (cur - sum) appears in the hash table.
*/

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
int pathSum(TreeNode* root, int sum) {
    int result = 0;
    std::unordered_map<int,int> m;
    int cur = 0;
    m.emplace(make_pair(0, 1));
    
    std::function<void(TreeNode*, int, int, int&, std::unordered_map<int, int>&)>
    pathSumHelper = [&](TreeNode* root, int cur, int sum, int& total, std::unordered_map<int, int>& m)
    {
        if(root == nullptr) return;
        cur += root->val;
        if(m.find(cur - sum) != m.end()) total += m[cur - sum];
        m[cur]++;
        
        pathSumHelper(root->left, cur, sum, total, m);
        pathSumHelper(root->right, cur, sum, total, m);
        --m[cur];
    };
    
    pathSumHelper(root, cur, sum, result, m);
    return result;
}
};

//Code2:
int pathSum(TreeNode* root, int sum) {
    int result = 0;
    
    std::function<void(TreeNode*, int, int&)>
    pathSumCount = [&](TreeNode* root, int sum, int& result)
    {
        if(root == nullptr) return;
        if(sum - root->val == 0) ++result;
        pathSumCount(root->left, sum - root->val, result);
        pathSumCount(root->right, sum - root->val, result);
    };
    
    std::function<void(TreeNode*, int, int&)>
    pathSumHelper = [&](TreeNode* root, int sum, int& result)
    {
        if(root == nullptr) return;
        pathSumCount(root, sum, result);
        pathSumHelper(root->left, sum, result);
        pathSumHelper(root->right, sum, result);
    };
    
    pathSumHelper(root, sum, result);
    return result;
}
