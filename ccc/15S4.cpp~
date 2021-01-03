#include <bits/stdc++.h>
using namespace std;
int K, N, M;
int a[2001][2001]={};
int b[2001][2001]={};
vector<int> adj[2001]={};
int w[2001];
int d[2001];
typedef pair<int, int> ii;
priority_queue<ii, vector<ii>, greater<ii>> p;

void initialize_ss(int s) {
    for(int i=1; i<2001; ++i) {
        w[i]=N;
    }
    for(int i=1; i<2001; ++i) {
        d[i]=INT_MAX;
    }
    d[s]=0;
}

void dijkstra(int s) {
    bool processed[2001]={};
    initialize_ss(s);
    for(int i=0; i<N; ++i) {
        p.push(make_pair(d[i+1], i+1));
    }

    while(!p.empty()) {
        int u=p.top().second; p.pop();
        if(processed[u])continue;
        for(auto v : adj[u]) {
            if(d[v]>d[u]+a[u][v]) {
                d[v]=d[u]+a[u][v];
                p.push(make_pair(d[v], v));
            }
        }
    }
}

int main() {
    cin >> K >> N >> M;

    for(int i=0; i<M; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        cin >> a[x][y];
        cin >> b[x][y];
    }
    int s, e;
    cin >> s >> e;
    dijkstra(s);
    for(int i=0; i<2001; ++i) {
        if(d[i]!=INT_MAX) {
            cout << i << ": " << d[i] << endl; 
        }
    }
}
