#include <bits/stdc++.h>
using namespace std;
const int N = 1e7+10;
long long int ar[N];

///starting a 1 index array of zeroes and a list of operations for each operation add a value to each the array element between two given indices.

int main(){
    int n,m;
    cin >> n >> m;
    while(m--){
        int a , b , d;
        cin >> a >> b >> d ;
        ar[a] += d;
        ar[b+1] -=d;
    }
    for(int i=1;i<=n;i++){
        ar[i] += ar[i-1];
    }
    long long mx = -1;
    for(int i=1;i<=n;i++){
        if(mx<ar[i]){
            mx = ar[i];
        }
    }
    cout << mx << endl;
}
