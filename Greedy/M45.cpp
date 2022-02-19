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
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return 0;
        }
        int step = 0;
        for(int i = 0; i < n;){
            int next = 0;
            int far = 0;
            if(i + nums[i] >= n - 1){
                return step + 1;
            }
            for(int j = i + 1; j <= i + nums[i]; j++){
                if(j + nums[j] > far){
                    next = j;
                    far = j + nums[j];
                }
            }
            i = next;
            step++;
        }
        return step;
    }
};