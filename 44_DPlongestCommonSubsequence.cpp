#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int N = 1e5+10;
int dp[1005][1005];

int lcs(int i,int j,string &s1,string &s2){
    if(i<0 || j < 0) return 0;
    if(dp[i][j]!= -1) return dp[i][j];
    int ans = lcs(i-1,j,s1,s2);
    ans = max(ans,lcs(i,j-1,s1,s2));
    ans = max(ans,lcs(i-1,j-1,s1,s2) + (s1[i] == s2[j]));
    return dp[i][j] = ans;
}

int longestcommonsub(string text1,string text2){
    return lcs(text1.size()-1,text2.size()-1, text1,text2);
}
int main(){
    memset(dp,-1,sizeof(dp));
    string s1 = "abcde";
    string s2 = "abfg";
    cout << longestcommonsub(s1,s2);
}

//way 2
/*
int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[m][n];
    }
*/


