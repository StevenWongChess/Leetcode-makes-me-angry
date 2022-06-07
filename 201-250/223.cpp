class Solution
{
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
    {
        int a = min(ax2, bx2) - max(ax1, bx1);
        int b = min(ay2, by2) - max(ay1, by1);
        int sum = (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1);
        return (a > 0 && b > 0) ? sum - a * b : sum;
    }
};