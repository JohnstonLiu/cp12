#include <bits/stdc++.h>
using namespace std;
int M, N;
int a[1001][1001];
vector<int> dp[1000001];

vector<int> find(int n) {
    vector<int> b;
    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= N; ++j) {
            if(a[i][j]==n){
                b.push_back(i);
                b.push_back(j);
            }
        }
    }
    return b;
}

void BFS() {
    int temp=M, temp1=N;
    queue<int> q; bool visited[1000001];
    visited[M*N]=true;
    q.push(M); q.push(N);
    while(!q.empty()) {
        int r=q.front(); q.pop();
        int c=q.front(); q.pop();
    }
}


int main() {
    cin >> M >> N;
    for(int i=1; i<=M; ++i) {
        for(int j=1; j<=N; ++j) {
            int n; cin >> n;
            a[i][j]=n;
        }
    }

    BFS();
}
