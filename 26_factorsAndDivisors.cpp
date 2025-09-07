#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int cnt=0,sum =0;
    for(int i=1;i*i <= n;i++){
        if(n%i==0){
            cnt++;
            sum+= i;
            if(n/i!=i){
                sum += n/i;
                cnt++;
            }
        }
    }
    cout << cnt << ' ' << sum ;


    /* Divisors

    ll n;cin >> n ;
    set<ll>s;
    vector<ll>v;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            s.insert(i);
            ll y = n/i;
            s.insert(y);
        }
    }
    v.assign(s.begin(),s.end());

        */
}
