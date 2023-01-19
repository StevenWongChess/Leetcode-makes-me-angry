class Trie{
public:
    vector<Trie*> v;
    bool isend;
    Trie(){
        v = vector<Trie*>(26, nullptr);
        isend = false;
    }
};

void insert(const string& s, Trie* it){
    for(auto i: s){
        int idx = i - 'a';
        if(!it->v[idx])
            it->v[idx] = new Trie;
        it = it->v[idx];
    }
    it->isend = true;
}

class WordDictionary {
public:
    Trie* root;
    WordDictionary() {
        root = new Trie;
    }
    
    void addWord(string word) {
        insert(word, root);
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }

    bool dfs(const string& word, int ith, Trie* it){
        if(ith == word.size())
            return it->isend;

        auto c = word[ith];
        if(c >= 'a' && c <= 'z'){
            Trie* next = it->v[c - 'a'];
            if(next && dfs(word, ith + 1, next))
                return true;
        }
        else if(c == '.'){
            for(int i = 0; i < 26; ++i){
                Trie *next = it->v[i];
                if(next && dfs(word, ith + 1, next))
                    return true;
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */