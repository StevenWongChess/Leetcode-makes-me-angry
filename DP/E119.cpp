class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0){
            return {1};
        }
        vector<int> line = {1, 1};
        for(int i = 2; i <= rowIndex; i++){
            for(int j = i - 1; j > 0; j--){
                line[j] += line[j - 1];
            }
            line[0] = 1;
            line.push_back(1);
        }
        return line;
    }
};