class Solution {
public:
    int compareVersion(string version1, string version2) {
        int m = version1.length();
        int n = version2.length();
        int i = 0;
        int j = 0;
        while(i < m || j < n){
            int first = 0; 
            int second = 0;
            while(i < m && version1[i] != '.'){
                first *= 10;
                first += version1[i] - '0';
                i++;
            }
            i++;
            while(j < n && version2[j] != '.'){
                second *= 10;
                second += version2[j] - '0';
                j++;
            }
            j++;
            if(first > second)
                return 1;
            else if(first < second)
                return -1;
        }
        return 0;
    }
};