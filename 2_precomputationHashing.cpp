#include <bits/stdc++.h>
using namespace std;

/*const int n = 1e5;
long long fact[n];

int main() {
    ///factorial
    fact[0] = fact[1] = 1;
    for(int i=2;i<n;++i){
        fact[i] = fact[i-1]*i;
    }

    int a,b;
    cin >> a >> b;
    long long c = fact[a] + fact[b];
    cout << c << endl;
}
*/

///given an array a of N integers.Given q queries and in each query given a number x,print count of that number in array
///constrains
/// 1<= N <= 10^5
///1<=a[i]<=10^7
/// 1<=q<=10^5
const int N = 1e7+10;
int hsh[N];

int main (){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
        hsh[a[i]]++;
    }

    int q;
    cin >> q;
    while(q--){
        int x;
        cin >> x;
        cout << hsh[x] << endl;
    }
}
