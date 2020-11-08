#include <bits/stdc++.h>
using namespace std;


int af[401][401]={};
int as[401]={};

int sum(int i, int j) {
    return as[j]-as[i-1];
}

int f(int i, int j) {
    if(i>=j) {
        return 1;
    }

    if(af[i][j]!=-1) {
        return af[i][j];
    }
    int m=0;
    for(int a=i; a<j; ++a) {
        for(int b=j; b>=a+1; --b) {
            if(sum(i,a)==sum(b,j)) {
                int x=f(i,a); int y=f(a+1,b-1); int z=f(b,j);
                m=max(m, x*y*z);
            }
        }
    }
    af[i][j]=m;
    return m;
}


int main() {
    int n;
    cin >> n;

    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j) {
            af[i][j]=-1;
        }
    }

    for(int i=1; i<=n; ++i) {
        int a; cin >> a;
        as[i]=as[i-1]+a;
    }

    int m=0;
    for(int i=1; i<=n; ++i) {
        for(int j=i; j<=n; ++j) {
            m=max(m, f(i,j)*sum(i,j));
        }
    }
    cout << m;
}