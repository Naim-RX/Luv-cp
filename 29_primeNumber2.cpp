#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const int N = 1e5 + 1;
vector<bool> prime(N, true);
vector<int>lp(N,0);
vector<int>hp(N,0);
vector<int>divisors[N];
///heighest and lowest prime
void sieve() {
    prime[0] = prime[1] = false;
    for (int i = 2; i * i < N; ++i) {
        if (prime[i]) {
                lp[i] = hp[i] = i;
            for (int j = i * i; j < N; j += i) {
                prime[j] = false;
                hp[j] = i;
                if(lp[j]==0){
                    lp[j] = i;
                }
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sieve();

    /// prime factorization using sieve
    int num;
    cin >> num;
    vector<int>prime_factors;
    map<int,int>count_prime;
    while(num > 1){
        int prime_factor = hp[num];
        while(num % prime_factor==0){
            num /= prime_factor;
            prime_factors.push_back(prime_factor);
            count_prime[prime_factor]++; /// counts the number of factors
        }
    }
    for(int factor : prime_factors){
        cout << factor << ' ';
    }
    cout << endl;
    for(auto factor : count_prime){
        cout << factor.first << ' ' << factor.second << endl;
    }

    /// divisors
    for(int i=2;i<N;i++){
        for(int j=i;j<N;j+=i){
            divisors[j].push_back(i);
        }
    }

    for(int i=1;i<10;++i){
        for(int div : divisors[i]){
            cout << div << ' ';
        }
        cout << endl;
    }
    return 0;


}
