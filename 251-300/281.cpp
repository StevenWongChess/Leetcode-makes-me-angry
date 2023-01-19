class ZigzagIterator {
public:
    vector<int>& vec1, vec2;
    int i = -1, j = -1, m, n;
    ZigzagIterator(vector<int>& v1, vector<int>& v2): vec1(v1), vec2(v2){
        m = v1.size();
        n = v2.size();
    }

    int next() {
        if(i != m - 1 && (i == j || j == n - 1)){
            ++i;
            return vec1[i];
        }
        else{
            ++j;
            return vec2[j];
        }
    }

    bool hasNext() {
        return i + j < m + n - 2;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */