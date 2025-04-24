#include <iostream>
using namespace std;
const int N = 1e3;
int C1, dp[N];
int fib(int n) {
    C1++;
    if (n == 0 || n == 1) return n;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n;
    cin >> n;
    cout << fib(n) << ' ';
    cout << C1 << '\n';
    dp[0] = dp[1] = 1;
    for (int i=2; i<n; i++) dp[i] = dp[i-1] + dp[i-2];
    cout << dp[n-1] << ' ' << n;
}
