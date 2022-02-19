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