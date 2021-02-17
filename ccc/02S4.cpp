#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000009
struct node {
    int prev;
    int x;
    node(int n,int b) {
        prev=b;
        x=n;
    }
};


int main() {
    int M, Q;
    cin >> M >> Q;
    int a[Q+1];
    string names[Q+1];
    for(int i=1; i<=Q; ++i) {
        int n; string str;
        cin >> str >> n;
        a[i]=n;
        names[i]=str;
    }
    //int groups=Q/M+(Q%M!=0);
    node* best[Q+1];
    best[0]=new node(0, -1);
    for(int i=1; i<=Q; ++i)best[i]=new node(INF, -1);
    int m=-INF;
    for(int i=1; i<=Q; ++i) {
        for(int j=i; j<i+M && j<=Q; ++j) {
            m=max(m, a[j]);
            if(best[i-1]->x+m<best[j]->x) {
                best[j]->x=best[i-1]->x+m;
                best[j]->prev=i-1;
            }
        }
        m=-INF;
    }
    cout << "Total Time: " << best[Q]->x << "\n";
    int s=best[Q]->prev;
    while(s>0) {
        names[s]+='\n';
        s=best[s]->prev;
    }
    for(int i=1; i<=Q; ++i) {
        if(names[i].back()=='\n')cout << names[i];
        else cout << names[i]+" ";
    }
}
