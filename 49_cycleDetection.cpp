#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int N = 1e3;
vector<int>g[N];
bool vis[N];

bool dfs(int vertex ,int par){
    /// take action on vertex after entering the vertex
    //if(vis[vertex]) return;
    vis[vertex] = true;
    bool isLoopExists = false;
    for(int child : g[vertex]){
        if(vis[child] && child == par) continue;
        if(vis[child]) return true;
        ///take action on the child before entering the child node
        isLoopExists |= dfs(child,vertex);
        ///take action on child before entering the child node
    }
    /*take action on vertex before exiting the vertex*/
    return isLoopExists;
}

int main(){
    int n,e;
    cin >> n >> e;
    for(int i=0;i<e;i++){
    int x,y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
    }
    int ct = 0;
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        if(dfs(i,0)){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}

/*
8 6
1 2
2 3
2 4
3 5
6 7
1 5
*/


