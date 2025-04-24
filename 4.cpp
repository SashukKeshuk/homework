#include <iostream>
using namespace std;
int dp[10], a[10] = {7, 3, 2, 9, 6, 7, 4, 9, 1, 3}, ans;
int main() {
    for (int i=0; i<10; i++) dp[i] = 1;
    for (int i=0; i<10; i++)
        for (int j=0; j<i; j++) if (a[i] > a[j]) dp[i] = max(dp[i], dp[j] + 1);
    for (int i=0; i<10; i++) ans = max(ans, dp[i]);
    cout << ans;
}
