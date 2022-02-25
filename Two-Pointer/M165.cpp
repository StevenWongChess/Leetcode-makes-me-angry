class Solution {
public:
    int compareVersion(string version1, string version2) {
        int m = version1.length();
        int n = version2.length();
        int i = 0;
        int j = 0;
        while(i < m || j < n){
            int l = 0;
            int r = 0;
            while(i < m && version1[i] != '.'){
                l *= 10;
                l += (version1[i] - '0');
                i++;
            }
            while(j < n && version2[j] != '.'){
                r *= 10;
                r += (version2[j] - '0');
                j++;
            }
            i++;
            j++;
            if(l > r)
                return 1;
            if(l < r)
                return -1;
        }
        return 0;
    }
};