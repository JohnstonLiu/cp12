#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000007

int cows[100001];
int out[100001]={};
set<int> pos[100001];
bool processed[100001];
vector<int> v;
void dfs(int s) {
    if(processed[s])return;
    processed[s]=true;
    v.push_back(s);
    dfs(cows[s]);
}

int main() {
    int N, K;
    cin >> N >> K;
    for(int i=1; i<=N; ++i) {
        cows[i]=i;
        pos[i].insert(i);
    }
    for(int i=0; i<K; ++i) {
        int a, b;
        cin >> a >> b;
        int temp=cows[a];
        cows[a]=cows[b];
        cows[b]=temp;
        pos[cows[b]].insert(b);
        pos[cows[a]].insert(a);
    }

    for(int i=1; i<=N; ++i) {
        if(!processed[i]) {
            set<int> temp;
            dfs(i);
            for(auto u : v) {
                temp.insert(pos[u].begin(), pos[u].end());
            }
            int len=temp.size();
            for(auto u : v) {
                out[u]=len;
            }
            v={};
        }
    }
    for(int i=1; i<=N; ++i) {
        cout << out[i] << endl;
    }
}
