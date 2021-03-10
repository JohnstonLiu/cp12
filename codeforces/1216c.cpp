#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000007
struct rec {
    ll x1, x2, y1, y2;
    ll area;
    rec(ll a1, ll b1, ll a2, ll b2) {
        x1=a1; y1=b1;
        x2=a2; y2=b2;
        area=(y2-y1)*(x2-x1);
    }
    rec(){
        area=0;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.sync_with_stdio(0);
    ll a, b, c, d, e, f, g, h, i, j, k, l;
    cin >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j >> k >> l;
    rec w=rec(a, b, c, d);
    rec b1=rec(e, f, g, h);
    rec b2=rec(i, j, k, l);
    rec b1nw, b2nw;
    ll temp=max((ll)0, min(b1.y2, w.y2)-max(b1.y1, w.y1))*max((ll)0, min(b1.x2, w.x2)-max(b1.x1, w.x1));
    if(temp!=0) {
        b1nw=rec(max(b1.x1, w.x1), max(b1.y1, w.y1), min(b1.x2, w.x2), min(b1.y2, w.y2));
    }
    temp =max((ll)0, min(b2.y2, w.y2)-max(b2.y1, w.y1))*max((ll)0, min(b2.x2, w.x2)-max(b2.x1, w.x1));
    if(temp!=0) {
        b2nw=rec(max(b2.x1, w.x1), max(b2.y1, w.y1), min(b2.x2, w.x2), min(b2.y2, w.y2));
    }
    ll black;
    if(b1nw.area!=0 && b2nw.area!=0) {
        black=b1nw.area+b2nw.area;
        black-=max((ll)0, min(b1nw.y2, b2nw.y2)-max(b1nw.y1, b2nw.y1))*max((ll)0, min(b1nw.x2, b2nw.x2)-max(b1nw.x1, b2nw.x1));
    }else if(b1nw.area!=0) {
        black=b1nw.area;
    }else if(b2nw.area!=0) {
        black=b2nw.area;
    }else {
        black=0;
    }

    if(black<w.area) {
        cout << "YES\n";
    }else {
        cout << "NO\n";
    }
}
