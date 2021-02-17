#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000007

struct node {
    vector<int> next;
    bool pho=false;
};

node graph[100001];

bool valid[100001]={};
bool visited[100001]={};
void prune(int s) {
    node x=graph[s];
    valid[s]=x.pho;
    for(auto u : x.next) {
        if(visited[u])continue;
        visited[u]=true;
        node a=graph[u];
        valid[u]=a.pho;
        if(valid[u])valid[s]=true;
        prune(u);
    }
}
visited={};

int main() {
    int N, M;
    cin >> N >> M;
    for(int i=1; i<=N; ++i) {
        graph[i]=node();
    }
    int p;
    for(int i=0; i<M; ++i) {
        int x; cin >> x;
        graph[x].pho=true;
        p=x;
    }
    for(int i=0; i<N-1; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].next.push_back(b);
        graph[b].next.push_back(a);
    }
    prune(p);
}