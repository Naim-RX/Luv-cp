#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int M = 1e9+7;
///(a/b)%m = (a*b^-1)%m = ((a%m)*(b^-1)%m)%m
///if(a*b)%m =1 then b is modular multiplicative inverse
/// if a and m are coprime then we can find modular multiplicative inverse
/// coprime is gcd of a,m = 1
///optimization: fermat theorem
///a^M-1 == 1 (mod M) (M is prime and a is not multiple of m)
/// (a^ M-2) = a^-1 (mod M)
/// (a^M-2)%M = a^-1

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

///there are N children and K toffees K<N
///count the number of ways to distribute toffee amond N students such that each student get 1 toffee
///ANS : nCk
///nCr = n! / (n-r)! * r!

const int N = 1e6+10;
int fac[N];
int main(){
    int a=2;
    cout << binary(a,M-2,M);

    cout << "Number of ways" << endl;
    fac[0] = 1;
    for(int i=1;i<N;i++){
        fac[i] = (fac[i-1] * 1LL * i) % M;
    }
    int n = 3,r = 9;
    int ans = fac[n];
    int den = (fac[n-r] * 1LL * fac[r]) % M;
    ans = (ans * 1LL *  binary(den,M-2,M))%M;
    cout << ans << endl;

}



















