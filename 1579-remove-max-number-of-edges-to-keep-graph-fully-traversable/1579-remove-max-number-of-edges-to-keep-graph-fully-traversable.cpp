class DSU{
    int* parent;
    int* rank;
    int n;
public:
    DSU(int n){
        parent = new int[n+1];
        rank = new int[n+1];
        this->n = n;
        for(int i=0; i<n+1; i++){
            parent[i] = -1;
            rank[i] = 1;
        }
    }
    
    int find(int x){
        if(parent[x] == -1){
            return x;
        }
        return parent[x]=find(parent[x]);
    }
    
    bool union_set(int x, int y){
        int s1 = find(x);
        int s2 = find(y);
        if(s1 != s2){
            if(rank[s1] > rank[s2]){
                parent[s2] = s1;
                rank[s1] += s2;
            }else{
                parent[s1] = s2;
                rank[s2] += s1;
            }
            n--;
            return true;
        }
        return false;
    }
    
    bool checkConnected(){
        return n==1;
    }
};

bool compator(vector<int>& v1, vector<int>& v2){
    return v1[0]>v2[0];
}

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end(), compator);
        DSU alice(n), bob(n);
        int count = 0;
        for(int i=0; i<edges.size(); i++){
            int type = edges[i][0];
            int from = edges[i][1];
            int to = edges[i][2];
            if(type == 3){
                count += (alice.union_set(from, to) | bob.union_set(from, to));
            }else if(type == 2){
                count += bob.union_set(from, to);
            }else if(type == 1){
                count += alice.union_set(from, to);
            }
        }
        if(alice.checkConnected() && bob.checkConnected()){
            return edges.size()-count;
        }else{
            return -1;
        }
    }
};