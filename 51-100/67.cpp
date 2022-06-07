class Solution
{
public:
    string addBinary(string a, string b)
    {
        if (a.length() < b.length())
            swap(a, b);
        int n = a.length();
        int m = b.length();

        string ans(n, ' ');
        int carry = 0;
        for (int i = 0; i < n; ++i)
        {
            int x = (a[n - 1 - i] - '0');
            int y = (m - 1 - i >= 0) ? b[m - 1 - i] - '0' : 0;
            int sum = x + y + carry;
            ans[n - 1 - i] = '0' + sum % 2;
            carry = sum / 2;
        }
        if (carry)
            ans = "1" + ans;
        return ans;
    }
};