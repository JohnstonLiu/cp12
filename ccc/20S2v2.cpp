#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000007
int graph[1001][1001];
bool done[10000001]={};
int M, N;
void dfs(int x) {
    if(done[x])return;
    done[x]=true;
    if(done[N*M]) {
        cout << "yes" << "\n";
        exit(0);
    }
    for(int r=1; r<=(int)sqrt(x); ++r) {
        if(x%r==0) {
            int c=x/r;
            if(c<=N && r<=M)dfs(graph[r][c]);
            if(c<=M && r<=N)dfs(graph[c][r]);
        }
    }
}

int main() {
    cin >> M >> N;
    for(int i=1; i<=M; ++i) {
        for(int j=1; j<=N; ++j) {
            cin >> graph[i][j];
        }
    }
    dfs(1);
    cout << "no" << "\n";
}
