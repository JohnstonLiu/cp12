#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000007
struct rectangle {
    int x1, x2, y1, y2;
    int area;
    rectangle(int a1, int a2, int b1, int b2) {
        x1=a1; x2=a2; y1=b1; y2=b2;
        area=(y2-y1)*(x2-x1);
    }
    rectangle(){}
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.sync_with_stdio(0);
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    rectangle board[3];
    for(int i=0; i<3; ++i) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        board[i]=rectangle(x1, x2, y1, y2);
    }
    int ans=board[0].area+board[1].area;
    rectangle b0=board[0];
    rectangle b1=board[1];
    rectangle b2=board[2];

    ans-=max(0, min(b0.x2, b2.x2)-max(b0.x1, b2.x1))*(max(0, min(b0.y2, b2.y2)-max(b0.y1, b2.y1)));
    ans-=max(0, min(b1.x2, b2.x2)-max(b1.x1, b2.x1))*(max(0, min(b1.y2, b2.y2)-max(b1.y1, b2.y1)));
    cout << ans;
}
