#include<bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int bfs(vector<vector<int>>&adj,int n, int k){
        int cnt = 0;
        queue<pair<int,int>>q;
        
        q.push({1,0});
        
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            int node = x.first;
            int steps = x.second;
            if(steps == k){

                if(node == n){
                    cnt = (cnt + 1)%mod;
                }
                continue;
            }
            for(int x2 : adj[node]){                 
                    q.push({x2,steps+1});
            }
        }
    return cnt;
}
int main(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    cout << bfs(adj,n,k) << endl;
    
}
