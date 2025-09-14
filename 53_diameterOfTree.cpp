#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int N = 1e5;
vector<int> g[N];
int depth[N];
void dfs(int v,int par = -1){
    /// take action on vertex after entering the vertex
    //if(vis[vertex]) return;
    for(int child : g[v]){
        if(child == par) continue;
        depth[child] = depth[v] + 1;
        ///take action on the child before entering the child node
        dfs(child,v);
        ///take action on child before entering the child node
    }
}

int main(){
    int n;cin >> n;
    for(int i=0;i<n;i++){
        int v1,v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);

    }
    dfs(1);
    int mx_depth = -1;
    int mx_d_node;
    for(int i=1;i<=n;i++){
        if(mx_depth < depth[i]){
            mx_depth = depth[i];
            mx_d_node = i;
        }
        depth[i] = 0;
    }
    dfs(mx_d_node);
    mx_depth = -1;
    for(int i=1;i<=n;i++){
        if(mx_depth < depth[i]){
            mx_depth = depth[i];
        }
    }
    cout << mx_depth << endl;
}

/*
13
1 2
1 3
1 13
2 5
3 4
5 6
5 7
5 8
8 12
4 9
4 10
10 11
*/


