// three solutions
class Solution {
public:
    unordered_map<int, int> dict;
    vector<int> ans;
    
    int partition(vector<pair<int, int>>& v, int l, int r){
        int j = l; 
        int pivot = v[r].second;
        for(int i = l; i <= r; i++){
            if(pivot < v[i].second){
                swap(v[i], v[j]);
                j++;
            }
        }
        swap(v[j], v[r]);
        return j;
    }
    void quicksort(vector<pair<int, int>>& v, int k, int l, int r){
        if(k == 0){
            return;
        }
        int mid = partition(v, l, r);
        if(mid == k - 1)
            return;
        else if(mid < k - 1)
            quicksort(v, k, mid + 1, r);
        else
            quicksort(v, k, l, mid - 1);
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        for(auto i: nums){
            dict[i]++;
        }
        vector<pair<int, int>> v(dict.begin(), dict.end());
        quicksort(v, k, 0, v.size() - 1);
        for(int i = 0; i < k; i++){
            ans.push_back(v[i].first);
        }
        return ans;
    }
};

class Solution {
public:
    struct cmp{
        bool operator() (pair<int, int> a, pair<int, int> b){
            return a.second < b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> dict;
        for(auto i: nums){
            dict[i]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq(dict.begin(), dict.end());
        vector<int> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};

class Solution {
public:
    struct cmp{
        bool operator() (pair<int, int> a, pair<int, int> b){
            return a.second > b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> dict;
        for(auto i: nums){
            dict[i]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        for(auto [a, b]: dict){
            pair<int, int> p(a, b);
            if(pq.size() < k){
                pq.push(p);
            }
            else if(b > pq.top().second){
                pq.pop();
                pq.push(p);
            }

        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};