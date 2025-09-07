#include<bits/stdc++.h>
using namespace std;
// a <= 10^18 b = 10^9 M = 10^9
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

int binMultiply(int a , int b){

}

int main(){

}
