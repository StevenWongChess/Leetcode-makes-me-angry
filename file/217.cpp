class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> dict;
        for(auto i: nums){
            if(dict.find(i) != dict.end()){
                return true;
            }
            else{
                dict[i] = 1;
            }
        }
        return false;
    }
};