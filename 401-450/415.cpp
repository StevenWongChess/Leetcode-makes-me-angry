class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0;
        int m = num1.size(), n = num2.size();
        int i = m - 1, j = n - 1;
        
        string ans;
        
        while(i >= 0 || j >= 0 || carry > 0){
            int a = (i < 0) ? 0 : num1[i] - '0';
            int b = (j < 0) ? 0 : num2[j] - '0';
            int sum = a + b + carry;
            ans.push_back('0' + sum % 10);
            carry = sum / 10;
            --i;
            --j;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};