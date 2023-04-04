class Solution {
public:
    long getValue(string& num, int l, int r){
        if(l - r > 17)
            return -1;
        long n = 0;
        for(int i = l; i <= r; ++i){
            n = n * 10 + num[i] - '0';
        }
        if(l - r != 0 && num[l] == '0')
            return -1;
        return n;
    };

    bool judge(string& num, long a, long b, int index){
        int n = num.size();
        if(a == -1 || b == -1 || index == n)
            return false;

        while(index < n){
            long c = a + b, tmp = c;
            string s;
            while(tmp){
                s += ('0' + tmp % 10);
                tmp /= 10;
            }
            if(s.size() == 0)
                s = "0";
            // reverse(s.begin(), s.end());
            int m = s.size();
            if(index + m > n)
                return false;
            for(int i = index; i < index + m; ++i){
                if(num[i] != s[index + m - i - 1])
                    return false;
            }
            // prep for next
            index += m;
            a = b;
            b = c;
        }

        return index == n;
    };

    bool isAdditiveNumber(string num) {
        int n = num.size();
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                long a = getValue(num, 0, i), b = getValue(num, i + 1, j);
                auto flag = judge(num, a, b, j + 1);
                if(flag)
                    return true;
            }
        }

        return false;
    }
};