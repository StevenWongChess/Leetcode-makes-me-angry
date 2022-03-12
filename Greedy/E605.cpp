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


class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();
        if(flowerbed[m - 1] == 0){
            flowerbed.push_back(0); flowerbed.push_back(1);
        }
        if(flowerbed[0] == 0){
            flowerbed.emplace(flowerbed.begin(), 0);
            flowerbed.emplace(flowerbed.begin(), 1);
        }
        int count = 0;
        int ans = 0;
        for(auto i: flowerbed){
            if(i == 0)
                count++;
            else{
                ans += (count - 1) / 2;
                count = 0;
            }
        }
        ans += (count + 1) / 2;
        return ans >= n;
    }
};