#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e3;
int sz[N], D[N], P[N];
vector<vector<int> > v(N);
void dfs(int x, int p, int d) {
    D[x] = d; P[x] = p;
    if (v[x].size() == 1) return;
    for (int u:v[x]) if (u != p) dfs(u, x, d + 1);
}
int main() {
    int n, x, y;
    cin >> n;
    for (int i=0; i<n-1; i++)
    {
        cin >> x >> y;
        x--; y--;
        v[x].push_back(y); v[y].push_back(x);
    }
    for (int i=0; i<n; i++) sz[i] = 1;
    dfs(0, -1, 0);
    while (1) {
        cin >> x >> y;
        x--; y--;
        if (D[x] > D[y]) swap(x, y);
        while (D[y] > D[x]) y = P[y];
        while (x != y) x = P[x], y = P[y];
        cout << x + 1 << "\n";
    }
}
