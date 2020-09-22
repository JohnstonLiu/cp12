#include <bits/stdc++.h>
using namespace std;

char** city;

int BFS(int r, int c) {
    int maxC=c; int maxR=r;
    queue<int> q; bool visited[r][c]; int distance[r][c];
    r=0; c=0;
    visited[r][c]=true;
    distance[r][c]=1;
    q.push(r); q.push(c);
    while(!q.empty()) {
        int s1=q.front(); q.pop();
        int s2=q.front(); q.pop();
        if(s1==maxR-1 && s2==maxC-1) {
            return distance[s1][s2];
        }
        if(city[s1][s2]!='*') {
            if(city[s1][s2]=='-' || city[s1][s2]=='+') {
                if(s2-1>=0) {
                    if(!visited[s1][s2-1]) {
                        visited[s1][s2-1]=true;
                        distance[s1][s2-1]=distance[s1][s2]+1;
                        q.push(s1); q.push(s2-1);
                    }
                }
                if(s2+1<maxC) {
                    if(!visited[s1][s2+1]) {
                        visited[s1][s2+1]=true;
                        distance[s1][s2+1]=distance[s1][s2]+1;
                        q.push(s1); q.push(s2+1);
                    }
                }
            }
            if(city[s1][s2]=='|' || city[s1][s2]=='+'){
                if(s1-1>=0) {
                    if(!visited[s1-1][s2]) {
                        visited[s1-1][s2]=true;
                        distance[s1-1][s2]=distance[s1][s2]+1;
                        q.push(s1-1); q.push(s2);
                    }
                }
                if(s1+1<maxR) {
                    if(!visited[s1+1][s2]) {
                        visited[s1+1][s2]=true;
                        distance[s1+1][s2]=distance[s1][s2]+1;
                        q.push(s1+1); q.push(s2);
                    }
                }
            }

        }
    }
    return -1;
}

int main() {
    int t;
    cin >> t;
    for(int i=0; i<t; ++i) {
        int r, c;
        cin >> r >> c;
        city=new char*[r];
        for(int n=0; n<r; ++n) {
            city[n]=new char[c];
        }

        for(int j=0; j<r; ++j) {
            for(int k=0; k<c; ++k) {
                char n;
                cin >> n;
                city[j][k]=n;
            }
        }

        cout << BFS(r, c) << "\n";
    }
}