#include <iostream>
using namespace std;
int dp[8];
int main() {
    bool mrk[8] = {0, 1, 0, 1, 0, 0, 0, 0};
    dp[0] = 1;
    for (int i=0; i<7; i++)
    {
        if (mrk[i]) continue;
        for (int j=1; j<=3; j++) dp[i+j] += dp[i];
    }
    cout << dp[7] << ' ';
    for (int i=1; i<8; i++) dp[i] = 0;
    for (int i=1; i<8; i++)
    {
        if (mrk[i]) continue;
        for (int j=1; j<=3; j++) dp[i] += dp[i-j];
    }
    cout << dp[7];
}
