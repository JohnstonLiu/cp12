#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000007
struct node {
    int step;
    node(int s) {
        step=s;
    }
};


int houses[1000000];
int H, K;

bool check(int x) {
    stack<int> hydrants;
    int len=0;
    hydrants.push(-1);
    for(int i=0; i<H; ++i) {
        if(len>K)return false;
        if((hydrants.top()<=houses[i] && hydrants.top()>=houses[i]-x) || (hydrants.top()>=houses[i] && hydrants.top()<=houses[i]+x)) {
            continue;
        }

        int pos=(houses[i]+x)%H;

    }
    return true;
}

int main() {
    cin >> H;
    for(int i=0; i<H; ++i) {
        cin >> houses[i];
    }
    cin >> K;
    sort(houses, houses+H);
    int ans;
    int lo=0, hi=999999;
    while(lo<=hi) {
        int med=lo+(hi-lo)/2;
        if(check(med)) {
            ans=med;
            hi=med-1;
        }else {
            lo=med+1;
        }
    }

    cout << ans << endl;
}

