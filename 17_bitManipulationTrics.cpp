#include <bits/stdc++.h>
using namespace std;

void print(int num){
    for(int i=10;i >= 0 ;--i){
        cout << ((num >> i) & 1);
    }
    cout << endl;
}

int main(){
    if(7&1){
        cout << "odd" << endl;
    }
    int n = 5;
    cout << "5/2: " <<  (n >> 1)  << endl;
    cout << "5*2: " <<  (n << 1) << endl;

    cout<< "uppercase to lower case: ";
    char A = 'B';
    char a = A | (1 << 5);
    cout << a << endl;
    cout << char(('C' | ' ')) << endl;
    cout<< "lowercase to upper case: ";
    char A1 = 'a';
    char a1 = (A1 & (~(1 << 5)));
    cout << a1 << endl;
    cout << char('c' & '_') << endl;

    cout << "Clear LSB : " << endl;
    print(59);
    int b = 59;
    int i  =5;
    int b1 = (b & ((1<<(i+1) - 1)));
    print(b1);
    cout << "Clear MSB : " << endl;
    int i1 = 5;
    int b2 = (b & (~(1<<(i1+1) - 1)));
    print(b2);

    cout << "Check pow of 2 : " << endl;
    int x = 16;
    if(x & (x-1)){
        cout << "not power of 2" << endl;
    }
    else cout << "power of 2";

}
