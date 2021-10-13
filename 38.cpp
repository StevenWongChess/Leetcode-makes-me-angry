class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for(int i = 1; i < n; i++){
            char prev = '0' - 1;
            int count = 0;
            string next = "";
            for(auto i: ans){
                if(i == prev){
                    count++;
                }
                else{
                    if(count)
                        next += (to_string(count) + prev);
                    prev = i;
                    count = 1;
                }
            }
            if(count)
                next += (to_string(count) + prev);
            ans = next;
        }
        return ans;
    }
};