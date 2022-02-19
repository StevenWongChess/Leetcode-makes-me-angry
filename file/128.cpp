class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> dict;
        int ans = 0;
        for(auto i: nums){
            dict[i] = true;
        }
        for(auto i: dict){
            if(dict.find(i.first - 1) == dict.end()){
                int count = 1;
                int it = i.first + 1;
                while(dict.find(it) != dict.end()){
                    it++;
                    count++;
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};