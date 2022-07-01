class Solution
{
public:
    vector<int> init;
    vector<int> arr;

    Solution(vector<int> &nums)
    {
        arr = init = nums;
    }

    vector<int> reset()
    {
        arr = init;
        return arr;
    }

    vector<int> shuffle()
    {
        // random_shuffle(arr.begin(), arr.end());
        int n = arr.size();
        for (int i = 0; i < n; ++i)
        {
            int j = i + rand() % (n - i);
            swap(arr[i], arr[j]);
        }

        return arr;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */