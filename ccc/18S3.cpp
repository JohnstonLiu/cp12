#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    vector<Node> children;
    int r, c;
    char type;
    Node(char car, int r, int c) {
        type=car;
    }
    Node(){}
    void add(Node n) {
        children.push_back(n);
    }
};
int N, M;
Node** fac;

void reformat(vector<int> cameras) {
    for(int i=0; i<cameras.size()-1; ++i) {
        
    }
}

bool verify(int r, int c) {
    return (r<N && c<M && r>=0 && c>=0);
}

void child(Node n) {
    if(verify(n.r+1, n.c)) {
        n.add(fac[n.r+1][n.c]);
    }
    if(verify(n.r-1, n.c)) {
        n.add(fac[n.r-1][n.c]);
    }
    if(verify(n.r, n.c-1)) {
        n.add(fac[n.r][n.c-1]);
    }
    if(verify(n.r, n.c+1)) {
        n.add(fac[n.r][n.c+1]);
    }
}


int BFS(Node start, Node end) {

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

    reformat(cameras);
    //to stop from repeating steps make your previous steps a wall

    for(int i=0; i<end.size()-1; ++i) {
        BFS(fac[start.first][start.second], fac[end.at(i)][end.at(i+1)]);
    }
}
