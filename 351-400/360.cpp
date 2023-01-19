class Solution {
public:
    int f(int a, int b, int c, int x){
        return a * x * x + b * x + c;
    }
    
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n = nums.size(), l = 0, r = n - 1;
        vector<int> ans(n, 0);
        
        if(a > 0){
            int it = n - 1;
            while(l <= r){
                int lv = f(a, b, c, nums[l]), rv = f(a, b, c, nums[r]);
                if(lv > rv){
                    ans[it] = lv;
                    ++l;
                }
                else{
                    ans[it] = rv;
                    --r;
                }
                --it;
            }
        }
        else{
            int it = 0;
            while(l <= r){
                int lv = f(a, b, c, nums[l]), rv = f(a, b, c, nums[r]);
                if(lv < rv){
                    ans[it] = lv;
                    ++l;
                }
                else{
                    ans[it] = rv;
                    --r;
                }
                ++it;
            }
        }
        
        return ans;
    }
};