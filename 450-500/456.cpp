class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        
        if(n < 3){
            return false;
        }
        
        int left_min = nums[0];
        multiset<int> r_set;
        
        for(int i = 2; i < n; ++i){
            r_set.insert(nums[i]);
        }
        
        for(int i = 1; i < n - 1; ++i){
            if(left_min < nums[i]){
                auto it = r_set.upper_bound(left_min);
                if(it != r_set.end() && *it < nums[i]){
                    return true;
                }
            }
            left_min = min(left_min, nums[i]);
            r_set.erase(r_set.find(nums[i + 1]));
        }
        return false;
    }
};





class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(n < 3){
            return false;
        }
        
        stack<int> s;
        s.push(nums[n - 1]);
        int max_k = INT_MIN;
        
        for(int i = n - 2; i >= 0; --i){
            if(nums[i] < max_k)
                return true;
            while(!s.empty() && nums[i] > s.top()){
                max_k = max(max_k, s.top());
                s.pop();
            }
            if(nums[i] > max_k){
                s.push(nums[i]);
            }
        }
        
        return false;
    }
};