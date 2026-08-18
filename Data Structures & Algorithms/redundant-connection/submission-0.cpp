class Solution {
public:
    
    vector<int> parent;
    vector<int> size;

    int find(int x){
        if(x == parent[x])return x;

        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b){
        a = find(a);
        b = find(b);

        if(a == b)return true;

        if(size[b]>size[a])swap(b,a);

        size[a] += size[b];
        parent[b] = a;
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for(int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        int f = 0;
        int s = 0;

        for(int i = 0; i <edges.size(); i++){
            int n1 = edges[i][0];
            int n2 = edges[i][1];
            if(unite(n1,n2)){
                f = n1;
                s = n2;
            }
        }
        return{f,s};
    }
};
