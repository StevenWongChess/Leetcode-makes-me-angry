class SnakeGame {
public:
    vector<vector<int>> food;
    set<pair<int, int>> body;
    queue<pair<int, int>> order;
    int x, y, m, n, ith;
    unordered_map<string, pair<int, int>> dir = {
        {"U", {-1, 0}}, {"D", {1, 0}}, {"L", {0, -1}}, {"R", {0, 1}}
    };

    SnakeGame(int width, int height, vector<vector<int>>& food) {
        this->food = food;
        m = height, n = width, x = y = ith = 0;
        body.insert({0, 0});
        order.push({0, 0});
    }
    
    int move(string direction) {
        auto [dx, dy] = dir[direction];
        x += dx, y += dy;
        if(x < 0 || x >= m || y < 0 || y >= n){
            return -1;
        }
        // meet food
        if(ith < food.size() && x == food[ith][0] && y == food[ith][1]){
            body.insert({x, y});
            order.push({x, y});
            ++ith;
            return ith;
        }
        auto [tmpx, tmpy] = order.front();
        order.pop();
        body.erase({tmpx, tmpy});
        // crash itself
        if(body.count({x, y}) > 0){
            return -1;
        }
        order.push({x, y});
        body.insert({x, y});
        return ith;
        // rest
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */