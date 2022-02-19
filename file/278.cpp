// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        while(left < right){
            int mid = (right - left) / 2 + left;
            if(!isBadVersion(mid))
                left = mid + 1;
            else{
                right = mid;
            }
        }
        return left;
    }
};