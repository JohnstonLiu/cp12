#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000007
int b[1000]; int a[1000];

int main() {
    freopen("photo.in", "r", stdin);
    freopen("photo.out", "w", stdout);
    int N; cin >> N;
    for(int i=0; i<N-1; ++i) {
        cin >> b[i];
    }
    for(int x=1; x<b[0]; ++x) {
        bool done[100000]={};
        a[0]=x;
        done[x]=true;
        bool flag=true;
        for(int i=1; i<N; ++i) {
            a[i]=b[i-1]-a[i-1];
            if(done[a[i]] || a[i]<=0) {
                flag=false;
                break;
            }
            done[a[i]]=true;
        }
        if(flag) {
            for(int i=0; i<N; ++i) {
                cout << a[i];
                if(i!=N-1)cout << " ";
            }
            exit(0);
        }
    }
}