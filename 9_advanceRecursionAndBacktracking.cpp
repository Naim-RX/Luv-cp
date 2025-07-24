#include <bits/stdc++.h>
using namespace std;

vector<string> valid;

void generates(string &s, int open, int close) {
    if (open == 0 && close == 0) {
        valid.push_back(s);
        return;
    }

    if (open > 0) {
        s.push_back('(');
        generates(s, open - 1, close);
        s.pop_back();
    }

    if (close > open) {
        s.push_back(')');
        generates(s, open, close - 1);
        s.pop_back();
    }
}

int main() {
    int n;
    cin >> n;
    string s;
    generates(s, n, n);
    for (auto u : valid) {
        cout << u << endl;
    }
}
