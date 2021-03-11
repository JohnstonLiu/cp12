#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000007
int arr[4]={0,1,2,3};
void swap(int a, int b) {
    int temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.sync_with_stdio(0);
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);
    int ans=0;
    int counter=0;
    int N; cin >> N;
    tuple<int,int,int> swaps[N];
    for(int i=0; i<N; ++i) {
        int a, b, g;
        cin >> a >> b >> g;
        swaps[i]={a, b, g};
    }
    for(int x=1; x<=3; ++x) {
        for(int i=0; i<N; ++i) {
            int a=get<0>(swaps[i]), b=get<1>(swaps[i]), g=get<2>(swaps[i]);
            swap(a, b);
            if(arr[g]==x) {
                counter++;
            }
        }
        for(int i=1; i<=3; ++i)arr[i]=i;
        ans=max(ans, counter);
        counter=0;
    }
    cout << ans << "\n";
}
