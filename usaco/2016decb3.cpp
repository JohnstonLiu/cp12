#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000007

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.sync_with_stdio(0);
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);
    int M, N, K;
    cin >> M >> N >> K;
    for(int i=0; i<M; ++i) {
        string s;
        cin >> s;
        for(int x=0; x<K; ++x) {
            for(int j=0; j<N; ++j) {
                for(int k=0; k<K; ++k) {
                    cout << s[j];
                }
            }
            cout << "\n";
        }
    }
}
