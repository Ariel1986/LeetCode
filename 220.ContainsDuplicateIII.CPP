/*Question:
Given an array of integers, find out whether there are two distinct indices i and j in the array such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.
Subscribe to see which companies asked this question
Tags: Binary Search Tree
Similar Problems: (E) Contains Duplicate (E) Contains Duplicate II
*/

/*思路:
方法二：
用二叉查找树实现
*/

//Code:
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int sz = nums.size();
        std::vector<std::pair<long, int>> mapping; //The first type should be long

        for (int i = 0; i < sz; ++i)
            mapping.push_back(std::make_pair(nums[i], i));
        
        std::sort(mapping.begin(), mapping.end());
        
        for (int i = 0; i < sz; ++i)
        {
            for (int j = i + 1; j < sz && mapping[j].first - mapping[i].first <= t; ++j)
            {
                if (std::abs(mapping[i].second - mapping[j].second) <= k)
                    return true;
            }
        }

        return false;
    }
};


//Code 2: (by Java)
private TreeNode add(TreeNode root, TreeNode nNode) {
    if(root == null) {
        return nNode;
    }
    else if(root.val < nNode.val) {
        root.right = add(root.right, nNode);
        return root;
    }
    else {
        root.left = add(root.left, nNode);
        return root;
    }
}

private TreeNode delete(TreeNode root, TreeNode dNode) {
    if(root == null) {
        return null;
    }
    else if(root.val < dNode.val) {
        root.right = delete(root.right, dNode);
        return root;
    }
    else if(root.val > dNode.val) {
        root.left = delete(root.left, dNode);
        return root;
    }
    else if(root == dNode) {
         if(dNode.left == null && dNode.right == null) return null;
         else if(dNode.left != null && dNode.right == null) return dNode.left;
         else if(dNode.right != null && dNode.left == null) return dNode.right;
         else {
             TreeNode p = dNode.right;
             while(p.left != null) p = p.left;
             dNode.right = delete(dNode.right, p);
             p.left = dNode.left;
             p.right = dNode.right;
             return p;
         }
    }
    else {
        return root;
    }
}

private boolean search(TreeNode root, long val, int t) {
    if(root == null) {
        return false;
    }
    else if(Math.abs((root.val - val)) <= t) {
        return true;
    }
    else if((root.val - val) > t) {
        return search(root.left, val, t);
    }
    else {
        return search(root.right, val, t);
    }
}

public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
    if(k < 1 || t < 0 || nums.length <= 1) {
        return false;
    }
    int len = nums.length;
    TreeNode[] map = new TreeNode[len];
    map[0] = new TreeNode((long)nums[0]);
    TreeNode root = null;
    root = add(root, map[0]);
    for(int i = 1; i < len; i++) {
        if(search(root, (long)nums[i], t)) {
            return true;
        }
        map[i] = new TreeNode((long)nums[i]);
        if(i - k >= 0) {
            root = delete(root, map[i-k]);
        }
        root = add(root, map[i]);
    }
    return false;
}

//Code 3:
bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int k, int t) 
{ 
    if (nums.size() <= 1 || k <= 0) return false;  
    std::multimap<long long, int> m; 
    for (int i = 0, iEnd = nums.size(); i < iEnd; ++i) 
    { 
        m.emplace(nums[i], i); 
    } 
    for (auto it1 = m.cbegin(); it1 != m.cend(); ++it1) 
    { 
        auto it2 = it1; 
        while (++it2 != m.cend() && std::abs(it1->first - it2->first) <= t) 
        { 
            if (std::abs(it1->second - it2->second) <= k) 
                return true; 
        } 
    } 
    return false; 
}
