#include<bits/stdc++.h>
using namespace std;
const int M = 1e9+7;

int binary(int a,int b){
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

int main(){
    int a=2,b=13;
    cout << binary(a,b);
}

