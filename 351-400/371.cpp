class Solution
{
public:
    int getSum(int a, int b)
    {
        while (b)
        {
            unsigned int carry = static_cast<unsigned int>(a & b) << 1;
            a = a ^ b;
            b = carry;
        }

        return a;
    }
};