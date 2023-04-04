class Solution {
public:
    vector<string> v1 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> v2 = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> v3 = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> v4 = {"", " Thousand", " Million", " Billion"};

    string helper(int n){
        if(n == 0)
            return "";
        string s;
        int a = n / 100;
        n %= 100;
        int b = n / 10, c = n % 10;
        if(a > 0){
            s = s + v1[a] + " Hundred" + (n == 0 ? "" : " ");
        }
        if(b == 1)
            s = s + v2[c];
        else if(b > 1){
            if(c > 0)
                s = s + v3[b] + " " + v1[c];
            else   
                s = s + v3[b];
        }
        else
            s = s + v1[c];
        return s;
    }

    string numberToWords(int num) {
        if(num == 0)
            return "Zero";
        string ans;
        bool flag = false;
        for(int i = 0; i < 4; ++i){
            int n = num % 1000;
            auto s = helper(n);
            if(s != ""){
                if(flag)
                    ans = s + v4[i] + " " + ans;
                else
                    ans = s + v4[i] + ans;
                flag = true;
            }
            num /= 1000;
        }
        return ans;
    }
};