class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> s(10,0);
        vector<int> g(10,0);
        int a = 0; int b = 0;
        for(int i = 0; i < secret.length(); i++){
            if(secret[i] == guess[i]){
                a++;
            }
            else{
                s[secret[i] - '0']++;
                g[guess[i]- '0']++;
            }
        }
        for(int i = 0; i < 10; i++){
            b += min(s[i], g[i]);
        }
        return to_string(a) + "A" + to_string(b) + "B";
    }
};

class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.length();
        unordered_map<char, int> dict1;
        unordered_map<char, int> dict2;
        int A = 0;
        int B = 0;
        for(int i = 0; i < n; i++){
            if(secret[i] == guess[i])
                A++;
            else{
                dict1[secret[i]]++;
                dict2[guess[i]]++;
            }
        }
        for(auto [x, y]: dict1){
            if(dict2.find(x) != dict2.end()){
                B += min(dict2[x], y);
            }
        }
        return to_string(A) + "A" + to_string(B) + "B";
    }
};