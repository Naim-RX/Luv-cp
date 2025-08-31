#include<bits/stdc++.h>
using namespace std;

///find a number which appears 1 time in the array and other element appears two times
void oddCount(int n){
    vector<int>v = {1 , 2 , 3, 1, 2};
    int ans = 0;
    for(int i=0;i<n;i++){
        ans ^= v[i];
    }
    cout << ans << endl;
}

int main(){
    int a =4,b = 7;
    a = a^b;
    b = b^a;
    a = a^b;
    cout << a << ' ' << b << endl;
    int c = 9 , d = 5;
    c = c + d;
    d = c - d;
    c = c - d;
    cout << c << ' ' << d << endl;

    int n = 5;
    oddCount(5);
}
