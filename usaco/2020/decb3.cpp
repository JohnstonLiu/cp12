#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000007

struct node{
    int ans;
    bool ded=false;
    int x; int y;
    char c;
    node(){}
    bool operator< (const node &other) const{
        if(c=='E')return y<other.y;
        if(c=='N')return x<other.x;
    }
};

int main() {
    int n; cin >> n;
    vector<node> xcow;
    vector<node> ycow;
    vector<pair<int, int>> helper;
    map<pair<int, int>, int> output;
    for(int i=0; i<n; ++i) {
        char c; cin >> c;
        int x, y;
        cin >> x >> y;
        if(c=='N') {
            ycow.push_back(node());
            ycow.back().c=c; ycow.back().x=x; ycow.back().y=y;
        }else {
            xcow.push_back(node());
            xcow.back().c=c; xcow.back().x=x; xcow.back().y=y;
        }
        helper.push_back({x, y});
        output[{x,y}]=INF;
    }
    sort(ycow.begin(), ycow.end());
    sort(xcow.begin(), xcow.end());

    for(int j=0; j<xcow.size(); ++j) {
        int ans=INF;
        for(int i=0; i<ycow.size(); ++i) {
            if(!ycow[i].ded && !xcow[j].ded && xcow[j].y>ycow[i].y && xcow[j].x<ycow[i].x) {
                if(ycow[i].x-xcow[j].x<xcow[j].y-ycow[i].y) {
                    ycow[i].ded=true;
                    ycow[i].ans=xcow[j].y-ycow[i].y;
                    output[{ycow[i].x, ycow[i].y}]=ycow[i].ans;
                }else if(xcow[j].y-ycow[i].y<ycow[i].x-xcow[j].x) {
                    xcow[j].ans=ycow[i].x-xcow[j].x;
                    xcow[j].ded=true;
                    output[{xcow[j].x, xcow[j].y}]=xcow[j].ans;
                }
            }
        }
    }
    for(auto u : helper) {
        if(output[u]==INF)cout << "Infinity\n";
        else cout << output[u] << "\n";
    }
}
