class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for(int i = digits.size() - 1; i >= 0; i--){
            int sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;
        }
        if(carry == 1)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        bool flag = true;
        for(int i = 0; i < n; i++){
            if(digits[i] != 9)
                flag = false;
        }
        if(flag){
             vector<int> ans(n + 1, 0);
             ans[0] = 1;
             return ans;
        }
        vector<int> ans(n, 0);
        int carry = 1;
        for(int i = n - 1; i >= 0; i--){
            ans[i] = carry + digits[i];
            carry = ans[i] / 10;
            ans[i] %= 10;
        }
        return ans;
    }
};