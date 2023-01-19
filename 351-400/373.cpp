class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        if(k / m >= n){
            k = m * n;
        }        
        auto cmp = [](pair<int, int> a, pair<int, int> b){
            return a.first + a.second < b.first + b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(pq.size() < k){
                    pq.push({nums1[i], nums2[j]});
                }
                else{
                    auto [x, y] = pq.top();
                    if(x + y > nums1[i] + nums2[j]){
                        pq.pop();
                        pq.push({nums1[i], nums2[j]});
                    }
                    else{
                        break;
                    }
                }
            }
        }

        vector<vector<int>> ans(k);
        for(int i = 0; i < k; ++i){
            auto [x, y] = pq.top();
            pq.pop();
            ans[k - 1 - i] = {x, y};
        }
        return ans;
    }
};