#include <bits/stdc++.h>
using namespace std;

/// constrain n <=10
///print module M where M=47

///10^9+7 = very close of int range

int main(){
    int n;
    cin >> n;
    int M = 47;
    long long fact = 1;
    for (int i=2;i<=n ;++i){
        fact = (fact * i)%M;
    }
    cout << fact;
}

///(a+b)%M = ((a%M)+(b%M))%M
///(a*b)%M = ((a%M)*(b%M))%M
///(a-b)%M = ((a%M)-(b%M)+M)%M
///(a/b)%M = ((a%M) * (b^-1)%M)%M
