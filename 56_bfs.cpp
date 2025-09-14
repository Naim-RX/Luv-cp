#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int N = 1e3;
vector<int> g[N];
int vis[N];
int level[N];
void bfs(int source){
    queue<int>q;
    q.push(source);
    vis[source] = 1;

    while(!q.empty()){
        int cur_v = q.front();
        q.pop();
        for(int child : g[cur_v]){
            if(!vis[child]){
                q.push(child);
                vis[child] = 1;
                level[child] = level[cur_v] + 1;
            }
        }
    }
}

int main(){
    int n;cin >> n ;
    for(int i=0;i<n;i++){
        int v1,v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);

    }
    bfs(1);
    for(int i=0;i<=n;i++){
        cout << i << ' ' << level[i] << endl;
    }

}

/*
13
1 2
1 3
1 13
2 5
5 6
5 7
5 8
8 12
3 4
4 9
4 10
10 11
9 10
*/

