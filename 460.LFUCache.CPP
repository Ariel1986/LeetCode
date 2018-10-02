/* Question:
Design and implement a data structure for Least Frequently Used (LFU) cache. It should support the following operations: get and put.
get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least frequently used item before inserting a new item. For the purpose of this problem, when there is a tie (i.e., two or more keys that have the same frequency), the least recently used key would be evicted.
Follow up:
Could you do both operations in O(1) time complexity?
Example:
LFUCache cache = new LFUCache( 2 // capacity  );
cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.get(3);       // returns 3.
cache.put(4, 4);    // evicts key 1.
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/

//=================Code======================
class LFUCache {
public:
    LFUCache(int capacity):capacity_(capacity){
        
    }
    
    int get(int key) {
        auto iter = cache.find(key);
        if (cache.find(key) == cache.end()){
            return -1;
        }
        UpdateProxy(iter);
        return iter->second.first;
    }
    
    void put(int key, int value) {
        if(capacity_ <= 0) return;
        
        auto iter = cache.find(key);
        if(iter != cache.end()){
            UpdateProxy(iter);
            cache[key].first = value;
        }
        else{
            if(cache.size() >= capacity_){
                int deleteKey =freqMap.begin()->second.front();
                cache.erase(deleteKey);
                keyMap.erase(deleteKey);
                freqMap.begin()->second.pop_front();
            }
            cache[key] = std::make_pair(value, 1);
            freqMap[1].push_back(key);
            keyMap[key] = --freqMap[1].end();
        }
        return;
    }
    
private:
    void UpdateProxy(std::unordered_map<int, std::pair<int,int>>::iterator iter){
        freqMap[iter->second.second].erase(keyMap[iter->first]);
        //如下判断非常重要
        if(freqMap[iter->second.second].size() == 0){
            freqMap.erase(iter->second.second);
        }
        ++iter->second.second;
        freqMap[iter->second.second].push_back(iter->first);
        keyMap[iter->first] = --freqMap[iter->second.second].end();
    }
    
    std::size_t capacity_;
    std::unordered_map<int, std::pair<int, int>> cache; //key->{value, freq}
    std::map<int, std::list<int>> freqMap; //freq->{key1=>key2...}, freq->list
    std::unordered_map<int, std::list<int>::iterator> keyMap; //key->list::iterator
};
