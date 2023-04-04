/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    char str[4];
    int a = 0, ith = 0;
    int read(char *buf, int n) {
        int cnt = 0;
        while(cnt < n){
            if(a == 0){
                a = read4(str);
                if(a == 0)
                    break;
                ith = 0;
            }
            else{
                *buf++ = str[ith++];
                // ++ith;
                // ++buf;
                ++cnt;
                --a;
            }
        }
        return cnt;
    }
};