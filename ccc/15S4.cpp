#include <bits/stdc++.h>
using namespace std;
int K, N, M;
vector<int> weight[2001]={};
vector<int> damage[2001]={};
vector<int> adj[2001]={};
//use the big brain vector<int>, int instead of int, int`
int h[2001];
int d[2001];
typedef pair<vector<int>, int> ii;
priority_queue<ii, vector<ii>, greater<ii>> p;

void initialize_ss(int s) {
    for(int i=1; i<2001; ++i) {
        h[i]=K;
    }
    for(int i=1; i<2001; ++i) {
        d[i]=INT_MAX;
    }
    d[s]=0;
}

void dijkstra(int s) {
    bool processed[2001]={};
    initialize_ss(s);
    for(int i=1; i<N; ++i) {
        vector<int> v; v.push_back(d[i]);
        p.push(make_pair(v, i));
    }

    while(!p.empty()) {
        int u=p.top().second; p.pop();
        if(processed[u])continue;
        for(int i=0; i<adj[u].size(); ++i) {
            //for
            int v=adj[u][i];
            if(d[v]>d[u]+weight[u][i] && (h[u]-b[u][v])>0) {
                h[v]=[u]-b[u][v];
                d[v]=d[u]+a[u][v];
                p.push(make_pair(d[v], v));
            }
        }
    }
}

int main() {
    cin >> K >> N >> M;

    for(int i=0; i<M; ++i) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        adj[x].push_back(y);
        adj[y].push_back(x);
        weight[x].push_back(a);
        weight[y].push_back(a);
        damage[x].push_back(b);
        damage[y].push_back(b);
    }
    int s, e;
    cin >> s >> e;
    dijkstra(s);
    if(d[e]==INT_MAX) {
        cout << -1;
    }else {
        cout << d[e];
    }
}
