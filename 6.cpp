class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }
        string ans = "";
        int n = s.length();
        for(int j = 0; j < n; j += (2 * numRows - 2))
            ans += s[j];
        for(int i = 1; i < numRows - 1; i++){
            for(int j = 0; i + j * (2 * numRows - 2) < n; j++){
                // if(i + j * (2 * numRows - 1) < n)
                    ans += s[i + j * (2 * numRows - 2)];
                if((j + 1) * (2 * numRows - 2) - i < n)
                    ans += s[(j + 1) * (2 * numRows - 2) - i];
            }
        }
        for(int j = numRows - 1; j < n; j += (2 * numRows - 2))
            ans += s[j];
        return ans;
    }
};