class Solution {
public:
    string addBinary(string a, string b) {
        if(a.length() > b.length()){
            swap(a, b);
        }
        int m = a.length();
        int n = b.length();
        int carry = 0;
        string ans = string(n, ' ');
        for(int i = 0; i < n; i++){
            int first = m - 1 - i >= 0 ? (int)(a[m - 1 - i] - '0') : 0;
            int sum = carry + (int)(b[n - 1 - i] - '0') + first;
            carry = sum / 2;
            ans[n - 1- i] = (sum % 2 + '0');
        }
        if(carry){
            ans = "1" + ans;
        }
        return ans;
    }
};