/*
Given a non-empty array of integers, return the k most frequent elements.
For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].
Note: 
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
Tags: Hast table, Heap
*/

/*思路
方法一：
先用map统计每个元素出现的次数，然后存到vector中，根据元素出现的次数排序vector（由大到小），最后将前k个元素作为结果输出
方法二
先用map统计每个元素出现的次数，然后存到vector中，最后对vector建堆，最后得到堆的前k个元素
STD提供的堆的操作函数
std::is_heap
std::pop_heap
std::make_heap
std::push_heap
std::sort_heap
*/

//Code:
//Code 1:
vector<int> topKFrequent(vector<int>& nums, int k) {
    if( k > nums.size()) return nums;
    std::map<int, int> numMap;
    for(auto&& num : nums)
        if(!numMap.emplace(std::make_pair(num, 1)).second)
            ++numMap[num];
    
    std::vector<pair<int, int>> numVec;
    for(auto&& iter : numMap)
        numVec.emplace_back(iter);
    
    std::sort(numVec.begin(), numVec.end(),
              [](const std::pair<int, int>& a, const std::pair<int, int>&  b)
              { return a.second > b.second; }
              );
    
    std::vector<int> result;
    for(int i = 0; i < k; ++i)
        result.emplace_back(numVec[i].first);
        
    return result;
}

//Code 2:
vector<int> topKFrequent(vector<int>& nums, int k) {
    if( k > nums.size()) return nums;
    std::map<int, int> numMap;
    for(auto&& num : nums)
        if(!numMap.emplace(std::make_pair(num, 1)).second)
            ++numMap[num];
    
    std::vector<pair<int, int>> numVec;
    for(auto&& iter : numMap)
        numVec.emplace_back(iter);
    
    std::make_heap(numVec.begin(), numVec.end(),
                   [](const std::pair<int, int> &a, const std::pair<int, int> &b)
                   { return a.second < b.second; }
                   );
    
    std::vector<int> result;
    while(k-- > 0)
    {
        // The lambda is important
        std::pop_heap(numVec.begin(), numVec.end(),
                   [](const std::pair<int, int> &a, const std::pair<int, int> &b)
                   { return a.second < b.second; });
                   
        result.emplace_back(numVec.back().first);
        numVec.pop_back();
    }
    
    return result;
}
