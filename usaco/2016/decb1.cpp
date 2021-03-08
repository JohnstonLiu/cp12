#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000007

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.sync_with_stdio(0);
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);
    int a, b, c, d, e, f, g, h;
    cin >> a >> b >> c >> d >> e >> f >> g >> h;
    int len=(max(h, d)-min(b, f));
    int wid=(max(g, c)-min(a, e));
    cout << max(len, wid)*max(len, wid);
}
