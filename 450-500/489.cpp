/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
public:
    vector<pair<int, int>> dirs = {
        {-1, 0}, {0, 1}, {1, 0}, {0, -1}
    };
    set<pair<int, int>> visited;
    void dfs(Robot& robot, int d, int x, int y){
        visited.insert({x, y});
        robot.clean();
        for(int i = 0; i < 4; ++i){
            int newd = (i + d) % 4;
            int newx = x + dirs[newd].first, newy = y + dirs[newd].second;
            if(visited.find({newx, newy}) == visited.end() && robot.move()){
                dfs(robot, newd, newx, newy);
                robot.turnRight();
                robot.turnRight();
                robot.move();
                robot.turnRight();
                robot.turnRight();
            }
            robot.turnRight();
        }
    }

    void cleanRoom(Robot& robot) {
        dfs(robot, 0, 0, 0);
    }
};