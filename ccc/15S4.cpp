#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define INF 1000000007
#define PB push_back
#define MP make_pair

vi g[2001];
int d[2001];
int weight[2001][2001]={};
int dmg[2001][2001]={};
void djks(int s) {
    for(int i=1; i<2001; ++i)d[i]=INF;
    priority_queue<pi> q;
    bool visited[2001]={};
    d[s]=0;
    q.push({0, s});
    while(!q.empty()) {
        int a=q.top().second; q.pop();
        if(visited[a])continue;
        visited[a]=true;
        for(auto b : g[a]) {
            int w=weight[a][b];
            if(d[a]+w<d[b]) {
                d[b]=d[a]+w;
                q.push({-d[b], b});
            }
        }
    }


}

int main() {
    int hull, N, M;
    cin >> hull >> N >> M;
    for(int i=0; i<M; ++i) {
        int a, b, t, h;
        cin >> a >> b >> t >> h;
        g[a].PB(b);   
        g[b].PB(a);
        weight[a][b]=t;
        weight[b][a]=t;
        dmg[a][b]=h;
        dmg[b][a]=h;
    }
    int A, B;
    cin >> A >> B;
    djks(A);
    cout << d[B];
}
