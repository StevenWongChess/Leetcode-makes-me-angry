class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int mmax = 0;
        for(auto i: nums){
            mmax = max(mmax, i);
        }
        vector<int> freq(mmax + 1, 0);
        for(auto i: nums){
            freq[i] += i;
        }
        int pick = 0;
        int not_pick = 0;
        for(int i = 1; i <= mmax; i++){
            int tmp = pick;
            pick = max(pick, not_pick + freq[i]);
            not_pick = tmp;
        }
        return max(pick, not_pick);

        // sort(nums.begin(), nums.end());
        // int start = -2;
        // int take = 0;
        // int not_take = 0;
        // for(int i = 0; i < nums.size(); i++){


        // }
    }
};