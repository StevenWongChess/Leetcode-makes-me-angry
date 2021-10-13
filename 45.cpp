class Solution {
public:
    int jump(vector<int>& nums) {
        int farthest = 0;
        int steps = 0;
        int tmp = 0;
        for(int i = 0; i < nums.size(); i++){
            if(farthest >= nums.size() - 1)
                return steps;
            tmp = max(tmp, i + nums[i]);
            if(i == farthest){
                farthest = max(farthest, tmp);
                steps++;
            }
        }
        return steps;
    }
};