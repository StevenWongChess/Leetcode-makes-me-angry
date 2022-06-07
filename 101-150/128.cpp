class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> dict;
        for(auto i: nums){
            dict[i] = true;
        }
        int ans = 0;
        for(auto i: nums){
            if(dict.find(i - 1) != dict.end())
                continue;
            int count = 0;
            while(dict.find(i) != dict.end()){
                count++;
                i++;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};