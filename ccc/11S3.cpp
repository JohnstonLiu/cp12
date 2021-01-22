#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define INF 1000000007
#define F first
#define S second
#define PB push_back
#define MP make_pair

bool foo(int l, int x, int y) {
    int e=l/5;
    if(l==5) {
        return (((x==1 || x==3) && y==0) || x==2 && (y==0 || y==1));
    }
    if(x>=e && x<2*e) {
        if(y<e)return true;
        if(y<2*e)return foo(e, x-e, y-e);
    }
    if(x>=2*e && x<3*e) {
        if(y<2*e)return true;
        if(y<3*e)return foo(e, x-2*e, y-2*e);
    }
    if(x>=3*e && x<4*e) {
        if(y<e)return true;
        if(y<2*e)return foo(e, x-3*e, y-e);
    }
    return false;
}

int main() {
    int T;
    cin >> T;
    for(int i=0; i<T; ++i) {
        int m, x, y;
        cin >> m >> x >> y;
        int l=pow(5, m);
        if(foo(l, x, y))cout << "crystal" << endl;
        else cout << "empty" << endl;
    }
}
