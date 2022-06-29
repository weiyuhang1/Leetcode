class LRUCache {
    list<pair<int, int>> storage;
    unordered_map<int, list<pair<int, int>> :: iterator> lookup;
    int storagecapacity;
public:
    
    LRUCache(int capacity) {
        storagecapacity = capacity;
    }
    
    int get(int key) {
        if (lookup.find(key) == lookup.end()) return -1;
        auto it = lookup[key];
        storage.splice(storage.begin(), storage, it);
        return it->second;
        
    }
    
    void put(int key, int value) {
        //key exists
        if (lookup.find(key) != lookup.end()) {
            auto it = lookup[key];
            it->second = value;
            storage.splice(storage.begin(), storage, it);
            return;
        }
        
        if (storage.size() == storagecapacity) {
            int key_to_delete = storage.back().first;
            storage.pop_back();
            lookup.erase(key_to_delete);
        }
        storage.push_front({key, value});
        lookup[key] = storage.begin();
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */