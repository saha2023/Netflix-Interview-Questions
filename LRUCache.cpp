class LRUCache {
int cap;
    unordered_map<int,pair<int,int>>mp;
    set<pair<int,int>>st;
    int seq = 0;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(mp.count(key)){
            st.erase({mp[key].second, key});
            st.insert({++seq,key});
            mp[key].second = seq;
            return mp[key].first;
        }
        return -1;
    }
    
    void put(int key, int val) {
        if(mp.count(key)){
            st.erase({mp[key].second, key}); // seq , key
            st.insert({++seq,key});
            mp[key] = {val,seq};
        }
        else{
            if(st.size() == cap){
                auto it = st.begin();
                mp.erase(it->second);
                st.erase({it->first, it->second});
            }
            mp[key]={val,++seq};
            st.insert({seq,key});
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */