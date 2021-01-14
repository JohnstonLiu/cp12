#include <bits/stdc++.h>
using namespace std;

vector<int> adj[26];

bool bfs() {
    queue<int> q;
    bool visited[26]={};
    visited[0]=true;
    q.push(0);
    while(!q.empty()) {
        int s=q.front(); q.pop();
        if(s==1) {
            return true;
        }
        for(auto u : adj[s]) {
            if(visited[u])continue;
            visited[u]=true;
            q.push(u);
        }
    }
    return false;
}

int main() {
    queue<int> q;
    queue<int> output;
    while(true) {
        string str;
        cin >> str;
        if(str=="**") {
            break;
        }
        int r=str[0]-65;
        int c=str[1]-65;
        q.push(r); q.push(c);
        adj[r].push_back(c);
        adj[c].push_back(r);
    }
    while(!q.empty()) {
        int r=q.front(); q.pop();
        int c=q.front(); q.pop();
        adj[r].erase(remove(adj[r].begin(), adj[r].end(), c));
        adj[c].erase(remove(adj[c].begin(), adj[c].end(), r));
        if(!bfs()) {
            output.push(r);
            output.push(c);
        }
        adj[r].push_back(c);
        adj[c].push_back(r);
    }
    int len=0;
    while(!output.empty()) {
        cout << (char)(output.front()+65);
        output.pop();
        cout << (char)(output.front()+65) << endl;
        output.pop();
        len++;
    }
    cout << "There are " << len << " disconnecting roads." << endl;
}