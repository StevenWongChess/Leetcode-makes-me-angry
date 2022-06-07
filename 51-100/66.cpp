class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int n = digits.size();
        int carry = 1;
        int i = n - 1;
        while (i >= 0 && carry)
        {
            int sum = digits[i] + carry;
            digits[i] = sum % 10;
            --i;
            carry = sum / 10;
        }
        if (carry)
            digits.emplace(digits.begin(), 1);
        return digits;
    }
};