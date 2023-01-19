class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int sum = 0;
        int last = -1;
        
        for(auto t: timeSeries){
            if(last < t){
                sum += duration;
            }
            else{
                sum += duration - (last - t + 1);
            }
            last = t + duration - 1;
        }
        
        return sum;
    }
};