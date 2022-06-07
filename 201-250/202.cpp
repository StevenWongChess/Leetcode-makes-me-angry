class Solution
{
public:
    int happy(int n)
    {
        int sum = 0;
        while (n)
        {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n)
    {
        int slow = n;
        int fast = happy(n);

        while (slow != fast && slow != 1)
        {
            slow = happy(slow);
            fast = happy(happy(fast));
        }

        return slow == 1;
    }
};