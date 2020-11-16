#include <bits/stdc++.h>
using namespace std;

int len;
int clubs[32];
bool dp(int i, int strokes, int d) {
    if(d==0) {
        cout << "Roberta wins in " << strokes << " strokes.";
        return true;
    }
    if(i==len) {
        return false;
    }

    int r=d/clubs[i];
    for(int j=0; j<r; ++j) {
        if(dp(i+1, strokes+(r-j), d-(clubs[i]*(r-j)))) {
            return true;
        }
    }
    return dp(i+1, strokes, d);
}


int main() {
    int d;
    cin >> d;
    cin >> len;
    for(int i=0; i<len; ++i) {
        cin >> clubs[i];
    }
    sort(clubs, clubs+len, greater<>());
    if(!dp(0,0,d)) {
        cout << "Roberta acknowledges defeat.";
    }
}