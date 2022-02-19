class Trie{
public:
    vector<Trie*> list;
    bool isEnd;
    Trie(){
        list = vector<Trie*>(26);
        isEnd = false;
    }
    void insert(string& word){
        Trie* it = this;
        for(auto i: word){
            int index = i - 'a';
            if(!it->list[index])
                it->list[index] = new Trie;
            it = it->list[index];
        }
        it->isEnd = true;
    }
};
class WordDictionary {
public:
    Trie* head;
    WordDictionary() {
        head = new Trie;
    }
    void addWord(string word) {
        head->insert(word);
    }
    bool search(string word) {
        return dfs(0, head, word);
    }
    bool dfs(int i, Trie* it, string& word){
        if(i >= word.length())
            return it->isEnd;
        if(word[i] == '.'){
            for(int j = 0; j < 26; j++){
                if(it->list[j] && dfs(i + 1, it->list[j], word))
                    return true;
            }
        }
        else{
            return it->list[word[i] - 'a'] && dfs(i + 1, it->list[word[i] - 'a'], word);
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