#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define INF 1000000009
#define PB push_back
#define MP make_pair

int main() {
    int N, K;
    cin >> N >> K;
    int a[N];
    int days=N/K;
    if(N%K!=0)days++;

    for(int i=0; i<N; ++i) {
        a[i]=N;
    }

    //knowing the amount of groups that I must form
    //test possible group size arrangements
    //rearrange them accordingly likely using recursion.
}