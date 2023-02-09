class Solution {
public:
    // int f(){}
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int n = rectangles.size();
        long area = 0;
        map<pair<int, int>, int> dict;
        int x1 = rectangles[0][0], y1 = rectangles[0][1], x2 = rectangles[0][2], y2 = rectangles[0][3];
        // from (x1, y1) to (x2, y2)
        for(auto i: rectangles){
            // from (a, b) to (c, d)
            int a = i[0], b = i[1], c = i[2], d = i[3];
            x1 = min(x1, a), y1 = min(y1, b), x2 = max(x2, c), y2 = max(y2, d);
            area += static_cast<long>(c - a) * (d - b);
            ++dict[{a, b}];
            ++dict[{a, d}];
            ++dict[{c, d}];
            ++dict[{c, b}];
        }

        if(area != static_cast<long>(x2 - x1) * (y2 - y1))
            return false;
        if(!dict.count({x1, y1}) || !dict.count({x1, y2}) || !dict.count({x2, y1}) || !dict.count({x2, y2}))
            return false;
        for(auto [i, cnt]: dict){
            auto x = i.first, y = i.second;
            if((x == x1 || x == x2) && (y == y1 || y == y2)){
                continue;
            } 
            else{
                if(cnt != 2 && cnt != 4)
                    return false;
            }
        }

        return true;
    }
};