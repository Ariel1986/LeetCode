/*Question:
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.
get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
Follow up:
Could you do both operations in O(1) time complexity?
Example:
LRUCache cache = new LRUCache( 2 // capacity  );
cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/

/*Method:
========================Method1======================
用unordered_map保存[key, <value, list<key>::iterator>];
Get：如果找到，在list<key>里面将当前key放到list的begin；
Set：
如果找到，在list<key>里面将当前key放到list的begin；
如果未找到：
  1）如果capacity已经占满，删掉used中最后一个值对应的cache元素，将used中的最后一个值删除。
  2）将key放入used的begin
更新cache中[key, <value, list<key>::iterator>]的值;
========================Method2======================
使用std::list的splice方法去更新元素，将元素放在链表头。在该方法中，存储在hash table中的iterator不需要更新。
*/

//======================Code 1======================
class LRUCache {
public:
    LRUCache(int capacity): capacity_(capacity) {
    }
    
    int get(int key) {
        auto iter = cache.find(key);
        if(iter != cache.end()){
            updateUsedProxy(iter);
            return iter->second.first;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto iter = cache.find(key);
        
        if (iter != cache.end()) {
            updateUsedProxy(iter);
        }
        else{
            if(cache.size() == capacity_){
                cache.erase(used.back());
                used.pop_back();
            }
            used.push_front(key);
        }
        
        cache[key]= std::make_pair(value, used.begin());
        
        return;
    }
    
private:
    //[key, <value, list<key>::iterator>]
    typedef std::unordered_map<int, std::pair<int, std::list<int>::iterator>> HIPII;
    
    void updateUsedProxy(HIPII::iterator iter){
        if (iter->second.second == used.begin()){
            return;
        }
        
        int key = iter->first;
        used.erase(iter->second.second);
        used.push_front(key);
        iter->second.second = used.begin();
        return;
    }
    
    std::size_t capacity_;
    std::list<int> used;  //保存key，并将最新访问的放在前面
    HIPII cache;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */


//===================Code 2============================
class LRUCache {
public:
    LRUCache(int capacity): capacity_(capacity) {
    }
    
    int get(int key) {
        if(helperHash.find(key) != helperHash.end()){
            if(helperHash[key] != used.begin()){
                used.splice(used.begin(), used, helperHash[key]);
            }
            return used.begin()->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (helperHash.find(key) != helperHash.end()) {
            if(helperHash[key] != used.begin()){
                used.splice(used.begin(), used, helperHash[key]);
            }
            used.begin()->second = value;
        }
        else{
            if(helperHash.size() == capacity_){
                helperHash.erase(used.back().first);
                used.pop_back();
            }
            used.push_front(std::make_pair(key, value));
            helperHash[key] = used.begin();
        }
        
        return;
    }
    
private:
    typedef std::list<std::pair<int, int>> PList;
    
    std::size_t capacity_;
    PList used;  //[key,value]
    std::unordered_map<int, PList::iterator> helperHash; //[key, list<key,value>::iterator]
};
