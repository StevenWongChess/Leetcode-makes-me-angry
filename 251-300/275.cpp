class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size(), l = 0, r = n - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(n - mid <= citations[mid]){
                r = mid - 1;
            }
            else{
                l = mid + 1;   
            }
        }
        return n - l;
    }
};