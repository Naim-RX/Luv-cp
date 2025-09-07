#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int N = 1e5+10;
int wt[105],val[105];
ll dp[105][100005];


ll func(int idx,int value_left){
    if(value_left==0) return 0;
    if(idx < 0) return 1e15;
    if(dp[idx][value_left] != -1) return dp[idx][value_left];
    ll ans = func(idx-1,value_left);
    if(value_left-val[idx] >= 0)
        ans = min(ans,func(idx-1,value_left - val[idx]) + wt[idx]);
    return dp[idx][value_left] = ans;
}
int main(){
    memset(dp,-1,sizeof(dp));
    int n,w;
    cin >> n >> w;
    for(int i=0;i<n;i++){
        cin >> wt[i] >> val[i];
    }
    int max_value = 1e5;
    for(int i=max_value;i>=0;--i){
        if(func(n-1,i) <= w){
            cout << i << endl;
            break;
        }
    }
}
/*input
3 8
3 30
4 50
5 60
output
90
*/
