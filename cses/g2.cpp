#include<bits/stdc++.h>
using namespace std;

int dr[4] = {0,1,0,-1};

int dc[4] = {1,0,-1,0};

void dfs(vector<vector<char>>&arr,int r,int c,int n, int m){
    

    arr[r][c] = '#';
    for(int i = 0; i < 4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr < n && nr >= 0 && nc < m && nc >= 0 && arr[nr][nc] == '.'){
            dfs(arr,nr,nc,n,m);
        }
    }
}

int main(){

    int n, m;
    cin >> n >> m;
    vector<vector<char>>grd(n,vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char temp;
            cin >> temp;
            grd[i][j] = temp;
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grd[i][j] == '.'){
                cnt++;
                dfs(grd,i,j,n,m);
            }
        }
    }
    cout << cnt << endl;
}