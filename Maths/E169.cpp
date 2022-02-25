class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        while(true){
            int index = rand() % n;
            int freq = 0;
            for(auto i: nums){
                if(i == nums[index])
                    freq++;
            }
            if(freq > n / 2)
                return nums[index];
        }
        return -1;

        // int candidate = -1;
        // int count = 0;
        // for(int i: nums){
        //     if(i == candidate)
        //         count++;
        //     else{
        //         count--;
        //         if(count < 0){
        //             candidate = i;
        //             count = 1;
        //         }
        //     }
        // }
        // return candidate;
    }
};