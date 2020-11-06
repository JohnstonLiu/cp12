#include <bits/stdc++.h>
using namespace std;
int M, N;
int room[1010][1010];
vector<pair<int, int>> adj[1000010];

void BFS() {
    queue<pair<int,int>> q;
    bool visited[1010][1010];

    q.push(make_pair(M, N));
    while(!q.empty()) {
        pair<int, int> p=q.front(); q.pop();
        if(p.first==1 && p.second==1) {
            cout << "yes";
            return;
        }
        for(auto u : adj[p.first*p.second]) {
            if(visited[u.first][u.second]) {
                continue;
            }
            visited[u.first][u.second]=true;
            q.push(u);
        }
    }
    cout << "no";
}

int main() {
    cin >> M >> N;
    for(int i=1; i<=M; ++i) {
        for(int j=1; j<=N; ++j) {
            cin >> room[i][j];
            adj[room[i][j]].push_back(make_pair(i,j));
        }
    }
    BFS();
    return 0;
}