#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000007

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.sync_with_stdio(0);
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    int a, b, c ,d;
    cin >> a >> b >> c >> d;
    cout << min(max(d, b)-min(a, c), (d-c)+(b-a));
}
