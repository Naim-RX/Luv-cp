#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int M = 1e9+7;
const int N = 1e5+10;
int fac[N];
///hackerearth unlock the door

int binary(int a,int b,int M){
    int ans = 1;
    while(b){
        if(b&1){
            ans = (ans * 1ll * a) % M;
        }
        a = (a * 1ll * a) %M;
        b >>=1;
    }
    return ans;
}

///alphabet ->k sylbols ,N size password , k > N
/// kCn = N! * kCn



int main(){
    int t;cin >> t;
    fac[0] = 1;
    for(int  i = 1;i<N;i++){
        fac[i] = (fac[i-1] * 1LL * i) % M;
    }
    while(t--){
        int n,k; cin >> n >> k;
        int ans = fac[n];
        ans = (ans * 1LL * fac[k]) % M;
        int den = (fac[k-n] * 1LL *(fac[n])) % M;
        ans = (ans * 1LL * binary(den,M-2,M))%M;
        cout << ans << endl;
    }
}

/*
1
3 3
*/













