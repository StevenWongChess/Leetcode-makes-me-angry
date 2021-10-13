class Solution {
public:
    string intToRoman(int num) {
        string ans;
        while(num >= 1000){
            ans += "M";
            num -= 1000;
        }
        while(num >= 100){
            if(num / 100 == 9){
                ans += "CM";
                num -= 900;
            }
            else if(num >= 500){
                ans += "D";
                num -= 500;
            }
            else if(num / 100 == 4){
                ans += "CD";
                num -= 400;
            }
            else{
                ans += "C";
                num -= 100;
            }
        }
        while(num >= 10){
            if(num / 10 == 9){
                ans += "XC";
                num -= 90;
            }
            else if(num >= 50){
                ans += "L";
                num -= 50;
            }
            else if(num / 10 == 4){
                ans += "XL";
                num -= 40;
            }
            else{
                ans += "X";
                num -= 10;
            }
        }
        while(num > 0){
            if(num == 9){
                ans += "IX";
                num = 0;
            }
            else if(num >= 5){
                ans += "V";
                num -= 5;
            }
            else if(num == 4){
                ans += "IV";
                num = 0;
            }
            else{
                ans += "I";
                num --;
            }
        }
        return ans;
    }
};