class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int len_a = a.length();
        int len_b = b.length();
        string ans = "";
        for(int i = 0; i < max(len_a, len_b); i++){
            int l = i < len_a ? (int)(a[i] - '0') : 0;
            int r = i < len_b ? (int)(b[i] - '0') : 0;
            ans += (char)('0' + (l + r + carry) % 2);
            carry = (l + r + carry) / 2;
        }
        if(carry)
            ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};