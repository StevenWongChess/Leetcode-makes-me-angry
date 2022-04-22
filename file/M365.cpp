class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        int a = jug1Capacity;
        int b = jug2Capacity;
        int c = targetCapacity;
        
        if(a + b < c)
            return false;
        return c % gcd(a, b) == 0;
            
    }
};