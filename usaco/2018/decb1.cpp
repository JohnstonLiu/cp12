#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
#define INF 1000000007

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.sync_with_stdio(0);
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);
    int terminate=0;
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    pi ar[4];
    ar[1]={a, b};
    ar[2]={c, d};
    ar[3]={e, f};
    pi swaps[3]={{1,2}, {2,3}, {3,1}};
    for(int i=0; i<3; ++i, ++terminate) {
        if(terminate==100) {
            cout << ar[1].second << "\n" << ar[2].second << "\n" << ar[3].second << "\n";
            return 0;
        }
        int x=swaps[i].first; int y=swaps[i].second;
        int temp=ar[y].second;
        ar[y].second+=min(ar[x].second, ar[y].first-ar[y].second);
        ar[x].second-=min(ar[x].second, ar[y].first-temp);
        if(i==2) {
            i=-1;
        }
    }
}