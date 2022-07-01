class RandomizedSet
{
public:
    unordered_map<int, int> dict;
    vector<int> v;

    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (dict.count(val))
            return false;
        v.push_back(val);
        dict[val] = v.size() - 1;
        return true;
    }

    bool remove(int val)
    {
        if (!dict.count(val))
            return false;
        int n = v.size(), index = dict[val];
        swap(v[index], v[n - 1]);
        dict[v[index]] = index;
        dict.erase(v[n - 1]);
        v.pop_back();
        return true;
    }

    int getRandom()
    {
        int index = rand() % v.size();
        return v[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */