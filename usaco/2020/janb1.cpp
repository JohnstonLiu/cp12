#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000007

int main() {
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);
    int N, K;
    cin >> N >> K;
    string sentence[N];
    for(int i=0; i<N; ++i) {
        cin >> sentence[i];
    }
    int len=0;
    bool fresh=true;
    for(int i=0; i<N; ++i) {
        len+=sentence[i].length();
        if(len>K) {
            cout << "\n";
            len=sentence[i].length();
            fresh=true;
        }
        if(fresh) {
            cout << sentence[i];
            fresh=false;
        }else {
            cout << " " << sentence[i];
        }
    }
}