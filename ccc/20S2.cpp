#include <bits/stdc++.h>
using namespace std;
int M, N;
int room[1010][1010];
vector<int> adj[1000001];

void BFS() {
    queue<int> q;
    bool visited[1000001];

    q.push(M); q.push(N);
    while(!q.empty()) {
        int r=q.front(); q.pop();
        int c=q.front(); q.pop();
        if(r==1 && c==1) {
            cout << "yes";
            return;
        }
        if(!visited[r*c]){
            for(auto u : adj[r*c]) {
                q.push(u);
            }
            visited[r*c]=true;
        }
    }
    cout << "no";
}

int main() {
    cin >> M >> N;
    for(int i=1; i<=M; ++i) {
        for(int j=1; j<=N; ++j) {
            cin >> room[i][j];
            adj[room[i][j]].push_back(i);
            adj[room[i][j]].push_back(j);
        }
    }
    BFS();
}