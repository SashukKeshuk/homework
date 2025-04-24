#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[10], a[10] = {7, 3, 2, 9, 6, 7, 4, 9, 1, 3}, ans, p[10], mrk;
vector<int> v;
int main() {
    for (int i=0; i<10; i++) dp[i] = 1, p[i] = i;
    for (int i=0; i<10; i++)
        for (int j=0; j<i; j++) if (a[i] > a[j])
                if (dp[j] + 1 > dp[i]) p[i] = j, dp[i] = dp[j] + 1;
    for (int i=0; i<10; i++) if (ans < dp[i]) mrk = i, ans = dp[i];
    cout << ans << "\n";
    while (p[mrk] != mrk) v.push_back(a[mrk]), mrk = p[mrk];
    v.push_back(a[mrk]);
    reverse(v.begin(), v.end());
    for (int u:v) cout << u << ' ';
}
