#include <bits/stdc++.h>
using namespace std;

int len;
int coins[32];
int solve(int x) {
    if(x<0)return INFINITY;
    if(x==0)return 0;
    int best=INFINITY;
    for(int i=0; i<len; ++i) {
        best=min(best, solve(x-coins[i])+1);
    }
    return best;
}

int main() {
    int x;
    cin >> x;
    cin >> len;
    for(int i=0; i<len; ++i) {
        cin >> coins[i];
    }
    sort(coins, coins+len);
    cout << solve(x);
}
