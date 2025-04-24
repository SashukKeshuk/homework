#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e3;
int sz[N];
vector<vector<int> > v(N);
void dfs(int x, int p) {
    sz[x] = 1;
    if (v[x].size() == 1 && p != -1) return;
    for (int u:v[x]) if (u != p) {dfs(u, x); sz[x] += sz[u];}
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
    dfs(0, -1);
    for (int i=0; i<n; i++) cout << "Subtree: " << i + 1 << " Size: " << sz[i] << "\n";
}
