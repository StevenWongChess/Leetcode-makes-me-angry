class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int start = 0;
        while(start < n){
            int sum = 0;
            int i = 0;
            for(; i < n; i ++){
                int index = (i + start) % n;
                sum += gas[index] - cost[index];
                if(sum < 0){
                    start += i + 1;
                    break;
                } 
            }
            if(i == n)
                return start;
        }
        return -1;
    }
};