#include <bits/stdc++.h>
using namespace std;

///1D array
///given an array a of N integers. Given q queries and in each query print sum of L and r OF elements in array
///constrains
///N<= 10^5
///a[i] <= 10^9
/// L,R<= N;

/*const int N= 1e5+10;
int a[N];
int pf[N];
int main(){
    int n;
    cin >> n;
    for(int i=1;i<n;++i){
        cin >> a[i];
        pf[i] = pf[i-1] + a[i];
    }
    int q;
    cin >> q;
    while(q--){
        int l,r;
        cin >> l >> r;
        cout << pf[r] - pf[l-1] << endl;

    }
}
*/


///Given 2D array a of N*N integers. Given Q queries and in each query given a,b,c and d print sum of square represented by (a,b) as top left
///point and (c,d) as top bottom right
///constrains
///N<= 10^3
///a[i][j]<=10^9
///Q<= 10^5
/// a,b,c,d<= N

const int N = 1e3+10;
int ar[N][N];
long long pf[N][N];
int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cin >> ar[i][j];
            pf[i][j] = ar[i][j]+pf[i-1][j]+pf[i][j-1]-pf[i-1][j-1];
        }
    }
    int q;
    cin >> q;
    while(q--){
        int a,b,c,d;
        cin >>a >> b >> c >> d;
        cout << pf[c][d]-pf[a-1][d]-pf[c][b-1]+pf[a-1][b-1] << endl;
    }
}
