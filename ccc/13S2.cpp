#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000007

int main() {
    int W, N; cin >> W >> N;
    int car[N];
    for(int i=0; i<N; ++i) {
        cin >> car[i];
    }
    int counter=0;
    int sum=0;
    for(int i=0; i<=3; ++i) {
        sum+=car[i];
        if(sum>W) {
            cout << counter;
            exit(0);
        }
        counter++;
    }
    for(int i=4; i<N; ++i) {
        sum-=car[i-4]; sum+=car[i];
        if(sum>W) {
            cout << counter;
            exit(0);
        }
        counter++;
    }
    cout << counter;
}
