#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000007

int main() {
    int N; cin >> N;
    int sum[N+1];
    sum[0]=0;
    int a[N+1];
    for(int i=1; i<=N; ++i) {
        int x; cin >> x;
        sum[i]=sum[i-1]+x;
        a[i]=x;
    }
    //for(int i=1; i<=N; ++i)cout << sum[i] << " ";
    int ans=N;
    for(int i=1; i<N; ++i) {
        for(int j=i+1; j<=N; ++j) {
            int n=j-i+1;
            int s=(sum[j]-sum[i-1]);
            bool flag=false;
            for(int k=i; k<=j; ++k) {
                if(a[k]*n==s) {
                    flag=true;
                    break;
                }
            }
            if(flag)ans++;
        }
    }
    cout << ans;
}
