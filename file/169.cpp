class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int most = 0;
        int count = 0;
        for(auto i: nums){
            if(i == most)
                count++;
            else
                count--;
            if(count < 0){
                most = i;
                count = 1;
            }
        }
        return most;
    // random algo
        // while(true){
        //     int count = 0;
        //     int pivot = rand() % nums.size();
        //     for(auto i: nums){
        //         if(i == nums[pivot])
        //             count++;
        //     }
        //     if(count > (nums.size() / 2))
        //         return nums[pivot];
        // }
    }
};