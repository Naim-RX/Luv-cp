#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int N = 1e5+10;
int subtree_sum[N];
int even_cnt[N];
vector<int>g[N];


bool dfs(int vertex ,int par){
    /// take action on vertex after entering the vertex
    //if(vis[vertex]) return;
    subtree_sum[vertex] += vertex;
    if(vertex%2==0) even_cnt[vertex]++;
    for(int child : g[vertex]){
        ///take action on the child before entering the child node
        if(child == par) continue;
        dfs(child,vertex);
        ///take action on child after entering the child node
        subtree_sum[vertex] += subtree_sum[child];
        even_cnt[vertex] += even_cnt[child];
    }
    /*take action on vertex before exiting the vertex*/
}

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n-1;i++){
        int x,y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++){
        cout << subtree_sum[i] << ' ' << even_cnt[i] << endl;
    }
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




