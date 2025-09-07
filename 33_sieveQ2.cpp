#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int N = 1e6+10;
int a[N];
int hp[N];
int canremove[N];
int hsh[N];

vector<int>distinct(int x){
    vector<int>ans;
    while(x > 1){
        int pf = hp[x];
        while(x % pf == 0) x /= pf;
        ans.push_back(pf);
    }
    return ans;
}

int main(){
    for(int i=2;i<N;i++){
        if(hp[i]==0){
            for(int j=i;j<N;j+=i){
                hp[j] = i;
            }
        }
    }
    int n,q; cin >> n >> q;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        hsh[x] = 1;
    }
    for(int i=2;i<N;i++){
        if(hsh[i]){
            for(ll j = i; j< N ; j *= i){
                canremove[j] = 1;
            }
        }
    }
    while(q--){
        int x; cin >> x;
        vector<int> pf = distinct(x);
        bool ispossible = false;
        for(int i=0;i<pf.size();i++){
            for(int j = i;j<pf.size();j++){
                int product = pf[i] * pf[j];
                if(i==j && x % product != 0) continue;
                int toremove = x /product;
                if(canremove[toremove]==1 || toremove == 1) {
                    ispossible = true;
                    break;
                }
            }
            if(ispossible) break;
        }
        cout << (ispossible? "YES\n" : "NO\n");
    }
}

/*input
4 3
2 22 7 10
16
429
42

output
yes
no
yes
*/














