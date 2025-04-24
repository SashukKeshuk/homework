#include <iostream>
#include <algorithm>
using namespace std;
int ans, dp[6];
struct box {
    int w, l, h;
};
bool cmp(box x, box y) {
    return x.l * x.w < y.l * y.w;
}
int main() {
    box boxes[6] = {
        box{4, 5, 3},
        box{1, 5, 4},
        box{2, 3, 2},
        box{2, 4, 1},
        box{2, 3, 2},
        box{1, 2, 2}
    };
    sort(boxes, boxes + 6, cmp);
    for (int i=0; i<6; i++) dp[i] = boxes[i].h;
    for (int i=0; i<6; i++)
        for (int j=0; j<i; j++) if (boxes[j].w < boxes[i].w && boxes[j].l < boxes[i].l) dp[i] = max(dp[i], dp[j] + boxes[i].h);
    for (int i=0; i<6; i++) ans = max(ans, dp[i]);
    cout << ans;
}
