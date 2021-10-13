class Solution {
public:
    vector<vector<int>> ans;
    vector<int> line;
    void dfs(vector<int>& nums, int pos){
        if(pos == nums.size()){
            ans.push_back(line);
            return;
        }
        line.push_back(nums[pos]);
        dfs(nums, pos + 1);
        line.pop_back();
        dfs(nums, pos + 1);
    }
        
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return ans;
        // using base 2 representation
        // vector<vector<int>> ans;
        // int n = nums.size();
        // for(int i = 0; i < pow(2, n); i++){
        //     vector<int> set;
        //     int bit = i;
        //     int pos = n - 1;
        //     while(bit){
        //         if(bit % 2 == 1){
        //             set.push_back(nums[pos]);
        //         }
        //         bit /= 2;
        //         pos--;
        //     }
        //     ans.push_back(set);
        // }
        // return ans;
    }
};