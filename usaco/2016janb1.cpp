#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000007

int main() {
    //freopen("promote.in", "r", stdin);
    //freopen("promote.out", "w", stdout);
    int bb, ab, bs, as, bg, ag, bp, ap;
    cin >> bb >> ab >> bs >> as >> bg >> ag >> bp >> ap;
    int goldplat=ap-bp;
    int silvergold=(ap+ag)-(bp+bg);
    int bronzesilver=(ap+ag+as)-(bp+bg+bs);
    cout << bronzesilver << "\n" << silvergold << "\n" << goldplat;
}
