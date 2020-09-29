#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    vector<Node> children;
    int r, c;
    char type;
    Node(char car, int r, int c) {
        type=car;
        this->r=r;
        this->c=c;
    }
    Node(){}
    void add(Node n) {
        children.push_back(n);
    }
    void set(char n) {
        type=n;
    }
};
int N, M;
Node** fac;

void reformat(vector<int> cameras) {
    for(int i=0; i<cameras.size()-1; i+=2) {
        int r=cameras.at(i); int c=cameras.at(i+1);
        for(int j=r; j<N; ++j) {
            if(fac[j][c].type=='W'){
                break;
            }
            if (fac[j][c].type=='U' || fac[j][c].type=='D' || fac[j][c].type=='R' || fac[j][c].type=='L' || fac[j][c].type=='C') {
                continue;
            }
            fac[j][c].set('X');
        }
        for(int j=r; j>=0; --j) {
            if(fac[j][c].type=='W'){
                break;
            }
            if (fac[j][c].type=='U' || fac[j][c].type=='D' || fac[j][c].type=='R' || fac[j][c].type=='L' || fac[j][c].type=='C') {
                continue;
            }
            fac[j][c].set('X');
        }
        for(int j=c; j<M; ++j) {
            if(fac[r][j].type=='W'){
                break;
            }
            if (fac[r][j].type=='U' || fac[r][j].type=='D' || fac[r][j].type=='R' || fac[r][j].type=='L' || fac[r][j].type=='C') {
                continue;
            }
            fac[r][j].set('X');
        }
        for(int j=c; j>=0; --j) {
            if(fac[r][j].type=='W'){
                break;
            }
            if (fac[r][j].type=='U' || fac[r][j].type=='D' || fac[r][j].type=='R' || fac[r][j].type=='L' || fac[r][j].type=='C') {
                continue;
            }
            fac[r][j].set('X');
        }
        fac[r][c].set('W');
    }

}

void verify(int r, int c, int a, int b) {
    if(r<N && c<M && r>=0 && c>=0 && (fac[r][c].type!='W' && fac[r][c].type!='X')){
        while(fac[r][c].type!='W') {
            if(fac[r][c].type=='D') {
                fac[r][c].set('W');
                r++;
            }else if(fac[r][c].type=='R') {
                fac[r][c].set('W');
                c++;
            }else if(fac[r][c].type=='L') {
                fac[r][c].set('W');
                c--;
            }else if(fac[r][c].type=='U'){
                fac[r][c].set('W');
                r--;
            }else {
                fac[a][b].add(fac[r][c]);
                break;
            }
        }
    }
}

void child(Node n) {
    int c=n.r; int d=n.c;
    int a=n.r+1;
    int b=n.c;
    verify(a, b, c ,d);
    a=n.r-1;
    b=n.c;
    verify(a, b, c ,d);
    a=n.r;
    b=n.c-1;
    verify(a, b, c ,d);
    a=n.r;
    b=n.c+1;
    verify(a, b, c ,d);
}
int** d;


void BFS(Node start) {
    queue<Node> q;
    d=new int*[N];
    for(int i=0; i<N; ++i) {
        d[i]=new int[M];
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            d[i][j]=0;
        }
    }
    if(start.type=='W') return;
    fac[start.r][start.c].set('W');
    start=fac[start.r][start.c];
    q.push(start);
    while(!q.empty()) {
        start = q.front(); q.pop();
        child(start);
        start = fac[start.r][start.c];
        for (Node n : start.children) {
            n=fac[n.r][n.c];
            d[n.r][n.c] = d[start.r][start.c] + 1;
            fac[n.r][n.c].set('W');
            q.push(n);
        }
    }
}

int main() {
    cin >> N >> M;
    fac=new Node*[N];
    for(int i=0; i<N; ++i) {
        fac[i]=new Node[M];
    }

    pair<int, int> start;
    vector<int> end;
    vector<int> cameras;

    for(int i=0; i<N; ++i) {
        for(int j=0; j<M; ++j) {
            char c;
            cin >> c;
            if(c=='C') {
                cameras.push_back(i);
                cameras.push_back(j);
            }
            if(c=='.') {
                end.push_back(i);
                end.push_back(j);
            }
            if(c=='S') {
                start.first=i;
                start.second=j;
            }
            fac[i][j]=Node(c, i, j);
        }
    }

    if(!cameras.empty()) reformat(cameras);
    for(int i=0; i<N; ++i) {
        for (int j = 0; j < M; ++j) {
            if(fac[i][j].type=='X')fac[i][j].set('W');
        }
    }
    /*
    for(int i=0; i<N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << fac[i][j].type;
        }
        cout << endl;
    }
     */

    BFS(fac[start.first][start.second]);

    for(int i=0; i<end.size()-1; i+=2) {
        if(d[end.at(i)][end.at(i+1)]==0)cout << -1 << "\n";
        else cout << d[end.at(i)][end.at(i+1)] << endl;
    }
}
