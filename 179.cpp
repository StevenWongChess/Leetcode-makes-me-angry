class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ans = "";
        sort(nums.begin(), nums.end(), [](int a, int b){
            long end_a = 10;
            while(end_a <= a)
                end_a *= 10;
            long end_b = 10;
            while(end_b <= b)
                end_b *= 10;
            return end_b * a + b > end_a * b + a;
        });
        if(nums[0] == 0)
            return "0";
        for(auto i: nums){
            ans += to_string(i);
        }
        return ans;
    }
};