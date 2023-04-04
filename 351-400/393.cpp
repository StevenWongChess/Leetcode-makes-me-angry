class Solution {
public:
    vector<int> int2byte(int n){
        vector<int> v(8, 0);
        for(int i = 0; i < 8; ++i){
            v[7 - i] = n % 2;
            n /= 2;
        }
        return v;
    }

    int count1(const vector<int>& v){
        int i = 0, cnt = 0;
        while(i < 8 && v[i] == 1){
            ++cnt;
            ++i;
        }
        return cnt;
    }

    bool valid(const vector<int>& v){
        if(v[0] == 1 && v[1] == 0)
            return true;
        return false;
    }

    bool validUtf8(vector<int>& data) {
        int n = data.size(), i = 0;
        while(i < n){
            auto v = int2byte(data[i]);
            int cnt = count1(v);
            if(cnt == 1 || cnt > 4)
                return false;
            for(int j = 0; j < cnt - 1; ++j){
                ++i;
                if(i >= n || !valid(int2byte(data[i])))
                    return false;
            }
            ++i;
        }
        return true;
    }
};