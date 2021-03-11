#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000007

int main() {
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    int ans=0;
    int ans1=0;
    ans+=abs(x-a);
    ans+=abs(b-y);
    ans1+=abs(y-a);
    ans1+=abs(b-x);
    cout << min(ans, min(ans1, abs(b-a)));
}
