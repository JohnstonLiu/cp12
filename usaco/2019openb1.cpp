#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000007

int main() {
    freopen("buckets.in", "r", stdin);
    freopen("buckets.out", "w", stdout);
    cin.tie(0), cout.sync_with_stdio(0);
    pair<int, int> barn;
    pair<int, int> lake;
    pair<int, int> rock;
    for(int i=0; i<10; ++i) {
        for(int j=0; j<10; ++j) {
            char c; cin >> c;
            if(c=='B') {
                barn={j, i};
            }
            if(c=='L') {
                lake={j, i};
            }
            if(c=='R') {
                rock={j, i};
            }
        }
    }
    int distbl=abs(lake.second-barn.second)+abs(lake.first-barn.first);
    int distbr=abs(rock.second-barn.second)+abs(rock.first-barn.first);
    int distrl=abs(lake.second-rock.second)+abs(lake.first-rock.first);
    if((lake.second==barn.second || lake.first==barn.first) && distbl==distbr+distrl) {
        cout << distbl+1;
    }else {
        cout << distbl-1;
    }
}
