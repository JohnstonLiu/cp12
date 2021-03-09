#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000007
struct board {
    int x1, x2, y1, y2, area;
    board(int a1, int a2, int b1, int b2) {
        x1=a1; x2=a2;
        y1=b1; y2=b2;
        area=(x2-x1)*(y2-y1);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.sync_with_stdio(0);
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    int a, b, c, d, e, f, g, h;
    cin >> a >> b >> c >> d >> e >> f >> g >> h;
    board bad=board(a+1000, c+1000, b+1000, d+1000);
    board good=board(e+1000, g+1000, f+1000, h+1000);
    int ans=bad.area;
    if(good.y1<=bad.y1 && good.y2>=bad.y2 && !(good.x2<bad.x2 && good.x1>bad.x1)) {
        ans-=max(0, (min(bad.x2, good.x2)-max(bad.x1, good.x1)))*(bad.y2-bad.y1);
    }else if(good.x1<=bad.x1 && good.x2>=bad.x2 && !(good.y2<bad.y2 && good.y1>bad.y1)) {
        ans-=max(0, (min(bad.y2, good.y2)-max(bad.y1, good.y1)))*(bad.x2-bad.x1);
    }
    cout << ans << "\n";
}