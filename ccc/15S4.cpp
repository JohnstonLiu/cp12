#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000007

struct path{
    int weight;
    int dmg;
    int end;
    path(int e, int w, int d) {
        weight=w;
        dmg=d;
        end=e;
    }
};

vector<path> graph[2001];
int d[2001];
void djks(int A) {
    for(int i=1; i<=2000; ++i)d[i]=INF;
    d[A]=0;
    bool visited[2001]={};
    priority_queue<pair<int, int>> q;
    q.push({0, A});
    while(!q.empty()) {
        int a=q.top().second; q.pop();
        if(visited[a])continue;
        visited[a]=true;
        for(auto u : graph[a]) {
            int b=u.end; int h=u.dmg; int w=u.weight;
            if(d[a]+w<d[b] && ) {
                d[b]=d[a]+w;
                q.push({-d[b], b});
            }
        }
    }
}


int main() {
    int K, N, M;
    cin >> K >> N >> M;
    for(int i=0; i<M; ++i) {
        int a, b, t, h;
        cin >> a >> b >> t >> h;
        graph[a].emplace_back(path(b, t, h));
        graph[b].emplace_back(path(a, t, h));
    }
    int A, B;
    cin >> A >> B;
    djks(A);
    cout << d[B];
}
