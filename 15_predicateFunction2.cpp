#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n,cows;
int positions[N];

bool canplace(int mindis){
    int last = -1;
    int cows_cnt = cows;
    for(int i=0;i<n;i++){
        if(positions[i]-last >= mindis || last == -1){
            cows_cnt--;
            last = positions[i];
        }
        if(cows_cnt ==0) break;
    }
    return cows_cnt == 0 ;
}

int main(){
    int t;cin >> t;
    while(t--){
        cin >> n >> cows;
        for(int i=0;i<n;i++){
            cin >> positions[i];
        }
        sort(positions,positions+n);
        int lo=0,hi=1e9,mid;
        while(hi-lo>1){
            int mid = (lo+hi)/2;
            if(canplace(mid)){
                lo = mid;
            }
            else {
                hi = mid - 1;
            }
        }
        if(canplace(hi)){
            cout << hi << endl;
        }
        else cout << lo << endl;
    }
}
