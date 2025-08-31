#include <bits/stdc++.h>
using namespace std;

int n;
long long m;
const int N = 1e6+10;
long long tress [N];

bool iswood(int h){
    long long wood = 0;
    for(int i=0;i<n;i++){
        if(tress[i] >= h){
            wood += (tress[i]-h);
        }
    }
    return wood >= m;
}
int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> tress[i];
    }
    long long lo = 0 , hi = 1e9, mid;
    while(hi-lo>1){
        mid = (hi+lo)/2;
        if(iswood(mid)){
            lo = mid;
        }
        else{
            hi = mid - 1;
        }
    }
    if(iswood(hi)){
        cout << hi << endl;
    }
    else cout << lo << endl;
}
