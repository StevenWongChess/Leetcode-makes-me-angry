class Node{
public:
    int key, value;
    Node *prev, *next;
    Node(): key(0), value(0), prev(nullptr), next(nullptr){}
};

class LRUCache {
public:
    unordered_map<int, Node*> dict;
    Node *head, *tail;
    int size, capacity;

    LRUCache(int capacity): capacity(capacity), size(0), head(new Node()), tail(new Node()){
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(dict.count(key)){
            auto node = dict[key];
            move_to_head(node);
            return node->value;
        }
        else
            return -1;
    }
    
    void put(int key, int value) {
        if(dict.count(key)){
            auto node = dict[key];
            node->value = value;
            move_to_head(node);
        }
        else{
            ++size;
            auto node = new Node();
            node->value = value, node->key = key;
            dict[key] = node;

            head->next->prev = node;
            node->next = head->next;
            node->prev = head;
            head->next = node;

            if(size > capacity){
                auto r_node = tail->prev;
                tail->prev = tail->prev->prev;
                tail->prev->next = tail;
                --size;
                dict.erase(r_node->key);
            }
        }
        // print();
    }

    void print(){
        auto it = head;
        while(it){
            cout << it->key << "+" << it->value << "  ";
            it = it->next;
        }
        cout << endl;
    }

    void move_to_head(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;

        head->next->prev = node;
        node->next = head->next;
        node->prev = head;
        head->next = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */