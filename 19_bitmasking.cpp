#include<bits/stdc++.h>
using namespace std;

/*
    input
    5
    4
    1 4 7 9
    6
    2 9 1 7 25 29
    7
    1 23 4 7 9 11 29
    10
    2 28 8 7 9 10 30 21 18 19
    4
    1 11 29 7
*/


int main(){
    int n;cin >> n;
    vector<int>mask(n,0);
    for(int i=0;i<n;i++){
        int num;
        cin >> num;
        int m = 0;
        for(int j = 0; j < num ;++j){
            int day ;
            cin >> day;
            m = (m | (1<<day));
        }
        mask[i] = m;
    }
    int mx = 0;
    int p1 = -1;
    int p2 = -1;
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;++j){
            int in = (mask[i] & mask[j]);
            int common = __builtin_popcount(in);
            if(common > mx){
                p1 = i;
                p2 = j;
            }
            mx = max(mx,common);
        }
    }
    cout << p1 << ' ' << p2 << endl;
    cout << mx << endl;
}
