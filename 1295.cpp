class Solution {
public:
    int digits(int i){
        int d = 0;
        while(i){
            d++;
            i /= 10;
        }
        return d;
    }
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for(auto i: nums){
            count += 1 - (digits(i) % 2);
        }
        return count;
    }
};