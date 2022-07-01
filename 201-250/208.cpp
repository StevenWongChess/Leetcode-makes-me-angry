class Trie
{
public:
    vector<Trie *> link;
    bool isEnd;

    Trie()
    {
        link = vector<Trie *>(26);
        isEnd = false;
    }

    void insert(string word)
    {
        Trie *it = this;
        for (auto i : word)
        {
            int index = i - 'a';
            if (!it->link[index])
                it->link[index] = new Trie;
            it = it->link[index];
        }
        it->isEnd = true;
    }

    bool search(string word)
    {
        Trie *it = this;
        for (auto i : word)
        {
            int index = i - 'a';
            it = it->link[index];
            if (!it)
                return false;
        }
        return it->isEnd;
    }

    bool startsWith(string prefix)
    {
        Trie *it = this;
        for (auto i : prefix)
        {
            int index = i - 'a';
            it = it->link[index];
            if (!it)
                return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */