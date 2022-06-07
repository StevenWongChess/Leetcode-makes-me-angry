class Solution
{
public:
    bool isRobotBounded(string instructions)
    {
        int n = instructions.size();
        int x = 0, y = 0;
        int direction = 0;
        for (auto i : instructions)
        {
            if (i == 'G')
            {
                if (direction == 0)
                {
                    ++y;
                }
                else if (direction == 1)
                {
                    ++x;
                }
                else if (direction == 2)
                {
                    --y;
                }
                else
                {
                    --x;
                }
            }
            else if (i == 'R')
            {
                direction = (direction + 1) % 4;
            }
            else
            {
                --direction;
                if (direction == -1)
                {
                    direction = 3;
                }
            }
        }

        return direction != 0 || (x == 0 && y == 0);
    }
};