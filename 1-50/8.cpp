class Solution
{
public:
    int myAtoi(string s)
    {
        int flag = 1;

        int it = 0;
        while (s[it] == ' ')
        {
            ++it;
        }

        if (s[it] == '+')
        {
            ++it;
        }
        else if (s[it] == '-')
        {
            ++it;
            flag = -1;
        }

        int number = 0;
        while (s[it] <= '9' && s[it] >= '0')
        {
            if (flag == 1 && ((number == INT_MAX / 10 && s[it] - '0' >= 7) || number > INT_MAX / 10))
                return INT_MAX;
            if (flag == -1 && ((number == INT_MAX / 10 && s[it] - '0' >= 8) || number > INT_MAX / 10))
                return INT_MIN;

            number *= 10;
            number += s[it] - '0';
            ++it;
        }

        return number * flag;
    }
};