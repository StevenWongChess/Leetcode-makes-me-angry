class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int l = *min_element(nums.begin(), nums.end()), 
        r = *max_element(nums.begin(), nums.end()), 
        n = nums.size();
        if(n < 2)
            return 0;
        int size = max(1, (r - l) / (n - 1)),
        m = (r - l) / size + 1;
        
        vector<int> vmax(m, -1), vmin(m, INT_MAX);

        for(auto i: nums){
            int idx = (i - l) / size;
            vmax[idx] = max(vmax[idx], i);
            vmin[idx] = min(vmin[idx], i);
        }

        int ans = 0;
        int a = vmax[0];
        for(int i = 1; i < m; ++i){
            if(vmin[i] != INT_MAX){
                ans = max(ans, vmin[i] - a);
                a = vmax[i];
            }
        }
        return ans;
    }
};




class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n < 2)
            return 0;
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());
        int size = max(1, (high - low) / (n - 1));
        int count = (high - low) / size + 1;
        vector<pair<int, int>> bucket(count, {-1, -1});
        for(int i = 0; i < n; i++){
            int index = (nums[i] - low) / size;
            if(bucket[index].first == -1){
                bucket[index] = {nums[i], nums[i]};
            }
            else{
                bucket[index].first = max(bucket[index].first, nums[i]);
                bucket[index].second = min(bucket[index].second, nums[i]);
            }
        }
        int ans = 0;
        int prev = -1;
        for(int i = 0; i < count; i++){
            if(bucket[i].first != -1){
                if(prev != -1){
                    ans = max(ans, bucket[i].second - prev);
                }
                prev = bucket[i].first;
            }
        }
        return ans;
    }
};