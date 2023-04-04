class RandomizedCollection {
public:
    vector<int> v;
    unordered_map<int, unordered_set<int>> dict;
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        v.push_back(val);
        dict[val].insert(v.size() - 1);
        return dict[val].size() == 1;
    }
    
    bool remove(int val) {
        if(dict.count(val) == 0)
            return false;
        int m = dict[val].size();
        auto it = dict[val].begin();
        if(*it != v.size() - 1){
            int a = *it, b = v.size() - 1, c = v[a], d = v[b];
            dict[d].erase(b);
            dict[d].insert(a);
            swap(v[a], v[b]);
        }
        v.pop_back();
        dict[val].erase(it);
        if(m == 1)
            dict.erase(val);
        return true;
    }
    
    int getRandom() {
        int idx = rand() % v.size();
        return v[idx];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */