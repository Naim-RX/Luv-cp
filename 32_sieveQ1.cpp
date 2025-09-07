#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int M = 1e9+7;
const int N = 2e5+10;
int hsn[N];
int multiple[N];
///hackerearth = monk and divisor conundrum

int main(){
    int n;cin >> n;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        hsn[x]++;
    }
    for(int i=1;i<N;i++){
        for(int j = i;j<N;j+=i){
            multiple[i] += hsn[j];
        }
    }
    int q;cin >> q;
    while(q--){
        int p ,q;cin >> p >> q;
        ll lcm = p * 1LL *  q / __gcd(p,q);
        ll ans = multiple[p] + multiple[q];
        if(lcm < N){
            ans -= multiple[lcm];
        }
        cout << ans << endl;
    }
}

/*
6
2 3 5 7 4 9
2
4 5
3 7
*/
/* output
2 3
*/
