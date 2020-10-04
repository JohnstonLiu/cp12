#include <bits/stdc++.h>
using namespace std;
int M, N;
int a[1010][1010];
vector<int> dp[1000010];


void factor(int n) {
    if(dp[n].empty()) {
        for(int i=1; i<=(int)sqrt(n) && i<=M; ++i) {
            if(n%i==0) {
                if(n/i<=N) {
                    dp[n].push_back(i); dp[n].push_back(n/i);
                }
                if(i<=N && n/i<=M) {
                    dp[n].push_back(n/i); dp[n].push_back(i);
                }
            }
        }
    }
}

void BFS() {
    int temp=1, temp1=1;
    queue<int> q; bool visited[1000001];

    visited[a[temp][temp1]]=true;
    q.push(temp); q.push(temp1);
    while(!q.empty()) {
        int r=q.front(); q.pop();
        int c=q.front(); q.pop();

        if(r==M && c==N) {
            cout << "yes";
            return;
        }

        int n=a[r][c];
        factor(n);

        for(int i=0, j=1; j<dp[n].size(); i+=2, j+=2) {
            if(!visited[a[dp[n].at(i)][dp[n].at(j)]]) {
                q.push(dp[n].at(i)); q.push(dp[n].at(j));
            }
        }
        visited[n]=true;
    }
    cout << "no";
}


int main() {
    cin >> M >> N;
    for(int i=1; i<=M; ++i) {
        for(int j=1; j<=N; ++j) {
            int n; cin >> n;
            a[i][j]=n;
        }
    }

    BFS();
}
