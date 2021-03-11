#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
#define INF 1000000007

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.sync_with_stdio(0);
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    int N, M; cin >> N >> M;
    int road[110];
    int bessie[110];
    int temp=1;
    for(int i=0; i<N; ++i) {
        int a, b; cin >> a >> b;
        for(int j=temp; j<=temp+a; ++j) {
            road[j]=b;
        }
        temp+=a;
    }
    temp=1;
    for(int i=0; i<M; ++i) {
        int a, b; cin >> a >> b;
        for(int j=temp; j<=temp+a; ++j) {
            bessie[j]=b;
        }
        temp+=a;
    }
    int ans=0;
    for(int i=1; i<=100; ++i) {
        ans=max(ans, bessie[i]-road[i]);
    }
    cout << ans << "\n";
}