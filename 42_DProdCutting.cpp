#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int N = 1e5+10;
int dp[1005];

int func(int len,vector<int>&prices){
    if(len == 0) return 0;
    if(dp[len] != -1) return dp[len];
    int ans = 0;
    for(int len_to_cut=1;len_to_cut<=prices.size();len_to_cut++){
        if(len - len_to_cut >=0){
            ans = max(ans,func(len - len_to_cut,prices) + prices[len_to_cut-1]);
        }
    }
    return dp[len] = ans;
}

int cutRod(int price[],int n){
    vector<int>prices(price,price+n);
    return func(n,prices);
}
int main(){
    memset(dp,-1,sizeof(dp));
    int n = 8;
    int price[n] = {1,5,8,9,10,17,17,20};
    cout << cutRod(price,n);
}
