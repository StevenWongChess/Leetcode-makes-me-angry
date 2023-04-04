class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int ans = 1;
        int inc = 1, dec = 0, pre = 1;

        for(int i = 1; i < n; ++i){
            if(ratings[i] > ratings[i - 1]){
                dec = 0;
                ++pre;
                ans += pre;
                inc = pre;
            }
            else if(ratings[i] == ratings[i - 1]){
                dec = 0;
                inc = pre = 1;
                ++ans;
            }
            else{
                ++dec;
                if(dec == inc)
                    ++dec;
                ans += dec;
                pre = 1;
            }
        }
        return ans;
    }
};