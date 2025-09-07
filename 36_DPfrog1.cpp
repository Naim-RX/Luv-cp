#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int N = 1e5+10;
///atcoder frog
int h[N];
int h2[N];
int dp[N];
int dp2[N];
int k;

/// frog 1 function
/* input
4
10 30 40 20
output
*/
int frog1(int i){
    if(i==0) return 0;
    if(dp[i] != -1) return dp[i];
    int cost = INT_MAX;
    cost  =min(cost,frog1(i-1) + abs(h[i] - h[i-1]));
    if(i > 1){
        cost  =min(cost,frog1(i-2) + abs(h[i] - h[i-2]));
    }
    return dp[i] = cost;
}
/// frog 2 function
/* input
3 1
10 20 10
output
20
*/
int frog2(int i){
    if(i==0) return 0;
    if(dp2[i] != -1) return dp2[i];
    int cost = INT_MAX;
    for(int j = 1;j <=k;j++){
        if(i - j >=0)
        cost  =min(cost,frog2(i-j) + abs(h2[i] - h2[i-j]));
    }
    return dp2[i] = cost;
}


int main(){
    memset(dp,-1,sizeof(dp));
    memset(dp2,-1,sizeof(dp));
    int n;cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> h[i];
        h2[i] = h[i];
    }
    cout << frog1(n-1);
    cout << endl;
    cout << frog2(n-1);
}






