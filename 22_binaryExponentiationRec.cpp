#include<bits/stdc++.h>
using namespace std;
const int M = 1e9+7;

int binary(int a,int b){
    if(b==0) return 1;
    int res = binary(a,b/2);
    if(b&1){
        return (a*((res*1ll * res) % M)) %M;
    }
    else return (res * 1ll * res) %M;
}

int main(){
    int a=2,b=13;
    cout << binary(a,b);
}
