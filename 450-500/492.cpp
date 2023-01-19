class Solution {
public:
    vector<int> constructRectangle(int area) {
        int n = sqrt(area);
        for(int i = n; i > 0; --i){
            if(area % i == 0){
                return {area / i, i};
            }
        }
        return {-1, -1};
    }
};