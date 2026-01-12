#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<vector<int>>&arr,vector<int>&vis){
    vis[node] = 1;
    for(int x:arr[node]){
       if(!vis[x]){
         dfs(x,arr,vis);
       }
    }
}

int main(){

    int n,m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    vector<int>vis(n+1,0);
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int>ans;
    for(int i = 1; i<=n; i++){
        if(!vis[i]){
            ans.push_back(i);
            dfs(i,adj,vis);
        }
    }
    
    cout << ans.size()-1 << endl;
    for(int i = 0; i+1 < (int)ans.size(); i++){
        cout << ans[i] << " " << ans[i+1] << endl;
    }

    return 0;
}