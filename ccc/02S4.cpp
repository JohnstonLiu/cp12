#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define INF 1000000009
#define PB push_back
#define MP make_pair

int main() {
    int M, Q;
    cin >> M >> Q;
    int a[Q+1];
    string names[Q+1];
    for(int i=1; i<=Q; ++i) {
        int n; string str;
        cin >> str >> n;
        a[i]=n;
        names[i]=str;
    }
    //int groups=Q/M+(Q%M!=0);
    int best[Q+1];
    best[0]=0;
    for(int i=1; i<=Q; ++i)best[i]=INF;
    int m=-INF;

    for(int i=1; i<=Q; ++i) {
        for(int j=i; j<i+M; ++j) {
            m=max(m, a[j]);
            best[j]=min(best[j], best[i-1]+m);
        }
        m=-INF;
    }
    //for(int i=1; i<=Q; ++i)cout << best[i] <<  " ";
    //cout << endl;
    cout << "Total Time: " << best[Q] << "\n";
}
