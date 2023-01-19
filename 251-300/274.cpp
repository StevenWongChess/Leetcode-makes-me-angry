class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> cnt(n + 1);
        for(auto i: citations){
            ++cnt[min(i, n)];
        }
        int sum = 0;
        for(int i = n; i >= 0; --i){
            sum += cnt[i];
            if(sum >= i){
                return i;
            }
        }
        return 0;
    }
};