#include <bits/stdc++.h>
using namespace std;

int lowerbound(vector<int>&v,int element){
    int lo=0,hi= v.size()-1;
    int mid;
    while(hi-lo >1){
        int mid = (hi+lo)/2;
        if(v[mid]<element){
            lo = mid+1;
        }
        else {
            hi = mid;
        }
    }
    if(v[lo] >= element){
        return lo;
    }
    if(v[hi] >= element){
        return hi;
    }
    return -1;
}

int upperbound(vector<int>&v,int element){
    int lo=0,hi= v.size()-1;
    int mid;
    while(hi-lo >1){
        int mid = (hi+lo)/2;
        if(v[mid]<=element){
            lo = mid+1;
        }
        else {
            hi = mid;
        }
    }
    if(v[lo] > element){
        return lo;
    }
    if(v[hi] > element){
        return hi;
    }
    return -1;
}

int main(){
    int n,t;cin >> n >> t;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin >> v[i];

        while(t--){
    int element;cin >> element;
    int lb = lowerbound(v,element);
    cout << lb << " " <<  v[lb] << endl;
    }
}
