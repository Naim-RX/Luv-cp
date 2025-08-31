#include <bits/stdc++.h>
using namespace std;

double ep = 1e-6;

int main(){
    double x;cin >> x;
    double lo = 1,hi = x,mid;
    while(hi-lo>ep){
        mid = (hi+lo)/2;
        if(mid* mid <x){
            lo = mid;
        }
        else {
            hi = mid;
        }
    }
    cout << lo << endl;
}
