#include <bits/stdc++.h>
using namespace std;


void print(int num){
    for(int i=10;i >= 0 ;--i){
        cout << ((num >> i) & 1);
    }
    cout << endl;
}
int main(){
    int a = 9;
    int i = 3;
    print(9);
    cout << "If set a bit : ";
    print(a | (1 << 1));
    cout << "If unset a bit: ";
    print( a & (~(1 << 3)));
    cout << "toggle the bit: ";
    print( a ^ (1 << 2));
    if((a & ( 1<< i)) != 0){
        cout << "set bit" << endl;
    }
    else cout << " not Set bit" << endl;
    int cnt = 0;
    for(int i= 31 ; i>=0;--i){
        if((a & ( 1<< i)) != 0){
        cnt++;
        }
    }
    cout << "set bit: " << cnt << endl;
    cout << __builtin_popcount(a) << endl;

    cout << INT_MAX << endl;
    int c = (1LL<<31) - 1;
    cout << c << endl;
    unsigned int b = (1LL<<32) - 1;
    cout << b << endl;

    // find unique number
    int ax= 3,bx=3,cx=2;
    cout << (ax^bx^cx) << endl;
}
