class Solution
{
public:
    unordered_map<char, char> map = {
        {'1', '1'},
        {'6', '9'},
        {'9', '6'},
        {'8', '8'},
        {'0', '0'}};
    bool isStrobogrammatic(string num)
    {
        int n = num.length(), l = 0, r = n - 1;
        while (l <= r)
        {
            if (!map.count(num[l]) || map[num[l]] != num[r])
                return false;
            ++l;
            --r;
        }
        return true;
    }
};