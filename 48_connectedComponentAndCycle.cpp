#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int N = 1e3;
vector<int>g[N];
bool vis[N];
///storing connectd components
vector<vector<int>>cc;
vector<int>current_cc;

void dfs(int vertex){
    /// take action on vertex after entering the vertex
    //if(vis[vertex]) return;
    vis[vertex] = true;
    current_cc.push_back(vertex);
    for(int child : g[vertex]){
        if(vis[child]) continue;
        ///take action on the child before entering the child node
        dfs(child);
        ///take action on child before entering the child node
    }
    /*take action on vertex before exiting the vertex*/
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
        current_cc.clear();
        dfs(i);
        cc.push_back(current_cc);
        ct++;
    }
    cout << "Connected components: " <<ct << endl;
    for(auto c_cc: cc){
        for(int vertex : c_cc){
            cout << vertex << ' ';
        }
        cout << endl;
    }
}

/*
8 5
1 2
2 3
2 4
3 5
6 7
*/


