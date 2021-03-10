#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000007

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.sync_with_stdio(0);
    int M, N;
    cin >> M >> N;
    int K; cin >> K;
    int r[M+1]; int c[N+1];
    for(int i=1; i<=M; ++i)r[i]=0;
    for(int i=1; i<=N; ++i)c[i]=0;
    for(int i=0; i<K; ++i) {
        char a; int n;
        cin >> a >> n;
        if(a=='R') {
            r[n]++;
        }else {
            c[n]++;
        }
    }
    int ans=0;
    for(int i=1; i<=M; ++i) {
        for(int j=1; j<=N; ++j) {
            if((r[i]+c[j])%2==1) {
                ans++;
            }
        }
    }
    cout << ans;
}
