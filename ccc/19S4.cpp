#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    int a[100001]={};
    for(int i=0; i<N; ++i) {
        cin >> a[i];
    }    
    int R=N%K;

    int k[100000]={};
    int r[100000]={};

    int m=0;
    for(int i=0; i<=N; ++i) {
        if(i!=0 && i%K==0) {
            k[i-K]=m;
            m=0;
        }
        m=max(m, a[i]);
    }
    m=0;
    for(int i=R; i<=N; ++i) {
        if(i-R!=0 && (i-R)%K==0) {
            k[i-K]=m;
            m=0;
        }
        m=max(m, a[i]);
    }
    m=0;
    int counter=1;
    for(int i=0; i<=N; ++i, ++counter) {
        if(i!=0 && counter==R+1) {
            r[i-R]=m;
            counter=1;
            m=0;
            i+=(K-R);
        }
        m=max(m, a[i]);
    }

    for(int i=0; i<N; ++i) {
        cout << a[i];
    }
    cout << endl;

    for(int i=0; i<N; ++i) {
        if(k[i]==0) {
            cout << " ";
        }else {
            cout << k[i];
        }
    }
    cout << endl;

    for(int i=0; i<N; ++i) {
        if(r[i]==0) {
            cout << " ";
        }else {
            cout << r[i];
        }
    }


    int sum=0;
    sum+=r[0];
    for(int i=R; i<N; i+=K) {
        sum+=k[i];
    }
    for(int i=0; i<N-R; i+=K) {
        int prev=sum;
        sum-=r[i];
        sum+=k[i];
        sum-=k[i+R];
        sum+=r[i+K];
        sum=max(sum, prev);
    }
    int final=0;
    for(int i=0; i<N-R; i+=K) {
        final+=k[i];
    }
    final+=r[N-R];
    sum=max(sum, final);
    cout << sum;
}
