class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n < 2){
            return n;
        }
        
        int a = 1, b = 1; // a up, b down
        for(int i = 1; i < n; ++i){
            if(nums[i] > nums[i - 1]){
                a = max(a, b + 1);
            }
            else if(nums[i] < nums[i - 1]){
                b = max(b, a + 1);
            }
        }
        return max(a, b);
    }
};