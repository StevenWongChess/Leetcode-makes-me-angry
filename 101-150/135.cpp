class Solution {
public:
   int candy(vector<int>& ratings) {
        int n = (int)ratings.size();
        int ret = 1; // 初始值为1
        // inc记录最近的递增序列的长度 dec记录递减序列长度 pre前一个同学分得的糖果
        int inc = 1, dec = 0, pre = 1; 
        for (int i = 1; i < n; i++) {
            if (ratings[i] >= ratings[i - 1]) { // 处于非递减序列中
                dec = 0; // 递减序列长度清零
                // 评分相同 重置 pre 为 1 否则为之前同学分配的糖果 + 1
                pre = ratings[i] == ratings[i - 1] ? 1 : pre + 1;
                ret += pre; // 每次递增序列的长度即为要发的糖果数量
                inc = pre; // 更新递增序列长度
            }
            else { // 处于递减序列中
                dec++; // 递减序列长度++
                // 如果某个时刻递减序列长度和递增序列长度一样 需要把之前递增序列的最后一个元素归入递减序列里
                if (dec == inc) dec++; 
                ret += dec; // 每次递减序列的长度即为要发的糖果数量
                pre = 1; // pre必须重置为1 这样下一个评分如果和当前构成升序才会取得最小结果
            }
        }
        return ret;
    }
};