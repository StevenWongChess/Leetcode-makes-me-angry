class Solution {
public:
    int lengthLongestPath(string input) {
        int n = input.size();
        int i = 0, depth = 0, len = 0, ans = 0, prefix = 0;
        vector<int> v;
        bool isfile = false;
        while(i < n){
            if(input[i] == '\n'){

                cout << "prefix: " << prefix << " len: " << len << endl;
                for(auto k: v){
                    cout << k << ", ";
                }
                cout << endl;

                if(isfile){
                    ans = max(ans, prefix + len + static_cast<int>(v.size()));
                }

                isfile = false;
                depth = 0; 

                while(i + 1 < n && input[i + 1] == '\t'){
                    ++depth;
                    ++i;
                }

                // deal with length
                v.push_back(len);
                while(v.size() > depth){
                    prefix -= v.back();
                    v.pop_back();
                }

                prefix += len;
                len = 0;
            }
            else if(input[i] == '.'){
                isfile = true;
                ++len;
            }
            else{
                // normal char
                ++len;
            }
            ++i;
        }
        
        if(isfile){
            ans = max(ans, prefix + len + static_cast<int>(v.size()));
        }

        return ans;
    }
};