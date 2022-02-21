class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for(int i = 0; i < n;){
            int sum = 0;
            int j; 
            for(j = 0; j < n; j++){
                int now = (i + j) % n;
                sum += gas[now] - cost[now];
                if(sum < 0){
                    i += j + 1;
                    break;
                }
            }
            if(j == n)
                return i;
        }
        return -1;
    }
};