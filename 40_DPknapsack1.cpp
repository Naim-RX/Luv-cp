#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int N = 1e5+10;
int wt[105],val[105];
ll dp[105][100005];

///atcoder knapsack 1
ll func(int idx,int wt_left){
    if(wt_left == 0) return 0;
    if(idx <0) return 0;
    if(dp[idx][wt_left] != -1) return dp[idx][wt_left];
    ll ans = func(idx-1,wt_left);
    if(wt_left - wt[idx] >= 0)
        ans = max(ans,func(idx-1,wt_left - wt[idx])+val[idx]);
    return dp[idx][wt_left] = ans;
}
int main(){
    memset(dp,-1,sizeof(dp));
    int n,w;
    cin >> n >> w;
    for(int i=0;i<n;i++){
        cin >> wt[i] >> val[i];
    }
    cout << func(n-1,w);
}
/*input
3 8
3 30
4 50
5 60
output
90
*/

/// way 2
/*
#include<bits/stdc++.h>
using namespace std;
long long n,s,w[100004],v[100004],f[105][100004];
int main ()
{
    cin>>n>>s;
    for(int i =1 ;i<=n;i++) cin>>w[i]>>v[i];
    for(int i =1 ;i<=n;i++)
    {
        for(int j =0;j<=s;j++){
            if(j>=w[i]) f[i][j]=max(f[i-1][j],f[i-1][j-w[i]]+v[i]);
            else f[i][j]=f[i-1][j];
        }
    }
    cout<<f[n][s];
}
*/
