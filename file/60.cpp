class Solution {
public:
    int fact(int t){
        int m = 1;
        for(int i = 2; i <= t; i++){
            m *= i;
        }
        return m;
    }
    string getPermutation(int n, int k) {
        string ans;
        vector<int> chosen(n, 0);
        vector<int> rem;
        k--;
        for(int i = n - 1; i >= 1; i--){
            int div = fact(i);
            rem.push_back(k / div);
            k = k % div;
        }
        rem.push_back(0);       
        for(int i = 0; i < n; i++){
            int count = 0;
            for(int j = 0; j < n; j++){
                if(chosen[j] == 0){
                    count++;
                }
                if(count == rem[i] + 1){
                    ans += (char)('1' + j);
                    chosen[j] = 1;
                    break;
                }
            }
        }
        return ans;
    }
};