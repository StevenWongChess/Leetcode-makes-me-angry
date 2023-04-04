class Solution {
public:
    unordered_map<string, int> dict; // word->id
    vector<vector<int>> edges; // 
    int cnt = 0;

    void addWord(string& word){
        if(dict.count(word))
            return;
        edges.push_back({});
        dict[word] = cnt;
        ++cnt;
    }

    void addEdge(string& word){
        addWord(word);
        auto id1 = dict[word];
        for(auto& ch: word){
            auto tmp = ch;
            ch = '*';
            addWord(word);
            auto id2 = dict[word];
            edges[id1].push_back(id2);
            edges[id2].push_back(id1);
            ch = tmp;
        }
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for(auto& word: wordList)
            addEdge(word);
        addEdge(beginWord);

        if(!dict.count(endWord))
            return 0;
        
        vector<int> distance(cnt, INT_MAX);
        int start = dict[beginWord], end = dict[endWord];
        distance[start] = 0;

        queue<int> q;
        q.push(start);

        while(!q.empty()){
            auto now = q.front();
            q.pop();
            if(now == end)
                return distance[end] / 2 + 1;

            for(auto& next: edges[now]){
                if(distance[next] == INT_MAX){
                    distance[next] = distance[now] + 1;
                    q.push(next);
                }
            }
        }

        return 0;
    }
};