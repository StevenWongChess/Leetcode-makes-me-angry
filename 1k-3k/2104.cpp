class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> lmin(n), rmin(n), lmax(n), rmax(n);
        stack<int> minindex, maxindex;
        
        for(int i = 0; i < n; ++i){
            while(!minindex.empty() && nums[minindex.top()] > nums[i]){
                minindex.pop();
            }
            lmin[i] = minindex.empty() ? -1 : minindex.top();
            minindex.push(i);
            
            while(!maxindex.empty() && nums[maxindex.top()] <= nums[i]){
                maxindex.pop();
            }
            lmax[i] = maxindex.empty() ? -1 : maxindex.top();
            maxindex.push(i);
        }
        
        minindex = {}, maxindex = {};
        
        for(int i = n - 1; i >= 0; --i){
            while(!minindex.empty() && nums[minindex.top()] >= nums[i]){
                minindex.pop();
            }
            rmin[i] = minindex.empty() ? n : minindex.top();
            minindex.push(i);
            
            while(!maxindex.empty() && nums[maxindex.top()] < nums[i]){
                maxindex.pop();
            }
            rmax[i] = maxindex.empty() ? n : maxindex.top();
            maxindex.push(i);
        }
        
        long long ans = 0;
        for(int i = 0; i < n; ++i){
            ans += static_cast<long long>(nums[i]) * (rmax[i] - i) * (i - lmax[i]);
            ans -= static_cast<long long>(nums[i]) * (rmin[i] - i) * (i - lmin[i]);
        }
        return ans;
    }
};