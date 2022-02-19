class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        int prev = 0;
        int count = 0;
        for(int i = 0; i < size; i++){
            if(flowerbed[i] || prev || (i != size - 1 && flowerbed[i + 1])){
                prev = flowerbed[i];
            }
            else{
                prev = 1;
                count++;
            }
        }
        return count >= n;
    }
};