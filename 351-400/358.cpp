class Solution {
public:
    string rearrangeString(string s, int k) {
        int n = s.size(); // n is length of s

        vector<int> freqs(26); // freq of each char
        for(auto ch: s)
            ++freqs[ch - 'a'];
        priority_queue<pair<int, char>> pq; // size maybe smaller than 26
        for(int i = 0; i < 26; ++i){
            if(freqs[i] > 0)
                pq.push({freqs[i], 'a' + i});
        }

        int max_freq = pq.top().first;
        string ans(n, ' ');
        if(max_freq == 1 || k <= 1)
            return s;

        int it = 0;
        while(it < n){
            int step = min(k, n - it);
            vector<pair<int, char>> v;
            if(pq.size() < step)
                return "";
            for(int i = 0; i < step; ++i){
                auto [cnt, ch] = pq.top();
                pq.pop();
                v.push_back({cnt - 1, ch});
                ans[it + i] = ch;
            }
            for(auto item: v){
                if(item.first > 0)
                    pq.push(item);
            }
            it += k;
        }
        
        return ans;
    }
};
