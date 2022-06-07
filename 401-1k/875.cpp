class Solution
{
public:
    int count(vector<int> &piles, int speed)
    {
        int sum = 0;
        for (auto i : piles)
        {
            sum += i % speed == 0 ? i / speed : i / speed + 1;
        }
        return sum;
    }

    int minEatingSpeed(vector<int> &piles, int h)
    {
        int n = piles.size();

        int l = 1, r = *max_element(piles.begin(), piles.end());

        while (l < r)
        {
            int mid = (l + r) / 2;
            int cnt = count(piles, mid);
            if (cnt <= h)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }

        return l;
    }
};