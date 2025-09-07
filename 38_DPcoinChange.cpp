#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int N = 1e5+10;
/// leetcode coin change
int func(int amount , vector<int>&coins,vector<int> &dp){
    if(amount == 0) return 0;
    if(dp[amount] != -1) return dp[amount];
    int ans = INT_MAX;
    for(int coin:coins){
        if(amount - coin >= 0)
            ans = min(ans + 0LL,func(amount-coin,coins,dp) + 1LL);
    }
    return dp[amount] = ans;
}
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, -1);
    int ans = func(amount,coins,dp);
    return ans==INT_MAX? -1 : ans;
}

int main(){
    vector<int> coins = {1,2,5};
    cout << coinChange(coins , 11);
}

///way 2
/*
const int INF = 1e9+10;
int main() {
int n,  amount ;
    cin >> n>> amount;
    vector<int> B(n);
    for (int i = 0; i < n; ++i)  cin >> B[i];
     vector<int> dp(amount + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i - B[j] >= 0) {
                dp[i] = min(dp[i], dp[i - B[j]] + 1);
            } } }
    int C = dp[amount];
    cout << C << endl;
return 0;  }
*/




