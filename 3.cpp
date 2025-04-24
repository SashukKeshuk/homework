#include <iostream>
using namespace std;
int dp[4][7];
int main() {
    for (int i=0; i<4; i++) dp[i][0] = 1;
    for (int i=0; i<7; i++) dp[0][i] = 1;
    for (int i=1; i<4; i++)
        for (int j=1; j<7; j++) dp[i][j] = dp[i-1][j] + dp[i][j-1];
    cout << dp[3][6];
}
