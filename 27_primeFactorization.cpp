#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int>primefac;
    for(int i=2;i<=n;i++){
        while(n % i==0){
            primefac.push_back(i);
            n/=i;
        }
    }
    if(n>1) primefac.push_back(n);
    for(auto i:primefac) cout << i << ' ';
}
