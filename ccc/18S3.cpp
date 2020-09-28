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
            fac[j][c].set('W');
        }
        for(int j=r; j>=0; --j) {
            if(fac[j][c].type=='W'){
                break;
            }
            if (fac[j][c].type=='U' || fac[j][c].type=='D' || fac[j][c].type=='R' || fac[j][c].type=='L' || fac[j][c].type=='C') {
                continue;
            }
            fac[j][c].set('W');
        }
        for(int j=c; j<M; ++j) {
            if(fac[r][j].type=='W'){
                break;
            }
            if (fac[r][j].type=='U' || fac[r][j].type=='D' || fac[r][j].type=='R' || fac[r][j].type=='L' || fac[j][c].type=='C') {
                continue;
            }
            fac[r][j].set('W');
        }
        for(int j=c; j>=0; --j) {
            if(fac[r][j].type=='W'){
                break;
            }
            if (fac[r][j].type=='U' || fac[r][j].type=='D' || fac[r][j].type=='R' || fac[r][j].type=='L' || fac[j][c].type=='C') {
                continue;
            }
            fac[r][j].set('W');
        }
        fac[r][c].set('W');
    }
}

bool verify(int r, int c) {
    return (r<N && c<M && r>=0 && c>=0 && fac[r][c].type!='W');
}

void child(Node n) {
    int a=n.r+1;
    int b=n.c;
    if(verify(a, b)) {
        if(fac[a][b].type=='D') {
            fac[a][b].set('W');
            if(verify(a+1, b))fac[n.r][n.c].add(fac[a+1][b]);
        }else if(fac[a][b].type=='R') {
            fac[a][b].set('W');
            if(verify(a, b+1))fac[n.r][n.c].add(fac[a][b+1]);
        }else if(fac[a][b].type=='L') {
            fac[a][b].set('W');
            if(verify(a, b-1))fac[n.r][n.c].add(fac[a][b-1]);
        }else{
            fac[n.r][n.c].add(fac[a][b]);
        }
    }
    a=n.r-1;
    b=n.c;
    if(verify(a, b)) {
        if(fac[a][b].type=='U') {
            fac[a][b].set('W');
            if(verify(a-1, b))fac[n.r][n.c].add(fac[a-1][b]);
        }else if(fac[a][b].type=='R') {
            fac[a][b].set('W');
            if(verify(a, b+1))fac[n.r][n.c].add(fac[a][b+1]);
        }else if(fac[a][b].type=='L') {
            fac[a][b].set('W');
            if(verify(a, b-1))fac[n.r][n.c].add(fac[a][b-1]);
        }else{
            fac[n.r][n.c].add(fac[a][b]);
        }
    }
    a=n.r;
    b=n.c-1;
    if(verify(a, b)) {
        if(fac[a][b].type=='D') {
            fac[a][b].set('W');
            if(verify(a+1, b))fac[n.r][n.c].add(fac[a+1][b]);
        }else if(fac[a][b].type=='U') {
            fac[a][b].set('W');
            if(verify(a-1, b))fac[n.r][n.c].add(fac[a-1][b]);
        }else if(fac[a][b].type=='L') {
            fac[a][b].set('W');
            if(verify(a, b-1))fac[n.r][n.c].add(fac[a][b-1]);
        }else{
            fac[n.r][n.c].add(fac[a][b]);
        }
    }
    a=n.r;
    b=n.c+1;
    if(verify(a, b)) {
        if(fac[a][b].type=='D') {
            fac[a][b].set('W');
            if(verify(a+1, b))fac[n.r][n.c].add(fac[a+1][b]);
        }else if(fac[a][b].type=='R') {
            fac[a][b].set('W');
            if(verify(a, b+1))fac[n.r][n.c].add(fac[a][b+1]);
        }else if(fac[a][b].type=='U') {
            fac[a][b].set('W');
            if(verify(a-1, b))fac[n.r][n.c].add(fac[a-1][b]);
        }else{
            fac[n.r][n.c].add(fac[a][b]);
        }
    }
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
    start.set('W');
    q.push(start);
    while(!q.empty()) {
        start = q.front();
        q.pop();

        child(start);
        start = fac[start.r][start.c];
        for (Node n : start.children) {
            fac[n.r][n.c].set('W');
            d[n.r][n.c] = d[start.r][start.c] + 1;
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




    //to stop from repeating steps make your previous steps a wall
    BFS(fac[start.first][start.second]);

    for(int i=0; i<end.size()-1; i+=2) {
        cout << d[i][i+1] << endl;
    }
}
