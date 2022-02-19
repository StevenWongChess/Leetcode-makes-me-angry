class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        multiset<int> s(nums.begin(), nums.begin() + k);
        auto l = s.begin();
        for(int i = 0; i < (k - 1) / 2; i++){
            l++;
        }

        for(int i = k; i < nums.size(); i++){
            auto r = l; if(!(k & 1)) r++;
            ans.push_back(*l / 2.0 + *r / 2.0);
            s.insert(nums[i]);
            if(nums[i] < *l)
                l--;
            if(nums[i - k] <= *l)
                l++;
            s.erase(s.lower_bound(nums[i - k]));
        }
        cout << *l << endl;
        auto r = l; if(!(k & 1)) r++;
        ans.push_back(*l / 2.0 + *r / 2.0);
        return ans;
    }
};