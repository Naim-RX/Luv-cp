#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int N = 1e5+10;
int a[N];
int dp[N];

int lis(int i){
    if(dp[i] != -1) return dp[i];
    int ans = 1;
    for(int j=0;j<i;++j){
        if(a[i] > a[j]){
            ans = max(ans,lis(j) + 1);
        }
    }
    return dp[i] = ans;
}


int main(){
    memset(dp,-1,sizeof(dp));
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans = max(ans,lis(i));
    }
    cout << ans;
}

//binary search way
/*
int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    vector<int>temp;
    temp.push_back(arr[0]);
    for(int i=1;i<n;i++){
        if(arr[i] > temp.back()){
            temp.push_back(arr[i]);
        }
        else {
            int ind = lower_bound(temp.begin(),temp.end(),arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }
    }
    cout << temp.size() << endl;
*/