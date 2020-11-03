#include <bits/stdc++.h>
using namespace std;


int af[401][401]={};
int as[401][401]={};
int ar[401]={};

int sum(int i, int j) {
    int a=i, b=j;
    if(as[i][j]!=0) {
        return as[i][j];
    }
    int s=0;
    while(i<=j) {
        s+=ar[i];
        i++;
    }
    as[a][b]=s;
    return s;
}

int f(int i, int j) {
    if(i>=j) {
        return 1;
    }

    if(af[i][j]!=0) {
        return af[i][j];
    }
    int m=0;
    for(int a=i; a<j; ++a) {
        for(int b=a+1; b<=j; ++b) {
            int x=f(i,a); int y=f(a+1,b-1); int z=f(b,j);
            if(sum(i,a)==sum(b,j)) {
                m=max(m,x*y*z);
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
        cin >> ar[i];
    }

    int m=0;
    for(int i=1; i<=n; ++i) {
        for(int j=i; j<=n; ++j) {
            m=max(m, f(i,j)*sum(i,j));
        }
    }
    cout << m;
}