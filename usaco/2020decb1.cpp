#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000007

int main() {
    int foo[7];
    for(int i=0; i<7; ++i) {
        cin >> foo[i];
    }
    sort(foo, foo+7);
    int a=foo[0];
    int bc=foo[6]-a;
    int b, c;
    for(int i=1; i<6; ++i) {
        for(int j=1; j<6; ++j) {
            if(foo[i]+foo[j]==bc) {
                b=min(foo[i], foo[j]);
                c=max(foo[i], foo[j]);
            }
        }
    }
    printf("%d %d %d", a, b, c);
}
