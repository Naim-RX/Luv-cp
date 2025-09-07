#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int N = 1e3;
int graph[N][N];

int main(){
    int n , m;
    cin >> n >> m;
    for(int i = 0;i<m;i++){
        int v1 , v2;
        cin >> v1 >> v2;
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }
}

