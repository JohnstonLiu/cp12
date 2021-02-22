#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000007

int main() {
    int N, K;
    cin >> N >> K;
    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;
    int a[N+1]; int disp[N+1];
    for(int i=1; i<=N; ++i) {
        a[i]=i; disp[i]=i;
    }
    for(int i=a1, j=a2; i<a1+(a2-a1)/2+1; ++i, --j) {
        int temp=disp[i];
        disp[i]=disp[j];
        disp[j]=temp;
    }
    for(int i=b1, j=b2; i<b1+(b2-b1)/2+1; ++i, --j) {
        int temp=disp[i];
        disp[i]=disp[j];
        disp[j]=temp;
    }
    //for(int i=1; i<=N; ++i)cout << a[i] << " ";
    K--;
    while(K>=0) {
        int temp[N+1];
        for(int i=1; i<=N; ++i) {
            temp[disp[i]]=a[disp[i]];
            a[disp[i]]=a[i];
        }
        for(int i=1; i<=N; ++i)cout << a[i] << " ";
        cout << "\n";
        K--;
    }
}
