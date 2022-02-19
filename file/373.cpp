class Solution {
public:
    struct cmp{
        bool operator()(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
            return a.first + a.second.second > b.first + b.second.second;
        }
    };
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> ans;
        if(n == 0 || m == 0)
            return ans;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, cmp> pq;
        for(int i = 0; i < n; i++){
            pq.push(pair<int, pair<int, int>>(nums1[i], pair<int, int>(0, nums2[0])));
        }
        for(int i = 0; i < k && !pq.empty(); i++){
            auto p = pq.top();
            vector<int> v;
            v.push_back(p.first); v.push_back(p.second.second);
            ans.push_back(v);
            pq.pop();
            if(p.second.first < m - 1){
                pq.push(pair<int, pair<int, int>>(p.first, pair<int, int>(p.second.first + 1, nums2[p.second.first + 1])));
            }
        }
        return ans;
    }
};