class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0;
        int y = 0;
        int dir = 0;
        for(auto i: instructions){
            if(i == 'L')
                dir = (dir == 0) ? 3 : (dir - 1) % 4;
            else if(i == 'R')
                dir = (dir + 1) % 4;
            else{
                if(dir == 0)
                    y++;
                else if(dir == 1)
                    x++;
                else if(dir == 2)
                    y--;
                else
                    x--;
            }
            // cout << x << " " << y << " " << dir <<endl;
        }
        return (x == 0 && y == 0) || dir != 0;
    }
};