#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000007

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.sync_with_stdio(0);
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);
    int x, y; cin >> x >> y;
    int distance=0;
    int move=1;
    int pos=x;
    if(y>x) {
        while(pos<y) {
            distance+=abs((x+move)-pos);
            pos=x+move;
            move*=-2;
        }
    }else {
        while(pos>y) {
            distance+=abs((x+move)-pos);
            pos=x+move;
            move*=-2;
        }
    }


    cout << distance-abs(pos-y) << "\n";
}
