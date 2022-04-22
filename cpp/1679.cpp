class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> dict;
        int ans = 0;

        for (auto i : nums)
        {
            if (dict.count(k - i) && dict[k - i] > 0)
            {
                --dict[k - i];
                ++ans;
            }
            else
                ++dict[i];
        }

        return ans;

        //         int n = nums.size();
        //         sort(nums.begin(), nums.end());
        //         int l = 0; int r = n - 1;
        //         int ans = 0;

        //         while(l < r){
        //             int sum = nums[l] + nums[r];
        //             if(sum == k){
        //                 ++l; --r; ++ans;
        //             }
        //             else if(sum < k)
        //                 ++l;
        //             else
        //                 --r;
        //         }

        //         return ans;
    }
};