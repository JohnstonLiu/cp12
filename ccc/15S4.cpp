#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000007
struct node {
    int weight;
    int num;
    int dmg;
    node(int n, int w, int d) {
        weight=w;
        num=n;
        dmg=d;
    }
};

int K, N;
int dist[2001][201];
vector<node> adj[2001];
void djks(int s) {
    bool processed[2001]={};
    for(int i=0; i<=N; ++i)
        for(int j=1; j<=201; ++j)
            dist[i][j]=INF;

    dist[s][0]=0;
    priority_queue<pair<int, int>> q;
    q.push({0, s});
    processed[s]=true;
    while(!q.empty()) {
        int a=q.top().second; q.pop();
        processed[a]=false;
        for(auto u : adj[a]) {
            int b=u.num; int w=u.weight; int h=u.dmg;
            for(int j=0; j+h<K; ++j) {
                if(dist[a][j]+w<dist[b][j+h]) {
                    dist[b][j+h]=dist[a][j]+w;
                    if(!processed[b]) {
                        processed[b]=true;
                        q.push({-dist[b][j+h], b});
                    }

                }
            }
        }
    }

}

int main() {
    int M;
    cin >> K >> N >> M;
    for(int i=0; i<M; ++i) {
        int a, b, t, h;
        cin >> a >> b >> t >> h;
        adj[a].push_back(node(b, t, h));
        adj[b].push_back(node(a, t, h));
    }
    int A, B;
    cin >> A >> B;
    djks(A);
    int ans=INF;
    for(int i=0; i<201; ++i)ans=min(ans, dist[B][i]);
    if(ans==INF)cout << -1;
    else cout << ans;
}
