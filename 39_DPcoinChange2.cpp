#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int N = 1e5+10;
/// leetcode coin change 2
int dp[310][10010];
/*int func(int amount , vector<int>&coins){
    if(amount == 0) return 1;
    if(dp[amount] != -1) return dp[amount];
    int ways = INT_MAX;
    for(int coin: coins){
        if(amount - coin >= 0)
        ways += func(amount - coin,coins);
    }
    return dp[amount] = ans;
}*/

int func1(int idx,int amount , vector<int>&coins){
    if(amount == 0) return 1;
    if(idx < 0) return 0;
    if(dp[idx][amount] != -1) return dp[idx][amount];
    int ways = 0;
    for(int coin_amount = 0; coin_amount <= amount ; coin_amount+= coins[idx]){
        ways += func1(idx-1,amount - coin_amount,coins);
    }
    return dp[idx][amount] = ways;
}

int coinChange(vector<int>&coins , int amount){
    int ans = func1(coins.size()-1,amount , coins);
    return ans;
}

int main(){
    memset(dp,-1,sizeof(dp));
    vector<int> coins = {1,2,5};
    cout << coinChange(coins , 5);
}



/// way 2
/*
int change(int amount, vector<int>& coins) {
        vector<unsigned int>dp(amount+1,0);
        dp[0]=1;
        for(auto coin:coins){
            for(int j=coin;j<=amount;j++){
                dp[j]+=dp[j-coin];
            }
        }
        return dp[amount];
    }
*/




