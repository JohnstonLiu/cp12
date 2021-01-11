//test each posible irregular group and then sum the max.
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    int a[N];
    for(int i=0; i<N; ++i) {
        cin >> a[i];
    }    
    int rem=N%K;
    int k[N];
    int r[N];
    //O(n) implementation of creating the k and r arrays
    int m=0;
    for(int i=0; i<N; ++i) {
        if(i!=0 && i%K==0) {
            m=0;
        }
        m=max(m, a[i]);
    }
    
}
