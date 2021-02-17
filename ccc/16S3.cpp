#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000007

vector<int> graph[100001];

bool valid[100001]={};
void prune(int s, int parent) {
    for(auto u : graph[s]) {
        if(u==parent)continue;
        prune(u, s);
        valid[s]|=valid[u];
    }
}

bool visited[100001]={};
int start;
int deep=0;
int nodes;
void dfs(int s, int depth) {
    nodes++;
    if(depth>deep) {
        deep=depth;
        start=s;
    }
    for(auto u : graph[s]) {
        if(visited[u] || !valid[u])continue;
        visited[u]=true;
        dfs(u, depth+1);
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    int p;
    for(int i=0; i<M; ++i) {
        int x; cin >> x;
        valid[x]=true;
        p=x;
    }
    for(int i=0; i<N-1; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    prune(p, -1);
    dfs(p, 0);
    memset(visited, 0, sizeof(visited));
    deep=0;
    nodes=0;
    visited[start]=true;
    dfs(start, 0);
    cout << ((nodes-1)*2)-deep;
}