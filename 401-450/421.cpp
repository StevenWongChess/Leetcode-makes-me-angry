class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0;
        
        for(int i = 30; i >= 0; --i){
            unordered_set<int> s;
            
            for(auto n: nums){
                s.insert(n >> i);
            }
            
            int tmp = ans * 2 + 1;
            bool flag = false;
            
            for(auto n: nums){
                if(s.count(tmp ^ (n >> i))){
                    flag = true;
                    break;
                }
            }
            
            ans = flag ? tmp : tmp - 1;
        }
        
        return ans;
    }
};