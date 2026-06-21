class node{
    public:
    node* next;
    node* pre;
    int key;
    int value;
    node(int k, int val){
        next = NULL;
        pre = NULL;
        key = k;
        value = val;
    }
};

class LRUCache {
    unordered_map<int, node*> mp;
    int capacity;
    int count;
    node* head;
    node* tail;
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        count = 0;
        head = new node(0, 0);
        tail = new node(0, 0);
        head->next = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        if(mp.count(key) > 0){
            node* temp = mp[key];
            temp->pre->next = temp->next;
            temp->next->pre = temp->pre;
            temp->next = head->next;
            temp->pre = head;
            temp->next->pre = temp;
            head->next = temp;
            return mp[key]->value;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(mp.count(key) > 0){
            mp[key]->value = value;
            node* temp = mp[key];
            temp->pre->next = temp->next;
            temp->next->pre = temp->pre;
            temp->next = head->next;
            temp->pre = head;
            temp->next->pre = temp;
            head->next = temp;
        }else{
            if(count == capacity){
                mp.erase(tail->pre->key);
                count--;
                node* temp = tail->pre;
                tail->pre = temp->pre;
                temp->pre->next = tail;
                temp->next = NULL;
                temp->pre = NULL;
                delete temp;
            }
            node* temp = new node(key, value);
            temp->next = head->next;
            temp->pre = head;
            head->next->pre = temp;
            head->next = temp;
            mp[key] = temp;
            count++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */