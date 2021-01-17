#include <bits/stdc++.h>
#define INF 1000000007
using namespace std;

int len;
int coins[33];
int value[5281];
int solve(int n) {
    value[0]=0;
    for(int x=1; x<=n; ++x) {
        value[x]=INF;
        for(int i=0; i<len; ++i) {
            if(x-coins[i]>=0) {
                value[x]=min(value[x], value[x-coins[i]]+1);
            }
        }
    }
    return value[n];
}

int main() {
    int x;
    cin >> x;
    cin >> len;
    for(int i=0; i<len; ++i) {
        cin >> coins[i];
    }
    int ans=solve(x);
    if(ans!=INF) {
        cout << "Roberta wins in " << solve(x) << " strokes.";
    }else {
        cout << "Roberta acknowledges defeat.";
    }
}
