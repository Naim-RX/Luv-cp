#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const int N = 1e7 + 1;
vector<bool> prime(N, true);

void sieve() {
    prime[0] = prime[1] = false;
    for (int i = 2; i * i < N; ++i) {
        if (prime[i]) {
            for (int j = i * i; j < N; j += i) {
                prime[j] = false;
            }
        }
    }
}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sieve();
    return 0;


}

