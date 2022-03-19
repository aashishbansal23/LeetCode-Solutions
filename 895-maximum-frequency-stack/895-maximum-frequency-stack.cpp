class FreqStack {
public:
    int i = 0;
    priority_queue<pair<pair<int, int>, int>> q;
    unordered_map<int, int> m;
    
    FreqStack() {
        
    }
    
    void push(int val) {
        i++;
        m[val]++;
        q.push({{m[val], i}, val});
    }
    
    int pop() {
        int x = q.top().second;
        q.pop();
        m[x]--;
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */



/*
// Gives TLE
class FreqStack {
public:
    vector<int> s;
    int maxx = INT_MIN;
    unordered_map<int, int> mp;
    FreqStack() {
        vector<int> s;
        int maxx = INT_MIN;
        unordered_map<int, int> mp;
    }
    
    void push(int val) {
        s.push_back(val);
        if(mp.count(val) > 0){
            mp[val]++;
        }else{
            mp[val] = 1;
        }
        maxx = max(maxx, mp[val]);
    }
    
    int pop() {
        int len = s.size();
        int ans;
        for(int i=len-1; i>=0; i--){
            if(mp[s[i]] == maxx){
                ans = s[i];
                mp[s[i]]--;
                for(int j=i; j<len-1; j++){
                    s[j] = s[j+1];
                }
                s.pop_back();
                break;
            }
        }
        maxx = INT_MIN;
        for(int i=len-2; i>=0; i--){
            maxx = max(maxx, mp[s[i]]);
        }
        return ans;
    }
};
*/