class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> dict{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int ans = 0;
        int prev = 1000;
        for(auto i: s){
            int tmp = dict[i];
            if(prev >= tmp){
                ans += tmp;
            }
            else{
                ans += (tmp - 2 * prev);
            }
            prev = tmp;
        }
        return ans;
    }
};