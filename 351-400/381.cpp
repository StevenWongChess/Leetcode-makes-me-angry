class RandomizedCollection {
public:
    vector<int> v;
    unordered_map<int, unordered_set<int>> dict;
    RandomizedCollection() {
        
    }

    void print(){
        for(auto i: v){
            cout << i << " ";
        }
        cout << endl;
        for(auto [x, y]: dict){
            cout << x << ": ";
            for(auto i: y)
                cout << i << " ";
            cout << endl;
        }
    }
    
    bool insert(int val) {
        v.push_back(val);
        dict[val].insert(v.size() - 1);
        return dict[val].size() == 1;
    }
    
    bool remove(int val) {
        if(dict.count(val)){
            int n = dict[val].size(), m = v.size();
            if(v.back() == val){
                v.pop_back();
                dict[val].erase(m - 1);
            }
            else{
                int idx = *dict[val].begin();
                int _val = v.back();

                dict[val].erase(idx);
                swap(v[idx], v[m - 1]);
                v.pop_back();
                dict[_val].insert(idx);
                dict[_val].erase(m - 1);
            }
            if(n == 1)
                dict.erase(val);
            return true;
        }
        else{
            return false;
        }
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