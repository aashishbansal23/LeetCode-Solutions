class MyHashSet {
public:
    /** Initialize your data structure here. */
    bool store[1000001] = {false};
    MyHashSet() {
        
    }
    
    void add(int key) {
        store[key] = true;
    }
    
    void remove(int key) {
        store[key] = false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        if(store[key]){
            return true;
        }else{
            return false;
        }
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */