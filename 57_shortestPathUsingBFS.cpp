#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
const int INF = 1e9+10;

int vis[8][8];
int lev[8][8];

int getx(string s) {
    return s[0] - 'a';
}
int gety(string s) {
    return s[1] - '1';
}

bool isValid(int x, int y) {
    return x >= 0 && y >= 0 && x < 8 && y < 8;
}

vector<pair<int,int>> movements = {
    {-1,2}, {1,2},
    {-1,-2}, {1,-2},
    {2,-1}, {2,1},
    {-2,-1}, {-2,1}
};

int bfs(string source, string dest) {
    int sourcex = getx(source);
    int sourcey = gety(source);
    int destx = getx(dest);
    int desty = gety(dest);

    queue<pair<int,int>> q;
    q.push({sourcex, sourcey});
    vis[sourcex][sourcey] = 1;
    lev[sourcex][sourcey] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (auto [dx, dy] : movements) {
            int nx = x + dx;
            int ny = y + dy;
            if (isValid(nx, ny) && !vis[nx][ny]) {
                q.push({nx, ny});
                vis[nx][ny] = 1;
                lev[nx][ny] = lev[x][y] + 1;
            }
        }
    }

    return lev[destx][desty];
}

void reset() {
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++) {
            vis[i][j] = 0;
            lev[i][j] = INF;
        }
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        reset();
        string s1, s2;
        cin >> s1 >> s2;
        cout << bfs(s1, s2) << endl;
    }
}
