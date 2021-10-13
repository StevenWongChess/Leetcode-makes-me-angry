class Solution {
public:
    int select(vector<int>& nums, int l, int r, int k){
        int pivot = rand() % (r - l + 1) + l;
        swap(nums[pivot], nums[r]);
        int j = l;
        for(int i = l; i < r; i++){
            if(nums[i] <= nums[r]){
                swap(nums[i], nums[j]);
                j++;
            }
        }
        swap(nums[r], nums[j]);
        if(k == j)
            return nums[k];
        else if(k > j)
            return select(nums, j + 1, r, k);
        else    
            return select(nums, l, j - 1, k);
    }

    int findKthLargest(vector<int>& nums, int k) {
        srand(0);
        return select(nums, 0, nums.size() - 1, nums.size() - k);
    }
};