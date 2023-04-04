class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string s;
        for(auto& str: strs){
            int n = str.size();
            string num(3, ' ');
            for(int i = 0; i < 3; ++i){
                num[2 - i] = '0' + n % 10;
                n /= 10;
            }
            s = s + num + str;
        }
        return s;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        int n = s.size(), i = 0;
        vector<string> strs;
        while(i < n){
            string l = s.substr(i, 3);
            int length = stoi(l);
            i += 3;
            string str = s.substr(i, length);          
            strs.push_back(str);
            i += length;
        }
        return strs;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));