#include <bits/stdc++.h>
using namespace std;

// you have to find the gcd of the array after excluding the part from range L to R.
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,q;
        cin >> n >> q;
        int a[n+10];
        int forward1[n+10];
        int backward[n+10];
        forward1[0] = backward[n+1] = 0;
        for(int i=1;i<=n;i++){
            cin >> a[i];
        }
        // forward prefix sum
        for(int i=1;i<=n;i++){
            forward1[i] = __gcd(forward1[i-1],a[i]);
        }
        //backward prefix sum
        for(int i=n;i>=1;i--){
            backward[i] = __gcd(backward[i+1],a[i]);
        }
        while(q--){
            int l,r;
            cin >> l >> r ;
            cout << __gcd(forward1[l-1],backward[r+1]) << endl;
        }
    }
}
