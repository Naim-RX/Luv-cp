#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int N = 1e3;
const int M = 1e9+7;
vector<int> g[N];
int subtre_sum[N];
int val[N];

void dfs(int vertex,int par){
    /// take action on vertex after entering the vertex
    //if(vis[vertex]) return;
    subtre_sum[vertex] += val[vertex];
    for(int child : g[vertex]){
        if(child == par) continue;
        ///take action on the child before entering the child node
        dfs(child,vertex);
        subtre_sum[vertex] += subtre_sum[child];
        ///take action on child before entering the child node
    }
}

int main(){
    int n;cin >> n;
    for(int i=0;i<m;i++){
        int v1,v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);

    }
    dfs(1,0);
    ll ans = 0;
    for(int i=2;i<=n;++i){
        int part1 = subtre_sum[i];
        int part2 = subtre_sum[1] - part1;
        ans = max(ans , (part1 * 1LL * part2) % M);
    }
    cout << ans << endl;
}

/*
6 9
1 3
1 5
3 5
3 4
3 6
3 2
2 6
4 6
5 6
*/


